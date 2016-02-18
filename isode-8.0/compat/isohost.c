/* isohost.c - getlocalhost */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/compat/RCS/isohost.c,v 9.0 1992/06/16 12:07:00 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/compat/RCS/isohost.c,v 9.0 1992/06/16 12:07:00 isode Rel $
 *
 *
 * $Log: isohost.c,v $
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

#include <stdio.h>
#include "general.h"
#include "manifest.h"
#ifdef	TCP
#include "internet.h"
#endif
#include "tailor.h"
#ifdef	SYS5
#include <sys/utsname.h>
#endif

/*  */

char   *getlocalhost () {
    register char   *cp;
#ifdef	TCP
    register struct hostent *hp;
#endif
#ifdef	SYS5
    struct utsname uts;
#endif
    static char buffer[BUFSIZ];

    if (buffer[0])
	return buffer;

    isodetailor (NULLCP, 0);
    if (*isodename)
	(void) strcpy (buffer, isodename);
    else {
#if	!defined(SOCKETS) && !defined(SYS5)
	(void) strcpy (buffer, "localhost");
#endif
#ifdef	SOCKETS
	(void) gethostname (buffer, sizeof buffer);
#endif
#ifdef	SYS5
	(void) uname (&uts);
	(void) strcpy (buffer, uts.nodename);
#endif

#ifdef	TCP
	if (hp = gethostbyname (buffer))
	    (void) strcpy (buffer, hp -> h_name);
	else
	    SLOG (addr_log, LLOG_EXCEPTIONS, NULLCP,
		  ("%s: unknown host", buffer));
#endif

	if (cp = index (buffer, '.'))
	    *cp = NULL;
    }

    return buffer;
}
