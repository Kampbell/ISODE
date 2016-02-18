//============================================================================
// Name        : isod.cpp
// Author      : FA
// Version     :
// Copyright   : Copyright Kampbell.net All Right Reserved
// Description : The isod daemon listening on port 102 service(iso-tsap) on IANA records
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>

#include "Poco/AutoPtr.h"
#include "Poco/ClassLoader.h"
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Environment.h"
#include "Poco/Exception.h"
#include "Poco/Manifest.h"
#include "Poco/NObserver.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/SAX/SAXParser.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/AutoPtr.h"
#include "Poco/SharedPtr.h"
#include "Poco/SharedLibrary.h"
#include "Poco/Thread.h"
#include "Poco/ThreadLocal.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/XMLConfiguration.h"

#include "als/base/srvc/AEISAXHandler.h"

using Poco::AutoPtr;
using Poco::ClassLoader;
using Poco::Environment;
using Poco::Manifest;
using Poco::NObserver;
using Poco::Net::ErrorNotification;
using Poco::Net::IdleNotification;
using Poco::Net::ReadableNotification;
using Poco::Net::ServerSocket;
using Poco::Net::ShutdownNotification;
using Poco::Net::SocketAcceptor;
using Poco::Net::SocketReactor;
using Poco::Net::StreamSocket;
using Poco::Net::TimeoutNotification;
using Poco::Net::WritableNotification;
using Poco::Path;
using Poco::File;
using Poco::SharedLibrary;
using Poco::Thread;
using Poco::ThreadLocal;
using Poco::Util::Application;
using Poco::Util::HelpFormatter;
using Poco::Util::LoggingConfigurator;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::PropertyFileConfiguration;
using Poco::Util::ServerApplication;

using namespace std;
using namespace Poco::Util;
using namespace Poco::XML;
using namespace ALS::BASE::SRVC;


#include "als/nsap/prov/RFC1006.h"
#include "als/base/util/SharedNetworkBuffer.h"
#include "als/nsap/prov/Provider.h"
#include "als/nsap/prov/Logger.h"
#include "als/tsap/prov/Provider.h"
#include "als/tsap/user/Linker.h"
#include "als/base/srvc/TSAPServices.h"

using ALS::BASE::UTIL::SharedNetworkBuffer;
using ALS::BASE::SRVC::TSAP_SERVICES;
using ALS::NSAP::PROV::RFC1006;


namespace ALS {
namespace NSAP {
class TSAPServiceHandler : 
	public ALS::NSAP::PROV::Provider,
	public ALS::NSAP::SERV::Responder
{
	typedef ClassLoader<ALS::NSAP::USER::Responder>NSAP_USER_ResponserLoader;

	StreamSocket				socket;
	SocketReactor&				reactor;
	RFC1006						rfc1006;
	ALS::NSAP::PROV::Logger		logger;
	NSAPAddr					responding;
	QualityOfService			qualityOfService;
	QualityOfServiceParameters	qosp;
	ALS::NSAP::USER::Responder* responder = nullptr;
	SharedNetworkBuffer				sharedBuffer;

	NSAP_USER_ResponserLoader	nsapUserResponserLoader;

  public:
	TSAPServiceHandler(StreamSocket& socket, SocketReactor& reactor):
		socket(socket),
		reactor(reactor),
		rfc1006(socket),
		logger(0) {
		Application& app = Application::instance();
		app.logger().information("Connection from " + socket.peerAddress().toString());

		reactor.addEventHandler(socket, NObserver<TSAPServiceHandler, ReadableNotification>(*this, &TSAPServiceHandler::onReadable));
		reactor.addEventHandler(socket, NObserver<TSAPServiceHandler, ShutdownNotification>(*this, &TSAPServiceHandler::onShutdown));
		reactor.addEventHandler(socket, NObserver<TSAPServiceHandler, WritableNotification>(*this, &TSAPServiceHandler::onWritable));
		reactor.addEventHandler(socket, NObserver<TSAPServiceHandler, ErrorNotification>(*this, &TSAPServiceHandler::onError));

		responding.stack() = NSAPAddr::NA_TCP;
		responding.community() = NSAPAddr::SUBNET_INTERNET;
		responding.tcp_port() = 102;
		memcpy(responding.tcp_domain(), socket.address().addr(), responding.tcp_length() = socket.address().length());

		string library = "tsap";
		library += Poco::SharedLibrary::suffix();

		nsapUserResponserLoader.loadLibrary(library, "ALS_NSAP_USER_Responder");

		responder = nsapUserResponserLoader.create("ALS::NSAP::USER::Responder");
		responder->NSetTSAPServices(&TSAP_SERVICES);
		responder->nsapServInitiator() = nullptr;
		responder->nsapServResponder() = this;
		responder->NConnectIndication(responding, false, false, qualityOfService, qosp);
	}

	~TSAPServiceHandler() {
		Application& app = Application::instance();
		try {
			app.logger().information("Disconnecting " + socket.peerAddress().toString());
		} catch (...) {
		}
		reactor.removeEventHandler(socket, NObserver<TSAPServiceHandler, ReadableNotification>(*this, &TSAPServiceHandler::onReadable));
		reactor.removeEventHandler(socket, NObserver<TSAPServiceHandler, ShutdownNotification>(*this, &TSAPServiceHandler::onShutdown));
		reactor.removeEventHandler(socket, NObserver<TSAPServiceHandler, WritableNotification>(*this, &TSAPServiceHandler::onWritable));
		reactor.removeEventHandler(socket, NObserver<TSAPServiceHandler, ErrorNotification>(*this, &TSAPServiceHandler::onError));
	}

	void onReadable(const AutoPtr<ReadableNotification>& pNf) {
		ReturnCode rc = DONE;
		try {
			NetworkBuffer* buffer = nullptr;
			int received = rfc1006.recv(buffer);
			if (received == 0) {
				logger.NDisconnectIndication();
				responder->NDisconnectIndication();
				delete this;
				return;
			}
			if (buffer == nullptr)
				return;
			sharedBuffer = SharedNetworkBuffer(buffer);
			logger.NDataIndication(sharedBuffer);
			rc = responder->NDataIndication(sharedBuffer);
			if (rc != DONE)
				delete this;

		} catch (Poco::Net::ConnectionResetException& e) {
			NSAPAddr originator;
			int reason = 0;
			logger.NResetIndication(originator, reason);
			responder->NResetIndication(originator, reason);
			delete this;
		} catch (Poco::Exception& e) {
			logger.log(e);
			logger.NDisconnectIndication();
			responder->NDisconnectIndication();
			delete this;
		} catch (std::exception& e) {
			logger.error(e.what());
			logger.NDisconnectIndication();
			responder->NDisconnectIndication();
			delete this;
		} catch (...) {
			logger.NDisconnectIndication();
			responder->NDisconnectIndication();
			delete this;
		}
#if 0
		POCO_DECLARE_EXCEPTION(Net_API, NetException, Poco::IOException)
		POCO_DECLARE_EXCEPTION(Net_API, InvalidAddressException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, InvalidSocketException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, ServiceNotFoundException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, ConnectionAbortedException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, ConnectionResetException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, ConnectionRefusedException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, DNSException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, HostNotFoundException, DNSException)
		POCO_DECLARE_EXCEPTION(Net_API, NoAddressFoundException, DNSException)
		POCO_DECLARE_EXCEPTION(Net_API, InterfaceNotFoundException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, NoMessageException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, MessageException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, MultipartException, MessageException)
		POCO_DECLARE_EXCEPTION(Net_API, HTTPException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, NotAuthenticatedException, HTTPException)
		POCO_DECLARE_EXCEPTION(Net_API, UnsupportedRedirectException, HTTPException)
		POCO_DECLARE_EXCEPTION(Net_API, FTPException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, SMTPException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, POP3Exception, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, ICMPException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, NTPException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, HTMLFormException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, WebSocketException, NetException)
		POCO_DECLARE_EXCEPTION(Net_API, UnsupportedFamilyException, NetException)
#endif
	}

	void onWritable(const AutoPtr<WritableNotification>& pNf) {
	}
	void onTimeout(const AutoPtr<TimeoutNotification>& pNf)	{
		logger.information("onTimeout ");
	}
	void onIdle(const AutoPtr<IdleNotification>& pNf) {
		logger.information("onIdle ");
	}
	void onShutdown(const AutoPtr<ShutdownNotification>& pNf) {
		logger.information("onShutdown ");
		responder->NDisconnectIndication();
		delete this;
	}
	void onError(const AutoPtr<ErrorNotification>& pNf)	{
		logger.information("onError ");
		responder->NResetIndication(responding, 0);
	}
	virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation) {
		logger.NDataRequest(buffer, confirmation);
		rfc1006.send(buffer);
		return OK;
	}
	virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation) {
		logger.NDataRequest(cc, buffer, confirmation);
		int sended = socket.sendBytes(buffer, cc);
		return OK;
	}
	virtual ReturnCode NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
		logger.NConnectRequest(calling, called, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
		return OK;
	}
	virtual ReturnCode NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
		logger.NConnectResponse(responding, receiptConfirmationSelection, expeditedDataSelection, qualityOfService, qosp, cc, data);
		return OK;
	}
	virtual ReturnCode NDataAcknoledgeRequest() {
		logger.NDataAcknoledgeRequest();
		return OK;
	}
	virtual ReturnCode NExpeditedDataRequest(int cc, const byte* data) {
		logger.NExpeditedDataRequest(cc, data);
		return OK;
	}
	virtual ReturnCode NResetRequest(int reason) {
		logger.NResetRequest(reason);
		return OK;
	}
	virtual ReturnCode NResetResponse() {
		logger.NResetResponse();
		return OK;
	}
	virtual ReturnCode NResetConfirmation() {
		logger.NResetConfirmation();
		return DONE;
	}
	virtual ReturnCode NDisconnectRequest(int reason, const NSAPAddr& responding, int cc, const byte* data) {
		logger.NDisconnectRequest(reason, responding, cc, data);
		return OK;
	}
};

class isod: public Poco::Util::ServerApplication
/// The main application class.
///
/// This class handles command-line arguments and
/// configuration files.
/// Start the isod executable with the help
/// option (/help on Windows, --help on Unix) for
/// the available command line options.
///
/// To use the sample configuration file (isod.properties),
/// copy the file to the directory where the isod executable
/// resides. If you start the debug version of the isod
/// (isod[.exe]), you must also create a copy of the configuration
/// file named isodd.properties. In the configuration file, you
/// can specify the port on which the server is listening .
///
{
  public:
	isod(): help(false) {
	}

	~isod() {
	}

  protected:
	void initialize(Application& self) {
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
	}

	void uninitialize() {
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options) {
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
			.required(false)
			.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value) {
		ServerApplication::handleOption(name, value);

		if (name == "help")
			help = true;
	}

	void displayHelp()	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("An echo server implemented using the Reactor and Acceptor patterns.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args) {
		if (help) {
			displayHelp();
		} else {
			// get parameters from configuration file
			unsigned short port = (unsigned short) config().getInt("port", 102);
			Path AEI;
			if (!Environment::has("ISODE")) {
				cerr << "Missing ISODE environment variable" << endl;
				return Application::EXIT_CONFIG;
			}

			AEI = Environment::get("ISODE");
			AEI.append(config().getString("AEI"));
			AEI.makeFile();

			AEISAXHandler handler;
			SAXParser parser;

			parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
			parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
			parser.setContentHandler(&handler);
			parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER,	static_cast<LexicalHandler*>(&handler));


			parser.parse(AEI.toString());

			// set-up a server socket
			ServerSocket svs(port);
			// set-up a SocketReactor...
			SocketReactor reactor;
			// ... and a SocketAcceptor
			SocketAcceptor<TSAPServiceHandler> acceptor(svs, reactor);
			// run the reactor in its own thread so that we can wait for
			// a termination request
			Thread thread;
			thread.start(reactor);
			// wait for CTRL-C or kill
			waitForTerminationRequest();
			// Stop the SocketReactor
			reactor.stop();
			thread.join();
		}
		return Application::EXIT_OK;
	}

  private:
	bool help;
};
}
}
POCO_SERVER_MAIN(ALS::NSAP::isod)
