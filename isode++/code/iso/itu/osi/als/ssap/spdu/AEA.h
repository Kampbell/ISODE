/*
 * AEA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AEA_H_
#define ALS_SSAP_SPDU_AEA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AEA : public SPDU {	// ACTIVITY END (MAJOR SYNC) ACK SPDU
private:
	static const int		SMASK_AEA_SERIAL = 0x0001;
	static const int		AEA_SIZE = 512;
	static const int	AEA_BASE_SIZE = 11;

	nat4 aea_serial = 0;

public:
	AEA() : SPDU(CAT2, SPDU_AEA) {
	}

	AEA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AEA, tsdu)  {
	}
	virtual ~AEA() {
	}
	void setSerial(nat4 serial) {
		aea_serial = serial;
		addMask(SMASK_AEA_SERIAL);
	}
	nat4 getSerial() const {
		return aea_serial;
	}
	const nat4& ssn() const {
		return aea_serial;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
