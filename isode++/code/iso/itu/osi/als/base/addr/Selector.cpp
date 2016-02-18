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
		}
		Selector::Selector(nat2 port) {
			memset(&value, 0, sizeof(value));
			value.number = ByteOrder::toNetwork(port);
			sl_length = sizeof(value.number);
			sl_kind = NUMBER;
			sl_present = true;
		}
		Selector::Selector(int cc, const byte* val) {
			if (cc > SIZE)
				throw  AddressException();
			if (cc == sizeof(value.number))
				sl_kind = NUMBER;
			if (sl_kind == NUMBER) {
				value.number = *(nat2*)val;	// val must be in Network Order
				sl_length = sizeof(value.number);
			}
			else {
				memcpy(value.literal, val, sl_length = cc);
			}
			sl_present = true;
		}
		Selector::Selector(const Selector& selector) {
			memcpy(&value, (const void*)&selector.value, sizeof(value));
			sl_length = selector.length();
			sl_kind = selector.kind();
			sl_present = selector.isPresent();
		}
		Selector&	Selector::operator = (const Selector& selector) {
			memcpy(&value, (const void*)&selector.value, sizeof(value));
			sl_length = selector.length();
			sl_kind = selector.kind();
			sl_present = selector.isPresent();
			return *this;
		}
		const char* Selector::parse(const char* addr) {
			if (addr != nullptr) {
				const char* beg = addr;
				const char* end;
				int len;
				switch (*beg) {
				case '/':			// empty
					sl_present = true;
					addr += 1;
					break;

				case '"':			// "256aaZZd"/
					sl_present = true;
					end = strchr(++beg, '"');
					if (end == nullptr) {
						// TODO invalid selector
						throw  exception();
					}
					len = end - beg;
					if (len > sizeof(value.literal)) {
						// TODO invalid selector
						throw  exception();
					}
					memcpy(value.literal, beg, sl_length = len);
					addr = end + 2;
					sl_kind = STRING;
					break;

				case '\'':			// '3a'H/
					sl_present = true;
					end = strchr(++beg, '\'');
					if (end == nullptr || *(end + 1) != 'H') {
						// invalid address
						throw  exception();
					}
					value.number = ByteOrder::toNetwork((unsigned short)strtol(beg, (char**)&end, 16));
					sl_kind = NUMBER;
					sl_length = sizeof(value.number);
					addr = end + 3;
					break;

				case '#':			// #132/
					sl_present = true;
					beg += 1;
					value.number = ByteOrder::toNetwork((unsigned short)strtol(beg, (char**)&end, 10));
					sl_kind = NUMBER;
					sl_length = sizeof(value.number);
					addr = end + 1;
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
				switch (addr.at(pos)) {
				case '"': { // "otherstring"
					selector.sl_present = true;
					int quote = (int)addr.find('"', pos + 1);
					if (quote != string::npos) {
						selector.sl_length = quote - pos - 1;
						memcpy(selector.value.literal, addr.c_str() + 1, selector.sl_length);
						selector.sl_kind = STRING;
					}
				}
					break;

				case '#': {// #digits
					selector.sl_present = true;
					size_t slash = 0;
					sub = addr.substr(pos + 1);
					nat2 value = stoi(sub, &slash);
					selector.value.number = ByteOrder::toNetwork(value);
					selector.sl_length = sizeof(short);
					selector.sl_kind = NUMBER;
				}
					break;

				case '\'':  {// 'hexdigits'H
					selector.sl_present = true;
					size_t quote = 0;
					sub = addr.substr(pos + 1);
					nat2 value = stoi(sub, &quote, 16);
					selector.value.number = ByteOrder::toNetwork(value);
					if (sub[quote] != '\'') {
						throw  exception();
					}
					selector.sl_length = sizeof(short);
					selector.sl_kind = NUMBER;
				}
					break;
				}
			}
			return selector;
		}

		bool Selector::operator < (const Selector& other) const {
			switch (kind()) {
			case NUMBER:
				return number() < other.number();
			case STRING:
				return memcmp(literal(), other.literal(), length()) < 0;
			case EMPTY:
				return this < &other;
			}
		}
		
		const string&	Selector::to_string() const {
			if (sl_string.empty()) {
				switch (kind()) {
				case NUMBER:
					sl_string += '#';
					sl_string += std::to_string(number());
					break;
				case STRING:
					sl_string += std::string((const char*)literal(), length());
					break;
				default:
					break;
				}
				sl_string += '/';
			}
			return sl_string;
		}
	}
}
}
