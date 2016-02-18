/*
 * Initiator.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_SERV_INITIATOR_H_
#define ALS_TSAP_SERV_INITIATOR_H_

#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/tsap/serv/Service.h"
#include "als/nsap/addr/TSAPAddr.h"
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::QualityOfService;

#include "als/tsap/serv/DataRequest.h"
#include "als/tsap/serv/DisconnectRequest.h"

namespace ALS {
namespace TSAP {
namespace SERV {

class Initiator : 
	public virtual DataRequest,
	public virtual DisconnectRequest,
	public virtual Request  {
public:
	virtual ~Initiator() {}
	/**
	 * T-CONNECT.REQUEST.
	 * 
	 * @param callingAddr the calling
	 * @param calledAddr the called
	 * @param expedited the expedited
	 * @param qualityOfService the qualityOfService
	 * @param cc the data character count
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode TConnectRequest(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr) = 0;

protected:
	Initiator() {}
private:
	Initiator(const Initiator&){}
	Initiator& operator = (const Initiator&) { return *this; };
};

}}
}

#endif
