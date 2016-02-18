#ifndef SelectorTest_INCLUDED
#define SelectorTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"

namespace ALS {
	namespace BASE {
		namespace ADDR {

			class SelectorTest :public CppUnit::TestCase
			{
			public:
				SelectorTest(const std::string& name);
				~SelectorTest();

				void testSelector();
				void testGet();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}
#endif
