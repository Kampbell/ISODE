/*
 * StateForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_STATE_H_
#define ALS_FSMC_CPP_STATE_H_

#include "fsmc/smc/State.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class StateForCpp : public CompilableForCpp, public SMC::MODEL::State {
				public:
					StateForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::State(name, lineno) {
					}
					virtual ~StateForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;

					void generateForwarDeclaration(ostream& inc, bool debug) const;
					void generateVirtualTransitions(ostream& inc, bool debug) const;
					void generateDefinition(ostream& inc, bool debug) const;
					void generateDeclaration(ostream& cpp, int no) const;
					
				private:
					string statename() const;

				};

			}
		}
	}
}
#endif
