/*
 * BinaryOperationForCpp.h
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef BINARYOPERATIONFORCPP_H_
#define BINARYOPERATIONFORCPP_H_

#include "fsmc/smc/BinaryOperation.h"
#include "fsmc/cpp/ExpressionForCpp.h"

namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {

				class BinaryOperationForCpp : public ExpressionForCpp, public SMC::MODEL::BinaryOperation {

				public:
					BinaryOperationForCpp(ALS::SMC::MODEL::Operator op) :
						SMC::MODEL::BinaryOperation(op) {
					}
					virtual ~BinaryOperationForCpp() {
					}
					const string BinaryOperationForCpp::display(const string& prefix) const;
				};
			}
		}
	}
}

#endif
