/*
 * CR.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_CR_H_
#define ALS_TSAP_TPDU_CR_H_

#include "als/tsap/tpdu/C.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API CR : public C {
public:
	CR() : C(TPDU_CR) {}
	CR(byte li) : C(li, TPDU_CR) {}
};

}
}
}

#endif
