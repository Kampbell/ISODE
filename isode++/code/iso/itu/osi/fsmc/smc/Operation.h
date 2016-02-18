/*
 * Operation.h
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include "fsmc/smc/Expression.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			enum class Operator {
				none,
				and,
				or,
				xor,
				not,
				equal,
				notequal
			};
			class Operation : public virtual Expression {
			protected:
				bool _contextuel = true;

			protected:
				Operator		_operator;

			public:
				Operation(Operator op);
				virtual ~Operation();

				const bool&	contextuel() const		{ return _contextuel; }
				const Operator&		op() const		{ return _operator; }

				void setNoContextuel();
			};

		}
	}
}
#endif
