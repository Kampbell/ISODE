/*
 * SynchronizeConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_SYNCHRONIZE_CONFIRMATION_H_
#define ALS_PSAP_USER_SYNCHRONIZE_CONFIRMATION_H_
#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/psap/psap.h"

namespace ALS {
namespace SSAP {
	class ActivityId;
	class Reference;
	class SSN;
	enum SyncOption;
}
}
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;
using ALS::SSAP::SyncOption;


namespace ALS {
namespace PSAP {
namespace USER {

class SynchronizeConfirmation : public virtual Confirmation {
public:
	/**
	 * P-RESYNCHRONIZE.CONFIRMATION.
	 * 
	 * @param ssn the serial number
	 * @param tokens the new token settings
	 * @param userData the infos
	 * @return the return code
	 */
	virtual ReturnCode PResynchronizeConfirmation(const SSN& ssn, byte tokens, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MAJOR.CONFIRMATION.
	 * 
	 * @param ssn the ssn
	 * @param userData the infos
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMajorConfirmation(const SSN& ssn, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MINOR.CONFIRMATION.
	 * 
	 * @param ssn the serial number
	 * @param userData the infos
	 * @return the return code
	 */
	virtual ReturnCode PSyncMinorConfirmation(const SSN& ssn, const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
