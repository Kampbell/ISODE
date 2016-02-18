/*
 * BUFFER.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_BUFFER_H_
#define ALS_SSAP_SPDU_BUFFER_H_
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class BUFFER : public PI {
private:
	NetworkBuffer&		value;

protected:
	BUFFER(byte i, int cc, NetworkBuffer& data) : PI(i) {
		pli(data.remaining());
		value = data;
	}

	BUFFER(int i, NetworkBuffer& tsdu) : PI(i, tsdu) {
		value = tsdu;
	}
	virtual ~BUFFER() {
	}
};

}
}
}

#endif
