/*
 * C.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

//#include "als/tsap/Disconnect.h"
//using ALS::TSAP::Disconnect;
#include "als/base/util/NetworkBuffer.h"
#include "als/tsap/tpdu/TPDUException.h"
#include "als/tsap/tpdu/C.h"
#include "als/nsap/prov/RFC1006.h"
using ALS::NSAP::PROV::RFC1006;

namespace ALS {
namespace TSAP {
namespace TPDU {
void	C::setData(NetworkBuffer* buffer) {
	if (buffer->remaining() > TS_SIZE)
		buffer->shrink(TS_SIZE);
	TPCI::setData(buffer);
}
void	C::setData(const string&  message) {
	int size = message.length();;
	if (size > TS_SIZE)
		size = TS_SIZE;
	TPCI::setData(size, (const byte*)message.data());
}
void	C::setData(int cc, const byte* data) {
	if (cc > TS_SIZE)
		cc = TS_SIZE;
	TPCI::setData(cc, data);
}

C::TransportClass
C::transportClass() const {
	switch(tp_klass) {
		case CR_CLASS_TP0: return TP0; break;
		case CR_CLASS_TP1: return TP1; break;
		case CR_CLASS_TP2: return TP2; break;
		case CR_CLASS_TP3: return TP3; break;
	}
}
C::TransportAlternate
C::transportAlternate() const {
	return (TransportAlternate)tp_alternate;
}
bool	C::hasTransportOption(const TransportOption& option) const {
	bool result = false;
	switch(option) {
		case UseTransportExpedited		: result = (tp_options & OPT_TEXPEDITE) != 0;break;
		case Use16bitChecksum			: result = (tp_options & OPT_CHECKSUM) != 0;break;
		case UseReceiptConfirmation		: result = (tp_options & OPT_CONFIRM) != 0;break;
		case UseNetworkExpedited		: result = (tp_options & OPT_NEXPEDITE) != 0;break;
		case UseSelectiveAcknowledgement: result = (tp_options & OPT_SELECTIVE_ACK) != 0;break;
		case UseRequestAcknoledgement	: result = (tp_options & OPT_REQUEST_ACK) != 0; break;
	}
	return result;
}
void C::addOption(const TransportOption& option) {
	switch(option) {
		case UseTransportExpedited		: tp_options |= OPT_TEXPEDITE;break;
		case Use16bitChecksum			: tp_options |= OPT_CHECKSUM;break;
		case UseReceiptConfirmation		: tp_options |= OPT_CONFIRM;break;
		case UseNetworkExpedited		: tp_options |= OPT_NEXPEDITE;break;
		case UseSelectiveAcknowledgement: tp_options |= OPT_SELECTIVE_ACK;break;
		case UseRequestAcknoledgement	: tp_options |= OPT_REQUEST_ACK; break;
	}
}
void C::remOption(const TransportOption& option) {
	switch(option) {
		case UseTransportExpedited		: tp_options &= ~OPT_TEXPEDITE;break;
		case Use16bitChecksum			: tp_options &= ~OPT_CHECKSUM;break;
		case UseReceiptConfirmation		: tp_options &= ~OPT_CONFIRM;break;
		case UseNetworkExpedited		: tp_options &= ~OPT_NEXPEDITE;break;
		case UseSelectiveAcknowledgement: tp_options &= ~OPT_SELECTIVE_ACK;break;
		case UseRequestAcknoledgement	: tp_options &= ~OPT_REQUEST_ACK; break;
	}
}

void C::calling(byte length, const byte* bytes) {
	if (length > sizeof(tp_calling))
		throw  InvalidArgumentException();
	if (length > 0) {
		memcpy(tp_calling, bytes, tp_callinglen = length);
		tp_vlen += 2 + length;
	}
}
void C::called(byte length, const byte* bytes) {
	if (length > sizeof(tp_called))
		throw  InvalidArgumentException("length should be <= 64");
	if (length > 0) {
		memcpy(tp_called, bytes, tp_calledlen = length);
		tp_vlen += 2 + length;
	}
}

nat2	C::tpdusize() const	{ 
	if (tp_prefered_tpdusize > 0)
		return tp_prefered_tpdusize * 128;
	return tp_tpdusize == 0 ? 0 : 1 << tp_tpdusize; 
}

void	C::tpdusize(nat4 size) {
#if 0
	int i, j, k;
	i = k = size;
	for (j = 0; i > 0; j++)
		i >>= 1;
	if (k == (1 << (j - 1)))
		j--;
#else
	int tpdusize;
	switch (size) {
		case 8192: tpdusize = SIZE_8K; break;
		case 4096: tpdusize = SIZE_4K; break;
		case 2048: tpdusize = SIZE_2K; break;
		case 1024: tpdusize = SIZE_1K; break;
		case 512:  tpdusize = SIZE_512; break;
		case 256:  tpdusize = SIZE_256; break;
		case 128:  tpdusize = SIZE_128; break;
		default:   tp_prefered_tpdusize = size;
	}
#endif
	if (tp_prefered_tpdusize > 0) {
		tp_tpdusize = 0;
	} else {
		tp_tpdusize = tpdusize;
		tp_prefered_tpdusize = 0;
	}
}
void C::klass(const TransportClass& tc) {
	switch (tc) {
		case TP0:	tp_klass = CR_CLASS_TP0; break;
		case TP1:	tp_klass = CR_CLASS_TP1; break;
		case TP2:	tp_klass = CR_CLASS_TP2; break;
		case TP3:	tp_klass = CR_CLASS_TP3; break;
		case TP4:	tp_klass = CR_CLASS_TP4; break;
		default:
			throw  InvalidArgumentException();
	}
}
int C::decode(NetworkBuffer* nsdu) {
    if (li() < minimumLength()) {
		throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
	}
	int remain = li() - 1 /*code*/;

	tp_dstref = nsdu->getShort();
	remain -= sizeof(short);
	tp_srcref = nsdu->getShort();
	remain -= sizeof(short);
	tp_klass = nsdu->getByte();
	remain -= sizeof(byte);

	if (remain > nsdu->remaining()) {
		throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
	}
	while (nsdu->hasRemaining()) {
		int ilen;

		if (nsdu->remaining() < 2) {
			throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
		}

		byte subcode = nsdu->getByte();
		byte sublen = nsdu->getByte();

		if (nsdu->remaining() < sublen) {
			throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
		}

		byte b = 0;
		short size = 0;
		switch (subcode) {
		case VDAT_TSAP_CALLED:
			if ((ilen = sublen) > ID_SIZE) {
				ilen = ID_SIZE;
			}
			nsdu->getBytes(tp_calledlen = ilen, tp_called);
			break;

		case VDAT_TSAP_CALLING:
			if ((ilen = sublen) > ID_SIZE) {
				ilen = ID_SIZE;
			}
			nsdu->getBytes(tp_callinglen = ilen, tp_calling);
			break;

		case VDAT_TPDU_SIZE:
			if (sublen != 1) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			tp_tpdusize = nsdu->getByte();
			if (!(SIZE_128 <= tp_tpdusize &&  tp_tpdusize <= SIZE_8K))
				throw  TPDUException(0x80 + 5);// Disconnect::DR_PROTOCOL);
			break;

		case VDAT_PREFERED_TPDU_SIZE: {
			if (sublen > 4) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nat4 shift = 0;
			switch(sublen) {
				case 1: 
					shift = nsdu->getByte();
					break;
				case 2: 
					shift = nsdu->getShort();
					break;
				case 3: 
					shift = nsdu->getByte();
					shift <<= sizeof(nat2) * 8;
					shift += nsdu->getShort();
					break;
				case 4: 
					shift = nsdu->getInt();
					break;
			}
			if (shift < 1) {
				throw  TPDUException(0x80 + 5);// Disconnect::DR_PROTOCOL);
			}
			tp_prefered_tpdusize = 128 * shift;
			//
			// for now one have only support for RFC1006 i.e TP0 over TCP/IP
			// should be fixed using a better parametrization
			if (tp_prefered_tpdusize > RFC1006::TPDU_MAXLEN)
				tp_prefered_tpdusize = RFC1006::TPDU_MAXLEN;
			}
			break;

		case VDAT_OPTIONS:
			if (sublen != 1) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			tp_options = nsdu->getByte() & 0x3F;
			break;

		case VDAT_ALTERNATE:
			for (int i = sublen; i > 0; i--) {
				byte ap = nsdu->getByte();
				tp_alternate |= 1 << ((ap >> 4) & 0x0f);
			}
			break;

		case VDAT_VRSN:
			if (sublen != 1) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_SECURITY:
			nsdu->skip(sublen);
			break;

		case VDAT_CHECKSUM:
			nsdu->skip(sublen);
			break;

		case VDAT_ACKTIME:
			if (sublen != 2) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_THROUGHPUT:
			if (sublen != 12 && sublen != 24) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_ERRORATE:
			if (sublen != 3) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_PRIORITY:
			if (sublen != 2) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_DELAY:
			if (sublen != 8) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_TTR:
			if (sublen != 2) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		case VDAT_INACTIVITY_TIMER:
			if (sublen != 4) {
				throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
			}
			nsdu->skip(sublen);
			break;

		default: /* IS 8073 says to ignore it on CRs */
			if (code() == TPDU_CR) {
				nsdu->skip(sublen);
				break;
			}
			throw  TPDUException(0x80 + 5);// Disconnect::DR_PROTOCOL);
		}
	}

	return OK;
}
int C::encode(unique_ptr<NetworkBuffer>& nsdu) {
	TPCI::encode(nsdu);
	nsdu->putShort(tp_dstref);
	nsdu->putShort(tp_srcref);
	nsdu->putByte(tp_klass);

	int cp;
	int check = 0;

	if (tp_options != 0) {
		nsdu->putByte(VDAT_OPTIONS);
		nsdu->putByte(1);
		nsdu->putByte(tp_options);
		check += 3;
	}

	if (tp_klass != CR_CLASS_TP0 && tp_alternate != 0) {
		// XXX: this doesn't preserve the order of alternates
		nsdu->putByte(VDAT_ALTERNATE);

		cp = nsdu->position();
		nsdu->putByte((byte)0);

		if (tp_alternate & ALT_TP0) {
			nsdu->putByte((byte)CR_CLASS_TP0);
		}

		if (tp_alternate & ALT_TP1) {
			nsdu->putByte((byte)CR_CLASS_TP1);
		}

		if (tp_alternate & ALT_TP2) {
			nsdu->putByte((byte)CR_CLASS_TP2);
		}

		if (tp_alternate & ALT_TP3) {
			nsdu->putByte((byte)CR_CLASS_TP3);
		}

		if (tp_alternate & ALT_TP4) {
			nsdu->putByte((byte)CR_CLASS_TP4);
		}

		int pos = nsdu->position();
		byte number = (pos - cp) - 1;
		nsdu->putByte(cp, number);

		check += (2 + number);
	}

	if (tp_callinglen > 0) {
		nsdu->putByte(VDAT_TSAP_CALLING);
		nsdu->putByte(tp_callinglen);
		nsdu->putBytes(tp_callinglen, tp_calling);
		check += 2 + tp_callinglen;
	}

	if (tp_calledlen > 0) {
		nsdu->putByte(VDAT_TSAP_CALLED);
		nsdu->putByte(tp_calledlen);
		nsdu->putBytes(tp_calledlen, tp_called);
		check += 2 + tp_calledlen;
	}
	if (tp_prefered_tpdusize > 0) {
		nsdu->putByte(VDAT_PREFERED_TPDU_SIZE);
		nsdu->putByte(4);
		nsdu->putInt(tp_prefered_tpdusize / 128);
		check += 6;
	} else {
		nsdu->putByte(VDAT_TPDU_SIZE);
		nsdu->putByte(1);
		nsdu->putByte(tp_tpdusize);
		check += 3;
	}
	if (check != tp_vlen) {
		throw  InvalidArgumentException();
	}
	tp_li = minimumLength() + tp_vlen;
	nsdu->putByte(0, tp_li);

	nsdu->flip();
	return OK;
}
}
}
}
