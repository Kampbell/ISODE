/*
 * ECMA117Decimal.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ECMA117DECIMAL_H_
#define ECMA117DECIMAL_H_

#include "als/NSAP/addr/DSP.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

	class ECMA117Decimal : public DSP {
public:
	ECMA117Decimal() : DSP("ECMA-117-Decimal") {
	}
	virtual ~ECMA117Decimal() {
	}
	virtual const char* parse(NSAPAddr& nsap, const char* address) const { return address; }
};

}
}
}

#endif
