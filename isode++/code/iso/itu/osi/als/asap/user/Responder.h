/*
 * Responder.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_USER_RESPONDER_H_
#define ALS_ASAP_USER_RESPONDER_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
#include "als/asap/asap.h"
#include "als/asap/user/AbortIndication.h"
#include "als/asap/user/ReleaseIndication.h"
#include "als/asap/user/ReleaseConfirmation.h"

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
namespace USER {

class Responder : 
	public virtual AbortIndication,
	public virtual ReleaseIndication,
	public virtual ReleaseConfirmation,
	public virtual Indication {
public:
	/**
	 * A-ASSOCIATE.INDICATION.
	 *
	 * @param application the application context
	 * @param applications the application contexts list
	 * @param callingAEI the calling AEI
	 * @param calledAEI the called AEI
	 * @param senderACSERequirements the sender ACSE requirements
	 * @param mechanism the authentification mechanism
	 * @param authentification the authentification
	 * @param implementation the implementation specific datas
	 * @param userInformation the user data
	 * @param callingAddr the calling PSAP Addr
	 * @param calledAddr the called PSAP Addr
	 * @param presentationContexts the presentation contexts
	 * @param presentationContextResults the presentation contexts's results
	 * @param defaultContext the default context
	 * @param defaultContextResult the default context's result
	 * @param prequirements the presentation requirements
	 * @param srequirements the user session requirements
	 * @param isn the initial serialization number
	 * @param settings the proposed tokens settings
	 * @param reference the session connection identifier
	 * @param qualityOfService the qualityOfService
	 *
	 * @return the return code
	 */
	virtual ReturnCode AAssociateIndication(
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
		const PresentationAddress& 							callingAPresentationAddress,
		const PresentationAddress& 							calledPresentationAddress,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		const Default_context_name& 						defaultContext,
		int 												defaultContextResult,
		const Presentation_requirements& 					presentationRequirements,
		const User_session_requirements& 					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const QualityOfService&								qualityOfService,
		const Association_information* 						userInformation = nullptr) = 0;

};

}
}
}

#endif
