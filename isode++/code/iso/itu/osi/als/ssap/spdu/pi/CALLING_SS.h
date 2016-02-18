/*
 * CALLING_SS.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CALLING_SS_H_
#define ALS_SSAP_SPDU_CALLING_SS_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CALLING_SS : public BYTES {
public:
	CALLING_SS(int cc, const byte* data) : BYTES(PI_CALLING_SS, cc, data) {}
	CALLING_SS(NetworkBuffer& tsdu) : BYTES(PI_CALLING_SS, tsdu) {}
	virtual ~CALLING_SS() {
	}
};

}
}
}

#endif
