/*
 * Operation.cpp
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Operation.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			Operation::Operation(Operator op) :_operator(op) {
			}
			Operation:: ~Operation() {
			}
			void Operation::setNoContextuel() {
				if (_operator == Operator::equal || _operator == Operator::notequal) {
					_contextuel = false;
				}
			}
		}
	}
}