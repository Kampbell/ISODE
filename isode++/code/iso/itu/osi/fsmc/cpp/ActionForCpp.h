/*
 * ActionForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_ACTION_H_
#define ALS_FSMC_CPP_ACTION_H_

#include "fsmc/smc/Action.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class ActionForCpp : public CompilableForCpp, public SMC::MODEL::Action {
				public:
					ActionForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Action(name, lineno) {
					}
					virtual ~ActionForCpp() {
					}
					virtual const string name() const;
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}
#endif
