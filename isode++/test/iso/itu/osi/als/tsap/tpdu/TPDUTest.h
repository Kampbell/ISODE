#ifndef TPDUTest_INCLUDED
#define TPDUTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"


namespace ALS {
	namespace TSAP {
		namespace TPDU {

			class TPDUTest : public CppUnit::TestCase	{
			private:

			public:
				TPDUTest(const std::string& name);
				~TPDUTest();

				void testCR();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}
#endif

