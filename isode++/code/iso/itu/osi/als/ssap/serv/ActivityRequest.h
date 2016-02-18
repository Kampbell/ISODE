/*
 * ActivityRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_ACTIVITYREQUEST_H_
#define ALS_SSAP_SERV_ACTIVITYREQUEST_H_

#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
	namespace SSAP {
		class  ActivityId;
		class Reference;
		class SSN;
	}
}
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
	namespace SERV {

class ActivityRequest : public virtual Request {
public:
	virtual ~ActivityRequest() {}

	/**
	 * S-ACTIVITY-DISCARD.REQUEST.
	 *
	 * @param reason the reason of the discard request
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityDiscardRequest(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.REQUEST.
	 *
	 * @param firstSSN the first serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndRequest(SSN& firstSSN, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-INTERRUPT.REQUEST.
	 *
	 * @param reason the reason to interrupt
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityInterruptRequest(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-RESUME.REQUEST.
	 *
	 * @param activityId the activity identifier
	 * @param oldActivityId the old activity identifier
	 * @param firstSSN the the first serial number
	 * @param secondSSN the second serial number
	 * @param reference the session connection identifier
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN&  secondSSN,
		const Reference& reference, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-START.REQUEST.
	 *
	 * @param activityId the activity identifier
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityStartRequest(const ActivityId& activityId, int cc = 0, const void* data = nullptr) = 0;


};

}
}
}

#endif
