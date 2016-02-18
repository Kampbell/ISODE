/*
 * Macros.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#include <sstream>
#include <stdexcept>
#include "Poco/Token.h"
#include "Poco/Ascii.h"
#include "als/base/addr/Macros.h"
#include "Poco/StringTokenizer.h"

using Poco::StringTokenizer;
using Poco::Token;
using Poco::InvalidToken;
using Poco::EOFToken;
using Poco::WhitespaceToken;
using Poco::Ascii;
/**
###############################################################################
#
# Syntax:
#
#	<macro>  <string>
#
#	Each token is separated by LWSP, though double-quotes may be
#	used to prevent separation
#
###############################################################################


# standard macros, defined in "A string encoding of Presentation Address"

Int-X25(80)			TELEX+00728722+X.25(80)+01+
Janet				TELEX+00728722+X.25(80)+02+
Internet-RFC-1006 	TELEX+00728722+RFC-1006+03+


# ISODE standard macros

X25(80)				TELEX+00728722+X.25(80)+
TCP					TELEX+00728722+RFC-1006+


# Interim Community Names

realNS				NS+
Int-X25				X25(80)=01+
# Janet				X25(80)=02+
Internet			TCP=03+
localTCP			TCP=05+
localHost			localTCP=127.0.0.1+
IXI					X25(80)=06+

NSAP				NS+

# US GOSIP v2 Addresses

us					NS+47000580
nsfnet  			us=ffff00
psinet				us=fffc00

# UK CONS addresses
UKNS				DCC+826+d
JanetNS				UKNS=11000
 */

namespace ALS {
namespace BASE {
namespace ADDR {

map<string, string> Macros::macros;

Macros::Macros() {
#if 0
#endif
	//
	macros["Int-X25(80)"]=			"TELEX+00728722+X.25(80)+01+";
	macros["Janet"]=				"TELEX+00728722+X.25(80)+02+";
	macros["Internet-RFC-1006"]=	"TELEX+00728722+X.25(80)+03+";

	// ISODE standard macros
	macros["X25(80)"]=				"TELEX+00728722+X.25(80)+";
	macros["TCP"]=					"TELEX+00728722+RFC-1006+";

	// Interim Community Names
	macros["realNS"]=				"NS+";
	macros["Int-X25"]=				"X25(80)=01+";
	macros["Janet"]=				"X25(80)=02+";
	macros["Internet"]=				"TCP=03+";
	macros["localTCP"]=				"TCP=05+";
	macros["localhost"]=			"localTCP=127.0.0.1+";
	macros["IXI"]=					"X25(80)=06+";
	macros["NSAP"]=					"NS+";
}
void Macros::add(const string& name, const string& value) {
	macros[name] = value;
}

/**
 * Gets the value.
 *
 * @param name the name
 *
 * @return the value
 */
string Macros::get(const string& name)  {
	string catene;
	try {
		catene = macros.at(name);
	}
	catch (const std::out_of_range&) {
		return name;
	}
	string result;
	StringTokenizer st(catene, "+", StringTokenizer::TOK_TRIM | StringTokenizer::TOK_IGNORE_EMPTY);
	for (int no = 0; no < st.count(); ++no) {
		string token = st[no];
		string value = expand(token);
		if (value.empty()) {
		} else {
			result += value;
			result += '+';
		}
	}
	return result;
}

/**
 * @exclude
 */
string Macros::expand(const string& assign)  {
	int equal = 0;
	string result;
	if ((equal = assign.find('=')) >= 0) {
		string macro = assign.substr(0, equal);
		if (!macro.empty()) {
			string value = get(macro);
			result.append(value);
			result.append(assign.substr(equal + 1));
		} else {
			result = assign;
		}
	} else {
		result.append(assign);
	}
	return result;
}

}
}
}

