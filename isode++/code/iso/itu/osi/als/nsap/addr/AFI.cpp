/*
 * AFI.cpp
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */
#include "als/nsap/addr/AFI.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

	const string&	AFI::asstring() const {
		if (string_.empty()) {
			string_ += name_; string_ += ':';
			string_ += dec0_; string_ += ':';
			string_ += hex0_; string_ += ':';
			string_ += dec1_; string_ += ':';
			string_ += hex1_; string_ += ':';
			string_ += ia5_; string_ += ':';
			string_ += std::to_string(idi_len_); string_ += ':';
			string_ += std::to_string(dec_dslen_); string_ += ':';
			string_ += std::to_string(hex_dslen_);
		}

		return string_;
	}


}
}
}
