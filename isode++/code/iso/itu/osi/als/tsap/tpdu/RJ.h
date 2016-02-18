/*
 * RJ.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_RJ_H_
#define ALS_TSAP_TPDU_RJ_H_

#include "als/tsap/tpdu/TPCI.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

class RJ : public TPCI {
public:
	RJ()		: TPCI(TPDU_RJ) {}
	RJ(byte li) : TPCI(li, TPDU_RJ) {}

	virtual int fixedSize() const		{ return 0; }
	virtual int variableSize() const	{ return 0; }
	virtual int decode(NetworkBuffer* nsdu);
	virtual int	encode(unique_ptr<NetworkBuffer>& nsdu);

private:
	RJ(const RJ& ak) = delete;
	RJ& operator = (const RJ&)  = delete;
};

}
}
}

#endif
