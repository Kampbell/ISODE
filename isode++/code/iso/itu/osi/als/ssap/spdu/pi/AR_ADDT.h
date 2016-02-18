/*
 * AR_ADDT.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AR_ADDT_H_
#define ALS_SSAP_SPDU_AR_ADDT_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AR_ADDT : public BYTES {
public:
	AR_ADDT(int cc, const void* data) : BYTES(PI_AR_ADDT, cc, data) {}
	AR_ADDT(NetworkBuffer& tsdu) : BYTES(PI_AR_ADDT, tsdu) {}
	virtual ~AR_ADDT() {
	}
};

}
}
}

#endif
