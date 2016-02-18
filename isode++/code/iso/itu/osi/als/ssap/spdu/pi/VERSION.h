/*
 * VERSION.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_VERSION_H_
#define ALS_SSAP_SPDU_VERSION_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTE.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class VERSION : public BYTE {
public:
	VERSION(byte tokens) : BYTE(PI_VERSION, tokens) {}
	VERSION(NetworkBuffer& tsdu) : BYTE(PI_VERSION, tsdu) {}
	virtual ~VERSION() {
	}
};

}
}
}

#endif
