/*
 * NA_TCP_TS_TCP.h
 *
 *  Created on: 25 août 2014
 *      Author: FrancisANDRE
 */

#ifndef NA_TCP_TS_TCP_H_
#define NA_TCP_TS_TCP_H_

#include <iostream>

#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Thread.h"
#include "Poco/Runnable.h"
#include "Poco/ThreadTarget.h"
#include "Poco/Timestamp.h"
#include "Poco/Timespan.h"
#include "Poco/Environment.h"

#include "als/nsap/prov/RFC1006.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/user/Initiator.h"
#include "als/nsap/serv/Initiator.h"
#include "als/nsap/serv/Responder.h"


using Poco::Net::StreamSocket;
using Poco::Net::SocketReactor;
using Poco::Net::ReadableNotification;
using Poco::Net::ShutdownNotification;
using Poco::Net::WritableNotification;
using Poco::Net::TimeoutNotification;
using Poco::Net::IdleNotification;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::AutoPtr;
using Poco::Thread;
using Poco::Runnable;
using Poco::ThreadTarget;

using ALS::NSAP::ADDR::NSAPAddr;
using ALS::NSAP::USER::Initiator;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using ALS::NSAP::PROV::RFC1006;
using namespace ALS::NSAP::ADDR;

namespace ALS {
	namespace NSAP {
		namespace PROV {
			class NA_TCP_TS_TCP : 
				public ALS::NSAP::SERV::Initiator,
				public ALS::NSAP::USER::Initiator,
				public Runnable {
			private:
				ALS::NSAP::USER::Initiator* initiator;

				Thread			thread;
				StreamSocket	socket;
				SocketReactor	reactor;
				RFC1006			rfc1006;
				string			threadName;
				bool			ran = false;

public:
	NA_TCP_TS_TCP(ALS::NSAP::USER::Initiator* initiator);
	virtual ~NA_TCP_TS_TCP();

	virtual void run();

	virtual ReturnCode NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);

	virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation = false);
	virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation = false);
	virtual ReturnCode NDataIndication(const SharedNetworkBuffer& buffer);
	virtual ReturnCode NDataAcknoledgeRequest();
	virtual ReturnCode NExpeditedDataRequest(int cc = 0, const byte* buffer = nullptr);

	virtual ReturnCode NResetRequest(int reason);
	virtual ReturnCode NResetResponse();

	virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc = 0, const byte* buffer = nullptr);
	virtual ReturnCode NDisconnectIndication();

	virtual ReturnCode NResetIndication(const NSAPAddr& originator, int reason);
	virtual ReturnCode NResetConfirmation();
			};

}
}
}

#endif
