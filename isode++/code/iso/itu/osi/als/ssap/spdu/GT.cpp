/*
 * GT.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/GT.h"
#include "als/ssap/spdu/pi/TOKEN.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			GT::encode() {
		PI* pi;
		int len = 0;

		if (hasMask(SMASK_GT_TOKEN)) {
			pi = new TOKEN(gt_token);len += pi->length();append(pi);
		}
		if (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);len += pi->length();append(pi);
		}
		if (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new UDATA(spdu_ulen, spdu_udata);len += pi->length(); append(pi);
		}
		return len;
	}
/*
	case SPDU_GT:
#ifdef	notdef
	case SPDU_DT:		// aka SPDU_GT
#endif
	    If_Set (SMASK_SPDU_GT) {
			start_spdu (&c, GT_BASE_SIZE);
			If_Set (SMASK_GT_TOKEN)
				Put_Item (PI_TOKEN, (char *) &s_gt_token);
			break;
	    }			// else fall
	    start_spdu (&c, DT_BASE_SIZE);
	    If_Set (SMASK_ENCLOSE)
			Put_Item (PI_ENCLOSE, (char *) &s_enclose);
/* NB: caller responsible for mapping s_udata to user info
	    break;

 */
	ReturnCode	GT::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		rc = SPDU::control(tsdu); 
		if (sli() == 0)
			return OK;
		while (tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch (code) {
				case PI::PI_TOKEN: {
					TOKEN pi(tsdu);
					gt_token = pi.getValue();
					addMask(SMASK_GT_TOKEN);
				}
					break;
				case PI::PI_ENCLOSE: {
					ENCLOSE pi(tsdu);
					setEnclose(pi.getValue());
					addMask(SMASK_ENCLOSE);
				}
					break;
				case PI::PI_UDATA: {
					UDATA pi(tsdu);
					int cc = 0;
					const byte* data = pi.getValue(cc);
		    		setData(cc, data);
				}
					break;
				default:
					tsdu.reset();
					goto EXIT;
			}
		}
	EXIT:
		return rc;
	}

}
}
}
