/*
 * CDU.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CDA_H_
#define ALS_SSAP_SPDU_CDA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CDA : public SPDU {
	// CAPABILITY DATA ACK SPDU
private:
	static const int	CDA_SIZE = SX_CDASIZE;
	static const int	CDA_BASE_SIZE = 3;
public:
	CDA() : SPDU(CAT2, SPDU_CDA) {
	}

	CDA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_CDA, tsdu)  {
	}
	virtual ~CDA() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
