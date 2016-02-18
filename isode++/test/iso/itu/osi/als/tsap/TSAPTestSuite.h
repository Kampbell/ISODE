#ifndef TSAPTestSuite_INCLUDED
#define TSAPTestSuite_INCLUDED

#include "CppUnit/TestSuite.h"

namespace ALS {
	namespace TSAP {
			class TSAPTestSuite
			{

			public:
				static CppUnit::Test* suite();
			};
		}
}
#endif
