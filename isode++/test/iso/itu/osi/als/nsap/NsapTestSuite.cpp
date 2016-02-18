#include "NsapTestSuite.h"
#include "addr/AddrTestSuite.h"


namespace ALS {
	namespace NSAP {
			CppUnit::Test* NsapTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("NsapTestSuite");

				pSuite->addTest(ADDR::AddrTestSuite::suite());

				return pSuite;
			}
	}
}
