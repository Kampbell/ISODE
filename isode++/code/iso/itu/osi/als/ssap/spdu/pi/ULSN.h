/*
 * ULSN.h
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ULSN_H_
#define ALS_SSAP_SPDU_ULSN_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ULSN : public BYTES {
public:
	ULSN(int isn) : BYTES(PI_ULSN, SIZE_CN_ISN, nullptr) {
		throw NotYetImplementedException();
	}
	ULSN(NetworkBuffer& tsdu) : BYTES(PI_ULSN, tsdu) {
		throw NotYetImplementedException();
	}
	virtual ~ULSN();
};

} 
}
}

#endif 
