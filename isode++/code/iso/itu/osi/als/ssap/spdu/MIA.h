/*
 * MIA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_MIA_H_
#define ALS_SSAP_SPDU_MIA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class MIA : public SPDU {	// MINOR SYNC ACK SPDU
private:
	static const int	SMASK_MIA_SERIAL = 0x0001;
	static const int	MIA_SIZE = 512;
	static const int	MIA_BASE_SIZE = 11;

	nat4	mia_serial;

public:
	MIA() : SPDU(CAT2, SPDU_MIA) {
	}

	MIA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_MIA, tsdu)  {
	}
	virtual ~MIA() {
	}
	void setSerial(int serial) {
		addMask(SMASK_MIA_SERIAL);
		mia_serial = serial;
	}

	nat4 getSerial() const {
		return mia_serial;
	}
	const nat4& ssn() const {
		return mia_serial;
	}

	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
