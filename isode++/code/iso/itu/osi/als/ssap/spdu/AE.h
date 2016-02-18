/*
 * AE.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AE_H_
#define ALS_SSAP_SPDU_AE_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AE : public SPDU {
	// ACTIVITY END (MAJOR SYNC) SPDU
private:
	static const int		AE_SIZE = 512;
	static const int	AE_BASE_SIZE = 8;

	nat4	ae_serial = 0;

public:
	AE() : SPDU(CAT2, SPDU_AE) {
	}

	AE(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AE, tsdu)  {
	}
	virtual ~AE() {
	}
	void setSerial(nat4 serial) {
		ae_serial = serial;
		addMask(SMASK_MAP_SERIAL);
	}
	nat4 getSerial() const {
		return ae_serial;
	}
	const nat4& ssn() const {
		return ae_serial;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
