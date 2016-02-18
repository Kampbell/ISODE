/*
 * TELEX.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef TELEX_H_
#define TELEX_H_

#include "als/nsap/addr/AFI.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

class PSAPAddr;

class TELEX : public AFI {
public:
	TELEX(const string& name, const string& dec0, const string& hex0, const string& dec1, const string& hex1, const string& ia5, int idi_len, int dec_dsp_len, int hex_dsp_len) :
		AFI(name, dec0, hex0, dec1, hex1, ia5, idi_len, dec_dsp_len, hex_dsp_len) {
	}
	virtual ~TELEX() {
	}
	virtual const char* parse(NSAPAddr& nsap, const char* address) const;
};

}
}
}

#endif
