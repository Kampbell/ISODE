/*
 * Reject.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef REJECT_H_
#define REJECT_H_

#include "tsap/tpdu/TPDU.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class Reject : protected TPDU {
public:
	Reject();
	virtual ~Reject();
};

}
}
}

#endif
