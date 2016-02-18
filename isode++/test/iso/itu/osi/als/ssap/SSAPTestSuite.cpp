#include "SSAPTestSuite.h"
#include "prov/PROVTestSuite.h"
#include "tpdu/TpduTestSuite.h"

namespace ALS {
	namespace TSAP {
			CppUnit::Test* SSAPTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SSAPTestSuite");

				pSuite->addTest(PROV::PROVTestSuite::suite());

				return pSuite;
			}
	}
}
