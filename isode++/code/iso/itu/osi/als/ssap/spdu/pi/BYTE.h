/*
 * BYTE.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_BYTE_H_
#define ALS_SSAP_SPDU_BYTE_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class BYTE : public PI {
private:
	byte	value;

protected:
	BYTE(byte pi, byte option) : PI(pi) {
		pli(1);
		value = option;
	}

	BYTE(byte pi, NetworkBuffer& tsdu) : PI(pi, tsdu) {
		if (pli() <= 1) {
			value = tsdu.get();
		}
		else {
			throw  RuntimeException();
		}
	}
	virtual ~BYTE() {
	}
	virtual NetworkBuffer* toTSDU() { return nullptr; }
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->put(value);
		return OK;
	}

public:
	byte getValue() const {
		return value;
	}
};

}
}
}

#endif
