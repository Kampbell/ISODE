/*
 * XDATA.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_XDATA_H_
#define ALS_SSAP_SPDU_XDATA_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class XDATA : public BYTES {
public:
	XDATA(int cc, const void* data) : BYTES(PI_XDATA, cc, data) {}
	XDATA(NetworkBuffer& tsdu) : BYTES(PI_XDATA, tsdu) {}
	virtual ~XDATA() {
	}
};

}
}
}

#endif
