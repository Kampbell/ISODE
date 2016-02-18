/*
 * Number.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_NUMBERTOKEN_H_
#define ALS_SMC_PARSER_NUMBERTOKEN_H_

#include "fsmc/cmp/Token.h"

namespace ALS { namespace SMC {
namespace PARSER {

class Number: public Token {
public:
	Number() {}
	~Number() {}

	Class tokenClass() const ;
	bool start(char c, istream& istr);
	void finish(istream& istr);
};

}
}
}

#endif
