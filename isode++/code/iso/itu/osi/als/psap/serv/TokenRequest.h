/*
 * TokenRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_TOKEN_REQUEST_H_
#define ALS_PSAP_SERV_TOKEN_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class TokenRequest : public virtual Request {
public:
	/**
	 * P-CONTROL-GIVE.REQUEST.
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PControlGiveRequest() = 0;

	/**
	 * P-TOKEN-GIVE.REQUEST.
	 * 
	 * @param tokens the tokens given
	 * @param userData TODO
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTokenGiveRequest(int tokens, const User_data* userData = nullptr) = 0;

	/**
	 * P-TOKEN-PLEASE.REQUEST.
	 * 
	 * @param tokens the tokens requested
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTokenPleaseRequest(int tokens, const User_data* userData = nullptr) = 0;


};

}
}
}

#endif
