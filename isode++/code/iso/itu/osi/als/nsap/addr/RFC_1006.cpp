/*
 * RFC_1006.cpp
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#include <cstring>
#include "Poco/Net/IPAddress.h"
#include "als/base/addr/AddressException.h"
#include "als/nsap/addr/RFC_1006.h"

// TELEX+00728722+RFC-1006+03+10.0.0.6:8080
using namespace Poco::Net;
using ALS::BASE::ADDR::AddressException;

namespace ALS {
namespace NSAP {
namespace ADDR {

const char* RFC_1006::parse(NSAPAddr& nsap, const char* address) const { 
	const char* b = address;
	const char* e = nullptr;
	if (memcmp(name().c_str(), address, name().length()) != 0)
		throw InvalidArgumentException();
	b += name().length();

	int len = 0;
	if (*b != '+')
		throw AddressException(string("RFC-1006 should start with a + :").append(address));
	
	
	const char* prefix = ++b;
	e = strchr(b, '+');
	if (e == nullptr) {
		e = strchr(b, 0);
	}
	len = e - b;
		
	if (memcmp(prefix, "03", 2) || memcmp(prefix, "05", 2)) {
		b = prefix + 2;
		if (*b == '+') {
			const char* hostc = ++b;
			e = strchr(b, '+');
			if (e == nullptr) {
				e = strchr(b, 0);
			}
			len = e - b;
			string host(hostc, len);

			int port = 0; int tset = 0;
			if (*e == '+') {
				b = e + 1;
				if (*b == 0) {
					throw AddressException(address);
				}
				e = strchr(b, '+');
				port = (int)strtol(b, (char**) &e, 10);
				if (e != nullptr) {
					if (*e == '+') {
						b  = e + 1;
						tset = (int)strtol(b, (char**)&e, 10);
					}
				}
			}
			if (port == 0)
				port = 102;
			IPAddress inetAddress;
			bool result = IPAddress::tryParse(host, inetAddress);
			if (!result)
				throw AddressException(address);

			nsap.na_stack = NSAPAddr::NA_TCP;
			nsap.na_community = NSAPAddr::SUBNET_INTERNET;
			nsap.addr.na_tcp.na_tcp_port = port;
			nsap.addr.na_tcp.na_tcp_length = inetAddress.length();
			memcpy(nsap.addr.na_tcp.na_tcp_domain, inetAddress.addr(), inetAddress.length());
			nsap.addr.na_tcp.na_tcp_family = inetAddress.af();
		}
		
	}

	return e;
}
}
}
}
