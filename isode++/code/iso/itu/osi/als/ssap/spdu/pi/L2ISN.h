/*
 * L2ISN.h
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_L2ISN_H_
#define ALS_SSAP_SPDU_L2ISN_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"


namespace ALS {
namespace SSAP {
namespace SPDU {

class L2ISN : public BYTES {
public:
	L2ISN(int isn) : BYTES(PI_L2ISN, SIZE_CN_ISN, nullptr) {
		throw NotYetImplementedException();
	}
	L2ISN(NetworkBuffer& tsdu) : BYTES(PI_L2ISN, tsdu) {
		throw NotYetImplementedException();
	}
	virtual ~L2ISN();
};

}
}
}

#endif /* L2ISN_H_ */
