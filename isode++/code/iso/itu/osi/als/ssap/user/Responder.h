/*
 * Responder.h
 *
 *  Created on: 27 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_RESPONDER_H_
#define ALS_SSAP_USER_RESPONDER_H_

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

class Responder : 
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
	virtual ~Responder() {}

	/**
	 * S-CONNECT.INDICATION.
	 *
	 * @param reference the session connection identifier
	 * @param callingAddr the address of peer calling
	 * @param calledAddr the address of peer called
	 * @param result the result
	 * @param qualityOfService the quality of service
	 * @param requirements the session requirements
	 * @param firstInitialSSN the first initial serial number
	 * @param secondInitialSSN the second initial serial number
	 * @param settings the initial settings of tokens
	 * @param ssdusize the largest atomic SSDU
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode SConnectIndication(
		const Reference&					reference,	//
		const SSAPAddr&						calling,	// the SSAP address of peer calling
		const SSAPAddr&						called,		// the SSAP address of peer called
		int									result,		// the result
		const QualityOfService&							qualityOfService,		// the quality of service
		const Requirement&					requirements, // the session requirements
		SSN&								firstInitialSSN, //the initial serial number
		SSN&								secondInitialSSN, // the second initial serial number
		int									settings, // the initial settings of tokens
		int									ssdusize, // the largest atomic SSDU
		int									cc = 0, 
		const void*							data = nullptr) = 0;
};

}
}
}

#endif
