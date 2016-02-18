/*
 * SyncOptions.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_REPORT_H_
#define ALS_SSAP_REPORT_H_


namespace ALS {
	namespace SSAP {
		enum Report {
			/** No specific reason stated. */
			SP_NOREASON = 0,

			/** User receiving ability jeopardized. */
			SP_JEOPARDY = 1,

			/** reserved. */
			SP_RESERVED1 = 2,

			/** User sequence error. */
			SP_SEQUENCE = 3,

			/** reserved. */
			SP_RESERVED2 = 4,

			/** Local SS-user error. */
			SP_LOCAL = 5,

			/** Unrecoverable procedural error. */
			SP_PROCEDURAL = 6,

			/** Demand data token. */
			SP_DEMAND = 128,

			/** SS-provider protocol error. */
			SP_PROTOCOL = (-1),

			/** maximum report DATA from peer. */
			SP_MAX_REPORT_DATA_SIZE = 512



		};
	}
}

#endif
