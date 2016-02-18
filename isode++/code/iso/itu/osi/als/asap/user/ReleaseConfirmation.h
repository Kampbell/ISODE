/*
 * ReleaseConfirmation.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_USER_RELEASE_CONFIRMATION_H_
#define ALS_ASAP_USER_RELEASE_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;
#include "als/asap/asap.h"

namespace ALS {
namespace ASAP {
namespace USER {

class ReleaseConfirmation : public virtual Confirmation {
public:
	/**
	 * A-RELEASE.CONFIRMATION.
	 *
	 * @param affirmative true = connection released, false = release request refused
	 * @param responseReason the release response reason
	 * @param userInformation release information from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode AReleaseConfirmation(bool affirmative, const Release_response_reason& responseReason, const Association_information* userInformation = nullptr) = 0;

};

}
}
}

#endif
