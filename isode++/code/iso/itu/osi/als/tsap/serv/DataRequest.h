/*
 * DataRequest.h
 *
 *  Created on: 21 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_SERV_DATAREQUEST_H_
#define ALS_TSAP_SERV_DATAREQUEST_H_
#include "als/base/serv/Request.h"

namespace ALS {
namespace TSAP {
namespace SERV {

class DataRequest : public virtual ALS::BASE::SERV::Request {
public:
	/**
	 * T-DATA.REQUEST.
	 *
	 * @param tsdu the tsdu
	 * @return the return code
	 */
	virtual ReturnCode TDataRequest(NetworkBuffer* tsdu) = 0;
	virtual ReturnCode TDataRequest(int cc = 0, const byte* data = nullptr) = 0;
	/**
	 * T-EXPEDITED-DATA.REQUEST.
	 *
	 * @param tsdu the tsdu
	 *
	 * @return the return code
	 */
	virtual ReturnCode TExpeditedDataRequest(int cc = 0, const byte* data = nullptr) = 0;

protected:
	DataRequest() {}
private:
	DataRequest(const DataRequest&){}
	DataRequest& operator = (const DataRequest&) { return *this; };
};

}
}
}

#endif
