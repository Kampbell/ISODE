/*
 * PREPARE.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PREPARE_H_
#define ALS_SSAP_SPDU_PREPARE_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class PREPARE : public BYTE{
public:
	PREPARE(byte tokens) : BYTE(PI_PREPARE, tokens) {}
	PREPARE(NetworkBuffer& tsdu) : BYTE(PI_PREPARE, tsdu) {}
	virtual ~PREPARE() {
	}
};

}
}
}

#endif
