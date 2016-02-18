/*
 * Responder.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_RESPONDER_H_
#define ALS_PSAP_USER_RESPONDER_H_
#include "als/psap/psap.h"
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

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
namespace PSAP {
namespace USER {

class Responder : 
	public virtual AbortIndication,
	public virtual ReleaseIndication,
	public virtual ReleaseConfirmation,
	public virtual Indication {
public:
	/**
	 * P-CONNECT.INDICATION.
	 * 
	 * @param callingAddr the calling PSAP addr
	 * @param calledAddr the called PSA addr
	 * @param presentationContexts the presentation contexts
	 * @param presentationResults the presentation results
	 * @param defaultContext the default context
	 * @param prequirements the presentation requirements
	 * @param mode the mode of operation: X410 or NORMAL
	 * @param srequirements the session requirements
	 * @param isn the initial serail number
	 * @param settings the proposed settings
	 * @param reference the session connection identifier
	 * @param userData the datas from peer
	 * @param qualityOfService the qualityOfService
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PConnectIndication(
		const PresentationAddress&							callingAddr,
		const PresentationAddress&							calledAddr,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		const Default_context_name&							defaultContext,
		const Presentation_requirements&					presentationRequirements,
		const Mode_selector&								mode,
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference, 
		const QualityOfService&								qualityOfService,
		const User_data*									userData = nullptr) = 0;
};

}
}
}

#endif
