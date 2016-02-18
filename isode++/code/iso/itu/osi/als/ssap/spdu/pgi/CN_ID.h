/*
 * CN_ID.h
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PGI_CN_ID_H_
#define ALS_SSAP_SPDU_PGI_CN_ID_H_
#include "als/ssap/Reference.h"
using ALS::SSAP::Reference;
#include "als/ssap/spdu/pgi/PGI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	class CN_AC;

class CN_ID : public PGI {
public:
	CN_ID(PI_SS_TYPE call, const Reference& ref);
	CN_ID(CN_AC& spdu_cn, NetworkBuffer& tsdu);
	virtual ~CN_ID();
};

}
}
}

#endif
