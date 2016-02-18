/*
 * AbortIndication.h
 *
 *  Created on: 17 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_USER_ABORT_INDICATION_H_
#define ALS_ASAP_USER_ABORT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
#include "als/asap/asap.h"


namespace ALS {
namespace ASAP {
namespace USER {

class AbortIndication : public virtual Indication {
public:
	/*
	 * A-ABORT.INDICATION.
	 *
	 * @param source the source of the abort
	 * @param diagnostic the diagnostic of the abort
	 * @param userInformation data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode AAbortIndication(const ABRT_source& source, const ABRT_diagnostic& diagnostic, const Association_information* userInformation = nullptr) = 0;

	/**
	 * A-P-ABORT.INDICATION
	 *
	 * @param reason the reason
	 * @param extension the extension
	 * @param data TODO
	 * @return the return code
	 */
	virtual ReturnCode APAbortIndication(int reason, int extension,  const Association_information* userInformation = nullptr) = 0;
};

}
}
}

#endif
