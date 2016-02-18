#ifndef SrvcTestSuite_INCLUDED
#define SrvcTestSuite_INCLUDED


#include "CppUnit/TestSuite.h"


namespace ALS {
	namespace BASE {
		namespace SRVC {
			class SrvcTestSuite
			{
			public:
				static CppUnit::Test* suite();
			};
		}
	}
}

#endif
