/*
 * ReleaseIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_RELEASE_INDICATION_H_
#define ALS_PSAP_USER_RELEASE_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class ReleaseIndication : public virtual Indication {
public:
	/**
	 * P-RELEASE.INDICATION.
	 * 
	 * @param userData the datas
	 * @return the return code
	 */
	virtual ReturnCode PReleaseIndication(const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
