/*
 * BufferTest.cpp
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

#include "als/base/util/NetworkBuffer.h"
#include "BufferTest.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {
			BufferTest::BufferTest(const std::string& name) : CppUnit::TestCase(name) {
			}
			BufferTest::~BufferTest() {
			}
			void BufferTest::testBuffer() {
				NetworkBuffer	buffer(32);
				poco_assert(buffer.position() == 0);
				poco_assert(buffer.limit() == 32);
				poco_assert(buffer.capacity() == 32);
				poco_assert(buffer.hasRemaining());
				poco_assert(buffer.remaining() == 32);
				buffer.put(1);
				buffer.put(2);
				buffer.skip(2);
				buffer.put(3);
				buffer.put(4);
				poco_assert(buffer.position() == 6);
				poco_assert(buffer.limit() == 32);
				buffer.flip();
				poco_assert(buffer.position() == 0);
				poco_assert(buffer.limit() == 6);
				poco_assert(buffer.get() == 1);
				poco_assert(buffer.get() == 2);
				buffer.skip(2);
				poco_assert(buffer.get() == 3);
				poco_assert(buffer.get() == 4);
			}
			void BufferTest::setUp() {
			}
			void BufferTest::tearDown() {
			}
			CppUnit::Test* BufferTest::suite() {
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("BufferTest");
				CppUnit_addTest(pSuite, BufferTest, testBuffer);
				return pSuite;
			}

		}
	}
}
