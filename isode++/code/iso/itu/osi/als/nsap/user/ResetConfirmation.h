/*
 * ResetConfirmation.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_RESET_CONFIRMATION_H_
#define ALS_NSAP_USER_RESET_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

namespace ALS {
namespace NSAP {
namespace USER {

class ResetConfirmation : public virtual Confirmation {
public:
	virtual ReturnCode NResetConfirmation() = 0;
};

}
}
}

#endif
