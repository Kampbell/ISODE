/*
 * OSIServices.cpp
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#include "als/base/addr/Selector.h"
#include "als/base/srvc/OSIServices.h"
#include "als/base/srvc/TSAPServices.h"
#include "als/base/srvc/SSAPServices.h"
#include "als/base/srvc/PSAPServices.h"

namespace ALS {
namespace BASE {
namespace SRVC {

OSIServices::OSIServices() {
}
OSIServices::~OSIServices() {
	servicesBySelectorMap::iterator m;
	for(m = servicesBySelector.begin(); m!=servicesBySelector.end(); ++m) {
		delete m->second;
	}

}

void OSIServices::add(const OSIService& service) {
	const OSIService* s = new OSIService(service);
	servicesBySelector[service.selector()] = s;
	servicesByEntity[service.entity()] = s;
}

const OSIService* OSIServices::getServiceBySelector(const Selector& selector)  const {
	try {
		return servicesBySelector.at(selector);
	} catch (std::out_of_range& ) {
	}
	return nullptr;
}

const OSIService* OSIServices::getServiceByEntity(const string& entity)  const{
	try {
		return servicesByEntity.at(entity);
	} catch (std::out_of_range& ) {
	}
	return nullptr;
}


void OSIServices::add(const Layer& layer, const string& name, const string& selector, const string& klass, const string& library) {
	switch(layer) {
	case TSAP: 
		TSAP_SERVICES.add(name, selector, klass, library);
		break;
	case SSAP: 
		SSAP_SERVICES.add(name, selector, klass, library);
		break;
	case PSAP:
		PSAP_SERVICES.add(name, selector, klass, library);
		break;
	}
}
}
}
}
