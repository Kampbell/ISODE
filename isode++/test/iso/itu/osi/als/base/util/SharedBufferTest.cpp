/*
 * SharedBufferTest.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Buffer.h"
using namespace Poco;

#include "als/base/util/SharedNetworkBuffer.h"
#include "SharedBufferTest.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {
			void SharedBufferTest::set(SharedNetworkBuffer& nsdu) {
				csb = nsdu;
				poco_assert(csb.total() == nsdu.total());
			}
			void SharedBufferTest::append(SharedNetworkBuffer& nsdu) {
				nat4 remain = csb.total();
				csb.append(nsdu);
				poco_assert(csb.total() == nsdu.total() + remain);
			}
			void SharedBufferTest::use() {
				const SharedNetworkBuffer* buffer = &csb;
				for (;;) {
					if (!buffer) break;
					cout << "use: " << (*buffer)->data() << endl;
					buffer = buffer->next();
				}
			}
			void SharedBufferTest::del() {
				csb.reset();
				poco_assert(csb.count() == 0);
			}
			SharedBufferTest::SharedBufferTest(const std::string& name) : CppUnit::TestCase(name) {
				delete b1;
				delete b2;
				delete b3;
				delete b4;
			}
			SharedBufferTest::~SharedBufferTest() {
			}
			void SharedBufferTest::testSharedBuffer() {
				cout << endl;
				SharedNetworkBuffer sb;
				b1 = new NetworkBuffer(32);
				{
					b1->putBytes(7, "azerty");
					b1->flip();
					b1->position() = 1;
					sb = SharedNetworkBuffer(b1);
					poco_assert(sb.count() == 1);
					set(sb);
					poco_assert(sb.count() == 2);
					poco_assert(csb.count() == 2);
				}
				cout << "csb.count(1)=" << csb.count() << endl;
				poco_assert(sb.count() == 2);
				b2 = new NetworkBuffer(32);
				{
					b2->putBytes(7, "abcdef");
					b2->flip();
					b2->position() = 2;
					sb = SharedNetworkBuffer(b2);
					poco_assert(sb.count() == 1);
					append(sb);
				}
				cout << "csb.count(2)=" << csb.count() << endl;
				b3 = new NetworkBuffer(32);
				{
					b3->putBytes(7, "123456");
					b3->flip();
					b3->position() = 3;
					sb = SharedNetworkBuffer(b3);
					poco_assert(sb.count() == 1);
					append(sb);
				}
				cout << "csb.count(3)=" << csb.count() << endl;
				poco_assert(csb.count() == 1);
				b4 = new NetworkBuffer(32);
				{
					b4->putBytes(7, "poiuyt");
					b4->flip();
					b4->position() = 4;
					sb = SharedNetworkBuffer(b4);
					poco_assert(sb.count() == 1);
					append(sb);
				}
				cout << "csb.count(4)=" << csb.count() << endl;
				poco_assert(csb.count() == 1);
			}
			void SharedBufferTest::setUp() {
			}
			void SharedBufferTest::tearDown() {
				cout << "csb.count(5)=" << csb.count() << endl;
				use();
				// zerty
				// cdef
				// 456
				// yt
				const SharedNetworkBuffer* sb = &csb;
				poco_assert(string((*sb)->data(), 2) == "ze");
				poco_assert(string((*sb->next())->data(), 2) == "cd");
				poco_assert(string((*sb->next()->next())->data(), 2) == "45");
				poco_assert(string((*sb->next()->next()->next())->data(), 2) == "yt");
				poco_assert(!sb->next()->next()->next()->next());

				nat4 size = 0;
				for (SharedNetworkBuffer::iterator sbi = csb.begin(); sbi != csb.end(); ++sbi) {
					cout << string((*sbi)->data(), 2) << endl;
					size += (*sbi)->remaining();
				}
				poco_assert(csb.total() == size);
				del();
			}
			CppUnit::Test* SharedBufferTest::suite() {
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SharedBufferTest");
				CppUnit_addTest(pSuite, SharedBufferTest, testSharedBuffer);
				return pSuite;
			}

		}
	}
}
