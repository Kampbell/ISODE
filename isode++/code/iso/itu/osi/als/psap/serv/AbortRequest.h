/*
 * AbortRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_ABORT_REQUEST_H_
#define ALS_PSAP_SERV_ABORT_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class AbortRequest : public virtual Request {
public:
	virtual ReturnCode PUAbortRequest(const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
