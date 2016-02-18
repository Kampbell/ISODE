/*
 * GTA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_GTA_H_
#define ALS_SSAP_SPDU_GTA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class GTA : public SPDU {
	// GIVE TOKENS ACK SPDU
private:
	static const int	GTA_SIZE = 0;
	static const int	GTA_BASE_SIZE = 0;

public:
	GTA() : SPDU (CAT1, SPDU_GTA) {
	}

	GTA(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_GTA, tsdu)  {
	}
	virtual ~GTA() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
