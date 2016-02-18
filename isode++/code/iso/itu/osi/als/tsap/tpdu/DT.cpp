/*
 * DT.cpp
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

//FIXME #include "als/tsap/Disconnect.h"
//FIXME using ALS::TSAP::Disconnect;

#include "als/tsap/tpdu/DT.h"
#include "als/tsap/tpdu/TPDUException.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

int DT::decode(NetworkBuffer* nsdu) {
	if (li() < minimumLength()) {
		throw  TPDUException(0x80 + 10);// Disconnect::DR_LENGTH);
	}

	dt_nr = nsdu->getByte();
	return OK;
}
int DT::encode(unique_ptr<NetworkBuffer>& nsdu) {
	TPCI::encode(nsdu);
	nsdu->putByte(dt_nr);
	addData(nsdu);
	nsdu->flip();
	return OK;
}

}
}
}
