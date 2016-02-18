/*
 * MIA_DATA.h
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_MIA_DATA_H_
#define ALS_SSAP_SPDU_MIA_DATA_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"


namespace ALS {
namespace SSAP {
namespace SPDU {

class MIA_DATA : public BYTES {
public:
	MIA_DATA(int isn) : BYTES(PI_MIA_DATA, SIZE_CN_ISN, nullptr) {
		throw NotYetImplementedException();
	}
	MIA_DATA(NetworkBuffer& tsdu) : BYTES(PI_MIA_DATA, tsdu) {
		throw NotYetImplementedException();
	}
	virtual ~MIA_DATA();
};

}
}
}

#endif /* MIA_DATA_H_ */
