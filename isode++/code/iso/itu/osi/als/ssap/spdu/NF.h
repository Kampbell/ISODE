/*
 * NF.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_NF_H_
#define ALS_SSAP_SPDU_NF_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class NF : public SPDU {
	// NOT FINISHED SPDU (RELEASE)
private:
	static const int	NF_SIZE = 512;
	static const int NF_BASE_SIZE = 3;

public:
	NF() : SPDU (CAT1, SPDU_NF) {
	}

	NF(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_NF, tsdu)  {
	}
	virtual ~NF() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
