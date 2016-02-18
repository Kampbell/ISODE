/*
 * REASONS.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_REASONS_H_
#define ALS_SSAP_SPDU_REASONS_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class REASONS : public BYTES {
public:
	REASONS(int cc, const byte* data) : BYTES(PI_REASON, cc, data) {}
	REASONS(NetworkBuffer& tsdu) : BYTES(PI_REASON, tsdu) {}
	virtual ~REASONS() {
	}
};

}
}
}

#endif
