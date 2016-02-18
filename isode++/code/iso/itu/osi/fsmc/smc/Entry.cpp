/*
 * Entry.cpp
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#include "fsmc/smc/Entry.h"
#include "fsmc/smc/Action.h"

namespace ALS {
namespace SMC {
namespace MODEL {
			const string Entry::display() const {
				if (oneline.empty()) {
					oneline += Element::name();
				}
				return oneline;
			}
			void Entry::print(Print& print) const {
				string line;
				line += "Entry\t{";

				for (const auto& action : actions())
					line += action->display();

				line += '}';
				print(line);
			}
}
}
}
