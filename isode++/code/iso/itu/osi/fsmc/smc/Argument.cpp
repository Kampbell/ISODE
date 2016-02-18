/*
 * Argument.cpp
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Argument.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string Argument::display() const {
				if (oneline.empty()) {
					oneline += name();
				}
				return oneline;
			}

		}
	}
}
