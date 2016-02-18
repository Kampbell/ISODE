/*
 * Function.cpp
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#include "fsmc/smc/Function.h"
#include "fsmc/smc/Argument.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string Function::display() const {
				if (oneline.empty()) {
					oneline += name();
					oneline += '(';
					string arguments;

					for (int no = 0; no < _arguments.size(); ++no) {
						arguments += _arguments[no]->name();
						if (no + 1 < _arguments.size())
							arguments += ", ";
					}
					oneline += arguments;
					oneline += ')';
				}
				return oneline;
			}

		}
	}
}