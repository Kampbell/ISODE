/*
 * RS.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Exception.h"
#include "als/ssap/AbortCode.h"
using ALS::SSAP::Exception;
using ALS::SSAP::AbortCode;


#include "als/ssap/spdu/RS.h"
#include "als/ssap/spdu/pi/TOKEN_SET.h"
#include "als/ssap/spdu/pi/RESYNC.h"
#include "als/ssap/spdu/pi/SERIAL.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/XDATA.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int	RS::encode() {
		PI*	pi;int len = 0;
		if  (hasMask(SMASK_RS_SET)) {
			pi = new TOKEN_SET(rs_settings); len += pi->length();append(pi);
		}
		if  (!hasMask(SMASK_RS_TYPE)) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		pi = new RESYNC(rs_resync); len += pi->length();append(pi);
		if  (!hasMask(SMASK_RS_SSN)) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		pi = new SERIAL(rs_serial); len += pi->length();append(pi);
	    if  (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose); len += pi->length();append(pi);
	    }
		if  (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new XDATA(spdu_ulen, spdu_udata); len += pi->length();append(pi);
		}
		return len;
	}
	ReturnCode	RS::decode(NetworkBuffer& tsdu) {
		SPDU::control(tsdu); 
		if  (sli() == 0) return OK;
		ReturnCode rc = OK;
		while(tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch(code) {
			case PI::PI_TOKEN_SET: {
		    	TOKEN_SET pi(tsdu);
		    	rs_settings = pi.getValue();
		    	addMask (SMASK_GT_TOKEN);
		    }
		    break;
		    case PI::PI_RESYNC: {
		    	RESYNC pi(tsdu);
		    	rs_resync = pi.getValue();
				switch(rs_resync) {
					case 0: // RESTART;
					case 1: // ABANDON;
					case 2: // SET;
						break;
					default: throw Exception("invalid Resync Type:");
				}
		    	addMask (SMASK_RS_TYPE);
		    }
		    break;
		    case PI::PI_SERIAL: {
		    	SERIAL pi(tsdu);
		    	rs_serial = pi.getValue();
		    	addMask (SMASK_RS_SSN);
		    }
		    break;
		    case PI::PI_ENCLOSE: {
		    	ENCLOSE pi(tsdu);
		    	setEnclose(pi.getValue());
		    	addMask (SMASK_ENCLOSE);
		    }
		    break;
		    case PI::PI_UDATA: {
		    	UDATA pi(tsdu);
				int cc = 0;
				const byte* data = pi.getValue(cc);
		    	setData(cc, data);
		    }
		    break;
		    case PI::PI_XDATA: {
		    	XDATA pi(tsdu);
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
