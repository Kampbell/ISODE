/*
 * Logger.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_PROV_LOGGER_H_
#define ALS_PSAP_PROV_LOGGER_H_

#include "als/base/root/Logger.h"
#include "als/base/util/NetworkBuffer.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/ssap/Reference.h"
#include "als/ssap/SyncOption.h"
#include "als/ssap/ResyncOption.h"
#include "als/nsap/QualityOfService.h"
#include "als/psap/serv/Initiator.h"
#include "als/psap/serv/Responder.h"
#include "als/psap/user/Initiator.h"
#include "als/psap/user/Responder.h"
using ALS::PSAP::USER::Responder;

using ALS::NSAP::ADDR::SSAPAddr;
using ALS::NSAP::QualityOfService;
using ALS::BASE::UTIL::NetworkBuffer;
using ALS::SSAP::SyncOption;
using ALS::SSAP::ResyncOption;

namespace ALS {
namespace PSAP {
namespace PROV {

class Logger :
	public ALS::BASE::ROOT::Logger,
	public SERV::Initiator, public SERV::Responder,
	public USER::Initiator, public USER::Responder {
	friend class Provider;
public:
	Logger(int level) : ALS::BASE::ROOT::Logger("PSAP") {
	}
	~Logger() {
	}
	ReturnCode PConnectRequest(const PresentationAddress& callingAddr,	const PresentationAddress& calledAddr,	const Presentation_context_definition_list& presentationContexts, const Default_context_name& defaultContext, const Presentation_requirements& prequirements, const Mode_selector& mode, const User_session_requirements& srequirements, const SSN& isn, int settings, const Reference& reference, const QualityOfService& qualityOfService, const User_data* userData = nullptr);
	ReturnCode PConnectIndication(const PresentationAddress& callingAddr, const PresentationAddress& calledAddr, const Presentation_context_definition_list& presentationContexts, const Presentation_context_definition_result_list& presentationResults, const Default_context_name& defaultContext, const Presentation_requirements& prequirements, const Mode_selector& mode, const User_session_requirements& srequirements,	const SSN& isn,	int settings, const Reference& reference, const QualityOfService& qualityOfService, const User_data* userData = nullptr);
	ReturnCode PConnectResponse(int status, const PresentationAddress& respondingAddr,const Presentation_context_definition_result_list& results, int defaultContextResult, const Presentation_requirements& prequirements, const User_session_requirements& usrequirements, const SSN& isn, byte settings, const Reference& reference, const User_data* userData = nullptr);
	ReturnCode PConnectConfirmation(const PresentationAddress& respondingAddr,	const Presentation_context_definition_list& presentationContexts, const Presentation_context_definition_result_list& presentationResults, int defaultContextResult, const Presentation_requirements& prequirements, const User_session_requirements& srequirements, int settings, const SSN& isn, const Reference& reference, int ssdusize, const QualityOfService& qualityOfService, int result, const User_data* userData = nullptr);

	ReturnCode PActivityDiscardRequest(int reason);
	ReturnCode PActivityDiscardIndication(int reason, const User_data* userData = nullptr);
	ReturnCode PActivityDiscardConfirmation(const User_data* userData = nullptr);
	ReturnCode PActivityDiscardResponse();
	ReturnCode PActivityInterruptRequest(int reason);
	ReturnCode PActivityInterruptIndication(int reason, const User_data* userData = nullptr);
	ReturnCode PActivityInterruptResponse();
	ReturnCode PActivityInterruptConfirmation(const User_data* userData = nullptr);
	ReturnCode PActivityStartRequest(const ActivityId& activityId, const User_data* userData = nullptr);
	ReturnCode PActivityStartIndication(const ActivityId& aid, const User_data* userData = nullptr);
	ReturnCode PActivityResumeIndication(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldReference, const User_data* userData = nullptr);
	ReturnCode PActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& ssn, const Reference& oldReference,	const User_data* userData = nullptr);
	ReturnCode PActivityEndRequest(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PActivityEndIndication(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PActivityEndResponse(const User_data* userData = nullptr);
	ReturnCode PActivityEndConfirmation(const SSN& secondSSN, const User_data* userData = nullptr);


	ReturnCode PAlterContextRequest(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const User_data* userData = nullptr);
	ReturnCode PAlterContextIndication(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const Presentation_context_addition_result_list& presentationAdditionResults,	const User_data* userData = nullptr);
	ReturnCode PAlterContextResponse(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData = nullptr);
	ReturnCode PAlterContextConfirmation(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData = nullptr);

	ReturnCode PDataRequest(const User_data* data = nullptr);
	ReturnCode PExpeditedDataRequest(const User_data* userData = nullptr);
	ReturnCode PTypedDataRequest(const User_data* userData = nullptr);
	ReturnCode PDataIndication(const User_data& userData);
	ReturnCode PExpeditedDataIndication(const User_data& userData);
	ReturnCode PTypedDataIndication(const User_data& userData);
	ReturnCode PCapabilityDataRequest(const User_data* userData = nullptr);
	ReturnCode PCapabilityDataIndication(const User_data& userData);
	ReturnCode PCapabilityDataResponse(const User_data* userData = nullptr);
	ReturnCode PCapabilityDataConfirmation(const User_data& userData);

	ReturnCode PResynchronizeRequest(const ResyncOption& type, const SSN& ssn, byte tokens, const User_data* userData = nullptr);
	ReturnCode PSyncMajorRequest(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMinorRequest(const SyncOption& type, const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMajorIndication(SSN ssn, const User_data* userData = nullptr);

	ReturnCode PSyncMinorIndication(SyncOption type, const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PResynchronizeConfirmation(const SSN& ssn, byte tokens, const User_data* userData = nullptr);
	ReturnCode PResynchronizeIndication(SyncOption type, const SSN& ssn, byte tokens, const Presentation_context_identifier_list& presentationIdentifications, const User_data* userData = nullptr);
	ReturnCode PSyncMajorConfirmation(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMinorConfirmation(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PResynchronizeResponse(const SSN& ssn, int tokens, const Presentation_context_identifier_list& presentationIdentififiers, const User_data* userData = nullptr);
	ReturnCode PSyncMajorResponse(const User_data* userData = nullptr);
	ReturnCode PSyncMinorResponse(const SSN& ssn, const User_data* userData = nullptr);

	ReturnCode PControlGiveRequest();
	ReturnCode PTokenGiveRequest(int tokens, const User_data* userData = nullptr);
	ReturnCode PTokenPleaseRequest(int tokens, const User_data* userData = nullptr);
	ReturnCode PTokenGiveIndication(byte tokens, const User_data* userData = nullptr);
	ReturnCode PControlGiveIndication(byte tokens, const User_data* userData = nullptr);
	ReturnCode PTokenPleaseIndication(byte tokens, const User_data* userData = nullptr);

	ReturnCode PUExceptionReportRequest(int reason, const User_data* userData = nullptr);
	ReturnCode PPExceptionReportIndication(int reason);
	ReturnCode PUExceptionReportIndication(int reason, const User_data* userData = nullptr);


	ReturnCode PUAbortRequest(const User_data* userData = nullptr);
	ReturnCode PUAbortIndication(int reason, int extension, const User_data* userData = nullptr);
	ReturnCode PPAbortIndication(int reason, int extension, const User_data* userData = nullptr);

	ReturnCode PReleaseRequest(int secs, const User_data* userData = nullptr);
	ReturnCode PReleaseResponse(int status, const User_data* userData = nullptr);
	ReturnCode PReleaseIndication(const User_data* userData = nullptr);
	ReturnCode PReleaseConfirmation(bool affirmative, const User_data* userData = nullptr);
	};
}
}
}

#endif
