/*
 * MAP.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */
#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;
#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/MAP.h"
#include "als/ssap/spdu/pi/SYNC.h"
#include "als/ssap/spdu/pi/SERIAL.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int	MAP::encode() {
		PI* pi;
		int len = 0;
		if (hasMask(SMASK_MAP_SYNC)) {
			pi = new SYNC(map_sync);	len += pi->length();	append(pi);
		}
		if (!hasMask(SMASK_MAP_SERIAL)) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		pi = new SERIAL(map_serial);	len += pi->length();	append(pi);
		if (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);	len += pi->length();	append(pi);
		}
		if (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new UDATA(spdu_ulen, spdu_udata);len += pi->length(); append(pi);
		}
		return len;
	}
	ReturnCode	MAP::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		rc = SPDU::control(tsdu); 
		if (sli() == 0)
			return OK;
		while (tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch (code) {
				case PI::PI_SYNC: {
					SYNC pi(tsdu);
					map_sync = pi.getValue();
					addMask(SMASK_MAP_SYNC);
				}
				break;
				case PI::PI_SERIAL: {
					SERIAL pi(tsdu);
					map_serial = pi.getValue();
					addMask(SMASK_MAP_SERIAL);
				}
				break;
			    case PI::PI_ENCLOSE: {
			    	ENCLOSE pi(tsdu);
			    	setEnclose(pi.getValue());
					addMask(SMASK_ENCLOSE);
			    }
				break;
			    case PI::PI_UDATA: {
			    	UDATA pi(tsdu);
					int cc = 0;
					const byte* data = pi.getValue(cc);
		    		setData(cc, data);
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
