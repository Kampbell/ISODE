/*
 * AddrTSAP.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ADDRTSAP_H_
#define ADDRTSAP_H_

#include "als/nsap/nsap.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/base/addr/Selector.h"

using ALS::BASE::ADDR::Selector;

namespace ALS {
	namespace NSAP {
		namespace ADDR {

class NSAP_API AddrTSAP {

	/* network type codes:	must be outside [0-9A-Fa-f] */
#define	NT_TCP	'T'		/* TCP */
#define	NT_X25	'X'		/* X.25 */
#define	NT_BSD	'Z'		/* 4.4BSD */
#define	NT_SUN	'S'		/* SunLink OSI */
#define NT_TLI	't'		/* TLI */
#define NT_XTI	'x'		/* XTI */
#define NT_X2584 'N'	/* X25(84) NSAP */

private:
	NSAPAddr			ta_addr;
	bool				ta_present;
	int					ta_selectlen;
	Selector			ta_selector;

public:
	AddrTSAP();
	virtual ~AddrTSAP();

	const NSAPAddr&		addr() const		{ return ta_addr; }
	const Selector&		selector()	const	{ return ta_selector; }
	bool				present() const		{ return ta_present; }

	NSAPAddr&			addr()				{ return ta_addr; }
	Selector&			selector()			{ return ta_selector; }
	bool				present()			{ return ta_present; }
};

}
}
}

#endif
