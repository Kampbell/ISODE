/*
 * Macros.h
 *
 *  Created on: 3 ao�t 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_ADDR_MACROS_H_
#define ALS_BASE_ADDR_MACROS_H_

#include <string>
#include <map>
using std::string;
using std::map;

#include "als/base/base.h"

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

BASE				NS+

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

class BASE_API Macros {
private:
	static map<string, string> macros;

public:
	Macros();
	~Macros() {}

	static void		add(const string& macro, const string& value);
	static string 	expand(const string& macro);
//	static string 	expand(const char* macro) ;
private:
	static string 	get(const string& name);
};

}
}
}

#endif
