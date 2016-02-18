#ifndef AddrTestSuite_INCLUDED
#define AddrTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace NSAP {
		namespace ADDR {
			class AddrTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
