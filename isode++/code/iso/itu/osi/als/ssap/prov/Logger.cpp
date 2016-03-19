/*
 * Logger.cpp
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */
#include <string>
using std::string;

#include "Poco/NumberFormatter.h"
using Poco::NumberFormatter;

#include "als/ssap/prov/Logger.h"
#include "als/ssap/ActivityId.h"
#include "als/ssap/Literal.h"
#include "als/ssap/SSN.h"
#include "als/ssap/Token.h"
using ALS::SSAP::ActivityId;
using ALS::SSAP::Literal;
using ALS::SSAP::SSN;
using ALS::SSAP::Token;

static const string SPAbortRequest(Literal::S_P_ABORT_REQUEST);
static const string SUAbortRequest(Literal::S_U_ABORT_REQUEST);
static const string SUAbortIndication(Literal::S_U_ABORT_INDICATION);
static const string SPAbortIndication(Literal::S_P_ABORT_INDICATION);


static const string SActivityDiscardRequest(Literal::S_ACTIVITY_DISCARD_REQUEST);
static const string SActivityEndRequest(Literal::S_ACTIVITY_END_REQUEST);
static const string SActivityInterruptRequest(Literal::S_ACTIVITY_INTERRUPT_REQUEST);
static const string SActivityResumeRequest(Literal::S_ACTIVITY_RESUME_REQUEST);
static const string SActivityStartRequest(Literal::S_ACTIVITY_START_REQUEST);
static const string SActivityDiscardResponse(Literal::S_ACTIVITY_DISCARD_RESPONSE);
static const string SActivityEndResponse(Literal::S_ACTIVITY_END_RESPONSE);
static const string SActivityInterruptResponse(Literal::S_ACTIVITY_INTERRUPT_RESPONSE);
static const string SActivityStartIndication(Literal::S_ACTIVITY_START_INDICATION);
static const string SActivityResumeIndication(Literal::S_ACTIVITY_RESUME_INDICATION);
static const string SActivityInterruptConfirmation(Literal::S_ACTIVITY_INTERRUPT_CONFIRMATION);
static const string SActivityInterruptIndication(Literal::S_ACTIVITY_INTERRUPT_INDICATION);
static const string SActivityDiscardIndication(Literal::S_ACTIVITY_DISCARD_INDICATION);
static const string SActivityEndIndication(Literal::S_ACTIVITY_END_INDICATION);
static const string SActivityDiscardConfirmation(Literal::S_ACTIVITY_DISCARD_CONFIRMATION);
static const string SActivityEndConfirmation(Literal::S_ACTIVITY_END_CONFIRMATION);

static const string SDataRequest(Literal::S_DATA_REQUEST);
static const string SCapabilityDataRequest(Literal::S_CAPABILITY_DATA_REQUEST);
static const string SCapabilityDataResponse(Literal::S_CAPABILITY_DATA_RESPONSE);
static const string SCapabilityDataIndication(Literal::S_CAPABILITY_DATA_INDICATION);
static const string SCapabilityDataConfirmation(Literal::S_CAPABILITY_DATA_CONFIRMATION);
static const string SExpeditedDataRequest(Literal::S_EXPEDITED_DATA_REQUEST);
static const string STypedDataRequest(Literal::S_TYPED_DATA_REQUEST);
static const string SDataIndication(Literal::S_DATA_INDICATION);
static const string SExpeditedDataIndication(Literal::S_EXPEDITED_DATA_INDICATION);
static const string STypedDataIndication(Literal::S_TYPED_DATA_INDICATION);

static const string SSendRequest(Literal::S_SEND_REQUEST);
static const string SWriteRequest(Literal::S_WRITE_REQUEST);

static const string SReleaseRequest(Literal::S_RELEASE_REQUEST);
static const string SReleaseRetryRequest(Literal::S_RELEASE_RETRY_REQUEST);
static const string SReleaseResponse(Literal::S_RELEASE_RESPONSE);

static const string SUExceptionReportRequest(Literal::S_U_EXCEPTION_REPORT_REQUEST);

static const string SConnectRequest(Literal::S_CONNECT_REQUEST);
static const string SConnectResponse(Literal::S_CONNECT_RESPONSE);
static const string SConnectIndication(Literal::S_CONNECT_INDICATION);
static const string SConnectConfirmation(Literal::S_CONNECT_CONFIRMATION);

static const string SResynchronizeRequest(Literal::S_RESYNCHRONIZE_REQUEST);
static const string SResynchronizeResponse(Literal::S_RESYNCHRONIZE_RESPONSE);
static const string SResynchronizeIndication(Literal::S_RESYNCHRONIZE_INDICATION);
static const string SResynchronizeConfirmation(Literal::S_RESYNCHRONIZE_CONFIRMATION);

static const string SSyncMajorRequest(Literal::S_SYNC_MAJOR_REQUEST);
static const string SSyncMajorResponse(Literal::S_SYNC_MAJOR_RESPONSE);
static const string SSyncMajorIndication(Literal::S_SYNC_MAJOR_INDICATION);
static const string SSyncMajorConfirmation(Literal::S_SYNC_MAJOR_CONFIRMATION);
static const string SSyncMinorRequest(Literal::S_SYNC_MINOR_REQUEST);
static const string SSyncMinorResponse(Literal::S_SYNC_MINOR_RESPONSE);
static const string SSyncMinorIndication(Literal::S_SYNC_MINOR_INDICATION);
static const string SSyncMinorConfirmation(Literal::S_SYNC_MINOR_CONFIRMATION);


static const string SControlGiveRequest(Literal::S_CONTROL_GIVE_REQUEST);
static const string SControlGiveIndication(Literal::S_CONTROL_GIVE_INDICATION);
static const string STokenGiveRequest(Literal::S_TOKEN_GIVE_REQUEST);
static const string STokenGiveIndication(Literal::S_TOKEN_GIVE_INDICATION);
static const string STokenPleaseRequest(Literal::S_TOKEN_PLEASE_REQUEST);
static const string STokenPleaseIndication(Literal::S_TOKEN_PLEASE_INDICATION);


static const string SReleaseIndication(Literal::S_RELEASE_INDICATION);
static const string SReleaseConfirmation(Literal::S_RELEASE_CONFIRMATION);

static const string SUExceptionReportIndication(Literal::S_U_EXCEPTION_REPORT_INDICATION);
static const string SPExceptionReportIndication(Literal::S_P_EXCEPTION_REPORT_INDICATION);

namespace ALS {
namespace SSAP {
namespace PROV {

ReturnCode Logger::SConnectRequest(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, byte settings, int cc, const void* data) {
	const string& callingAddrAsString = calling.to_string();
	const string& calledAddrAsString = called.to_string();
	trace(prefix + "calling=%s, called=%s, requirements=%?d, settings=%s, cc=%?d",
		REQUEST, ::SConnectRequest, callingAddrAsString, calledAddrAsString, requirements.to_ulong(), NumberFormatter::formatHex(settings, true), cc);
	return OK;
}
ReturnCode Logger::SConnectResponse(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement& requirements, int settings, SSN& firstInitialSSN, SSN& secondInitialSSN, int cc, const void* data) {
	const string&  respondingAddrAsString = responding.to_string();
	trace(prefix + "responding=%s, result=%?d, requirements=%?d, settings=%s, cc=%?d", 
		RESPONSE, ::SConnectResponse, respondingAddrAsString, result, requirements.to_ulong(), NumberFormatter::formatHex(settings, true), cc);
	return OK;
}
ReturnCode Logger::SConnectIndication(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, int result, const QualityOfService& qualityOfService, const Requirement& requirements, SSN& firstInitialSSN, SSN& secondInitialSSN, int settings, int ssdusize, int cc, const void* data) {
	const string&  callingAddrAsString = calling.to_string();
	const string&  calledAddrAsString = called.to_string();
	trace(prefix + "calling=%s, called=%s, result=%?d, requirements=%?d, settings=%s, cc=%?d", 
		INDICATION, ::SConnectIndication, callingAddrAsString, calledAddrAsString, result, (int)requirements.to_ulong(), NumberFormatter::formatHex(settings, true), cc);
	return DONE;
}
ReturnCode Logger::SConnectConfirmation(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize, int cc, const void* data, int rdcc, const void* realdata) {
	const string&  respondingAddrAsString = responding.to_string();
	trace(prefix + "responding=%s, result=%?d, requirements=%?d, settings=%s, cc=%?d", 
		CONFIRMATION, ::SConnectConfirmation, respondingAddrAsString, result, requirements.to_ulong(), NumberFormatter::formatHex(settings, true), cc);
	return DONE;
}
ReturnCode Logger::SUAbortRequest(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SUAbortRequest, cc);
	return OK;
}
ReturnCode Logger::SActivityDiscardRequest(int reason, int cc, const void* data) { 
	trace(prefix + "reason=%?d, cc=%?d", REQUEST, ::SActivityDiscardRequest, reason, cc);
	return OK;
}
ReturnCode Logger::SActivityEndRequest(SSN& firstSSN, int cc, const void* data) { 
	trace(prefix + "ssn=%?d, cc=%?d", REQUEST, ::SActivityEndRequest, (int)firstSSN, cc);
	return OK;
}
ReturnCode Logger::SActivityInterruptRequest(int reason, int cc, const void* data) { 
	trace(prefix + "reason=%?d, cc=%?d", REQUEST, ::SActivityInterruptRequest, reason, cc);
	return OK;
}
ReturnCode Logger::SActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN&  secondSSN, const Reference& reference, int cc, const void* data) {
	trace(prefix + "activityId=%s, cc=%?d", REQUEST, ::SActivityResumeRequest, activityId.to_string(), cc);
	return OK; 
}
ReturnCode Logger::SActivityStartRequest(const ActivityId& activityId, int cc, const void* data) { 
	trace(prefix + "activityId=%s, cc=%?d", REQUEST, ::SActivityStartRequest, activityId.to_string() , cc);
	return OK;
}
ReturnCode Logger::SActivityDiscardResponse(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SActivityDiscardResponse, cc);
	return OK;
}
ReturnCode Logger::SActivityEndResponse(int cc, const void* data) { 
	trace(prefix + "cc=%?d", REQUEST, ::SActivityEndResponse, cc);
	return OK;
}
ReturnCode Logger::SActivityEndResponse(const SSN& secondSSN, int cc, const void* data) { 
	trace(prefix + "ssn=%?d, cc=%?d", REQUEST, ::SActivityEndResponse, (int)secondSSN, cc);
	return OK;
}
ReturnCode Logger::SActivityInterruptResponse(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SActivityInterruptResponse, cc);
	return OK;
}
ReturnCode Logger::SActivityStartIndication(const ActivityId&  activityId, int cc, const void* data) { 
	trace(prefix + "activityId=%s, cc=%?d", INDICATION, ::SActivityStartIndication, activityId.to_string(), cc);
	return DONE;
}
ReturnCode Logger::SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc, const void* data) {
	trace(prefix + "cc=%?d", INDICATION, ::SActivityResumeIndication, cc);
	return DONE;
}
ReturnCode Logger::SActivityInterruptConfirmation(int cc, const void* data) {
	trace(prefix + "cc=%?d", CONFIRMATION, ::SActivityInterruptConfirmation, cc);
	return DONE;
}
ReturnCode Logger::SActivityInterruptIndication(int reason, int cc, const void* data) { 
	trace(prefix + "cc=%?d", INDICATION, ::SActivityInterruptIndication, cc);
	return DONE;
}
ReturnCode Logger::SActivityDiscardIndication(int reason, int cc, const void* data) {
	trace(prefix + "cc=%?d", INDICATION, ::SActivityDiscardIndication, cc);
	return DONE;
}
ReturnCode Logger::SActivityEndIndication(const SSN& firstSSN, int cc, const void* data) {
	trace(prefix + "ssn=%?d, cc=%?d", INDICATION, ::SActivityEndIndication, (int)firstSSN, cc);
	return DONE;
}
ReturnCode Logger::SActivityDiscardConfirmation(int cc, const void* data) { 
	trace(prefix + "cc=%?d", CONFIRMATION, ::SActivityDiscardConfirmation, cc);
	return DONE;
}
ReturnCode Logger::SActivityEndConfirmation(int cc, const void* data) {
	trace(prefix + "cc=%?d", CONFIRMATION, ::SActivityEndConfirmation, cc);
	return DONE;
}
ReturnCode Logger::SActivityEndConfirmation(const SSN& secondSSN, int cc, const void* data) {
	trace(prefix + "cc=%?d", CONFIRMATION, ::SActivityEndConfirmation, cc);
	return DONE;
}
ReturnCode Logger::SDataRequest(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SDataRequest, cc);
	return OK;
}
ReturnCode Logger::SCapabilityDataRequest(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SCapabilityDataRequest, cc);
	return OK;
}
ReturnCode Logger::SCapabilityDataResponse(int cc, const void* data) {
	trace(prefix + "cc=%?d", RESPONSE, ::SCapabilityDataResponse, cc);
	return OK;
}
ReturnCode Logger::SCapabilityDataIndication(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", INDICATION, ::SCapabilityDataIndication, data.total());
	return DONE;
}
ReturnCode Logger::SCapabilityDataConfirmation(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", CONFIRMATION, ::SCapabilityDataConfirmation, data.total());
	return DONE;
}
ReturnCode Logger::SExpeditedDataRequest(int cc, const void* data) { 
	trace(prefix + "cc=%?d", REQUEST, ::SExpeditedDataRequest, cc);
	return OK;
}
ReturnCode Logger::SDataRequest(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", REQUEST, ::SDataRequest, data.total());
	return OK;
}
ReturnCode Logger::STypedDataRequest(int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::STypedDataRequest, cc);
	return OK;
}
ReturnCode Logger::SDataIndication(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", INDICATION, ::SDataIndication, data.total());
	return DONE;
}
ReturnCode Logger::SExpeditedDataIndication(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", INDICATION, ::SExpeditedDataIndication, data.total());
	return DONE;
}
ReturnCode Logger::STypedDataIndication(const SharedNetworkBuffer& data) {
	trace(prefix + "cc=%?d", INDICATION, ::STypedDataIndication, data.total());
	return DONE;
}
ReturnCode Logger::SSendRequest(bool begin, bool end, int cc, const void* data) {
	return OK; 
}
ReturnCode Logger::SWriteRequest(bool typed, int cc, const void* data) {
	return OK;
}
ReturnCode Logger::SReleaseRequest(int secs, int cc, const void* data) {
	trace(prefix + "secs=%?d, cc=%?d", REQUEST, ::SReleaseRequest, secs, cc);
	return OK;
}
ReturnCode Logger::SReleaseRetryRequest(int status) {
	trace(prefix + "status=%?d", REQUEST, ::SReleaseRetryRequest, status);
	return OK;
}
ReturnCode Logger::SReleaseResponse(bool accept, int cc, const void* data) { 
	trace(prefix + "accept=%b, cc=%?d", RESPONSE, ::SReleaseResponse, accept, cc);
	return OK;
}
ReturnCode Logger::SUExceptionReportRequest(int reason, int cc, const void* data) {
	trace(prefix + "cc=%?d", REQUEST, ::SUExceptionReportRequest, cc);
	return OK;
}
ReturnCode Logger::SResynchronizeRequest(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) { 
	string resyncAsString = resync_to_string(firstResync);
	trace(prefix + "resync=%s, ssn=%?d, settings=%s, cc=%?d", REQUEST, ::SResynchronizeRequest, resyncAsString, (int)firstSSN, NumberFormatter::formatHex(settings, true), cc);
	return OK;
}
ReturnCode Logger::SResynchronizeResponse(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) { 
	string resyncAsString = resync_to_string(firstResync);
	trace(prefix + "resync=%s, ssn=%?d, settings=%s, cc=%?d", RESPONSE, ::SResynchronizeResponse,  resyncAsString, (int)firstSSN, NumberFormatter::formatHex(settings, true), cc);
	return OK;
}
ReturnCode Logger::SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) { 
	string resyncAsString = resync_to_string(firstResync);
	trace(prefix + "resync=%s, ssn=%?d, settings=%s, cc=%?d", INDICATION, ::SResynchronizeIndication, resyncAsString, (int)firstSSN, NumberFormatter::formatHex(settings, true), cc);
	return DONE;
}
ReturnCode Logger::SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) { 
	string resyncAsString = resync_to_string(firstResync);
	trace(prefix + "resync=%s, ssn=%?d, settings=%s, cc=%?d", CONFIRMATION, ::SResynchronizeConfirmation, resyncAsString, (int)firstSSN,  NumberFormatter::formatHex(settings, true), cc);
	return DONE;
}
ReturnCode Logger::SSyncMajorRequest(SSN& firstSSN, int cc, const void* data) { 
	trace(prefix + "ssn=%?d, cc=%?d", REQUEST, ::SSyncMajorRequest, (int)firstSSN, cc);
	return OK;
}
ReturnCode Logger::SSyncMajorResponse(int cc, const void* data) { 
	trace(prefix + "cc=%?d", RESPONSE, ::SSyncMajorResponse, cc);
	return OK;
}
ReturnCode Logger::SSyncMajorResponse(const SSN& secondSSN, int cc, const void* data) { 
	trace(prefix + "cc=%?d", RESPONSE, ::SSyncMajorResponse, cc);
	return OK;
}
ReturnCode Logger::SSyncMajorIndication(const SSN& firstSSN, int cc, const void* data) {
	trace(prefix + "ssn=%?d, cc=%?d", INDICATION, ::SSyncMajorIndication, (int)firstSSN, cc);
	return DONE;
}
ReturnCode Logger::SSyncMajorConfirmation(int cc, const void* data) {
	trace(prefix + "cc=%?d", CONFIRMATION, ::SSyncMajorConfirmation, cc);
	return DONE;
}
ReturnCode Logger::SSyncMajorConfirmation(const SSN& secondSSN, int cc, const void* data) {
	trace(prefix + "ssn=%?d, cc=%?d", CONFIRMATION, ::SSyncMajorConfirmation, (int) secondSSN, cc);
	return DONE;
}
ReturnCode Logger::SSyncMinorRequest(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc, const void* data) {
	trace(prefix + "dataSeparation=%b, ssn=%?d, cc=%?d", REQUEST, ::SSyncMinorRequest, dataSeparation, (int) firstSSN,  cc);
	return OK;
}
ReturnCode Logger::SSyncMinorResponse(const SSN& firstSSN, int cc, const void* data) {
	trace(prefix + "ssn=%?d, cc=%?d", RESPONSE, ::SSyncMinorResponse, (int)firstSSN, cc);
	return OK;
}
ReturnCode Logger::SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc, const void* data) {
	trace(prefix + "dataSeparation=%b, ssn=%?d, cc=%?d", INDICATION, ::SSyncMinorIndication, dataSeparation, (int) firstSSN, cc);
	return DONE;
}
ReturnCode Logger::SSyncMinorConfirmation(const SSN& firstSSN, int cc, const void* data) { 
	trace(prefix + "ssn=%?d, cc=%?d", CONFIRMATION, ::SSyncMinorConfirmation, (int)firstSSN, cc);
	return DONE;
}
ReturnCode Logger::SControlGiveRequest() { 
	trace(prefix, REQUEST, ::SControlGiveRequest);
	return OK;
}
ReturnCode Logger::STokenGiveRequest(int tokens, int cc, const void* data) { 
	trace(prefix + "%s, cc=%?d", REQUEST, ::STokenGiveRequest, Token::token(tokens), cc);
	return OK;
}
ReturnCode Logger::STokenPleaseRequest(int tokens, int cc, const void* data) { 
	trace(prefix + "%s, cc=%?d", REQUEST, ::STokenPleaseRequest, Token::token(tokens), cc);
	return OK;
}
ReturnCode Logger::SUAbortIndication(int reason, int cc, const void* data) { 
	trace(prefix + "reason=%?d, cc=%?d", INDICATION, ::SUAbortIndication, reason, cc);
	return DONE;
}
ReturnCode Logger::SPAbortIndication(int reason, int extension, int cc, const void* data) { 
	trace(prefix + "reason=%?d, extension=%?d, cc=%?d", INDICATION, ::SPAbortIndication, reason, extension, cc);
	return DONE;
}
ReturnCode Logger::SReleaseIndication(int cc, const void* data) {
	trace(prefix + "cc=%?d", INDICATION, ::SReleaseIndication, cc);
	return DONE;
}
ReturnCode Logger::SReleaseConfirmation(bool affirmative, int cc, const void* data) { 
	trace(prefix + "affirmative=%b, cc=%?d", CONFIRMATION, ::SReleaseConfirmation, affirmative, cc);
	return DONE;
}
ReturnCode Logger::SUExceptionReportIndication(int reason, int cc, const void* data) { 
	trace(prefix + "reason=%?d, cc=%?d", INDICATION, ::SUExceptionReportIndication, reason, cc);
	return DONE;
}
ReturnCode Logger::SPExceptionReportIndication(int reason) { 
	trace(prefix + "reason=%?d", INDICATION, ::SPExceptionReportIndication, reason);
	return DONE;
}
ReturnCode Logger::STokenGiveIndication(int tokens, int cc, const void* data) {
	trace(prefix + "%s, cc=%?d", INDICATION, ::STokenGiveIndication, Token::token(tokens), cc);
	return DONE;
}
ReturnCode Logger::STokenPleaseIndication(int tokens, int cc, const void* data) { 
	trace(prefix + "%s, cc=%?d", INDICATION, ::STokenPleaseIndication, Token::token(tokens), cc);
	return DONE;
}
ReturnCode Logger::SControlGiveIndication(int tokens, int cc, const void* data) { 
	trace(prefix + "%s, cc=%?d", INDICATION, ::SControlGiveIndication, Token::token(tokens), cc);
	return DONE;
}
}
}
}
