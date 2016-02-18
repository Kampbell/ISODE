/*
 * NF.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/NF.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			NF::encode() {
		PI*	pi;int len = 0;
		
	    if  (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose); len += pi->length();append(pi);
	    }
		if  (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new UDATA(spdu_ulen, spdu_udata); len += pi->length();append(pi);
		}
		return len;
	}
	ReturnCode	NF::decode(NetworkBuffer& tsdu) {
		ReturnCode rc;
		rc = SPDU::control(tsdu); 
		return rc;
	}

}
}
}
