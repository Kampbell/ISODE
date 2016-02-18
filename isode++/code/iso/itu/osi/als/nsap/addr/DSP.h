/*
 * DSP.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_ADDR_DSP_H_
#define ALS_NSAP_ADDR_DSP_H_
#include "als/nsap/nsap.h"

#include <string>
using std::string;

namespace ALS {
namespace NSAP {
namespace ADDR {
	class NSAPAddr;

class DSP {
	string name_;

public:
	DSP(const char* name) : name_(name){
	}
	virtual ~DSP() {
	}

	const string& name() const { return name_; }
	virtual const char* parse(NSAPAddr& nsap, const char* address) const = 0;

	const string& to_string() const { return name_; }
};

}
}
}

#endif
