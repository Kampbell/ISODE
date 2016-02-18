/*
 * ReleaseResponse.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_RELEASERESPONSE_H_
#define ALS_SSAP_SERV_RELEASERESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

namespace ALS {
namespace SSAP {
namespace SERV {

class ReleaseResponse : public virtual Response {
public:
	virtual ~ReleaseResponse() {}
	/**
	 * S-RELEASE.RESPONSE.
	 *
	 * @param status the status
	 * @param data the data from peer
	 *
	 * @return the return code
	 *
	 * @throws TSAPException the TSAP exception
	 */
	virtual ReturnCode SReleaseResponse(bool accept, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
