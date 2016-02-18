/*
 * RS.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_RS_H_
#define ALS_SSAP_SPDU_RS_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/ResyncOption.h"

namespace ALS {
	namespace SSAP {
		namespace SPDU {

			class RS : public SPDU {
				// RESYNCHRONIZE SPDU
			private:
				static const int SMASK_RS_SET = 0x0001;
				static const int SMASK_RS_TYPE = 0x0002;
				static const int SMASK_RS_SSN = 0x0004;
				static const int SMASK_RS_SECOND_TYPE = 0x0008;
				static const int SMASK_RS_SECOND_SSN = 0x0010;
				static const int RS_SIZE = 512;
				static const int RS_BASE_SIZE = 17;

				//
				byte rs_settings;
				byte rs_resync;
				nat4 rs_serial;
				byte rs_second_resync;
				nat4 rs_second_serial;

			public:
				RS() : SPDU(CAT2, SPDU_RS) {
				}

				RS(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_RS, tsdu)  {
				}
				virtual ~RS() {
				}
				//	static final boolean SYNC_OK(int r) {
				//		return  r <= SSAPSync.SS_SET;
				//	}
				void setSerial(nat4 serial) {
					addMask(SMASK_RS_SSN);
					rs_serial = serial;
				}
				void setSecondSerial(nat4 serial) {
					addMask(SMASK_RS_SECOND_SSN);
					rs_second_serial = serial;
				}
				const nat4& SSN() const			{ return rs_serial; }
				const nat4& secondSSN() const	{ return rs_second_serial; }

				void setFirstType(ResyncOption resync) {
					addMask(SMASK_RS_TYPE);
					switch (resync) {
					case RESTART: rs_resync = 0; break;
					case ABANDON: rs_resync = 1; break;
					case SET: rs_resync = 2; break;
					default: throw InvalidArgumentException();
					}
				}
				void setSettings(byte settings) {
					addMask(SMASK_RS_SET);
					rs_settings = settings;
				}
				ResyncOption getFirstType() const {
					switch (rs_resync) {
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
