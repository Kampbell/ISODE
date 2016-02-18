/*
 * SocketChannel.h
 *
 *  Created on: 4 août 2015
 *      Author: FrancisANDRE
 */

#ifndef SOCKETCHANNEL_H_
#define SOCKETCHANNEL_H_
#include "Poco/Logger.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/SocketAddress.h"

using Poco::Logger;
using Poco::Net::IPAddress;
using Poco::Net::StreamSocket;
using Poco::Net::SocketStream;
using Poco::Net::SocketAddress;

#include "als/base/util/NetworkChannel.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BASE_API SocketChannel : public NetworkChannel {
			private:
				SocketAddress	sa;
				StreamSocket	socket;
				string			host;
				short			port;
				Logger*			logger;

			public:
				SocketChannel(Logger* logger, const string& host, short port);
				SocketChannel(Logger* logger, StreamSocket& socket);
				virtual ~SocketChannel();

				virtual void connect(int second = 0);
				virtual void disconnect(int second = 0);
				virtual int send(NetworkBuffer& cos);
				virtual int recv(NetworkBuffer& cis);

				virtual void setRecvTimeout(int second);
				virtual void setSendTimeout(int second);
			};
		}
	}
}

#endif
