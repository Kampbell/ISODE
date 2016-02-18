/*
 * SharedBufferTest.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef SHAREDBUFFERTEST_H_
#define SHAREDBUFFERTEST_H_
#include <stack>
using std::stack;

#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "als/base/util/SharedNetworkBuffer.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class SharedBufferTest : public CppUnit::TestCase	{
			private:
				SharedNetworkBuffer csb;
				NetworkBuffer* b1 = nullptr;
				NetworkBuffer* b2 = nullptr;
				NetworkBuffer* b3 = nullptr;
				NetworkBuffer* b4 = nullptr;
				stack<SharedNetworkBuffer>	buffers;

			public:
				SharedBufferTest(const std::string& name);
				~SharedBufferTest();

				void testSharedBuffer();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			private:
				void set(SharedNetworkBuffer& nsdu);
				void append(SharedNetworkBuffer& nsdu);
				void use();
				void del();
			};
		}
	}
}

#endif
