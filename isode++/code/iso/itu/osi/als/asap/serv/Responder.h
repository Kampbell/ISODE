/*
 * Responder.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_SERV_RESPONDER_H_
#define ALS_ASAP_SERV_RESPONDER_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;
#include "als/asap/asap.h"
#include "als/asap/serv/AbortRequest.h"
#include "als/asap/serv/ReleaseRequest.h"
#include "als/asap/serv/ReleaseResponse.h"

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

class Responder :
	public virtual AbortRequest,
	public virtual ReleaseRequest,
	public virtual ReleaseResponse,
	public virtual Response {
public:
	/**
	 * A-ASSOCIATE-RESPONSE.
	 *
	 * @param result the status
	 * @param diagnostic the reason
	 * @param application the application context
	 * @param applications the applicationContexts
	 * @param respondingAEI the responding title
	 * @param sendACSERequirements the sender ACSE requirements
	 * @param mechanism the mechanism
	 * @param authentification the authentification
	 * @param respondingAddr the responding address
	 * @param presentationContextResults the presentation context results
	 * @param defaultContextResult the default context result
	 * @param qualityOfService the quality of service
	 * @param prequirements the presentation requirements
	 * @param srequirements the user's session requirements
	 * @param isn the initial serial number
	 * @param settings the initial token settings
	 * @param reference the reference
	 * @param userInformation the datas from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode AAssociateResponse(
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
		const Presentation_context_definition_result_list&	presentationContextResults,
		int													defaultContextResult,
		const QualityOfService&								qualityOfService,
		const Presentation_requirements& 					presentationRequirements,
		const User_session_requirements& 					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const Association_information*						userInformation = nullptr) = 0;
};

}
}
}

#endif
