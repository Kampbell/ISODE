/*
 * ACT_ID.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ACT_ID_H_
#define ALS_SSAP_SPDU_ACT_ID_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ACT_ID : public BYTES {
public:
	ACT_ID(int cc, const void* data) : BYTES(PI_ACT_ID, cc, data) {}
	ACT_ID(NetworkBuffer& tsdu) : BYTES(PI_ACT_ID, tsdu) {}
	virtual ~ACT_ID() {
	}
};

}
}
}

#endif
