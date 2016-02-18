/*
 * SynchronizeConfirmation.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_SYNCHRONIZE_CONFIRMATION_H_
#define ALS_SSAP_USER_SYNCHRONIZE_CONFIRMATION_H_

#include "als/base/user/Confirmation.h"
#include "als/ssap/ResyncOption.h"
#include "als/ssap/SyncOption.h"
#include "als/ssap/ActivityId.h"
#include "als/ssap/Reference.h"
#include "als/ssap/SSN.h"
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;
using ALS::SSAP::SyncOption;
using ALS::SSAP::ResyncOption;
using ALS::BASE::USER::Confirmation;


namespace ALS {
namespace SSAP {
namespace USER {

class SynchronizeConfirmation : public virtual Confirmation {
public:
	/**
	 * S-SYNC-MINOR.CONFIRMATION.
	 * @param firstSSN the first serial number
	 * @param data the data
	 *
	 * @return the return code
	 */

	virtual ReturnCode SSyncMinorConfirmation(const SSN& ssn, int cc = 0, const void* data = nullptr) = 0;


	/**
	 * S-SYNC-MAJOR.CONFIRMATION.
	 * @param data the data
	 *
	 * @return the return code
	 */

	virtual ReturnCode SSyncMajorConfirmation(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MAJOR.CONFIRMATION.
	 * @param secondSSN the serial number
	 * @param data the data
	 *
	 * @return the return code
	 */

	virtual ReturnCode SSyncMajorConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr) = 0;


	/**
	 * S-RESYNCHRONIZE.CONFIRMATION.
	 *
	 * @param firstResync the first resync type
	 * @param firstSSN the first serial number
	 * @param secondResync the second resync type
	 * @param secondSSN the second serial number
	 * @param settings the settings
	 * @param data the data
	 * @return the return code
	 */

	virtual ReturnCode SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
