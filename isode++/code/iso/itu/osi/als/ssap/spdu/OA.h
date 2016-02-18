/*
 * OA.h
 *
 *  Created on: 22 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_OA_H_
#define ALS_SSAP_SPDU_OA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class OA : public SPDU {
public:
	OA() : SPDU(CAT1, SPDU_OA) {
	}

	OA(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_OA, tsdu)  {
	}
	virtual ~OA() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */

#endif /* OA_H_ */
