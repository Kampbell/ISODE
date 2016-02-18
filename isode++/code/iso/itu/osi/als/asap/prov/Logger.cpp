/*
 * Logger.cpp
 *
 *  Created on: 18 déc. 2014
 *      Author: FrancisANDRE
 */

#include "als/asap/prov/Logger.h"
#include "als/asap/Literal.h"
using namespace ALS::ASAP;

static const string AAssociateRequest(Literal::A_ASSOCIATE_REQUEST);
static const string AAssociateIndication(Literal::A_ASSOCIATE_INDICATION);
static const string AAssociateResponse(Literal::A_ASSOCIATE_RESPONSE);
static const string AAssociateConfirmation(Literal::A_ASSOCIATE_CONFIRMATION);
static const string AReleaseRequest(Literal::A_RELEASE_REQUEST);
static const string AReleaseIndication(Literal::A_RELEASE_INDICATION);
static const string AReleaseResponse(Literal::A_RELEASE_RESPONSE);
static const string AReleaseConfirmation(Literal::A_RELEASE_CONFIRMATION);
static const string AAbortRequest(Literal::A_ABORT_REQUEST);
static const string AAbortIndication(Literal::A_ABORT_INDICATION);
static const string APAbortIndication(Literal::A_P_ABORT_INDICATION);

namespace ALS {
namespace ASAP {

namespace PROV {
ReturnCode Logger::AAssociateRequest(
	const Mode_selector&								mode,
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
	const Authentication_value& 						authentification,
	const Implementation_data& 							implementation,
	const PresentationAddress&							callingPresentationAddress,
	const PresentationAddress& 							calledPresentationAddress,
	const Presentation_context_definition_list&			presentationContexts,
	const Default_context_name& 						defaultContext,
	const Presentation_requirements& 					presentationRequirements,
	const User_session_requirements& 					sessionRrequirements,
	const SSN& 											isn,
	byte 												settings,
	const Reference& 									reference,
	const QualityOfService&				 				qualityOfService,
	const Association_information* 						userInformation) {
	Mode_selector::mode_value mode_value = mode.get_mode_value();
	if (mode_value == x410_1984_mode)
		;
	else if (mode_value == normal_mode)
		;
	information(prefix, REQUEST, ::AAssociateRequest);
	return OK;
}
ReturnCode Logger::AAssociateIndication(
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
	const Presentation_requirements& 					presentationRequirements,
	const User_session_requirements&					sessionRrequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference,
	const QualityOfService&								qualityOfService,
	const Association_information* 						userInformation) {
	information(prefix, INDICATION, ::AAssociateIndication);
	return DONE;
}
ReturnCode Logger::AAssociateResponse(
	const Associate_result&								result,
	const Associate_source_diagnostic&					diagnostic,
	const Application_context_name&						applicationContext,
	const Application_context_name_list&				applicationContexts,
	const AP_title&										respondingAPtitle,
	const AE_qualifier&									respondingAEqualifier,
	const AP_invocation_identifier&						respondingAPInvocationIdentifier,
	const AE_invocation_identifier&						respondingAEInvocationIdentifier,
	const ACSE_requirements&							sendACSERequirements,
	const Mechanism_name&								mechanism,
	const Authentication_value&							authentification,
	const PresentationAddress&							respondingPresentationAddress,
	const Presentation_context_definition_result_list&	presentationContextResults,
	int													defaultContextResult,
	const QualityOfService&								qualityOfService,
	const Presentation_requirements&					presentationRequirements,
	const User_session_requirements&					sessionRrequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference,
	const Association_information*						userInformation) {
	information(prefix, RESPONSE, ::AAssociateResponse);
	return OK;
}
ReturnCode Logger::AAssociateConfirmation(
	const Associate_result&								result,
	const Associate_source_diagnostic&					diagnostic,
	const Application_context_name&						applicationContext,
	const Application_context_name_list&				applicationContexts,
	const AP_title&										respondingAPtitle,
	const AE_qualifier&									respondingAEqualifier,
	const AP_invocation_identifier&						respondingAPInvocationIdentifier,
	const AE_invocation_identifier&						respondingAEInvocationIdentifier,
	const ACSE_requirements&							sendACSERequirements,
	const Mechanism_name&								mechanism,
	const Authentication_value&							authentification,
	const PresentationAddress&							respondingPresentationAddress,
	const Presentation_context_definition_result_list&	presentationResults,
	int													defaultContextResult,
	const QualityOfService&								qualityOfService,
	const Presentation_requirements&					presentationRequirements,
	const User_session_requirements&					sessionRrequirements,
	const SSN&											isn,
	int													settings,
	const Reference&									reference,
	const Association_information*						userInformation) {
	information(prefix, CONFIRMATION, ::AAssociateConfirmation);
	return DONE;
}
ReturnCode Logger::AReleaseRequest(
	const Release_request_reason&						requestReason,
	const Association_information*						userInformation) {
	information(prefix, REQUEST, ::AReleaseRequest);
	return OK;
}
ReturnCode Logger::AReleaseIndication(
	const Release_request_reason&						requestReason,
	const Association_information*						userInformation) {
	information(prefix, INDICATION, ::AReleaseIndication);
	return DONE;
}
ReturnCode Logger::AReleaseResponse(
	bool												result,
	const Release_response_reason&						responseReason,
	const Association_information*						userInformation) {
	information(prefix, RESPONSE, ::AReleaseResponse);
	return OK;
}
ReturnCode Logger::AReleaseConfirmation(
	bool												affirmative,
	const Release_response_reason&						responseReason,
	const Association_information*						userInformation) {
	return DONE;
	information(prefix, CONFIRMATION, ::AReleaseConfirmation);
}
ReturnCode Logger::AAbortRequest(
	const ABRT_diagnostic&								diagnostic,
	const Association_information*						userInformation) {
	information(prefix, REQUEST, ::AAbortRequest);
	return OK;
}
ReturnCode Logger::AAbortIndication(
	const ABRT_source&									source, 
	const ABRT_diagnostic&								diagnostic, 
	const Association_information*						userInformation) {
	information(prefix, INDICATION, ::AAbortIndication);
	return DONE;
}
ReturnCode Logger::APAbortIndication(
	int													reason,
	int													extension,
	const Association_information*						userInformation) {
	information(prefix, INDICATION, ::APAbortIndication);
	return DONE;
}


}
}
}
