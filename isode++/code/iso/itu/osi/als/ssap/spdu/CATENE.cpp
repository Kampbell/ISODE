/*
 * CONCATENE.cpp
 *
 *  Created on: 9 déc. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/CATENE.h"
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

CATENE::CATENE() {
	// TODO Auto-generated constructor stub

}

CATENE::~CATENE() {
	// TODO Auto-generated destructor stub
}
void CATENE::allocate(unique_ptr<NetworkBuffer>& tsdu, int cc)  {
	if (tsdu.get() != nullptr)
		throw  InvalidArgumentException();
	int total = cc;
	unique_ptr<NetworkBuffer> newBuffer(new NetworkBuffer(total));
	tsdu = std::move(newBuffer);
}
ReturnCode	CATENE::flush(unique_ptr<NetworkBuffer>& tsdu, int cc, const void* data) const {
	int size = 0;
	for(auto spdu : spdus) {
		size += spdu->length();
	}
	allocate(tsdu, size + cc);
	for(auto spdu : spdus) {
		spdu->flush(tsdu);
	}
	if (cc > 0)
		tsdu->putBytes(cc, (const byte*)data);
	poco_assert(tsdu->remaining() == 0);
	tsdu->flip();
	return OK;
}

} 
} 
} 
