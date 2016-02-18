/*
 * EntryForCpp.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ENTRYFORCPP_H_
#define ENTRYFORCPP_H_

#include "fsmc/smc/Entry.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class EntryForCpp : public CompilableForCpp, public SMC::MODEL::Entry {
				public:
					EntryForCpp(const string& name, int lineno = 0) :
						SMC::MODEL::Entry(name, lineno) {
					}
					virtual ~EntryForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;
				};

			}
		}
	}
}

#endif
