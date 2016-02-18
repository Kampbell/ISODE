/*
 * Literal.cpp
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Literal.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string Literal::display() const {
				return name();
			}
			const string Literal::display(const string& prefix) const {
				return display();
			}
		}
	}
}
