/*
 * EX.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_EX_H_
#define ALS_SSAP_SPDU_EX_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class EX : public SPDU {
	// EXPEDITED DATA SPDU
private:
	static const int	EX_SIZE = SX_EXSIZE;
	static const int	EX_BASE_SIZE = 0;

public:
	EX() : SPDU(CAT2, SPDU_EX) {
	}

	EX(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_EX, tsdu)  {
	}
	virtual ~EX() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
