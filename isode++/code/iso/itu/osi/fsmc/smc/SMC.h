/*
 * fsmc.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_SMC_H_
#define ALS_FSMC_SMC_SMC_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#define List vector

namespace ALS {
	namespace SMC {
		namespace PARSER {
			class Parser;
		}
	}
}
using ALS::SMC::PARSER::Parser;

namespace ALS {
	namespace SMC {
		namespace MODEL {
			class Action;
			class Element;
			class FSM;
			class Guard;
			class Map;
			class Parameter;
			class State;
			class Entry;
			class Exit;
			class Transition;
			class Expression;
			class Variable;
			class Reference;
			class Function;
			class Literal;
			class Argument;
			class Operation;
			class UnaryOperation;
			class BinaryOperation;

			typedef Action* ActionPtr;
			typedef Element* ElementPtr;
			typedef FSM* FSMPtr;
			typedef Guard* GuardPtr;
			typedef Map* MapPtr;
			typedef Parameter* ParameterPtr;
			typedef State* StatePtr;
			typedef Entry* EntryPtr;
			typedef Exit* ExitPtr;
			typedef Transition* TransitionPtr;
			typedef Expression* ExpressionPtr;
			typedef Variable* VariablePtr;
			typedef Reference* ReferencePtr;
			typedef Function* FunctionPtr;
			typedef Literal* LiteralPtr;
			typedef Argument* ArgumentPtr;
			typedef Operation* OperationPtr;
			typedef UnaryOperation* UnaryOperationPtr;
			typedef BinaryOperation* BinaryOperationPtr;
		}
	}
}
#endif
