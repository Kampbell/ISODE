/* logger.h - logging routines */

/* 
 * $Header: /xtel/isode/isode/h/RCS/logger.h,v 9.0 1992/06/16 12:17:57 isode Rel $
 *
 *
 * $Log: logger.h,v $
 * Revision 9.0  1992/06/16  12:17:57  isode
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


#ifndef	_LOGGER_
#define	_LOGGER_

#include "manifest.h"

/*  */

typedef struct  ll_struct {
    char   *ll_file;		/* path name to logging file */

    char   *ll_hdr;		/* text to put in opening line */
    char   *ll_dhdr;		/* dynamic header - changes */

    int	    ll_events;		/* interesting events */
#define	LLOG_NONE	0
#define	LLOG_FATAL	0x01	/*   fatal errors */
#define	LLOG_EXCEPTIONS	0x02	/*   exceptional events */
#define	LLOG_NOTICE	0x04	/*   informational notices */
#define	LLOG_PDUS	0x08	/*   PDU printing */
#define	LLOG_TRACE	0x10	/*   program tracing */
#define	LLOG_DEBUG	0x20	/*   full debugging */
#define	LLOG_ALL	0xff
#define	LLOG_MASK \
    "\020\01FATAL\02EXCEPTIONS\03NOTICE\04PDUS\05TRACE\06DEBUG"

    int	    ll_syslog;		/* interesting events to send to syslog */
				/*   takes same values as ll_events */

    int     ll_msize;		/* max size for log, in Kbytes */

    int     ll_stat;		/* assorted switches */
#define	LLOGNIL		0x00
#define	LLOGCLS		0x01	/*   keep log closed, except when writing */
#define	LLOGCRT		0x02	/*   create log if necessary */
#define	LLOGZER		0x04	/*   truncate log when limits reached */
#define	LLOGERR		0x08    /*   log closed due to (soft) error */
#define	LLOGTTY		0x10	/*   also log to stderr */
#define	LLOGHDR		0x20    /*   static header allocated */
#define	LLOGDHR		0x40    /*   dynamic header allocated */

    int     ll_fd;		/* file descriptor */
} LLog;

/*  */

#define	SLOG(lp,event,what,args) \
if (lp -> ll_events & (event)) { \
    (void) ll_log (lp, event, what, "%s", ll_preset args); \
} \
else

#ifndef	LLOG
#define	LLOG(lp,event,args)	SLOG (lp, event, NULLCP, args)
#endif

#ifdef	DEBUG
#define	DLOG(lp,event,args)	SLOG (lp, event, NULLCP, args)
#else
#define	DLOG(lp,event,args)
#endif


#ifdef	DEBUG

#ifdef PEPSY_VERSION

#ifdef __STDC__

#define	PLOGP(lp,args,pe,text,rw) \
    if ((lp) -> ll_events & LLOG_PDUS) { \
	pvpdu (lp, print_##args##_P, pe, text, rw); \
    } \
    else

#define	PLOG(lp,fnx,pe,text,rw)	\
    if ((lp) -> ll_events & LLOG_PDUS) { \
	pvpdu (lp, fnx##_P, pe, text, rw); \
    } \
    else

#else

#define	PLOGP(lp,args,pe,text,rw) \
    if ((lp) -> ll_events & LLOG_PDUS) { \
	pvpdu (lp, print_/**/args/**/_P, pe, text, rw); \
    } \
    else

#define	PLOG(lp,fnx,pe,text,rw)	\
    if ((lp) -> ll_events & LLOG_PDUS) { \
	pvpdu (lp, fnx/**/_P, pe, text, rw); \
    } \
    else

#endif

#else	/* !PEPSY_VERSION */

#define	PLOG(lp,fnx,pe,text,rw)	\
    if ((lp) -> ll_events & LLOG_PDUS) { \
	vpdu (lp, fnx, pe, text, rw); \
    } \
    else

#endif	/* !PEPSY_VERSION */

#ifdef	lint
#undef	PLOGP
#define	pvpdu(lp,cookie,pe,text,rw) \
	_pvpdu(lp, pe, text, rw)
#define	PLOGP(lp,args,pe,text,rw) \
	_pvpdu (lp, pe, text, rw);
#endif

#ifndef PLOGP
#define	PLOGP(lp,args,pe,text,rw) \
    if ((lp) -> ll_events & LLOG_PDUS) { \
	pvpdu (lp, 0, (struct modtype *) 0, pe, text, rw); \
    } \
    else
#endif

#else	/* !DEBUG */
#define	PLOG(lp,fnx,pe,text,rw)
#define	PLOGP(lp,args,pe,text,rw)
#endif


int	ll_open ();
int	ll_log (), _ll_log ();
int	ll_close ();

void	ll_hdinit ();
void	ll_dbinit ();

int	ll_printf ();
int	ll_sync ();

char   *ll_preset ();

int	ll_check ();

int	ll_defmhdr ();
IFP	ll_setmhdr ();
#endif

/******************************/
/* should be removed finally: */
/******************************/

#ifdef ULTRIX_X25_DEMSA
/* for Trace Information of module names */
#include <stdio.h>
char our_global_buffer[BUFSIZ];
#endif
