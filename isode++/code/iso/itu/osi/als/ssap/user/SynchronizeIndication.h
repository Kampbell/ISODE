/*
 * SyncIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_SYNCHRONIZE_INDICATION_H_
#define ALS_SSAP_USER_SYNCHRONIZE_INDICATION_H_

#include "als/base/user/Indication.h"
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
using ALS::BASE::USER::Indication;

namespace ALS {
namespace SSAP {
	namespace USER {
		class SynchronizeIndication : public virtual Indication {
public:
	/**
	 * S-SYNC-MAJOR.INDICATION.
	 * @param firsSSN the serial number
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMajorIndication(const SSN& ssn, int cc = 0, const void* data = nullptr)= 0;

	/**
	 * S-SYNC-MINOR.INDICATION.
	 *
	 * @param type the  sync type
	 * @param dataSeparation true is data separation should apply
	 * @param firstSSN the first serial number
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data = nullptr)= 0;

	/**
	 * S-RESYNCHRONIZE.INDICATION.
	 *
	 * @param firstResync the first resync type
	 * @param firstSSN the first serial number
	 * @param secondResync the second resync type
	 * @param secondSSN the second serial number
	 * @param settings the new token settings
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
