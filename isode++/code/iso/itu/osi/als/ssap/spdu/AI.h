/*
 * AI.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AI_H_
#define ALS_SSAP_SPDU_AI_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AI : public SPDU {
	// ACTIVITY INTERRUPT (ABORT) SPDU
private:
	static const int	SMASK_AI_REASON = 0x0001;	// don't collide with SMASK_AB_DISC
	static const int	AI_SIZE = 0;
	static const int	AI_BASE_SIZE = 3;

	byte				ai_reason;

public:
	AI() : SPDU(CAT2, SPDU_AI) {
	}

	AI(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AI, tsdu)  {
	}
	virtual ~AI() {
	}
	int			encode()	{ return 0; }
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
