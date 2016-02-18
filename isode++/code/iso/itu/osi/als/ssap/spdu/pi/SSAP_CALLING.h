/*
 * SSAP_CALLING.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SSAP_CALLING_H_
#define ALS_SSAP_SPDU_SSAP_CALLING_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class SSAP_CALLING : public BYTES {
public:
	SSAP_CALLING(int cc, byte* data) : BYTES(PI_SSAP_CALLING, cc, data) {}
	SSAP_CALLING(NetworkBuffer& tsdu): BYTES(PI_SSAP_CALLING, tsdu) {}
	virtual ~SSAP_CALLING() {
	}
};

}
}
}

#endif
