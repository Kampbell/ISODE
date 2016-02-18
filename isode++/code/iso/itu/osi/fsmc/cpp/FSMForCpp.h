/*
 * FSMForCpp.h
 *
 *  Created on: 19 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef  ALS_FSMC_CPP_FSM_H_
#define  ALS_FSMC_CPP_FSM_H_


#include "fsmc/smc/FSM.h"
#include "fsmc/cpp/CompilableForCpp.h"
#include "fsmc/cmp/IndentStream.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class FSMForCpp : public SMC::MODEL::FSM {
				public:
					FSMForCpp(Parser* parser) :
						SMC::MODEL::FSM(parser) {
					}
					virtual ~FSMForCpp() {
					}
					void generate(const Path& out, bool debug) const;
					virtual bool updated(const Path& out);

				private:
					void openNamespaces(IndentStream& os) const;
					void closeNamespaces(IndentStream& os) const;
				};

			}
		}
	}
}
#endif
