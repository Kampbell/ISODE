/*
 * ReleaseConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_RELEASE_CONFIRMATION_H_
#define ALS_PSAP_USER_RELEASE_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class ReleaseConfirmation : public virtual Confirmation {
public:
	/**
	 * P-RELEASE.CONFIRMATION.
	 * 
	 * @param affirmative - true = connection released, false = request refused
	 * @param userData the datas
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PReleaseConfirmation(bool affirmative, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
