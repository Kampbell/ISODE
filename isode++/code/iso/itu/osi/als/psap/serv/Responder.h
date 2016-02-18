/*
 * Responder.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_RESPONDER_H_
#define ALS_PSAP_SERV_RESPONDER_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

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

class Responder : public virtual Response {
public:
	/**
	 * P-CONNECT.RESPONSE.
	 * 
	 * @param status the status
	 * @param respondingAddr the responding PSAP addr
	 * @param results the presentation context result lists
	 * @param defaultContextResult the default context result
	 * @param prequirements the presentation requirements
	 * @param usrequirements the session requirements
	 * @param isn the initial serial number
	 * @param settings the accepted settings
	 * @param reference the session connection identifier
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PConnectResponse(
		int													status, 
		const PresentationAddress&							respondingAddr,
		const Presentation_context_definition_result_list&	presentationContextResults,
		int													defaultContextResult, 
		const Presentation_requirements&					presentationRequirements, 
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn, 
		byte												settings, 
		const Reference&									reference, 
		const User_data*									userData = nullptr) = 0;

};

}
}
}

#endif
