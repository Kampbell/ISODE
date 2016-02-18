/*
 * Dumper.h
 *
 *  Created on: 8 févr. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_MODEL_DUMPER_H_
#define ALS_SMC_MODEL_DUMPER_H_

#include <string>
using std::string;

#include "fsmc/smc/SMC.h"
using ALS::SMC::MODEL::TransitionPtr;
using ALS::SMC::MODEL::GuardPtr;

namespace ALS {
namespace SMC {
namespace MODEL {

class Dumper {
public:
	virtual void operator()(const char* message) = 0;
	virtual void operator()(const string& message) = 0;
	virtual void operator()(const TransitionPtr transition, const GuardPtr guard) = 0;
};

}
}
}

#endif
