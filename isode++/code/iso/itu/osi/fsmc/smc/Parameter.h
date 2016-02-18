/*
 * Parameter.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_PARAMETER_H_
#define ALS_FSMC_SMC_PARAMETER_H_


#include "fsmc/smc/smc.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/Reference.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Parameter : public Element {
			private:
				string _type;

			public:
				Parameter(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~Parameter() {
				}

				string& type()					{ return _type; }
				const string& type() const		{ return _type; }
				virtual const string display() const;
			};

		}
	}
}
#endif
