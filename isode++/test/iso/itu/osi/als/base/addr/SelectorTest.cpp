#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "als/base/addr/Selector.h"
#include "SelectorTest.h"


namespace ALS {
	namespace BASE {
		namespace ADDR {
			SelectorTest::SelectorTest(const std::string& name) : CppUnit::TestCase(name)
			{
			}


			SelectorTest::~SelectorTest()
			{
			}
			void SelectorTest::testSelector() {
				const char* p;
				{
					Selector selector;
					p = selector.parse("///NS+a433bb93c1");
					poco_assert(*p == '/');
					poco_assert(selector.length() == 0);

					p = selector.parse("#124/NS");
					poco_assert(*p == 'N');
					poco_assert(selector.length() == 2);
					poco_assert(selector.number() == 124);

					p = selector.parse("\"abc\"/NS");
					poco_assert(*p == 'N');
					poco_assert(selector.length() == 3);
					poco_assert(memcmp(selector.literal(), "abc", selector.length()) == 0);

					p = selector.parse("'3a'H/NS");
					poco_assert(*p == 'N');
					poco_assert(selector.length() == 2);
					poco_assert(selector.number() == 58);
				}
				{
					Selector selector;
					string sel;
					sel = string("#132");
					selector = Selector::parse(sel);
					poco_assert(selector.number() == 132);
					poco_assert(selector.length() == 2);

					sel = string("'10'H");
					selector = Selector::parse(sel);
					poco_assert(selector.number() == 16);
					poco_assert(selector.length() == 2);

					sel = string("\"ab12\"");
					selector = Selector::parse(sel);
					poco_assert(selector.length() == 4);
					poco_assert(memcmp(selector.literal(), "ab12", selector.length()) == 0);
				}

			}
			void SelectorTest::testGet() {

			}

			void SelectorTest::setUp() {

			}
			void SelectorTest::tearDown() {

			}
			CppUnit::Test* SelectorTest::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SelectorTest");

				CppUnit_addTest(pSuite, SelectorTest, testSelector);
				CppUnit_addTest(pSuite, SelectorTest, testGet);

				return pSuite;
			}
		}
	}
}
