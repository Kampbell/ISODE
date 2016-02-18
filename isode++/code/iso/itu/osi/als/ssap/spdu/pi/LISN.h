/*
 * LISN.h
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_LISN_H_
#define ALS_SSAP_SPDU_LISN_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"


namespace ALS {
namespace SSAP {
namespace SPDU {

class LISN : public BYTES {
public:
	LISN(int isn) : BYTES(PI_LISN, SIZE_CN_ISN, nullptr) {
		throw NotYetImplementedException();
	}
	LISN(NetworkBuffer& tsdu) : BYTES(PI_LISN, tsdu) {
		throw NotYetImplementedException();
	}
	virtual ~LISN();
};

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */

#endif /* LISN_H_ */
