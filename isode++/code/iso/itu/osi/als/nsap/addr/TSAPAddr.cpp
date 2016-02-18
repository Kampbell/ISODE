/*
 * TSAPAddr.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#include "als/NSAP/addr/TSAPAddr.h"

namespace ALS {
namespace NSAP {
namespace ADDR {
const char* TSAPAddr::parse(const char* address) {
	address = ta_addrs[ta_naddr].parse(address); ta_naddr += 1;
	return address;
}

const string& TSAPAddr::to_string() const {
	if (ta_string.empty()) {
		if (selector().isPresent()) {
			ta_string += selector().to_string();
		}
		for (int no = 0; no < size(); no++) {
			ta_string += ta_addrs[no].to_string();
			if (no < size() - 1)
				ta_string += '|';
		}
	}
	return ta_string;
}

}
}
}
