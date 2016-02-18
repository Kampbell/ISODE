/*
 * SSAP_CALLED.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SSAP_CALLED_H_
#define ALS_SSAP_SPDU_SSAP_CALLED_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class SSAP_CALLED : public BYTES {
public:
	SSAP_CALLED(int cc, byte* data) : BYTES(PI_SSAP_CALLED, cc, data) {}
	SSAP_CALLED(NetworkBuffer& tsdu) : BYTES(PI_SSAP_CALLED, tsdu) {}
	virtual ~SSAP_CALLED() {
	}
};

}
}
}

#endif
