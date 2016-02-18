/*
 * ReleaseIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_RELEASE_INDICATION_H_
#define ALS_SSAP_USER_RELEASE_INDICATION_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
namespace SSAP {
namespace USER {

class ReleaseIndication : public virtual Indication {
public:
	/**
	 * S-RELEASE.INDICATION.
	 *
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SReleaseIndication(int cc = 0, const void* data = nullptr) = 0;

};

}
}
}

#endif
