/* implode.c - explode ascii into octets */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/compat/RCS/implode.c,v 9.0 1992/06/16 12:07:00 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/compat/RCS/implode.c,v 9.0 1992/06/16 12:07:00 isode Rel $
 *
 *
 * $Log: implode.c,v $
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

/*    DATA */

char	hex2nib[0x80] = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, NULL, 
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, NULL, 
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

/*  */

int	implode (a, b, n)
register u_char *a;
register char  *b;
register int    n;
{
    register int    i;

    for (i = 0; i < n; i += 2) {
	*a++ = (hex2nib[b[0] & 0x7f] << 4) | (hex2nib[b[1] & 0x7f]);
	b += 2;
    }

    return (n / 2);
}
