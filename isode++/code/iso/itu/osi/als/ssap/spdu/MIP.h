/*
 * MIP.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_MIP_H_
#define ALS_SSAP_SPDU_MIP_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class MIP : public SPDU {
	// MINOR SYNC POINT SPDU
private:
	static const int	SMASK_MIP_SYNC = 0x0001;
	static const int	MIP_SYNC_NOEXPL = 0x01;	// no explicit ack required
	static const int	MIP_SYNC_MASK = MIP_SYNC_NOEXPL;

	static const int	SMASK_MIP_SERIAL = 0x0002;
	static const int	MIP_SIZE = 512;
	static const int	MIP_BASE_SIZE = 14;

	//
	byte	mip_sync;
	nat4	mip_serial;

public:
	MIP() : SPDU(CAT2, SPDU_MIP) {
	}
	MIP(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_MIP, tsdu)  {
	}
	virtual ~MIP() {
	}
	void setSync(byte sync) {
		addMask(SMASK_MIP_SYNC);
		mip_sync = sync;
	}
	byte getSync() const {
		return mip_sync;
	}
	void setSerial(nat4 serial) {
		addMask(SMASK_MIP_SERIAL);
		mip_serial = serial;
	}
	nat4 getSerial() const {
		return mip_serial;
	}


	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
