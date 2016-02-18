/*
 * Exception.h
 *
 *  Created on: 19 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_PROV_EXCEPTION_H_
#define ALS_TSAP_PROV_EXCEPTION_H_

namespace ALS {
namespace TSAP {
namespace PROV {

class Exception {
public:
	Exception() {
	}
	Exception(int code) {
	}
	virtual ~Exception() {
	}
};

}
}
}

#endif
