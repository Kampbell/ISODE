/*
 * Initiator.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_INITIATOR_H_
#define ALS_PSAP_USER_INITIATOR_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

#include "als/nsap/addr/PSAPAddr.h"
using ALS::NSAP::ADDR::PSAPAddr;
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;

#include "als/psap/user/AbortIndication.h"
#include "als/psap/user/ReleaseIndication.h"
#include "als/psap/user/ReleaseConfirmation.h"

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

class Initiator :
	public virtual AbortIndication,
	public virtual ReleaseIndication,
	public virtual ReleaseConfirmation,
	public virtual Confirmation
	{
public:
	/**
	 * P-CONNECT.CONFIRMATION.
	 * 
	 * @param respondingAddr the  PSAP address of peer responding
	 * @param presentationContexts the list of proposed contexts
	 * @param presentationResults the list of negotiated contexts
	 * @param defaultContextResult the result for proposed default context name
	 * @param prequirements the presentation requirements
	 * @param srequirements the session requirements
	 * @param settings the initial settings of tokens
	 * @param isn the initial serial number
	 * @param reference the session connection identifier
	 * @param ssdusize the largest atomic SSDU
	 * @param qualityOfService the qualityOfService
	 * @param result the result
	 * @param userData the initial data from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PConnectConfirmation(
		const PresentationAddress&							respondingAddr,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		int													defaultContextResult,
		const Presentation_requirements&					presentationRequirements, 
		const User_session_requirements&					sessionRequirements,
		int													settings, 
		const SSN&											isn,
		const Reference&									reference, 
		int													ssdusize,
		const QualityOfService&											qualityOfService, 
		int													result,
		const User_data*									userData = nullptr) = 0;
};

}
}
}

#endif
