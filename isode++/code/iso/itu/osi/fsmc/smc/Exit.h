/*
 * Exit.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef EXIT_H_
#define EXIT_H_

#include "fsmc/smc/Print.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/Actions.h"

namespace ALS {
namespace SMC {
namespace MODEL {

			class Exit : public Actions, public Element {
			public:
				Exit(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~Exit() {
				}
				virtual const string display() const;
				void print(Print& print) const;
			};

}
}
}

#endif
