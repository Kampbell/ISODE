/*
 * EA.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/EA.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int EA::decode(NetworkBuffer* nsdu) {
	return OK;
}
int EA::encode(unique_ptr<NetworkBuffer>& nsdu) {
	return OK;
}

}
}
}
