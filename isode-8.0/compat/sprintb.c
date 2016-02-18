/* sprintb.c - sprintf on bits */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/compat/RCS/sprintb.c,v 9.0 1992/06/16 12:07:00 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/compat/RCS/sprintb.c,v 9.0 1992/06/16 12:07:00 isode Rel $
 *
 *
 * $Log: sprintb.c,v $
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

/*  */

char  *sprintb (v, bits)
register int	v;
register char  *bits;
{
	register int    i,
			 j;
	register char   c,
			 *bp;
	static char buffer[BUFSIZ];

	(void) sprintf (buffer, bits && *bits == 010 ? "0%o" : "0x%x", v);
	bp = buffer + strlen (buffer);

	if (bits && *++bits) {
		j = 0;
		*bp++ = '<';
		while (i = *bits++)
			if (v & (1 << (i - 1))) {
				if (j++)
					*bp++ = ',';
				for (; (c = *bits) > 32; bits++)
					*bp++ = c;
			} else
				for (; *bits > 32; bits++)
					continue;
		*bp++ = '>';
		*bp = NULL;
	}

	return buffer;
}
