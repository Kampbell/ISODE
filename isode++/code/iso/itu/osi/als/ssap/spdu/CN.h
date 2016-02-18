/*
 * CN.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CN_H_
#define ALS_SSAP_SPDU_CN_H_
#include "als/ssap/spdu/CN_AC.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class CN : public CN_AC {
public:
	static const int	SIZE_CN_ISN		= 6;
	static const int		CN_SIZE		= 512;

	static const int	SMASK_CN_REF	= 0x0001;
	static const int	SMASK_CN_OPT	= 0x0002;
	static const int	SMASK_CN_TSDU	= 0x0004;
	static const int	SMASK_CN_VRSN	= 0x0008;
	static const int	SMASK_CN_ISN	= 0x0010;
	static const int	SMASK_CN_SET	= 0x0020;
	static const int	SMASK_CN_REQ	= 0x0080;
	static const int	SMASK_CN_CALLING= 0x0100;
	static const int	SMASK_CN_CALLED = 0x0200;

	CN() : CN_AC(CAT1, SPDU_CN) {
	}
	CN(NetworkBuffer& tsdu) : CN_AC(CAT1, SPDU_CN, tsdu)  {
	}
	virtual ~CN() {
	}
};

}
}
}

#endif
