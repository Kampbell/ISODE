/*
 * String.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_STRINGTOKEN_H_
#define ALS_SMC_PARSER_STRINGTOKEN_H_

#include "fsmc/cmp/Token.h"


namespace ALS { namespace SMC {
namespace PARSER {

class String : public Token {
public:
	String();
	~String();
	Poco::Token::Class tokenClass() const;
	bool start(char c, std::istream& istr);
	void finish(std::istream& istr);
	std::string asString() const;
};

}
}
}

#endif
