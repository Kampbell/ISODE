/*
 * ER.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/ER.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int ER::decode(NetworkBuffer* nsdu) {
	_dstref = nsdu->getShort();
	_reject = nsdu->getByte();
	return OK;
}
int ER::encode(unique_ptr<NetworkBuffer>& nsdu) {
	return OK;
}

}
}
}
