//============================================================================
// Name        : EchoClient.cpp
// Author      : FA
// Version     :
// Copyright   : Your copyright notice
// Description : ASAP EchoClient
//============================================================================

#include <sstream>
#include <fstream>
#include <iostream>
#include "Poco/DateTime.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/Util/LoggingConfigurator.h"
#include "Poco/Util/PropertyFileConfiguration.h"
#include "Poco/AutoPtr.h"
#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/NObserver.h"
#include "Poco/Exception.h"
#include "Poco/Semaphore.h"
#include "Poco/Thread.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Random.h"
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
using Poco::Semaphore;
using Poco::NObserver;
using Poco::AutoPtr;
using Poco::Thread;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::LoggingConfigurator;
using Poco::Util::PropertyFileConfiguration;
using Poco::AutoPtr;
using Poco::Random;

#include "asn1/csn/ASN.h"
using namespace ASN;

#include "als/base/root/Logger.h"
#include "als/nsap/addr/PSAPAddr.h"
#include "als/ssap/Literal.h"
#include "als/ssap/ActivityId.h"
#include "als/ssap/Token.h"
#include "als/ssap/AbortCode.h"
#include "als/ssap/Requirement.h"
#include "als/psap/TransfertSyntaxes.h"
#include "als/asap/user/Initiator.h"
#include "als/asap/serv/Initiator.h"
#include "als/asap/prov/Provider.h"

using ALS::BASE::ROOT::Logger;
using ALS::SSAP::ActivityId;
using ALS::SSAP::Literal;
using ALS::SSAP::Token;
using ALS::SSAP::Requirement;
using ALS::SSAP::PROV::Provider;
using ALS::SSAP::USER::Initiator;
using ALS::PSAP::TransfertSyntaxes;


using namespace std;

using namespace ALS::NSAP::ADDR;

Semaphore semaphore(0, 1);

namespace ALS {
	namespace ASAP {

enum Mode {
	sink,
	echo
};
enum Request {
	REQUEST_NORMAL,
	REQUEST_EXPEDITED,
	REQUEST_TYPED,
	REQUEST_CAPABILITY,
};



class PresentationContext {
public:
	static const int		NPCTX		= 8;

private:
	int						pci;
	Abstract_syntax_name	asn;
	Transfer_syntax_name	tsn;
	int						rc;

public:
	PresentationContext() {
	}
	PresentationContext(int pci, const Abstract_syntax_name& asn) {
		this->pci = pci;
		this->asn = asn;
	}

	PresentationContext(int pci, const Abstract_syntax_name& asn, const Transfer_syntax_name& tsn) {
		this->pci = pci;
		this->asn = asn;
		this->tsn = tsn;
	}

protected:
	void setAccepted(const Transfer_syntax_name& tsn) {
		rc = accepted;
		this->tsn = tsn;
	}

public:
	string toString() {
		return "PresentationContext FIXME";// + pci + ':' + asn + ':' + tsn;
	}
};

const Transfer_syntax_name	TRANSFERT_SYNTAX_NAMES[] {
	TransfertSyntaxes::BER, 
	TransfertSyntaxes::DER,
	TransfertSyntaxes::PER_BA,
	TransfertSyntaxes::XER_B 
};
const int TRANSFERT_SYNTAX_NAMES_LENGTH = sizeof(TRANSFERT_SYNTAX_NAMES) / sizeof(Transfer_syntax_name);

class ASAPEchoClient : 
	public Poco::Util::ServerApplication, 
	public ALS::ASAP::USER::Initiator,
	public ALS::SSAP::Token {
private:
	Mode										mode	= echo;
	bool										isacs	= true;
	bool										isrts	= false;
	int											owned	= 0;
	int											avail	= 0;
	Presentation_requirements*					presentationRequirements;
	User_session_requirements*					sessionRequirements;
	string										pmessage;
	bool										timer = false;
	PresentationContext							datactxs[PresentationContext::NPCTX];
	User_data*									user_data		= nullptr;
	Presentation_context_definition_list		contexts;
	Presentation_context_definition_result_list	results;
	int											status		= 0;
	Request										request;
	OssOpen										pe;
	OssOpen										udata[3];
	Request										datamodes[4];
	ALS::ASAP::SERV::Initiator*				initiator = nullptr;
	Mode_selector								modeSelector;
	Application_context_name 					applicationContext;
	Application_context_name_list 				applicationContexts;
	AP_title									callingAPtitle;
	AE_qualifier								callingAEqualifier;
	AP_invocation_identifier					callingAPInvocationIdentifier;
	AE_invocation_identifier					callingAEInvocationIdentifier;
	AP_title									calledAPtitle;
	AE_qualifier								calledAEqualifier;
	AP_invocation_identifier					calledAPInvocationIdentifier;
	AE_invocation_identifier					calledAEInvocationIdentifier;
	ACSE_requirements 							senderACSERequirements;
	Mechanism_name 								mechanism;
	Authentication_value 						authentification;
	Implementation_data 						implementation;
	PresentationAddress							callingPresentationAddress;
	PresentationAddress 						calledPresentationAddress;
	Presentation_context_definition_list		presentationContexts;
	Default_context_name 						defaultContext;
	SSN 										isn;
	byte 										settings;
	Reference									reference;
	QualityOfService				 			qualityOfService;

	Abstract_syntax_name asn;
	Default_context_name dcn;

	byte				foo[13];
public:
	ASAPEchoClient() {
		reference = Reference(6, "idefix");
		sessionRequirements = new User_session_requirements(13, foo);
		(*sessionRequirements)[half_duplex] = true;
		(*sessionRequirements)[duplex] = true;
		(*sessionRequirements)[expedited_data] = true;
		(*sessionRequirements)[minor_synchronize] = true;
		(*sessionRequirements)[major_synchronize] = true;
		(*sessionRequirements)[resynchronize] = true;
		(*sessionRequirements)[activity_management] = true;
		(*sessionRequirements)[negotiated_release] = true;
		(*sessionRequirements)[capability_data] = true;
		(*sessionRequirements)[exceptions] = true;
		(*sessionRequirements)[typed_data] = true;
		(*sessionRequirements)[symmetric_synchronize] = true;
		(*sessionRequirements)[data_separation] = true;

		initiator = new ALS::ASAP::PROV::Provider();
	}

	AttributeTypeAndDistinguishedValue makeCountryName(const string& countryName) {
//		if (countryName.length() == 0)
//			throw  IllegalArgumentException();
		AttributeTypeAndDistinguishedValue countryNameATDV;
		const CountryName cn(countryName.c_str());
		SupportedAttributes_Type v;
		countryNameATDV.set_type(id_at_countryName);
		countryNameATDV.set_value(v);       ;//.set_value(cns);
		return countryNameATDV;
	}
	RDNSequence getRDN() {
		RDNSequence	rdnseq;
		RelativeDistinguishedName rdn;
		const AttributeTypeAndDistinguishedValue dn;
		const AttributeTypeAndDistinguishedValue o;
		const AttributeTypeAndDistinguishedValue ou1;
		const AttributeTypeAndDistinguishedValue ou2;
		const AttributeTypeAndDistinguishedValue cn;
		RDNSequence::component dnc;
		
		OssIndex no;
		no = rdn.insert_after(no, dn);
		no = rdn.insert_after(no, o);
		no = rdn.insert_after(no, ou1);
		no = rdn.insert_after(no, ou2);

		rdnseq.insert_after(no, rdn);

		return rdnseq;
	}
protected:
	void initialize(Application& self)
	{
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
	}

	void uninitialize()
	{
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value)
	{
		ServerApplication::handleOption(name, value);

		if (name == "help")
			help = true;
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("An echo client implemented using the Reactor and Acceptor patterns.");
		helpFormatter.format(std::cout);
	}
	ReturnCode AAssociateConfirmation(
		const Associate_result&								result,
		const Associate_source_diagnostic&					diagnostic,
		const Application_context_name&						applicationContext,
		const Application_context_name_list&				applicationContexts,
		const AP_title&										respondingAPtitle,
		const AE_qualifier&									respondingAEqualifier,
		const AP_invocation_identifier&						respondingAPInvocationIdentifier,
		const AE_invocation_identifier&						respondingAEInvocationIdentifier,
		const ACSE_requirements&							senderACSERequirements,
		const Mechanism_name&								mechanism,
		const Authentication_value&							authentification,
		const PresentationAddress&							respondingPresentationAddress,
		const Presentation_context_definition_result_list&	presentationResults,
		int													defaultContextResult,
		const QualityOfService&								qualityOfService,
		const Presentation_requirements&					presentationRequirements,
		const User_session_requirements&					sessionRrequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const Association_information*						userInformation) {
		return DONE;
	}
	ReturnCode AReleaseIndication(const Release_request_reason& requestReason, const Association_information* userInformation) {
		return DONE;
	}
	ReturnCode AReleaseConfirmation(bool affirmative, const Release_response_reason& responseReason, const Association_information* userInformation) {
		return DONE;
	}
	ReturnCode AAbortIndication(const ABRT_source& source, const ABRT_diagnostic& diagnostic, const Association_information* userInformation) {
		return DONE;
	}
	ReturnCode APAbortIndication(int reason, int extension,  const Association_information* userInformation) {
		return DONE;
	}
	void perform() {
		ReturnCode rc;
		PSAPAddr psapaddr;
		const char* addr = "#128//TELEX+00728722+RFC-1006+03+127.0.0.1";
		psapaddr.parse(addr);
		SSAPAddr calling;
		SSAPAddr called = psapaddr.ssapaddr();
		OssEncOID oid;

		applicationContext.setDotValNotation("1.17.0.1.1");

		OssEncOID syntax("");
		OssIndex ossno;

		for(int no = 0; no < PresentationContext::NPCTX; no++) {
			datactxs[no] = PresentationContext(no * 2 + 1, asn, 
				TRANSFERT_SYNTAX_NAMES[no % TRANSFERT_SYNTAX_NAMES_LENGTH ]);
			Presentation_context_definition_list::component context;
			context.set_presentation_context_identifier(no * 2  + 1);
			context.set_abstract_syntax_name(syntax);
			contexts.insert_after(ossno, context);
		}

		Association_information information;
		for (int no = 0; no < sizeof(udata) / sizeof(udata[0]); no++) {
			OssHugeInt integer(1, (const unsigned char*)"1");
			//udata[no] = integer; // = new Asn1IntegerType(no);
			Association_information::component element;
			//element.set_indirect_reference((no % contexts.size()) * 2 + 1);
			//element.single_ASN1_type().setValue(udata[no]);
			//element.set_data_value_descriptor(udata[no])
			information.insert_after(ossno, element);
		}

		rc = initiator->AAssociateRequest(
			mode, applicationContext, applicationContexts, 
			callingAPtitle, callingAEqualifier, callingAPInvocationIdentifier, callingAEInvocationIdentifier, 
			calledAPtitle, calledAEqualifier, calledAPInvocationIdentifier, calledAEInvocationIdentifier, 
			senderACSERequirements, mechanism, authentification, implementation,
			callingPresentationAddress, calledPresentationAddress, 
			presentationContexts, defaultContext, 
			*presentationRequirements, *sessionRequirements, 
			isn, settings, reference, qualityOfService, 
			&information);

	}

	private:
		void acquire() {
			semaphore.wait();
		}

		void release() {
			semaphore.set();
		}

		ReturnCode ss_adios(const char* message) {
		return NOTOK;
	}
	int main(const std::vector<std::string>& args)
	{
		if (help){
			displayHelp();
		}else{
			ifstream istr;
			istr.open("initiator.properties");
			AutoPtr<PropertyFileConfiguration> pConfig = new PropertyFileConfiguration(istr);
			LoggingConfigurator configurator;
			configurator.configure(pConfig);
			istr.close();

			// get parameters from configuration file
			unsigned short port = 102;//(unsigned short) config().getInt("SSAPEchoClient.port", 9977);
			perform();

		}
		return Application::EXIT_OK;
	}

private:
	bool help;
};
}
}

int main(int argc, char** argv)
{
	ALS::ASAP::ASAPEchoClient app;
	try {
		return app.run(argc, argv);
	}
	catch (const Poco::Exception& e) {
		Application& app = Application::instance();
		app.logger().log(e);
	}
	catch (const std::exception& e) {
		Application& app = Application::instance();
		app.logger().error(e.what());
	}
	catch (...) {
		Application& app = Application::instance();
		app.logger().error("unknown exception");
	}
}
