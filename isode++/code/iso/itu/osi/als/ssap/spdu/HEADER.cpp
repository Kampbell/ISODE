/*
 * HEADER.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */
#include "Poco/Exception.h"
using Poco::RuntimeException;


#include "HEADER.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
HEADER::HEADER(byte id) : id(id) {
	size = l0 = l1 = l2 = 0;
}
HEADER::HEADER(byte id, NetworkBuffer& tsdu) : id(id) {
	l0 = tsdu.get();
	if (l0 == 255) {
		//l1 = tsdu.get();
		//l2 = tsdu.get();
		size = tsdu.getShort();
		if (hli() < 255) {
			throw  RuntimeException("hli() < 255");
		}
	}
	else {
		l1 = l2 = 0;
		size = 0;
	}
}
HEADER::~HEADER() {
}
int HEADER::length()  const {
	int len = hli();
	if (len < 255) {
		return len + 2; /* sizeof(id) + sizeof(l0) */
	}
	else {
		return len + 4; /* sizeof(id) + sizeof(l0) + sizeof(l1)  + sizeof(l2) */
	}
}
int HEADER::hli()  const {
	if  (l0 < 255) {
		return l0;
	} else {
		//return (l1 << 8) + l2;
		return size;
	}
}

void HEADER::hli(int cc) {
	if (cc >= 0) {
		if  (cc < 255) {
			l0 = cc;
		} else {
			l0 = 255;
			//l1 = cc >> 8;l2 = cc & 0xFF;
			size = cc;
		}
	}
}
int HEADER::add(HEADER* header) {
	int len = hli() + header->length();// - 2 /*sizeof(id) + sizeof(l0) */;
	if (len <= 0) {
		throw  RuntimeException("invalid length: " + to_string(len) + " <= 0");
	}
	if (len < 255) {
		l0 = len;
	} else
	if (len < 64 * 1024) {
		if (l0 != 255) {
			l0 = 255;
//					update(2); // add 2 to hierarchy
		} else {
			//len -= 2; // -2 + -2 = -4 = sizeof(id) + sizeof(l0) + sizeof(l1)  + sizeof(l2)
		}
		//l1 = ((len >> 8) & 0xFF);
		//l2 = (len & 0xFF);
		size = len;
	} else {
		throw  RuntimeException("invalid length: " + to_string(len) + " >= 65536");
	}
	return len;
}

void HEADER::allocate(unique_ptr<NetworkBuffer>& tsdu, int cc) const {
	if (tsdu.get() != nullptr)
		throw  InvalidArgumentException();
	int total = length() + cc;
	unique_ptr<NetworkBuffer> newBuffer(new NetworkBuffer(total));
	tsdu = std::move(newBuffer);
}
ReturnCode	HEADER::encode(unique_ptr<NetworkBuffer>& tsdu) const {
	tsdu->put(id);
	tsdu->put(l0);
	if (l0 == 255)
		tsdu->putShort(size);
	return OK;
}


}
}
}
