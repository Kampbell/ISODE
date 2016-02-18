/*
 * GuardForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_GUARD_H_
#define ALS_FSMC_CPP_GUARD_H_

#include "fsmc/smc/Guard.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class GuardForCpp : public CompilableForCpp, public SMC::MODEL::Guard {
				public:
					GuardForCpp(const string& name, int lineno = 0) :

						SMC::MODEL::Guard(name, lineno) {
					}
					virtual ~GuardForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}

#endif
