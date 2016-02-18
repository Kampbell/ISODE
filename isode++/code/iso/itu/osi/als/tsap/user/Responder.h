/*
 * Responder.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_RESPONDER_H_
#define ALS_TSAP_USER_RESPONDER_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/nsap/addr/TSAPAddr.h"
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::QualityOfService;

#include "als/tsap/user/DataIndication.h"
#include "als/tsap/user/DisconnectIndication.h"

namespace ALS {
	namespace BASE {
		namespace SRVC {
			class SSAPServices;
		}
	}
}

namespace ALS { namespace TSAP { namespace USER {

class Responder :
	public virtual DataIndication,
	public virtual DisconnectIndication,
	public virtual Indication {
public:
	/**
	 * T-CONNECT.INDICATION.
	 * 
	 * @param callingAddr the calling tsap
	 * @param calledAddr the called tsap
	 * @param expedited the expedited
	 * @param tsdusize the largest atomic TSDU
	 * @param qualityOfService the quality of service
	 * @param data the initial data from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr) = 0;
	virtual ReturnCode TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices) = 0;

protected:
	Responder() {}
private:
	Responder(const Responder&){}
	Responder& operator = (const Responder&);
};

}}
}

#endif
