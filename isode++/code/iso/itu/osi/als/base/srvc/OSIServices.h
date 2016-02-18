/*
 * OSIServices.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_OSISERVICES_H_
#define ALS_BASE_SRVC_OSISERVICES_H_

#include <map>
#include <vector>
#include "als/base/base.h"
#include "als/base/addr/Selector.h"
#include "als/base/srvc/OSIService.h"

using std::map;
using std::pair;
using std::vector;


using ALS::BASE::ADDR::Selector;

namespace ALS {
namespace BASE {
namespace SRVC {

class BASE_API OSIServices {
public:
	typedef map<Selector, const OSIService*>	servicesBySelectorMap;
	typedef pair<Selector, const OSIService*>	servicesBySelectorPair;
	typedef map<string, const OSIService*>		servicesByEntityMap;
	typedef pair<string, const OSIService*>		servicesByEntityPair;

protected:
	servicesBySelectorMap	servicesBySelector;
	servicesByEntityMap		servicesByEntity;

public:
	OSIServices();
	virtual ~OSIServices();

	const OSIService* getServiceBySelector(const Selector& selector)  const ;
	const OSIService* getServiceByEntity(const string& entity)  const;

	static  void add(const Layer& layer, const string& name, const string& selector, const string& klass, const string& library);
	virtual void add(const string& name, const string& selector, const string& klass, const string& library) = 0;
	virtual void print(Printer& printer) const = 0;

protected:
	void add(const OSIService& service);
};

}
}
}

#endif
