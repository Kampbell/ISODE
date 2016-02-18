/*
 * DR.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_DR_H_
#define ALS_TSAP_TPDU_DR_H_

#include "als/tsap/tpdu/D.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API DR : public D {
public:
	DR()		: D(TPDU_DR) {}
	DR(byte li) : D(li, TPDU_DR) {}

private:
	DR(const DR& ak)  = delete;
	DR& operator = (const DR&)  = delete;
};

}
}
}

#endif
