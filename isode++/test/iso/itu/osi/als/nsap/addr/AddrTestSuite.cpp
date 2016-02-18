#include "AddrTestSuite.h"
#include "PSAPAddrTest.h"


namespace ALS {
	namespace NSAP {
		namespace ADDR {
			CppUnit::Test* AddrTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AddrTestSuite");

				pSuite->addTest(PSAPAddrTest::suite());

				return pSuite;
			}
		}
	}
}
 