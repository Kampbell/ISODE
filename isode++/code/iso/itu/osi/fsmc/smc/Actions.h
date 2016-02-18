/*
 * Actions.h
 *
 *  Created on: 26 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ACTIONS_H_
#define ACTIONS_H_

#include "fsmc/smc/Element.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class Actions {
			protected:
				List<const ActionPtr>	_actions;
			public:
				Actions() {
				}
				virtual ~Actions() {
				}
				
				List<const ActionPtr>&			actions()			{ return _actions; }
				const List<const ActionPtr>&	actions() const		{ return _actions; }
				
				void add(const ActionPtr action)	{ _actions.push_back(action); }
			};

		}
	}
}

#endif
