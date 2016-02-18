/*
 * Logger.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_PROV_LOGGER_H_
#define ALS_SSAP_PROV_LOGGER_H_

#include "Poco/Logger.h"
#include "Poco/Path.h"
#include "Poco/Timestamp.h"
#include "Poco/Timespan.h"
#include "Poco/Util/ServerApplication.h"
using Poco::Util::Application;

#include "als/base/root/Logger.h"
#include "als/base/util/SharedNetworkBuffer.h"
using ALS::BASE::UTIL::SharedNetworkBuffer;
#include "als/base/util/Bits.h"
using ALS::BASE::UTIL::Bits;

#include "als/nsap/addr/SSAPAddr.h"

#include "als/ssap/ssap.h"
#include "als/ssap/Reference.h"
#include "als/ssap/SyncOption.h"
#include "als/ssap/ResyncOption.h"
#include "als/nsap/QualityOfService.h"
#include "als/ssap/serv/Initiator.h"
#include "als/ssap/serv/Responder.h"
#include "als/ssap/user/Initiator.h"
#include "als/ssap/user/Responder.h"

using ALS::NSAP::QualityOfService;
using ALS::SSAP::ResyncOption;

namespace ALS {
namespace SSAP {
namespace PROV {

	class SSAP_API Logger : public ALS::BASE::ROOT::Logger,
		public SERV::Initiator, public SERV::Responder,
		public USER::Initiator, public USER::Responder {
		friend class Provider; 
	private:
		const Reference* ref;
		Requirement		req;
public:
	Logger(int level) : ALS::BASE::ROOT::Logger("SSAP") {
	}
	virtual ~Logger() {
	}
private:
	virtual const Reference& reference() const { return *ref; }
	virtual Requirement requirements() const { return req; }
	virtual int available() const { return 0; }
	virtual Bits owned() const { return 0; }
	virtual bool isInitiator() const { return false; }
	virtual bool isResponder() const { return false; }
	virtual ALS::BASE::ROOT::Logger* logger() { return nullptr; }

	ReturnCode SConnectRequest(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, byte settings, int cc = 0, const void* data = nullptr);
	ReturnCode SConnectResponse(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement& requirements, int settings, SSN& firstInitialSSN, SSN& secondInitialSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SConnectIndication(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, int result, const QualityOfService& qualityOfService, const Requirement& requirements, SSN& firstInitialSSN, SSN& secondInitialSSN, int settings, int ssdusize, int cc = 0, const void* data =  nullptr);
	ReturnCode SConnectConfirmation(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize, int cc = 0, const void* data =  nullptr, int rdcc = 0, const void* realdata = nullptr);

	ReturnCode SUAbortRequest(int cc = 0, const void* data = nullptr);
	ReturnCode SUAbortIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPAbortIndication(int reason, int extension, int cc = 0, const void* data = nullptr);


	ReturnCode SActivityDiscardRequest(int reason, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityDiscardResponse(int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityDiscardIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityDiscardConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndRequest(SSN& firstSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityEndResponse(int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityEndResponse(const SSN& secondSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityEndIndication(const SSN& firstSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptRequest(int reason, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityInterruptResponse(int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityInterruptIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN&  secondSSN, const Reference& reference, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityStartRequest(const ActivityId& activityId, int cc = 0, const void* data =  nullptr);
	ReturnCode SActivityStartIndication(const ActivityId&  activityId, int cc = 0, const void* data = nullptr);

	ReturnCode SDataRequest(int cc = 0, const void* data = nullptr);
	ReturnCode SDataRequest(const SharedNetworkBuffer& data);
	ReturnCode SDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataRequest(int cc = 0, const void* data = nullptr);
	ReturnCode SCapabilityDataResponse(int cc = 0, const void* data = nullptr);
	ReturnCode SCapabilityDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataConfirmation(const SharedNetworkBuffer& data);
	ReturnCode SExpeditedDataRequest(int cc = 0, const void* data = nullptr);
	ReturnCode SExpeditedDataIndication(const SharedNetworkBuffer& data);
	ReturnCode STypedDataRequest(int cc = 0, const void* data = nullptr);
	ReturnCode STypedDataIndication(const SharedNetworkBuffer& data);

	ReturnCode SSendRequest(bool begin, bool end, int cc = 0, const void* data = nullptr);
	ReturnCode SWriteRequest(bool typed, int cc = 0, const void* data = nullptr);

	ReturnCode SUExceptionReportRequest(int reason, int cc = 0, const void* data =  nullptr);
	ReturnCode SUExceptionReportIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPExceptionReportIndication(int reason);

	ReturnCode SResynchronizeRequest(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data =  nullptr);
	ReturnCode SResynchronizeResponse(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data =  nullptr);
	ReturnCode SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data =  nullptr);
	ReturnCode SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data =  nullptr);

	ReturnCode SSyncMajorRequest(SSN& firstSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMajorResponse(int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMajorResponse(const SSN& secondSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMajorIndication(const SSN& firsSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMajorConfirmation(int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMajorConfirmation(const SSN& secondSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMinorRequest(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMinorResponse(const SSN& firstSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data =  nullptr);
	ReturnCode SSyncMinorConfirmation(const SSN& firstSSN, int cc = 0, const void* data =  nullptr);


	ReturnCode SControlGiveRequest();
	ReturnCode SControlGiveIndication(int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenGiveRequest(int tokens, int cc = 0, const void* data =  nullptr);
	ReturnCode STokenGiveIndication(int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenPleaseRequest(int tokens, int cc = 0, const void* data =  nullptr);
	ReturnCode STokenPleaseIndication(int tokens, int cc = 0, const void* data = nullptr);


	ReturnCode SReleaseRequest(int secs, int cc = 0, const void* data =  nullptr);
	ReturnCode SReleaseRetryRequest(int status);
	ReturnCode SReleaseResponse(bool accept, int cc = 0, const void* data =  nullptr);
	ReturnCode SReleaseIndication(int cc = 0, const void* data = nullptr);
	ReturnCode SReleaseConfirmation(bool affirmative, int cc = 0, const void* data = nullptr);

	};

}
}
}

#endif
