/*
 * PSAPServices.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */
#include <iostream>
using namespace std;

#include "PSAPService.h"
#include "PSAPServices.h"



namespace ALS {
namespace BASE {
namespace SRVC {
BASE_API PSAPServices	PSAP_SERVICES;

void PSAPServices::add(const string& name, const string& selector, const string& klass, const string& library) {
	OSIServices::add(PSAPService(name, selector, klass,library));
}
void PSAPServices::print(Printer& printer) const {
	servicesBySelectorMap::const_iterator m;
	for(m = servicesBySelector.begin(); m!=servicesBySelector.end(); ++m) {
		printer(m->second->to_string());
	}
}

}
}
}
