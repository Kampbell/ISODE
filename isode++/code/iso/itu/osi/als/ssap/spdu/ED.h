/*
 * ED.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ED_H_
#define ALS_SSAP_SPDU_ED_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ED : public SPDU {
	// EXCEPTION DATA SPDU
private:
	static const int	SMASK_ED_REASON = 0x0001;
	static const int	ED_SIZE = 512;
	static const int	ED_BASE_SIZE = 6;

	byte			ed_reason;

public:
	ED() : SPDU(CAT2, SPDU_ED) {
	}

	ED(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_ED, tsdu)  {
	}
	virtual ~ED() {
	}
	void setReason(byte reason) {
		addMask(SMASK_ED_REASON);
		ed_reason = reason;
	}
	byte getReason() const {
		return ed_reason;
	}

	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
