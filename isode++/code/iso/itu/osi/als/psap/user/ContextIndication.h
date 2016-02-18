/*
 * ContextIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_CONTEXT_INDICATION_H_
#define ALS_PSAP_USER_CONTEXT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"


namespace ALS {
namespace PSAP {
namespace USER {

class ContextIndication : public virtual Indication {
public:
	
	/**
	 * P-ALTER-CONTEXT.INDICATION.
	 * 
	 * @param presentationAdditions the presentation additions
	 * @param presentationDeletions the presentation deletions
	 * @param presentationAdditionResults the presentation addition results
	 * @param userData the datas
	 * 
	 * @return the return code
	 */
	virtual ReturnCode	PAlterContextIndication(
		const Presentation_context_addition_list& presentationAdditions,
		const Presentation_context_deletion_list& presentationDeletions,
		const Presentation_context_addition_result_list& presentationAdditionResults,
		const User_data* userData = nullptr) = 0;
	
};

}
}
}

#endif
