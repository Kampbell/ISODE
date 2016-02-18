/*
 * ReferenceForCpp.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#include "ReferenceForCpp.h"
#include "VariableForCpp.h"
#include "FunctionForCpp.h"

using namespace ALS::SMC::MODEL;

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				void ReferenceForCpp::generateInclude(ostream& inc, bool debug) const {
				}
				void ReferenceForCpp::generateCode(ostream& cpp, bool debug) const {
				}
				const string ReferenceForCpp::display(const string& prefix) const {
					VariableForCpp* vfc;
					FunctionForCpp* ffc;
					vfc = dynamic_cast<VariableForCpp*>(reference());
					ffc = dynamic_cast<FunctionForCpp*>(reference());
					if (isParameter() || (operation() && !operation()->contextuel())) {
						if (operation())
							operation()->setNoContextuel();
						if (vfc)
							return vfc->Variable::display();
						else if (ffc)
							return ffc->Function::display();
						else
							poco_assert(false);
					}
					else {
						if (vfc)
							return vfc->display(prefix);
						else if (ffc)
							return ffc->display(prefix);
						else
							poco_assert(false);
					}
				}
			}
		}
	}
}
