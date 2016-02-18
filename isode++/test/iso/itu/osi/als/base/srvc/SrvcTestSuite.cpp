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


#include "SrvcTestSuite.h"


namespace ALS {
	namespace BASE {
		namespace SRVC {
			CppUnit::Test* SrvcTestSuite::suite()
			{
				CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SrvcTestSuite");

//				pSuite->addTest(SrvcTestSuite::suite());

				return pSuite;
			}
		}
	}
}
