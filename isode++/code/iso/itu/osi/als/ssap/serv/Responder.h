/*
 * Responder.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_RESPONDER_H_
#define ALS_SSAP_SERV_RESPONDER_H_
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
	namespace NSAP {
		namespace ADDR {
			class SSAPAddr;
		}
	}
}
using ALS::NSAP::ADDR::SSAPAddr;

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
	namespace SERV {

class Responder :
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
		 * S-CONNECT.RESPONSE.
		 *
		 * @param reference the session connection identifier
		 * @param respondingAddr the responding SSAP addr
		 * @param result the status
		 * @param qualityOfService the required quality of service
		 * @param requirements the requirements
		 * @param settings the session's settings
		 * @param firstInitialSSN the the first initial serial number
		 * @param secondInitialSSN the second initial serial number
		 * @param data the data from peer
		 *
		 * @return the return code
		 */
		virtual ReturnCode SConnectResponse(const Reference& reference, const SSAPAddr& responding, int result,
			const QualityOfService& qualityOfService, const Requirement&  requirements, int settings, SSN& firstInitialSSN, SSN& secondInitialSSN, int cc = 0, const void* data = nullptr) = 0;

	};

}
}
}

#endif
