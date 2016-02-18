#include <iostream>
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "als/tsap/tpdu/CR.h"

#include "TPDUTest.h"
using namespace std;

namespace ALS {
	namespace TSAP {
		namespace TPDU {
			TPDUTest::TPDUTest(const std::string& name) :
				CppUnit::TestCase(name)
			{
			}


			TPDUTest::~TPDUTest()
			{
			}
			void TPDUTest::testCR() {
				CR cr;
				cr.srcref(0);
				cr.dstref(0);
			}
			void TPDUTest::setUp() {
			}
			void TPDUTest::tearDown() {

			}
			CppUnit::Test* TPDUTest::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TPDUTest");

				CppUnit_addTest(pSuite, TPDUTest, testCR);

				return pSuite;
			}
		}
	}
}
