/*
 * PSAPAddr.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#include <string>
#include <memory>
#include "als/base/addr/Macros.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/nsap/addr/AFI.h"
#include "als/nsap/addr/X121.h"
#include "als/nsap/addr/DCC.h"
#include "als/nsap/addr/TELEX.h"
#include "als/nsap/addr/PSTN.h"
#include "als/nsap/addr/ISDN.h"
#include "als/nsap/addr/ICD.h"
#include "als/nsap/addr/LOCAL.h"

using std::string;
using std::auto_ptr;

namespace ALS {
namespace NSAP {
namespace ADDR {

NSAP_API Macros	MACROS;

void PSAPAddr::parse(const char* address) {
	Selector selectors[3];
	int selectlen = 0;
	const char* sel = address;

	enum SELECTOR {
		PS_INIT = 0,	/* <selector> or <network-address> */
		PS_SEL1 = 1,	/* .. got one selector already */
		PS_SEL2 = 2,	/* .. got two selectors already */
		PS_SEL3 = 3		/* <network-address> */
	};


	for (SELECTOR state = PS_INIT; state != PS_SEL3;) {
		Selector selector;
		sel = selector.parse(sel);
		switch (state) {
		case PS_INIT:
			selectors[0] = selector; state = PS_SEL1;
			break;
		case PS_SEL1:
			selectors[1] = selector; state = PS_SEL2;
			break;
		case PS_SEL2:
			selectors[2] = selector; state = PS_SEL3;
			break;
		case PS_SEL3:
			break;
		}
	}
	string expanded = MACROS.expand(sel);
	address = pa_addr.parse(expanded.c_str());
	poco_assert(*address == 0);

	if (selectors[2].isPresent()) { // PSEL + SSEL + TSEL
		pa_selector = selectors[0];
		pa_selectlen = selectors[0].length();
		pa_addr.sa_selector = selectors[1];
		pa_addr.sa_selectlen = selectors[1].length();
		pa_addr.sa_addr.ta_selector = selectors[2];
		pa_addr.sa_addr.ta_selectlen = selectors[2].length();
	}
	else if (selectors[1].isPresent()) { // SSEL + TSEL
		pa_addr.sa_selector = selectors[0];
		pa_addr.sa_selectlen = selectors[0].length();
		pa_addr.sa_addr.ta_selector = selectors[1];
		pa_addr.sa_addr.ta_selectlen = selectors[1].length();
	}
	else if (selectors[0].isPresent()) { // TSEL
		pa_addr.sa_addr.ta_selector = selectors[0];
		pa_addr.sa_addr.ta_selectlen = selectors[0].length();
	}

}
	const string& PSAPAddr::to_string() const {
		if (sa_string.empty()) {
			if (selector().isPresent()) {
				sa_string += selector().to_string();
			}
			sa_string += pa_addr.to_string();
		}
		return sa_string;
	}

}
}
}
