/*
 * AD.cpp
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#include "AD.h"
#include "als/ssap/spdu/pi/REASON.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
int	AD::encode() {
	PI* pi;
	int len = 0;
	if (hasMask(SMASK_AD_REASON)) {
		pi = new REASON(ad_reason);
		len += pi->length();
		append(pi);
	}
	return len;
}
}
}
}
