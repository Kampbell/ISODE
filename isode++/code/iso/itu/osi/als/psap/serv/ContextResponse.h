/*
 * ContextResponse.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_CONTEXT_RESPONSE_H_
#define ALS_PSAP_SERV_CONTEXT_RESPONSE_H_

#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ContextResponse : public virtual Response {
public:
	/**
	 * P-ALTER-CONTEXT.RESPONSE.
	 * 
	 * @param presentationAdditionResults the presentation addition results
	 * @param presentationDeletionResults the presentation deletion results
	 * @param userData the datas
	 * 
	 * @return the return code
	 */
	virtual ReturnCode	PAlterContextResponse(
		const Presentation_context_addition_result_list& presentationAdditionResults,
		const Presentation_context_deletion_result_list& presentationDeletionResults,
		const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
