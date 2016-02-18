/*
 * NSAPAddr.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#include "Poco/Net/IPAddress.h"
#include "als/base/addr/AddressException.h"
#include "als/base/addr/Macros.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/addr/AFI.h"
#include "als/nsap/addr/X121.h"
#include "als/nsap/addr/DCC.h"
#include "als/nsap/addr/TELEX.h"
#include "als/nsap/addr/PSTN.h"
#include "als/nsap/addr/ISDN.h"
#include "als/nsap/addr/ICD.h"
#include "als/nsap/addr/LOCAL.h"
#include "als/nsap/addr/IANA.h"
#include "als/nsap/addr/ATM.h"

using Poco::Net::IPAddress;
using ALS::BASE::ADDR::Macros;

namespace ALS {
namespace NSAP {
namespace ADDR {
	const Macros	macros;

	/*
					d0    h0	d1    h1   ia5 idi decds hexds
	IANA ("IANA",  "34", "35",   "",   "",  "",  6, 34,  17),
	X121 ("X121",  "36", "37", "52", "53",  "", 14, 24,  12),
	DCC  ("DCC",   "38", "39",   "",   "",  "",  3, 35, 17),
	TELEX("TELEX", "40", "41", "54", "55",  "",  8, 30, 15),
	PSTN ("PSTN",  "42", "43", "56", "57",  "", 12, 26, 13),
	ISDN ("ISDN",  "44", "45", "58", "59",  "", 15, 23,  11),
	ICD  ("ICD",   "46", "47",   "",   "",  "",  4, 34, 17),
	LOCAL("LOCAL", "48", "49",   "",   "", "50", 0, 38, 19),
	ATM  ("ATM",   "76", "77",   "",   "",   "", 6, 32, 16),

	*/

	const AFI* AFIs[] = {
		new IANA("IANA", "34", "35", "", "", "", 6, 24, 9),
		new X121("X121", "36", "37", "52", "53", "", 14, 24, 12),
		new DCC("DCC", "38", "39", "", "", "", 3, 35, 17),
		new TELEX("TELEX", "40", "41", "54", "55", "", 8, 30, 15),
		new PSTN("PSTN", "42", "43", "56", "57", "", 12, 26, 13),
		new ISDN("ISDN", "44", "45", "58", "59", "", 15, 23, 11),
		new ICD("ICD", "46", "47", "", "", "", 4, 34, 17),
		new LOCAL("LOCAL", "48", "49", "", "", "50", 0, 38, 19),
		new ATM("ATM", "48", "49", "", "", "", 6, 38, 19)
	}; 

	const char* NSAPAddr::parse(const char* address) {
		const char* network = address;
		//NS == Concrete Binary Representation: compact encoding
		if (*network != 'N' && *(network + 1) != 'S') {
			string expanded = macros.expand(network);
			const AFI* afi = nullptr;
			for (int afino = 0; afino < sizeof(AFIs) / sizeof(AFIs[0]); afino++) {
				afi = AFIs[afino];
				if (expanded.substr(0, afi->name().length()) == (afi->name())) {
					break;
				}
				afi = nullptr;
			}
			if (afi == nullptr)			// no AFI found ISO 8348 compatibility
				return network;
			network = afi->parse(*this, network);
			return network;

		}
	}
	const string& NSAPAddr::to_string() const {
		switch (stack()) {
		case NA_NSAP:
			na_string = "nsap";
			break;
		case NA_TCP: {
			IPAddress inetadress(tcp_domain(), tcp_length());
			na_string = inetadress.toString();
		}
			break;
		case NA_X25:
			na_string = "x25";
			break;
		}
		return na_string;
}

}
}
}
