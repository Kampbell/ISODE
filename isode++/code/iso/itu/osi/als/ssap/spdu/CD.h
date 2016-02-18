/*
 * CD.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CD_H_
#define ALS_SSAP_SPDU_CD_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CD : public SPDU {
	// CAPABILITY DATA SPDU 
private:
	static const int	CD_SIZE = SX_CDSIZE;
	static const int	CD_BASE_SIZE = 3;

public:
	CD() : SPDU(CAT2, SPDU_CD) {
	}

	CD(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_CD, tsdu)  {
	}
	virtual ~CD() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
