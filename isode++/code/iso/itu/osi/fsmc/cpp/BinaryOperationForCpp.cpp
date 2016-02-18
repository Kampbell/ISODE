/*
 * BinaryOperationForCpp.cpp
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#include "BinaryOperationForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				const string BinaryOperationForCpp::display(const string& prefix) const {
					string value;
					value += dynamic_cast<ExpressionForCpp*>(left())->display(prefix);
					switch (_operator) {
					case ALS::SMC::MODEL::Operator::equal: value += "=="; break;
					case ALS::SMC::MODEL::Operator::notequal: value += "!="; break;
					case ALS::SMC::MODEL::Operator::and: value += "&&"; break;
					case ALS::SMC::MODEL::Operator::or: value += "||"; break;
					case ALS::SMC::MODEL::Operator::xor: value += '^'; break;
					default: value += "???"; break;
					}
					value += dynamic_cast<ExpressionForCpp*>(right())->display(prefix);
					return value;
				}

			}
		}
	}
}
