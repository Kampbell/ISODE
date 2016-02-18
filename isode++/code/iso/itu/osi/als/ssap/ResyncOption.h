/*
 * SyncOptions.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_RESYNCOPTION_H_
#define ALS_SSAP_RESYNCOPTION_H_
#include <string>
using std::string;

namespace ALS {
	namespace SSAP {
		enum ResyncOption {
			// No resynchronization in progress
			NOSYNC = 0,
			no = NOSYNC,

			// for S-RESYNCHRONIZE.INDICATION
			/** The service user requires a RESTART  on S-RESYNCHRONIZE.INDICATION. */
			RESTART = 1, 	// synchronization restart = 1
			r = RESTART,	// as named in the SSAP State machine.

			/** The service user requires a SET on S-RESYNCHRONIZE.INDICATION. */
			SET = 2, 		// synchronization set = 2, prevails over restart
			s = SET,		// as named in the SSAP State machine

			/** The service user requires an ABANDON on S-RESYNCHRONIZE.INDICATION. */
			ABANDON = 3, 	// synchronization abandon = 3, prevails over set
			a = ABANDON,	// as named in the SSAP State machine

			INTERRUPT = 4, 	// interrupt activity, prevails over abandon
			inte = INTERRUPT,

			DISCARD = 5, 	// discard activity, prevails overs interrupt
			dsc = DISCARD
			//
			// thus value must comply with numeric increasing order as
			// no < r < s < a < inte < dsc
			//

		};
		static const char* resync_to_string(const ResyncOption& resync) {
			switch (resync) {
			case NOSYNC:	return "NOSYNC";
			case RESTART:	return "RESTART";
			case SET:		return "SET";
			case ABANDON:	return "ABANDON";
			case INTERRUPT: return "INTERRUPT";
			case DISCARD:	return "DISCARD";
			}
			return"???";
		}
	}
}

#endif
