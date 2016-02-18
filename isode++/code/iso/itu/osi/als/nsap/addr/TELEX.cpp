/*
 * TELEX.cpp
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#include "als/nsap/addr/DSP.h"
#include "als/nsap/addr/TELEX.h"
#include "als/nsap/addr/RFC_1006.h"
#include "als/nsap/addr/X2580.h"
#include "als/nsap/addr/ECMA117Binary.h"
#include "als/nsap/addr/ECMA117Decimal.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/base/addr/AddressException.h"

using ALS::BASE::ADDR::AddressException;

namespace ALS {
namespace NSAP {
namespace ADDR {
//
//	'3a'H/TELEX+00728722+X.25(80)+02+00002340555+CUDF+"892796"
//	TELEX+00728722+RFC-1006+03+10.0.0.6
	static const DSP* DSPs[] = {
		new RFC_1006(),
		new X2580(),
		new ECMA117Binary(),
		new ECMA117Decimal()
	};
	const char* TELEX::parse(NSAPAddr& nsap, const char* address) const {
		const char* b = address;
		const char* e = nullptr;
		if (memcmp(name().c_str(), address, name().length()) != 0)
			throw InvalidArgumentException();

		b += name().length();
		if (*b != '+') {
			throw AddressException("Invalid TELEX address");
		}
		e = strchr(++b, '+');
		if (e == nullptr || e - b > 8) {
			throw AddressException("Invalid TELEX address");
		}
		b = e + 1; e = b;
		const DSP* dsp = nullptr;
		for (int no = 0; no < sizeof(DSPs) / sizeof(DSPs[0]); no++) {
			dsp = DSPs[no];
			string s(b, dsp->name().length());
			if (s == dsp->name())
				break;
			dsp = nullptr;
		}
		if (dsp == nullptr)
			throw AddressException();
		return dsp->parse(nsap, b);
	}
}
}
}
