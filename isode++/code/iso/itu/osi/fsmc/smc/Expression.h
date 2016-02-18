/*
 * Expression.h
 *
 *  Created on: 21 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "fsmc/smc/smc.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Expression {
			protected:
				OperationPtr	_operation = NULL;
				mutable string	_asstring;
				GuardPtr		_guard = NULL;

			public:
				Expression() {
				}
				virtual ~Expression() {
				}
				GuardPtr&		guard()				{ return _guard; }
				const GuardPtr	guard() const 		{ return _guard; }

				virtual const string display() const = 0;
				OperationPtr&		operation()			{ return _operation;  }
				const OperationPtr&	operation() const	{ return _operation;  }
			};

		}
	}
}
#endif
