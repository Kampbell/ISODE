/*
 * 2ISN.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TOISN_H_
#define ALS_SSAP_SPDU_TOISN_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TOISN : public PI {
protected:
	TOISN() : PI(PI_TOISN) {
	}
	TOISN(NetworkBuffer& tsdu) : PI(PI_TOISN, tsdu) {
	}
	virtual ~TOISN() {
	}
};

}
}
}

#endif
