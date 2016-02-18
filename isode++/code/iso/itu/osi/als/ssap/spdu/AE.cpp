/*
 * AE.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */
#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;
#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/AE.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/SERIAL.h"


namespace ALS {
namespace SSAP {
namespace SPDU {
		int	AE::encode() {
		PI* pi;
		int len = 0;
		if (!hasMask(SMASK_MAP_SERIAL)) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		pi = new SERIAL(ae_serial);	len += pi->length();append(pi);
		if  (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);len += pi->length();append(pi);
		}
		return len;
	}
	ReturnCode	AE::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		rc = SPDU::control(tsdu); 
		if (sli() == 0)
			return OK;
		while (tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch (code) {
				case PI::PI_SERIAL: {
					SERIAL pi(tsdu);
					ae_serial = pi.getValue();
					addMask(SMASK_MAP_SERIAL);
				}
				break;
				case PI::PI_ENCLOSE: {
					ENCLOSE pi(tsdu);
					setEnclose(pi.getValue());
					addMask(SMASK_ENCLOSE);
				}
				break;
				default:
					tsdu.reset();
					goto EXIT;
			}
		}
	 EXIT:
		 return rc;
	}

}
}
}
