/*
 * OSIService.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_OSISERVICE_H_
#define ALS_BASE_SRVC_OSISERVICE_H_

#include <string>
#include <fstream>
#include "als/base/base.h"
#include "als/base/addr/Selector.h"

using std::string;
using std::ifstream;
using ALS::BASE::ADDR::Selector;

namespace ALS {
namespace BASE {
namespace SRVC {
/*
 <?xml version='1.0' encoding='UTF-8'?>
 <osi xmlns='urn:cfg.svc.als.osi.itu.iso'
 xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance'
 xsi:schemaLocation='urn:cfg.svc.als.osi.itu.iso cfg.xsd'>
 <asap>
 <jndi>
 <!--
 This jndi element specifies directories where are defined the
 ApplicationEntityInformation (APT and AEQ) from either the ldap element
 for a LDAP server, either from the file element for a local jndi file system directory.

 From the applicationEntity or the applicationProcess entry is fetched the
 corresponding mandatory presentationAddress attribute on the initiator side.

 From the applicationEntity or the applicationProcess entry is fetched the
 corresponding mandatory javaClassName attribute on the responder side.

 When both file and ldap element are present, the ldap element has
 precedence over the file element and the DN is looked for only from this ldap
 element. The file element is mainly used at the installation time for running
 the ASAPEcho demo application but it could be used also meantime until the ldap
 be properly configured.
 -->
 <!--
 <ldap>
 <server  host='localhost' port='389'>
 <root dn='cn=Directory Manager' pwd='pippo' />
 <base dn='' />
 </server>
 </ldap>
 -->
 <!--
 The ASAPEcho application's Distinguished Name is:
 countryName=fr
 organizationName=kampbell
 organizationalUnitName=osi
 organizationalUnitName=demos
 commonName=ASAPEcho

 which corresponds to the jndi file system based directory file
 $INSTALLDIR/cfg/countryName=fr/organizationName=kampbell/organizationalUnitName=osi/organizationalUnitName=demos/commonName=ASAPEcho

 The commonName=ASAPEcho file contains one mandatory attributes as property:
 presentationAddress=#512///localTCP=localhost. Since the ASAPEcho application
 is a specific ASE above the PSAP layer, its javaClassName is given by the psap
 service element of this configuration file. For a User Service Element
 above the ASAP layer, the mandatory attribute javaClassName should be provided
 -->
 <file url='file:///${installer:INSTALLATION_PATH}'>
 <base   dn='cfg/jndi' />
 </file>
 </jndi>
 </asap>
 <psap>
 <service name='ftam' selector='#1'	class='iso.itu.osi.als.asap.provider.ASAPStarter' />
 <service name='echo' selector='#128' class='com.pac.osi.demo.echo.PSAPEchoServer' />
 <service name='sink' selector='#129' class='com.pac.osi.demo.echo.PSAPEchoServer' />
 <service name='echo' selector='#1024' class='com.pac.osi.demo.echo.RoSAPEchoServer' />
 </psap>
 <ssap>
 <service name='rts'  selector='#1' class='iso.itu.osi.als.psap.provider.PSAPStarter' />
 <service name='rts'  selector='#2' class='com.pac.osi.rtsap.RtSAP' />
 <service name='ros'  selector='#3' class='com.pac.osi.rosap.RoSAP' />
 <service name='echo' selector='#128' class='com.pac.osi.demo.echo.SSAPEchoServer' />
 <service name='sink' selector='#129' class='com.pac.osi.demo.echo.SSAPEchoServer' />
 </ssap>
 <tsap>
 <service name='echo' selector='#1'   class='iso.itu.osi.als.ssap.provider.SSAPStarter' />
 <service name='echo' selector='#128' class='com.pac.osi.demo.echo.TSAPEchoServer' />
 <service name='sink' selector='#129' class='com.pac.osi.demo.echo.TSAPEchoServer' />
 <service name='sink' selector='#130' class='com.pac.osi.demo.echo.TSAPPerfServer' />
 </tsap>
 <nsap>
 </nsap>
 <addr>
 <macros>
 <!--
 macros used in presentation address definition as specified in RFC1278
 "A string encoding of Presentation Address"	from S.E Hardcastle-Kille.
 -->
 <macro name='X25(80)' 		value='TELEX+00728722+X.25(80)+'/>
 <macro name='TCP' 			value='TELEX+00728722+RFC-1006+'/>
 <macro name='Int-X25(80)' 	value='TELEX+00728722+X.25(80)+01+'/>
 <macro name='Janet' 		value='X25(80)=02+'/>
 <macro name='realNS' 		value='NS+'/>
 <macro name='Int-X25' 		value='X25(80)=01+'/>
 <macro name='Internet' 		value='TCP=03+'/>
 <macro name='localTCP' 		value='TCP=05+'/>
 <macro name='localHost' 	value='localTCP=127.0.0.1+'/>
 <macro name='IXI' 			value='X25(80)=06+'/>
 <macro name='NSAP' 			value='NS+'/>
 </macros>
 </addr>
 </osi>
 */

enum Layer {
	NONE = 0,
	NSAP = 3,
	TSAP = 4,
	SSAP = 5,
	PSAP = 6,
	ASAP = 7,
	RtSAP = 8,
	RoSAP = 9,
	MSAP = 10
};

class BASE_API OSIService {
private:
	Layer		osi_layer;
	string		osi_entity;
	Selector	osi_selector;
	string		osi_klass;
	string		osi_library;

	mutable string osi_string;
	mutable string osi_mangled;

public:
	OSIService() : osi_layer(NONE) {}
	OSIService(const Layer& layer, const string& entity, const Selector& selector, const string& klass, const string& library);
//	OSIService(const ifstream& reader);
	virtual ~OSIService() {}


	Layer				provider() const	{ return osi_layer; }
	const string&		entity() const		{ return osi_entity; }
	const Selector&		selector() const	{ return osi_selector; }
	const string&		klass() const		{ return osi_klass; }
	const string&		library() const		{ return osi_library; }

	const string&		mangled() const;
	const string&		to_string() const;

};

}
}
}

#endif
