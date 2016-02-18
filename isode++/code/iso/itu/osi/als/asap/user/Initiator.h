/*
 * Initiator.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_USER_INITIATOR_H_
#define ALS_ASAP_USER_INITIATOR_H_
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;

#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;
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

class Initiator :
	public virtual AbortIndication,
	public virtual ReleaseIndication,
	public virtual ReleaseConfirmation,
	public virtual Confirmation {
public:
	/**
	 * A-ASSOCIATE.CONFIRMATION.
	 *
	 * @param result the status
	 * @param diagnostic the reason
	 * @param application the application context
	 * @param applications the application contexts
	 * @param respondingAEI the responding title
	 * @param sendACSERequirements the send acse requirements
	 * @param mechanism the mechanism
	 * @param authentification the authentification
	 * @param respondingAddr the responding PSAP addresse
	 * @param presentationResults the presentation context results
	 * @param defaultContextResult the default context result
	 * @param qualityOfService the quality of service
	 * @param presentationRequirements the presentation requirements
	 * @param sessionRrequirements the user's session requirements
	 * @param isn the initial serial number
	 * @param settings the accepted tokens settings
	 * @param reference the session connection identifier
	 * @param userInformation the infos
	 *
	 * @return the return code
	 */
	virtual ReturnCode AAssociateConfirmation(
		const Associate_result&								result,
		const Associate_source_diagnostic&					diagnostic,
		const Application_context_name&						applicationContext,
		const Application_context_name_list&				applicationContexts,
		const AP_title&										respondingAPtitle,
		const AE_qualifier&									respondingAEqualifier,
		const AP_invocation_identifier&						respondingAPInvocationIdentifier,
		const AE_invocation_identifier&						respondingAEInvocationIdentifier,
		const ACSE_requirements&							senderACSERequirements,
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
		const Association_information*						userInformation = nullptr
		) = 0;
};

}
}
}

#endif
