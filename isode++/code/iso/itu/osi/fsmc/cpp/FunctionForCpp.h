/*
 * FunctionForCpp.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef FUNCTIONFORCPP_H_
#define FUNCTIONFORCPP_H_

#include "fsmc/smc/Function.h"
#include "fsmc/cpp/CompilableForCpp.h"
#include "fsmc/cpp/ReferenceForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class FunctionForCpp : public SMC::MODEL::Function {
				public:
					FunctionForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Function(name, lineno) {
					}
					virtual ~FunctionForCpp() {
					}
					const string display(const string& prefix) const;
				};

			}
		}
	}
}

#endif
