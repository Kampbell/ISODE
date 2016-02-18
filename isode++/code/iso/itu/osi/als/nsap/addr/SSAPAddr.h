/*
 * SSAPAddr.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef SSAPADDR_H_
#define SSAPADDR_H_

#include "als/base/addr/Selector.h"
#include "als/nsap/addr/TSAPAddr.h"

namespace ALS {
namespace NSAP {
namespace ADDR {
	class PSAPAddr;

	/*
	struct SSAPaddr {
    struct TSAPaddr sa_addr;		// transport address

#define	SSSIZE	64
	int	    sa_selectlen;

	union {				// SSAP selector 
		char    sa_un_selector[SSSIZE];
		u_short sa_un_port;
	}               un_sa;
#define	sa_selector	un_sa.sa_un_selector
#define	sa_port		un_sa.sa_un_port
};
#define	NULLSA			((struct SSAPaddr *) 0)
*/
class NSAP_API SSAPAddr {
	friend PSAPAddr;
private:
	mutable string	sa_string;

public:
	TSAPAddr 		sa_addr; 	// transport address
	int 			sa_selectlen;
	Selector 		sa_selector; // SSAP selector 
public:
	SSAPAddr() {
	}
	SSAPAddr(const TSAPAddr & tsapAddr) {
	}
	~SSAPAddr() {
	}
	const char* parse(const char* address);
	const Selector& selector() const { return sa_selector; }
	const TSAPAddr& tsapaddr() const { return sa_addr; }
	const string& to_string() const;

	bool valid() const { return true; }
};

}
}
}

#endif
