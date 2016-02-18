#ifndef TPDUTestSuite_INCLUDED
#define TPDUTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace TSAP {
		namespace TPDU {
			class TPDUTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
