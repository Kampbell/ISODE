/*
 * ED.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_ED_H_
#define ALS_TSAP_TPDU_ED_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class ED : public TPCI {
public:
	static const int	ED_EOT		= 0x80;
	static const int	ED_MAGIC	= (2 + 1); // ti + li + 1
	static const int	TX_SIZE = 16;

	ED()		: TPCI(TPDU_ED) {}
	ED(byte li) : TPCI(li, TPDU_ED) {}
	ED(const ED& ak) = delete;
	ED& operator = (const ED&)  = delete;

	virtual int fixedSize() const		{ return 1; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

	bool isEOT() const					{ return (ed_nr & ED_EOT) != 0; }
	void resetEOT()						{ ed_nr &= ~ED_EOT; }
	void setEOT()						{ ed_nr |= ED_EOT;	}

private:
	/* FIXED part */
	byte			ed_nr = 0;
};

}
}
}

#endif
