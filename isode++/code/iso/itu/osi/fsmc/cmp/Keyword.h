/*
 * Keyword.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_PERCENTTOKEN_H_
#define ALS_SMC_PARSER_PERCENTTOKEN_H_

#include <map>
using std::map;
#include "fsmc/cmp/Token.h"

namespace ALS { namespace SMC {
namespace PARSER {

class Keyword: public Token {
public:
	enum  KW {
		START = 1,	// %start
		CLASS,		// %class
		FSMFILE,	// %fsmfile
		FSMCLASS,	// %fsmclass
		HEADER,		// %header
		INCLUDE,	// %include
		PACKAGE,	// %package
		IMPORT,		// %import
		DECLARE,	// %declare
		ACCESS,		// %access
		MAP,		// %map
	};
	Keyword();
	~Keyword();

	Class tokenClass() const ;
	bool start(char c, istream& istr);
	void finish(istream& istr);
	int asInteger() const;
	static const char* asString(int kwno);

private:
	typedef map<std::string, int> OpMap;
	
	OpMap _opMap;
};

}
}
}

#endif
