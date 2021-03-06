/*
 * TD.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/TD.h"
#include "als/ssap/spdu/pi/PI.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int	TD::encode()	{ 
		PI* pi;
		int len = 0;
		if (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);
			len += pi->length();
			append(pi);
		}
		return len;
	}
	ReturnCode	TD::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		SPDU::control(tsdu); 
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
