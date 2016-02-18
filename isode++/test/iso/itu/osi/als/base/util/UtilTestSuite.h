#ifndef UtilTestSuite_INCLUDED
#define UtilTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {
			class UtilTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
