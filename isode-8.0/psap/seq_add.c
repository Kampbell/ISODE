/* seq_add.c - add an element to a sequence */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/psap/RCS/seq_add.c,v 9.0 1992/06/16 12:25:44 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/psap/RCS/seq_add.c,v 9.0 1992/06/16 12:25:44 isode Rel $
 *
 *
 * $Log: seq_add.c,v $
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

int	seq_add (pe, r, i)
register PE	pe,
		 r;
register int	i;
{
	register PE	   *p,
			 q;

	if (r == NULLPE)
		return pe_seterr (pe, PE_ERR_NMEM, NOTOK);

	if (i < 0)
		i = pe -> pe_cardinal;
	for (p = &pe -> pe_cons; q = *p; p = &q -> pe_next)
		if (q -> pe_offset == i) {
			r -> pe_next = q -> pe_next;
			pe_free (q);
			break;
		} else if (q -> pe_offset > i) {
			r -> pe_next = q;
			break;
		}

	*p = r;
	if ((r -> pe_offset = i) >= pe -> pe_cardinal)
		pe -> pe_cardinal = i + 1;

	return OK;
}
