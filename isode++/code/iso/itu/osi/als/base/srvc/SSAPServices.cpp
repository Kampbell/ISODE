/*
 * SSAPServices.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */
#include <iostream>
using namespace std;

#include "SSAPService.h"
#include "SSAPServices.h"

namespace ALS {
namespace BASE {
namespace SRVC {
BASE_API SSAPServices	SSAP_SERVICES;

void SSAPServices::add(const string& name, const string& selector, const string& klass, const string& library) {
	OSIServices::add(SSAPService(name, selector, klass,library));
}
void SSAPServices::print(Printer& printer) const {
	servicesBySelectorMap::const_iterator m;
	for(m = servicesBySelector.begin(); m!=servicesBySelector.end(); ++m) {
		printer(m->second->to_string());
	}
}
}
}
}
