/*
 * CDU.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/CDA.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			CDA::encode() {
		PI* pi;
		int len = 0;

		if (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);len += pi->length();append(pi);
		}
		if (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new UDATA(spdu_ulen, spdu_udata);len += pi->length(); append(pi);
		}
		return len;
	}
	ReturnCode	CDA::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		rc = SPDU::control(tsdu); 
		if (sli() == 0)
			return OK;
		while (tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch (code) {
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
