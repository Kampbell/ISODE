/*
 * ActivityIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_ACTIVITY_INDICATION_H_
#define ALS_SSAP_USER_ACTIVITY_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

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
		class ActivityIndication : public virtual Indication {
public:
	/**
	 * S-ACTIVITY-START.INDICATION.
	 *
	 * @param activityId the START/RESUME activity identifier
	 * @param data the activity DATA from peer
	 * @return the return code
	 */
	virtual ReturnCode SActivityStartIndication(const ActivityId&  activityId, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-RESUME.INDICATION.
	 *
	 * @param activityId the START/RESUME activity identifier
	 * @param oldActivityId the RESUME old activity identifier
	 * @param firstSSN the RESUME/END Serial number
	 * @param secondSSN the second serial number
	 * @param oldSessionReference the old connection identifier
	 * @param data the activity DATA from peer
	 * @return the return code
	 */
	virtual ReturnCode SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN,
		const SSN& secondSSN, const Reference& oldSessionReference, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-INTERRUPT.INDICATION.
	 * @param reason the reason to interrupt
	 * @param data the activity DATA from peer
	 * @return the return code
	 */
	virtual ReturnCode SActivityInterruptIndication(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-DISCARD.INDICATION.
	 *
	 * @param reason the INTERRUPT/DISCARD reason
	 * @param data the activity DATA from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityDiscardIndication(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.INDICATION.
	 *
	 * @param firstSSN the RESUME/END Serial number
	 * @param data the activity DATA from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndIndication(const SSN& ssn, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
