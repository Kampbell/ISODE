/*
 * LONG.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_LONG_H_
#define ALS_SSAP_SPDU_LONG_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class LONG : public PI {
private:
	int4 value;
public:
	LONG(byte pi, long l) : PI(pi) {
		pli(sizeof(value));
		value = l;
	}
	LONG(byte pi, NetworkBuffer& tsdu) : PI(pi, tsdu) {
		pli(sizeof(value));
		value = tsdu.getInteger();
	}
	virtual ~LONG() {
	}
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->putInteger(value);
		return OK;
	}
	int4 getValue() {
		return value;
	}
};

}
}
}

#endif
