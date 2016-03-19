/*
 * TSAPEchoServer.cpp
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#include <iostream>
#include "Poco/ClassLibrary.h"
#ifndef POCO_EXPORT_INTERFACE

#define POCO_EXPORT_INTERFACE(cls, itf) \
    pManifest->insert(new Poco::MetaObject<cls, _Base>(itf));

#endif
#include "Poco/Format.h"
using Poco::format;

#include "TSAPEchoServer.h"
#include "als/tsap/prov/Provider.h"

using namespace std;

POCO_BEGIN_NAMED_MANIFEST(ALS_TSAP_USER_Responder, ALS::TSAP::USER::Responder)
	POCO_EXPORT_INTERFACE(ALS::TSAP::TSAPEchoServer, "ALS::TSAP::USER::Responder")
POCO_END_MANIFEST

namespace ALS {
namespace TSAP {
TSAPEchoServer::TSAPEchoServer() {
}
TSAPEchoServer::~TSAPEchoServer() {
}
USER::Initiator* 
TSAPEchoServer::initiator() const {
	return nullptr;
}
PROV::Provider*&
TSAPEchoServer::provider() {
	return tsap_serv_provider;
}
ReturnCode TSAPEchoServer::TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc, const byte* data) {
	try {
		tsap_serv_provider->TConnectResponse(calledAddr, expedited, qualityOfService);
	} catch (const Poco::Exception& e) {
		tsap_serv_provider->logger().error(e.message());
	}
	return DONE;
}
ReturnCode TSAPEchoServer::TDataIndication(const SharedNetworkBuffer& data) {
	string message;

	if (data) {
		if (data->remaining() < 32) {
			message += string(data->data(), data->remaining());
		}
		else {
			message += '>';
			message += to_string(data.total());
			message += '<';
		}
	}
	else {
		message = "No data received";
	}
	tsap_serv_provider->logger().information(message);
	unique_ptr<byte> tosend(new byte[data.total()]);
	int remain = data.total();
	int offset = 0;
	int moved = 0;
	for (SharedNetworkBuffer::const_iterator buffer = data.begin(); buffer != data.end(); ++buffer) {
		moved = (*buffer)->getBytes(remain, tosend.get() + offset);
		remain -= moved;
		offset += moved;
	}
	tsap_serv_provider->TDataRequest(offset, tosend.get());
	return DONE;
}
ReturnCode TSAPEchoServer::TExpeditedDataIndication(const SharedNetworkBuffer& data) {
	const byte* bytes = nullptr;
	int cc = 0;
	if (data && data->hasRemaining()) {
		cc = data->remaining();
		bytes = data->bytes();
	}
	tsap_serv_provider->TExpeditedDataRequest(cc, bytes);
	return DONE;
}
ReturnCode TSAPEchoServer::TDisconnectIndication(int reason, const string& data) {
	return DONE;
}

}
}
