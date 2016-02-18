/*
 * PSAPService.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SRVC_PSAPSERVICE_H_
#define ALS_BASE_SRVC_PSAPSERVICE_H_

#include "als/base/srvc/OSIService.h"

namespace ALS {
namespace BASE {
namespace SRVC {

class PSAPService : public OSIService {
public:
	PSAPService(const string& entity, const string& selector, const string& clazz, const string& library) :
		OSIService(TSAP, entity, Selector:: parse(selector), clazz,library) {
	}
	virtual ~PSAPService() {
	}
};

}
}
}

#endif
