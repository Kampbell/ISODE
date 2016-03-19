/*
 * SSN.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SSN_H_
#define ALS_SSAP_SSN_H_
#include <string>
using std::string;

#include "als/ssap/ssap.h"

namespace ALS {
namespace SSAP {
/** The Constant SERIAL_NONE. */
static const int	SERIAL_NONE = -1;		// No SSN
/** The Constant SERIAL_MIN with value 000 000. */
static const int	SERIAL_MIN = 000000;	// the min SSN
/** The Constant SERIAL_MAX with value 999 998. */
static const int	SERIAL_MAX = 999998;	// the max SSN

static const int	UPPER_LIMIT_SERIAL_NUMBER = 6;

class SSAP_API SSN {
private:
	static const int	SIZE_CN_ISN = 6;
	nat4	serial;

public:
	SSN() : serial(SERIAL_NONE){
	}
	SSN(int ssn) {
		if (!isValid(ssn)) {
			throw  1;// RuntimeException("invalid SSN: " + ssn);
		}
		serial = ssn;
	}
	SSN(const SSN& ssn) {
		this->serial = ssn.serial;
	}
	~SSN() {
		serial = SERIAL_NONE;
	}
	int			ssn() const { return serial;	}
	const SSN&	ssn(nat4 ssn) {
		if (!isValid(ssn)) {
			throw  1;//  RuntimeException();
		}
		serial = ssn;
		return *this;
	}
	string		to_string() const;
	static int	range() { return SERIAL_MAX - SERIAL_MIN + 1; }

private:
	static bool isValid(int ssn) {
		return ssn == SERIAL_NONE || (SERIAL_MIN <= ssn && ssn <= SERIAL_MAX);
	}

public:
	bool isValid() const {
		return serial == SERIAL_NONE || (SERIAL_MIN <= serial && serial <= SERIAL_MAX);
	}
	SSN  operator +(int n)	{ SSN newSSN(*this); newSSN.serial += n; return newSSN; }
	SSN  operator -(int n)	{ SSN newSSN(*this); newSSN.serial -= n; return newSSN; }
	SSN& operator +=(int n) { serial += n; return *this; }

	bool operator >(nat4 ssn) const			{ return this->serial > ssn; }
	bool operator >=(nat4 ssn) const		{ return this->serial >= ssn; }
	bool operator ==(nat4 ssn) const		{ return this->serial == ssn; }
	bool operator <=(nat4 ssn) const		{ return this->serial <= ssn; }
	bool operator <(nat4 ssn) const			{ return this->serial < ssn; }

	bool operator >(const SSN& ssn) const	{ return this->serial > ssn.serial; }
	bool operator >=(const SSN& ssn) const	{ return this->serial >= ssn.serial; }
	bool operator ==(const SSN& ssn) const	{ return this->serial == ssn.serial; }
	bool operator <=(const SSN& ssn) const	{ return this->serial <= ssn.serial; }
	bool operator <(const SSN& ssn) const	{ return this->serial < ssn.serial; }
		 operator int() const				{ return serial; }
};

}
}

#endif
