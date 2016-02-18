/*
 * UnaryOperation.h
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef UNARYOPERATION_H_
#define UNARYOPERATION_H_

#include "fsmc/smc/Operation.h"
#include "fsmc/smc/Expression.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class UnaryOperation : public Operation {
			private:
				ExpressionPtr		_operand;

			public:
				UnaryOperation(Operator op) : Operation(op) {
				}
				virtual ~UnaryOperation() {
				}

				ExpressionPtr& operand()				{ return _operand; }
				const ExpressionPtr  operand() const	{ return _operand; }
				virtual const string display() const;
			};

		}
	}
}
#endif
