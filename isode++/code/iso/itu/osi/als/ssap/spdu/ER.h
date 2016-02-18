/*
 * ER.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ER_H_
#define ALS_SSAP_SPDU_ER_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ER : public SPDU {
	// EXCEPTION REPORT SPDU
private:
	static const int	ER_SIZE = 0;
	static const int ER_BASE_SIZE = 0;

public:
	ER() : SPDU(CAT2, SPDU_ER) {
	}

	ER(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_ER, tsdu)  {
	}
	virtual ~ER() {
	}
	int			encode()	{ return 0; }
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
