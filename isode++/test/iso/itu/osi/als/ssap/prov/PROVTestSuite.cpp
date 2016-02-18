#include "PROVTestSuite.h"
#include "ProviderTest.h"


namespace ALS {
	namespace TSAP {
		namespace PROV {
			CppUnit::Test* PROVTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("PROVTestSuite");

				pSuite->addTest(ProviderTest::suite());

				return pSuite;
			}
		}
	}
}
 