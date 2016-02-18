/*
 * AIA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AIA_H_
#define ALS_SSAP_SPDU_AIA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AIA : public SPDU {
	// ACTIVITY INTERRUPT (ABORT) SPDU
private: 
	static const int	SMASK_AI_REASON = 0x0001;	// don't collide with SMASK_AB_DISC
	static const int	AI_SIZE = 0;
	static const int	AI_BASE_SIZE = 3;

	byte				ai_reason;

public:
	AIA() : SPDU(CAT2, SPDU_AIA) {
	}

	AIA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AIA, tsdu)  {
	}
	virtual ~AIA() {
	}
	int			encode()	{ return 0; }
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
