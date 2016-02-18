/*
 * CN_ITEMS.cpp
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/pgi/CN_ITEMS.h"
#include "als/ssap/spdu/pi/PROTOCOL_OPT.h"
#include "als/ssap/spdu/pi/TSDU_MAXSIZ.h"
#include "als/ssap/spdu/pi/VERSION.h"
#include "als/ssap/spdu/pi/ISN.h"
#include "als/ssap/spdu/pi/TOKEN_SET.h"
#include "als/ssap/spdu/CN_AC.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	CN_ITEMS::CN_ITEMS(CN_AC& spdu_cn) : PGI(PGI_CN_ITEMS) {
		int len = 0;
		if (spdu_cn.hasMask(SPDU::SMASK_CN_OPT)) {
			PROTOCOL_OPT*	pi = new PROTOCOL_OPT(spdu_cn.getOptions());
			add(pi); len += pi->length();
		}
		if (spdu_cn.hasMask(SPDU::SMASK_CN_TSDU)) {
			int tsdu_maxsize = ((spdu_cn.getTSDUInitiator() & 0xffff) << 16) | (spdu_cn.getTSDUResponder() & 0xffff);
			TSDU_MAXSIZ*	pi = new TSDU_MAXSIZ(tsdu_maxsize);
			add(pi); len += pi->length();
		}
		if (spdu_cn.hasMask(SPDU::SMASK_CN_VRSN)) {
			VERSION*	pi = new VERSION(spdu_cn.getVersion());
			add(pi); len += pi->length();
		}
		if (spdu_cn.hasMask(SPDU::SMASK_CN_ISN)) {
			ISN*	pi = new ISN(spdu_cn.getIsn());
			add(pi); len += pi->length();
		}
		if (spdu_cn.hasMask(SPDU::SMASK_CN_SET)) {
			TOKEN_SET*	pi = new TOKEN_SET((byte)spdu_cn.getSettings());
			add(pi); len += pi->length();
		}
	}
	CN_ITEMS::CN_ITEMS(CN_AC& spdu_cn, NetworkBuffer& tsdu) : PGI(PGI_CN_ITEMS, tsdu) {
		byte code;
		while (tsdu.hasRemaining()) {
		tsdu.markit();
		code = tsdu.get() & 0xFF;
		switch (code) {
		case PI::PI_PROTOCOL_OPT: {
			PROTOCOL_OPT pi(tsdu);
			spdu_cn.setOptions(pi.getValue());
			spdu_cn.addMask(SPDU::SMASK_CN_OPT);
		}
			break;
		case PI::PI_TSDU_MAXSIZ: {
			TSDU_MAXSIZ pi(tsdu);
			spdu_cn.setTSDUInitiator(pi.getTSDUInit());
			spdu_cn.setTSDUResponder(pi.getTSDUResp());
			spdu_cn.addMask(SPDU::SMASK_CN_TSDU);
		}
			break;
		case PI::PI_VERSION: {
			VERSION 	pi(tsdu);
			spdu_cn.setVersion(pi.getValue());
			spdu_cn.addMask(SPDU::SMASK_CN_VRSN);
		}
			break;
		case PI::PI_ISN: {
			ISN 		pi(tsdu);
			spdu_cn.setIsn(pi.getValue());
			spdu_cn.addMask(SPDU::SMASK_CN_ISN);
		}
			break;
		case PI::PI_TOKEN_SET: {
			TOKEN_SET 	pi(tsdu);
			spdu_cn.setSettings(pi.getValue());
			spdu_cn.addMask(SPDU::SMASK_CN_SET);
		}
			break;
		default:
			tsdu.reset();
			goto EXIT;
		}
	}
	EXIT:
		;
	}
	CN_ITEMS::~CN_ITEMS() {
	}
}
}
}
