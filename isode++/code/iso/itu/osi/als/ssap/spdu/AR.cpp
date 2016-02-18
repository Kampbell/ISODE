/*
 * AR.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */
#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;
#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;


#include "als/ssap/spdu/AR.h"
#include "als/ssap/spdu/pgi/AR_LINK.h"
#include "als/ssap/spdu/pi/ACT_ID.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/UDATA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	int			AR::encode() {
		PI* pi;PGI* pgi;
		int len = 0;

		if (hasMask(SMASK_AR_REF)) {
			pgi = new AR_LINK(*this);len += pgi->length();append(pgi);
		}
		if (!hasMask(SMASK_AR_ID)) {
			throw Exception(AbortCode::SC_PROTOCOL);
		}
		if (hasMask(SMASK_AR_ID)) {
			pi = new ACT_ID(ar_id.cc(), ar_id.data());len += pi->length();append(pi);
		}
		if (hasMask(SMASK_ENCLOSE)) {
			pi = new ENCLOSE(spdu_enclose);len += pi->length();append(pi);
		}
		if (spdu_udata != nullptr && spdu_ulen > 0) {
			pi = new UDATA(spdu_ulen, spdu_udata);len += pi->length(); append(pi);
		}
		return len;
	}
	ReturnCode	AR::decode(NetworkBuffer& tsdu) {
		ReturnCode rc = OK;
		rc = SPDU::control(tsdu); 
		if (sli() == 0)
			return OK;
		while (tsdu.hasRemaining()) {
			tsdu.markit();
			byte code = tsdu.get();
			switch (code) {
				case PGI::PGI_AR_LINK: {
					AR_LINK pgi(*this, tsdu);
					addMask(SMASK_AR_REF);
				}
					break;
				case PI::PI_ACT_ID: {
					ACT_ID pi(tsdu);
					int cc = 0;
					const byte* data = pi.getValue(cc);
					ar_id = ActivityId(cc, data);
					addMask(SMASK_AS_ID);
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
					if (pi.pli() > MAX_CONNECT_DATA_SIZE) {
						throw Exception(AbortCode::SC_PROTOCOL);
					}
					addMask(SMASK_UDATA_PGI);
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
