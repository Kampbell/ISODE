/*
 * Identifier.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_PARSER_IDENTIFIERTOKEN_H_
#define ALS_SMC_PARSER_IDENTIFIERTOKEN_H_

#include "fsmc/cmp/Token.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {

			class Identifier : public Token {
			public:
				Identifier() {}
				~Identifier() {}
				Class tokenClass() const;
				bool start(char c, istream& istr);
				void finish(istream& istr);
			};

		}
	}
}

#endif
