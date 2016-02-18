/*
 * AbortRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_ABORTREQUEST_H_
#define ALS_SSAP_SERV_ABORTREQUEST_H_

#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace SSAP {
namespace SERV {

class AbortRequest : public virtual Request {
public:
	~AbortRequest() {}
	/**
	 * S-U-ABORT.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SUAbortRequest(int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
