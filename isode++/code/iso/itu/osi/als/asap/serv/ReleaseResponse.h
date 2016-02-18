/*
 * ReleaseResponse.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_SERV_RELEASE_RESPONSE_H_
#define ALS_ASAP_SERV_RELEASE_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;
#include "als/asap/asap.h"

namespace ALS {
namespace ASAP {
namespace SERV {

class ReleaseResponse : public virtual Response {
public:
	/**
	 * A-RELEASE-RESPONSE.
	 *
	 * @param aca the abort info from provider if any
	 * @param userInformation the user information
	 * @param result the result
	 * @param responseReason the response reason
	 *
	 * @return the return code
	 */
	virtual ReturnCode AReleaseResponse(bool result, const Release_response_reason& responseReason, const Association_information* userInformation = nullptr) = 0;
};

}
}
}

#endif
