/*
 * SyncResponse.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_SYNCRESPONSE_H_
#define ALS_SSAP_SERV_SYNCRESPONSE_H_
#include "als/base/serv/Response.h"
#include "als/ssap/ResyncOption.h"
using ALS::BASE::SERV::Response;
using ALS::SSAP::ResyncOption;

namespace ALS {
namespace SSAP {
	class SSN;
	namespace SERV {

class SynchronizeResponse : public virtual Response {
public:
	virtual ~SynchronizeResponse() {}
	/**
	 * S-RESYNCHRONIZE.RESPONSE.
	 *
	 * @param firstSSN the the first serial number
	 * @param secondSSN the second serial number
	 * @param settings the settings
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SResynchronizeResponse(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MAJOR.RESPONSE.
	 *
	 * @param secondSSN the second serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMajorResponse(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MAJOR.RESPONSE.
	 *
	 * @param secondSSN the second serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMajorResponse(const SSN& secondSSN, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SYNC-MINOR.RESPONSE.
	 *
	 * @param firstSSN the first serial number
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSyncMinorResponse(const SSN& firstSSN, int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
