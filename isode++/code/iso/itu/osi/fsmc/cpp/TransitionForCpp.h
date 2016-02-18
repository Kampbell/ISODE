/*
 * TransitionForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_TRANSITION_H_
#define ALS_FSMC_CPP_TRANSITION_H_

#include "fsmc/smc/Transition.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class TransitionForCpp : public CompilableForCpp, public SMC::MODEL::Transition {
				public:
					TransitionForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Transition(name, lineno) {
					}
					virtual ~TransitionForCpp() {
					}
					virtual const string name() const;
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
					void generateVirtualTransitions(ostream& inc, bool debug) const;
					void generateDefinition(ostream& inc, bool debug) const;
				};

			}
		}
	}
}
#endif
