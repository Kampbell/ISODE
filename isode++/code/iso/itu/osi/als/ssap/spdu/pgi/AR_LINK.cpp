/*
 * AR_LINK.cpp
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/pgi/AR_LINK.h"
#include "als/ssap/spdu/pi/AR_CALLED.h"
#include "als/ssap/spdu/pi/AR_CALLING.h"
#include "als/ssap/spdu/pi/AR_COMMON.h"
#include "als/ssap/spdu/pi/AR_ADDT.h"
#include "als/ssap/spdu/pi/ACT_ID.h"
#include "als/ssap/spdu/pi/AR_ADDT.h"
#include "als/ssap/spdu/pi/SERIAL.h"
#include "als/ssap/spdu/AR.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	AR_LINK::AR_LINK(AR& spdu_ar) : PGI(PGI_AR_LINK) {
		/*
		start_pgi (PGI_AR_LINK, &c);
		If_Set (SMASK_AR_REF) {
		if (s_ar_reference.sr_called_len)
		put2spdu (PI_AR_CALLED, (int) s_ar_reference.sr_called_len, s_ar_reference.sr_called, &c);
		if (s_ar_reference.sr_calling_len)
		put2spdu (PI_AR_CALLING, (int) s_ar_reference.sr_calling_len,
		s_ar_reference.sr_calling, &c);
		if (s_ar_reference.sr_clen)
		put2spdu (PI_AR_COMMON, (int) s_ar_reference.sr_clen,  s_ar_reference.sr_cdata, &c);
		if (s_ar_reference.sr_alen)
		put2spdu (PI_AR_ADDT, (int) s_ar_reference.sr_alen,  s_ar_reference.sr_adata, &c);
		}
		If_Reset (SMASK_AR_OID) {
		s_errno = SC_PROTOCOL;
		break;
		}
		put2spdu (PI_ACT_ID, (int) s_ar_oid.sd_len, s_ar_oid.sd_data, &c);
		If_Reset (SMASK_AR_SSN) {
		s_errno = SC_PROTOCOL;
		break;
		}
		Put_SSN (PI_SERIAL, s_ar_serial);
		end_pgi (&c);

		*/
	}
	AR_LINK::AR_LINK(AR& spdu_ar, NetworkBuffer& tsdu) : PGI(PGI_AR_LINK, tsdu) {
		const byte* called = nullptr;
		const byte* calling = nullptr;
		const byte* common = nullptr;
		const byte* additional = nullptr;
		Reference ref;
		int len = 0;
		byte code;

		while (tsdu.hasRemaining() && len < hli()) {
			tsdu.markit();
			code = tsdu.get();
			switch (code) {
			case PI::PI_AR_CALLED: {
				AR_CALLED pi(tsdu);
				int cc = 0;
				called = pi.getValue(cc);
				ref.vdata(cc, called);
				spdu_ar.addMask(AR::SMASK_AR_REF); len += pi.length();
			}
				break;
			case PI::PI_AR_CALLING: {
				AR_CALLING pi(tsdu);
				int cc = 0;
				calling = pi.getValue(cc);
				ref.udata(cc, calling);
				spdu_ar.addMask(AR::SMASK_AR_REF); len += pi.length();
			}
				break;
			case PI::PI_AR_COMMON: {
				AR_COMMON pi(tsdu);
				int cc = 0;
				common = pi.getValue(cc);
				ref.cdata(cc, common);
				spdu_ar.addMask(AR::SMASK_AR_REF); len += pi.length();
			}
				break;
			case PI::PI_AR_ADDT: {
				AR_ADDT pi(tsdu);
				int cc = 0;
				additional = pi.getValue(cc);
				ref.adata(cc, additional);
				spdu_ar.addMask(AR::SMASK_AR_REF); len += pi.length();
			}
				break;
			case PI::PI_ACT_ID: {
				ACT_ID pi(tsdu);
				int cc = 0;
				const byte* data = pi.getValue(cc);
				spdu_ar.setOldActivityId(ActivityId(cc, data));
				spdu_ar.addMask(AR::SMASK_AR_OID); len += pi.length();
			}
				break;
			case PI::PI_SERIAL: {
				SERIAL pi(tsdu);
				long serial = pi.getValue();
				spdu_ar.setSerial(serial);
				spdu_ar.addMask(AR::SMASK_AR_SSN); len += pi.length();
			}
				break;
			default:
				tsdu.reset();
				goto EXIT;
			}
		}
	EXIT:
		if (spdu_ar.hasMask(SPDU::SMASK_AR_REF)) {
				spdu_ar.setReference(ref);
		}
	}
	AR_LINK::~AR_LINK() {

	}
}
}
}
