/* real2prim.c - real to presentation element */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/psap/RCS/real2prim.c,v 9.0 1992/06/16 12:25:44 isode Rel $";
#endif

/*
 * $Header: /xtel/isode/isode/psap/RCS/real2prim.c,v 9.0 1992/06/16 12:25:44 isode Rel $
 *
 * Contributed by Julian Onions, Nottingham University.
 * July 1989 - this is awful stuff!
 *
 * $Log: real2prim.c,v $
 * Revision 9.0  1992/06/16  12:25:44  isode
 * Release 8.0
 *
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

#include "psap.h"

/*  */

PE	real2prim (d, class, id)
register double d;
PElementClass	class;
PElementID	id;
{
	register PE pe;
	double	mant, nm;
	int	exponent;
	int	expsign;
	int	parts[sizeof (double)];
	int	sign, i, maxi, mask;
	int	n, explen;
	PElementData	dp;

	if ((pe = pe_alloc (class, PE_FORM_PRIM, id)) == NULLPE)
		return NULLPE;

	if (d == 0.0)
		return pe;

	mant = frexp (d, &exponent);

	if (mant < 0.0) {
		sign = -1;
		mant = -mant;
	} else	sign = 1;

	nm = mant;
	for (i = 0; i < sizeof (double) ; i++) {
		int intnm;
		nm *= (1<<8);
		intnm = ((int)nm) & 0xff;
		nm -= intnm;
		if (intnm)
			maxi = i + 1;
		parts[i] = intnm;
	}

	exponent -= 8 * maxi;

	expsign = exponent >= 0 ? exponent : exponent ^ (-1);
	mask = 0x1ff << (((n = sizeof exponent) - 1) * 8 - 1);
	while (n > 1 && (expsign & mask) == 0)
		mask >>= 8, n--;

	explen = n;
	if (n > 3)
		n ++;

	if ((pe -> pe_prim = PEDalloc (n + maxi + 1)) == NULLPED) {
		pe_free (pe);
		return NULLPE;
	}

	dp = pe -> pe_prim + (pe -> pe_len = n + maxi + 1);

	for (; maxi > 0; maxi --)
		*--dp = parts[maxi - 1];
	for (n = explen; n-- > 0; exponent >>= 8)
		*--dp = exponent & 0xff;
	if (explen > 3)
		*--dp = explen & 0xff;

	switch (explen) {
	case 1:
		explen = PE_REAL_B_EF1;
		break;
	case 2:
		explen = PE_REAL_B_EF2;
		break;
	case 3:
		explen = PE_REAL_B_EF3;
		break;
	default:
		explen = PE_REAL_B_EF3;
		break;
	}
	*--dp = PE_REAL_BINENC
			| PE_REAL_B_B2
			| (sign == -1 ? PE_REAL_B_S : 0)
			| explen;
	return pe;
}




