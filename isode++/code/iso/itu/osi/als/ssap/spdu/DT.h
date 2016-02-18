/*
 * DT.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_DT_H_
#define ALS_SSAP_SPDU_DT_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class DT : public SPDU {
	// DATA TRANSFER SPDU
private:
	static const int	DT_SIZE = 65535;
	static const int	DT_MINSIZE = 64;	// don't segment if MSS < this
	static const int	DT_BASE_SIZE = 3;

public:
	DT() : SPDU(CAT2, SPDU_DT) {
	}

	DT(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_DT, tsdu)  {
	}
	virtual ~DT() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
