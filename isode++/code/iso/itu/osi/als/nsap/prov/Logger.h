/*
 * Logger.h
 *
 *  Created on: 17 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_PROV_LOGGER_H_
#define ALS_NSAP_PROV_LOGGER_H_
#include <memory>
using std::shared_ptr;

#include "als/nsap/nsap.h"
#include "als/base/root/Logger.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/serv/Initiator.h"
#include "als/nsap/serv/Responder.h"
#include "als/nsap/user/Initiator.h"
#include "als/nsap/user/Responder.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			class NetworkBuffer;
		}
	}
	namespace NSAP {
		namespace ADDR {
			class NSAPAddr;
		}
		class QualityOfService;
		class QualityOfServiceParameters;
	}
}
using ALS::BASE::UTIL::NetworkBuffer;
using ALS::NSAP::ADDR::NSAPAddr;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;

namespace ALS {
namespace NSAP {
namespace PROV {

class NSAP_API Logger : 
	public BASE::ROOT::Logger,
	public SERV::Initiator, public SERV::Responder,
	public USER::Initiator, public USER::Responder {
		friend class Provider;
	private:
public:
	Logger(int level) : BASE::ROOT::Logger("NSAP") {}
	~Logger() {}

	virtual Logger&	logger() const  { return *(Logger*)this; }

	virtual ReturnCode NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectIndication(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);

	virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation = false);
	virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation = false);
	virtual ReturnCode NDataIndication(const SharedNetworkBuffer& buffer);

	virtual ReturnCode NDataAcknoledgeRequest();
	virtual ReturnCode NExpeditedDataRequest(int cc = 0, const byte* buffer = nullptr);

	virtual ReturnCode NResetRequest(int reason);
	virtual ReturnCode NResetResponse();
	virtual ReturnCode NResetIndication(const NSAPAddr& originator, int reason);
	virtual ReturnCode NResetConfirmation();

	virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc = 0, const byte* buffer = nullptr);
	virtual ReturnCode NDisconnectIndication();
	virtual ReturnCode NSetTSAPServices(const ALS::BASE::SRVC::TSAPServices* tsapServices) { return OK; };

	virtual ALS::NSAP::USER::Initiator* nsapUserInitiator() const   { return nullptr; }
	virtual ALS::NSAP::USER::Responder* nsapUserResponder() const   { return nullptr; }
	virtual ALS::NSAP::SERV::Initiator*&nsapServInitiator()			{ ALS::NSAP::SERV::Initiator* p=nullptr;  return p; }
	virtual ALS::NSAP::SERV::Responder*&nsapServResponder()			{ ALS::NSAP::SERV::Responder* p=nullptr;  return p; }


private:
	void dump(const void* buffer, std::size_t length, Message::Priority prio = Message::PRIO_TRACE);
};

}
}
}

#endif
