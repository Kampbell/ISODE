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
	ED()		: TPCI(TPDU_ED) {}
	ED(byte li) : TPCI(li, TPDU_ED) {}

	virtual int fixedSize() const		{ return 0; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

private:
	ED(const ED& ak) = delete;
	ED& operator = (const ED&)  = delete;
};

}
}
}

#endif
