/*
 * TokenRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_TOKENREQUEST_H_
#define ALS_SSAP_SERV_TOKENREQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace SSAP {
namespace SERV {

class TokenRequest : public virtual Request {
public:
	virtual ~TokenRequest() {}
	/**
	 * S-CONTROL-GIVE.REQUEST.
	 *
	 * @return the return code
	 *
	 * @throws TSAPException the TSAP exception
	 */
	virtual ReturnCode SControlGiveRequest() = 0;

	/**
	 * S-TOKEN-GIVE.REQUEST.
	 *
	 * @param tokens the tokens given
	 * @param datas TODO
	 * @return the return code
	 */
	virtual ReturnCode STokenGiveRequest(int tokens, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-TOKEN-PLEASE.REQUEST.
	 *
	 * @param tokens the tokens requested
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode STokenPleaseRequest(int tokens, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
