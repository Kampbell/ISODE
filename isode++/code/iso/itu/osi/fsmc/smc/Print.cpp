/*
 * Print.cpp
 *
 *  Created on: 22 janv. 2016
 *      Author: FrancisANDRE
 */

#include <algorithm>
using std::max;

#include "fsmc/smc/Parameter.h"
#include "fsmc/smc/Guard.h"
#include "fsmc/smc/Transition.h"
#include "fsmc/smc/Print.h"

namespace ALS {
namespace SMC {
namespace MODEL {
	void Print::operator()(const char* message) {
		logger.information(message);
	}
	void Print::operator()(const string& message) {
		logger.information(message);
	}
	void Print::operator()(const TransitionPtr transition, const GuardPtr guard) {
		string line = transition->name();

		string parameters;
		if (!transition->parameters().empty())
			parameters += '(';
		for (auto parameter : transition->parameters()) {
			parameters += parameter->display();
		}
		if (!transition->parameters().empty())
			parameters += ')';

		line += parameters;
		line.resize(max(line.size(), (size_t)34), ' ');

		string guards = guard->display();
		logger.information("\t%s%s", line, guards);

	}

}
}
}
