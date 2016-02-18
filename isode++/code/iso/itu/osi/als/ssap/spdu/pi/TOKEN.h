/*
 * TOKEN.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TOKEN_H_
#define ALS_SSAP_SPDU_TOKEN_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TOKEN : public BYTE {
public:
	TOKEN(byte tokens) : BYTE(PI_TOKEN, tokens) {}
	TOKEN(NetworkBuffer& tsdu) : BYTE(PI_TOKEN, tsdu) {}
	virtual ~TOKEN() {
	}
};

}
}
}

#endif
