/*
 * ADA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ADA_H_
#define ALS_SSAP_SPDU_ADA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ADA : public SPDU {
	// ACTIVITY DISCARD ACK SPDU
private:
	static const int		ADA_SIZE = 0;
	static const int	ADA_BASE_SIZE = 0;

public:
	ADA() : SPDU(CAT2, SPDU_ADA) {
	}

	ADA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_ADA, tsdu)  {
	}
	virtual ~ADA() {
	}
	int			encode()	{ return 0; }
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
