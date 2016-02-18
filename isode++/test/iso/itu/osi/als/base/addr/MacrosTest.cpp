#include <iostream>
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "Poco/Net/IPAddress.h"
#include "Poco/Util/XMLConfiguration.h"
#include "Poco/SAX/SAXParser.h"

using Poco::XML::SAXParser;
using Poco::XML::XMLReader;
using Poco::XML::LexicalHandler;

#include "als/base/addr/Macros.h"
#include "als/base/srvc/AEISAXHandler.h"
using ALS::BASE::SRVC::AEISAXHandler;

#include "MacrosTest.h"
using namespace std;

/**
###############################################################################
#
# Syntax:
#
#	<macro>  <string>
#
#	Each token is separated by LWSP, though double-quotes may be
#	used to prevent separation
#
###############################################################################


# standard macros, defined in "A string encoding of Presentation Address"

Int-X25(80)			TELEX+00728722+X.25(80)+01+
Janet				TELEX+00728722+X.25(80)+02+
Internet-RFC-1006 	TELEX+00728722+RFC-1006+03+


# ISODE standard macros

X25(80)				TELEX+00728722+X.25(80)+
TCP					TELEX+00728722+RFC-1006+


# Interim Community Names

realNS				NS+
Int-X25				X25(80)=01+
# Janet				X25(80)=02+
Internet			TCP=03+
localTCP			TCP=05+
localhost			localTCP=127.0.0.1+
IXI					X25(80)=06+

NSAP				NS+

# US GOSIP v2 Addresses

us					NS+47000580
nsfnet  			us=ffff00
psinet				us=fffc00

# UK CONS addresses
UKNS				DCC+826+d
JanetNS				UKNS=11000
 */
/*
		////NS+a433bb93c1
		"256"/NS + a433bb93c1_NS + aa3106
		#63/#41 / #12 / X121 + 234219200300
		'3a'H/TELEX + 00728722 + X.25(80) + 02 + 00002340555 + CUDF + "892796"
*/

namespace ALS {
	namespace BASE {
		namespace ADDR {
			MacrosTest::MacrosTest(const std::string& name) : CppUnit::TestCase(name)
			{
			}


			MacrosTest::~MacrosTest()
			{
			}
			void MacrosTest::testMacros() {
				char* addr;
				string psapaddrs;
				Macros macro;

				cout << endl;
				{
					addr = "NSAP=102";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "NS+102");
				}
				{
					addr = "localhost=102+1234";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "TELEX+00728722+RFC-1006+05+127.0.0.1+102+1234");
				}
				{
					addr = "Int-X25=1029993";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "TELEX+00728722+X.25(80)+01+1029993");
				}
				{
					addr = "NS+a433bb93c1";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "NS+a433bb93c1");
				}
				{
					addr = "X121+234219200300";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "X121+234219200300");
				}
				{
					addr = "TELEX+00728722+X.25(80)+02+00002340555+CUDF+\"892796\"";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "TELEX+00728722+X.25(80)+02+00002340555+CUDF+\"892796\"");
				}
				{
					addr = "TELEX+00728722+RFC-1006+03+10.0.0.6";
					string expanded = macro.expand(addr);
					poco_assert(expanded == "TELEX+00728722+RFC-1006+03+10.0.0.6");
//					cout << expanded << endl;
				}
			}
			void MacrosTest::setUp() {
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
			void MacrosTest::tearDown() {

			}
			CppUnit::Test* MacrosTest::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("MacrosTest");

				CppUnit_addTest(pSuite, MacrosTest, testMacros);

				return pSuite;
			}
		}
	}
}
