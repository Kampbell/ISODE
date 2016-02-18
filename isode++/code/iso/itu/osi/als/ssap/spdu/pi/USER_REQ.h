/*
 * USER_REQ.h
 *
 *  Created on: 10 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_USER_REQ_H_
#define ALS_SSAP_SPDU_USER_REQ_H_
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/Requirement.h"
using ALS::SSAP::Requirement;
#include "als/ssap/spdu/pi/SHORT.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class USER_REQ : public SHORT {
public:
	USER_REQ(const Requirement& requirement) : SHORT(PI_USER_REQ, (short)requirement.to_ulong()) {}
	USER_REQ(NetworkBuffer& tsdu): SHORT(PI_USER_REQ, tsdu) {}
	virtual ~USER_REQ() {
	}
	virtual int prepare() { return 0; };
	virtual int close()   { return 0; };
};

}
}
}

#endif
