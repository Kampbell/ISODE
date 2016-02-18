/*
 * Reference.h
 *
 *  Created on: 1 févr. 2016
 *      Author: FrancisANDRE
 */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Expression.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/Variable.h"
#include "fsmc/smc/Literal.h"
#include "fsmc/smc/Function.h"
#include "fsmc/smc/Operation.h"

namespace ALS {
namespace SMC {
namespace MODEL {

class Reference  : public virtual Expression, public Element {
private:

	union {
		VariablePtr	_variable;
		LiteralPtr  _literal;
		FunctionPtr  _function;
	};

public:
	Reference(const VariablePtr variable, int lineno = 0) : 
		Element(lineno), 
		_variable(variable)  {
	}
	Reference(const FunctionPtr function, int lineno = 0) :
		Element(lineno),
		_function(function)  {
	}
	Reference(const LiteralPtr literal, int lineno = 0) :
		Element(lineno),
		_literal(literal)  {
	}
	virtual ~Reference() {
	}
	virtual const string display() const;
	ElementPtr			reference()			{ return _variable;  }
	const ElementPtr	reference() const	{ return _variable;  }
	bool isParameter() const;
};

}
}
}

#endif
