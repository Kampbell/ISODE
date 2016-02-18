/*
 * BufferPtrTestTest.h
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
#include "als/base/util/Buffer.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BufferPtrTest : public CppUnit::TestCase	{
			private:
				BufferPtr csb;
				Buffer* b1 = nullptr;
				Buffer* b2 = nullptr;
				Buffer* b3 = nullptr;
				Buffer* b4 = nullptr;
				stack<const BufferPtr>	stack;

			public:
				BufferPtrTest(const std::string& name);
				~BufferPtrTest();

				void testBufferPtr();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			private:
				void set(const SharedBuffer& nsdu);
				void insert(const SharedBuffer& nsdu);
				void reorder();
				void use();
				void del();
			};
		}
	}
}

#endif
