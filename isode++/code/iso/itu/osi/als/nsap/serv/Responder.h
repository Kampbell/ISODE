/*
 * Responder.h
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_RESPONDER_H_
#define ALS_NSAP_SERV_RESPONDER_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/nsap/nsap.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/serv/DataRequest.h"
#include "als/nsap/serv/DisconnectRequest.h"
#include "als/nsap/serv/ResetRequest.h"
#include "als/nsap/serv/ResetResponse.h"

namespace ALS {
	namespace NSAP {
		class QualityOfService;
		class QualityOfServiceParameters;
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
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;

namespace ALS {
namespace NSAP {
namespace SERV {

class Responder : 
	public virtual DataRequest,
	public virtual DisconnectRequest,
	public virtual ResetRequest,
	public virtual ResetResponse,
	public virtual Response {
public:
	virtual ~Responder() {}
	/**
	* N-CONNECT.RESPONSE.
	*
	* @param cc the tpkt length
	* @param data the tpkt 
	*
	* @return the return code
	*/
	virtual ReturnCode NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr) = 0;
};

}
}
}

#endif
