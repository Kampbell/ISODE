/*
 * SYNC.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SYNC_H_
#define ALS_SSAP_SPDU_SYNC_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class SYNC : public BYTE {
public:
	SYNC(byte tokens) : BYTE(PI_SYNC, tokens) {}
	SYNC(NetworkBuffer& tsdu) : BYTE(PI_SYNC, tsdu) {}
	virtual ~SYNC() {
	}
};

}
}
}

#endif
