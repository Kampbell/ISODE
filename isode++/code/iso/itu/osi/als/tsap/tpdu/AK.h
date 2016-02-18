/*
 * AK.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_AK_H_
#define ALS_TSAP_TPDU_AK_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class AK : public TPCI {
public:
	static const byte	VDAT_SUBSEQ		= (byte) 0x8c;	/* Sub-sequence number */
	static const byte	VDAT_FLOWCTL	= (byte) 0x8b;	/* Flow control confirmation */

public:
	AK()		: TPCI(TPDU_AK) { }
	AK(byte li) : TPCI(li, TPDU_AK) { }

	virtual int fixedSize() const		{ return 0; }
	virtual int variableSize() const	{ return 0; }

	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

private:
	AK(const AK& ak)  = delete;
	AK& operator = (const AK&)  = delete;
};

}
}
}

#endif
