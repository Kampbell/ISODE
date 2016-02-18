/*
 * AB.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Exception.h"
using ALS::SSAP::Exception;

#include "als/ssap/AbortCode.h"
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/pi/PI.h"
#include "als/ssap/spdu/pi/ENCLOSE.h"
#include "als/ssap/spdu/pi/REFLECT.h"
#include "als/ssap/spdu/pi/TDISC.h"
#include "als/ssap/spdu/pi/UDATA.h"
#include "als/ssap/spdu/AB.h"


namespace ALS {
namespace SSAP {
namespace SPDU {
AB::AB() : SPDU(CAT1, SPDU_AB) {
	addMask(SMASK_SPDU_AB);
}
AB::AB(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_AB, tsdu)  {
	addMask(SMASK_SPDU_AB);
}
AB::~AB() {
}
void AB::addDisconnect(byte disconnect) {
	addMask(SMASK_AB_DISC);
	ab_disconnect |=  disconnect;
}

void AB::setDisconnect(byte disconnect) {
	addMask(SMASK_AB_DISC);
	ab_disconnect =  disconnect;
}

void AB::setReflect(int cc, byte* reflect) {
	addMask(SMASK_AB_REFL);
	memcpy(ab_reflect, reflect, min(cc, sizeof(ab_reflect)));
}

byte AB::getDisconnect() {
	return ab_disconnect;
}

byte* AB::getReflect() {
	return ab_reflect;
}

NetworkBuffer* AB::toTSDU(int fake) {
NetworkBuffer* tsdu = nullptr;
#if 0
	PI pi;
	PGI pgi;
	int len = 0;
	pi = new PI_TDISC(ab_disconnect);
	len += pi->length();
	addSon(pi);
	if (spkt.hasMask(SMASK_AB_REFL)) {
		pi = new PI_REFLECT(ab_reflect);
		len += pi->length();
		addSon(pi);
	}
	if (spkt.hasMask(SMASK_ENCLOSE)) {
		pi = new PI_ENCLOSE(spdu_enclose);
		len += pi->length();
		addSon(pi);
	}
	byte[] bytes = spkt.popData();
	if (bytes != nullptr) {
		pi = new PI_UDATA(AB_SIZE, bytes);
		len += pi->length();
		addSon(pi);
	}
	if (spkt.hasMask(SMASK_ENCLOSE)) {
		pi = new PI_ENCLOSE(spdu_enclose);
		len += pi->length();
		addSon(pi);
	}

	sli(len);

	if (logger != nullptr) {
		logger.trace(toString());
	}
	TSDU tsdu = super.toTSDU(spkt, fake);
#endif

	return tsdu;
}


ReturnCode AB::decode(NetworkBuffer& buffer) {
	SPDU::control(buffer);
	if (sli() == 0)
		return OK;
	ReturnCode rc = OK;
	while (buffer.hasRemaining()) {
		buffer.markit();
		byte code = buffer.get();
		switch (code) {
		case PI::PI_TDISC: {
			TDISC* pi = new TDISC(buffer);
			ab_disconnect = pi->getValue();
			addMask(SMASK_AB_DISC);
		}
			break;
		case PI::PI_REFLECT: {
			REFLECT* pi = new REFLECT(buffer);
			int length = 0;
			memcpy(ab_reflect, pi->getValue(length), length);
			addMask(SMASK_AB_REFL);
		}
			break;
		case PI::PI_ENCLOSE: {
			ENCLOSE* pi = new ENCLOSE(buffer);
			setEnclose(pi->getValue());
			addMask(SMASK_ENCLOSE);
		}
			break;
		case PI::PI_UDATA: {
			UDATA* pi = new UDATA(buffer);
			int length = 0;
			const byte* data;
			data = pi->getValue(length);
			setData(length, data);
			addMask(SMASK_ENCLOSE);
		}
			break;
		default:
			buffer.reset();
			goto EXIT;
		}
	}
EXIT:
	return rc;
}

int AB::encode() {
	/*
	If_Set (SMASK_SPDU_AB) {
	start_spdu (&c, AB_BASE_SIZE);
	If_Reset (SMASK_AB_DISC) {
	s_errno = AbortCode::SC_PROTOCOL;
	break;
	}
	Put_Item (PI_TDISC, (char *) &s_ab_disconnect);
	If_Set (SMASK_AB_REFL)
	put2spdu (PI_REFLECT, AB_REFL_SIZE, (char *) s_reflect, &c);
	If_Set (SMASK_ENCLOSE)
	Put_Item (PI_ENCLOSE, (char *) &s_enclose);
	Put_UData (AB_SIZE);
	break;
	}
	*/
	PI* pi;
	int len = 0;
	if (!hasMask(SMASK_AB_DISC)) {
		throw Exception(AbortCode::SC_PROTOCOL);
	}
	pi = new TDISC(ab_disconnect);
	len += pi->length();
	append(pi);
	if (hasMask(SMASK_AB_REFL)) {
		pi = new REFLECT(AB_REFL_SIZE, ab_reflect);
		len += pi->length();
		append(pi);
	}
	if (hasMask(SMASK_ENCLOSE)) {
		pi = new ENCLOSE(spdu_enclose);
		len += pi->length();
		append(pi);
	}
	if (spdu_udata != nullptr) {
		pi = new UDATA(AB_SIZE, spdu_udata);
		len += pi->length();
		append(pi);
	}

	return len;
}
}
}
}
