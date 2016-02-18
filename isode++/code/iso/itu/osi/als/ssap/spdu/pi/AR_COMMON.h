/*
 * AR_COMMON.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AR_COMMON_H_
#define ALS_SSAP_SPDU_AR_COMMON_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AR_COMMON : public BYTES {
public:
	AR_COMMON(int cc, const void* data) : BYTES(PI_AR_COMMON, cc, data) {}
	AR_COMMON(NetworkBuffer& tsdu) : BYTES(PI_AR_COMMON, tsdu) {}
	virtual ~AR_COMMON() {
	}
};

}
}
}

#endif
