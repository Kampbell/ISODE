/*
 * BYTES.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_BYTES_H_
#define ALS_SSAP_SPDU_BYTES_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class BYTES : public PI {
protected:
	int size;
	byte* value;
	bool owner;
protected:
	BYTES(byte pi, int cc, const void* data) : PI(pi) {
		pli(cc);
		size = cc;
		value = (byte*)data;
		owner = false;
	}

	BYTES(int pi, NetworkBuffer& tsdu) : PI(pi, tsdu) {
		value = new byte[size = pli()];
		tsdu.getBytes(size, value);
		owner = true;
	}
	virtual ~BYTES() {
		if (owner) delete value;
	}
	virtual NetworkBuffer* toTSDU() { return nullptr; }
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->putBytes(size, value);
		return OK;
	}

public:
	const byte* getValue(int& len) const { len = size; return value; }
};

}
}
}

#endif
