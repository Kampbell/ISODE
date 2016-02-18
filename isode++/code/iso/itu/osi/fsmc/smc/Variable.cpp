/*
 * Variable.cpp
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Variable.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string Variable::display() const {
				return name();
			}
		}
	}
}