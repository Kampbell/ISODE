/*
 * Parameter.cpp
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#include "Parameter.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			const string Parameter::display() const {
				if (oneline.empty()) {
					oneline += name();
					oneline += ':';
					oneline += _type;
				}
				return oneline;
			}
		}
	}
}