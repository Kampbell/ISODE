/*
 * Provider.h
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_PROV_PROVIDER_H_
#define ALS_NSAP_PROV_PROVIDER_H_

#include "als/nsap/nsap.h"
#include "als/nsap/prov/Logger.h"
#include "als/nsap/user/Initiator.h"
#include "als/nsap/serv/Initiator.h"
#include "als/nsap/serv/Responder.h"
#include "als/nsap/QualityOfService.h"

using ALS::NSAP::USER::Initiator;
using ALS::NSAP::PROV::Logger;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using namespace ALS::NSAP::ADDR;


namespace ALS {
namespace NSAP {
namespace PROV {
	class NA_TCP_TS_TCP;

class NSAP_API Provider :
	public ALS::NSAP::SERV::Initiator,
	public ALS::NSAP::USER::Initiator{
private:
	ALS::NSAP::USER::Initiator*	initiator;
	NA_TCP_TS_TCP*			natcptstcp;
	Logger*					nb_logger;

public:
	Provider() : initiator(nullptr), natcptstcp(nullptr), nb_logger(nullptr) {}
	Provider(ALS::NSAP::USER::Initiator* initiator);
	~Provider();


	virtual ReturnCode NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);

	virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation = false);
	virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation = false);
	virtual ReturnCode NDataAcknoledgeRequest();
	virtual ReturnCode NExpeditedDataRequest(int cc = 0, const byte* buffer = nullptr);

	virtual ReturnCode NResetRequest(int reason);
	virtual ReturnCode NResetResponse();
	
	virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc = 0, const byte* buffer = nullptr);


	virtual ReturnCode NDataIndication(const SharedNetworkBuffer& buffer);
	virtual ReturnCode NDisconnectIndication();
	virtual ReturnCode NResetIndication(const NSAPAddr& originator, int reason);
	virtual ReturnCode NResetConfirmation();

};

}
}
}

#endif
