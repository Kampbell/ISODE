/*
 * AA.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AA_H_
#define ALS_SSAP_SPDU_AA_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AA : public SPDU {
	// ABORT ACCEPT SPDU
private:
	static const int	AA_SIZE			= 0;
	static const int 	AA_BASE_SIZE	= 0;

public:
	AA() : SPDU (CAT1, SPDU_AA) {
		addMask(SMASK_SPDU_AA);
	}
	AA(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_AA, tsdu)  {
		addMask(SMASK_SPDU_AA);
	}
	virtual ~AA() {
	}
	/*
	case SPDU_AA:
	#ifdef	notdef
		case SPDU_AIA:		/* aka SPDU_AA
	#endif
		If_Set (SMASK_SPDU_AA) {
			start_spdu (&c, AA_BASE_SIZE);
		break;
		}
		start_spdu (&c, AIA_BASE_SIZE);
	break;
	*/
	int			encode()	{ return 0; }
	ReturnCode	decode(NetworkBuffer& tsdu) { return SPDU::control(tsdu); }
};

}
}
}

#endif
