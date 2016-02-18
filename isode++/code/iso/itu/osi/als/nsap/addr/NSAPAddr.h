/*
 * NSAPAddr.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_ADDR_NSAPADDR_H_
#define ALS_NSAP_ADDR_NSAPADDR_H_

#include <string>
#include <memory>
#include "als/nsap/nsap.h"
#include "als/base/util/NetworkBuffer.h"

using std::string;
using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
namespace NSAP {
namespace ADDR {
	class AFI;
class NSAP_API NSAPAddr  {
	friend class RFC_1006;
private:
	mutable string		na_string;
public:
	static const int	NA_NSAP = 0;		// native COTS
	static const int	NA_TCP = 1;			// RFC1006/TCP
	static const int	NA_X25 = 2;			// TP0/X.25
protected:
	int     na_stack;						// TS-stack

public:
	static const int	SUBNET_REALNS	= (-1);	// hard-wired
    static const int	SUBNET_INT_X25	= 1;
    static const int	SUBNET_JANET	= 2;
    static const int	SUBNET_INTERNET	= 3;
    static const int	SUBNET_DYNAMIC	= 100;	// dynamic start here...
protected:
	int    na_community;						// internal community #

	struct un_na_nsap {						// real network service
		static const int	NASIZE = 64;	// 20 ought to do it
		static const int	NAS_UNKNOWN = 0;// don't know
		static const int	NAS_CONS = 1;	// is CONS
		static const int	NAS_CLNS = 2;	// is CLNS
		char    na_nsap_address[NASIZE];
 		char    na_nsap_addrlen;
 		char    na_nsap_addr_class;			// CONS/CLNS
    };

	 struct un_na_tcp {						// emulation via RFC1006
		static const int	NSAP_DOMAINLEN = 63;
 		byte	na_tcp_domain[NSAP_DOMAINLEN + 1];
 	    nat2	na_tcp_port;		// non-standard TCP port
		nat2	na_tcp_tset;		// transport set
		int2	na_tcp_family;
		byte	na_tcp_length;	
 	};


	 struct un_na_x25 {			/* X.25 (assume single subnet) */
		 static const int NSAP_DTELEN = 36;
		 static const int NPSIZE = 4;
		 static const int CUDFSIZE = 16;
		 static const int FACSIZE = 6;
		 char    na_x25_dte[NSAP_DTELEN + 1]; /* Numeric DTE + Link */
		 char    na_x25_dtelen;	/* number of digits used */

		 /* Conventionally, the PID sits at the first head bytes of user data and so
		 * should probably not be mentioned specially. A macro might do it, if
		 * necessary.
		 */
		 char    na_x25_pid[NPSIZE];	/* X.25 protocol id */
		 char    na_x25_pidlen;			/*   .. */
		 char    na_x25_cudf[CUDFSIZE];	/* call user data field */
		 char    na_x25_cudflen;		/* .. */
		 /*
		 * X25 Facilities field.
		 */
		 char    na_x25_fac[FACSIZE];	/* X.25 facilities */
		 char    na_x25_faclen;			/*   .. */
	 };
protected:
	union nau {
		un_na_nsap	na_nsap;
		un_na_tcp	na_tcp;
		un_na_x25	na_x25;
	} addr;
public:
	NSAPAddr() : na_stack(0), na_community(0) {
		memset(&addr, 0, sizeof(addr));
	}
	NSAPAddr(int stack) : na_stack(stack), na_community(0) {
		memset(&addr, 0, sizeof(addr));
	}
	~NSAPAddr() {
	}

	const char*		parse(const char* address);
	const int2		tcp_family() const	{ return addr.na_tcp.na_tcp_family; }
	int2&			tcp_family()		{ return addr.na_tcp.na_tcp_family; }
	const nat2		tcp_port() const	{ return addr.na_tcp.na_tcp_port; }
	nat2&			tcp_port()		{ return addr.na_tcp.na_tcp_port; }
	const nat2		tcp_tset() const	{ return addr.na_tcp.na_tcp_tset; }
	nat2&			tcp_tset()		{ return addr.na_tcp.na_tcp_tset; }
	const byte*		tcp_domain() const	{ return addr.na_tcp.na_tcp_domain; }
	byte*			tcp_domain()		{ return addr.na_tcp.na_tcp_domain; }
	byte			tcp_length() const	{ return  addr.na_tcp.na_tcp_length; }
	byte&			tcp_length()		{ return  addr.na_tcp.na_tcp_length; }
	const int		stack() const		{ return na_stack; }
	int&			stack()				{ return na_stack; }
	const int		community() const	{ return na_community; }
	int&			community()			{ return na_community; }
	const string&	to_string() const;
};

}
}
}

#endif
