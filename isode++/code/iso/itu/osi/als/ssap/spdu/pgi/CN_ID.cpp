/*
 * CN_ID.cpp
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/pgi/CN_ID.h"
#include "als/ssap/spdu/CN_AC.h"
#include "als/ssap/spdu/pi/CALLING_SS.h"
#include "als/ssap/spdu/pi/CALLED_SS.h"
#include "als/ssap/spdu/pi/COMMON_REF.h"
#include "als/ssap/spdu/pi/ADD_INFO.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	CN_ID::CN_ID(PI_SS_TYPE call, const Reference& ref) : PGI(PGI_CN_ID) {
		int	len = 0;
		if (ref.udata() != nullptr && ref.ulength() > 0) {
			if (call == PI_SS_TYPE::CALLING) {
				CALLING_SS*	pi = new CALLING_SS(ref.ulength(), ref.udata());
				add(pi); len += pi->length();
			} else
			if (call == PI_SS_TYPE::CALLED) {
				CALLED_SS*	pi = new CALLED_SS(ref.ulength(), ref.udata());
				add(pi); len += pi->length();
			}
		}
		if (ref.cdata() != nullptr && ref.clength() > 0) {
			COMMON_REF*	pi = new COMMON_REF(ref.clength(), ref.cdata());
			add(pi); len += pi->length();
		}
		if (ref.adata() != nullptr && ref.alength() > 0) {
			ADD_INFO*		pi = new ADD_INFO(ref.alength(), ref.adata());
			add(pi); len += pi->length();
		}
	}
	CN_ID::CN_ID(CN_AC& spdu_cn, NetworkBuffer& tsdu) : PGI(PGI_CN_ID, tsdu) {
	while (tsdu.hasRemaining()) {
		tsdu.markit();
		int code = tsdu.get() & 0xFF;
		switch (code) {
		case PI::PI_CALLING_SS: {
			CALLING_SS	pi(tsdu);
			int length = 0;
			const byte* data = pi.getValue(length);
			spdu_cn.getReference().udata(length, data);
		}
			break;
		case PI::PI_COMMON_REF: {
			COMMON_REF 	pi(tsdu);
			int length = 0;
			const byte* data = pi.getValue(length);
			spdu_cn.getReference().cdata(length, data);
		}
			break;
		case PI::PI_ADD_INFO: {
			ADD_INFO 	pi(tsdu);
			int length = 0;
			const byte* data = pi.getValue(length);
			spdu_cn.getReference().adata(length, data);
		}
			break;
		default:
			tsdu.reset();
			goto EXIT;

		}
	}
EXIT:;
	}
	CN_ID::~CN_ID() {

	}
}
}
}
