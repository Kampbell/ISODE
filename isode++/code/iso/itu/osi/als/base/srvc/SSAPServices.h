/*
 * SSAPServices.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_SSAPSERVICES_H_
#define ALS_BASE_SRVC_SSAPSERVICES_H_

#include "als/base/srvc/OSIServices.h"

namespace ALS {
namespace BASE {
namespace SRVC {

class BASE_API SSAPServices  : public OSIServices  {
public:
	SSAPServices() {
	}
	virtual ~SSAPServices() {
	}
	virtual void add(const string& name, const string& selector, const string& klass, const string& library);
	virtual void print(Printer& printer) const;

};

extern BASE_API SSAPServices	SSAP_SERVICES;

}
}
}

#endif
