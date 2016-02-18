/*
 * SyncRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_SYNCREQUEST_H_
#define ALS_SSAP_SERV_SYNCREQUEST_H_
#include "als/base/serv/Request.h"
#include "als/ssap/SyncOption.h"
#include "als/ssap/ResyncOption.h"
#include "als/ssap/SSN.h"
using ALS::BASE::SERV::Request;
using ALS::SSAP::SyncOption;
using ALS::SSAP::ResyncOption;
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
	namespace SERV {

class SynchronizeRequest : public virtual Request {
public:
	virtual ~SynchronizeRequest() {}
	/**
	 * S-RESYNCHRONIZE.REQUEST.
	 *
	 * @param firstResync the type of the first resynchronize request
	 * @param firstSSN the first serial number
	 * @param secondResync the type of the second resynchronize request
	 * @param secondSSN the second serial number
	 * @param settings the settings
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SResynchronizeRequest(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MAJOR.REQUEST.
	 *
	 * @param firstSSN the first serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMajorRequest(SSN& ssn, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MINOR.REQUEST.
	 *
	 * @param type the type of minor synchronization request
	 * @param dataSeparation if data separation is applied
	 * @param firstSSN the first serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMinorRequest(const SyncOption& type, bool dataSeparation, const SSN& ssn, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
