/*
 * GTC.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_GTC_H_
#define ALS_SSAP_SPDU_GTC_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class GTC : public SPDU {
	// GIVE TOKENS CONFIRM SPDU
private:
	static const int	GTC_SIZE = 0;
	static const int	GTC_BASE_SIZE = 0;

public:
	GTC() : SPDU (CAT1, SPDU_GTC) {
	}

	GTC(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_GTC, tsdu)  {
	}
	virtual ~GTC() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
