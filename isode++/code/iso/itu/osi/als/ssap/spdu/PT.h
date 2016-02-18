/*
 * PT.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PT_H_
#define ALS_SSAP_SPDU_PT_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class PT : public SPDU {
	// PLEASE TOKENS SPDU
private:
	static const int	SMASK_PT_TOKEN = 0x0001;
	static const int	PT_SIZE = 512;
	static const int	PT_BASE_SIZE = 6;

	byte	pt_token = 0;

public:
	PT() : SPDU(CAT0, SPDU_PT) {
	}
	PT(byte tokens) : SPDU(CAT0, SPDU_PT) {
		pt_token = tokens;
		addMask(SMASK_PT_TOKEN);
	}

	PT(NetworkBuffer& tsdu) : SPDU(CAT0, SPDU_PT, tsdu)  {
	}
	virtual ~PT() {
	}
	void setToken(byte token) {
		addMask(SMASK_PT_TOKEN);
		pt_token = token;
	}
	byte getToken() const {
		return pt_token;
	}

	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
