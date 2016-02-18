/*
 * PSAPAddr.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_ADDR_PSAPAddr_H_
#define ALS_NSAP_ADDR_PSAPAddr_H_

#include "als/base/addr/Selector.h"
#include "als/nsap/addr/SSAPAddr.h"
#include "als/base/addr/Macros.h"
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


"256"/NS+a433bb93c1_NS+aa3106
#63/#41/#12/X121+234219200300
'3a'H/TELEX+00728722+X.25(80)+02+00002340555+CUDF+"892796"
TELEX+00728722+RFC-1006+03+10.0.0.6


*/
using ALS::BASE::ADDR::Macros;

namespace ALS {
namespace NSAP {
namespace ADDR {

	class NSAP_API PSAPAddr {
	private:
		mutable string	sa_string;

	public:
		static const int		PSSIZE = 64;

		SSAPAddr				pa_addr;				// session address 
		int						pa_selectlen;
		Selector				pa_selector;			// [PSSIZE]; /* PSAP

	public:
		PSAPAddr() {
		}
		~PSAPAddr() {
		}
		void parse(const char* address);
		const Selector& selector() const { return pa_selector; }
		const SSAPAddr& ssapaddr() const { return pa_addr; }
		const string& to_string() const;
	};

}
}
}

#endif
