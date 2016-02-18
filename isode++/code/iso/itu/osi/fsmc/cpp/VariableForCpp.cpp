/*
 * VariableForCpp.cpp
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#include "VariableForCpp.h"

using namespace ALS::SMC::MODEL;

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				const string VariableForCpp::display(const string& prefix) const {
					return prefix + name();
				}
			}
		}
	}
}
