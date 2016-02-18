/*
 * CALLED_SS.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CALLED_SS_H_
#define ALS_SSAP_SPDU_CALLED_SS_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CALLED_SS : public BYTES {
public:
	CALLED_SS(int cc, const byte* data) : BYTES(PI_CALLED_SS, cc, data) {}
	CALLED_SS(NetworkBuffer& tsdu)				: BYTES(PI_CALLED_SS, tsdu) {}
	virtual ~CALLED_SS() {
	}
};

}
}
}

#endif
