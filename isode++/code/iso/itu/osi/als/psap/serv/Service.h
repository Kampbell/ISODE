/*
 * Service.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_SERVICE_H_
#define ALS_PSAP_SERV_SERVICE_H_

namespace ALS {
namespace PSAP {
namespace SERV {

class Service {
public:
	/**
	 * Ssap.
	 * 
	 * @return the SSAP services
	 */
	Services ssap();

	/**
	 * Initiator.
	 * 
	 * @return the sSAP initiator
	 */
	Initiator initiator();

	/**
	 * Responder.
	 * 
	 * @return the sSAP responder
	 */
	Responder responder();

	/**
	 * Available.
	 * 
	 * @return the int
	 */
	byte available();

	/**
	 * Owned.
	 * 
	 * @return the int
	 */
	 byte owned();

	bool isActivityInProgress();
	bool hasTurn();
};

}
}
}

#endif
