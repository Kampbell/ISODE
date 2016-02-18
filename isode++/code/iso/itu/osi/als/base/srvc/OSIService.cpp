/*
 * OSIService.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <sstream>
#include "Poco/Token.h"
#include "Poco/StreamTokenizer.h"
#include "Poco/Ascii.h"

#include "als/base/srvc/OSIService.h"

using std::ifstream;
using std::istringstream;
using Poco::StreamTokenizer;
using Poco::Token;
using Poco::InvalidToken;
using Poco::EOFToken;
using Poco::WhitespaceToken;
using Poco::Ascii;

namespace ALS {
namespace BASE {
namespace SRVC {

OSIService::OSIService(const Layer& layer, const string& entity, const Selector& selector, const string& klass, const string& library) :
	osi_layer(layer),
	osi_entity(entity),
	osi_selector(selector),
	osi_klass(klass),
	osi_library(library) {
}

const string& OSIService::mangled() const {
#if 0
	if (osi_mangled.empty()) {
		istringstream isstr(osi_klass);
		StreamTokenizer tokenizer(isstr);
		tokenizer.addToken(new WhitespaceToken());
		tokenizer.addToken(new IdentifierToken());
		tokenizer.addToken(new NamespaceQualifierToken());

		string spacename[32];
		int no = 0;
		const Token* next;

#ifdef POCO_OS_FAMILY_WINDOWS
// as for example
// class='ALS::PSAP::PROV::Provider' entry='newInstance()'
// "?newInstance@Provider@PROV@SSAP@ALS@@SAPAV1234@XZ";
//
		for(;;) {
			next = tokenizer.next();
			if (next->is(Token::IDENTIFIER_TOKEN)) {
				spacename[no++] = next->asString();
			} else
			if (next->is(Token::SEPARATOR_TOKEN)) {
			} else
			if (next->is(Token::EOF_TOKEN)) {
				break;
			} else
			if (next->is(Token::INVALID_TOKEN)) {
				break; //FIXME
			}
		}
		int count = no;
		osi_mangled += "?";
//		osi_mangled += osi_entry.substr(0, osi_entry.length() - 2); //FIXME check the ()
		while(--no >= 0) {
			osi_mangled += "@";
			osi_mangled += spacename[no];
		}
		osi_mangled += "@";
		osi_mangled += "@";
		osi_mangled += "SAPAV";
		for(int no = 1; no <= count; no++) {
			osi_mangled += std::to_string(no);
		}
		osi_mangled += "@XZ";
#endif
	}
#endif
	return osi_mangled;

}
const string& OSIService::to_string() const {
	if (osi_string.empty()) {
		osi_string.append("provider:");
		osi_string.append("TSAP");
		osi_string.append("  ");
		osi_string.append("entity:");
		osi_string.append(osi_entity);
		osi_string.append("  ");
		osi_string.append("selector:");
		osi_string.append(osi_selector.to_string());
		osi_string.append("  ");
		osi_string.append("class:");
		osi_string.append(osi_klass);
		osi_string.append("  ");
		osi_string.append("library:");
		osi_string.append(osi_library);
	}
	return osi_string;
}

}
}
}
