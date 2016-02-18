/*
 * RESYNC.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_RESYNC_H_
#define ALS_SSAP_SPDU_RESYNC_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class RESYNC : public BYTE {
public:
	RESYNC(byte tokens) : BYTE(PI_RESYNC, tokens) {}
	RESYNC(NetworkBuffer& tsdu) : BYTE(PI_RESYNC, tsdu) {}
	virtual ~RESYNC() {
	}
};

}
}
}

#endif
