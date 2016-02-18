/*
 * PROTOCOLOPT.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PROTOCOL_OPT_H_
#define ALS_SSAP_SPDU_PROTOCOL_OPT_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class PROTOCOL_OPT : public BYTE {
public:
	PROTOCOL_OPT(byte tokens) : BYTE(PI_PROTOCOL_OPT, tokens) {}
	PROTOCOL_OPT(NetworkBuffer& tsdu) : BYTE(PI_PROTOCOL_OPT, tsdu) {}
	virtual ~PROTOCOL_OPT() {
	}
};

}
}
}

#endif
