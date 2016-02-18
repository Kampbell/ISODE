/*
 * Element.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_ELEMENT_H_
#define ALS_FSMC_SMC_ELEMENT_H_

#include "fsmc/smc/smc.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Element {
			private:
				string	_name;		// An element has a unique name.
				int		_lineno;

			protected:
				mutable string oneline;

			public:
				Element(int lineno = 0) : _lineno(lineno) {
				}
				Element(const string& name, int lineno = 0) : _name(name), _lineno(lineno) {
				}
				virtual ~Element() {
				}

				virtual const string	name() const		{ return _name; }
				const int				lineno() const		{ return _lineno; }

				virtual const string display() const = 0;
			};

		}
	}
}
#endif
