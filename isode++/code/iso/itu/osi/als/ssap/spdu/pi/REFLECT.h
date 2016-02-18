/*
 * REFLECT.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_REFLECT_H_
#define ALS_SSAP_SPDU_REFLECT_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class REFLECT : public BYTES {
public:
	REFLECT(int cc, const byte* data) : BYTES(PI_REFLECT, cc, data) {}
	REFLECT(NetworkBuffer& tsdu): BYTES(PI_REFLECT, tsdu) {}
	virtual ~REFLECT() {
	}
	virtual NetworkBuffer* toTSDU() { return nullptr; }
};


}
}
}

#endif
