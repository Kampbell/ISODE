/*
 * COMMON_REF.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_COMMON_REF_H_
#define ALS_SSAP_SPDU_COMMON_REF_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class COMMON_REF : public BYTES {
public:
	COMMON_REF(int cc, const byte* data) : BYTES(PI_COMMON_REF, cc, data) {}
	COMMON_REF(NetworkBuffer& tsdu) : BYTES(PI_COMMON_REF, tsdu) {}
	virtual ~COMMON_REF() {
	}
};

}
}
}

#endif
