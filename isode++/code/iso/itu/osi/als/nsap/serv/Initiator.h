/*
 * Initiator.h
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_SERV_INITIATOR_H_
#define ALS_NSAP_SERV_INITIATOR_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/serv/DataRequest.h"
#include "als/nsap/serv/DisconnectRequest.h"
#include "als/nsap/serv/ResetRequest.h"
#include "als/nsap/serv/ResetResponse.h"

using ALS::NSAP::ADDR::NSAPAddr;
namespace ALS {
	namespace NSAP {
		class QualityOfService;
		class QualityOfServiceParameters;
	}
}
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;

namespace ALS {
namespace NSAP {
namespace SERV {
class Initiator : 
	public virtual DataRequest,
	public virtual DisconnectRequest,
	public virtual ResetRequest,
	public virtual ResetResponse,
	public virtual Request {
public:
	virtual ~Initiator() {}
	/**
	* N-CONNECT-REQUEST.
	* @param calling the local calling NSAP address
	* @param called the remote called  NSAP address
	* @return the return code
	*/
	 virtual ReturnCode NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr) = 0;
};

}
}
}

#endif
