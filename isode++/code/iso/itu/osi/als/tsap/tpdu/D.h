/*
 * D.h
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_D_H_
#define ALS_TSAP_TPDU_D_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API D : public TPCI {
public:
	static const int TD_SIZE	= 64;	// maximum user data allowed

protected:
	static const byte 	VDAT_ADDITIONAL	= (byte) 0xe0;		/* Additional information */
	
private:
	short d_dstref;
	short d_srcref;
	byte  d_reason;

public:
	D(byte code)			: TPCI(code) {}
	D(byte li, byte code) 	: TPCI(li, code) {}

	virtual int fixedSize() const		{ return 5; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

	virtual void	setData(NetworkBuffer* buffer);
	virtual void	setData(const string&  message);
	virtual void	setData(int cc, const byte* data);

	short&	dstref() 				{ return d_dstref; }
	short&	srcref() 				{ return d_srcref; }
	byte&	reason() 				{ return d_reason; }
	short	dstref() const			{ return d_dstref; }
	short	srcref() const			{ return d_srcref; }
	byte	reason() const			{ return d_reason; }

protected:
	D()  = delete;
private:
	D(const D& ak)  = delete;
	D& operator = (const D&)  = delete;

};

}
}
}

#endif
