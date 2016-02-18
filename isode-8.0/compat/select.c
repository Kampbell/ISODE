/* select.c - select() abstractions */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/compat/RCS/select.c,v 9.0 1992/06/16 12:07:00 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/compat/RCS/select.c,v 9.0 1992/06/16 12:07:00 isode Rel $
 *
 *
 * $Log: select.c,v $
 * Revision 9.0  1992/06/16  12:07:00  isode
 * Release 8.0
 *
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */


/* LINTLIBRARY */

#include <errno.h>
#include <stdio.h>
#include "manifest.h"
#include "tailor.h"
#include <sys/stat.h>


extern int errno;


int	xselect_blocking_on_intr = 0;

/*  */

#if	defined(SOCKETS) && !defined(TLI_POLL)

#include <sys/time.h>


/* Synchronous multiplexing:
	< 0 :	block indefinately
	= 0 :	poll
	> 0 :	wait
*/

#ifdef ULTRIX_X25
#ifdef ULTRIX_X25_DEMSA

/* the dec-x25 library */
#include "/usr/include/x25.h"

/* declarations and handler functions as proposed by J.Kloppenburg */

static fd_set in_rfds, in_wfds, in_efds;
static fd_set out_rfds, out_wfds, out_efds;
static int out_n;

void rhandler(fd)
int fd;
{
	if ( FD_ISSET(fd,&in_rfds) ) {
		FD_SET(fd,&out_rfds);
		out_n++;
	}
}

void whandler(fd)
int fd;
{
	if ( FD_ISSET(fd,&in_wfds) ) {
		FD_SET(fd,&out_wfds);
		out_n++;
	}
}

void xhandler(fd)
int fd;
{
	if ( FD_ISSET(fd,&in_efds) ) {
		FD_SET(fd,&out_efds);
		out_n++;
	}
}

#endif
#endif

int	selsocket (nfds, rfds, wfds, efds, secs)
int	nfds;
fd_set *rfds,
	   *wfds,
	   *efds;
int	secs;
{
	int     n;
	fd_set  ifds,
			ofds,
			xfds;

#ifdef ULTRIX_X25_DEMSA

	/* X25SelectCall uses timeval struct */

	int     error;
	struct timeval  tvs;
	register struct timeval *tv = &tvs;

	if (secs != NOTOK)
		tv -> tv_sec = secs, tv -> tv_usec = 0;
	else
		tv = NULL;

#else

#if defined(masscomp) && defined(_ATT)
	int msecs;
#else
	struct timeval  tvs;
	register struct timeval *tv = &tvs;
#endif

#if defined(masscomp) && defined(_ATT)
	if (secs != NOTOK)
		msecs = secs * 1000;
	else
		msecs = -1;
#else
	if (secs != NOTOK)
		tv -> tv_sec = secs, tv -> tv_usec = 0;
	else
		tv = NULL;
#endif

#endif

	if (rfds)
		ifds = *rfds;
	if (wfds)
		ofds = *wfds;
	if (efds)
		xfds = *efds;
#if defined(masscomp) && defined(_ATT)
	if (efds)
		FD_ZERO(efds);
#endif

	for (;;) {
#ifdef ULTRIX_X25_DEMSA

		if (rfds) in_rfds = *rfds;
		else FD_ZERO(&in_rfds);
		if (wfds) in_wfds = *wfds;
		else FD_ZERO(&in_wfds);
		if (efds) in_efds = *efds;
		else FD_ZERO(&in_efds);
		FD_ZERO(&out_rfds);
		FD_ZERO(&out_wfds);
		FD_ZERO(&out_efds);
		out_n = 0;

		/* handlers rhandler whandler xhandler are being called */
		/* by the X25SelectCall routine                         */

		error = X25SelectCall(tv);

		if ( error < NULL )  {
			n = NOTOK;
			switch (error) {
			case X25E_SELCNT:
				SLOG (compat_log, LLOG_EXCEPTIONS, "selsocket:",
					  ("There is an incorrect pre-selection count"));
				break;
			case X25E_SELECT:
				SLOG (compat_log, LLOG_EXCEPTIONS, "selsocket:",
					  ("The select system call returns an error"));
				break;
			case X25E_XTRA_SEL:
				SLOG (compat_log, LLOG_EXCEPTIONS, "selsocket:",
					  ("There is an extra bit in the select system call"));
				break;
			default:
				SLOG (compat_log, LLOG_EXCEPTIONS, "selsocket:",
					  ("unknown errorcode"));
			}
		} else
			n = out_n;

		if (rfds) *rfds = out_rfds;
		if (wfds) *wfds = out_wfds;
		if (efds) *efds = out_efds;
		switch(n) {

#else
#if  defined(masscomp) && defined(_ATT)
		switch (n = select (nfds, rfds, wfds, msecs)) {
#else
		switch (n = select (nfds, rfds, wfds, efds, tv)) {
#endif
#endif
		case OK:
			if (secs == NOTOK)
				break;
			return OK;

		case NOTOK:
			if (xselect_blocking_on_intr
					&& errno == EINTR
					&& secs == NOTOK)
				continue;
		/* else fall... */

		default:
			return n;
		}

		if (rfds)
			*rfds = ifds;
		if (wfds)
			*wfds = ofds;
		if (efds)
			*efds = xfds;
	}
}
#endif


/*  */

#ifdef	EXOS

#ifdef	SYS5

/* There seems to be a bug in the SYS5 EXOS select() routine when a socket can
   be read immediately (don't know about write).  The bug is that select()
   returns ZERO, and the mask is zero'd as well.  The code below explicitly
   checks for this case.
*/

#include "sys/soioctl.h"


int	selsocket (nfds, rfds, wfds, efds, secs)
int	nfds;
fd_set *rfds,
	   *wfds,
	   *efds;
int	secs;
{
	register int    fd;
	int     n;
	fd_set  ifds,
			ofds;
	long    nbytes,
			usecs;

	if (secs != NOTOK)
		usecs = secs * 1000;
	else
		usecs = 0xffff; /* used to be ~(1L << (8 * sizeof usecs - 1)) */

	if (rfds)
		ifds = *rfds;
	if (wfds)
		ofds = *wfds;
	if (efds)
		FD_ZERO (efds);

	for (;;) {
		switch (n = select (nfds + 1, rfds, wfds, usecs)) {  /* +1 for UNISYS */
		case OK:
			if (rfds)
				for (fd = 0; fd < nfds; fd++)
					if (FD_ISSET (fd, &ifds)
							&& ioctl (fd, FIONREAD, (char *) &nbytes)
							!= NOTOK
							&& nbytes > 0) {
						FD_SET (fd, rfds);
						n++;
					}
			if (n == 0 && secs == NOTOK)
				break;
			return n;

		case NOTOK:
		default:
			return n;
		}

		if (rfds)
			*rfds = ifds;
		if (wfds)
			*wfds = ofds;
	}
}
#endif
#endif

#if defined(TLI_TP) && defined(TLI_POLL)
#include <poll.h>

int selsocket (nfds, rfds, wfds, efds, secs)
int	nfds;
fd_set	*rfds, *wfds, *efds;
int	secs;
{
	int i, j, n;
	struct pollfd pollfds[128];

	for (i = j = 0; i < nfds; i++) {
		pollfds[j].fd = NOTOK;
		pollfds[j].events = 0;
		if (rfds && FD_ISSET (i, rfds)) {
			pollfds[j].fd = i;
			pollfds[j].events |= POLLIN | POLLPRI;
		}
		if (wfds && FD_ISSET (i, wfds)) {
			pollfds[j].fd = i;
			pollfds[j].events |= POLLOUT;
		}
		if (efds && FD_ISSET(i, efds)) {
			pollfds[j].fd = i;
			/* one always gets notified of exceptions */
		}
		if (pollfds[j].fd == i)
			j ++;

	}

	if (rfds) FD_ZERO(rfds);
	if (wfds) FD_ZERO(wfds);
	if (efds) FD_ZERO(efds);

	if (secs != 0 && secs != NOTOK)
		secs *= 1000;

again:
	n = poll (pollfds, (unsigned long)j, secs);
	if (n == NOTOK) {
		if (errno == EAGAIN)
			goto again;
		if (errno != EINTR)
			SLOG (compat_log, LLOG_EXCEPTIONS, "failed", ("poll"));
		return NOTOK;
	}

	for (i = 0; i < j; i++) {
		if (rfds && (pollfds[i].revents & (POLLIN | POLLPRI)))
			FD_SET (pollfds[i].fd, rfds);
		if (wfds && (pollfds[i].revents & POLLOUT))
			FD_SET (pollfds[i].fd, wfds);
		if (efds && (pollfds[i].revents & (POLLERR | POLLHUP | POLLNVAL)))
			FD_SET (pollfds[i].fd, efds);
	}
	return n;
}

#endif

/*  */

/* This routine used to be used for devices that didn't support real select.
   Those devices are no longer supported.

   Instead the routine is used to check if an I/O abstraction has some data
   buffered in user-space for reading...
 */

static IFP	sfnx[FD_SETSIZE] = { NULL };
static caddr_t	sdata[FD_SETSIZE] = { NULL };


IFP	set_check_fd (fd, fnx, data)
int	fd;
IFP	fnx;
caddr_t	data;
{
	IFP	    ofnx;

	if (fd < 0 || fd >= FD_SETSIZE)
		return NULLIFP;

	ofnx = sfnx[fd];
	sfnx[fd] = fnx, sdata[fd] = data;

	return ofnx;
}

/*  */
#if !(defined(_AIX) && defined(X25))
/* We have an AIX specific version if X25 is defined */

int	xselect (nfds, rfds, wfds, efds, secs)
int	nfds;
fd_set *rfds,
	   *wfds,
	   *efds;
int	secs;
{
	register int    fd;
	int	    n;
	fd_set  ifds,
			ofds,
			xfds;
	static int nsysfds = NOTOK;

	if (nsysfds == NOTOK)
		nsysfds = getdtablesize ();
	if (nfds > FD_SETSIZE)
		nfds = FD_SETSIZE;
	if (nfds > nsysfds + 1)
		nfds = nsysfds + 1;

	FD_ZERO (&ifds);
	n = 0;

	for (fd = 0; fd < nfds; fd++)
		if (sfnx[fd] != NULLIFP
				&& rfds
				&& FD_ISSET (fd, rfds)
				&& (*sfnx[fd]) (fd, sdata[fd]) == DONE) {
			FD_SET (fd, &ifds);
			n++;
		}

	if (n > 0) {
		*rfds = ifds;	/* struct copy */
		if (wfds)
			FD_ZERO (wfds);
		if (efds)
			FD_ZERO (efds);

		return n;
	}

	if (rfds)
		ifds = *rfds;	/* struct copy */
	if (wfds)
		ofds = *wfds;	/* struct copy */
	if (efds)
		xfds = *efds;	/* struct copy */

	if ((n = selsocket (nfds, rfds, wfds, efds, secs)) != NOTOK)
		return n;

	if (rfds)
		FD_ZERO (rfds);
	if (wfds)
		FD_ZERO (wfds);
	if (efds)
		FD_ZERO (efds);

	if (errno == EBADF) {
		struct stat st;

		n = 0;
		for (fd = 0; fd < nfds; fd++)
			if (((rfds && FD_ISSET (fd, &ifds))
					|| (wfds && FD_ISSET (fd, &ofds))
					|| (efds && FD_ISSET (fd, &xfds)))
					&& fstat (fd, &st) == NOTOK
					&& errno == EBADF) {
				if (rfds && FD_ISSET (fd, &ifds))
					FD_SET (fd, rfds);
				if (wfds && FD_ISSET (fd, &ofds))
					FD_SET (fd, wfds);
				if (efds && FD_ISSET (fd, &xfds))
					FD_SET (fd, efds);

				SLOG (compat_log, LLOG_EXCEPTIONS, "",
					  ("fd %d has gone bad", fd));
				n++;
			}

		if (n)
			return n;

		errno = EBADF;
	}

	return NOTOK;
}

#endif
