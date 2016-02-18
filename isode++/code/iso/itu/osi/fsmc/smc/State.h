/*
 * State.h
 *
 *  Created on: 16 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_MODEL_STATE_H_
#define ALS_SMC_MODEL_STATE_H_

#include <map>
using std::map;

#include "fsmc/smc/smc.h"
#include "fsmc/smc/Print.h"
#include "fsmc/smc/Element.h"
#include "fsmc/smc/State.h"
#include "fsmc/smc/Transition.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {
			class State : public Element {
			private:
				map<string, TransitionPtr>	maps;

			protected:
				MapPtr				_map = nullptr;
				string				_className;
				string				_instanceName;
				EntryPtr			_entry = nullptr;
				ExitPtr				_exit = nullptr;
				List<TransitionPtr>	_transitions;

			public:
				State(const string& name, int lineno = 0) : Element(name, lineno) {
				}
				virtual ~State() {
				}
				MapPtr&			map()								{ return _map; }
				EntryPtr&		entry()								{ return _entry; }
				ExitPtr&		exit()								{ return _exit; }
				const MapPtr&	map()	const 						{ return _map; }
				const EntryPtr& entry()	const 						{ return _entry; }
				const ExitPtr&	exit()	const 						{ return _exit; }
				const List<TransitionPtr>&	transitions() const		{ return _transitions; }

				TransitionPtr add(TransitionPtr transition);
				TransitionPtr get(const string& transition, const List<ParameterPtr>& parameters) const;

				virtual const string display() const;
				void print(Print& print) const;
			};

		}
	}
}
#endif
