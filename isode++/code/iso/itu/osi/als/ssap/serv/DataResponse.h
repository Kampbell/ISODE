/*
 * DataResponse.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_DATARESPONSE_H_
#define ALS_SSAP_SERV_DATARESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

namespace ALS {
namespace SSAP {
namespace SERV {

	class DataResponse : public virtual Response {
public:
	DataResponse() {}
	virtual ~DataResponse() {}
	/**
	 * S-CAPABILILTY-DATA.RESPONSE.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SCapabilityDataResponse(int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
