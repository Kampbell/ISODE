/*
 * TSAPServices.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_TSAPSERVICES_H_
#define ALS_BASE_SRVC_TSAPSERVICES_H_

#include "als/base/srvc/OSIServices.h"

namespace ALS {
namespace BASE {
namespace SRVC {


class BASE_API TSAPServices : public OSIServices {
private:
	
public:
	TSAPServices() {
	}
	virtual ~TSAPServices() {
	}
	virtual void add(const string& name, const string& selector, const string& klass, const string& library);
	virtual void print(Printer& printer) const;
};

extern BASE_API TSAPServices	TSAP_SERVICES;

}
}
}

#endif
