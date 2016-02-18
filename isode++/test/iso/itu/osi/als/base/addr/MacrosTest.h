#ifndef MacrosTest_INCLUDED
#define MacrosTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ALS {
	namespace BASE {
		namespace ADDR {

			class MacrosTest : public CppUnit::TestCase	{
			public:
				MacrosTest(const std::string& name);
				~MacrosTest();

				void testMacros();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}
#endif

