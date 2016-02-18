/* rydserror.c - ROSY: return error to invocation */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/rosy/RCS/rydserror.c,v 9.0 1992/06/16 12:37:29 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/rosy/RCS/rydserror.c,v 9.0 1992/06/16 12:37:29 isode Rel $
 *
 *
 * $Log: rydserror.c,v $
 * Revision 9.0  1992/06/16  12:37:29  isode
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
#include "rosy.h"


#ifdef __STDC__
#define missingP(p) \
{ \
    if (p == NULL) \
        return rosaplose (roi, ROS_PARAMETER, NULLCP, \
                            "mandatory parameter \"%s\" missing", #p); \
}
#else
#define	missingP(p) \
{ \
    if (p == NULL) \
	return rosaplose (roi, ROS_PARAMETER, NULLCP, \
			    "mandatory parameter \"%s\" missing", "p"); \
}
#endif
/*    ERROR */

int	RyDsError (sd, id, err, out, priority, roi)
int	sd;
int	id,
	err,
	priority;
caddr_t	out;
struct RoSAPindication *roi;
{
    int	    result;
    PE	    pe;
    register struct opsblk *opb;
    register struct RyError **ryep,
			    *rye;
    register struct RyOperation *ryo;

    missingP (roi);

    if ((opb = findopblk (sd, id, OPB_RESPONDER)) == NULLOPB)
	return rosaplose (roi, ROS_PARAMETER, NULLCP,
		"invocation %d not in progress on association %d",
		id, sd);

    ryo = opb -> opb_ryo;
    if (!(ryep = ryo -> ryo_errors))
	return rosaplose (roi, ROS_PARAMETER, NULLCP,
		"error not permitted with operation %s/%d",
		ryo -> ryo_name, ryo -> ryo_op);

    for (; *ryep; ryep++)
	if ((*ryep) -> rye_err == err)
	    break;

    if (!(rye = *ryep))
	return rosaplose (roi, ROS_PARAMETER, NULLCP,
		"error %d not permitted with operation %s/%d",
		err, ryo -> ryo_name, ryo -> ryo_op);

#ifdef PEPSY_DEFINITIONS
    if (rye -> rye_param_mod) {
#else 
    if (rye -> rye_param_encode) {
#endif 
#ifdef	notdef
	missingP (out);
#endif
	PY_pepy[0] = 0;
#ifdef PEPSY_DEFINITIONS
	if (enc_f (rye -> rye_param_index, rye -> rye_param_mod, &pe, 1, NULL,
		   NULLCP, out) == NOTOK)
#else 
	if ((*rye -> rye_param_encode) (&pe, 1, NULL, NULLCP, out) == NOTOK)
#endif 
	    return rosaplose (roi, ROS_CONGEST, NULLCP,
	    "error encoding parameter for invocation %d having %s/%d [%s]",
			      opb -> opb_id, rye -> rye_name, rye -> rye_err,
			      PY_pepy);
    }
    else {
	if (out)
	    return rosaplose (roi, ROS_PARAMETER, NULLCP,
		    "error parameter not permitted with operation %s/%d",
		    rye -> rye_name, rye -> rye_err);

	pe = NULLPE;
    }

    if ((result = RoErrorRequest (sd, id, err, pe, priority, roi)) != NOTOK)
	freeopblk (opb);

    if (pe)
	pe_free (pe);

    return result;

}
