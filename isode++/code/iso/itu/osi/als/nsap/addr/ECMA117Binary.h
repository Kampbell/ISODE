/*
 * ECMA117Binary.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ECMA117BINARY_H_
#define ECMA117BINARY_H_

#include "als/NSAP/addr/DSP.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

	class ECMA117Binary : public DSP {
public:
	ECMA117Binary() : DSP("ECMA-117-Binary"){
	}
	virtual ~ECMA117Binary() {
	}
	virtual const char* parse(NSAPAddr& nsap, const char* address) const { return address; }
};

}
}
}

#endif
