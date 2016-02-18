/*
 * REASON.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_REASON_H_
#define ALS_SSAP_SPDU_REASON_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class REASON : public BYTE{
public:
	REASON(byte tokens) : BYTE(PI_REASON, tokens) {}
	REASON(NetworkBuffer& tsdu) : BYTE(PI_REASON, tsdu) {}
	virtual ~REASON() {
	}
};

}
}
}

#endif
