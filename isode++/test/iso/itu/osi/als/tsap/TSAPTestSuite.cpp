#include "TSAPTestSuite.h"
#include "prov/PROVTestSuite.h"
#include "tpdu/TPDUTestSuite.h"

namespace ALS {
	namespace TSAP {
			CppUnit::Test* TSAPTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TSAPTestSuite");

				pSuite->addTest(TPDU::TPDUTestSuite::suite());
				pSuite->addTest(PROV::PROVTestSuite::suite());

				return pSuite;
			}
	}
}
