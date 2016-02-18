/*
 * Initiator.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_SERV_INITIATOR_H_
#define ALS_ASAP_SERV_INITIATOR_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/asap/asap.h"
#include "als/asap/serv/AbortRequest.h"
#include "als/asap/serv/ReleaseRequest.h"
#include "als/asap/serv/ReleaseResponse.h"

#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;

namespace ALS {
namespace SSAP {
	class ActivityId;
	class Reference;
	class SSN;
}
}
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace ASAP {
namespace SERV {

class Initiator : 
	public virtual AbortRequest,
	public virtual ReleaseRequest,
	public virtual ReleaseResponse,
	public virtual Request {
public:
	/**
	 * A-ASSOCIATE.REQUEST.
	 *
	 * @param applicationContext the application context
	 * @param applicationContexts the application contexts list
	 * @param callingAEI the calling AEI
	 * @param calledAEI the called AEI
	 * @param senderACSERequirements the selected ACSE functional unit
	 * @param mechanism the authentification mechanism
	 * @param authentification the authentification value
	 * @param implementation the specific implementation data
	 * @param userInformation the user's datas
	 * @param callingAddr the calling presentation address
	 * @param calledAddr the called presentation address
	 * @param presentationContexts the contexts
	 * @param defaultContext the default context
	 * @param prequirements the presentation requirements
	 * @param srequirements the user's session requirements
	 * @param isn the initial synchronization serial number
	 * @param settings the initial assignment of tokens
	 * @param reference the session connection identifier
	 * @param qualityOfService the quality of service
	 * @return the return code
	 */
	/*
Mode
Application Context Name
Calling AP Title
Calling AE Qualifier
Calling AP Invocation-identifier
Calling AE Invocation-identifier
Called AP Title
Called AE Qualifier
Called AP Invocation-identifier
Called AE Invocation-identifier
Responding AP Title
Responding AE Qualifier
Responding AP Invocation-identifier
Responding AE Invocation-identifier
User Information
Result
Result Source
Diagnostic
Calling Presentation Address
Called Presentation Address
Responding Presentation Address
Presentation Context Definition List
Presentation Context Definition Result List
Default Presentation Context Name
Default Presentation Context Result
Quality of Service
Session Requirements
Initial Synchronization Point Serial Number
Initial Assignment of Tokens
Session-connection Identifier
*/
	virtual ReturnCode AAssociateRequest(
		const Mode_selector&						mode,
		const Application_context_name& 			applicationContext,
		const Application_context_name_list& 		applicationContexts,
		const AP_title&								callingAPtitle,
		const AE_qualifier&							callingAEqualifier,
		const AP_invocation_identifier&				callingAPInvocationIdentifier,
		const AE_invocation_identifier&				callingAEInvocationIdentifier,
		const AP_title&								calledAPtitle,
		const AE_qualifier&							calledAEqualifier,
		const AP_invocation_identifier&				calledAPInvocationIdentifier,
		const AE_invocation_identifier&				calledAEInvocationIdentifier,
		const ACSE_requirements& 					senderACSERequirements,
		const Mechanism_name& 						mechanism,
		const Authentication_value& 				authentification,
		const Implementation_data& 					implementation,
		const PresentationAddress&					callingPresentationAddress,
		const PresentationAddress& 					calledPresentationAddress,
		const Presentation_context_definition_list& presentationContexts,
		const Default_context_name& 				defaultContext,
		const Presentation_requirements& 			presentationRequirements,
		const User_session_requirements& 			sessionRequirements,
		const SSN& 									isn,
		byte 										settings,
		const Reference& 							reference,
		const QualityOfService&				 		qualityOfService,
		const Association_information* 				userInformation = nullptr) = 0;
};

}
}
}

#endif
