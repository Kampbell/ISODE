/*
 * AR_CALLING.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AR_CALLING_H_
#define ALS_SSAP_SPDU_AR_CALLING_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AR_CALLING : public BYTES {
public:
	AR_CALLING(int cc, const void* data) : BYTES(PI_AR_CALLING, cc, data) {}
	AR_CALLING(NetworkBuffer& tsdu) : BYTES(PI_AR_CALLING, tsdu) {}
	virtual ~AR_CALLING() {
	}
};

}
}
}

#endif
