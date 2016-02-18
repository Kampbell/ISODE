/*
 * D.cpp
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/D.h"

namespace ALS {
namespace TSAP {
namespace TPDU {
void	D::setData(NetworkBuffer* buffer) {
	if (buffer->remaining() > TD_SIZE)
		buffer->shrink(TD_SIZE);
	TPCI::setData(buffer);
}
void	D::setData(const string&  message) {
	int size = message.length();;
	if (size > TD_SIZE)
		size = TD_SIZE;
	TPCI::setData(size, (const byte*)message.data());
}
void	D::setData(int cc, const byte* data) {
	if (cc > TD_SIZE)
		cc = TD_SIZE;
	TPCI::setData(cc, data);
}

int D::decode(NetworkBuffer* nsdu) {
	d_dstref = nsdu->getShort();
	d_srcref = nsdu->getShort();
	d_reason = nsdu->getByte();
	return OK;
}
int D::encode(unique_ptr<NetworkBuffer>& nsdu) {
	TPCI::encode(nsdu);
	nsdu->putShort(d_dstref);
	nsdu->putShort(d_srcref);
	nsdu->putByte(d_reason);
	addData(nsdu);
	nsdu->flip();
	return OK;
}

}
}
}
