/*
 * Logger.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_PROV_LOGGER_H_
#define ALS_TSAP_PROV_LOGGER_H_

#include "Poco/Logger.h"
#include "Poco/Path.h"
#include "Poco/Timestamp.h"
#include "Poco/Timespan.h"
#include "Poco/Util/ServerApplication.h"

#include "als/tsap/tsap.h"

#include "als/base/root/Logger.h"
#include "als/nsap/addr/TSAPAddr.h"
#include "als/tsap/serv/Initiator.h"
#include "als/tsap/serv/Responder.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"
#include "als/nsap/QualityOfService.h"

using Poco::Util::Application;
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::QualityOfService;

namespace ALS {
namespace TSAP {
namespace PROV {

class TSAP_API Logger : 
	public ALS::BASE::ROOT::Logger,
	public SERV::Initiator, public SERV::Responder, 
	public USER::Initiator, public USER::Responder {
	friend class Provider;
private:
public:
	Logger(int level) : ALS::BASE::ROOT::Logger("TSAP") {
	}
	~Logger() {
	}
	virtual Logger&		logger() const  { return *(Logger*)this; }

private:
	virtual ReturnCode TConnectRequest(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TConnectResponse(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TConnectConfirmation(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int tsdusize, NetworkBuffer* data = nullptr);
	virtual ReturnCode TDataRequest(NetworkBuffer* tsdu);
	virtual ReturnCode TDataRequest(int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TDataIndication(const SharedNetworkBuffer& data);
	virtual ReturnCode TExpeditedDataRequest(int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TExpeditedDataIndication(int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TDisconnectRequest(int reason, const TSAPAddr& responding, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TDisconnectIndication(int reason, const string& data);
	virtual ReturnCode TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices);

};

}
}
}

#endif
