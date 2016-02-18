#include <iostream>
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "Poco/Net/IPAddress.h"
#include "Poco/Util/XMLConfiguration.h"
#include "Poco/SAX/SAXParser.h"

using Poco::XML::SAXParser;
using Poco::XML::XMLReader;
using Poco::XML::LexicalHandler;

#include "als/base/srvc/AEISAXHandler.h"
using ALS::BASE::SRVC::AEISAXHandler;

#include "als/nsap/addr/PSAPAddr.h"
#include "PSAPAddrTest.h"
using namespace std;

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

namespace ALS {
	namespace NSAP {
		namespace ADDR {
			PSAPAddrTest::PSAPAddrTest(const std::string& name) : CppUnit::TestCase(name)
			{
			}


			PSAPAddrTest::~PSAPAddrTest()
			{
			}
			void PSAPAddrTest::testX25_80Parsing() {
				char* addr = "'3a'H/TELEX+00728722+X.25(80)+02+00002340555+CUDF+\"892796\"";
			}
			void PSAPAddrTest::testTELEXParsing() {
				char* addr = "#63/#41/#12/X121+234219200300";
			}
			void PSAPAddrTest::testX121Parsing() {
				char* addr = "#63/#41/#12/X121+234219200300";
			}
			void PSAPAddrTest::testRFC1006Parsing() {
				char* addr;
				addr = "\"256\"/NS+a433bb93c1_NS+aa3106";
				string psapaddrs;
				cout << endl;
				{
					addr = "TELEX+00728722+RFC-1006+03+127.0.0.1+504+456";
					addr = "localhost=504+456";
					PSAPAddr psapaddr;
					psapaddr.parse(addr);
					psapaddrs = psapaddr.to_string();
					poco_assert(psapaddrs == "127.0.0.1");

					const SSAPAddr& ssapaddr = psapaddr.ssapaddr();
					const TSAPAddr& tsapaddr = ssapaddr.tsapaddr();
					const NSAPAddr& nsapaddr = tsapaddr.nsapaddr(0);
					
					poco_assert(!psapaddr.selector().isPresent());
					poco_assert(!ssapaddr.selector().isPresent());
					poco_assert(!tsapaddr.selector().isPresent());
					
					poco_assert(nsapaddr.tcp_port() == 504);
					poco_assert(nsapaddr.tcp_family() == AF_INET);
					poco_assert(nsapaddr.tcp_length() == 4);
					struct  {byte b0;byte b1;byte b2;byte b3;} bytes = { 127, 0, 0, 1 };
					poco_assert(memcmp(nsapaddr.tcp_domain(), &bytes, nsapaddr.tcp_length()) == 0);
				}
				{
					addr = "#128/TELEX+00728722+RFC-1006+05+10.0.0.6";
					addr = "#128/localTCP=10.0.0.6";
					PSAPAddr psapaddr;
					psapaddr.parse(addr);
					psapaddrs = psapaddr.to_string();
					poco_assert(psapaddrs == "#128/10.0.0.6");

					const SSAPAddr& ssapaddr = psapaddr.ssapaddr();
					const TSAPAddr& tsapaddr = ssapaddr.tsapaddr();
					const NSAPAddr& nsapaddr = tsapaddr.nsapaddr(0);

					poco_assert(!psapaddr.selector().isPresent());
					poco_assert(!ssapaddr.selector().isPresent());
					poco_assert(tsapaddr.selector().isPresent());
					poco_assert(tsapaddr.selector().isNotNull());
					poco_assert(tsapaddr.selector().kind() == Selector::NUMBER);
 					poco_assert(tsapaddr.selector().number() == 128);
					poco_assert(tsapaddr.selector().to_string() == "#128/");

					poco_assert(nsapaddr.tcp_port() == 102);
					poco_assert(nsapaddr.tcp_family() == AF_INET);
					poco_assert(nsapaddr.tcp_length() == 4);
					struct  {byte b0;byte b1;byte b2;byte b3;} bytes = { 10, 0, 0, 6 };
					const byte*p0 = nsapaddr.tcp_domain();
					const byte*p1 = ++p0;
					const byte*p2 = ++p1;
					const byte*p3 = ++p2;
					poco_assert(memcmp(nsapaddr.tcp_domain(), &bytes, nsapaddr.tcp_length()) == 0);
				}
				{
					addr = "#128//TELEX+00728722+RFC-1006+03+10.0.0.6";
					addr = "#128//localTCP=10.0.0.6";
					PSAPAddr psapaddr;
					psapaddr.parse(addr);
					
					psapaddrs = psapaddr.to_string();
					poco_assert(psapaddrs == "#128//10.0.0.6");

					const SSAPAddr& ssapaddr = psapaddr.ssapaddr();
					const TSAPAddr& tsapaddr = ssapaddr.tsapaddr();
					const NSAPAddr& nsapaddr = tsapaddr.nsapaddr(0);

					poco_assert(!psapaddr.selector().isPresent());

					poco_assert(ssapaddr.selector().isPresent());
					poco_assert(ssapaddr.selector().isNotNull());
					poco_assert(ssapaddr.selector().kind() == Selector::NUMBER);
 					poco_assert(ssapaddr.selector().number() == 128);
					poco_assert(ssapaddr.selector().to_string() == "#128/");

					poco_assert(tsapaddr.selector().isPresent());
					poco_assert(tsapaddr.selector().isNull());
					poco_assert(tsapaddr.selector().to_string() == "/");

					poco_assert(nsapaddr.tcp_port() == 102);
					poco_assert(nsapaddr.tcp_family() == AF_INET);
					poco_assert(nsapaddr.tcp_length() == 4);
					struct  {byte b0;byte b1;byte b2;byte b3;} bytes = { 10, 0, 0, 6 };
					poco_assert(memcmp(nsapaddr.tcp_domain(), &bytes, nsapaddr.tcp_length()) == 0);
				}
				{
					addr = "#128///TELEX+00728722+RFC-1006+03+10.0.0.6";
					addr = "#128///localTCP=10.0.0.6";
					PSAPAddr psapaddr;
					psapaddr.parse(addr);

					psapaddrs = psapaddr.to_string();
					poco_assert(psapaddrs == "#128///10.0.0.6");

					const SSAPAddr& ssapaddr = psapaddr.ssapaddr();
					const TSAPAddr& tsapaddr = ssapaddr.tsapaddr();
					const NSAPAddr& nsapaddr = tsapaddr.nsapaddr(0);

					poco_assert(psapaddr.selector().isPresent());
					poco_assert(psapaddr.selector().isNotNull());
					poco_assert(psapaddr.selector().kind() == Selector::NUMBER);
 					poco_assert(psapaddr.selector().number() == 128);
					poco_assert(psapaddr.selector().to_string() == "#128/");

					poco_assert(ssapaddr.selector().isPresent());
					poco_assert(ssapaddr.selector().isNull());
					poco_assert(ssapaddr.selector().to_string() == "/");

					poco_assert(tsapaddr.selector().isPresent());
					poco_assert(tsapaddr.selector().isNull());
					poco_assert(tsapaddr.selector().to_string() == "/");

					poco_assert(nsapaddr.tcp_port() == 102);
					poco_assert(nsapaddr.tcp_family() == AF_INET);
					poco_assert(nsapaddr.tcp_length() == 4);
					struct  {byte b0;byte b1;byte b2;byte b3;} bytes = { 10, 0, 0, 6 };
					poco_assert(memcmp(nsapaddr.tcp_domain(), &bytes, nsapaddr.tcp_length()) == 0);
				}

				{
					addr = "///TELEX+00728722+RFC-1006+03+10.0.0.6+102";
					PSAPAddr psapaddr;
					psapaddr.parse(addr);

					psapaddrs = psapaddr.to_string();
					poco_assert(psapaddrs == "///10.0.0.6");

					const SSAPAddr& ssapaddr = psapaddr.ssapaddr();
					const TSAPAddr& tsapaddr = ssapaddr.tsapaddr();
					const NSAPAddr& nsapaddr = tsapaddr.nsapaddr(0);

					poco_assert(psapaddr.selector().isPresent());
					poco_assert(psapaddr.selector().isNull());

					poco_assert(ssapaddr.selector().isPresent());
					poco_assert(ssapaddr.selector().isNull());

					poco_assert(tsapaddr.selector().isPresent());
					poco_assert(tsapaddr.selector().isNull());

					poco_assert(nsapaddr.tcp_port() == 102);
					poco_assert(nsapaddr.tcp_family() == AF_INET);
					poco_assert(nsapaddr.tcp_length() == 4);
					struct  {byte b0;byte b1;byte b2;byte b3;} bytes = { 10, 0, 0, 6 };
					poco_assert(memcmp(nsapaddr.tcp_domain(), &bytes, nsapaddr.tcp_length()) == 0);
				}
			}
			void PSAPAddrTest::testIANAParsing() {
				char* addr;
				addr = "IANA+IPv4+10.3.1.4+314";
			}
			void PSAPAddrTest::setUp() {
#if 0
//
// Macros are defined for now by the Macro constructor
//
				AEISAXHandler handler;
				SAXParser parser;

				parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
				parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
				parser.setContentHandler(&handler);
				parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER,	static_cast<LexicalHandler*>(&handler));

				parser.parse("../../../../../../test/iso/itu/osi/als/base/addr/Macros.xml");
#endif
			}
			void PSAPAddrTest::tearDown() {

			}
			CppUnit::Test* PSAPAddrTest::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("PSAPAddrTest");

				CppUnit_addTest(pSuite, PSAPAddrTest, testRFC1006Parsing);
				CppUnit_addTest(pSuite, PSAPAddrTest, testIANAParsing);

				return pSuite;
			}
		}
	}
}
