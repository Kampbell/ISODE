/*
 * TSAPServices.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */
#include <iostream>
#include <algorithm>
using namespace std;

#include "TSAPService.h"
#include "TSAPServices.h"

namespace ALS {
namespace BASE {
namespace SRVC {

BASE_API TSAPServices	TSAP_SERVICES;

void TSAPServices::add(const string& name, const string& selector, const string& klass, const string& library) {
	OSIServices::add(TSAPService(name, selector, klass, library));
}
void TSAPServices::print(Printer& printer) const {
	servicesBySelectorMap::const_iterator m;
	for(m = servicesBySelector.begin(); m!=servicesBySelector.end(); ++m) {
		printer(m->second->to_string());
	}
}

}
}
}
