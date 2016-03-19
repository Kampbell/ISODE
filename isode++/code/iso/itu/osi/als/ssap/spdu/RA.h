/*
 * RA.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_RA_H_
#define ALS_SSAP_SPDU_RA_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/ResyncOption.h"

namespace ALS {
	namespace SSAP {
		namespace SPDU {

			class RA : public SPDU {
				// RESYNCHRONIZE SPDU
			private:
				static const int SMASK_RA_SET	= 0x0001;
				static const int SMASK_RA_TYPE	= 0x0002;
				static const int SMASK_RA_SSN	= 0x0004;
				static const int SMASK_RA_SECOND_TYPE = 0x0008;
				static const int SMASK_RA_SECOND_SSN = 0x0010;
				static const int RA_SIZE = 512;
				static const int RA_BASE_SIZE = 17;

				//
				byte ra_settings;
				byte ra_resync;
				nat4 ra_serial;
				byte ra_second_resync;
				nat4 ra_second_serial;

			public:
				RA() : SPDU(CAT2, SPDU_RA) {
				}

				RA(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_RA, tsdu)  {
				}
				virtual ~RA() {
				}
				//	static final boolean SYNC_OK(int r) {
				//		return  r <= SSAPSync.SS_SET;
				//	}
				void serial(nat4 serial) {
					addMask(SMASK_RA_SSN);
					ra_serial = serial;
				}
				void secondSerial(nat4 serial) {
					addMask(SMASK_RA_SECOND_SSN);
					ra_second_serial = serial;
				}
				const nat4& ssn() const			{ return ra_serial; }
				const nat4& secondSSN() const	{ return ra_second_serial; }

				void type(ResyncOption resync) {
					addMask(SMASK_RA_TYPE);
					switch (resync) {
					case RESTART: ra_resync = 0; break;
					case ABANDON: ra_resync = 1; break;
					case SET: ra_resync = 2; break;
					default: throw InvalidArgumentException();
					}
				}
				byte settings() const {
					return ra_settings;
				}
				void settings(byte settings) {
					addMask(SMASK_RA_SET);
					ra_settings = settings;
				}
				ResyncOption type() const {
					switch (ra_resync) {
					case 0: return RESTART;
					case 1: return ABANDON;
					case 2: return SET;
					default: throw InvalidArgumentException();
					}
					return NOSYNC;
				}
				int			encode();
				ReturnCode	decode(NetworkBuffer& tsdu);
			};

		}
	}
}

#endif
