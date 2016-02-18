/*
 * ReleaseRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_RELEASE_REQUEST_H_
#define ALS_PSAP_SERV_RELEASE_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ReleaseRequest : public virtual Request {
public:
	/**
	 * P-RELEASE.REQUEST.
	 * 
	 * @param secs the secs to timeout
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PReleaseRequest(int secs, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
