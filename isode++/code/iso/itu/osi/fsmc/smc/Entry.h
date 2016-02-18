/*
 * Entry.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include "fsmc/smc/Print.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/Actions.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Entry : public Actions, public Element {
			public:
				Entry(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~Entry() {
				}
				virtual const string display() const;
				void print(Print& print) const;
			};
		}
	}
}
#endif
