/*
 * CN_ITEMS.h
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PGI_CN_ITEMS_H_
#define ALS_SSAP_SPDU_PGI_CN_ITEMS_H_
#include "als/ssap/spdu/pgi/PGI.h"

namespace ALS {
namespace SSAP {
	namespace PROV {
		class SPKT;
	}
	using PROV::SPKT;
namespace SPDU {
	class CN_AC;

	class CN_ITEMS : public PGI {
public:
	CN_ITEMS(CN_AC& spdu_cn);
	CN_ITEMS(CN_AC& spdu_cn, NetworkBuffer& tsdu);
	virtual ~CN_ITEMS();
};

}
}
}

#endif
