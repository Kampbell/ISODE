/*
 * DisconnectRequest.h
 *
 *  Created on: 21 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_SERV_DISCONNECT_REQUEST_H_
#define ALS_TSAP_SERV_DISCONNECT_REQUEST_H_
#include "als/base/serv/Request.h"

namespace ALS {
namespace TSAP {
namespace SERV {

class DisconnectRequest : public virtual ALS::BASE::SERV::Request {
public:
	/**
	 * T-DISCONNECT.REQUEST.
	 * @param reason TODO
	 * @param data the data
	 * @param responding TODO
	 *
	 * @return the return code
	 */
	virtual ReturnCode TDisconnectRequest(int reason, const TSAPAddr& responding, int cc = 0, const byte* data = nullptr )  = 0;

protected:
	DisconnectRequest() {}
private:
	DisconnectRequest(const DisconnectRequest&){}
	DisconnectRequest& operator = (const DisconnectRequest&) { return *this; };
};

}
}
}

#endif
