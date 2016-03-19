/*
 * SSAPEchoServer.cpp
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */
#define ISODE

#include <iostream>
#include "Poco/Format.h"
using Poco::format;

#include "Poco/ClassLibrary.h"
#ifndef POCO_EXPORT_INTERFACE

#define POCO_EXPORT_INTERFACE(cls, itf) \
    pManifest->insert(new Poco::MetaObject<cls, _Base>(itf));

#endif

#include "demo/SSAPEchoServer/SSAPEchoServer.h"
#include "als/base/util/NetworkBuffer.h"
#include "als/base/root/Logger.h"
#include "als/ssap/AbortCode.h"
#include "als/ssap/prov/Provider.h"
#include "als/ssap/Literal.h"
#include "als/ssap/SyncOption.h"

using namespace std;
using ALS::SSAP::AbortCode;
using ALS::SSAP::Literal;
using ALS::SSAP::SyncOption;

void pocoInitializeLibrary()
{
	cout << "#################### ALS::SSAP::SSAPEchoServer initializing" << endl;
}
void pocoUninitializeLibrary()
{
	cout << "#################### ALS::SSAP::SSAPEchoServer uninitializing" << endl;
}
POCO_BEGIN_NAMED_MANIFEST(ALS_SSAP_USER_Responder, ALS::SSAP::USER::Responder)
	POCO_EXPORT_INTERFACE(ALS::SSAP::SSAPEchoServer, "ALS::SSAP::USER::Responder")
POCO_END_MANIFEST

#define info information

namespace ALS {
namespace SSAP {
SSAPEchoServer::SSAPEchoServer() {
}
SSAPEchoServer::~SSAPEchoServer() {
}
USER::Initiator* 
SSAPEchoServer::initiator() const {
	return nullptr;
}
SERV::Responder*&
SSAPEchoServer::provider() {
	return ssap_serv_responder;
}

ReturnCode SSAPEchoServer::SConnectIndication(
	const Reference&		reference,	//
	const SSAPAddr&			calling,			// the SSAP address of peer calling
	const SSAPAddr&			called,				// the SSAP address of peer called
	int						result,				// the result
	const QualityOfService&	qualityOfService,				// the quality of service
	const Requirement&		srequirements,		// the session requirements
	SSN&					firstInitialSSN,	//the initial serial number
	SSN&					secondInitialSSN,	// the second initial serial number
	int						settings,			// the initial settings of tokens
	int						ssdusize,			// the largest atomic SSDU
	int						cc,
	const void*				data) {
	
	ReturnCode rc;

	static const int		SREQUIREMENTS =
		  Requirement::toint(HALFDUPLEX) 
		| Requirement::toint(DUPLEX)
		| Requirement::toint(EXPEDITED)
		| Requirement::toint(MINORSYNC)
		| Requirement::toint(MAJORSYNC)
		| Requirement::toint(RESYNCHRONIZE)
		| Requirement::toint(ACTIVITY)
		| Requirement::toint(NEGOTIATED)
		| Requirement::toint(CAPABILITY)
		| Requirement::toint(EXCEPTIONS)
		| Requirement::toint(TYPEDATA);
	
	ssap().logger()->notice("greeting !");

	requirements = srequirements;
	requirements &= SREQUIREMENTS;
	if (requirements[HALFDUPLEX] && requirements[DUPLEX])
		requirements[DUPLEX] = false;

#ifdef ISODE
#define dotoken(requires,shift,bit,type) \
{ \
    if (requirements.has(requires)) \
	switch (settings & (CHOICE_MASK << shift)) { \
	    case CALLED_VALUE << shift: \
		ssap().logger()->info(format("%s token  : caller's choice", type)); \
		settings &= ~(CHOICE_MASK << shift); \
		settings |= INITIATOR_VALUE << shift; \
		break; \
 \
	    case INITIATOR_VALUE: \
		ssap().logger()->info(format("%s token  : initiator", type)); \
		break; \
 \
	    case RESPONDER_VALUE: \
		ssap().logger()->info(format("%s token  : responder", type)); \
		owned.add(bit); \
		break; \
 \
	    default: \
		return adios (nullptr, format("%s token: reserved", type)); \
		break; \
	} \
}
	dotokens();
#undef dotoken
#else
	if (requirements.has(RELEASE_UNIT_EXISTS))
		switch (selectReleaseToken(settings)) {
		case RELEASE_TOKEN_AS_CALLED_CHOICE:
			ssap().logger()->info("release token  : caller's choice: given to initiator");
			settings = clearReleaseToken(settings);
			settings = addInitiatorRelease(settings);
			break;

		case RELEASE_TOKEN_FOR_INITIATOR:
			ssap().logger()->info("release token  : initiator");
			break;

		case RELEASE_TOKEN_FOR_RESPONDER:
			ssap().logger()->info("release token  : responder");
			owned = addReleaseToken(owned);
			break;

		default:
			return adios(nullptr, "release token: reserved");
			break;
	}

	if (requirements.has(MAJOR_UNIT_EXISTS) || requirements.has(ACTIVITY_UNIT_EXISTS))
		switch (selectMajorToken(settings)) {
		case MAJOR_TOKEN_AS_CALLED_CHOICE:
			ssap().logger()->info("majorsync token: caller's choice: given to initiator");
			settings = clearMajorToken(settings);
			settings = addInitiatorMajor(settings);
			break;

		case MAJOR_TOKEN_FOR_INITIATOR:
			ssap().logger()->info("majorsync token: initiator");
			break;

		case MAJOR_TOKEN_FOR_RESPONDER:
			ssap().logger()->info("majorsync token: responder");
			owned = addMajorToken(owned);
			break;

		default:
			return adios(nullptr, "majorsync token: reserved");
			break;
	}

	if (requirements.has(MINOR_UNIT_EXISTS))
		switch (selectMinorToken(settings)) {
		case MINOR_TOKEN_AS_CALLED_CHOICE:
			ssap().logger()->info("minorsync token: caller's choice: given to initiator");
			settings = clearMinorToken(settings);
			settings = addInitiatorMinor(settings);
			break;

		case MINOR_TOKEN_FOR_INITIATOR:
			ssap().logger()->info("minorsync token: initiator");
			break;

		case MINOR_TOKEN_FOR_RESPONDER:
			ssap().logger()->info("minorsync token: responder");
			owned = addMinorToken(owned);
			break;

		default:
			return adios(nullptr, "minorsync token: reserved");
			break;
	}

	if (requirements.has(DATA_UNIT_EXISTS))
		switch (selectDataToken(settings)) {
		case DATA_TOKEN_AS_CALLED_CHOICE:
			ssap().logger()->info("data token     : caller's choice: given to initiator");
			settings = clearDataToken(settings);
			settings = addInitiatorData(settings);
			break;

		case DATA_TOKEN_FOR_INITIATOR:
			ssap().logger()->info("data token     : initiator");
			break;

		case DATA_TOKEN_FOR_RESPONDER:
			ssap().logger()->info("data token     : responder");
			owned = addDataToken(owned);
			break;

		default:
			return adios(nullptr, "data token: reserved");
			break;
	}
#endif

	ssap().logger()->info("owned tokens: " + Token::responder(owned));

	if (!(requirements[MINORSYNC] || requirements[MAJORSYNC] || requirements[RESYNCHRONIZE])) {
		firstInitialSSN = SERIAL_NONE;
		secondInitialSSN = SERIAL_NONE;
	}
	else {
		firstInitialSSN = SERIAL_MIN;
		secondInitialSSN = SERIAL_MIN;
	}

	rc = OK;
	switch (mode) {
	case echo:
	case sink:
		if (mode == sink) {
			data = nullptr; cc = 0;
		}
		if ((rc = ssap().SConnectResponse(reference, called, AbortCode::SC_ACCEPT, qualityOfService, requirements, settings, 
			firstInitialSSN, secondInitialSSN, cc, data)) != OK) {
			rc = ss_adios(Literal::S_CONNECT_RESPONSE);// +" (accept)");
		}

		break;

	default:
		string text = "entity unknown or unavailable";
		if (ssap().SConnectResponse(ssap().reference(), called, AbortCode::SC_REJECTED, qualityOfService, requirements, settings,
			firstInitialSSN, secondInitialSSN, text.size(), text.c_str())) {
			ss_adios(Literal::S_CONNECT_RESPONSE);// +" (reject)");
			ssap().logger()->info("rejected");
			rc = NOTOK;
		}
	}
	return rc;
}
ReturnCode SSAPEchoServer::SUAbortIndication(int reason, int cc, const void* data) {
	return DONE; 
}
ReturnCode SSAPEchoServer::SPAbortIndication(int reason, int extension, int cc, const void* data) {
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityDiscardIndication(int reason, int cc, const void* data) {
	if (ssap().SActivityDiscardResponse(cc, mode == echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_ACTIVITY_DISCARD_RESPONSE);
	owned = 0;
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityDiscardConfirmation(int cc, const void* data) {
	adios(nullptr, "got activity discard confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityEndIndication(const SSN& firstSSN, int cc, const void* data) {
	if (ssap().SActivityEndResponse(secondSSN, 0, mode == echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_ACTIVITY_END_RESPONSE);

	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityEndConfirmation(int cc, const void * data) {
	adios(nullptr, "got activity end confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityEndConfirmation(const SSN& secondSSN, int cc, const void* data) {
	adios(nullptr, "got activity end confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityInterruptIndication(int reason, int cc, const void* data) {
	if (ssap().SActivityInterruptResponse(cc, mode == echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_ACTIVITY_INTERRUPT_RESPONSE);
	owned = 0;
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityInterruptConfirmation(int cc, const void* data) {
	adios(nullptr, "got activity interrupt confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc, const void* data) {
	return DONE; 
}
ReturnCode SSAPEchoServer::SActivityStartIndication(const ActivityId&  activityId, int cc, const void* data) {
	this->activityId = activityId;
	return DONE; 
}
ReturnCode SSAPEchoServer::SDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc;
	char* text;

	if (mode == sink)
		return DONE;

	if (requirements[HALFDUPLEX]) {
		if (hx) {
			text = "protocol screw-up";
			if (ssap().SUAbortRequest(0, text) == NOTOK)
				rc = ss_adios(Literal::S_U_ABORT_REQUEST);
			else {
				adios(nullptr, "protocol screw-up");
				rc = NOTOK;
			}
		} else {
			hx = data;
			if (!owned.has(DATA_TOKEN) && ssap().STokenPleaseRequest(DATA_TOKEN) == NOTOK)
				rc = ss_adios(Literal::S_TOKEN_PLEASE_REQUEST);
			rc = DONE;
		}
	} else {
		byte* bytes = nullptr;//data.bytes();
		if (ssap().SDataRequest(data) == NOTOK)
			rc = ss_adios(Literal::S_DATA_REQUEST);
		rc = DONE;
	}

	return rc; 
}
ReturnCode SSAPEchoServer::SCapabilityDataIndication(const SharedNetworkBuffer& data) {
	byte* p = nullptr;int cc = 0;

	if (data && data->hasRemaining()) {
		p = data->bytes();
		cc = data->remaining();
	}
	if (ssap().SCapabilityDataResponse(cc, p) == NOTOK)
		ss_adios(Literal::S_CAPABILITY_DATA_RESPONSE);

	return DONE; 
}
ReturnCode SSAPEchoServer::SCapabilityDataConfirmation(const SharedNetworkBuffer& data) {
	adios(nullptr, "got capability data confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SExpeditedDataIndication(const SharedNetworkBuffer& data) {
	byte* p = nullptr;
	int cc = 0;

	if (data && data->hasRemaining()) {
		p = data->bytes();
		cc = data->remaining();
	}

	if (mode == echo) {
		p = data->bytes();
		if (ssap().SExpeditedDataRequest(cc, p) == NOTOK)
			ss_adios(Literal::S_EXPEDITED_DATA_REQUEST);
	}
	return DONE; 
}
ReturnCode SSAPEchoServer::STypedDataIndication(const SharedNetworkBuffer& data) {
	byte* p = nullptr;
	int cc = 0;

	if (data && data->hasRemaining()) {
		p = data->bytes();
		cc = data->remaining();
	}


	if (mode == echo) {
		p = data->bytes();
		if (ssap().STypedDataRequest(cc, p) == NOTOK)
			ss_adios(Literal::S_TYPED_DATA_REQUEST);
	}
	return DONE; 
}
ReturnCode SSAPEchoServer::SUExceptionReportIndication(int reason, int cc, const void* data) {
	if (requirements.has(DATA_UNIT_EXISTS)) {
		if (ssap().STokenGiveRequest(DATA_TOKEN) == NOTOK)
			return ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
		else
			owned &= ~DATA_TOKEN;
		ssap().logger()->info("cleared");
	} else

	if (ssap().SUAbortRequest() == NOTOK)
		return ss_adios(Literal::S_U_ABORT_REQUEST);
	else
		adios(nullptr, "aborted");

	return DONE; 
}
ReturnCode SSAPEchoServer::SPExceptionReportIndication(int reason) {
	if (requirements.has(DATA_UNIT_EXISTS)) {
		if (ssap().STokenGiveRequest(DATA_TOKEN) == NOTOK)
			return ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
		else
			owned &= ~DATA_TOKEN;
		ssap().logger()->info("cleared");
	} else if (ssap().SUAbortRequest() == NOTOK)
		return ss_adios(Literal::S_U_ABORT_REQUEST);
	else
		adios(nullptr, "aborted");

	return DONE; 
}
ReturnCode SSAPEchoServer::SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) { 
#ifdef ISODE
#define	dotoken(requires,shift,bit,type) \
{ \
	    if (requirements.has(requires)) \
		switch (settings & (CHOICE_MASK << shift)) { \
		    case CALLED_VALUE << shift: \
			settings &= ~(CHOICE_MASK << shift); \
			settings |= RESPONDER_VALUE << shift; \
		    case RESPONDER_VALUE << shift: \
			owned.add(bit); \
			break; \
 \
		    case INITIATOR_VALUE << shift: \
			owned.rem(bit); \
			break; \
 \
		    default: \
			return adios (nullptr, format("%s token: reserved", type)); \
			break; \
		} \
}
		dotokens ();
#undef	dotoken

#else
	if (requirements.has(RELEASE_UNIT_EXISTS)) {
		switch (selectReleaseToken(settings)) {
		case RELEASE_TOKEN_AS_CALLED_CHOICE:
			settings = clearReleaseToken(settings);
			settings = addResponderRelease(settings);
		case RELEASE_TOKEN_FOR_RESPONDER:
			owned = addReleaseToken(owned);
			break;

		case RELEASE_TOKEN_FOR_INITIATOR:
			owned = remReleaseToken(owned);
			break;

		default:
			adios(nullptr, "release token: reserved");
			break;
		}
	}

	if (requirements.has(MAJOR_UNIT_EXISTS)) {
		switch (selectMajorToken(settings)) {
		case MAJOR_TOKEN_AS_CALLED_CHOICE:
			settings = clearMajorToken(settings);
			settings = addResponderMajor(settings);
		case MAJOR_TOKEN_FOR_RESPONDER:
			owned = addMajorToken(owned);
			break;

		case MAJOR_TOKEN_FOR_INITIATOR:
			owned = remMajorToken(owned);
			break;

		default:
			adios(nullptr, "majorsync token: reserved");
			break;
		}
	}

	if (requirements.has(MINOR_UNIT_EXISTS)) {
		switch (selectMinorToken(settings)) {
		case CALLED_VALUE << MINOR_SHIFT:
			settings = clearMinorToken(settings);
			settings = addResponderMinor(settings);
		case RESPONDER_VALUE << MINOR_SHIFT:
			owned = addMinorToken(owned);
			break;

		case INITIATOR_VALUE << MINOR_SHIFT:
			owned = remMinorToken(owned);
			break;

		default:
			adios(nullptr, "minorsync token: reserved");
			break;
		}
	}

	if (requirements.has(DATA_UNIT_EXISTS)) {
		switch (selectDataToken(settings)) {
		case CALLED_VALUE << DATA_SHIFT:
			settings = clearDataToken(settings);
			settings = addResponderData(settings);
		case RESPONDER_VALUE << DATA_SHIFT:
			owned = addDataToken(owned);
			break;

		case INITIATOR_VALUE << DATA_SHIFT:
			owned = remDataToken(owned);
			break;

		default:
			adios(nullptr, "data token: reserved");
			break;
		}
	}
#endif // ISODE

	SSN firstAbandonSSN;
	SSN secondAbandonSSN;
	if (ssap().SResynchronizeRequest(ABANDON, firstAbandonSSN, ABANDON, secondAbandonSSN, settings, mode == echo ? cc : 0, mode == echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_RESYNCHRONIZE_REQUEST);

	return DONE; 
}
ReturnCode SSAPEchoServer::SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) {
	// nothing to do
	return DONE; 
}
ReturnCode SSAPEchoServer::SSyncMajorIndication(const SSN& ssn, int cc, const void* data) {
	if (ssap().SSyncMajorResponse(cc, mode == echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_SYNC_MAJOR_RESPONSE);

	return DONE; 
}
ReturnCode SSAPEchoServer::SSyncMajorConfirmation( int cc, const void* data) {
	adios(nullptr, "got majorsync confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SSyncMajorConfirmation(const SSN& secondSSN, int cc, const void* data) {
	adios(nullptr, "got majorsync confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc, const void* data) {
	if (type == SyncOption::CONFIRM) {
		if (ssap().SSyncMinorResponse(firstSSN, 0, mode == echo ? data : nullptr) == NOTOK)
			return ss_adios(Literal::S_SYNC_MINOR_RESPONSE);
	}
	return DONE; 
}
ReturnCode SSAPEchoServer::SSyncMinorConfirmation(const SSN& firstSSN, int cc, const void* data) {
	adios(nullptr, "got minorsync confirmation");
	return DONE; 
}
ReturnCode SSAPEchoServer::SControlGiveIndication(int tokens, int cc, const void* data) {
	owned = tokens;
	if ((tokens & DATA_TOKEN) && hx && hx->remaining() > 0) {
		char* p;
		p = hx->data();
		if (ssap().SDataRequest(hx->remaining(), p) == NOTOK)
			ss_adios(Literal::S_DATA_REQUEST);
		hx = nullptr;
	}

	if (ssap().STokenGiveRequest(tokens, cc, data) == NOTOK)
		return ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
	else
		owned &= ~tokens;

	return DONE; 
}
ReturnCode SSAPEchoServer::STokenGiveIndication(int tokens, int cc, const void* data) {
	owned = tokens;
	if ((tokens & DATA_TOKEN) && hx && hx->remaining() > 0) {
		char* p;
		p = hx->data();
		if (ssap().SDataRequest(hx->remaining(), p) == NOTOK)
			ss_adios(Literal::S_DATA_REQUEST);
		hx = nullptr;
	}

	return DONE; 
}
ReturnCode SSAPEchoServer::STokenPleaseIndication(int tokens, int cc, const void* data) {
	if ((tokens & DATA_TOKEN) && hx && hx->remaining() > 0) {
		char* p;
		p = hx->data();
		if (ssap().SDataRequest(hx->remaining(),p) == NOTOK)
			ss_adios(Literal::S_DATA_REQUEST);
		hx = nullptr;
	}

	if (ssap().STokenGiveRequest(tokens, cc, data) == NOTOK)
		return ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
	else
		owned &= ~tokens;

	return DONE; 
}
ReturnCode SSAPEchoServer::SReleaseIndication(int cc, const void* data) {
	if (ssap().SReleaseResponse(AbortCode::SC_ACCEPT, 0, mode == Mode::echo ? data : nullptr) == NOTOK)
		return ss_adios(Literal::S_RELEASE_RESPONSE);

	return DONE; 
}
ReturnCode SSAPEchoServer::SReleaseConfirmation(bool affirmative, int cc, const void* data) { 
	return DONE; 
}
ReturnCode SSAPEchoServer::adios(const char* what, const string& message)  {
	ssap().SReleaseRequest(0);
	return NOTOK;
}
ReturnCode SSAPEchoServer::adios(const char* what, const char* message)  {
	ssap().SReleaseRequest(0);
	return NOTOK;
}
ReturnCode SSAPEchoServer::ss_adios(const string& message)  {
	ssap().SReleaseRequest(0);
	return NOTOK;
}

}
}
