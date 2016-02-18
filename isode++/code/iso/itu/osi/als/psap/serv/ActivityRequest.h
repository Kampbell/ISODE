/*
 * ActivityRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_ACTIVITY_REQUEST_H_
#define ALS_PSAP_SERV_ACTIVITY_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

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
namespace SERV {

class ActivityRequest : public virtual Request {
public:
	/**
	 * P-ACTIVITY-DISCARD.REQUEST.
	 * 
	 * @param reason the reason
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityDiscardRequest(int reason) = 0;


	/**
	 * P-ACTIVITY-END.REQUEST.
	 * 
	 * @param ssn the ssn
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityEndRequest(const SSN& ssn, const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-INTERRUPT.REQUEST.
	 * 
	 * @param reason the reason
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityInterruptRequest(int reason) = 0;

	/**
	 * P-ACTIVITY-RESUME.REQUEST.
	 * 
	 * @param activityId the activity identifier
	 * @param oldActivityId the old activity identifier
	 * @param ssn the serial number
	 * @param oldReference the session connection identifier
	 * @param userData the data from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& ssn, const Reference& oldReference,
		const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-START.REQUEST.
	 * 
	 * @param activityId the activity identifier
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityStartRequest(const ActivityId& activityId, const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
