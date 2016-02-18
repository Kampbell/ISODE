/*
 * AbortRequest.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_SERV_ABORT_REQUEST_H_
#define ALS_ASAP_SERV_ABORT_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;
#include "als/asap/asap.h"

namespace ALS {
namespace ASAP {
namespace SERV {

class AbortRequest : public virtual Request {
public:
	/**
	 * A-ABORT.REQUEST.
	 * @param diagnostic the diagnostic of the abort
	 * @param userInformation the user information
	 * @return the return code
	 */
	virtual ReturnCode AAbortRequest(const ABRT_diagnostic& diagnostic, const Association_information* userInformation = nullptr) = 0;
};

}
}
}

#endif
