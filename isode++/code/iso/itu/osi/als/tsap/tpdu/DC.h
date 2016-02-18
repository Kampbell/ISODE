/*
 * DC.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_DC_H_
#define ALS_TSAP_TPDU_DC_H_

#include "als/tsap/tpdu/D.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class DC : public D {
public:
	DC()		: D(TPDU_DC) {}
	DC(byte li) : D(li, TPDU_DC) {}

};

}
}
}

#endif
