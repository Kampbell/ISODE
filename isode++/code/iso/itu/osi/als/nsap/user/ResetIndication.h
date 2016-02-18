/*
 * ResetIndication.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_RESET_INDICATION_H_
#define ALS_NSAP_USER_RESET_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
	namespace NSAP {
		namespace ADDR {
			class NSAPAddr;
		}
	}
}

using ALS::NSAP::ADDR::NSAPAddr;


namespace ALS {
namespace NSAP {
namespace USER {

class ResetIndication : public virtual Indication {
public:
	virtual ReturnCode NResetIndication(const NSAPAddr& originator, int reason) = 0;
};

}
}
}

#endif
