/*
 * Bit.h
 *
 *  Created on: 27 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_UTIL_BITS_H_
#define ALS_BASE_UTIL_BITS_H_
#include "als/base/base.h"

namespace ALS {
namespace BASE {
namespace UTIL {


class Bits {
private:
	int4	bitset;
public:
	Bits() {
		bitset = 0;
	}
	Bits(int4 bits) {
		bitset = bits;
	}
	~Bits() {
	}
	inline bool has(int4 bits) const 	{ return (bitset & bits) != 0; }
	inline void add(int4 bits) 			{ bitset |= bits; }
	inline void set(int4 bits) 			{ bitset |= bits; }
	inline void rem(int4 bits) 			{ bitset &= ~bits; }
	inline void reset() 				{ bitset = 0; }
	inline void reset(int n)			{ bitset &= ~(1 << n); }
	Bits& operator=(Bits&& bits)		{ bitset = bits.bitset; return *this;}
	Bits& operator=(int4 bits)			{ bitset = bits; return *this; }
	Bits& operator&=(int4 bits)			{ bitset &= bits; return *this; }
	bool  operator==(int4 bits) const	{ return bitset == bits; }
		  operator int() const			{ return bitset; }
};

}
}
}

#endif
