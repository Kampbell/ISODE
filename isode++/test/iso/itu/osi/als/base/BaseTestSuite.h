#ifndef BaseTestSuite_INCLUDED
#define BaseTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace BASE {
			class BaseTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
	}
}

#endif
