/*
 * GT.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_GT_H_
#define ALS_SSAP_SPDU_GT_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class GT : public SPDU {
	// GIVE TOKENS SPDU
private:
	static const int	SMASK_GT_TOKEN = 0x0001;
	static const int	GT_SIZE = 0;
	static const int	GT_BASE_SIZE = 3;
	static const int	SMASK_SPDU_GT = 0x0002;	// to distinguish between DT and GT SPDUs

	//
	byte			gt_token = 0;

public:
	GT() : SPDU(CAT0, SPDU_GT) {
		addMask(SMASK_SPDU_GT);
	}
	GT(byte token) : SPDU(CAT0, SPDU_GT) {
		addMask(SMASK_SPDU_GT);
		gt_token = token;
		addMask(SMASK_GT_TOKEN);
	}
	GT(NetworkBuffer& tsdu) : SPDU(CAT0, SPDU_GT, tsdu)  {
		addMask(SMASK_SPDU_GT);
	}
	virtual ~GT() {
	}
	byte getToken() const { return gt_token; }
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
