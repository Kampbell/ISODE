/*
 * Factory.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_MODEL_FACTORY_H_
#define ALS_SMC_MODEL_FACTORY_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Operation.h"

using ALS::SMC::MODEL::ActionPtr;
using ALS::SMC::MODEL::FSMPtr;
using ALS::SMC::MODEL::GuardPtr;
using ALS::SMC::MODEL::MapPtr;
using ALS::SMC::MODEL::ParameterPtr;
using ALS::SMC::MODEL::StatePtr;
using ALS::SMC::MODEL::EntryPtr;
using ALS::SMC::MODEL::ExitPtr;
using ALS::SMC::MODEL::TransitionPtr;
using ALS::SMC::MODEL::ExpressionPtr;
using ALS::SMC::MODEL::ReferencePtr;
using ALS::SMC::MODEL::VariablePtr;
using ALS::SMC::MODEL::FunctionPtr;
using ALS::SMC::MODEL::LiteralPtr;
using ALS::SMC::MODEL::ArgumentPtr;
using ALS::SMC::MODEL::OperationPtr;
using ALS::SMC::MODEL::UnaryOperationPtr;
using ALS::SMC::MODEL::BinaryOperationPtr;

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Factory {
			public:
				Factory() {
				}
				virtual ~Factory() {
				}
				virtual FSMPtr				newFSM(Parser* parser) const = 0;
				virtual ActionPtr			newAction(const string& name, int lineno = 0) const = 0;
				virtual GuardPtr			newGuard(const string& name, int lineno = 0) const = 0;
				virtual MapPtr				newMap(const string& name, int lineno = 0) const = 0;
				virtual ParameterPtr		newParameter(const string& name, int lineno = 0) const = 0;
				virtual StatePtr			newState(const string& name, int lineno = 0) const = 0;
				virtual EntryPtr			newEntry(const string& name, int lineno = 0) const = 0;
				virtual ExitPtr				newExit(const string& name, int lineno = 0) const = 0;
				virtual TransitionPtr		newTransition(const string& name, int lineno = 0) const = 0;
				virtual VariablePtr			newVariable(const string& name, int lineno = 0) const = 0;
				virtual FunctionPtr			newFunction(const string& name, int lineno = 0) const = 0;
				virtual LiteralPtr			newLiteral(const string& name, int lineno = 0) const = 0;
				virtual	ReferencePtr		newReference(const VariablePtr variable, int lineno = 0) const = 0;
				virtual	ReferencePtr		newReference(const LiteralPtr literal, int lineno = 0) const = 0;
				virtual	ReferencePtr		newReference(const FunctionPtr function, int lineno = 0) const = 0;
				virtual ArgumentPtr			newArgument(const string& name, int lineno = 0) const = 0;
				virtual UnaryOperationPtr	newUnaryOperation(Operator op) const = 0;
				virtual BinaryOperationPtr	newBinaryOperation(Operator op) const = 0;
			};
		}
	}
}

#endif
