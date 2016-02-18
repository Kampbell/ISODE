/*
 * AC.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AC_H_
#define ALS_SSAP_SPDU_AC_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/spdu/CN_AC.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AC : public CN_AC {
	// ACCEPT SPDU
public:
	AC() : CN_AC(CAT1, SPDU_AC) {
	}
	AC(NetworkBuffer& tsdu) : CN_AC(CAT1, SPDU_AC, tsdu)  {
	}
	virtual ~AC() {
	}

	void setToken(byte token) {
		ac_token = token;
		addMask(SMASK_AC_TOKEN);
	}
	const byte getToken() const {
		return ac_token;
	}
	const byte& token() const {
		return ac_token;
	}
	bool hasToken(byte token) {
		return (ac_token & token) != 0;
	}
};

}
}
}

#endif
