/*
 * UnaryOperationForCpp.h
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef UNARYOPERATIONFORCPP_H_
#define UNARYOPERATIONFORCPP_H_

#include "fsmc/smc/UnaryOperation.h"
#include "fsmc/cpp/ExpressionForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class UnaryOperationForCpp : public ExpressionForCpp, public SMC::MODEL::UnaryOperation {
				public:
					UnaryOperationForCpp(ALS::SMC::MODEL::Operator op) :
						SMC::MODEL::UnaryOperation(op) {
					}
					virtual ~UnaryOperationForCpp() {
					}
					const string UnaryOperationForCpp::display(const string& prefix) const;
				};

			}
		}
	}
}

#endif
