#ifndef PSAPAddrTest_INCLUDED
#define PSAPAddrTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ALS {
	namespace NSAP {
		namespace ADDR {

			class PSAPAddrTest : public CppUnit::TestCase	{
			public:
				PSAPAddrTest(const std::string& name);
				~PSAPAddrTest();
				
				void testX25_80Parsing();
				void testTELEXParsing();
				void testX121Parsing();
				void testRFC1006Parsing();
				void testIANAParsing();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}
#endif

