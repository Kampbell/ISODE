/*
 * Function.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Expression.h"
#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Function : public Element {
			private:
				List<ArgumentPtr> _arguments;

			public:
				Function(const string& name, int lineno = 0) : Element(name, lineno)  {
				}
				virtual ~Function() {
				}
				List<ArgumentPtr>& arguments()					{ return _arguments; }
				const List<ArgumentPtr>& arguments() const		{ return _arguments; }

				void add(const ArgumentPtr argument)		{ _arguments.push_back(argument); }
				virtual const string display() const;
			};

		}
	}
}
#endif
