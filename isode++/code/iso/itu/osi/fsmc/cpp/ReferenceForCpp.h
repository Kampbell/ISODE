/*
 * ReferenceForCpp.h
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef REFERENCEFOCCPP_H_
#define REFERENCEFOCCPP_H_

#include "fsmc/smc/Reference.h"
#include "fsmc/cpp/ExpressionForCpp.h"
#include "fsmc/cpp/ReferenceForCpp.h"
#include "fsmc/cpp/CompilableForCpp.h"
#include <string>
using std::string;

using ALS::SMC::MODEL::VariablePtr;
using ALS::SMC::MODEL::FunctionPtr;
using ALS::SMC::MODEL::LiteralPtr;
using ALS::SMC::MODEL::OperationPtr;

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class ReferenceForCpp : 
					public ExpressionForCpp, 
					public CompilableForCpp, 
					public ALS::SMC::MODEL::Reference {
				public:
					ReferenceForCpp(const VariablePtr variable, int lineno = 0):
						Reference(variable, lineno) {
					}
					ReferenceForCpp(const FunctionPtr function, int lineno = 0):
						Reference(function, lineno) {
					}
					ReferenceForCpp(const LiteralPtr literal, int lineno = 0):
						Reference(literal, lineno) {
					}
					virtual ~ReferenceForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
					const string display(const string& prefix) const;
				};

			}
		}
	}
}

#endif
