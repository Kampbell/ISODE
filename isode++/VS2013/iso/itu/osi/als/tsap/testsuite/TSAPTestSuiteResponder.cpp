/*
 * TSAPTestSuiteResponder.cpp
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

#include "TSAPTestSuiteResponder.h"
#include "als/tsap/prov/Provider.h"

using namespace std;

POCO_BEGIN_NAMED_MANIFEST(ALS_TSAP_USER_Responder, ALS::TSAP::USER::Responder)
	POCO_EXPORT_INTERFACE(ALS::TSAP::TSAPTestSuiteResponder, "ALS::TSAP::USER::Responder")
POCO_END_MANIFEST

namespace ALS {
namespace TSAP {
TSAPTestSuiteResponder::TSAPTestSuiteResponder() {
}
TSAPTestSuiteResponder::~TSAPTestSuiteResponder() {
}
USER::Initiator* 
TSAPTestSuiteResponder::initiator() const {
	return nullptr;
}
PROV::Provider*&
TSAPTestSuiteResponder::provider() {
	return tsap_serv_provider;
}
ReturnCode TSAPTestSuiteResponder::TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc, const byte* data) {
	try {
		tsap_serv_provider->TConnectResponse(calledAddr, false, qualityOfService);
	} catch (const Poco::Exception& e) {
		tsap_serv_provider->logger().error(e.message());
	}
	return DONE;
}
ReturnCode TSAPTestSuiteResponder::TDataIndication(const SharedNetworkBuffer& data) {
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
ReturnCode TSAPTestSuiteResponder::TExpeditedDataIndication(const SharedNetworkBuffer& data) {
	tsap_serv_provider->TExpeditedDataRequest();
	return DONE;
}
ReturnCode TSAPTestSuiteResponder::TDisconnectIndication(int reason, const string& data) {
	return DONE;
}

}
}
