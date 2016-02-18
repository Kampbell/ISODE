/*
 * BufferTest.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BUFFERTEST_H_
#define BUFFERTEST_H_
#include <stack>
using std::stack;

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BufferTest : public CppUnit::TestCase	{
			public:
				BufferTest(const std::string& name);
				~BufferTest();

				void testBuffer();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
