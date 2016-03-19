/*
 * ED.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/ED.h"
#include "als/tsap/tpdu/TPDUException.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int ED::decode(NetworkBuffer* nsdu) {
	if (li() < minimumLength()) {
		throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
	}

	ed_nr = nsdu->getByte();
	return OK;
}
int ED::encode(unique_ptr<NetworkBuffer>& nsdu) {
	TPCI::encode(nsdu);
	nsdu->putByte(ed_nr);
	addData(nsdu);
	nsdu->flip();
	return OK;
}

}
}
}
