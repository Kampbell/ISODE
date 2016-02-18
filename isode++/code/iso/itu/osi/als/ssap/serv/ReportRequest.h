/*
 * ReportRequest.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_REPORTREQUEST_H_
#define ALS_SSAP_SERV_REPORTREQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

namespace ALS {
namespace SSAP {
namespace SERV {

class ReportRequest : public virtual Request {
public:
	virtual ~ReportRequest() {}
	/**
	 * S-U-EXCEPTION-REPORT.REQUEST.
	 *
	 * @param reason the reason
	 * @param data the data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode SUExceptionReportRequest(int reason, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
