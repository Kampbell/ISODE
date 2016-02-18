/*
 * AS.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AS_H_
#define ALS_SSAP_SPDU_AS_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/ActivityId.h"
using ALS::SSAP::ActivityId;

namespace ALS {
namespace SSAP {
namespace SPDU {

class AS : public SPDU {	// ACTIVITY START SPDU
private:
	static const int	SMASK_AS_ID = 0x0001;
	static const int	AS_SIZE = 512;
	static const int	AS_BASE_SIZE = 11;

	//
	ActivityId	as_id;

public:
	AS() : SPDU(CAT2, SPDU_AS) {
	}

	AS(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AS, tsdu)  {
	}
	virtual ~AS() {
	}
	void setId(const ActivityId& id) {
		addMask(SMASK_AS_ID);
		as_id = id;
	}

	const ActivityId& getId() const {
		return as_id;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
