/*
 * ReleaseRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_RELEASEREQUEST_H_
#define ALS_SSAP_SERV_RELEASEREQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace SSAP {
namespace SERV {

class ReleaseRequest : public virtual Request {
public:
	virtual ~ReleaseRequest() {}
	/**
	 * S-RELEASE.REQUEST.
	 *
	 * @param data the data from peer
	 * @param secs the seconds before timing out
	 *
	 * @return the return code
	 */
	virtual ReturnCode SReleaseRequest(int secs, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
