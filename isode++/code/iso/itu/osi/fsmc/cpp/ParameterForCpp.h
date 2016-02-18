/*
 * ParameterForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_PARAMETER_H_
#define ALS_FSMC_CPP_PARAMETER_H_

#include "fsmc/smc/Parameter.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class ParameterForCpp : public CompilableForCpp, public SMC::MODEL::Parameter {
				public:
					ParameterForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Parameter(name, lineno) {
					}
					virtual ~ParameterForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}
#endif
