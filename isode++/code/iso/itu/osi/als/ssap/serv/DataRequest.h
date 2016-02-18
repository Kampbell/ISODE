/*
 * DataRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_DATAREQUEST_H_
#define ALS_SSAP_SERV_DATAREQUEST_H_

#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace SSAP {
namespace SERV {

class DataRequest : public virtual Request {
public:
	virtual ~DataRequest() {}

	/**
	 * S-CAPABILILTY-DATA.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SCapabilityDataRequest(int cc = 0, const void* data = nullptr)= 0;

	/**
	 * S-DATA.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SDataRequest(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-DATA.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SDataRequest(const SharedNetworkBuffer& data) = 0;

	/**
	 * S-EXPEDITED-DATA.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 *
	 * @throws TSAPException the TSAP exception
	 */
	virtual ReturnCode SExpeditedDataRequest(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-TYPED-DATA.REQUEST.
	 *
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode STypedDataRequest(int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-SEND.REQUEST (segmented).
	 *
	 * @param data the data from peer
	 * @param begin the begin
	 * @param end the end
	 *
	 * @return the return code
	 */
	virtual ReturnCode SSendRequest(bool begin, bool end, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-WRITE.REQUEST (pseudo).
	 *
	 * @param typed the typed
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SWriteRequest(bool typed, int cc, const void* data) = 0;


};

}
}
}

#endif
