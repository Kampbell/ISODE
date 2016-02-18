/*
 * Map.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_FSMC_SMC_MAP_H_
#define ALS_FSMC_SMC_MAP_H_

#include<map>
using std::map;

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/State.h"
#include "fsmc/smc/Print.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Map : public Element {
			protected:
				FSMPtr _fsm = nullptr;
				StatePtr _defaultState = nullptr;
				map<string, StatePtr> _states;
				map<string, TransitionPtr> _transitions;

			public:
				Map(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~Map() {
				}

				StatePtr&		defaultState()			{ return _defaultState; }
				const StatePtr	defaultState() const	{ return _defaultState; }
				FSMPtr&			fsm()					{ return _fsm; }
				const FSMPtr	fsm() const				{ return _fsm; }

				const map<string, StatePtr>&			states() const		{ return _states; }
				const map<string, TransitionPtr>&		transitions() const	{ return _transitions; }


				void add(TransitionPtr transition);
				void add(StatePtr state);
				StatePtr lookfor(const string& state) const;
				virtual const string display() const;
				void print(Print& print) const;
			};

		}
	}
}
#endif
