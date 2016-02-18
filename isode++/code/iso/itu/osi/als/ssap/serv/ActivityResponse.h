/*
 * ActivityResponse.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_ACTIVITYRESPONSE_H_
#define ALS_SSAP_SERV_ACTIVITYRESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

namespace ALS {
	namespace SSAP {
		class Reference;
		class SSN;
	}
}
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
	namespace SERV {

		class ActivityResponse : public virtual Response {
public:
	virtual ~ActivityResponse() {}
	/**
	 * S-ACTIVITY-DISCARD.RESPONSE.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityDiscardResponse(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.RESPONSE.
	 *
	 * @param secondSSN the second serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndResponse(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-END.RESPONSE.
	 *
	 * @param secondSSN the second serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityEndResponse(const SSN& secondSSN, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-ACTIVITY-INTERRUPT.RESPONSE.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SActivityInterruptResponse(int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
