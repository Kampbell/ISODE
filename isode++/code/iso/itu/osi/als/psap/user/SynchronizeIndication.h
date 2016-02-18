/*
 * SynchronizeIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_SYNCHRONIZE_INDICATION_H_
#define ALS_PSAP_USER_SYNCHRONIZE_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"
namespace ALS {
namespace SSAP {
	class ActivityId;
	class Reference;
	class SSN;
	enum SyncOption;
}
}
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::SSN;
using ALS::SSAP::SyncOption;

namespace ALS {
namespace PSAP {
namespace USER {

class SynchronizeIndication : public virtual Indication {
public:
	/**
	 * P-SYNC-MAJOR.INDICATION.
	 * 
	 * @param ssn the serial number
	 * @param userData the data from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMajorIndication(SSN ssn, const User_data* userData = nullptr) = 0;

	/**
	 * P-SYNC-MINOR.INDICATION.
	 * 
	 * @param type the type of minor synchronization
	 * @param ssn the serial number
	 * @param userData the data from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PSyncMinorIndication(SyncOption type, const SSN& ssn, const User_data* userData = nullptr) = 0;

	/**
	 * P-RESYNCHRONIZE.INDICATION.
	 * 
	 * @param type the options
	 * @param ssn the serial number
	 * @param tokens the new token settings
	 * @param presentationIdentifications the presentation context identification list
	 * @param userData the data from peer
	 * @return the return code
	 */
	virtual ReturnCode PResynchronizeIndication(SyncOption type, const SSN& ssn, byte tokens, const Presentation_context_identifier_list& presentationIdentifications, const User_data* userData = nullptr) = 0;

};

}
}
}

#endif
