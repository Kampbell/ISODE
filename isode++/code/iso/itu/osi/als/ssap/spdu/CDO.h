/*
 * CDO.h
 *
 *  Created on: 22 nov. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CDO_H_
#define ALS_SSAP_SPDU_CDO_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CDO : public SPDU {
public:
	// CONNECT DATA OVERFLOW SPDU
public:
	CDO() : SPDU(CAT1, SPDU_CDO) {
	}

	CDO(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_CDO, tsdu)  {
	}
	virtual ~CDO() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */

#endif /* CDO_H_ */
