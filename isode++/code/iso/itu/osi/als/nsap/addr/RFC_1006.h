/*
 * RFC1006.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef RFC_1006_H_
#define RFC_1006_H_

#include "als/nsap/addr/DSP.h"
#include "als/nsap/addr/NSAPAddrTCP.h"


namespace ALS {
namespace NSAP {
namespace ADDR {
class NSAP_API RFC_1006 : public DSP {
private:
public:
	RFC_1006() : DSP("RFC-1006"){
	}
	virtual ~RFC_1006() {
	}
	virtual const char* parse(NSAPAddr& nsap, const char* address) const;
};

}
}
}

#endif

