/*
 * ReportIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_REPORTINDICATION_H_
#define ALS_SSAP_USER_REPORTINDICATION_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
namespace SSAP {
namespace USER {

	class ReportIndication : public virtual Indication {
public:
	~ReportIndication() {
	}
	//	true   = S-U-EXCEPTION-REPORT.INDICATION: reason/data both meaningful
	//	false  = S-P-EXCEPTION-REPORT.INDICATION: reason == SP_NOREASON or SP_PROTOCOL
	/**
	 * S-U-EXCEPTION-REPORT.INDICATION.
	 *
	 * @param reason the reason of the user's exception report
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SUExceptionReportIndication(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-P-EXCEPTION-REPORT.INDICATION.
	 *
	 * @param reason the reason of the provider's exception report: SP_NOREASON or SP_PROTOCOL
	 *
	 * @return the return code
	 */
	virtual ReturnCode SPExceptionReportIndication(int reason) = 0;

};

}
}
}

#endif
