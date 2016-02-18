/*
 * DataIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_DATA_INDICATION_H_
#define ALS_PSAP_USER_DATA_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {
namespace USER {

class DataIndication : public virtual Indication {
public:
	/**
	 * P-DATA.INDICATION.
	 * 
	 * @param infos the infos
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PDataIndication(const User_data& userData) = 0;

	/**
	 * P-EXPEDITED-DATA.INDICATION.
	 * 
	 * @param userData the infos
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PExpeditedDataIndication(const User_data& userData) = 0;

	/**
	 * P-TYPED-DATA.INDICATION.
	 * 
	 * @param userData the infos
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTypedDataIndication(const User_data& userData) = 0;

	/**
	 * P-CAPABILITY-DATA.INDICATION.
	 * 
	 * @param userData the infos from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PCapabilityDataIndication(const User_data& userData) = 0;
};

}
}
}

#endif
