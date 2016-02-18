/*
 * FactoryForCpp.cpp
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#include "fsmc/cpp/FactoryForCpp.h"
#include "fsmc/cpp/ActionForCpp.h"
#include "fsmc/cpp/FSMForCpp.h"
#include "fsmc/cpp/GuardForCpp.h"
#include "fsmc/cpp/MapForCpp.h"
#include "fsmc/cpp/ParameterForCpp.h"
#include "fsmc/cpp/StateForCpp.h"
#include "fsmc/cpp/EntryForCpp.h"
#include "fsmc/cpp/ExitForCpp.h"
#include "fsmc/cpp/TransitionForCpp.h"
#include "fsmc/cpp/ReferenceForCpp.h"
#include "fsmc/cpp/VariableForCpp.h"
#include "fsmc/cpp/FunctionForCpp.h"
#include "fsmc/cpp/LiteralForCpp.h"
#include "fsmc/cpp/ArgumentForCpp.h"
#include "fsmc/cpp/UnaryOperationForCpp.h"
#include "fsmc/cpp/BinaryOperationForCpp.h"


namespace ALS {
	namespace SMC {
		namespace PARSER {
			namespace CPP {
				ActionPtr		FactoryForCpp::newAction(const string& name, int lineno) const {
					return new ActionForCpp(name, lineno);
				}
				FSMPtr			FactoryForCpp::newFSM(Parser* parser) const {
					return new FSMForCpp(parser);
				}
				GuardPtr		FactoryForCpp::newGuard(const string& name, int lineno) const {
					return new GuardForCpp(name, lineno);
				}
				MapPtr			FactoryForCpp::newMap(const string& name, int lineno) const {
					return new MapForCpp(name, lineno);
				}
				ParameterPtr	FactoryForCpp::newParameter(const string& name, int lineno) const{
					return new ParameterForCpp(name, lineno);
				}
				StatePtr		FactoryForCpp::newState(const string& name, int lineno) const{
					return new StateForCpp(name, lineno);
				}
				EntryPtr		FactoryForCpp::newEntry(const string& name, int lineno) const{
					return new EntryForCpp(name, lineno);
				}
				ExitPtr			FactoryForCpp::newExit(const string& name, int lineno) const {
					return new ExitForCpp(name, lineno);
				}
				TransitionPtr	FactoryForCpp::newTransition(const string& name, int lineno) const{
					return new TransitionForCpp(name, lineno);
				}
				ReferencePtr	FactoryForCpp::newReference(const VariablePtr variable, int lineno) const {
					return new ReferenceForCpp(variable, lineno);
				}
				ReferencePtr	FactoryForCpp::newReference(const FunctionPtr function, int lineno) const {
					return new ReferenceForCpp(function, lineno);
				}
				ReferencePtr	FactoryForCpp::newReference(const LiteralPtr literal, int lineno) const {
					return new ReferenceForCpp(literal, lineno);
				}
				VariablePtr	FactoryForCpp::newVariable(const string& name, int lineno) const{
					return new VariableForCpp(name, lineno);
				}
				FunctionPtr	FactoryForCpp::newFunction(const string& name, int lineno) const{
					return new FunctionForCpp(name, lineno);
				}
				LiteralPtr	FactoryForCpp::newLiteral(const string& name, int lineno) const{
					return new LiteralForCpp(name, lineno);
				}
				ArgumentPtr	FactoryForCpp::newArgument(const string& name, int lineno) const{
					return new ArgumentForCpp(name, lineno);
				}
				UnaryOperationPtr	FactoryForCpp::newUnaryOperation(ALS::SMC::MODEL::Operator op) const{
					return new UnaryOperationForCpp(op);
				}
				BinaryOperationPtr	FactoryForCpp::newBinaryOperation(ALS::SMC::MODEL::Operator op) const{
					return new BinaryOperationForCpp(op);
				}

			}
		}
	}
}