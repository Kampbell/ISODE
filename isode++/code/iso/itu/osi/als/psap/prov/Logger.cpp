/*
 * Logger.cpp
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#include <string>
using std::string;
#include "als/psap/prov/Logger.h"

#include "als/psap/Literal.h"
using ALS::PSAP::Literal;
#include "als/ssap/SSN.h"

using ALS::SSAP::SSN;

static const string PPAbortRequest(Literal::P_P_ABORT_REQUEST);
static const string PUAbortRequest(Literal::P_U_ABORT_REQUEST);
static const string PUAbortIndication(Literal::P_U_ABORT_INDICATION);
static const string PPAbortIndication(Literal::P_P_ABORT_INDICATION);


static const string PActivityDiscardRequest(Literal::P_ACTIVITY_DISCARD_REQUEST);
static const string PActivityEndRequest(Literal::P_ACTIVITY_END_REQUEST);
static const string PActivityInterruptRequest(Literal::P_ACTIVITY_INTERRUPT_REQUEST);
static const string PActivityResumeRequest(Literal::P_ACTIVITY_RESUME_REQUEST);
static const string PActivityStartRequest(Literal::P_ACTIVITY_START_REQUEST);
static const string PActivityDiscardResponse(Literal::P_ACTIVITY_DISCARD_RESPONSE);
static const string PActivityEndResponse(Literal::P_ACTIVITY_END_RESPONSE);
static const string PActivityInterruptResponse(Literal::P_ACTIVITY_INTERRUPT_RESPONSE);
static const string PActivityStartIndication(Literal::P_ACTIVITY_START_INDICATION);
static const string PActivityResumeIndication(Literal::P_ACTIVITY_RESUME_INDICATION);
static const string PActivityInterruptConfirmation(Literal::P_ACTIVITY_INTERRUPT_CONFIRMATION);
static const string PActivityInterruptIndication(Literal::P_ACTIVITY_INTERRUPT_INDICATION);
static const string PActivityDiscardIndication(Literal::P_ACTIVITY_DISCARD_INDICATION);
static const string PActivityEndIndication(Literal::P_ACTIVITY_END_INDICATION);
static const string PActivityDiscardConfirmation(Literal::P_ACTIVITY_DISCARD_CONFIRMATION);
static const string PActivityEndConfirmation(Literal::P_ACTIVITY_END_CONFIRMATION);

static const string PDataRequest(Literal::P_DATA_REQUEST);
static const string PCapabilityDataRequest(Literal::P_CAPABILITY_DATA_REQUEST);
static const string PCapabilityDataResponse(Literal::P_CAPABILITY_DATA_RESPONSE);
static const string PCapabilityDataIndication(Literal::P_CAPABILITY_DATA_INDICATION);
static const string PCapabilityDataConfirmation(Literal::P_CAPABILITY_DATA_CONFIRMATION);
static const string PExpeditedDataRequest(Literal::P_EXPEDITED_DATA_REQUEST);
static const string PTypedDataRequest(Literal::P_TYPED_DATA_REQUEST);
static const string PDataIndication(Literal::P_DATA_INDICATION);
static const string PExpeditedDataIndication(Literal::P_EXPEDITED_DATA_INDICATION);
static const string PTypedDataIndication(Literal::P_TYPED_DATA_INDICATION);

static const string PSendRequest(Literal::P_SEND_REQUEST);
static const string PWriteRequest(Literal::P_WRITE_REQUEST);

static const string PReleaseRequest(Literal::P_RELEASE_REQUEST);
static const string PReleaseRetryRequest(Literal::P_RELEASE_RETRY_REQUEST);
static const string PReleaseResponse(Literal::P_RELEASE_RESPONSE);

static const string PUExceptionReportRequest(Literal::P_U_EXCEPTION_REPORT_REQUEST);

static const string PConnectRequest(Literal::P_CONNECT_REQUEST);
static const string PConnectIndication(Literal::P_CONNECT_INDICATION);
static const string PConnectResponse(Literal::P_CONNECT_RESPONSE);
static const string PConnectConfirmation(Literal::P_CONNECT_CONFIRMATION);

static const string PAlterContextRequest(Literal::P_ALTER_CONTEXT_REQUEST);
static const string PAlterContextIndication(Literal::P_ALTER_CONTEXT_INDICATION);
static const string PAlterContextResponse(Literal::P_ALTER_CONTEXT_RESPONSE);
static const string PAlterContextConfirmation(Literal::P_ALTER_CONTEXT_CONFIRMATION);

static const string PResynchronizeRequest(Literal::P_RESYNCHRONIZE_REQUEST);
static const string PResynchronizeResponse(Literal::P_RESYNCHRONIZE_RESPONSE);
static const string PResynchronizeIndication(Literal::P_RESYNCHRONIZE_INDICATION);
static const string PResynchronizeConfirmation(Literal::P_RESYNCHRONIZE_CONFIRMATION);

static const string PSyncMajorRequest(Literal::P_SYNC_MAJOR_REQUEST);
static const string PSyncMajorResponse(Literal::P_SYNC_MAJOR_RESPONSE);
static const string PSyncMajorIndication(Literal::P_SYNC_MAJOR_INDICATION);
static const string PSyncMajorConfirmation(Literal::P_SYNC_MAJOR_CONFIRMATION);
static const string PSyncMinorRequest(Literal::P_SYNC_MINOR_REQUEST);
static const string PSyncMinorResponse(Literal::P_SYNC_MINOR_RESPONSE);
static const string PSyncMinorIndication(Literal::P_SYNC_MINOR_INDICATION);
static const string PSyncMinorConfirmation(Literal::P_SYNC_MINOR_CONFIRMATION);


static const string PControlGiveRequest(Literal::P_CONTROL_GIVE_REQUEST);
static const string PControlGiveIndication(Literal::P_CONTROL_GIVE_INDICATION);
static const string PTokenGiveRequest(Literal::P_TOKEN_GIVE_REQUEST);
static const string PTokenGiveIndication(Literal::P_TOKEN_GIVE_INDICATION);
static const string PTokenPleaseRequest(Literal::P_TOKEN_PLEASE_REQUEST);
static const string PTokenPleaseIndication(Literal::P_TOKEN_PLEASE_INDICATION);


static const string PReleaseIndication(Literal::P_RELEASE_INDICATION);
static const string PReleaseConfirmation(Literal::P_RELEASE_CONFIRMATION);

static const string PUExceptionReportIndication(Literal::P_U_EXCEPTION_REPORT_INDICATION);
static const string PPExceptionReportIndication(Literal::P_P_EXCEPTION_REPORT_INDICATION);


namespace ALS {
namespace PSAP {
namespace PROV {
ReturnCode Logger::PConnectRequest(
	const PresentationAddress& callingPresentationAddress,
	const PresentationAddress& calledPresentationAddress,
	const Presentation_context_definition_list& presentationContexts,
	const Default_context_name& defaultContext,
	const Presentation_requirements& presentationRequirements,
	const Mode_selector& mode,
	const User_session_requirements& sessionRequirements,
	const SSN& isn,
	const int settings,
	const Reference& reference,
	const QualityOfService& qualityOfService, const User_data* userData) {
	information(prefix, REQUEST, ::PConnectRequest);
	return OK; 
}
ReturnCode Logger::PConnectIndication(
	const PresentationAddress& callingPresentationAddress,
	const PresentationAddress& calledPresentationAddress,
	const Presentation_context_definition_list& presentationContexts,
	const Presentation_context_definition_result_list& presentationResults,
	const Default_context_name& defaultContext,
	const Presentation_requirements& presentationRequirements,
	const Mode_selector& mode,
	const User_session_requirements& sessionRequirements,
	const SSN& isn,
	int settings,
	const Reference& reference, 
	const QualityOfService& qualityOfService, const User_data* userData) {
	information(prefix, INDICATION, ::PConnectIndication);
	return OK; 
}
ReturnCode Logger::PConnectResponse(int status, const PresentationAddress& respondingPresentationAddress,const Presentation_context_definition_result_list& results,
	int defaultContextResult, const Presentation_requirements& presentationRequirements, const User_session_requirements& usessionRequirements,
	const SSN& isn, byte settings, const Reference& reference, const User_data* userData) {
	information(prefix, RESPONSE, ::PConnectResponse);
	return OK; 
}
ReturnCode Logger::PConnectConfirmation(
	const PresentationAddress& respondingPresentationAddress,
	const Presentation_context_definition_list& presentationContexts,
	const Presentation_context_definition_result_list& presentationResults,
	const int defaultContextResult,
	const Presentation_requirements& presentationRequirements, 
	const User_session_requirements& sessionRequirements,
	const int settings, 
	const SSN& isn,
	const Reference& reference, 
	const int ssdusize,
	const QualityOfService& qualityOfService, 
	int result,
	const User_data* userData) {
	information(prefix, CONFIRMATION, ::PConnectConfirmation);
	return OK; 
}
ReturnCode Logger::PActivityDiscardRequest(int reason) {
	information(prefix, REQUEST, ::PActivityDiscardRequest);
	return OK; 
}
ReturnCode Logger::PActivityDiscardIndication(int reason, const User_data* userData) {
	information(prefix, INDICATION, ::PActivityDiscardIndication);
	return OK; 
}
ReturnCode Logger::PActivityDiscardResponse() {
	information(prefix, RESPONSE, ::PActivityDiscardResponse);
	return OK; 
}
ReturnCode Logger::PActivityDiscardConfirmation(const User_data* userData) {
	information(prefix, CONFIRMATION, ::PActivityDiscardConfirmation);
	return OK; 
}
ReturnCode Logger::PActivityInterruptRequest(int reason) {
	information(prefix, REQUEST, ::PActivityInterruptRequest);
	return OK; 
}
ReturnCode Logger::PActivityInterruptIndication(int reason, const User_data* userData) {
	information(prefix, INDICATION, ::PActivityInterruptIndication);
	return OK; 
}
ReturnCode Logger::PActivityInterruptResponse() {
	information(prefix, RESPONSE, ::PActivityInterruptResponse);
	return OK; 
}
ReturnCode Logger::PActivityInterruptConfirmation(const User_data* userData) {
	information(prefix, CONFIRMATION, ::PActivityInterruptConfirmation);
	return OK; 
}
ReturnCode Logger::PActivityStartRequest(const ActivityId& activityId, const User_data* userData) {
	information(prefix, REQUEST, ::PActivityStartRequest);
	return OK; 
}
ReturnCode Logger::PActivityStartIndication(const ActivityId& aid, const User_data* userData) {
	information(prefix, INDICATION, ::PActivityStartIndication);
	return OK; 
}
ReturnCode Logger::PActivityResumeIndication(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldReference, const User_data* userData) {
	information(prefix, INDICATION, ::PActivityResumeIndication);
	return OK; 
}
ReturnCode Logger::PActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& ssn, const Reference& oldReference,	const User_data* userData) {
	information(prefix, REQUEST, ::PActivityResumeRequest);
	return OK; 
}
ReturnCode Logger::PActivityEndRequest(const SSN& ssn, const User_data* userData) {
	information(prefix, REQUEST, ::PActivityEndRequest);
	return OK; 
}
ReturnCode Logger::PActivityEndIndication(const SSN& ssn, const User_data* userData) {
	information(prefix, INDICATION, ::PActivityEndIndication);
	return OK; 
}
ReturnCode Logger::PActivityEndResponse(const User_data* userData) {
	information(prefix, RESPONSE, ::PActivityEndResponse);
	return OK; 
}
ReturnCode Logger::PActivityEndConfirmation(const SSN& secondSSN, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PActivityEndConfirmation);
	return OK; 
}
ReturnCode Logger::PAlterContextRequest(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const User_data* userData) {
	information(prefix, REQUEST, ::PAlterContextRequest);
	return OK; 
}
ReturnCode Logger::PAlterContextIndication(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const Presentation_context_addition_result_list& presentationAdditionResults,	const User_data* userData) {
	information(prefix, INDICATION, ::PAlterContextIndication);
	return OK; 
}
ReturnCode Logger::PAlterContextResponse(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData) {
	information(prefix, RESPONSE, ::PAlterContextResponse);
	return OK; 
}
ReturnCode Logger::PAlterContextConfirmation(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PAlterContextConfirmation);
	return OK; 
}
ReturnCode Logger::PCapabilityDataRequest(const User_data* userData) {
	information(prefix, REQUEST, ::PCapabilityDataRequest);
	return OK; 
}
ReturnCode Logger::PDataRequest(const User_data* data) {
	information(prefix, REQUEST, ::PDataRequest);
	return OK; 
}
ReturnCode Logger::PExpeditedDataRequest(const User_data* userData) {
	information(prefix, REQUEST, ::PExpeditedDataRequest);
	return OK; 
}
ReturnCode Logger::PTypedDataRequest(const User_data* userData) {
	information(prefix, REQUEST, ::PTypedDataRequest);
	return OK; 
}
ReturnCode Logger::PDataIndication(const User_data& userData) {
	information(prefix, INDICATION, ::PDataIndication);
	return OK; 
}
ReturnCode Logger::PExpeditedDataIndication(const User_data& userData) {
	information(prefix, INDICATION, ::PExpeditedDataIndication);
	return OK; 
}
ReturnCode Logger::PTypedDataIndication(const User_data& userData) {
	information(prefix, INDICATION, ::PTypedDataIndication);
	return OK; 
}
ReturnCode Logger::PCapabilityDataIndication(const User_data& userData) {
	information(prefix, INDICATION, ::PCapabilityDataIndication);
	return OK; 
}
ReturnCode Logger::PCapabilityDataResponse(const User_data* userData) {
	information(prefix, RESPONSE, ::PCapabilityDataResponse);
	return OK; 
}
ReturnCode Logger::PCapabilityDataConfirmation(const User_data& userData) {
	information(prefix, CONFIRMATION, ::PCapabilityDataConfirmation);
	return OK; 
}
ReturnCode Logger::PResynchronizeRequest(const ResyncOption& type, const SSN& ssn, byte tokens, const User_data* userData) {
	information(prefix, REQUEST, ::PResynchronizeRequest);
	return OK; 
}
ReturnCode Logger::PSyncMajorRequest(const SSN& ssn, const User_data* userData) {
	information(prefix, REQUEST, ::PSyncMajorRequest);
	return OK; 
}
ReturnCode Logger::PSyncMinorRequest(const SyncOption& type, const SSN& ssn, const User_data* userData) {
	information(prefix, REQUEST, ::PSyncMinorRequest);
	return OK; 
}
ReturnCode Logger::PSyncMajorIndication(SSN ssn, const User_data* userData) {
	information(prefix, INDICATION, ::PSyncMajorIndication);
	return OK; 
}
ReturnCode Logger::PSyncMinorIndication(SyncOption type, const SSN& ssn, const User_data* userData) {
	information(prefix, INDICATION, ::PSyncMinorIndication);
	return OK; 
}
ReturnCode Logger::PResynchronizeConfirmation(const SSN& ssn, byte tokens, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PResynchronizeConfirmation);
	return OK; 
}
ReturnCode Logger::PResynchronizeIndication(SyncOption type, const SSN& ssn, byte tokens, const Presentation_context_identifier_list& presentationIdentifications, const User_data* userData) {
	information(prefix, INDICATION, ::PResynchronizeIndication);
	return OK; 
}
ReturnCode Logger::PSyncMajorConfirmation(const SSN& ssn, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PSyncMajorConfirmation);
	return OK; 
}
ReturnCode Logger::PSyncMinorConfirmation(const SSN& ssn, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PSyncMinorConfirmation);
	return OK; 
}
ReturnCode Logger::PResynchronizeResponse(const SSN& ssn, int tokens, const Presentation_context_identifier_list& presentationIdentififiers, const User_data* userData) {
	information(prefix, RESPONSE, ::PResynchronizeResponse);
	return OK; 
}
ReturnCode Logger::PSyncMajorResponse(const User_data* userData) {
	information(prefix, RESPONSE, ::PSyncMajorResponse);
	return OK; 
}
ReturnCode Logger::PSyncMinorResponse(const SSN& ssn, const User_data* userData) {
	information(prefix, RESPONSE, ::PSyncMinorResponse);
	return OK; 
}
ReturnCode Logger::PControlGiveRequest() {
	information(prefix, REQUEST, ::PControlGiveRequest);
	return OK; 
}
ReturnCode Logger::PTokenGiveRequest(int tokens, const User_data* userData) {
	information(prefix, REQUEST, ::PTokenGiveRequest);
	return OK; 
}
ReturnCode Logger::PTokenPleaseRequest(int tokens, const User_data* userData) {
	information(prefix, REQUEST, ::PTokenPleaseRequest);
	return OK; 
}
ReturnCode Logger::PTokenGiveIndication(byte tokens, const User_data* userData) {
	information(prefix, INDICATION, ::PTokenGiveIndication);
	return OK; 
}
ReturnCode Logger::PControlGiveIndication(byte tokens, const User_data* userData) {
	information(prefix, INDICATION, ::PControlGiveIndication);
	return OK; 
}
ReturnCode Logger::PTokenPleaseIndication(byte tokens, const User_data* userData) {
	information(prefix, INDICATION, ::PTokenPleaseIndication);
	return OK; 
}
ReturnCode Logger::PUExceptionReportRequest(int reason, const User_data* userData) {
	information(prefix, REQUEST, ::PUExceptionReportRequest);
	return OK; 
}
ReturnCode Logger::PPExceptionReportIndication(int reason) {
	information(prefix, INDICATION, ::PPExceptionReportIndication);
	return OK; 
}
ReturnCode Logger::PUExceptionReportIndication(int reason, const User_data* userData) {
	information(prefix, INDICATION, ::PUExceptionReportIndication);
	return OK; 
}
ReturnCode Logger::PUAbortRequest(const User_data* userData) {
	information(prefix, REQUEST, ::PUAbortRequest);
	return OK; 
}
ReturnCode Logger::PUAbortIndication(int reason, int extension, const User_data* userData) {
	information(prefix, INDICATION, ::PUAbortIndication);
	return OK; 
}
ReturnCode Logger::PPAbortIndication(int reason, int extension, const User_data* userData) {
	information(prefix, INDICATION, ::PPAbortIndication);
	return OK; 
}
ReturnCode Logger::PReleaseRequest(int secs, const User_data* userData) {
	information(prefix, REQUEST, ::PReleaseRequest);
	return OK; 
}
ReturnCode Logger::PReleaseResponse(int status, const User_data* userData) {
	information(prefix, RESPONSE, ::PReleaseResponse);
	return OK; 
}
ReturnCode Logger::PReleaseIndication(const User_data* userData) {
	information(prefix, INDICATION, ::PReleaseIndication);
	return OK; 
}
ReturnCode Logger::PReleaseConfirmation(bool affirmative, const User_data* userData) {
	information(prefix, CONFIRMATION, ::PReleaseConfirmation);
	return OK; 
}
}
}
}
