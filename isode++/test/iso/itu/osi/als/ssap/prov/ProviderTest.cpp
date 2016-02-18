#include <iostream>
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "Poco/File.h"
#include "Poco/Exception.h"
#include "Poco/ClassLoader.h"
#include "Poco/UnicodeConverter.h"
using Poco::UnicodeConverter;
using Poco::ClassLoader;
using Poco::Manifest;
using Poco::File;
using Poco::SystemException;

#include "als/base/srvc/SSAPServices.h"
#include "als/nsap/addr/PSAPAddr.h"

using namespace std;
using namespace ALS::NSAP::ADDR;
using namespace ALS::TSAP::TPDU;
using ALS::BASE::SRVC::SSAPServices;

#include "ProviderTest.h"

typedef ClassLoader<ALS::TSAP::USER::Responder>NSAP_USER_ResponserLoader;
NSAP_USER_ResponserLoader	nsapUserResponserLoader;

static SSAPServices	ssapServices;

namespace ALS {
namespace TSAP {
namespace PROV {

ProviderTest::ProviderTest(const std::string& name) :
	logger(0), CppUnit::TestCase(name) {
}


ProviderTest::~ProviderTest() {
}
void ProviderTest::testTPDUAssembly() {
	ReturnCode rc = DONE;
	try {
		NetworkBuffer* buffer;
		const char* addr = "#2/localhost=102";
#if 0
		PSAPAddr psapaddr;
		psapaddr.parse(addr);
		TSAPAddr calling;
		TSAPAddr called = psapaddr.ssapaddr().tsapaddr();
#endif
		test = TestType::Assembly;

		{
			state = STATE::CLOSED;
			TPDU::CR cr;
			cr.dstref(1);
			cr.srcref(2);
			cr.klass(TPDU::C::TP0);
			const byte sel[2] = { 0, 2 }; // #2/localhost
			cr.called(2, sel);
			unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
			cr.encode(nsdu);
			buffer = nsdu.release();
			SharedNetworkBuffer crb(buffer);
			state = STATE::WFCC;
			rc = responder->NDataIndication(crb);
		}
	} catch (Poco::Exception& e) {
		logger.log(e);
		responder->NDisconnectIndication();
	} catch (std::exception& e) {
		responder->NDisconnectIndication();
	} catch (...) {
		responder->NDisconnectIndication();
	}
}
void ProviderTest::setUp() {

//	loadConfiguration(); // load default configuration files, if present

	string library = "ssap";
	library += Poco::SharedLibrary::suffix();

	nsapUserResponserLoader.loadLibrary(library, "ALS_TSAP_USER_Responder");

	responder = nsapUserResponserLoader.create("ALS::TSAP::USER::Responder");

	ssapAddr.parse("#2//localhost");
	ssapServices.add("responder", "#2", "TSAPTestSuiteResponder", "tsap-testsuite-responder");
	responder->setSSAPServices(&ssapServices);
}
void ProviderTest::tearDown() {

}
CppUnit::Test* ProviderTest::suite() {
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("ProviderTest");

	CppUnit_addTest(pSuite, ProviderTest, testTPDUAssembly);

	return pSuite;
}
void ProviderTest::getPath(Poco::Path& appPath) const {
#if defined(POCO_OS_FAMILY_UNIX) && !defined(POCO_VXWORKS)
	if (_command.find('/') != std::string::npos) {
		Path path(_command);
		if (path.isAbsolute()) {
			appPath = path;
		} else {
			appPath = _workingDirAtLaunch;
			appPath.append(path);
		}
	} else {
		if (!Environment::has("PATH") || !Path::find(Environment::get("PATH"), _command, appPath))
			appPath = Path(_workingDirAtLaunch, _command);
		appPath.makeAbsolute();
	}
#elif defined(POCO_OS_FAMILY_WINDOWS)
#if defined(POCO_WIN32_UTF8) && !defined(POCO_NO_WSTRING)
	wchar_t path[1024];
	int n = GetModuleFileNameW(0, path, sizeof(path)/sizeof(wchar_t));
	if (n > 0) {
		std::string p;
		Poco::UnicodeConverter::toUTF8(path, p);
		appPath = p;
	} else throw SystemException("Cannot get application file name.");
#else
	char path[1024];
	int n = GetModuleFileNameA(0, path, sizeof(path));
	if (n > 0)
		appPath = path;
	else
		throw SystemException("Cannot get application file name.");
#endif
#else
	appPath = _command;
#endif
}
bool ProviderTest::findFile(Poco::Path& path) const {
	if (path.isAbsolute()) return true;

	Path appPath;
	getPath(appPath);
	Path base = appPath.parent();
	do {
		Path p(base, path);
		File f(p);
		if (f.exists()) {
			path = p;
			return true;
		}
		if (base.depth() > 0) base.popDirectory();
	} while (base.depth() > 0);
	return false;
}
}
}
}
