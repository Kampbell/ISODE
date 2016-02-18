/*
 * EA.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_EA_H_
#define ALS_TSAP_TPDU_EA_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class EA : public TPCI {
public:
	EA()		: TPCI(TPDU_EA) {}
	EA(byte li) : TPCI(li, TPDU_EA) {}

	virtual int fixedSize() const		{ return 0; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

private:
	EA(const EA& ak)  = delete;
	EA& operator = (const EA&)  = delete;
};

}
}
}

#endif
