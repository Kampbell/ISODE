/*
 * SyncOptions.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SYNCOPTION_H_
#define ALS_SSAP_SYNCOPTION_H_

#include "als/als.h"

namespace ALS {
namespace SSAP {
enum class SyncOption : byte {
	// for S-MINOR-SYNC.INDICATION
	/** The service's user does not want a confirmation. */
	NOCONFIRM = 0,			//   .. nope = 0

	/** The service's user wants a confirmation. */
	CONFIRM = 1,			// wants confirmation = 1

	//major synchronization point without end of activity
	MAJOR_SYNC_WITOUT_END_OF_ACTIVITY = 1,

	DATA_SEPARATION_REQUIRED_NO_CONFIRIM,
	DATA_SEPARATION_REQUIRED_CONFIRM

};
}
}

#endif
