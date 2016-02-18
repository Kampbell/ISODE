/*
 * ER.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_ER_H_
#define ALS_TSAP_TPDU_ER_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API ER : public TPCI {
public:
	static const byte	VDAT_INVALID		= (byte) 0xc1;	/* invalid TPDU */

	static const int	ER_REJ_NOTSPECIFIED	= 0x00;		/* Reason not specified */
	static const int	ER_REJ_CODE			= 0x01;		/* Invalid parameter code */
	static const int	ER_REJ_TPDU			= 0x02;		/* Invalid TPDU type */
	static const int	ER_REJ_VALUE		= 0x03;		/* Invalid parameter value */

private:	/* FIXED part */
	short			_dstref;
	byte			_reject;

public:
	ER()		: TPCI(TPDU_ER) {}
	ER(byte li)	: TPCI(li, TPDU_ER) {}

	virtual int	fixedSize() const		{ return 3; }
	virtual int	variableSize() const	{ return 0; }
	virtual int	decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);
	short		dstref() const			{ return _dstref; }
	byte		reject() const			{ return _reject; }

private:
	ER(const ER&)  = delete;
	ER& operator = (const ER&)  = delete;
};

}
}
}

#endif
