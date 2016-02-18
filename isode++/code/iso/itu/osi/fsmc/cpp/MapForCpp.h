/*
 * MapForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_CPP_MAP_H_
#define ALS_FSMC_CPP_MAP_H_

#include "fsmc/smc/Map.h"
#include "fsmc/cpp/CompilableForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class MapForCpp : public CompilableForCpp, public SMC::MODEL::Map {
				public:
					MapForCpp(const string& name, int lineno = 0) :

						SMC::MODEL::Map(name, lineno) {
					}
					virtual ~MapForCpp() {
					}
					virtual void generateInclude(ostream& inc, bool debug) const;
					virtual void generateCode(ostream& cpp, bool debug) const;

					string defaultStateName() const;
					string startStateName() const;
				};

			}
		}
	}
}
#endif
