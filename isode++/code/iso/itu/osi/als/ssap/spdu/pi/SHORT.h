/*
 * SHORT.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SHORT_H_
#define ALS_SSAP_SPDU_SHORT_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class SHORT : public PI {
private:
	nat2 value;
protected:
	SHORT(byte pi, nat2 s) : PI(pi) {
		pli(sizeof(nat2));
		value = s;
	}
	SHORT(byte pi, NetworkBuffer& tsdu) : PI(pi, tsdu) {
		value = tsdu.getShort();
	}
	virtual ~SHORT() {
	}
public:
	virtual NetworkBuffer* toTSDU() { return nullptr; }
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->putShort(value);
		return OK;
	}
	nat2 getValue() {
		return value;
	}
};

}
}
}

#endif
