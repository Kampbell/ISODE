/*
 * ISN.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_ISN_H_
#define ALS_SSAP_SPDU_ISN_H_
#include <string>
using std::stoi;

#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/pi/BYTES.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class ISN : public BYTES {
private:
	long value;
	char bytes[SIZE_CN_ISN + 1];
public:
	ISN(int isn) : BYTES(PI_ISN, SIZE_CN_ISN, bytes) {
		char  work[32];
		sprintf(work, "%0*d", SIZE_CN_ISN, isn);
		memcpy(bytes, work, SIZE_CN_ISN);
	}
	ISN(NetworkBuffer& tsdu) : BYTES(PI_ISN, tsdu) {
		memcpy(bytes, BYTES::value, pli());
		bytes[SIZE_CN_ISN] = 0;
		value = stoi(bytes);
		
	}
	virtual ~ISN() {
	}
	long getValue() {
		return value;
	}
	NetworkBuffer *toTSDU(void) { return nullptr;  }
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		tsdu->putBytes(SIZE_CN_ISN, bytes);
		return OK;
	}
};

}
}
}

#endif
