/*
 * Argument.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_ARGUMENT_H_
#define ALS_FSMC_SMC_ARGUMENT_H_

#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Argument : public Element {
			public:
				Argument(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~Argument() {
				}
				virtual const string display() const;
			};

		}
	}
}

#endif
