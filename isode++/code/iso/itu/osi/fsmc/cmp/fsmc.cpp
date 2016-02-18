#include <sstream>
#include <fstream>
#include <iostream>

using std::cout;
using std::cerr;
using std::clog;
using std::hex;
using std::endl;

#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/Exception.h"
#include "Poco/Thread.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/OptionCallback.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/FileStream.h"
#include "fsmc/smc/smc.h"
#include "fsmc/smc/FSM.h"
#include "fsmc/smc/Print.h"
#include "fsmc/cmp/Parser.h"

using Poco::Thread;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::Util::LoggingConfigurator;
using Poco::Util::PropertyFileConfiguration;
using Poco::Path;
using Poco::File;
using Poco::FileStream;
using Poco::FileInputStream;
using Poco::FileOutputStream;

using ALS::SMC::PARSER::Parser;
using ALS::SMC::MODEL::Print;

const static string NL = "\n";

class FSMCompiler: public Application {
public:
	FSMCompiler() {

	}
protected:
	void initialize(Application& self) {
		loadConfiguration(); // load default configuration files, if present
		Application::initialize(self);
	}

	void uninitialize() {
		Application::uninitialize();
	}

	void reinitialize(Application& self)
	{
		Application::reinitialize(self);
	}
	void defineOptions(OptionSet& options) {
		Application::defineOptions(options);

		options.addOption(
				Option("help", "h",	"display help information on command line arguments")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<FSMCompiler>(this, &FSMCompiler::handleHelp)));

		options.addOption(
				Option("out", "o", "the out directory where to generate the c++ code, defaulted to the fsm file directory")
				.required(false)
				.repeatable(false)
				.argument("file")
				.callback(OptionCallback<FSMCompiler>(this, &FSMCompiler::handleOutdir)));

		options.addOption(
				Option("verbose", "v", "output the parsed SMC file on the console")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<FSMCompiler>(this, &FSMCompiler::handleVerbose)));

		options.addOption(
				Option("debug", "d", "generate debug log")
				.required(false)
				.repeatable(false)
				.callback(OptionCallback<FSMCompiler>(this, &FSMCompiler::handleDebug)));

	}

	void handleHelp(const std::string& name, const std::string& value)
	{
		help = true;
		displayHelp();
		stopOptionsProcessing();
	}

	void handleOutdir(const std::string& name, const std::string& value) {
		out = Path(value);
	}
	void handleVerbose(const std::string& name, const std::string& value) {
		verbose = true;
	}

	void handleDebug(const std::string& name, const std::string& value) {
		debug = true;
	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("<options> <fsm>.sm");
		helpFormatter.setHeader("A FiniteStateMachine compiler for the ISODE++ stack.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args) {
		Logger& logger = Application::instance().logger();
		if (!help) {
			if (args.size() == 0) {
				logger.error("Missing <fsm>.sm file");
				return Application::EXIT_NOINPUT;
			}
			smPath = args[0];
			if (!smPath.isFile()) {
				logger.error("file %s is not a file", smPath.toString());
				return Application::EXIT_USAGE;
			}
			if (smPath.getExtension() != "sm") {
				logger.error("file %s is not a SMC file", smPath.toString());
				return Application::EXIT_USAGE;
			}
			if (!out.isDirectory()) {
				logger.error("%s is not a directory", out.toString());
				return Application::EXIT_USAGE;
			}
			if (out.depth() <= 0) {
				out = smPath;
				out = out.makeParent();
			}
			smFile = File(smPath.makeAbsolute());
			logger.information("fsmc %s", smPath.toString());

			FileInputStream fis(smPath.toString());
			Parser parser(logger, smFile, fis);
			FSMPtr fsm;

			fsm = parser.parse(out);
			if (fsm && !fsm->updated()) {
				Print print(logger);
				if (verbose)
					fsm->print(print);
				fsm->generate(out, debug);
			}
		}
		return Application::EXIT_OK;
	}

private:
	bool	help = false;
	bool	verbose = false;
	bool	debug = false;
	Path	out;
	Path	smPath;
	File	smFile;
};
POCO_APP_MAIN(FSMCompiler)

#if 0
int main(int argc, char* argv[]) {
	FSMCompiler app(argc, argv);
	try {
		return app.run();
	} catch (const Poco::Exception& e) {
		Application& app = Application::instance();
		app.logger().log(e);
	} catch (const std::exception& e) {
		Application& app = Application::instance();
		app.logger().error(e.what());
	} catch (...) {
		Application& app = Application::instance();
		app.logger().error("unknown exception");
	}
	return 0;
}
#endif
