/*
 * X2580.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef X2580_H_
#define X2580_H_

#include "als/NSAP/addr/DSP.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

	class X2580 : public DSP {
public:
	X2580() : DSP("X25(80)") {
	}
	virtual ~X2580() {
	}
	virtual const char* parse(NSAPAddr& nsap, const char* address) const { return address; }
	};

}
}
}

#endif
