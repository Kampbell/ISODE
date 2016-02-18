/*
 * ReleaseIndication.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_USER_RELEASE_INDICATION_H_
#define ALS_ASAP_USER_RELEASE_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
#include "als/asap/asap.h"

namespace ALS {
namespace ASAP {
namespace USER {

class ReleaseIndication : public virtual Indication {
public:
	/**
	 * A-RELEASE.INDICATION.
	 *
	 * @param requestReason the release request reason
	 * @param userInformation the release information from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode AReleaseIndication(const Release_request_reason& requestReason, const Association_information* userInformation = nullptr) = 0;


};

}
}
}

#endif
