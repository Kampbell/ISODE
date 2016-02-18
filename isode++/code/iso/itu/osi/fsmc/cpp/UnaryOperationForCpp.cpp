/*
 * UnaryOperationForCpp.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#include "UnaryOperationForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				const string UnaryOperationForCpp::display(const string& prefix) const {
					string value;
					switch (_operator) {
					case ALS::SMC::MODEL::Operator::not: value += "!"; break;
					default: value += "???"; break;
					}
					value += dynamic_cast<ExpressionForCpp*>(operand())->display(prefix);
					return value;
				}
			}
		}
	}
}
