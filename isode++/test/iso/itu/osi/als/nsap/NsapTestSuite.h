#ifndef NsapTestSuite_INCLUDED
#define NsapTestSuite_INCLUDED

#include "CppUnit/TestSuite.h"

namespace ALS {
	namespace NSAP {
			class NsapTestSuite
			{

			public:
				static CppUnit::Test* suite();
			};
		}
}
#endif
