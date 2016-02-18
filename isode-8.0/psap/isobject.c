/* isobject.c - lookup Object IDentifiers/DEscriptors */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/psap/RCS/isobject.c,v 9.0 1992/06/16 12:25:44 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/psap/RCS/isobject.c,v 9.0 1992/06/16 12:25:44 isode Rel $
 *
 *
 * $Log: isobject.c,v $
 * Revision 9.0  1992/06/16  12:25:44  isode
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

#include <ctype.h>
#include <stdio.h>
#include "psap.h"
#include "tailor.h"

/*    DATA */

static char *isobjects = "isobjects";

static FILE *servf = NULL;
static int  stayopen = 0;

static struct isobject    ios;

/*  */

int	setisobject (f)
int	f;
{
    if (servf == NULL)
	servf = fopen (isodefile (isobjects, 0), "r");
    else
	rewind (servf);
    stayopen |= f;

    return (servf != NULL);
}


int	endisobject () {
    if (servf && !stayopen) {
	(void) fclose (servf);
	servf = NULL;
    }

    return 1;
}

/*  */

struct isobject  *getisobject () {
    register int i;
    register struct isobject *io = &ios;
    register char  *cp;
    static char buffer[BUFSIZ + 1];
    static char *vec[NVEC + NSLACK + 1];
    static unsigned int elements[NELEM + 1];

    if (servf == NULL
	    && (servf = fopen (isodefile (isobjects, 0), "r")) == NULL)
	return NULL;

    while (fgets (buffer, sizeof buffer, servf) != NULL) {
	if (*buffer == '#')
	    continue;
	if (cp = index (buffer, '\n'))
	    *cp = NULL;
	if (str2vec (buffer, vec) < 2)
	    continue;

	if ((i = str2elem (vec[1], elements)) <= 1)
	    continue;

	io -> io_descriptor = vec[0];
	io -> io_identity.oid_elements = elements;
	io -> io_identity.oid_nelem = i;

	return io;
    }
    return NULL;
}
