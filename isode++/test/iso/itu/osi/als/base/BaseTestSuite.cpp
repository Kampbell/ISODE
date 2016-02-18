#include "BaseTestSuite.h"
#include "addr/AddrTestSuite.h"
#include "srvc/SrvcTestSuite.h"
#include "util/UtilTestSuite.h"


namespace ALS {
	namespace BASE {
			CppUnit::Test* BaseTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("BaseTestSuite");

				pSuite->addTest(ADDR::AddrTestSuite::suite());
				pSuite->addTest(SRVC::SrvcTestSuite::suite());
				pSuite->addTest(UTIL::UtilTestSuite::suite());

				return pSuite;
			}
	}
}
