/*
 * SSAPAddr.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#include "als/NSAP/addr/SSAPAddr.h"
#include "als/NSAP/addr/AFI.h"

namespace ALS {
namespace NSAP {
namespace ADDR {
	const char* SSAPAddr::parse(const char* address) {
		return sa_addr.parse(address);
	}
	const string& SSAPAddr::to_string() const {
		if (sa_string.empty()) {
			if (selector().isPresent()) {
				sa_string += selector().to_string();
			}
			sa_string += sa_addr.to_string();
		}
		return sa_string;
	}

}
}
}
