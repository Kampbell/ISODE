/*
 * ReleaseResponse.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_RELEASE_RESPONSE_H_
#define ALS_PSAP_SERV_RELEASE_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ReleaseResponse : public virtual Response {
public:
	/**
	 * P-RELEASE.RESPONSE.
	 * 
	 * @param status the status
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PReleaseResponse(int status, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
