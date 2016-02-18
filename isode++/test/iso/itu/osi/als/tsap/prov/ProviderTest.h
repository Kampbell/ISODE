#ifndef ProviderTest_INCLUDED
#define ProviderTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include "Poco/Path.h"
using Poco::Path;


#include "als/nsap/QualityOfService.h"
#include "als/nsap/addr/TSAPAddr.h"

#include "als/nsap/prov/Logger.h"
#include "als/nsap/user/Initiator.h"
#include "als/nsap/user/Responder.h"
#include "als/nsap/serv/Initiator.h"
#include "als/nsap/serv/Responder.h"
#include "als/tsap/tpdu/TPCI.h"
#include "als/tsap/user/Linker.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"
namespace ALS { 
	namespace NSAP { 
		class TSAPServiceHandler;
	}
	namespace TSAP {
		namespace TPDU {
			class CC; class CR; class DT; class DR; class DC; class AK; class ED; class EA;
		}
	}
}
#ifdef ERROR
#undef ERROR
#endif
#include "als/tsap/prov/FSM.h"

using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using ALS::NSAP::ADDR::TSAPAddr;

namespace ALS {
	namespace TSAP {
		namespace PROV {
			enum class TestType {
				Assembly
			};
	enum class STATE {
			AKWAIT,
			CLOSED,
			CLOSING,
			CLOSING_BOC,
			CLOSING_BOC_WR,
			CLOSING_R,
			CLOSING_WR,
			ERROR,
			OPEN,
			OPEN_R,
			OPEN_WR,
			REFWAIT,
			WBCL,
			WBCL_R,
			WBCL_WR,
			WBOC,
			WBOC_WR,
			WFCC,
			WFCC_R,
			WFNC,
			WFNC_R,
			WFTRESP,
			WFTRESP_WR
	};
			class ProviderTest : 
				public ALS::NSAP::SERV::Responder,
//				public ALS::TSAP::PROV::FSM<ProviderTest>,
				public CppUnit::TestCase	{
			private:
				NSAPAddr					responding;
				TSAPAddr					tsapAddr;

				QualityOfService			qos;
				QualityOfServiceParameters	qosp;
				ALS::NSAP::USER::Responder* responder;
				ALS::NSAP::PROV::Logger		logger;

				TestType					test;
				STATE						state;

			public:
				ProviderTest(const std::string& name);
				~ProviderTest();

				void testTPDUAssembly();

				void setUp();
				void tearDown();

				virtual ReturnCode NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
				virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation = false);
				virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation = false);
				virtual ReturnCode NDataAcknoledgeRequest();
				virtual ReturnCode NExpeditedDataRequest(int cc = 0, const byte* buffer = nullptr);
				virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc = 0, const byte* buffer = nullptr);
				virtual ReturnCode NResetRequest(int reason);
				virtual ReturnCode NResetResponse();
				static CppUnit::Test* suite();
				bool findFile(Path& path) const;
				void getPath(Path& path) const;
			};
		}
	}
}
#endif

