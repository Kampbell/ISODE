/*
 * DT.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_DT_H_
#define ALS_TSAP_TPDU_DT_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API DT : public TPCI {
public:
	 static const int	DT_EOT		= 0x80;
	 static const int	DT_MAGIC	= (2 + 1); // ti + li + 1

	/* FIXED part */
private:
	byte			dt_nr = 0;

public:
	DT()		: TPCI(TPDU_DT) { }
	DT(byte li) : TPCI(li, TPDU_DT) {
		if (li != 2) {
//FIXME			throw  TPDUException(DR_LENGTH);
		}
	}
	DT(const DT&)  = delete;
	DT& operator = (const DT&)  = delete;

	virtual int fixedSize() const		{ return 1; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

	bool isEOT() const					{ return (dt_nr & DT_EOT) != 0; }
	void resetEOT()						{ dt_nr &= ~DT_EOT; }
	void setEOT()						{ dt_nr |= DT_EOT;	}


};

}
}
}

#endif
