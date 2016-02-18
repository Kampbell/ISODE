/*
 * ReleaseConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_RELEASE_CONFIRMATION_H_
#define ALS_SSAP_USER_RELEASE_CONFIRMATION_H_
#include <memory>
using std::shared_ptr;

#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;
#include "als/base/util/NetworkBuffer.h"

using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
namespace SSAP {
namespace USER {

class ReleaseConfirmation : public virtual Confirmation {
public:
	/**
	 * S-RELEASE.CONFIRMATION.
	 *
	 * @param affirmative true = connection released, false = release request refused
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual  ReturnCode SReleaseConfirmation(bool affirmative, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
