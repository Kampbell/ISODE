/*
 * AR_CALLED.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AR_CALLED_H_
#define ALS_SSAP_SPDU_AR_CALLED_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AR_CALLED : public BYTES {
public:
	AR_CALLED(int cc, const void* data) : BYTES(PI_AR_CALLED, cc, data) {}
	AR_CALLED(NetworkBuffer& tsdu): BYTES(PI_AR_CALLED, tsdu) {}
	virtual ~AR_CALLED() {
	}
};

}
}
}

#endif
