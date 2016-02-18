/*
 * DataConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_DATA_CONFIRMATION_H_
#define ALS_SSAP_USER_DATA_CONFIRMATION_H_
#include <memory>
using std::shared_ptr;

#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;
#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
namespace SSAP {
namespace USER {

class DataConfirmation : public virtual Confirmation {
public:
	/**
	 * S-CAPABILITY-DATA.CONFIRMATION.
	 *
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SCapabilityDataConfirmation(const SharedNetworkBuffer& data) = 0;
};

}
}
}

#endif
