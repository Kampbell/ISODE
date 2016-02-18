/*
 * PR.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PR_H_
#define ALS_SSAP_SPDU_PR_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class PR : public SPDU {
	// PREPARE SPDU
private:
	static const int SMASK_PR_TYPE = 0x0001;
	static const int PR_MAA = 1; // expect SPDU_MAA
	static const int PR_RS = 2; // expect SPDU_RS
	static const int PR_RA = 3; // expect SPDU_RA
	static const int PR_AB = 4; // expect SPDU_AB
	static const int PR_MAX = PR_AB;
	static const int PR_SIZE = 0;
	static const int PR_BASE_SIZE = 3;

	//
	byte pr_type;

public:
	PR() : SPDU (CAT1, SPDU_PR) {
	}
	PR(byte type) : SPDU (CAT1, SPDU_PR) {
		pr_type = type;
		addMask(SMASK_PR_TYPE);
	}
	PR(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_PR, tsdu)  {
	}
	virtual ~PR() {
	}
	byte getType() const {
		return pr_type;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
