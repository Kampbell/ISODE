/*
 * VariableForCpp.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef VARIABLEFORCPP_H_
#define VARIABLEFORCPP_H_

#include "fsmc/smc/Variable.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class VariableForCpp : public SMC::MODEL::Variable {
				public:
					VariableForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Variable(name, lineno) {
					}
					virtual ~VariableForCpp() {
					}
					const string display(const string& prefix) const;
				};

			}
		}
	}
}

#endif
