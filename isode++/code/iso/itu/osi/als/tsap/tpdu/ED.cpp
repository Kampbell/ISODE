/*
 * ED.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/ED.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int ED::decode(NetworkBuffer* nsdu) {
	return OK;
}
int ED::encode(unique_ptr<NetworkBuffer>& nsdu) {
	return OK;
}

}
}
}
