/*
 * Object.h
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_ROOT_OBJECT_H_
#define ALS_BASE_ROOT_OBJECT_H_

#include <string>
#include "als/base/base.h"

using std::string;

namespace ALS {
namespace BASE {
namespace ROOT {

class BASE_API Object {
public:
	Object() {
	}
	virtual ~Object() {
	}

	virtual string toString() const;
};

}
}
}

#endif
