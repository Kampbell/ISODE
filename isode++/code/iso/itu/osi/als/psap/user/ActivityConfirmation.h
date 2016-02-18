/*
 * ActivityConfirmation.h
 *
 *  Created on: 18 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_ACTIVITY_CONFIRMATION_H_
#define ALS_PSAP_USER_ACTIVITY_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

namespace ALS {
namespace SSAP {
	class SSN;
}
}
using ALS::SSAP::SSN;

namespace ALS {
namespace PSAP {
namespace USER {

class ActivityConfirmation : public virtual Confirmation {
public:
	/**
	 * P-ACTIVITY-END.CONFIRMATION.
	 * @param secondSSN TODO
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityEndConfirmation(const SSN& secondSSN, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-INTERRUPT.CONFIRMATION.
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityInterruptConfirmation(const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-DISCARD.CONFIRMATION.
	 * @param userData the activity data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode PActivityDiscardConfirmation(const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
