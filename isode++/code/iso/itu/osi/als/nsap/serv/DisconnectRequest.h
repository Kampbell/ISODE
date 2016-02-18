/*
 * DisconnectRequest.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_DISCONNECT_REQUEST_H_
#define ALS_NSAP_SERV_DISCONNECT_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
	namespace NSAP {
		namespace ADDR {
			class NSAPAddr;
		}
	}
	namespace BASE {
		namespace UTIL {
			class NetworkBuffer;
		}
	}
}
using ALS::BASE::UTIL::NetworkBuffer;
using ALS::NSAP::ADDR::NSAPAddr;

namespace ALS {
namespace NSAP {
namespace SERV {

class DisconnectRequest : public virtual Request {
public:
	virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc = 0, const byte* buffer = nullptr) = 0;
};

}
}
}

#endif
