/*
 * ActivityIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_ACTIVITY_INDICATION_H_
#define ALS_PSAP_USER_ACTIVITY_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"

namespace ALS {
namespace SSAP {
	class ActivityId;
	class Reference;
	class SSN;
}
}
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace PSAP {
namespace USER {

class ActivityIndication : public virtual Indication {
public:
	/**
	 * P-ACTIVITY-START.INDICATION.
	 * 
	 * @param aid the activity identifier
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityStartIndication(const ActivityId& aid, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-RESUME.INDICATION.
	 * 
	 * @param activityId the activity identifier
	 * @param oldActivityId the  old connection identifier
	 * @param firstSSN the serial number
	 * @param secondSSN TODO
	 * @param oldReference the old connection identifier
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityResumeIndication(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN,
		const SSN& secondSSN, const Reference& oldReference, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-INTERRUPT.INDICATION.
	 * @param reason the reason to interrupt
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityInterruptIndication(int reason, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-DISCARD.INDICATION.
	 * 
	 * @param reason the reason to discard
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityDiscardIndication(int reason, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-END.INDICATION.
	 * 
	 * @param ssn the serial number
	 * @param userData the activity data from peer
	 * @return the return code
	 */
	virtual ReturnCode PActivityEndIndication(const SSN& ssn, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
