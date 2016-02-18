/*
 * AD.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AD_H_
#define ALS_SSAP_SPDU_AD_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AD : public SPDU {
	// ACTIVITY DISCARD SPDU
private:
	static const int	SMASK_AD_REASON = 0x0001;
	static const int	AD_SIZE = 0;
	static const int	AD_BASE_SIZE = 3;

	//
	byte			ad_reason;

public:
	AD() : SPDU(CAT2, SPDU_AD) {
	}
	AD(byte reason) : SPDU(CAT2, SPDU_AD) {
		ad_reason = reason;
		addMask(SMASK_AD_REASON);
	}

	AD(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AD, tsdu)  {
	}
	virtual ~AD() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
