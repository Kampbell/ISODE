/*
 * Initiator.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_INITIATOR_H_
#define ALS_SSAP_SERV_INITIATOR_H_
#include "als/nsap/addr/SSAPAddr.h"
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::ADDR::SSAPAddr;
using ALS::NSAP::QualityOfService;

#include "als/ssap/Requirement.h"
#include "als/ssap/serv/Service.h"
#include "als/ssap/serv/AbortRequest.h"
#include "als/ssap/serv/ActivityRequest.h"
#include "als/ssap/serv/ActivityResponse.h"
#include "als/ssap/serv/DataRequest.h"
#include "als/ssap/serv/DataResponse.h"
#include "als/ssap/serv/ReleaseRequest.h"
#include "als/ssap/serv/ReleaseResponse.h"
#include "als/ssap/serv/ReportRequest.h"
#include "als/ssap/serv/SynchronizeRequest.h"
#include "als/ssap/serv/SynchronizeResponse.h"
#include "als/ssap/serv/TokenRequest.h"

namespace ALS {
	namespace SSAP {
		class Reference;
		class SSN;
	}
}
using ALS::SSAP::Requirement;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
namespace SERV {
class Initiator : 
	public virtual AbortRequest,
	public virtual ActivityRequest,
	public virtual ActivityResponse,
	public virtual DataRequest,
	public virtual DataResponse,
	public virtual ReleaseRequest,
	public virtual ReleaseResponse,
	public virtual ReportRequest,
	public virtual SynchronizeRequest,
	public virtual SynchronizeResponse,
	public virtual TokenRequest,
	public virtual Service
{
public:
	/**
	 * S-CONNECT.REQUEST.
	 *
	 * @param reference the session connection identifier
	 * @param callingAddr the calling SSAP addr
	 * @param calledAddr the called SSAP addr
	 * @param qualityOfService the qualityOfService
	 * @param requirements the requirements
	 * @param firstInitialSSN the first initial serial number
	 * @param secondInitialSSN the second initial serial number
	 * @param settings the settings
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SConnectRequest(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called,
		const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, byte settings, int cc = 0, const void* data = nullptr
		) = 0;

};

}
}
}

#endif
