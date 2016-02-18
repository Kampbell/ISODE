/*
 * DTO.h
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_DTO_H_
#define ALS_SSAP_SPDU_DTO_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"


namespace ALS {
namespace SSAP {
namespace SPDU {

class DTO : public BYTES {
public:
	DTO(int isn) : BYTES(PI_DTO, SIZE_CN_ISN, nullptr) {
		throw NotYetImplementedException();
	}
	DTO(NetworkBuffer& tsdu) : BYTES(PI_DTO, tsdu) {
		throw NotYetImplementedException();
	}
	virtual ~DTO();
};

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */

#endif /* DTO_H_ */
