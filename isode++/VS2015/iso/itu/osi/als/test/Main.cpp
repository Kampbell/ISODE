#include <iostream>
#include "Poco/Util/AbstractConfiguration.h"
#include "Poco/Util/XMLConfiguration.h"
#include "Poco/SAX/SAXParser.h"
#include "als/base/srvc/AEISAXHandler.h"
#include "als/nsap/addr/RFC_1006.h"
#include "als/base/srvc/TSAPService.h"
#include "als/base/srvc/TSAPServices.h"
#include "als/base/srvc/SSAPService.h"
#include "als/base/srvc/SSAPServices.h"
#include "als/base/srvc/PSAPService.h"
#include "als/base/srvc/PSAPServices.h"

using namespace Poco::XML;
using namespace ALS::BASE::SRVC;
using namespace ALS::NSAP::ADDR;
using namespace Poco::Util;
using namespace std;


class OssFunctor {
public:
	virtual void  operator()(const string& s) = 0;
};

class MyFunctor : public OssFunctor {
private:
	ostream&	out;
	int no = 1;
public:
	MyFunctor(ostream& os) : out(os) {}
	virtual void  operator()(const string& s) { out << "line " << no++ << " : " << s << endl; }
};
void printPDU(OssFunctor& functor) {
	functor("first line");
	functor("second line");
	functor("third line");
}
#if 0
int main(int argc, char** argv) {
	MyFunctor f(cout);
	printPDU(f);
}
#endif
class ServiceFunctor : public Functor {
private:
	ostream&	out;
	int no = 1;
public:
	ServiceFunctor(ostream& os) : out(os) {}
	virtual void  operator()(const string& s) { out << "line " << no++ << " : " << s << endl; }
};
int main (int argc, char** argv) {
	if (false) {
		RFC_1006 rfc1006;
		NSAPAddr nsap;
		const char* n = rfc1006.parse(nsap, "+03+10.0.0.6:8080");
		const char*p;
		Selector selector;
		p = selector.parse("////NS+a433bb93c1");
		p = selector.parse("#124/NS");
		p = selector.parse("\"abc\"/NS");
		p = selector.parse("'3a'H/NS");

		string sel = "#124";
		TSAPService		service("echo", "#124", "pippo",  "bar");
		TSAPServices	services;
		services.add("echo", "#12", "pippo", "bar");
		const OSIService* os = services.getServiceBySelector(selector);
		if (os != NULL) {
			os->entity();
		}
	}
	{
		AEISAXHandler handler;
		SAXParser parser;

		parser.setFeature(XMLReader::FEATURE_NAMESPACES, true);
		parser.setFeature(XMLReader::FEATURE_NAMESPACE_PREFIXES, true);
		parser.setContentHandler(&handler);
		parser.setProperty(XMLReader::PROPERTY_LEXICAL_HANDLER,	static_cast<LexicalHandler*>(&handler));

		try	{
			parser.parse("AEI.xml");
			ServiceFunctor functor(cout);
			//TSAP_SERVICES.print(functor);
			//SSAP_SERVICES.print(functor);
			//PSAP_SERVICES.print(functor);

			const OSIService* service = TSAP_SERVICES.getServiceByEntity("ssap");
			cout << service->mangled() << endl;

		} catch (Poco::Exception& e)	{
			std::cerr << e.displayText() << std::endl;
		}
	}

#if 0
	<config>
    <prop1>1.23</prop1>
    <prop2>2.34</prop2>
    <prop3>
       <prop4 attr="1"/>
       <prop4 attr="2"/>
    </prop3>
    <prop5 id="first">Hello,</prop5>
    <prop5 id="second"> world!</prop5>
	</config>

	AbstractConfiguration *cfg = new XMLConfiguration("conf.xml");

	double prop1 = cfg->getDouble("prop1");
	double prop2 = cfg->getDouble("prop2");
	cout << "prop1 + prop2 = " << prop1 + prop2 << endl;

	cout << "This is an empty string: " 
       << cfg->getString("prop3.prop4") << endl;

	int prop4   = cfg->getInt("prop3.prop4[@attr]");
	int prop4_0 = cfg->getInt("prop3.prop4[0][@attr]");
	int prop4_1 = cfg->getInt("prop3.prop4[1][@attr]");
	cout << "prop4 + prop4_0 + prop4_1 = " 
       << prop4 + prop4_0 + prop4_1 << endl;

	cout << cfg->getString("prop5[0]") 
		   << cfg->getString("prop5[1]") << endl;
	cout << cfg->getString("prop5[@id=first]") 
		   << cfg->getString("prop5[@id='second'") << endl;

  // No need to delete cfg, since it is reference counted for garbage collection
#endif
	return 0;
}
