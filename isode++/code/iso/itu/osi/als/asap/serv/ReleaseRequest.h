/*
 * ReleaseRequest.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_SERV_RELEASE_REQUEST_H_
#define ALS_ASAP_SERV_RELEASE_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;
#include "als/asap/asap.h"

namespace ALS {
namespace ASAP {
namespace SERV {

class ReleaseRequest : public virtual Request {
public:
	/**
	 * A-RELEASE.REQUEST.
	 *
	 * @param aca the abort info from provider if any
	 * @param userInformation the user information
	 * @param requestReason the request reason
	 * @param secs the secs
	 *
	 * @return the return code
	 */
	virtual ReturnCode AReleaseRequest(const Release_request_reason& requestReason, const Association_information* userInformation = nullptr) = 0;
};

}
}
}

#endif
