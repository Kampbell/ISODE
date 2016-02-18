/*
 * Transition.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_TRANSITION_H_
#define ALS_FSMC_SMC_TRANSITION_H_

#include "fsmc/smc/smc.h"
#include "fsmc/smc/State.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/Guard.h"
#include "fsmc/smc/Parameter.h"
#include "fsmc/smc/Print.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Transition : public Element {
			protected:
				StatePtr			_begstate = nullptr;
				List<ParameterPtr>	_parameters;
				List<GuardPtr>		_guards;
				mutable string		_signature;

			public:
				Transition() = delete;
				Transition(const Transition&) = delete;
				Transition(const string& name, int lineno = 0);
				virtual ~Transition();

				StatePtr& begstate()				{ return _begstate; }
				List<ParameterPtr>& parameters()	{ return _parameters; }
				List<GuardPtr>& guards()			{ return _guards; }
				const StatePtr& begstate()	const	{ return _begstate; }
				const List<ParameterPtr>& parameters() const { return _parameters; }
				const List<GuardPtr>& guards() const{ return _guards; }

				virtual const string display() const;
				void print(Print& print) const;

				void add(ParameterPtr parameter)	{ _parameters.push_back(parameter); }
				void add(GuardPtr guard)			{ _guards.push_back(guard); guard->transition() = this; }


				string declaration(const Parameter* added = nullptr) const;
				string call(const char* embed) const;

				const string& signature() const;
				static string signature(const string& name, const List<ParameterPtr>& parameters);

				bool hasParameter(const string& name) const;
			};

		}
	}
}
#endif
