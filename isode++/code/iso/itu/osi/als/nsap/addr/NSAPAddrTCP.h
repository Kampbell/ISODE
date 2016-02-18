/*
 * NSAPAddrTCP.h
 *
 *  Created on: 6 août 2014
 *      Author: FrancisANDRE
 */

#ifndef NSAPADDRTCP_H_
#define NSAPADDRTCP_H_

#include "als/NSAP/addr/NSAPAddr.h"

namespace ALS {
namespace NSAP {
namespace ADDR {

class NSAPAddrTCP : public NSAPAddr {
public:
	enum IP {
		NSAP_IP4, NSAP_IP6
	};

private:
	static const int	NSAP_DOMAINS		= 4;
	static const int	NSAP_HEADER_LENGTH	= 1;									// emulation via RFC1006
	static const int	NSAP_IP_LENGTH		= 6;									// emulation via RFC1006
	static const int	NA_TSET_TCP			= 0x0001;								//   .. TCP
	static const int	NA_TSET_UDP			= 0x0002;								//   .. UDP
	static const int	NA_PORT_OFFSET		= NSAP_HEADER_LENGTH + NSAP_IP_LENGTH;
	static const int	NA_TSET_OFFSET		= NA_PORT_OFFSET + (sizeof(short));
	static const int	NSAP_LENGTH			= NA_TSET_OFFSET + (sizeof(short));

public:
	NSAPAddrTCP() : NSAPAddr(NA_TCP) {
	}
	virtual ~NSAPAddrTCP() {
	}
	const char* parse(const char* address);
};

}
}
}

#endif
