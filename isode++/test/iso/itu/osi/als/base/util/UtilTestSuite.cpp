//
// BaseTestSuite.cpp
//
// $Id: //poco/1.4/Base/testsuite/src/BaseTestSuite.cpp#3 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "UtilTestSuite.h"
#include "InputOutputStreamTest.h"
//#include "BufferPtrTest.h"
#include "SharedBufferTest.h"
#include "BufferTest.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {
			CppUnit::Test* UtilTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("UtilTestSuite");

				pSuite->addTest(BufferTest::suite());
//				pSuite->addTest(BufferPtrTest::suite());
				pSuite->addTest(SharedBufferTest::suite());
				pSuite->addTest(InputOutputStreamTest::suite());

				return pSuite;
			}
		}
	}
}
