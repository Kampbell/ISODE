/*
 * Literal.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef LITERAL_H_
#define LITERAL_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Expression.h"
#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Literal : public Element {
			public:
				Literal(const string& name, int lineno = 0) : Element(name, lineno)  {
				}
				virtual ~Literal() {
				}
				virtual const string display() const;
				virtual const string display(const string& prefix) const;
			};

		}
	}
}
#endif
