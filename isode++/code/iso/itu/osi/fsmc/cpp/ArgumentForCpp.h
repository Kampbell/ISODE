/*
 * ArgumentForCpp.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ARGUMENTFORCPP_H_
#define ARGUMENTFORCPP_H_

#include "fsmc/smc/Argument.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				class ArgumentForCpp : public CompilableForCpp, public SMC::MODEL::Argument {
				public:
					ArgumentForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Argument(name, lineno) {
					}
					virtual ~ArgumentForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}

#endif
