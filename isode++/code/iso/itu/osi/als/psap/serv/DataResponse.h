/*
 * DataResponse.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_DATA_RESPONSE_H_
#define ALS_PSAP_SERV_DATA_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class DataResponse : public virtual Response {
public:
	/**
	 * P-CAPABILITY-DATA.RESPONSE.
	 * 
	 * @param datas the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PCapabilityDataResponse(const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
