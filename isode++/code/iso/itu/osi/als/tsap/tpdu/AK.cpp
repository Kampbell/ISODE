/*
 * AK.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/AK.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int AK::decode(NetworkBuffer* nsdu) {
	return OK;
}
int AK::encode(unique_ptr<NetworkBuffer>& nsdu) {
	return OK;
}

}
}
}
