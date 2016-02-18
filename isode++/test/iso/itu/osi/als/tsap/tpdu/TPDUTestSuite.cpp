#include "TPDUTestSuite.h"
#include "TPDUTest.h"


namespace ALS {
	namespace TSAP {
		namespace TPDU {
			CppUnit::Test* TPDUTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TPDUTestSuite");

				pSuite->addTest(TPDUTest::suite());

				return pSuite;
			}
		}
	}
}
 