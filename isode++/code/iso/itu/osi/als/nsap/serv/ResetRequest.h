/*
 * ResetRequest.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_RESET_REQUEST_H_
#define ALS_NSAP_SERV_RESET_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace NSAP {
namespace SERV {

class ResetRequest : public virtual Request {
public:
	virtual ReturnCode NResetRequest(int reason) = 0;
};

}
}
}

#endif
