/*
 * TOKEN_SET.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TOKEN_SET_H_
#define ALS_SSAP_SPDU_TOKEN_SET_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TOKEN_SET : public BYTE {
public:
	TOKEN_SET(byte tokens) : BYTE(PI_TOKEN_SET, tokens) {}
	TOKEN_SET(NetworkBuffer& tsdu) : BYTE(PI_TOKEN_SET, tsdu) {}
	virtual ~TOKEN_SET() {
	}
};

}
}
}

#endif
