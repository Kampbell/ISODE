/*
 * InputOutputStreamTest.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef READERWRITERTEST_H_
#define READERWRITERTEST_H_
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class InputOutputStreamTest : public CppUnit::TestCase	{
			public:
				InputOutputStreamTest(const std::string& name);
				~InputOutputStreamTest();

				void testInputStream();
				void testOutputStream();
				void testInputOutputStream();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
