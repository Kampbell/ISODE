/*
 * TSDU_MAXSIZ.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TSDU_MAXSIZ_H_
#define ALS_SSAP_SPDU_TSDU_MAXSIZ_H_
#include "als/ssap/spdu/pi/INT.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TSDU_MAXSIZ : public INT {
public:
	TSDU_MAXSIZ(int4 tsdumax) : INT(PI_TSDU_MAXSIZ, tsdumax) {}
	TSDU_MAXSIZ(NetworkBuffer& tsdu): INT(PI_TSDU_MAXSIZ, tsdu) {}
	virtual ~TSDU_MAXSIZ() {
	}
	nat2 getTSDUInit() {
		return (nat2)(getValue() >> 16);
	}
	nat2 getTSDUResp() {
		return (nat2)(getValue());
	}
};

}
}
}

#endif
