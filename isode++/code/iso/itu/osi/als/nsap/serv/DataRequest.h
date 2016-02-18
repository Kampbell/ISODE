/*
 * DataRequest.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_DATA_REQUEST_H_
#define ALS_NSAP_SERV_DATA_REQUEST_H_
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

class DataRequest : public virtual Request {
public:
	virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation = false) = 0;
	virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation = false) = 0;
	virtual ReturnCode NDataAcknoledgeRequest() = 0;
	virtual ReturnCode NExpeditedDataRequest(int cc = 0, const byte* buffer = nullptr) = 0;
};

}
}
}

#endif
