/*
 * SERIAL.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SERIAL_H_
#define ALS_SSAP_SPDU_SERIAL_H_
#include "als/ssap/Exception.h"
#include "als/ssap/AbortCode.h"
using ALS::SSAP::Exception;
using ALS::SSAP::AbortCode;
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class SERIAL : public PI {
private:
	nat4 ssn;
public:
	SERIAL(nat4 serial) : PI(PI_SERIAL) {
		pli(SIZE_CN_ISN);
		ssn = serial;
	}
	SERIAL(NetworkBuffer& tsdu) : PI(PI_SERIAL, tsdu) {
		char ssnc[SIZE_CN_ISN + 1];
		if (pli() > SIZE_CN_ISN)
			throw Exception(AbortCode::SC_PROTOCOL);
		tsdu.getBytes(pli(), ssnc);
		ssnc[pli()] = 0;
		ssn = strtol(ssnc, nullptr, 10);
	}
	virtual ~SERIAL() {
	}
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const {
		HEADER::encode(tsdu);
		char ssnc[SIZE_CN_ISN + 1];
		sprintf(ssnc, "%0*d", SIZE_CN_ISN, ssn);
		tsdu->putBytes(SIZE_CN_ISN, ssnc);
		return OK;
	}
	nat4 getValue() const {
		return ssn;
	}
	virtual NetworkBuffer* toTSDU() {
		return nullptr;
	}
};

}
}
}

#endif
