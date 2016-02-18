/*
 * INT.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_INT_H_
#define ALS_SSAP_SPDU_INT_H_
#include "Poco/ByteOrder.h"
using Poco::ByteOrder;

#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class INT : public PI {
private:
	int4 value;

protected:
	INT(byte pi, const int4& i) : PI(pi) {
		pli(sizeof(value));
		value = i;
	}
	INT(byte pi, NetworkBuffer& tsdu) : PI(pi, tsdu) {
		pli(sizeof(value));
 		value = tsdu.getInt();
	}
	virtual ~INT() {
	}
	virtual NetworkBuffer* toTSDU() { return nullptr; }
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->putInt(value);
		return OK;
	}

public:
	int4 getValue() {
		return value;
	}


};

}
}
}

#endif
