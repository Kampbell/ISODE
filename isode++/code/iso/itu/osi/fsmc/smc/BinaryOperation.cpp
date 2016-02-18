/*
 * BinaryOperation.cpp
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#include "BinaryOperation.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string BinaryOperation::display() const {
				if (_asstring.empty()) {
					_asstring += _left->display();
					switch (_operator) {
					case Operator::equal: _asstring += "=="; break;
					case Operator::notequal: _asstring += "!="; break;
					case Operator::and: _asstring += "&&"; break;
					case Operator::or: _asstring += "||"; break;
					case Operator::xor: _asstring += '^'; break;
					default: _asstring += "???"; break;
					}
					_asstring += _right->display();
				}
				return _asstring;
			}
		}
	}
}