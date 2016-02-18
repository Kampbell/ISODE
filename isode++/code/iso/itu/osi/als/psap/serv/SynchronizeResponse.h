/*
 * SynchronizeResponse.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_SYNCHRONIZE_RESPONSE_H_
#define ALS_PSAP_SERV_SYNCHRONIZE_RESPONSE_H_
#include "als/base/serv/Response.h"
using ALS::BASE::SERV::Response;

#include "als/psap/psap.h"

namespace ALS {
namespace SSAP {
	class Reference;
	class SSN;
}
}
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;

namespace ALS {
namespace PSAP {
namespace SERV {

class SynchronizeResponse : public virtual Response {
public:
	/**
	 * P-RESYNCHRONIZE.RESPONSE.
	 * 
	 * @param ssn the serial number
	 * @param tokens the settings
	 * @param presentationIdentififiers TODO
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PResynchronizeResponse(const SSN& ssn, int tokens, const Presentation_context_identifier_list& presentationIdentififiers, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MAJOR.RESPONSE.
	 * 
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMajorResponse(const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MINOR.RESPONSE.
	 * 
	 * @param ssn the serial number
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMinorResponse(const SSN& ssn, const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
