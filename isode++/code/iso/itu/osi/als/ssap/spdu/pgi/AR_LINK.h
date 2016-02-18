/*
 * AR_LINK.h
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PGI_AR_LINK_H_
#define ALS_SSAP_SPDU_PGI_AR_LINK_H_
#include "als/ssap/spdu/pgi/PGI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	class AR;
class AR_LINK : public PGI {
public:
	AR_LINK(AR& spdu_ar);
	AR_LINK(AR& spdu_ar, NetworkBuffer& tsdu);
	virtual ~AR_LINK();
};

}
}
}

#endif
