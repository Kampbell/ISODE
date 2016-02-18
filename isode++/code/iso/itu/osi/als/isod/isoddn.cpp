//============================================================================
// Name        : nsapd.cpp
// Author      : FA
// Version     :
// Copyright   : Copyright Kampbell.net All Right Reserved
// Description : The nsapd daemon listening on port 102 service(iso-tsap) on IANA records
//============================================================================

#include <memory>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>


#include "Poco/ByteOrder.h"
#include "Poco/ClassLoader.h"
#include "Poco/DateTime.h"
#include "Poco/Delegate.h"
#include "Poco/Exception.h"
#include "Poco/Logger.h"
#include "Poco/Manifest.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/SAX/SAXParser.h"
#include "Poco/SharedLibrary.h"
#include "Poco/Thread.h"
#include "Poco/Timespan.h"
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/XMLConfiguration.h"

#include "als/base/srvc/AEISAXHandler.h"

#include "als/nsap/prov/RFC1006.h"
#include "als/base/util/NetworkBuffer.h"
#include "als/nsap/prov/Provider.h"
#include "als/nsap/prov/Logger.h"
#include "als/tsap/prov/Provider.h"
#include "als/tsap/user/Linker.h"

using Poco::Util::LoggingConfigurator;
using Poco::Util::PropertyFileConfiguration;
using Poco::AutoPtr;
//using Poco::ThreadLocal;
using Poco::ClassLoader;
using Poco::Manifest;



using Poco::Net::TCPServerConnectionFactoryImpl;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServerConnection;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::TCPServerParams;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnection;
using Poco::AutoPtr;
using Poco::Thread;
using Poco::delegate;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::ByteOrder;
using Poco::Timespan;

using namespace std;
using namespace Poco::Util;
using namespace Poco::XML;
using namespace ALS::BASE::SRVC;
using ALS::NSAP::PROV::RFC1006;
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


namespace ALS {
	namespace NSAP {

		template <class S, class Arg>
		class ConnectionFactory : public TCPServerConnectionFactory {
		private:
			const Arg& arg;

		public:
			ConnectionFactory(const Arg& arg) : arg(arg) { }
			~ConnectionFactory() {	}

			TCPServerConnection* createConnection(const StreamSocket& socket) {
				return new S(socket, arg);
			}
		};


		typedef ClassLoader<USER::Responder>USER_ResponserLoader;

		class Connection : public TCPServerConnection, public ALS::NSAP::PROV::Provider {
		private:
			RFC1006						rfc1006;
			ALS::NSAP::PROV::Logger		logger;
			NSAPAddr					responding;
			QualityOfService			qualityOfService;
			QualityOfServiceParameters	qosp;
			ALS::NSAP::USER::Responder* responder = nullptr;

			USER_ResponserLoader		userResponderLoader;

		public:
			Connection(const StreamSocket& socket, const string& library) :
				TCPServerConnection(socket),
				rfc1006(socket),
				logger(0){
				Application& app = Application::instance();
				app.logger().information("Connection from " + socket.peerAddress().toString());

				responding.stack() = NSAPAddr::NA_TCP;
				responding.community() = NSAPAddr::SUBNET_INTERNET;
				responding.tcp_port() = 102;
				memcpy(responding.tcp_domain(), socket.address().addr(), responding.tcp_length() = socket.address().length());

				userResponderLoader.loadLibrary(library, "ALS_NSAP_USER_Responder");

				responder = userResponderLoader.create("ALS::NSAP::USER::Responder");
				responder->nsapServInitiator() = nullptr;
				responder->nsapServResponder() = this;
				responder->NConnectIndication(responding, false, false, qualityOfService, qosp);
			}

			void run() {
				Application& app = Application::instance();
				app.logger().information("Connection    from: " + socket().peerAddress().toString());

				//				SocketChannel socketChannel(&logger, socket());
				bool shutdown = false;
				Exception* exception = nullptr;

				ReturnCode rc = DONE;
				while (!shutdown) {
					int received = -1;
					try {
						//						received = socketChannel.recv(is);
						NetworkBuffer* buffer = nullptr;
						received = rfc1006.recv(buffer);
						if (received == 0 || buffer == nullptr) {
							logger.NDisconnectIndication();
							responder->NDisconnectIndication();
							shutdown = true;
							continue;
						}
						SharedNetworkBuffer shared_buffer(buffer);
						logger.NDataIndication(shared_buffer);
						rc = responder->NDataIndication(shared_buffer);
						if (rc != DONE)
							shutdown = true;
					}
					catch (Poco::Net::ConnectionResetException& e) {
						NSAPAddr originator;
						int reason = 0;
						logger.NResetIndication(originator, reason);
						responder->NResetIndication(originator, reason);
						shutdown = true;
					}
					catch (Poco::Exception& e) {
						logger.log(e);
						logger.NDisconnectIndication();
						responder->NDisconnectIndication();
						shutdown = true;
					}
					catch (std::exception& e) {
						logger.error(e.what());
						logger.NDisconnectIndication();
						responder->NDisconnectIndication();
						shutdown = true;
					}
					catch (...) {
						logger.NDisconnectIndication();
						responder->NDisconnectIndication();
						shutdown = true;
					}
				}
				socket().shutdown();
				logger.information("Disconnecting from: " + socket().peerAddress().toString());
			}
			virtual ReturnCode NDataRequest(NetworkBuffer* buffer, bool confirmation) {
				logger.NDataRequest(buffer, confirmation);
				rfc1006.send(buffer);
				return OK;
			}
			virtual ReturnCode NDataRequest(int cc, byte* buffer, bool confirmation) {
				logger.NDataRequest(cc, buffer, confirmation);
				int sended = socket().sendBytes(buffer, cc);
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

		class nsapd : public ServerApplication {
		private:
			bool _helpRequested;

		public:
			nsapd() : _helpRequested(false)	{ }
			~nsapd() { }

		protected:
			void initialize(Application& self) {
				loadConfiguration();
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
					_helpRequested = true;
			}

			void displayHelp() {
				HelpFormatter helpFormatter(options());
				helpFormatter.setCommand(commandName());
				helpFormatter.setUsage("OPTIONS");
				helpFormatter.setHeader("A ISO nsapd server.");
				helpFormatter.format(std::cout);
			}

			int main(const std::vector<std::string>& args) {
				if (_helpRequested)	{
					displayHelp();
				}
				else	{
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
					parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER, static_cast<LexicalHandler*>(&handler));

					parser.parse(AEI.toString());


					// get parameters from configuration file
					unsigned short port = (unsigned short)config().getInt("port", 102);

					ServerSocket serverSocket(port);

					//Configure some server params.
					TCPServerParams* tcpParameters = new Poco::Net::TCPServerParams();
					tcpParameters->setMaxThreads(4);
					tcpParameters->setMaxQueued(4);
					tcpParameters->setThreadIdleTime(100);

					string library = config().getString("library", "tsap");
					library += Poco::SharedLibrary::suffix();

					//Create server 
					TCPServerConnectionFactory* connectionFactory;
					connectionFactory = new ConnectionFactory<Connection, string>(library);
					TCPServer nsapd(connectionFactory, serverSocket, tcpParameters);
					nsapd.start();

					while (1);

				}
				return Application::EXIT_OK;
			}
		};
	}
}
POCO_SERVER_MAIN(ALS::NSAP::nsapd)

