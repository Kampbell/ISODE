/*
 * TSAPAddr.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef TSAPADDR_H_
#define TSAPADDR_H_

#include "als/base/addr/Selector.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/addr/AddrTSAP.h"

using ALS::BASE::ADDR::Selector;

namespace ALS {
namespace NSAP {
namespace ADDR {
	class PSAPAddr;

class NSAP_API TSAPAddr {
public:
	static const int NTADDR = 8; 		/*according to NIST OIW */

private:
	friend PSAPAddr;
	mutable string	ta_string;

	NSAPAddr 		ta_addrs[NTADDR];	/*choice of network addresses */
	int		   		ta_naddr;

	static const int TSSIZE = 64;
	int		   	 	ta_selectlen;
	Selector 		ta_selector;	// TSAP selector

public:
	TSAPAddr() : ta_naddr(0), ta_selectlen(0) {
	}
	TSAPAddr(const AddrTSAP& addrTSAP) : ta_naddr(0), ta_selectlen(0) {
		ta_selector = addrTSAP.selector();
		if (addrTSAP.present())
			ta_addrs[++ta_naddr] = addrTSAP.addr();
	}
	~TSAPAddr() {
	}
	Selector&		selector(const Selector& selector) { ta_selector = selector; return ta_selector; }
	const Selector& selector() const { return ta_selector; }
	const NSAPAddr& nsapaddr(int no) const { return ta_addrs[no]; }
	const int		size() const { return ta_naddr; }
	const char*		parse(const char* address);
	const string&	to_string() const;
};

}
}
}

#endif
