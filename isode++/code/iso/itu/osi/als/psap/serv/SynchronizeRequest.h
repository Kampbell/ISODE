/*
 * SynchronizeRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_SYNCHRONIZE_REQUEST_H_
#define ALS_PSAP_SERV_SYNCHRONIZE_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace SSAP {
	class SyncOption;
	class ResyncOption;
	class SSN;
}
}
using ALS::SSAP::SyncOption;
using ALS::SSAP::ResyncOption;
using ALS::SSAP::SSN;
namespace ALS {
namespace PSAP {
namespace SERV {

class SynchronizeRequest : public virtual Request {
public:
	/**
	 * P-RESYNCHRONIZE.REQUEST.
	 * 
	 * @param type the type of resynchronization
	 * @param ssn the ssn
	 * @param tokens the settings
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PResynchronizeRequest(const ResyncOption& type, const SSN& ssn, byte tokens, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MAJOR.REQUEST.
	 * 
	 * @param ssn the serial number
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMajorRequest(const SSN& ssn, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MINOR.REQUEST.
	 * 
	 * @param type the type of minor synchronization request
	 * @param ssn the serial number
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMinorRequest(const SyncOption& type, const SSN& ssn, const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
