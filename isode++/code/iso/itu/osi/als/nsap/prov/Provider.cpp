/*
 * Provider.cpp
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/nsap/prov/NA_TCP_TS_TCP.h"
#include "als/nsap/prov/Provider.h"

namespace ALS {
namespace NSAP {
namespace PROV {
Provider::Provider(ALS::NSAP::USER::Initiator* initiator) : initiator(initiator)
{
		nb_logger = new Logger(0);
		natcptstcp = new NA_TCP_TS_TCP(this);
}
Provider::~Provider() {
	delete natcptstcp;
	delete nb_logger;
}
ReturnCode Provider::NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	nb_logger->NConnectRequest(called, called, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
	natcptstcp->NConnectRequest(called, called, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
	return OK;
}
ReturnCode Provider::NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	nb_logger->NConnectConfirmation(responding, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
	initiator->NConnectConfirmation(responding, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
	return DONE;
}
ReturnCode Provider::NDataRequest(NetworkBuffer* buffer, bool confirmation) {
	nb_logger->NDataRequest(buffer, confirmation);
	natcptstcp->NDataRequest(buffer, confirmation);
	return OK;
}
ReturnCode Provider::NDataRequest(int cc, byte* data, bool confirmation) {
	nb_logger->NDataRequest(cc, data, confirmation);
	natcptstcp->NDataRequest(cc, data, confirmation);
	return OK;
}
ReturnCode Provider::NDataIndication(const SharedNetworkBuffer& buffer) {
	nb_logger->NDataIndication(buffer);
	initiator->NDataIndication(buffer);
	return DONE;
}
ReturnCode Provider::NDataAcknoledgeRequest() {
	natcptstcp->NDataAcknoledgeRequest();
	natcptstcp->NDataAcknoledgeRequest();
	return OK;
}
ReturnCode Provider::NExpeditedDataRequest(int cc, const byte* data) {
	nb_logger->NExpeditedDataRequest(cc, data);
	natcptstcp->NExpeditedDataRequest(cc, data);
	return OK;
}
ReturnCode Provider::NResetRequest(int reason) {
	nb_logger->NResetRequest(reason);
	natcptstcp->NResetRequest(reason);
	return OK;
}
ReturnCode Provider::NResetResponse() {
	natcptstcp->NResetResponse();
	natcptstcp->NResetResponse();
	return OK;
}
ReturnCode Provider::NResetIndication(const NSAPAddr& originator, int reason) {
	nb_logger->NResetIndication(originator, reason);
	initiator->NResetIndication(originator, reason);
	return DONE;
}
ReturnCode Provider::NResetConfirmation() {
	nb_logger->NResetConfirmation();
	initiator->NResetConfirmation();
	return DONE;
}
ReturnCode Provider::NDisconnectRequest(int reason, const NSAPAddr& responding, int cc, const byte* data) {
	nb_logger->NDisconnectRequest(reason, responding, cc, data);
	natcptstcp->NDisconnectRequest(reason, responding, cc, data);
	return OK;
}
ReturnCode Provider::NDisconnectIndication() {
	nb_logger->NDisconnectIndication();
	initiator->NDisconnectIndication();
	return DONE;
}
}
}
}
