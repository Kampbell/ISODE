#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Exception.h"
#include "Poco/Event.h"
#include "Poco/AtomicCounter.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include "als/nsap/addr/PSAPAddr.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/serv/Initiator.h"
#include "als/tsap/prov/Provider.h"

using Poco::Event;
using Poco::AtomicCounter;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::LoggingConfigurator;
using Poco::Util::PropertyFileConfiguration;
using Poco::AutoPtr;

using namespace std;
using ALS::NSAP::QualityOfService;
using ALS::BASE::UTIL::NetworkBuffer;
using namespace ALS::NSAP::ADDR;

namespace ALS {
namespace TSAP {
class TSAPEchoClient :
	public Poco::Util::Application,
	public ALS::TSAP::USER::Initiator
/// The main application class.
///
/// This class handles command-line arguments and configuration files.
/// Start the TSAPEchoClient executable with the help option (/help on Windows, 
/// --help on Unix) for the available command line options.
///
/// To use the sample configuration file (TSAPEchoClient.properties),
/// copy the file to the directory paths where the TSAPEchoClient executable
/// resides. 
{
  private:
	AtomicCounter	round;
	Event			event;
	ALS::TSAP::PROV::Provider* provider;

  public:
	TSAPEchoClient() : help(false) {
		provider = new ALS::TSAP::PROV::Provider(this);
	}

	~TSAPEchoClient() {
		delete provider;
	}

	ReturnCode TConnectConfirmation(const TSAPAddr & responding, bool expedited, const QualityOfService &, int tsdusize, NetworkBuffer * data) {
		return DONE;
	}
	ReturnCode TDataIndication(const SharedNetworkBuffer& data) {
		provider->logger().information(string(data->data(), data->remaining()));
		if (--round == 0)
			event.set();
		return DONE;
	}
	ReturnCode TExpeditedDataIndication(const SharedNetworkBuffer& data) {
		return DONE;
	}
	ReturnCode TDisconnectIndication(int reason, const string& data) {
		exit = true;
		return DONE;
	}
  protected:
	void initialize(Application& self) {
		loadConfiguration(); // load default configuration files, if present
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

		if (name == "help")
			help = true;
	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("An echo client above the TSAP layer.");
		helpFormatter.format(std::cout);
	}

	void perform(const char* addr) {
		ReturnCode rc;
		PSAPAddr psapaddr;
		psapaddr.parse(addr);
		TSAPAddr calling;
		TSAPAddr called = psapaddr.ssapaddr().tsapaddr();
		QualityOfService qualityOfService;

		rc = provider->TConnectRequest(128, calling, called, false, qualityOfService);
		if (rc != OK)
			return;
		byte bytes[256] = { 1 };
		memset(bytes, '9', sizeof(bytes));
		for (int no = 1; no <= 10; no++) {
			bytes[no - 1] = '0' + no;
			if (exit)
				break;
			++round;
			rc = provider->TDataRequest(124 + no, bytes);
		}
		event.wait();
		if (!exit)
			rc = provider->TDisconnectRequest(0, calling);
	}
	int main(const std::vector<std::string>& args) {
		if (help) {
			displayHelp();
		} else {
			// get parameters from configuration file
			unsigned short port = (unsigned short) config().getInt("port", 102);
			const char* addr;
//			addr = #128/localhost=102";
			addr = "#128/TELEX+00728722+RFC-1006+03+127.0.0.1";

			perform(addr);

		}
		return Application::EXIT_OK;
	}

  private:
	bool help;
	bool exit = false;
};
}
}
POCO_APP_MAIN(ALS::TSAP::TSAPEchoClient)
