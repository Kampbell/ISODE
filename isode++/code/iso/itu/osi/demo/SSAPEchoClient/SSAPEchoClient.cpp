#define ISODE

#include <sstream>
#include <fstream>
#include <iostream>
#include "Poco/Exception.h"
#include "Poco/Thread.h"
#include "Poco/Random.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/Format.h"
#include "Poco/DateTime.h"
#include "Poco/FileStream.h"
#include "Poco/CountingStream.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
using Poco::Net::SocketReactor;
using Poco::Net::SocketAcceptor;
using Poco::Net::ReadableNotification;
using Poco::Net::ShutdownNotification;
using Poco::Net::WritableNotification;
using Poco::Net::TimeoutNotification;
using Poco::Net::IdleNotification;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::SocketAddress;
using Poco::Util::Application;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::LoggingConfigurator;
using Poco::Util::PropertyFileConfiguration;
using Poco::Thread;
using Poco::Random;
using Poco::File;
using Poco::Path;
using Poco::format;
using Poco::FileInputStream;
using Poco::CountingInputStream;


#include "als/base/root/Logger.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/ssap/Literal.h"
#include "als/ssap/ActivityId.h"
#include "als/ssap/Token.h"
#include "als/ssap/SyncOption.h"
#include "als/ssap/Report.h"
#include "als/ssap/AbortCode.h"
#include "als/ssap/Requirement.h"
#include "als/ssap/user/Initiator.h"
#include "als/ssap/serv/Initiator.h"
#include "als/ssap/prov/Provider.h"
#include "demo/SSAPEcho.h"

using ALS::BASE::ROOT::Logger;
using ALS::SSAP::ActivityId;
using ALS::SSAP::Literal;
using ALS::SSAP::Token;
using ALS::SSAP::Requirement;
using ALS::SSAP::PROV::Provider;
using ALS::SSAP::USER::Initiator;


using namespace std;

using namespace ALS::NSAP::ADDR;

//Semaphore semaphore(0, 1);

namespace ALS {
namespace SSAP {
static const nat4 req =
	Requirement::toint(HALFDUPLEX)		+
	Requirement::toint(DUPLEX)			+
	Requirement::toint(EXPEDITED)		+
	Requirement::toint(MINORSYNC)		+
	Requirement::toint(MAJORSYNC)		+
	Requirement::toint(RESYNCHRONIZE)	+
	Requirement::toint(ACTIVITY)		+
	Requirement::toint(NEGOTIATED)		+
	Requirement::toint(CAPABILITY)		+
	Requirement::toint(EXCEPTIONS)		+
	Requirement::toint(TYPEDATA)
//  +
//	Requirement::toint(SYMETRIC)        +
//	Requirement::toint(SEPARATION)
	;

static const Requirement SREQUIREMENTS(req);

class SSAPEchoClient :
	public SSAPEcho,
	public Poco::Util::Application,
	public ALS::SSAP::USER::Initiator,
	public ALS::SSAP::Token
/// The main application class.
///
/// This class handles command-line arguments and configuration files.
/// Start the SSAPEchoClient executable with the help option 
/// (/help on Windows, --help on Unix) for the available command line options.
///
{
  private:
	enum Request {
		REQUEST_NORMAL,
		REQUEST_EXPEDITED,
		REQUEST_TYPED,
		REQUEST_CAPABILITY
	};

	ALS::SSAP::SERV::Initiator&ssap() {
		return *initiator;
	}
  public:
	SSAPEchoClient(): help(false) {
		requirements = SREQUIREMENTS;
		initiator = new ALS::SSAP::PROV::Provider(this);
	}

	~SSAPEchoClient() {
		delete initiator;
	}

	void perform() {
		ReturnCode rc;
		PSAPAddr psapaddr;
		const char* addr;
		//addr = "#128//TELEX+00728722+RFC-1006+03+127.0.0.1";
		addr = "#128//localhost=102";
		psapaddr.parse(addr);
		SSAPAddr calling;
		SSAPAddr called = psapaddr.ssapaddr();
		QualityOfService qualityOfService;
		Reference sf(6, "idefix");
		byte tokens = 0;
#ifdef ISODE
#define dotoken(requires,shift,bit,type) \
{ \
    if (requirements.has(requires)) \
	tokens |= CALLED_VALUE << shift; \
}
		dotokens ();
#undef	dotoken
#else
		if (requirements.has(RELEASE_UNIT_EXISTS))
			tokens = addCalledChoiceRelease(tokens);
		if (requirements.has(MAJOR_UNIT_EXISTS))
			tokens = addCalledChoiceMajor(tokens);
		if (requirements.has(MINOR_UNIT_EXISTS))
			tokens = addCalledChoiceMinor(tokens);
		if (requirements.has(DATA_UNIT_EXISTS))
			tokens = addCalledChoiceData(tokens);
#endif

		cout << addr << endl;
		cout << called.to_string() << endl;
		userdata = "this is the connection request";
		rc = ssap().SConnectRequest(sf, calling, called, qualityOfService, requirements, isn(requirements),
									isn(requirements), tokens, strlen(userdata), userdata);
		if (rc == NOTOK) {
			cout << "failed" << endl;
			ss_adios(Literal::S_CONNECT_REQUEST);
		}
		SWaitFor();

		if (requirements[ACTIVITY]) {
			userdata = "this is the activity start request";
			id = ActivityId(mode == Mode::echo ? "echo" : "sink");
			if (ssap().SActivityStartRequest(id, strlen(userdata), userdata) == NOTOK)
				ss_adios(Literal::S_ACTIVITY_START_REQUEST);
		}

		if (path.getBaseName().empty()) {
			userdata = "12345678";
			for (int i = 3; i > 0; i--) {
				if (timer)
					setTimer(0);
				process(ssap(), REQUEST_NORMAL);
				if (timer)
					setTimer(strlen(userdata), userdata);
			}
		} else {
			int turn = 0;
			int datamode = 0;
			string line;
			Request request;
			File file(path);
			FileInputStream fis(path.toString());
			CountingInputStream cis(fis);

			//LineNumberReader lnr = new LineNumberReader(fr);

			for (;;) { //line = lnr.readLine(); line != nullptr; line = lnr.readLine()) {
				if (cis.eof())
					break;
				getline(cis, line);
				userdata = (char*) line.c_str();
				request = (datamode >= nmodes) ? REQUEST_EXPEDITED : datamodes[datamode++ % nmodes];
				if (strlen(userdata) > SX_EXSIZE && request == REQUEST_EXPEDITED) {
					if ((request = datamodes[datamode++ % nmodes]) == REQUEST_EXPEDITED)
						request = datamodes[datamode++ % nmodes];
				}

				SSN firstSSN;
				SSN secondSSN;
				ResyncOption resync;
				switch (request) {
				case REQUEST_CAPABILITY:
					if (!requirements[RESYNCHRONIZE] || bool(turn++ & 0x01)) {
						SGetToken(ACTIVITY_TOKEN);
						if (turn & 0x03) {
							if (ssap().SActivityInterruptRequest(SP_LOCAL) == NOTOK)
								ss_adios(Literal::S_ACTIVITY_INTERRUPT_REQUEST);
						} else {
							if (ssap().SActivityDiscardRequest(SP_SEQUENCE) == NOTOK)
								ss_adios(Literal::S_ACTIVITY_DISCARD_REQUEST);
						}
						SWaitFor();
						grc = SGetToken(-1);
						process(ssap(), request);
						if (request == REQUEST_CAPABILITY)
							if (ssap().SActivityResumeRequest(id, id, isn(requirements), isn(requirements),  sf, strlen(userdata), userdata) == NOTOK)
								ss_adios(Literal::S_ACTIVITY_RESUME_REQUEST);
						break;
					}
					if (!requirements[RESYNCHRONIZE])
						break;
					tokens = 0;
#ifdef ISODE
#define dotoken(requires,shift,bit,type) \
{ \
		    if (requirements.has(requires)) \
			tokens |= CALLED_VALUE << shift; \
}
					dotokens ();
#undef	dotoken

#else
					if (requirements.has(RELEASE_UNIT_EXISTS))
						tokens = Token::addCalledChoiceRelease(tokens);
					if (requirements.has(MAJOR_UNIT_EXISTS))
						tokens = Token::addCalledChoiceMajor(tokens);
					if (requirements.has(MINOR_UNIT_EXISTS))
						tokens = Token::addCalledChoiceMinor(tokens);
					if (requirements.has(DATA_UNIT_EXISTS))
						tokens = Token::addCalledChoiceData(tokens);
#endif
					ssn = ssn - 1;

					if (ssap().SResynchronizeRequest(SET, ssn,  resync, secondSSN, tokens, strlen(userdata), userdata) == NOTOK)
						ss_adios(Literal::S_RESYNCHRONIZE_REQUEST);
					SWaitFor();
					grc = SGetToken(-1);
					break;

				case REQUEST_EXPEDITED:
					if (datamode >= nmodes)
						datamode = datamode % nmodes;/* fall... */
					if (!requirements[EXPEDITED])
						request = REQUEST_NORMAL; /* fall... */
				default:
					process(ssap(), request);
					if (request == REQUEST_CAPABILITY
							&& ssap().SActivityResumeRequest(id, id, isn(requirements), 0, sf, /*SV_SIZE,*/
														  strlen(userdata), userdata) == NOTOK)
						ss_adios(Literal::S_ACTIVITY_RESUME_REQUEST);
					break;
				}
			}

			if (requirements[EXCEPTIONS]) {
				if (bool(owned & DATA_TOKEN))
					if (ssap().STokenGiveRequest(DATA_TOKEN, strlen(userdata), userdata) == NOTOK)
						ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
					else
						owned &= ~DATA_TOKEN;
				if (ssap().SUExceptionReportRequest(SP_NOREASON, strlen(userdata), userdata) == NOTOK)
					ss_adios(Literal::S_U_EXCEPTION_REPORT_REQUEST);
				SWaitFor();
				grc = SGetToken(-1);
			}
		}

		if (requirements[MAJORSYNC] && !requirements[ACTIVITY]) {
			if (ssap().SSyncMajorRequest(ssn, strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					SGetToken(DATA_TOKEN | MINOR_TOKEN | MAJOR_TOKEN);
					if (ssap().SSyncMajorRequest(ssn, strlen(userdata), userdata) == OK)
						break; /* else fall */

				default:
					ss_adios(Literal::S_SYNC_MAJOR_REQUEST);
				}

			SWaitFor();
			SGetToken(-1);
		}

		if (requirements[ACTIVITY]) {
			if (ssap().SActivityEndRequest(ssn, strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					grc = SGetToken(avail);
					if (ssap().SActivityEndRequest(ssn, strlen(userdata), userdata) == OK)
						break; /* else fall */

				default:
					ss_adios(Literal::S_ACTIVITY_END_REQUEST);
				}

			SWaitFor();
			grc = SGetToken(-1);

			if (ssap().SControlGiveRequest() == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					grc = SGetToken(avail);
					if (ssap().SControlGiveRequest() == OK)
						break; /* else fall */

				default:
					ss_adios(Literal::S_CONTROL_GIVE_REQUEST);
				}

			owned = 0;

			SWaitFor();
			grc = SGetToken(-1);
		}

		if (ssap().SReleaseRequest(0, strlen(userdata), userdata) == NOTOK) {
			switch (reason) {
			case AbortCode::invalid_operation:
			case AbortCode::indications_waiting:
				grc = SGetToken(avail);
				if (ssap().SReleaseRequest(0, strlen(userdata), userdata) == OK)
					break; /* else fall */

			default:
				ss_adios(Literal::S_RELEASE_REQUEST);
			}
			SWaitFor();
		}
	}
	ReturnCode SGetToken(int wanted) {
		int tokens;
		char* buffer;
		for (;;) {
			if (wanted == -1) {
				wanted = avail;
			}
			tokens = 0;
			if (hasReleaseToken(wanted) && !hasReleaseToken(owned))
				tokens = addReleaseToken(tokens);

			if (hasMajorToken(wanted) && !hasMajorToken(owned))
				tokens = addMajorToken(tokens);

			if (hasMinorToken(wanted) && !hasMinorToken(owned))
				tokens = addMinorToken(tokens);

			if (hasDataToken(wanted) && !hasDataToken(owned))
				tokens = addDataToken(tokens);

			if (tokens == 0) {
				return DONE;
			}

			grc = NOTOK;

			if (ssap().STokenPleaseRequest(tokens, strlen(userdata), userdata) == NOTOK)
				return ss_adios(Literal::S_TOKEN_PLEASE_REQUEST);

			acquire();
			switch (grc) {
			case NOTOK:
				return ss_adios(Literal::S_READ_REQUEST);

			case OK:
				buffer = "protocol screw-up";
				if (ssap().SUAbortRequest(strlen(buffer), buffer) == NOTOK)
					ss_adios(Literal::S_U_ABORT_REQUEST);
				return NOTOK;//adios (nullptr, "%s, data indication type=0x%x", buffer, sx.sx_type);

			case DONE:
				break;

			default:
				return NOTOK;//adios (nullptr, "unknown return from SReadRequest=%d", grc);
			}
		}
	}
	SSN isn(Requirement req) {
		int isn;
		if (req[MINORSYNC] || req[MAJORSYNC] || req[RESYNCHRONIZE] || req[ACTIVITY]) {
			isn = (int)  random.next() % SSN::range();
			if (isn < 0)
				isn = -isn;
		} else {
			isn = SERIAL_NONE;
		}
		return isn;
	}
	ReturnCode SWaitFor() {
		acquire();
		switch (grc) {
		case NOTOK:
			return ss_adios(Literal::S_READ_REQUEST);

		case OK:
			return OK;

		case DONE:
			return DONE;

		default:
			return NOTOK;
		}
	}

	void setTimer(int time) {
	}

	void setTimer(int cc, const void* data) {
	}

	void acquire() {
		semaphore.wait();
	}

	void release() {
		semaphore.set();
	}

	ReturnCode ss_adios(const string& message) {
		return NOTOK;
	}
	ReturnCode ss_adios(const char* message) {
		return NOTOK;
	}
	ReturnCode process(ALS::SSAP::SERV::Initiator& ssap, Request dm) {
		ReturnCode rc = NOTOK;

		request = dm;

		switch (dm) {
		case REQUEST_EXPEDITED:
			if (ssap.SExpeditedDataRequest(strlen(userdata), userdata) == NOTOK)
				ss_adios(Literal::S_EXPEDITED_DATA_REQUEST);
			break;

		case REQUEST_CAPABILITY:
			if (ssap.SCapabilityDataRequest(strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					rc = SGetToken(avail & ~RELEASE_TOKEN);
					if (ssap.SCapabilityDataRequest(strlen(userdata), userdata) == OK)
						break;/* else fall */

				default:
					ss_adios(Literal::S_CAPABILITY_DATA_REQUEST);
				}
			break;

		case REQUEST_TYPED:
			if (ssap.STypedDataRequest(strlen(userdata), userdata) == NOTOK)
				ss_adios(Literal::S_TYPED_DATA_REQUEST);
			break;

		default:
			if (ssap.SDataRequest(strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					rc = SGetToken(DATA_TOKEN);
					if (ssap.SDataRequest(strlen(userdata), userdata) == OK) {
						break;/* else fall */
					}

				default:
					ss_adios(Literal::S_DATA_REQUEST);
				}
			break;
		}

		if (mode == Mode::echo || dm == REQUEST_CAPABILITY)
			acquire();

		if (requirements[MINORSYNC] && !requirements[ACTIVITY]) {
			if (ssap.SSyncMinorRequest(SyncOption::CONFIRM, false, ssn, strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					rc = SGetToken(DATA_TOKEN | MINOR_TOKEN);
					if (ssap.SSyncMinorRequest(SyncOption::CONFIRM, false, ssn, strlen(userdata), userdata) == OK)
						break; /* else fall */

				default:
					rc = ss_adios(Literal::S_SYNC_MINOR_REQUEST);
				}

			rc = SGetToken(-1);
		} else if (requirements[ACTIVITY] && requirements[MAJORSYNC] && dm == REQUEST_NORMAL) {
			if (ssap.SSyncMajorRequest(ssn, strlen(userdata), userdata) == NOTOK)
				switch (reason) {
				case AbortCode::invalid_operation:
					rc = SGetToken(DATA_TOKEN | MINOR_TOKEN | MAJOR_TOKEN);
					if (ssap.SSyncMajorRequest(ssn, strlen(userdata), userdata) == OK)
						break;/* else fall */

				default:
					rc = ss_adios(Literal::S_SYNC_MAJOR_REQUEST);
				}

			SWaitFor();
			rc = SGetToken(-1);
		}
		return rc;
	}
/*
void dotoken(const Requirement& requires, int shift, int bit, const string& type) {
		if (requirements.has(requires))
			switch (settings & (CHOICE_MASK << shift)) {
			case CALLED_VALUE:
				adios(nullptr, format("%s token: choice", type));
				break;

			case INITIATOR_VALUE:
				owned |= bit, avail |= bit;
				break;

			case RESPONDER_VALUE:
				avail |= bit;
				break;

			default:
				adios(nullptr, format("%s token: reserved", type));
		}
	}
*/	
	ReturnCode SConnectConfirmation(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize, int cc = 0, const void* data = nullptr, int rdcc = 0, const void* realdata = nullptr) {
		//ssap.logger().info("responding SSAP address: " + sc_responding.toString());
		if (data != nullptr && cc > 0) {
			string s("greetings: ");
			s.append(to_string(cc));
			s.append(" octets");
			ssap().logger()->information(s);
			ssap().logger()->information(string((char*)data, cc));
		}
		this->requirements = requirements;
		nmodes = 0;
		datamodes[nmodes++] = REQUEST_NORMAL;
		if (requirements[EXPEDITED])
			datamodes[nmodes++] = REQUEST_EXPEDITED;
		if (requirements[CAPABILITY] && requirements[ACTIVITY])
			datamodes[nmodes++] = REQUEST_CAPABILITY;
		if (requirements[TYPEDATA])
			datamodes[nmodes++] = REQUEST_TYPED;

		ssn = firstInitialSSN;
		if (result != AbortCode::SC_ACCEPT) {
			cout << "connexion failed" << endl;
			if (data != nullptr && cc > 0)
				ss_adios("connection rejected: [");//FIXME  +SSAPAbort.SErrorString(result) + "] " + string(data));
			else
				ss_adios("connection rejected: [");//FIXME + SSAPAbort.SErrorString(result) + "]");
			grc = NOTOK;
		} else {
			cout << "connexion succeded: connected" << endl;
			grc = DONE;
		}
#ifdef ISODE
#define dotoken(requires,shift,bit,type) \
		{ \
    if (requirements.has(requires)) \
	switch (settings & (CHOICE_MASK << shift)) { \
	    case CALLED_VALUE: \
		adios (nullptr, format("%s token: choice", type)); \
		break; \
 \
	    case INITIATOR_VALUE: \
		owned |= bit, avail |= bit; \
		break; \
 \
	    case RESPONDER_VALUE: \
		avail |= bit; \
		break; \
 \
	    default: \
		adios (nullptr, format("%s token: reserved", type)); \
	} \
}
		dotokens ();
#undef	dotoken
#else
		if (requirements.has(RELEASE_UNIT_EXISTS)) {
			switch (selectReleaseToken(settings)) {
			case CALLED_VALUE:
				adios(nullptr, "release token: choice");
				break;

			case INITIATOR_VALUE:
				owned = addReleaseToken(owned);
				avail = addReleaseToken(avail);
				break;

			case RESPONDER_VALUE:
				avail = addReleaseToken(avail);
				break;

			default:
				adios(nullptr, "release token: reserved");
			}
		}

		if (requirements.has(MAJOR_UNIT_EXISTS)) {
			switch (selectMajorToken(settings)) {
			case CALLED_VALUE:
				adios(nullptr, "majorsync token: choice");
				break;

			case INITIATOR_VALUE:
				owned = addMajorToken(owned);
				avail = addMajorToken(avail);
				break;

			case RESPONDER_VALUE:
				avail = addMajorToken(avail);
				break;

			default:
				adios(nullptr, "majorsync token: reserved");
			}
		}

		if (requirements.has(MINOR_UNIT_EXISTS)) {
			switch (selectMinorToken(settings)) {
			case CALLED_VALUE:
				adios(nullptr, "minorsync token: choice");
				break;

			case INITIATOR_VALUE:
				owned = addMinorToken(owned);
				avail = addMinorToken(avail);
				break;

			case RESPONDER_VALUE:
				avail = addMinorToken(avail);
				break;

			default:
				adios(nullptr, "minorsync token: reserved");
			}
		}

		if (requirements.has(DATA_UNIT_EXISTS)) {
			switch (selectDataToken(settings)) {
			case CALLED_VALUE:
				adios(nullptr, "data token: choice");
				break;

			case INITIATOR_VALUE:
				owned = addDataToken(owned);
				avail = addDataToken(avail);
				break;

			case RESPONDER_VALUE:
				avail = addDataToken(avail);
				break;

			default:
				adios(nullptr, "data token: reserved");
			}
		}
#endif
		ssap().logger()->information("avail=%s", Token::initiator(avail));
		ssap().logger()->information("owned=%s", Token::initiator(owned));
		release();
		return grc;
	}
	ReturnCode SUAbortIndication(int reason, int cc = 0, const void* data = nullptr) {
		this->reason = reason;
		this->cc = cc;
		this->data = (char*)data;
		return DONE;
	}
	ReturnCode SPAbortIndication(int reason, int extension, int cc = 0, const void* data = nullptr) {
		this->reason = reason;
		this->extension = extension;
		this->cc = cc;
		this->data = (char*)data;
		return DONE;
	}
	ReturnCode SActivityDiscardIndication(int reason, int cc = 0, const void* data = nullptr) {
		ss_adios(format("activity discard indication %d, %d bytes", reason, cc));
		grc = NOTOK;
		return grc;
	}
	ReturnCode SActivityDiscardConfirmation(int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SActivityEndIndication(const SSN& firstSSN, int cc = 0, const void* data = nullptr) {
		ss_adios(format("activity end indication %s, %d bytes", firstSSN.to_string(), cc));
		grc = NOTOK;
		return grc;
	}
	ReturnCode SActivityEndConfirmation(int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SActivityEndConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SActivityInterruptIndication(int reason, int cc = 0, const void* data = nullptr) {
		ss_adios(format("activity interrupt indication: %d bytes", cc));
		grc = NOTOK;
		return grc;
	}
	ReturnCode SActivityInterruptConfirmation(int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc = 0, const void* data = nullptr) {
		ss_adios(format("activity resume indication: id=%*.*s oid=%*.*s connect=%*.*s ssn=%d, %d bytes",
			activityId.cc(), activityId.data(), oldActivityId.cc(), oldActivityId.data(), 
			oldSessionReference.ulength(), oldSessionReference.udata(), firstSSN.ssn(), cc));
		grc = NOTOK;
		return grc;
	}
	ReturnCode SActivityStartIndication(const ActivityId&  activityId, int cc = 0, const void* data = nullptr) {
		ss_adios(format("activity start indication: %*.*s, %d bytes", 
			activityId.cc(), activityId.data(), cc));
		grc = NOTOK;
		return grc;
	}
	ReturnCode SDataIndication(const SharedNetworkBuffer& data) {
		if (request != REQUEST_NORMAL) {
			ssap().logger()->fatal(format("data indication type mismatch, orig= %d echo=", REQUEST_NORMAL));
			status++;
		}
		if (data) {
			char* bytes = data.get()->data();
			if (strlen(userdata) != data.get()->remaining()) {
				ssap().logger()->fatal(format("length mismatch, orig=%d != echo=%d", strlen(userdata), data.get()->remaining()));
				status++;
			} else if (memcmp(bytes, userdata, strlen(userdata)) == 0) {
				status++;
			} else {
				ssap().logger()->fatal("data mismatch");
			}
		}
		grc = OK;
		release();
		return grc;
	}
	ReturnCode SCapabilityDataIndication(const SharedNetworkBuffer& data) {
		if (request != REQUEST_CAPABILITY) {
			ssap().logger()->fatal(format(
				"capability data indication type mismatch, orig=%d != echo=%d", request, REQUEST_CAPABILITY));
			status++;
		}
		if (data) {
			char* bytes = data.get()->data();
			if (strlen(userdata) != data.get()->remaining()) {
				ssap().logger()->fatal(format("length mismatch, orig=%d != echo=%d", strlen(userdata), data.get()->remaining()));
				status++;
			} else if (memcmp(bytes, userdata, strlen(userdata)) == 0) {
				status++;
			} else {
				ssap().logger()->fatal("data mismatch");
			}
		}
		grc = OK;
		return grc;
	}
	ReturnCode SCapabilityDataConfirmation(const SharedNetworkBuffer& data) {
		if (request != REQUEST_CAPABILITY) {
			ssap().logger()->fatal(format(
				"capability data confirmation type mismatch, orig=%d != echo=%d", REQUEST_CAPABILITY, request));
			status++;
		}
		if (data) {
			char* bytes = data.get()->data();
			if (strlen(userdata) != data.get()->remaining()) {
				ssap().logger()->fatal(format("length mismatch, orig=%d != echo=%d", strlen(userdata), data.get()->remaining()));
				status++;
			} else if (memcmp(bytes, userdata, strlen(userdata)) == 0) {
				status++;
			} else {
				ssap().logger()->fatal("data mismatch");
			}
		}
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SExpeditedDataIndication(const SharedNetworkBuffer& data) {
		if (request != REQUEST_EXPEDITED) {
			ssap().logger()->fatal("data indication type mismatch, orig=%d != echo=%d", request, REQUEST_EXPEDITED);
			status++;
		}
		if (data) {
			char* bytes = data.get()->data();
			if (strlen(userdata) != data.get()->remaining()) {
				ssap().logger()->fatal(format("length mismatch, orig=%d != echo=%d", strlen(userdata), data.get()->remaining()));
				status++;
			} else if (memcmp(bytes, userdata, strlen(userdata)) == 0) {
				status++;
			} else {
				ssap().logger()->fatal("data mismatch");
			}
		}
		grc = OK;
		return grc;
	}
	ReturnCode STypedDataIndication(const SharedNetworkBuffer& data) {
		if (request != REQUEST_TYPED) {
			ssap().logger()->fatal(format("typed data indication type mismatch, orig=%d !=  echo=%d", request, REQUEST_TYPED));
			status++;
		}
		if (data) {
			char* bytes = data.get()->data();
			if (strlen(userdata) != data.get()->remaining()) {
				ssap().logger()->fatal(format("length mismatch, orig=%d != echo=%d", strlen(userdata), data.get()->remaining()));
				status++;
			} else if (memcmp(bytes, userdata, strlen(userdata)) == 0) {
				status++;
			} else {
				ssap().logger()->fatal("data mismatch");
			}
		}
		grc = OK;
		release();
		return grc;
	}
	ReturnCode SUExceptionReportIndication(int reason, int cc = 0, const void* data = nullptr) {

		if (requirements.has(DATA_UNIT_EXISTS)) {
			if (ssap().STokenGiveRequest(DATA_TOKEN, strlen(userdata), userdata) == NOTOK) {
				ss_adios(string(Literal::S_TOKEN_GIVE_REQUEST) + " (to clear exception)");
				grc = NOTOK;
			} else {
				owned &= ~DATA_TOKEN;
				grc = DONE;
			}
		} else if (ssap().SUAbortRequest(strlen(userdata), userdata) == NOTOK) {
			ss_adios(Literal::S_U_ABORT_REQUEST);
			grc = NOTOK;
		} else {
			ss_adios("aborted");
			grc = NOTOK;
		}
		if (trace)
			ssap().logger()->trace(string("owned:") + Token::token(owned));
		return grc;
	}
	ReturnCode SPExceptionReportIndication(int reason) {

		if (requirements .has(DATA_UNIT_EXISTS)) {
			if (ssap().STokenGiveRequest(DATA_TOKEN, strlen(userdata), userdata) == NOTOK) {
				ss_adios(string(Literal::S_TOKEN_GIVE_REQUEST)+ " (to clear exception)");
				grc = NOTOK;
			} else {
				owned &= ~DATA_TOKEN;
				grc = DONE;
			}
		} else if (ssap().SUAbortRequest(strlen(userdata), userdata) == NOTOK) {
			ss_adios(Literal::S_U_ABORT_REQUEST);
			grc = NOTOK;
		} else {
			ss_adios("aborted");
			grc = NOTOK;
		}
		if (trace)
			ssap().logger()->trace(string("owned:") + Token::token(owned));
		return grc;
	}
	ReturnCode SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) {
		if (requirements .has(RELEASE_UNIT_EXISTS)) {
			switch (selectReleaseToken(settings)) {
			case RELEASE_TOKEN_AS_CALLED_CHOICE:
				settings = clearReleaseToken(settings);
				settings = addResponderRelease(settings);
			case RELEASE_TOKEN_FOR_RESPONDER:
				owned = remReleaseToken(owned);
				break;

			case RELEASE_TOKEN_FOR_INITIATOR:
				owned = addReleaseToken(owned);
				break;

			default:
				adios(nullptr, "release token: reserved");
				break;
			}
		}

		if (requirements .has(MAJOR_UNIT_EXISTS)) {
			switch (Token::selectMajorToken(settings)) {
			case MAJOR_TOKEN_AS_CALLED_CHOICE:
				settings = Token::clearMajorToken(settings);
				settings = Token::addResponderMajor(settings);
			case MAJOR_TOKEN_FOR_RESPONDER:
				owned = Token::remMajorToken(owned);
				break;

			case MAJOR_TOKEN_FOR_INITIATOR:
				owned = Token::addMajorToken(owned);
				break;

			default:
				adios(nullptr, "majorsync token: reserved");
				break;
			}
		}

		if (requirements .has(MINOR_UNIT_EXISTS)) {
			switch (selectMinorToken(settings)) {
			case MINOR_TOKEN_AS_CALLED_CHOICE:
				settings = Token::clearMinorToken(settings);
				settings = Token::addResponderMinor(settings);
			case MINOR_TOKEN_FOR_RESPONDER:
				owned = Token::remMinorToken(owned);
				break;

			case MINOR_TOKEN_FOR_INITIATOR:
				owned = Token::addMinorToken(owned);
				break;

			default:
				adios(nullptr, "minorsync token: reserved");
				break;
			}
		}

		if (requirements .has(DATA_UNIT_EXISTS)) {
			switch (Token::selectDataToken(settings)) {
			case DATA_TOKEN_AS_CALLED_CHOICE:
				settings = Token::clearDataToken(settings);
				settings = Token::addResponderData(settings);
			case DATA_TOKEN_FOR_RESPONDER:
				owned = Token::remDataToken(owned);
				break;

			case DATA_TOKEN_FOR_INITIATOR:
				owned = Token::addDataToken(owned);
				break;

			default:
				adios(nullptr, "data token: reserved");
				break;
			}
		}

		if (ssap().SResynchronizeResponse(firstResync, firstSSN, secondResync, 0, settings, strlen(userdata), userdata) == NOTOK)
			ss_adios(Literal::S_RESYNCHRONIZE_RESPONSE);
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode SSyncMajorIndication(const SSN& firsSSN, int cc = 0, const void* data = nullptr) {
		ssap().logger()->trace(format("majorsync indication %d, %d bytes", firsSSN, cc));
		grc = DONE;
		return grc;
	}
	ReturnCode SSyncMajorConfirmation(int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		if (false)
			exit(1);
		return grc;
	}
	ReturnCode SSyncMajorConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr) {
		grc = DONE;
		release();
		if (false)
			exit(1);
		return grc;
	}
	ReturnCode SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data = nullptr) {
		ssap().logger()->fatal(
			format("minorsync indication %d %s, %d bytes", firstSSN, type == SyncOption::CONFIRM ? " (wants confirmation)"
				: nullptr, cc));
		grc = DONE;
		return grc;
	}
	ReturnCode SSyncMinorConfirmation(const SSN& firstSSN, int cc = 0, const void* data = nullptr) {
		grc = DONE;
		return grc;
	}
	ReturnCode SControlGiveIndication(int tokens, int cc = 0, const void* data = nullptr) {
		owned = tokens;
		grc = DONE;
		if (trace)
			ssap().logger()->trace(string("owned:") + Token::token(owned));
		release();
		return grc;
	}
	ReturnCode STokenGiveIndication(int tokens, int cc = 0, const void* data = nullptr) {
		owned |= tokens;
		if (trace)
			ssap().logger()->trace(string("owned:") + Token::token(owned));
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode STokenPleaseIndication(int tokens, int cc = 0, const void* data = nullptr) {
		if (ssap().STokenGiveRequest(tokens, cc, data) == NOTOK) {
			ss_adios(Literal::S_TOKEN_GIVE_REQUEST);
			return NOTOK;
		} else {
			owned &= ~tokens;
			if (trace)
				ssap().logger()->trace(string("owned:") + Token::token(owned));
			grc = DONE;
			return grc;
		}
		return DONE;
	}
	ReturnCode SReleaseIndication(int cc = 0, const void* data = nullptr) {

		if (ssap().SReleaseResponse(AbortCode::SC_REJECTED, cc, data) == NOTOK) {
			ss_adios(Literal::S_RELEASE_RESPONSE);
			grc = NOTOK;
		} else {
			grc = DONE;
		}
		return grc;
	}
	ReturnCode SReleaseConfirmation(bool affirmative, int cc = 0, const void* data = nullptr) {

		if (affirmative) {
			if (data != nullptr)
				cout << string((char*)data, cc) << endl;
		} else {
			ssap().SUAbortRequest(cc, data);

			if (data != nullptr && cc > 0)
				adios(nullptr, format("release rejected by peer: %*.*s", cc, data));
			else
				adios(nullptr, "release rejected by peer");
		}
		grc = DONE;
		release();
		return grc;
	}
	ReturnCode adios(const char* what, const char* message) const {
		return NOTOK;
	}
	ReturnCode adios(const char* what, const string& message) const {
		return NOTOK;
	}
	ReturnCode ss_adios(const string& message) const {
		return NOTOK;
	}
  protected:
	void initialize(Application& self) {
		loadConfiguration(); 
		Application::initialize(self);
	}

	void uninitialize() {
		Application::uninitialize();
	}

	void defineOptions(OptionSet& options) {
		Application::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
			.required(false)
			.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value) {
		Application::handleOption(name, value);

		if (name == "help") {
			help = true;
			stopOptionsProcessing();
		}
	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("An SSAP echo client.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args) {
		Poco::Logger& logger = Application::instance().logger();
		if (help) {
			displayHelp();
		} else {
			path = args[0];
			if (!path.isFile()) {
				logger.error("file %s is not a file", path.toString());
				return Application::EXIT_USAGE;
			}
			// get parameters from configuration file
			unsigned short port = (unsigned short) config().getInt("port", 102);
			perform();

		}
		return Application::EXIT_OK;
	}

  private:
	bool	help = false;
	ALS::SSAP::SERV::Initiator* initiator;
	Reference					reference;
	char*						userdata = nullptr;
	Random						random;
	volatile ReturnCode			grc;
	Request						datamodes[4];
	Request						request;
	int							nmodes;
	Path						path;
	File						file;


};
}
}

POCO_APP_MAIN(ALS::SSAP::SSAPEchoClient)
