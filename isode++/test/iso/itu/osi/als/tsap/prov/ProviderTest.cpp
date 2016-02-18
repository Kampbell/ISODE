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

#include "als/base/srvc/TSAPServices.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/tsap/tpdu/TPCI.h"
#include "als/tsap/tpdu/CR.h"
#include "als/tsap/tpdu/CC.h"
#include "als/tsap/tpdu/DR.h"
#include "als/tsap/tpdu/DC.h"
#include "als/tsap/tpdu/DT.h"
#include "als/tsap/tpdu/ED.h"
#include "als/tsap/tpdu/AK.h"
#include "als/tsap/tpdu/EA.h"
#include "als/tsap/tpdu/RJ.h"
#include "als/tsap/tpdu/ER.h"

using namespace std;
using namespace ALS::NSAP::ADDR;
using namespace ALS::TSAP::TPDU;
using ALS::BASE::SRVC::TSAPServices;
using ALS::TSAP::TPDU::TPCI;

#include "ProviderTest.h"

typedef ClassLoader<ALS::NSAP::USER::Responder>NSAP_USER_ResponserLoader;
NSAP_USER_ResponserLoader	nsapUserResponserLoader;

static TSAPServices	tsapServices;

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
		{
			TPDU::DT dt;
			dt.setData(1, (const byte*)"1");
			unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
			dt.encode(nsdu);
			buffer = nsdu.release();
			SharedNetworkBuffer dtb(buffer);
			rc = responder->NDataIndication(dtb);
		}
		{
			TPDU::DT dt;
			dt.setData(2, (const byte*)"23");
			unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
			dt.encode(nsdu);
			buffer = nsdu.release();
			SharedNetworkBuffer dtb(buffer);
			rc = responder->NDataIndication(dtb);
		}
		{
			TPDU::DT dt;
			dt.setData(3, (const byte*)"456");
			unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
			dt.encode(nsdu);
			buffer = nsdu.release();
			SharedNetworkBuffer dtb(buffer);
			rc = responder->NDataIndication(dtb);
		}
		{
			TPDU::DT dt;
			dt.setData(4, (const byte*)"7890");
			dt.setEOT();
			unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
			dt.encode(nsdu);
			buffer = nsdu.release();
			SharedNetworkBuffer dtb(buffer);
			rc = responder->NDataIndication(dtb);
		}
		{
			rc = responder->NDisconnectIndication();
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
ReturnCode ProviderTest::NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	return OK;
}
ReturnCode ProviderTest::NDataRequest(NetworkBuffer* buffer, bool confirmation) {
	TPCI* tpdu = nullptr;
	tpdu = TPCI::decodeTPDU(buffer);
	switch (tpdu->code()) {
	case TPCI::TPDU_CC: {
		if (state == STATE::WFCC) {
			state = STATE::OPEN;
		} else {
			poco_assert(false);
		}
	}
	break;
	case TPCI::TPDU_DT: {
		if (state == STATE::OPEN) {
			TPDU::DT& dt = *(TPDU::DT*)tpdu;
			NetworkBuffer* buffer = dt.data();
			if (buffer && buffer->hasRemaining()) {
				cout << string(buffer->data(), buffer->remaining()) << endl;
			}
			switch (test) {
			case TestType::Assembly:
				poco_assert(string(buffer->data(), buffer->remaining()) == "1234567890");
				break;
			}
		} else {
			poco_assert(false);
		}
	}
	break;
	case TPCI::TPDU_DR: {
		TPDU::DR& dr = *(TPDU::DR*)tpdu;
		NetworkBuffer* buffer = dr.data();
		if (buffer && buffer->hasRemaining()) {
			cout << string(buffer->data(), buffer->remaining()) << endl;
		}
	}
	break;
	default:
		break;
	}
	return OK;
}
ReturnCode ProviderTest::NDataRequest(int cc, byte* buffer, bool confirmation) {
	return OK;
}

ReturnCode ProviderTest::NDataAcknoledgeRequest() {
	return OK;
}
ReturnCode ProviderTest::NExpeditedDataRequest(int cc, const byte* buffer) {
	return OK;
}
ReturnCode ProviderTest::NDisconnectRequest(int reason, const NSAPAddr& responding, int cc, const byte* buffer) {
	return OK;
}
ReturnCode ProviderTest::NResetRequest(int reason) {
	return OK;
}
ReturnCode ProviderTest::NResetResponse() {
	return OK;
}
void ProviderTest::setUp() {

//	loadConfiguration(); // load default configuration files, if present

	string library = "tsap";
	library += Poco::SharedLibrary::suffix();

	nsapUserResponserLoader.loadLibrary(library, "ALS_NSAP_USER_Responder");

	responder = nsapUserResponserLoader.create("ALS::NSAP::USER::Responder");
	responder->nsapServInitiator();
	responder->nsapServResponder() = this;
	responder->NConnectIndication(responding, false, false, qos, qosp);

	tsapAddr.parse("#2/localhost");
	tsapServices.add("responder", "#2", "TSAPTestSuiteResponder", "tsap-testsuite-responder");
	responder->NSetTSAPServices(&tsapServices);
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
