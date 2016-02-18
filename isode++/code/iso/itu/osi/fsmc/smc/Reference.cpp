/*
 * Reference.cpp
 *
 *  Created on: 1 f�vr. 2016
 *      Author: FrancisANDRE
 */

#include "Reference.h"
#include "Guard.h"
#include "Transition.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			bool Reference::isParameter() const {
				GuardPtr g = guard();
				TransitionPtr transition = guard()->transition();
				if (transition->hasParameter(reference()->Element::name()))
					return true;
				else
					return false;
			}
			const string Reference::display() const {
					return reference()->display();
			}
		}
	}
}
