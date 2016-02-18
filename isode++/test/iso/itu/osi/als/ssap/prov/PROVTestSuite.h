#ifndef PROVTestSuite_INCLUDED
#define PROVTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace TSAP {
		namespace PROV {
			class PROVTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
