/*
 * Selector.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

/*
RFC 1278:  A string encoding of Presentation Address S.E. Kille

<digit>					::= [0-9]
<other>					::= [0-9a-zA-Z+-.]
<domainchar>			::= [0-9a-zA-Z-.]
<hexdigit>				::= [0-9a-fA-F]
<hexoctet>				::= <hexdigit> <hexdigit>
<decimaloctet>			::= <digit> | <digit> <digit> | <digit> <digit> <digit>
<digitstring>			::= <digit> <digitstring> | <digit>
<otherstring>			::= <other> <otherstring> | <other>
<domainstring>			::= <domainchar> <otherstring> | <domainchar>
<hexstring>				::= <hexoctet> <hexstring> | <hexoctet>
<dotstring>				::= <decimaloctet> "." <dotstring> | <decimaloctet> "." <decimaloctet>
<dothexstring>			::= <dotstring> | <hexstring>
<presentation-address>	::= [[[ <psel> "/" ] <ssel> "/" ] <tsel> "/" ] <network-address-list>
<network-address-list>	::= <network-address> "_" <network-address-list> | <network-address>

<psel>					::= <selector>
<ssel>					::= <selector>
<tsel>					::= <selector>

<selector>				::= '"' <otherstring> '"'	-- IA5
													-- For chars not in this
													-- string use hex
						| "#" <digitstring>         -- US GOSIP
						| "'" <hexstring> "'H"      -- Hex
						| ""                        -- Empty but present
<network-address>		::= "NS" "+" <dothexstring>	-- Concrete Binary Representation
-- This is the compact encoding
| <afi> "+" <idi> [ "+" <dsp> ]	-- A user oriented form
| <idp> "+" <hexstring>			-- ISO 8348 Compatability

<idp>					::= <digitstring> -
<dsp>					::=
						| "d" <digitstring>          -- Abstract Decimal
						| "x" <dothexstring>         -- Abstract Binary
						| "l" <otherstring>          -- IA5:  local form only
						| "RFC-1006" "+" <prefix> "+" <ip> [ "+" <port> [ "+" <tset> ]]
						| "X.25(80)" "+" <prefix> "+" <dte> [ "+" <cudf-or-pid> "+" <hexstring> ]
						| "ECMA-117-Binary" "+" <hexstring> "+" <hexstring> "+" <hexstring>
						| "ECMA-117-Decimal" "+" <digitstring> "+" <digitstring> "+" <digitstring>

<idi>					::= <digitstring>
<afi>					::= "X121" | "DCC" | "TELEX" | "PSTN" | "ISDN" | "ICD" | "LOCAL"

<prefix>				::= <digit> <digit>

<ip>					::= <domainstring>			-- dotted decimal form (e.g., 10.0.0.6)
-- or domain (e.g., twg.com)
<port>					::= <digitstring>
<tset>					::= <digitstring>

<dte>					::= <digitstring>
<cudf-or-pid>			::= "CUDF" | "PID"


Examples:
"256"/NS+a433bb93c1_NS+aa3106
#63/#41/#12/X121+234219200300
'3a'H/TELEX+00728722+X.25(80)+02+00002340555+CUDF+"892796"
TELEX+00728722+RFC-1006+03+10.0.0.6


*/
#include <cstring>
#include <string>
#include "Poco/ByteOrder.h"
#include "als/base/addr/Selector.h"
#include "als/base/addr/AddressException.h"

using namespace std;
using Poco::ByteOrder;

namespace ALS {
namespace BASE {
namespace ADDR {

Selector::Selector() {
	memset(&value, 0, sizeof(value));
	length_ = 0;
	kind_ = UNKNOWN;
}
Selector::Selector(int cc, const byte* val) {
	if (cc > SIZE)
		throw new AddressException;
	if (cc == sizeof(value.number))
		kind_ = NUMBER;
	if (kind_ == NUMBER) {
		value.number = ByteOrder::fromNetwork(*(nat2*)val);
		length_ = sizeof(value.number);
	}
	else {
		memcpy(value.literal, val, length_ = cc);
	}
}

const char* Selector::parse(const char* addr) {
	if (addr != NULL) {
		const char* beg = addr;
		const char* end;
		int len;
		switch (*beg) {
		case '/':			// empty
			addr += 1;
			break;

		case '"':			// "256aaZZd"/
			end = strchr(++beg, '"');
			if (end == NULL) {
				// TODO invalid selector
				throw new exception();
			}
			len = end - beg;
			if (len > sizeof(value.literal)) {
				// TODO invalid selector
				throw new exception();
			}
			memcpy(value.literal, beg, length_ = len);
			addr = end + 1;
			kind_ = STRING;
			break;

		case '\'':			// '3a'H/
			end = strchr(++beg, '\'');
			if (end == NULL || *(end + 1) != 'H') {
				// invalid address
				throw new exception();
			}
			value.number = (unsigned short)strtol(beg, (char**)&end, 16);
			addr = end + 2;
			kind_ = NUMBER;
			length_ = sizeof(value.number);
			break;

		case '#':			// #132/
			beg += 1;
			value.number = (unsigned short)strtol(beg, (char**)&end, 10);
			addr = end;
			kind_ = NUMBER;
			length_ = sizeof(value.number);
			break;
		}
	}
	return addr;
}
Selector Selector::parse(const string& addr) {
	Selector selector;
	string	sub;
	if (!addr.empty()) {
		int pos = 0;
		switch(addr.at(pos)) {
		case '"': { // "otherstring"
			int quote = (int)addr.find('"', pos + 1);
			if (quote != string::npos) {
				selector.length_ = quote - pos - 1;
				memcpy(selector.value.literal, addr.c_str() + 1, selector.length_);
				selector.kind_ = STRING;
			}
			}
			break;

		case '#': {// #digits
			size_t slash;
			sub = addr.substr(pos + 1);
			selector.value.number = stoi(sub, &slash);
			selector.length_ = sizeof(short);
			selector.kind_ = NUMBER;
			}
			break;
		
		case '\'':  {// 'hexdigits'H
			size_t quote;
			sub = addr.substr(pos + 1);
			selector.value.number = stoi(sub, &quote, 16);
			if (sub[quote] != '\'') {
				throw new exception();
			}
			selector.length_ = sizeof(short);
			selector.kind_ = NUMBER;
			}
			break;
		}
	}
	return selector;
}


bool Selector::operator < (const Selector& other) const {
	switch(kind()) {
	case NUMBER:
		return number() < other.number();
	case UNKNOWN:
	case STRING:
		return memcmp(literal(), other.literal(), length()) < 0;
	}
}
}
}
}
