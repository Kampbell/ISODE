/*
 * TDISC.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TDISC_H_
#define ALS_SSAP_SPDU_TDISC_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TDISC : public BYTE {
public:
	TDISC(byte tokens) : BYTE(PI_TDISC, tokens) {}
	TDISC(NetworkBuffer& tsdu) : BYTE(PI_TDISC, tsdu) {}
	virtual ~TDISC() {
	}
	virtual NetworkBuffer* toTSDU() { return nullptr; }
};

}
}
}

#endif
