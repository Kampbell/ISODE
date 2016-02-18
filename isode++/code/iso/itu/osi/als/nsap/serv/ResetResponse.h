/*
 * ResetResponse.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_RESET_RESPONSE_H_
#define ALS_NSAP_SERV_RESET_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

namespace ALS {
namespace NSAP {
namespace SERV {

class ResetResponse : public virtual Response {
public:
	virtual ReturnCode NResetResponse() = 0;
};

}
}
}

#endif
