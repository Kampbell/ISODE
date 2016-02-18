/*
 * ActivityResponse.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_ACTIVITY_RESPONSE_H_
#define ALS_PSAP_SERV_ACTIVITY_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ActivityResponse : public virtual Response {
public:
	/**
	 * P-ACTIVITY-DISCARD.RESPONSE.
	 * 
	 * @param pa the abort info from provider if any
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityDiscardResponse();

	/**
	 * P-ACTIVITY-END.RESPONSE.
	 * 
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityEndResponse(const User_data* userData = nullptr) = 0;

	/**
	 * P-ACTIVITY-INTERRUPT.RESPONSE.
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PActivityInterruptResponse() = 0;

};

}
}
}

#endif
