/*
 * TD.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_TD_H_
#define ALS_SSAP_SPDU_TD_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class TD : public SPDU {
	// TYPED DATA SPDU
private:
	static const int	TD_SIGHS = 65535;	/* should be TD_SIZE, but <tsap.h>	got there first */
	static const int	TD_MINSIZE = 64;	/* don't segment if MSS < this */
	static const int	TD_BASE_SIZE = 3;

public:
	TD() : SPDU (CAT1, SPDU_TD) {
	}

	TD(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_TD, tsdu)  {
	}
	virtual ~TD() {
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
