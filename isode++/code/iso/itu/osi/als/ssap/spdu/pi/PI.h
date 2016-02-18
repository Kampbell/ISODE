/*
 * PI.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PI_H_
#define ALS_SSAP_SPDU_PI_H_
#include <cassert>
#include <list>
using std::list;
#include <string>
using std::string;
using std::to_string;

#include "Poco/Exception.h"
using Poco::RuntimeException;

#include "als/base/util/NetworkBuffer.h"
using ALS::BASE::UTIL::NetworkBuffer;

#include "als/ssap/spdu/HEADER.h"                                                                                                                                                       

#include "als/base/root/NotYetImplementedException.h"
using ALS::BASE::ROOT::NotYetImplementedException;


namespace ALS {
namespace SSAP {
namespace SPDU {

class PI : public HEADER {
public:
	static const int	PGI_CN_ID			= 1;
	static const int		PI_CALLED_SS		= 9;
	static const int		PI_CALLING_SS		= 10;
	static const int		PI_COMMON_REF		= 11;
	static const int		PI_ADD_INFO			= 12;
	static const int	PGI_CN_ITEMS		= 5;
	static const int		PI_PROTOCOL_OPT		= 19;
	static const int		PI_TSDU_MAXSIZ		= 21;
	static const int		PI_VERSION			= 22;
	static const int		PI_ISN				= 23;
	static const int		PI_TOKEN_SET		= 26;
	static const int		PI_TOISN			= 55;
	static const int		PI_ULSN				= 56;	// upper limit serial number
	static const int		PI_LISN				= 57;	// large initial number
	static const int		PI_L2ISN			= 58;	// large second initial number
	static const int		PI_DTO				= 60;	// data overflow
	static const int	PI_SYNC				= 15;
	static const int	PI_TOKEN			= 16;
	static const int	PI_TDISC			= 17;
	static const int	PI_USER_REQ			= 20;
	static const int	PI_PREPARE			= 24;
	static const int	PI_ENCLOSE			= 25;
	static const int	PI_RESYNC			= 27;
	static const int	PGI_AR_LINK			= 33;
	static const int		PI_AR_CALLED		= 9;
	static const int		PI_AR_CALLING		= 10;
	static const int		PI_AR_COMMON		= 11;
	static const int		PI_AR_ADDT			= 12;
	static const int		PI_AR_OLD			= 41;
	static const int		PI_AR_SERIAL		= 42;
	static const int	PI_ACT_ID			= 41;
	static const int	PI_SERIAL			= 42;
	static const int	PI_MIA_DATA			= 46;
	static const int	PI_REFLECT			= 49;
	static const int	PI_REASON			= 50;
	static const int	PI_SSAP_CALLING		= 51;
	static const int	PI_SSAP_CALLED		= 52;
	static const int	PI_UDATA			= 193;
	static const int	PI_XDATA			= 194;

	static const int	SIZE_CN_ISN = 6;

protected:
//	SSAPLogger logger;

	mutable string display;

protected:
	PI(byte id) : HEADER(id) {}
	PI(byte id, NetworkBuffer& tsdu) : HEADER(id, tsdu) {}
	virtual ~PI() {}

	byte pi();
protected:
	void pli(int cc) {
		hli(cc);
	}
public:
	int pli() { return hli(); }
private:
	virtual NetworkBuffer* toTSDU() = 0;
	void toBytes(NetworkBuffer& buffer);

protected:
	NetworkBuffer* toTSDU(int cc);
	NetworkBuffer& toTSDU(NetworkBuffer& tsdu);

	string toString();


	string getLiteral();
	static string toString(int i);
};
}
}
}

#endif
