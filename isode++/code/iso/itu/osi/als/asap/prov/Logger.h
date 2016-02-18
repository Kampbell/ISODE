/*
 * Logger.h
 *
 *  Created on: 18 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_AcSAP_PROV_LOGGER_H_
#define ALS_AcSAP_PROV_LOGGER_H_
#include "als/asap/asap.h"

#include "als/base/root/Logger.h"
#include "als/base/util/NetworkBuffer.h"
#include "als/ssap/Reference.h"
#include "als/nsap/QualityOfService.h"
#include "als/asap/serv/Initiator.h"
#include "als/asap/serv/Responder.h"
#include "als/asap/user/Initiator.h"
#include "als/asap/user/Responder.h"

namespace ALS {
namespace ASAP {
namespace PROV {

class ASAP_API Logger :
	public ALS::BASE::ROOT::Logger,
	public SERV::Initiator, public USER::Initiator,
	public SERV::Responder, public USER::Responder {
	friend class Provider;
public:
	Logger(int level) : ALS::BASE::ROOT::Logger("ASAP") {
	}
	~Logger() {
	}
	ReturnCode AAssociateRequest(
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
		const User_session_requirements& 					sessionRequirements,
		const SSN& 											isn,
		byte 												settings,
		const Reference& 									reference,
		const QualityOfService&				 				qualityOfService,
		const Association_information* 						userInformation = nullptr
		);
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
		const Presentation_requirements& 					presentationRequirements,
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const QualityOfService&								qualityOfService,
		const Association_information* 						userInformation = nullptr
		);

	ReturnCode AAssociateResponse(
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
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const Association_information*						userInformation = nullptr);

	ReturnCode AAssociateConfirmation(
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
		const Association_information*						userInformation = nullptr);

	ReturnCode AReleaseRequest(
		const Release_request_reason&						requestReason,
		const Association_information*						userInformation = nullptr);
	ReturnCode AReleaseIndication(
		const Release_request_reason&						requestReason,
		const Association_information*						userInformation = nullptr);
	ReturnCode AReleaseResponse(
		bool												result,
		const Release_response_reason&						responseReason,
		const Association_information*						userInformation = nullptr);
	ReturnCode AReleaseConfirmation(
		bool												affirmative,
		const Release_response_reason&						responseReason,
		const Association_information*						userInformation = nullptr);

	ReturnCode AAbortRequest(
		const ABRT_diagnostic&								diagnostic,
		const Association_information*						userInformation = nullptr);
	ReturnCode AAbortIndication(
		const ABRT_source&									source, 
		const ABRT_diagnostic&								diagnostic, 
		const Association_information*						userInformation = nullptr);
	ReturnCode APAbortIndication(
		int													reason,
		int													extension,
		const Association_information*						userInformation = nullptr);
};

}
}
}

#endif
