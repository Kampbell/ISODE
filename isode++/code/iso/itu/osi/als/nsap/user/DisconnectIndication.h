/*
 * DisconnectIndication.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_DISCONNECT_INDICATION_H_
#define ALS_NSAP_USER_DISCONNECT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;


namespace ALS {
namespace NSAP {
namespace USER {

class DisconnectIndication : public virtual Indication {
public:
	virtual ReturnCode NDisconnectIndication() = 0;
};

}
}
}

#endif
