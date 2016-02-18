/*
 * CC.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_CC_H_
#define ALS_TSAP_TPDU_CC_H_

#include "als/tsap/tpdu/C.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class CC : public C {
public:
	CC()		: C(TPDU_CC) {}
	CC(byte li) : C(li, TPDU_CC) {}

private:
	CC(const CC& ak) = delete;
	CC& operator = (const CC&)  = delete;
};

}
}
}

#endif
