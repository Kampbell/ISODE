/*
 * Responder.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_SERV_RESPONDER_H_
#define ALS_TSAP_SERV_RESPONDER_H_

#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/nsap/addr/TSAPAddr.h"
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::QualityOfService;

#include "als/tsap/serv/DataRequest.h"
#include "als/tsap/serv/DisconnectRequest.h"
#include "als/nsap/QualityOfService.h"


namespace ALS { namespace TSAP { namespace SERV {

class Responder :  
	public virtual DataRequest,
	public virtual DisconnectRequest,
	public virtual Response   {
public:
	/**
	 * T-CONNECT-RESPONSE.
	 * @param qualityOfService the qualityOfService
	 * @param respondingAddr the responding
	 * @param expedited the expedited
	 * @param cc the data length
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode TConnectResponse(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr)  = 0;

protected:
	Responder() {}
private:
	Responder(const Responder&){}
	Responder& operator = (const Responder&) { return *this; };

};

}}}

#endif
