/*
 * LiteralForCpp.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef LITERALFORCPP_H_
#define LITERALFORCPP_H_

#include "fsmc/smc/Literal.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class LiteralForCpp : public SMC::MODEL::Literal {
				public:
					LiteralForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Literal(name, lineno) {
					}
					virtual ~LiteralForCpp() {
					}
				};

			}
		}
	}
}

#endif
