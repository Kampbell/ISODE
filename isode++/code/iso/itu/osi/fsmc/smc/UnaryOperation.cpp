/*
 * UnaryOperation.cpp
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#include "UnaryOperation.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string UnaryOperation::display() const {
				if (_asstring.empty()) {
					switch (_operator) {
					case Operator::not: _asstring += '!';
					}
					_asstring += _operand->display();
				}
				return _asstring;
			}
		}
	}
}