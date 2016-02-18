/* pe_extract.c - extract a PE */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/psap/RCS/pe_extract.c,v 9.0 1992/06/16 12:25:44 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/psap/RCS/pe_extract.c,v 9.0 1992/06/16 12:25:44 isode Rel $
 *
 *
 * $Log: pe_extract.c,v $
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

/* assumes that q appears at most once directly under p... */

int	pe_extract (pe, r)
PE	pe,
	r;
{
    register PE	   *p,
		    q;

    switch (pe -> pe_form) {
	case PE_FORM_PRIM: 
	case PE_FORM_ICONS: 
	    break;

	case PE_FORM_CONS: 
	    for (p = &pe -> pe_cons; q = *p; p = &q -> pe_next)
		if (q == r) {
		    (*p) = q -> pe_next;
		    q -> pe_next = NULLPE;
		    if (r->pe_refcnt > 0)
			    r->pe_refcnt--;
		    return 1;
		}
		else
		    if (pe_extract (q, r))
			return 1;
	    break;
    }

    return 0;
}
