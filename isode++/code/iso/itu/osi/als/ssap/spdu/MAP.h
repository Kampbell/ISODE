/*
 * MAP.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_MAP_H_
#define ALS_SSAP_SPDU_MAP_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/SyncOption.h"
using ALS::SSAP::SyncOption;

namespace ALS {
namespace SSAP {
namespace SPDU {

class MAP : public SPDU {	// MAJOR SYNC POINT SPDU
private:
	static const int	SMASK_MAP_SYNC = 0x0001;
	static const int	MAP_SYNC_NOEND = 0x01;			// ACTIVITY NOT ENDED (i.e., MAP not AE)
	static const int	MAP_SYNC_MASK = MAP_SYNC_NOEND;
	static const int	SMASK_MAP_SERIAL = 0x0002;
	static const int	MAP_SIZE = 512;
	static const int	MAP_BASE_SIZE = 14;

	//
	byte			map_sync = 0;
	nat4			map_serial = 0;

public:
	MAP() : SPDU(CAT2, SPDU_MAP) {
	}
	MAP(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_MAP, tsdu)  {
	}
	virtual ~MAP() {
	}
	nat4 getSerial() const {
		return map_serial;
	}
	const nat4& ssn() const {
		return map_serial;
	}

	void setSerial(nat4 serial) {
		map_serial = serial;
		addMask(SMASK_MAP_SERIAL);
	}

	byte getSync() {
		return map_sync;
	}

	void setSync(SyncOption sync) {
		map_sync = (byte)sync;
		addMask(SMASK_MAP_SYNC);
	}

	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
