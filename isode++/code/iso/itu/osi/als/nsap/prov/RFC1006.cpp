/*
 * RFC1006.cpp
 *
 *  Created on: 27 juil. 2014
 *      Author: FrancisANDRE
 */

#include "Poco/ByteOrder.h"
#include "Poco/Net/StreamSocket.h"
#include "als/nsap/prov/RFC1006.h"
#include "als/base/util/NetworkBuffer.h"

using ALS::BASE::UTIL::NetworkBuffer;
using Poco::ByteOrder;

namespace ALS {
	namespace NSAP {
		namespace PROV {
			POCO_IMPLEMENT_EXCEPTION(ProtocolException, Poco::Net::NetException, "RFC 1006 protocol exception")

			RFC1006::RFC1006(StreamSocket& socket) :
				socket(socket), offset(0), buffer(nullptr) {
			}

			RFC1006::~RFC1006() {
			}

			int RFC1006::recv(NetworkBuffer*& buffer) {
				int received;
			LOOP:
				switch (offset) {
				case 0:
					buffer = nullptr;
					received = socket.receiveBytes(&version, sizeof(version));
					if (received == 0)
						return received;
					if (received == sizeof(version)) {
						offset += received;
						if (version == 3) {
							goto LOOP;
						}
						else
							throw  ProtocolException();
					}
					else
						throw  ProtocolException();
					break;
				case 1:
					received = socket.receiveBytes(&mbz, sizeof(mbz));
					if (received == sizeof(mbz)) {
						offset += received;
						if (mbz == 0) {
							goto LOOP;
						}
						else
							throw  ProtocolException();
					}
					else
						throw  ProtocolException();
					break;
				case 2:
					received = socket.receiveBytes(&length, sizeof(length));
					if (received == sizeof(length)) {
						offset += received;
						length = ByteOrder::fromNetwork(length);
					}
					else
						throw  ProtocolException();
					break;
				default:
					break;
				}

				if (buffer == nullptr) {
					if (length < TPKT_MINLEN)
						throw  ProtocolException();
					length -= 4;
					buffer = new NetworkBuffer(length);
				}
				received = socket.receiveBytes(buffer->bytes(), buffer->remaining());
				buffer->position(buffer->position() + received);
				if (buffer->hasRemaining())
					return 0;
				reset();
				buffer->flip();
				return 1;
			}

			int RFC1006::send(const NetworkBuffer* buffer) {
				if (buffer->remaining() > TPDU_MAXLEN)
					throw ProtocolException();
				int sended = 0;
				sended += socket.sendBytes(&TPKT_VERSION, sizeof(TPKT_VERSION));
				sended += socket.sendBytes(&TPKT_MBZ, sizeof(TPKT_MBZ));
				nat2 length = buffer->remaining();
				length += SIZEOF_HEADER;
				if (length < TPKT_MINLEN)
					throw  ProtocolException();
				length = ByteOrder::toNetwork(length);
				sended += socket.sendBytes(&length, sizeof(length));
				sended += socket.sendBytes(buffer->data(), buffer->remaining());
				return sended;
			}
			int	RFC1006::send(int cc, const byte* data) {
				if (cc > TPDU_MAXLEN)
					throw ProtocolException();

				int sended = 0;
				sended += socket.sendBytes(&TPKT_VERSION, sizeof(TPKT_VERSION));
				sended += socket.sendBytes(&TPKT_MBZ, sizeof(TPKT_MBZ));
				nat2 length = cc;
				length += SIZEOF_HEADER;
				if (length < TPKT_MINLEN)
					throw  ProtocolException();
				length = ByteOrder::toNetwork(length);
				sended += socket.sendBytes(&length, sizeof(length));
				sended += socket.sendBytes(data, cc);
				return sended;
			}

		}
	}
}
