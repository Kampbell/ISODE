/*
 * AbortIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_ABORT_INDICATION_H_
#define ALS_SSAP_USER_ABORT_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
namespace SSAP {
namespace USER {

class AbortIndication : public virtual Indication {
public:
// in WinUser.h #define SC_SIZE         0xF000
#ifdef SC_SIZE
#undef SC_SIZE
#endif
	// initial DATA from peer
	/** maximum initial DATA from peer. */
	static const int	SC_SIZE = 512;

	/** Drain for 30 seconds on ABORTs. */
	static const int	AB_TIM = 30;

	/** Drain for 30 seconds on REFUSEs. */
	static const int	RF_TIM = 30;

public:
	/**
	 * S-U-ABORT.INDICATION.
	 *
	 * @param reason the reason of the abort
	 * @param datas the data from the peer
	 * @return the return code
	 */
	virtual ReturnCode SUAbortIndication(int reason, int cc = 0, const void* data = nullptr) = 0;

	/**
	 * S-P-ABORT.INDICATION.
	 *
	 * @param reason the reason of the abort
	 * @param extension TODO
	 * @param message the data for messages from provider
	 * @return the return code
	 */
	virtual ReturnCode SPAbortIndication(int reason, int extension, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
