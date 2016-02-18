/*
 * EchoServer.h
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ASAP_ECHO_SERVER_H_
#define ASAP_ECHO_SERVER_H_
#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ASAP_ECHO_SERVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ASAP_ECHO_SERVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(ASAP_ECHO_SERVER_EXPORTS)
		#define ASAP_ECHO_SERVER_API __declspec(dllexport)
	#else
		#define ASAP_ECHO_SERVER_API __declspec(dllimport)
	#endif
#endif


#if !defined(ASAP_ECHO_SERVER_API)
	#define ASAP_ECHO_SERVER_API
#endif

//
// Automatically link ASAP_ECHO_SERVER library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(ASAP_ECHO_SERVER_EXPORTS)
		#pragma comment(lib, "ASAPEchoServer" ALS_LIB_SUFFIX)
	#endif
#endif

#include "als/base/util/Bits.h"
using ALS::BASE::UTIL::Bits;
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;

#include "als/ssap/ActivityId.h"
using ALS::SSAP::ActivityId;
#include "als/ssap/Requirement.h"
using ALS::SSAP::Requirement;
#include "als/ssap/Token.h"
using ALS::SSAP::Token;
#include "als/ssap/SSN.h"
using ALS::SSAP::SSN;

#include "als/psap/user/Linker.h"
#include "als/psap/user/ActivityIndication.h"
#include "als/psap/user/ActivityConfirmation.h"
#include "als/psap/user/ContextIndication.h"
#include "als/psap/user/ContextConfirmation.h"
#include "als/psap/user/DataIndication.h"
#include "als/psap/user/DataConfirmation.h"
#include "als/psap/user/ReportIndication.h"
#include "als/psap/user/SynchronizeIndication.h"
#include "als/psap/user/SynchronizeConfirmation.h"
#include "als/psap/user/TokenIndication.h"
#include "als/psap/serv/Responder.h"
#include "als/psap/user/Initiator.h"
#include "als/psap/user/Responder.h"


#include "als/asap/user/Responder.h"
#include "als/asap/user/AbortIndication.h"

namespace ALS {
namespace ASAP {
enum Mode {
	echo,
	sink
};

class ASAP_ECHO_SERVER_API EchoServer : 
	public ASAP::USER::Responder,
	public PSAP::USER::Linker,
	public PSAP::USER::ActivityIndication,
	public PSAP::USER::ActivityConfirmation,
	public PSAP::USER::ContextIndication,
	public PSAP::USER::ContextConfirmation,
	public PSAP::USER::DataIndication,
	public PSAP::USER::DataConfirmation,
	public PSAP::USER::ReportIndication,
	public PSAP::USER::SynchronizeIndication,
	public PSAP::USER::SynchronizeConfirmation,
	public PSAP::USER::TokenIndication,
	public Token{
private:
	PSAP::SERV::Responder*	psap_serv_responder = nullptr;
#if 0
	ASAPAddr			responding;
	QualityOfService					qualityOfService;
	Requirement			srequirements;
	Bits				owned = 0;
	Bits				avail = 0;
	ActivityId			activityId;
	SharedNetworkBuffer	hx;
	Mode				mode = echo;
	SSN					firstSSN;
	SSN					secondSSN;
#endif

	inline ALS::PSAP::SERV::Responder&	psap()  { return *psap_serv_responder; }
public:
	EchoServer();
	virtual ~EchoServer();

	static EchoServer* newInstance() { return new EchoServer(); }

	PSAP::USER::Initiator*	initiator() const;
	PSAP::USER::Responder*	responder() const;
	PSAP::SERV::Responder*&	provider();

	ReturnCode AAssociateIndication(
		const Application_context_name& 					applicationContext,
		const Application_context_name_list& 				applicationContexts,
		const AP_title&										callingAPtitle,
		const AE_qualifier&									callingAEqualifier,
		const AP_invocation_identifier&						callingAPInvocationIdentifier,
		const AE_invocation_identifier&						callingAEInvocationIdentifier,
		const AP_title&										calledAPtitle,
		const AE_qualifier&									calledAEqualifier,
		const AP_invocation_identifier&						calledAPInvocationIdentifier,
		const AE_invocation_identifier&						calledAEInvocationIdentifier,
		const ACSE_requirements& 							senderACSERequirements,
		const Mechanism_name& 								mechanism,
		const Authentication_value&							authentification,
		const Implementation_data& 							implementation,
		const PresentationAddress& 							callingPresentationAddress,
		const PresentationAddress& 							calledPresentationAddress,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		const Default_context_name& 						defaultContext,
		int 												defaultContextResult,
		const Presentation_requirements& 					prequirements,
		const User_session_requirements&					srequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const QualityOfService&								qualityOfService,
		const Association_information* 						userInformation = nullptr);

	ReturnCode AAbortIndication(const ABRT_source& source, const ABRT_diagnostic& diagnostic, const Association_information* userInformation = nullptr);
	ReturnCode APAbortIndication(int reason, int extension, const Association_information* userInformation = nullptr);

	ReturnCode AReleaseConfirmation(bool affirmative, const Release_response_reason& responseReason, const Association_information* userInformation = nullptr);
	ReturnCode AReleaseIndication(const Release_request_reason& requestReason, const Association_information* userInformation = nullptr);

	ReturnCode PActivityStartIndication(const ActivityId& aid, const User_data* userData = nullptr);
	ReturnCode PActivityResumeIndication(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldReference, const User_data* userData = nullptr);
	ReturnCode PActivityInterruptIndication(int reason, const User_data* userData = nullptr);
	ReturnCode PActivityInterruptConfirmation(const User_data* userData = nullptr);
	ReturnCode PActivityDiscardIndication(int reason, const User_data* userData = nullptr);
	ReturnCode PActivityDiscardConfirmation(const User_data* userData = nullptr);
	ReturnCode PActivityEndIndication(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PActivityEndConfirmation(const SSN& secondSSN, const User_data* userData = nullptr);

	ReturnCode PAlterContextIndication(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const Presentation_context_addition_result_list& presentationAdditionResults, const User_data* userData = nullptr);
	ReturnCode PAlterContextConfirmation(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData = nullptr);
	ReturnCode PDataIndication(const User_data& userData);
	ReturnCode PExpeditedDataIndication(const User_data& userData);
	ReturnCode PTypedDataIndication(const User_data& userData);

	ReturnCode PCapabilityDataIndication(const User_data& userData);
	ReturnCode PCapabilityDataConfirmation(const User_data& userData);

	ReturnCode PPExceptionReportIndication(int reason);
	ReturnCode PUExceptionReportIndication(int reason, const User_data* userData = nullptr);

	ReturnCode PSyncMajorIndication(SSN ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMajorConfirmation(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMinorIndication(SyncOption type, const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMinorConfirmation(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PResynchronizeIndication(SyncOption type, const SSN& ssn, byte tokens, const Presentation_context_identifier_list& presentationIdentifications, const User_data* userData = nullptr);
	ReturnCode PResynchronizeConfirmation(const SSN& ssn, byte tokens, const User_data* userData = nullptr);

	ReturnCode PTokenGiveIndication(byte tokens, const User_data* userData = nullptr);
	ReturnCode PControlGiveIndication(byte tokens, const User_data* userData = nullptr);
	ReturnCode PTokenPleaseIndication(byte tokens, const User_data* userData = nullptr);

private:
	ReturnCode adios(const char* what, const char* message) ;
	ReturnCode ss_adios(const string& message) ;
	int i;
};

}
}

#endif
