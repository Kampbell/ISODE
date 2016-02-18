/*
 * ContextRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_CONTEXT_REQUEST_H_
#define ALS_PSAP_SERV_CONTEXT_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ContextRequest : public virtual Request {
public:
	/**
	 * P-ALTER-CONTEXT.REQUEST.
	 * 
	 * @param presentationAdditions the presentation additions
	 * @param presentationDeletions the presentation deletions
	 * @param userData the datas
	 * 
	 * @return the return code
	 */
	virtual ReturnCode	PAlterContextRequest(
		const Presentation_context_addition_list& presentationAdditions,
		const Presentation_context_deletion_list& presentationDeletions,
		const User_data* userData = nullptr) = 0;
	
};

}
}
}

#endif
