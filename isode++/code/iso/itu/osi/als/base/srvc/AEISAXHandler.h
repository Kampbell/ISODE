/*
 * AEISAXHandler.h
 *
 *  Created on: 4 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_AEISAXHANDLER_H_
#define ALS_BASE_SRVC_AEISAXHANDLER_H_

#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/DeclHandler.h"
#include "Poco/SAX/LexicalHandler.h"
#include "Poco/SAX/Attributes.h"
#include "als/base/base.h"
#include "als/base/srvc/OSIService.h"

using Poco::XML::XMLString;
using Poco::XML::XMLChar;
using Poco::XML::Locator;
using Poco::XML::Attributes;

namespace ALS {
namespace BASE {
namespace SRVC {

class BASE_API AEISAXHandler :
	public Poco::XML::ContentHandler,
	public Poco::XML::DeclHandler,
	public Poco::XML::LexicalHandler {
private:
	enum TAG {
	NONE = -1,
	ADDR = 0,
	MACRO,
	MACROS,
	NSAP,
	TSAP,
	SSAP,
	PSAP,
	AcSAP,
	RtSAP,
	RoSAP,
	MSAP
	};

	enum TAG tag;
	const Locator* locator;
	bool isServiceProvider() const {
		return tag == TSAP || tag == SSAP || tag == PSAP;
	}

public:
	AEISAXHandler() {
	}
	void setDocumentLocator(const Locator* loc);
	void startDocument();
	void endDocument();

	void startElement(const XMLString& namespaceURI, const XMLString& localName, const XMLString& qname, const Attributes& attributes);
	void endElement(const XMLString& uri, const XMLString& localName, const XMLString& qname);
	void characters(const XMLChar ch[], int start, int length);
	void ignorableWhitespace(const XMLChar ch[], int start, int len);
	void processingInstruction(const XMLString& target, const XMLString& data);
	void startPrefixMapping(const XMLString& prefix, const XMLString& uri);
	void endPrefixMapping(const XMLString& prefix);
	void skippedEntity(const XMLString& name);

	void attributeDecl(const XMLString& eName, const XMLString& aName,	const XMLString* valueDefault,	const XMLString* value);
	void elementDecl(const XMLString& name, const XMLString& model);
	void externalEntityDecl(const XMLString& name,	const XMLString* publicId,	const XMLString& systemId);
	void internalEntityDecl(const XMLString& name,	const XMLString& value);

	void startDTD(const XMLString& name,	const XMLString& publicId,	const XMLString& systemId);
	void endDTD();

	void startEntity(const XMLString& name);
	void endEntity(const XMLString& name);

	void startCDATA();
	void endCDATA();
	void comment(const XMLChar ch[], int start, int length);
};

}
}
}

#endif
