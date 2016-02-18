/*
 * Initiator.h
 *
 *  Created on: 27 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_INITIATOR_H_
#define ALS_SSAP_USER_INITIATOR_H_

#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;
#include "als/nsap/addr/SSAPAddr.h"
using ALS::NSAP::ADDR::SSAPAddr;

#include "als/ssap/user/AbortIndication.h"
#include "als/ssap/user/ActivityIndication.h"
#include "als/ssap/user/ActivityConfirmation.h"
#include "als/ssap/user/DataIndication.h"
#include "als/ssap/user/DataConfirmation.h"
#include "als/ssap/user/ReleaseIndication.h"
#include "als/ssap/user/ReleaseConfirmation.h"
#include "als/ssap/user/ReportIndication.h"
#include "als/ssap/user/SynchronizeIndication.h"
#include "als/ssap/user/SynchronizeConfirmation.h"
#include "als/ssap/user/TokenIndication.h"

namespace ALS {
	namespace SSAP {
		class Requirement;
		class Reference;
		class SSN;
	}
}
using ALS::SSAP::Requirement;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
namespace USER {

class Initiator :
	public virtual AbortIndication,
	public virtual ActivityIndication,
	public virtual ActivityConfirmation,
	public virtual DataIndication,
	public virtual DataConfirmation,
	public virtual ReleaseIndication,
	public virtual ReleaseConfirmation,
	public virtual ReportIndication,
	public virtual SynchronizeIndication,
	public virtual SynchronizeConfirmation,
	public virtual TokenIndication
			{
public:
	virtual ~Initiator() {}

	/**
	 * S-CONNECT.CONFIRMATION.
	 *
	 * @param reference the session connection identifier
	 * @param respondingAddr the address of peer responding
	 * @param result the result of the session establishment
	 * @param qualityOfService the quality of service
	 * @param requirements the session requirements
	 * @param firstInitialSSN the initial serial number
	 * @param secondInitialSSN TODO
	 * @param settings the initial assignment of tokens
	 * @param ssdusize the largest atomic SSDU
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode SConnectConfirmation(const Reference& reference,	const SSAPAddr& responding,	int result,	const QualityOfService& qualityOfService,
		const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize,	int cc = 0, const void* data = nullptr,
		int rdcc = 0, const void* realdata = nullptr) = 0;
};

}
}
}

#endif
