/*
 * RJ.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/RJ.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int RJ::decode(NetworkBuffer* nsdu) {
	return OK;
}
int RJ::encode(unique_ptr<NetworkBuffer>& nsdu) {
	return OK;
}

}
}
}
