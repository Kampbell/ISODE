/*
 * BufferPtrTest.cpp
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

#include "als/base/util/Buffer.h"
#include "BufferPtrTest.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {
			void BufferPtrTest::set(const SharedBuffer& nsdu) {
				csb = nsdu;
			}
			void BufferPtrTest::insert(const SharedBuffer& nsdu) {
//				csb.append(nsdu);
//				BufferPtr::insert(csb, nsdu);
				stack.push(nsdu);
			}
			void BufferPtrTest::use() {
				shared_ptr<Buffer> buffer(csb);
				for (;;) {
					if (!buffer) break;
					cout << "use: " << buffer->data() << endl;
					buffer = buffer->next();
				}
			}
			void BufferPtrTest::reorder() {
				for (;;) {
					if (stack.empty()) break;
					stack.top()->next() = csb->next();
					csb->next() = stack.top();
					stack.pop();
				}
			}
			void BufferPtrTest::del() {
				csb.reset();
			}
			BufferPtrTest::BufferPtrTest(const std::string& name) : CppUnit::TestCase(name) {
			}
			BufferPtrTest::~BufferPtrTest() {
			}
			void BufferPtrTest::testBufferPtr() {
				cout << endl;
				BufferPtr sb;
				b1 = new Buffer(32);
				{
					b1->putBytes(7, "azerty");
					b1->flip();
					b1->position() = 1;
					sb = BufferPtr(b1);
					assert(sb.use_count() == 1);
					set(sb);
					assert(sb.use_count() == 2);
					assert(csb.use_count() == 2);
				}
				cout << "csb.use_count(1)=" << csb.use_count() << endl;
				assert(sb.use_count() == 2);
				b2 = new Buffer(32);
				{
					b2->putBytes(7, "abcdef");
					b2->flip();
					b2->position() = 2;
					sb = BufferPtr(b2);
					assert(sb.use_count() == 1);
					insert(sb);
				}
				cout << "csb.use_count(2)=" << csb.use_count() << endl;
				b3 = new Buffer(32);
				{
					b3->putBytes(7, "123456");
					b3->flip();
					b3->position() = 3;
					sb = BufferPtr(b3);
					assert(sb.use_count() == 1);
					insert(sb);
				}
				cout << "csb.use_count(3)=" << csb.use_count() << endl;
				assert(csb.use_count() == 1);
				b4 = new Buffer(32);
				{
					b4->putBytes(7, "poiuyt");
					b4->flip();
					b4->position() = 4;
					sb = BufferPtr(b4);
					assert(sb.use_count() == 1);
					insert(sb);
				}
				cout << "csb.use_count(4)=" << csb.use_count() << endl;
				assert(csb.use_count() == 1);
			}
			void BufferPtrTest::setUp() {
			}
			void BufferPtrTest::tearDown() {
				reorder();
				cout << "csb.use_count(5)=" << csb.use_count() << endl;
				use();
				// zerty
				// cdef
				// 456
				// yt
				assert(string(csb->data(), 2) == "ze");
				assert(string(csb->next()->data(), 2) == "cd");
				assert(string(csb->next()->next()->data(), 2) == "45");
				assert(string(csb->next()->next()->next()->data(), 2) == "yt");
				assert(!csb->next()->next()->next()->next());
				del();
				assert(csb.use_count() == 0);
			}
			CppUnit::Test* BufferPtrTest::suite() {
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("BufferPtrTest");
				CppUnit_addTest(pSuite, BufferPtrTest, testBufferPtr);
				return pSuite;
			}

		}
	}
}
