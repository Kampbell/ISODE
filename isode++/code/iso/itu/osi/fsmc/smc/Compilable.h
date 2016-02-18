/*
 * Compilable.h
 *
 *  Created on: 22 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_MODEL_COMPILABLE_H_
#define ALS_SMC_MODEL_COMPILABLE_H_

#include "Poco/Path.h"
using Poco::Path;


#include "fsmc/smc/smc.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Compilable {

			public:
				virtual void generate(const Path& out, bool debug) const = 0;
			};

		}
	}
}

#endif
