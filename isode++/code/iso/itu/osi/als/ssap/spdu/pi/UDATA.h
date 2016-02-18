/*
 * UDATA.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_UDATA_H_
#define ALS_SSAP_SPDU_UDATA_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class UDATA : public BYTES {
public:
	UDATA(int cc, const void* data) : BYTES(PI_UDATA, cc, data) {}
	UDATA(NetworkBuffer& tsdu): BYTES(PI_UDATA, tsdu) {}
	virtual ~UDATA() {
	}
};


}
}
}

#endif
