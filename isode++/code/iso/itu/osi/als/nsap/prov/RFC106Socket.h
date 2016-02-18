/*
 * RFC106Socket.h
 *
 *  Created on: 16 août 2014
 *      Author: FrancisANDRE
 */

#ifndef RFC106SOCKET_H_
#define RFC106SOCKET_H_
#include "Poco/Net/StreamSocket.h"
#include "als/base/util/NetworkBuffer.h"

namespace ALS {
namespace TSAP {

class RFC106Socket : public Poco::Net::StreamSocket {
public:
	RFC106Socket() {}
	explicit RFC106Socket(const Poco::Net::SocketAddress& address) : StreamSocket(address) {}
	explicit RFC106Socket(Poco::Net::IPAddress::Family family) : StreamSocket(family) {}
	virtual ~RFC106Socket() {}
	int sendBytes(ALS::BASE::UTIL::NetworkBuffer& buffer);
};

}
}

#endif
