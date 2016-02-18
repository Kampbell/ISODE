/*
 * AbortIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_ABORT_INDICATION_H_
#define ALS_PSAP_USER_ABORT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
namespace PSAP {
namespace USER {

class AbortIndication : public virtual Indication {
public:
	/**
	 * P-U-ABORT.INDICATION.
	 * @param reason the standard reason of the abort
	 * @param extension the reason as an int when reason == null
	 * @param userData the datas from peer
	 * @return the return code
	 */
	virtual ReturnCode PUAbortIndication(int reason, int extension, const User_data* userData = nullptr) = 0;

	/**
	 * P-P-ABORT.INDICATION.
	 * 
	 * @param reason the reason
	 * @param extension the extension
	 * @param data the data
	 * @return the return code
	 */
	virtual ReturnCode PPAbortIndication(int reason, int extension, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
