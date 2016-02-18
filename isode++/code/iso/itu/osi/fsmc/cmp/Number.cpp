/*
 * Number.cpp
 *
 *  Created on: 3 ao�t 2014
 *      Author: FrancisANDRE
 */

#include "Poco/Token.h"
#include "Poco/Ascii.h"
using Poco::InvalidToken;
using Poco::EOFToken;
using Poco::WhitespaceToken;
using Poco::Ascii;
#include "fsmc/cmp/Number.h"

namespace ALS { namespace SMC {
namespace PARSER {
Token::Class Number::tokenClass() const {
	return Token::INTEGER_LITERAL_TOKEN;
}
bool Number::start(char c, std::istream& istr) {
	if (c != -1 && Ascii::isDigit(c)) {
		_value = c;
		return true;
	} else
		return false;
}
void Number::finish(std::istream& istr) {
	int c = istr.peek();
	while (c != -1 && Ascii::isDigit(c)) {
		istr.get();
		_value += c;
		c = istr.peek();
	}
}

}
}
}
