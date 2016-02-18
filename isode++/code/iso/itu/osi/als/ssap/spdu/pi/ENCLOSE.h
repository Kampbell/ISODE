/*
 * ENCLOSE.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ENCLOSE_H_
#define ALS_SSAP_SPDU_ENCLOSE_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ENCLOSE : public BYTE {
public:
	ENCLOSE(byte tokens) : BYTE(PI_ENCLOSE, tokens) {}
	ENCLOSE(NetworkBuffer& tsdu) : BYTE(PI_ENCLOSE, tsdu) {}
	virtual ~ENCLOSE() {
	}
};


}
}
}

#endif
