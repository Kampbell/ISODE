/*
 * CN_AC.cpp
 *
 *  Created on: 23 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;

#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/CN_AC.h"
#include "als/ssap/spdu/pgi/CN_ID.h"
#include "als/ssap/spdu/pgi/CN_ITEMS.h"
#include "als/ssap/spdu/pi/USER_REQ.h"
#include "als/ssap/spdu/pi/SSAP_CALLING.h"
#include "als/ssap/spdu/pi/SSAP_CALLED.h"
#include "als/ssap/spdu/pi/XDATA.h"
#include "als/ssap/spdu/pi/UDATA.h"
#include "als/ssap/spdu/pi/CALLED_SS.h"
#include "als/ssap/spdu/pi/CALLING_SS.h"
#include "als/ssap/spdu/pi/COMMON_REF.h"
#include "als/ssap/spdu/pi/ADD_INFO.h"
#include "als/ssap/spdu/pi/VERSION.h"
#include "als/ssap/spdu/pi/ISN.h"
#include "als/ssap/spdu/pi/TOISN.h"
#include "als/ssap/spdu/pi/VERSION.h"
#include "als/ssap/spdu/pi/TOKEN.h"


namespace ALS {
namespace SSAP {
namespace SPDU {
	void CN_AC::reset() {
		cn_options = 0;
		cn_tsdu_init = 0;
		cn_tsdu_resp = 0;
		cn_version = 0;
		cn_isn = 0;
		cn_settings = 0;
		cn_require = 0;
		memset(cn_calling, 0, sizeof(cn_calling));
		cn_callinglen = 0;
		memset(cn_called, 0, sizeof(cn_called));
		cn_calledlen = 0;
	}
	CN_AC::CN_AC(Category cat, byte si) : SPDU(cat, si){
		reset();
	}
	CN_AC::CN_AC(Category cat, byte si, NetworkBuffer& tsdu) : SPDU(cat, si, tsdu) {
		reset();
	}
	CN_AC::~CN_AC() {
	}
	int CN_AC::encode() {
		PI* pi;
		PGI* pgi;
		int len = 0;
		if (hasMask(SMASK_CN_REF)) {
			pgi = new CN_ID(CALLED, cn_reference);
			len += pgi->length();
			append(pgi);
		}
		if (hasMask(SMASK_CN_OPT | SMASK_CN_TSDU | SMASK_CN_VRSN | SMASK_CN_ISN | SMASK_CN_SET)) {
			pgi = new CN_ITEMS(const_cast<CN_AC&>(*this));
			len += pgi->length();
			append(pgi);
		}
		if (hasMask(SMASK_CN_REQ)) {
			pi = new USER_REQ(cn_require);
			len += pi->length();
			append(pi);
		}
		if (hasMask(SMASK_CN_CALLING)) {
			pi = new SSAP_CALLING(cn_callinglen, cn_calling);
			len += pi->length();
			append(pi);
		}
		if (hasMask(SMASK_CN_CALLED)) {
			pi = new SSAP_CALLED(cn_calledlen, cn_called);
			len += pi->length();
			append(pi);
		}
		if (hasMask(SMASK_AC_TOKEN)) {
			if (si() != SPDU_AC) {
				//FIXME throw exception
			}
			pi = new TOKEN(ac_token);
			len += pi->length();
			append(pi);
		}
		if (spdu_udata != nullptr && spdu_ulen > 0) {
			if (spdu_ulen > CN_SIZE) {
				pi = new XDATA(spdu_ulen, spdu_udata);
				len += pi->length();
			}
			else {
				pi = new UDATA(CN_SIZE, spdu_udata);
				len += pi->length();
			}
			append(pi);
		}

		return len;
	}
	ReturnCode CN_AC::decode(NetworkBuffer& tsdu) {
		SPDU::control(tsdu);
		if (sli() == 0)
			return OK;
		ReturnCode rc = OK;
		while (tsdu.hasRemaining()) {
		/*			
		switch (code) {
			case PI_UDATA:
			if (!bool(pmask & PMASK_UDATA) || li() > 512)
			spkt.spdu_errno = SC_PROTOCOL;
			break;

			case PI_XDATA:
			if (!bool(pmask & PMASK_XDATA) || li() <= 512)
			spkt.spdu_errno = SC_PROTOCOL;
			break;

			default:
			if (bool(code < pi_table.length) && bool(pi_table[code])
			&& !bool(pmask & pi_table[code]))
			spkt.spdu_errno = SC_PROTOCOL;
			break;
			}
			if (code < pi_table.length && bool(pi_table[code])&& !bool(pi_table[code] & PMASK_PGI)) {
			if (li() > 0) {
			if (bool(pi_table[code] & PMASK_VARLEN)) {
			if (li() > pi_length[code]) {
			spkt.spdu_errno = SC_PROTOCOL;
			//							break;
			}
			} else
			if (li() != pi_length[code]) {
			spkt.spdu_errno = SC_PROTOCOL;
			//						break;
			}
			}
		}
		*/
			tsdu.markit();
			byte code = tsdu.get() & 0xFF;
			switch (code) {
			case PGI::PGI_CN_ID: {
				CN_ID pi(*this, tsdu);
				addMask(SMASK_CN_REF);
			}
				break;
			case PGI::PGI_CN_ITEMS: {
				CN_ITEMS pgi(*this, tsdu);
				addMask(SMASK_CN_REF);
			}
				break;
			case PI::PI_CALLED_SS: {
				CALLED_SS pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_reference.udata(length, data);
				addMask(SMASK_CN_REF);
			}
				break;
			case PI::PI_CALLING_SS: {
				//				case PI_AR_CALLED:
				//				case PI_AR_CALLING:
				CALLING_SS pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_reference.udata(length, data);
				addMask(SMASK_CN_REF);
			}
				break;
			case PI::PI_COMMON_REF: {
				//				case PI_AR_COMMON:
				COMMON_REF pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_reference.cdata(length, data);
				addMask(SMASK_CN_REF);
			}
				break;
			case PI::PI_ADD_INFO: {
				//				    case PI_AR_ADDT:
				ADD_INFO pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_reference.adata(length, data);
				addMask(SMASK_CN_REF);
			}
				break;
			case PI::PI_VERSION: {
				VERSION pi(tsdu);
				cn_version = pi.getValue();
				addMask(SMASK_CN_VRSN);
			}
				break;
			case PI::PI_USER_REQ: {
				USER_REQ pi(tsdu);
				cn_require = pi.getValue();
				addMask(SMASK_CN_REQ);
			}
				break;
			case PI::PI_ISN: {
				ISN pi(tsdu);
				cn_isn = pi.getValue();
				addMask(SMASK_CN_ISN);
			}
				break;
			case PI::PI_TOKEN: {
				if (si() != SPDU_AC) {
					//FIXME throw exception
				}
				TOKEN pi(tsdu);
				ac_token = pi.getValue();
				addMask(SMASK_AC_TOKEN);
			}
				break;
			case PI::PI_TOISN: {/* not supported yet */

			}
				break;
			case PI::PI_SSAP_CALLING: {
				SSAP_CALLING pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_callinglen = pi.pli();
				//FIXME check cn_callinglen == length
				memcpy(cn_calling, data, min(cn_callinglen, sizeof(cn_calling)));
				addMask(SMASK_CN_CALLING);
			}
				break;
			case PI::PI_SSAP_CALLED: {
				SSAP_CALLED pi(tsdu);
				int length = 0;
				const byte* data = pi.getValue(length);
				cn_calledlen = pi.pli();
				//FIXME check cn_callinglen == length
				memcpy(cn_called, data, min(cn_calledlen, sizeof(cn_calling)));
				addMask(SMASK_CN_CALLED);
			}
				break;
			case PI::PI_UDATA: {
				UDATA pi(tsdu);
				addMask(SMASK_UDATA_PGI);
				if (pi.pli() > 0) {
					// if (si() == SPDU_AB && !spkt.hasMask(SMASK_SPDU_AB)) {
					//     throw  SSAPException(SC_PROTOCOL);
					// } else
					if (pi.pli() > MAX_CONNECT_DATA_SIZE) {
						throw  Exception(AbortCode::SC_PROTOCOL);
					}
					int length = 0;
					const byte* data = pi.getValue(length);
					setData(length, data);
				}
			}
				break;
			case PI::PI_XDATA: {
				XDATA pi(tsdu);
				addMask(SMASK_UDATA_PGI);
				if (pi.pli() > 0) {
					// if (si() == SPDU_AB && !spkt.hasMask(SMASK_SPDU_AB)) {
					// throw  SSAPException(SC_PROTOCOL);
					//						} else
					if (pi.pli() > MAX_CONNECT_DATA_SIZE) {
						throw  Exception(AbortCode::SC_PROTOCOL);
					}
					int length = 0;
					const byte* data = pi.getValue(length);
					setData(length, data);
				}
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
