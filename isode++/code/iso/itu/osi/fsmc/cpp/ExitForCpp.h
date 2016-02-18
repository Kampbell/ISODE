/*
 * ExitForCpp.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef EXITFORCPP_H_
#define EXITFORCPP_H_

#include "fsmc/smc/Exit.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class ExitForCpp : public CompilableForCpp, public SMC::MODEL::Exit {
				public:
					ExitForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Exit(name, lineno) {
					}
					virtual ~ExitForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}

#endif
