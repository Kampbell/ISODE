/*
 * DataConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef DATACONFIRMATION_H_
#define DATACONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class DataConfirmation : public virtual Confirmation {
public:
	/**
	 * P-CAPABILITY-DATA.CONFIRMATION.
	 *
	 * @param userData the infos from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode PCapabilityDataConfirmation(const User_data& userData) = 0;
};

}
}
}

#endif
