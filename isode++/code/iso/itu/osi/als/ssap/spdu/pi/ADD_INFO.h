/*
 * ADD_INFO.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ADD_INFO_H_
#define ALS_SSAP_SPDU_ADD_INFO_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ADD_INFO : public BYTES {
public:
	ADD_INFO(int cc, const byte* data) : BYTES(PI_ADD_INFO, cc, data) {}
	ADD_INFO(NetworkBuffer& tsdu) : BYTES(PI_ADD_INFO, tsdu) {}
	virtual ~ADD_INFO() {
	}
};

}
}
}

#endif
