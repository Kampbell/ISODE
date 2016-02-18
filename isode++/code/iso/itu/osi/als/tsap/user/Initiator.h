/*
 * Initiator.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_INITIATOR_H_
#define ALS_TSAP_USER_INITIATOR_H_

#include "als/base/util/NetworkBuffer.h"
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/nsap/addr/TSAPAddr.h"
#include "als/nsap/QualityOfService.h"
#include "als/tsap/user/DataIndication.h"
#include "als/tsap/user/DisconnectIndication.h"

using ALS::BASE::UTIL::NetworkBuffer;
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::QualityOfService;

namespace ALS { namespace TSAP { namespace USER  {

class Initiator : 
	public virtual DataIndication,
	public virtual DisconnectIndication,
	public virtual Confirmation {
public:
	/**
	 * T-CONNECT.CONFIRMATION.
	 * @param tsdusize the confirmed tsdusize
	 * @param qualityOfService the confirmed suality of service
	 * @param responding the responding address
	 * @param expedited true if expedited is supported
	 * @param userData user data
	 * @return the return code
	 */
	virtual ReturnCode TConnectConfirmation(const TSAPAddr& responding, bool expedited, const QualityOfService& qualityOfService, int tsdusize, NetworkBuffer* data = nullptr) = 0;

protected:
	Initiator() {}
private:
	Initiator(const DataIndication&){}
	Initiator& operator = (const DataIndication&);
};

}}
}

#endif
