/*
 * DisconnectIndication.h
 *
 *  Created on: 21 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_DISCONNECT_INDICATION_H_
#define ALS_TSAP_USER_DISCONNECT_INDICATION_H_
#include "als/base/user/Indication.h"

namespace ALS {
namespace TSAP {
namespace USER {

class DisconnectIndication : public virtual ALS::BASE::USER::Indication {
public:
	/**
	 * T-DISCONNECT.INDICATION.
	 *
	 * @param reason the reason of the disconnection
	 * @param data data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode TDisconnectIndication(int reason, const string& data) = 0;

protected:
	DisconnectIndication() {}
private:
	DisconnectIndication(const DisconnectIndication&){}
	DisconnectIndication& operator = (const DisconnectIndication&);

};

}
}
}

#endif
