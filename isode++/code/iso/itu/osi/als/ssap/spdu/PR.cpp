/*
 * PR.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/PR.h"
#include "als/ssap/spdu/pi/PREPARE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			PR::encode() {
		PI*	pi;int len = 0;
	    if  (hasMask(SMASK_PR_TYPE)) {
			pi = new PREPARE(pr_type); len += pi->length();append(pi);
	    }
		return len;
	}
	ReturnCode	PR::decode(NetworkBuffer& tsdu) {
		ReturnCode rc;
		rc = SPDU::control(tsdu);
		return rc;
	}

}
}
}
