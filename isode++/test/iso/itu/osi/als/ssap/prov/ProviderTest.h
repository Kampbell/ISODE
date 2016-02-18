#ifndef ProviderTest_INCLUDED
#define ProviderTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/Path.h"
using Poco::Path;


#include "als/nsap/QualityOfService.h"
#include "als/nsap/addr/SSAPAddr.h"

#include "als/tsap/prov/Logger.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"
#include "als/tsap/serv/Initiator.h"
#include "als/tsap/serv/Responder.h"
#include "als/ssap/user/Linker.h"
#include "als/ssap/user/Initiator.h"
#include "als/ssap/user/Responder.h"
using ALS::NSAP::ADDR::SSAPAddr;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;

namespace ALS {
	namespace TSAP {
		namespace PROV {
			enum class STATE {
				CLOSED
			};
			enum class TestType {
				Assembly
			};
			class ProviderTest : 
				public ALS::TSAP::SERV::Responder,
				public CppUnit::TestCase	{
			private:
				TSAPAddr					responding;
				SSAPAddr					tsapAddr;

				QualityOfService			qos;
				QualityOfServiceParameters	qosp;
				ALS::TSAP::USER::Responder* responder;
				ALS::TSAP::PROV::Logger		logger;

				TestType					test;
				STATE						state;

			public:
				ProviderTest(const std::string& name);
				~ProviderTest();

				void testTPDUAssembly();

				void setUp();
				void tearDown();

				static CppUnit::Test* suite();
				bool findFile(Path& path) const;
				void getPath(Path& path) const;
			};
		}
	}
}
#endif

