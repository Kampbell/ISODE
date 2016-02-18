/*
 * ExpressionForCpp.h
 *
 *  Created on: 24 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef EXPRESSIONFORCPP_H_
#define EXPRESSIONFORCPP_H_

#include "fsmc/smc/Expression.h"

namespace ALS {
namespace SMC {
namespace PARSER {
namespace CPP {

class ExpressionForCpp : public virtual ALS::SMC::MODEL::Expression {
public:
	ExpressionForCpp() {
	}
	virtual ~ExpressionForCpp() {
	}
	virtual const string display(const string& prefix) const = 0;
};

}
}
}
}

#endif
