#include "AddrTestSuite.h"
#include "SelectorTest.h"
#include "MacrosTest.h"


namespace ALS {
	namespace BASE {
		namespace ADDR {
			CppUnit::Test* AddrTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AddrTestSuite");

				pSuite->addTest(SelectorTest::suite());
				pSuite->addTest(MacrosTest::suite());

				return pSuite;
			}
		}
	}
}
 