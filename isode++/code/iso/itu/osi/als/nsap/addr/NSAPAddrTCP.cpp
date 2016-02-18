/*
 * NSAPAddrTCP.cpp
 *
 *  Created on: 6 août 2014
 *      Author: FrancisANDRE
 */

#include "NSAPAddrTCP.h"

namespace ALS {
namespace NSAP {
namespace ADDR {
	const char* NSAPAddrTCP::parse(const char* address) {
		addr.na_tcp.na_tcp_port = 102;
		return address;
	}

}
}
}
