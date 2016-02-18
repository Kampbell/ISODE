/*
 * ActivityConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_ACTIVITY_ICONFIRMATION_H_
#define ALS_SSAP_USER_ACTIVITY_ICONFIRMATION_H_

#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

namespace ALS {
	namespace SSAP {
		class  ActivityId;
		class Reference;
		class SSN;
	}
}
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;
using ALS::SSAP::ActivityId;

namespace ALS {
namespace SSAP {
namespace USER {

class ActivityConfirmation : public virtual Confirmation {
public:
	/**
	 * S-ACTIVITY-DISCARD.CONFIRMATION.
	 *
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityDiscardConfirmation(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.CONFIRMATION.
	 * @param secondSSN the second serial number
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndConfirmation(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.CONFIRMATION.
	 * @param secondSSN the second serial number
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-INTERRUPT.CONFIRMATION.
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode SActivityInterruptConfirmation(int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
