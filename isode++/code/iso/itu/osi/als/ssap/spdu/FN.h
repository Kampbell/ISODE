/*
 * FN.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_FN_H_
#define ALS_SSAP_SPDU_FN_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class FN : public SPDU {
	// FINISH SPDU
private:
	static const int	SMASK_FN_DISC = 0x0001;
	static const int	FN_DISC_RELEASE = 0x01;	// release transport connection
	static const int	FN_DISC_MASK = FN_DISC_RELEASE;
	static const int	FN_SIZE = 512;
	static const int	FN_BASE_SIZE = 6;

	byte fn_disconnect = 0;

public:
	FN() : SPDU (CAT1, SPDU_FN) {
	}

	FN(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_FN, tsdu)  {
	}
	virtual ~FN() {
	}
	void setDisconnect(byte disconnect) {
		addMask(SMASK_FN_DISC);
		fn_disconnect = disconnect;
	}
	byte getDisconnect() const {
		return fn_disconnect;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
