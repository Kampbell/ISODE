/*
 * TPDU.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/TPCI.h"
#include "als/tsap/tpdu/CR.h"
#include "als/tsap/tpdu/CC.h"
#include "als/tsap/tpdu/DR.h"
#include "als/tsap/tpdu/DC.h"
#include "als/tsap/tpdu/DT.h"
#include "als/tsap/tpdu/ED.h"
#include "als/tsap/tpdu/AK.h"
#include "als/tsap/tpdu/EA.h"
#include "als/tsap/tpdu/RJ.h"
#include "als/tsap/tpdu/ER.h"

namespace ALS {
namespace TSAP {
namespace TPDU {
TPCI::TPCI(byte code) : 
	tp_code(code), 
	tp_len(0), 
	tp_data(nullptr),
	tp_buffer(nullptr) {
}
TPCI::TPCI(byte li, byte code) :
	tp_li(li),
	tp_code(code),
	tp_len(0),
	tp_data(nullptr),
	tp_buffer(nullptr) {
}
void TPCI::setData(NetworkBuffer* buffer) {
	poco_assert(tp_data == nullptr);
	tp_buffer = buffer; tp_len = buffer->remaining();  
}
void TPCI::setData(const string&  message) {
	poco_assert(tp_buffer == nullptr);
	tp_len = message.length(); tp_data = (const byte*)message.data(); 
}
void TPCI::setData(int cc, const byte* data) {
	poco_assert(tp_buffer == nullptr);
	tp_len = cc; tp_data = data; 
}
TPCI*
TPCI::decodeTPDU(NetworkBuffer* nsdu) {
	int rc = 0;
	TPCI* tpdu = nullptr;

	if (nsdu == nullptr)
		return tpdu;

	if (nsdu->remaining() < TPDU_MIN_LENGTH)
		return tpdu;

	byte li = nsdu->getByte();
	byte code = nsdu->getByte();

	switch(code) {
	case TPDU_CR:
		tpdu = new CR(li);
		break;

	case TPDU_CC:
		tpdu = new CC(li);
		break;

	case TPDU_DR:
		tpdu = new DR(li);
		break;

	case TPDU_DC:
		tpdu = new DC(li);
		break;

	case TPDU_DT:
		tpdu = new DT(li);
		break;

	case TPDU_ED:
		tpdu = new ED(li);
		break;

	case TPDU_AK:
		tpdu = new AK(li);
		break;

	case TPDU_EA:
		tpdu = new EA(li);
		break;

	case TPDU_RJ:
		tpdu = new RJ(li);
		break;

	case TPDU_ER:
		tpdu = new ER(li);
		break;

	default:
		break;
	}
	if (tpdu != nullptr) {
		rc = tpdu->decode(nsdu);
		if (nsdu->hasRemaining()) {
			tpdu->tp_buffer = nsdu;
			tpdu->tp_len = nsdu->remaining();
		}
	}

	return tpdu;
}
int	TPCI::encode(unique_ptr<NetworkBuffer>& nsdu) {
	if (nsdu.get() != nullptr)
		throw  InvalidArgumentException();
	int total = totalLength();
	int userlen = 0;
	if (tp_buffer != nullptr) {
		total += tp_buffer->remaining();
	} else
	if (tp_len > 0 && tp_data != nullptr) {
		total += tp_len;
	}
	unique_ptr<NetworkBuffer> newBuffer(new NetworkBuffer(total));
	nsdu = std::move(newBuffer);
	nsdu->putByte(tp_li = headerLength());
	nsdu->putByte(tp_code);
	return OK;
}
void TPCI::addData(unique_ptr<NetworkBuffer>& nsdu) {
	poco_assert(!(tp_buffer != nullptr && tp_data != nullptr));
	if (tp_buffer != nullptr) {
		nsdu->putBytes(tp_buffer->remaining(), tp_buffer->here());
		tp_buffer = nullptr;tp_len = 0;
	} else
	if (tp_len > 0 && tp_data != nullptr) {
		nsdu->putBytes(tp_len, tp_data);
		tp_len = 0; tp_data = nullptr;
	}
	poco_assert(nsdu->remaining() == 0);
}


}
}
}
