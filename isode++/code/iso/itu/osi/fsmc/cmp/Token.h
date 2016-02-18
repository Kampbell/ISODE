/*
 * Token.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_TOKEN_H_
#define ALS_SMC_PARSER_TOKEN_H_

#include <string>
#include <iostream>
using std::istream;

#include "Poco/Token.h"


namespace ALS {
	namespace SMC {
		namespace PARSER {
			class Token : public Poco::Token {
			public:
				Token();
				~Token();

			protected:
				void syntaxError(const std::string& expected, const std::string& actual);
			};

		}
	}
}
#endif
