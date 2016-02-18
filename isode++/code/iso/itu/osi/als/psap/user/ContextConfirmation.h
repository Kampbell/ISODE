/*
 * ContextConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_CONTEXT_CONFIRMATION_H_
#define ALS_PSAP_USER_CONTEXT_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class ContextConfirmation : public virtual Confirmation {
public:
	/**
	 *  P-ALTER-CONTEXT.CONFIRMATION.
	 *
	 * @param presentationAdditionResults the presentation addition results
	 * @param presentationDeletionResults the presentation deletion results
	 * @param userData the datas
	 *
	 * @return the return code
	 */
	virtual ReturnCode	PAlterContextConfirmation(
		const Presentation_context_addition_result_list& presentationAdditionResults,
		const Presentation_context_deletion_result_list& presentationDeletionResults,
		const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
