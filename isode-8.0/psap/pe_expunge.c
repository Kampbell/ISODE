/* pe_expunge.c - expunge a PE */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/psap/RCS/pe_expunge.c,v 9.0 1992/06/16 12:25:44 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/psap/RCS/pe_expunge.c,v 9.0 1992/06/16 12:25:44 isode Rel $
 *
 *
 * $Log: pe_expunge.c,v $
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

#include <stdio.h>
#include "psap.h"

/*  */

PE	pe_expunge (pe, r)
PE	pe,
 r;
{
	if (r) {
		if (pe == r)
			return r;

		if (pe_extract (pe, r))
			if (pe -> pe_realbase && !r -> pe_realbase) {
				r -> pe_realbase = pe -> pe_realbase;
				pe -> pe_realbase = NULL;
			}

		r -> pe_refcnt++;
	}

	pe_free (pe);

	return r;
}
