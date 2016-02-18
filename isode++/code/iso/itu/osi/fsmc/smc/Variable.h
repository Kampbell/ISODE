/*
 * Variable.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Expression.h"
#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Variable : public Element {
			public:
				Variable(const string& name, int lineno = 0) : Element(name, lineno)  {
				}
				virtual ~Variable() {
				}
				virtual const string display() const;
			};

		}
	}
}
#endif
