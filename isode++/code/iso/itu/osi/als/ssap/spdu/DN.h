/*
 * DN.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_DN_H_
#define ALS_SSAP_SPDU_DN_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class DN : public SPDU {
	// DISCONNECT
private:
	static const int	DN_SIZE = 512;
	static const int DN_BASE_SIZE = 3;

public:
	DN() : SPDU (CAT1, SPDU_DN) {
	}

	DN(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_DN, tsdu)  {
	}
	virtual ~DN() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
