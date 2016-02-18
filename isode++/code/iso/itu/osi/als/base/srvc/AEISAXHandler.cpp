/*
 * AEISAXHandler.cpp
 *
 *  Created on: 4 août 2014
 *      Author: FrancisANDRE
 */
#include <iostream>
#include "als/base/srvc/AEISAXHandler.h"
#include "als/base/srvc/OSIServices.h"
#include "als/base/addr/Macros.h"

using namespace Poco::XML;
using namespace std;

BASE_API ALS::BASE::ADDR::Macros macros;

namespace ALS {
namespace BASE {
namespace SRVC {

void AEISAXHandler::setDocumentLocator(const Locator* loc) {
	locator = loc;
}
void AEISAXHandler::startDocument(){
}
void AEISAXHandler::endDocument(){
}
void AEISAXHandler::startElement(const XMLString& namespaceURI,const XMLString& localName,const XMLString& qname,const Attributes& attributes){
	if (qname == "asap") {
		tag = AcSAP;
	} else 
	if (qname == "psap") {
		tag = PSAP;
	} else 
	if (qname == "ssap") {
		tag = SSAP;
	} else 
	if (qname == "tsap") {
		tag = TSAP;
	} else 
	if (qname == "addr") {
		tag = ADDR;
	} else 
	if (isServiceProvider() && qname == "service") {
		string entity;
		string selector;
		string klass;
		string library;

		for(int no = 0; no < attributes.getLength(); no++) {
			XMLString attribute = attributes.getQName(no);
			if (attribute == "entity") {
				entity = attributes.getValue(no);
			} else
			if (attribute == "selector") {
				selector = attributes.getValue(no);
			} else
			if (attribute == "class") {
				klass = attributes.getValue(no);
			} else
			if (attribute == "library") {
				library = attributes.getValue(no);
			}
		}
		switch(tag) {
			case TSAP: 
				OSIServices::add(Layer::TSAP, entity, selector, klass, library);
				break;
			case SSAP: 
				OSIServices::add(Layer::SSAP, entity, selector, klass, library);
				break;
			case PSAP: 
				OSIServices::add(Layer::PSAP, entity, selector, klass, library);
				break;
			default:
				break;
		}
	} else 
	if (qname == "macros") {
		tag = MACROS;
	} else 
	if (qname == "macro") {
		string name;
		string value;

		for(int no = 0; no < attributes.getLength(); no++) {
			XMLString attribute = attributes.getQName(no);
			if (attribute == "name") {
				name = attributes.getValue(no);
			} else
			if (attribute == "value") {
				value = attributes.getValue(no);
			}
		}
		macros.add(name, value);
	} else {
	}
}
void AEISAXHandler::endElement(const XMLString& uri,const XMLString& localName,const XMLString& qname){
	if (qname == "asap") {
		tag = NONE;
	} else 
	if (qname == "psap") {
		tag = NONE;
	} else 
	if (qname == "ssap") {
		tag = NONE;
	} else 
	if (qname == "tsap") {
		tag = NONE;
	} else 
	if (qname == "addr") {
		tag = NONE;
	}
}
void AEISAXHandler::characters(const XMLChar ch[], int start, int length){
}
void AEISAXHandler::ignorableWhitespace(const XMLChar ch[], int start, int len){
}
void AEISAXHandler::processingInstruction(const XMLString& target, const XMLString& data){
}
void AEISAXHandler::startPrefixMapping(const XMLString& prefix,const XMLString& uri){
}
void AEISAXHandler::endPrefixMapping(const XMLString& prefix){
}
void AEISAXHandler::skippedEntity(const XMLString& name){
}
void AEISAXHandler::attributeDecl(const XMLString& eName, const XMLString& aName,	const XMLString* valueDefault,	const XMLString* value){
}
void AEISAXHandler::elementDecl(const XMLString& name, const XMLString& model){
}
void AEISAXHandler::externalEntityDecl(const XMLString& name,	const XMLString* publicId,	const XMLString& systemId){
}
void AEISAXHandler::internalEntityDecl(const XMLString& name,	const XMLString& value){
}
void AEISAXHandler::startDTD(	const XMLString& name,	const XMLString& publicId,	const XMLString& systemId) {
}
void AEISAXHandler::endDTD() {
}
void AEISAXHandler::startEntity(const XMLString& name) {
}
void AEISAXHandler::endEntity(const XMLString& name) {
}
void AEISAXHandler::startCDATA() {
}
void AEISAXHandler::endCDATA() {
}
void AEISAXHandler::comment(const XMLChar ch[], int start, int length) {
}

}
}
}
