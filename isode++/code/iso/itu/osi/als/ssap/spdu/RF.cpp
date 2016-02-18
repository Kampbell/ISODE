/*
 * RF.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */
#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;
#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/RF.h"
#include "als/ssap/spdu/pgi/CN_ID.h"
#include "als/ssap/spdu/pi/TDISC.h"
#include "als/ssap/spdu/pi/USER_REQ.h"
#include "als/ssap/spdu/pi/VERSION.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/REASONS.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			RF::encode() {
		PI*	pi;int len = 0;PGI* pgi;
		if  (hasMask(SMASK_RF_REF)) {
			pgi = new CN_ID(CALLED, rf_reference); len += pgi->length();append(pgi);
		}
		if  (hasMask(SMASK_RF_DISC)) {
       		pi = new TDISC(rf_disconnect); len += pi->length();append(pi);
		}
		if  (hasMask(SMASK_RF_REQ)) {
       		pi = new USER_REQ(rf_require); len += pi->length();append(pi);
		}
		if  (hasMask(SMASK_RF_VRSN)) {
       		pi = new VERSION(rf_version); len += pi->length();append(pi);
		}
		if  (len > RF_SIZE) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		if  (hasMask(SMASK_ENCLOSE)) {
      		pi = new ENCLOSE(spdu_enclose); len += pi->length();append(pi);
		}
		if  (len > 0) {
       		pi = new REASONS(rf_cc, rf_data); len += pi->length();append(pi);
		}
		return len;
	}
	ReturnCode	RF::decode(NetworkBuffer& tsdu) {
		return SPDU::control(tsdu); 
	}

}
}
}
