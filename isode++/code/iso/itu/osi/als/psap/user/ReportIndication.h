/*
 * ReportIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_REPORT_INDICATION_H_
#define ALS_PSAP_USER_REPORT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class ReportIndication : public virtual Indication {
public:
	/**
	 * P-P-EXCEPTION-REPORT.INDICATION.
	 * 
	 * @param reason the reason : reason == SP_NOREASON, or reason == SP_PROTOCOL
	 * @return the return code
	 */
	virtual ReturnCode PPExceptionReportIndication(int reason) = 0;

	/**
	 * P-U-EXCEPTION-REPORT.INDICATION.
	 * 
	 * @param reason the reason
	 * @param userData the user data
	 * @return the return code
	 */
	virtual ReturnCode PUExceptionReportIndication(int reason, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
