/*
 * ReportRequest.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_SERV_REPORT_REQUEST_H_
#define ALS_PSAP_SERV_REPORT_REQUEST_H_
#include "als/base/serv/Request.h"
using ALS::BASE::SERV::Request;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace SERV {

class ReportRequest : public virtual Request {
public:
	/**
	 * P-U-EXCEPTION-REPORT.REQUEST.
	 * 
	 * @param reason the reason
	 * @param userData the datas from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PUExceptionReportRequest(int reason, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
