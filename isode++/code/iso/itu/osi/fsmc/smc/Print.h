/*
 * Print.h
 *
 *  Created on: 22 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_SMC_MODEL_PRINTER_H_
#define ALS_SMC_MODEL_PRINTER_H_

#include "Poco/Logger.h"
using Poco::Logger;

#include "Dumper.h"

namespace ALS {
namespace SMC {
namespace MODEL {

class Print : public Dumper {
public:
	Print(Logger& logger) : logger(logger) {
	}
	virtual ~Print() {
	}
	virtual void operator()(const char* message);
	virtual void operator()(const string& message);
	virtual void operator()(const TransitionPtr transition, const GuardPtr guard);

private:
	Logger& logger;

};

}
}
}

#endif
