/*
 * ParameterForCpp.cpp
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#include <iostream>
#include "fsmc/cpp/ParameterForCpp.h"
using namespace std;

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				 void ParameterForCpp::generateInclude(ostream& inc, bool debug) const {
					inc << type() << ' ' << name();
				}
				 void ParameterForCpp::generateCode(ostream& cpp, bool debug) const {
					cpp << type() << ' ' << name();
				}
			}
		}
	}
}