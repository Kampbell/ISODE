/*
 * DataRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_DATA_REQUEST_H_
#define ALS_PSAP_SERV_DATA_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class DataRequest : public virtual Request {
public:
	/**
	 * P-CAPABILITY-DATA.REQUEST.
	 * 
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PCapabilityDataRequest(const User_data* userData = nullptr) = 0;

	/**
	 * P-DATA.REQUEST.
	 * 
	 * @param data the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PDataRequest(const User_data* userData = nullptr) = 0;

	/**
	 * P-EXPEDITED-DATA.REQUEST.
	 * 
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PExpeditedDataRequest(const User_data* userData = nullptr) = 0;

	/**
	 * P-TYPED-DATA.REQUEST.
	 * 
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTypedDataRequest(const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
