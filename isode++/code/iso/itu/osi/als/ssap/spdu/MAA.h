/*
 * MAA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_MAA_H_
#define ALS_SSAP_SPDU_MAA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class MAA : public SPDU {
	// MAJOR SYNC ACK SPDU
private:
	static const int	SMASK_MAA_SERIAL = 0x0001;
	static const int	MAA_SIZE = 512;
	static const int	MAA_BASE_SIZE = 11;

	nat4	maa_serial = 0;

public:
	MAA() : SPDU(CAT2, SPDU_MAA) {
	}

	MAA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_MAA, tsdu)  {
	}
	virtual ~MAA() {
	}
	void setSerial(nat4 serial) {
		addMask(SMASK_MAA_SERIAL);
		maa_serial = serial;
	}

	nat4 getSerial() const {
		return maa_serial;
	}

	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
