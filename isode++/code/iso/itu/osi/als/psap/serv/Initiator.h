/*
 * Initiator.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_INITIATOR_H_
#define ALS_PSAP_SERV_INITIATOR_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;
#include "als/psap/psap.h"

#include "als/nsap/addr/PSAPAddr.h"
using ALS::NSAP::ADDR::PSAPAddr;
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;


namespace ALS {
namespace SSAP {
	class Reference;
	class SSN;
}
}
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;


namespace ALS {
namespace PSAP {
namespace SERV {

class Initiator : public virtual Request {
public:
	/**
	 * P-CONNECT.REQUEST.
	 * 
	 * @param callingAddr the calling PSAP addr
	 * @param calledAddr the called PSAP addr
	 * @param presentationContexts the presentation contexts
	 * @param defaultContext the default context
	 * @param prequirements the presentation requirements
	 * @param mode the selector mode: X410 or NORMAL
	 * @param srequirements the session requirements
	 * @param isn the initial serial number
	 * @param settings the proposed settings
	 * @param reference the session connection identifier
	 * @param userData the datas from peer
	 * @param qualityOfService the quality of service
	 * 
	 * @return the return code
	 * 
	 */
	virtual ReturnCode PConnectRequest(
		const PresentationAddress&					callingAddr,
		const PresentationAddress&					calledAddr,
		const Presentation_context_definition_list& presentationContexts,
		const Default_context_name&					defaultContext,
		const Presentation_requirements&			presentationRequirements,
		const Mode_selector&						mode,
		const User_session_requirements&			sessionRequirements,
		const SSN&									isn,
		int											settings,
		const Reference&							reference,
		const QualityOfService&						qualityOfService,
		const User_data*							userData = nullptr) = 0;

};

}
}
}

#endif
