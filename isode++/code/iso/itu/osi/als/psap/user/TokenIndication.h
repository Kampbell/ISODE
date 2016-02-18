/*
 * TokenIndication.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_USER_TOKEN_INDICATION_H_
#define ALS_PSAP_USER_TOKEN_INDICATION_H_
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/psap/psap.h"
namespace ALS {
namespace PSAP {
namespace USER {

class TokenIndication : public virtual Indication {
public:
	/**
	 * P-TOKEN-GIVE.INDICATION.
	 * @param owned the tokens owned by user
	 * @param tokens the tokens offered/wanted
	 * @param userData the infos from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTokenGiveIndication(byte tokens, const User_data* userData = nullptr) = 0;

	/**
	 * P-CONTROL-GIVE.INDICATION.
	 * @param owned the tokens owned by user
	 * @param tokens the tokens offered/wanted
	 * @param userData the infos from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PControlGiveIndication(byte tokens, const User_data* userData = nullptr) = 0;
	
	/**
	 * P-TOKEN-PLEASE.INDICATION.
	 * @param tokens the tokens offered/wanted
	 * @param owned the tokens owned by user
	 * @param userData the infos from peer
	 * 
	 * @return the return code
	 */
	virtual ReturnCode PTokenPleaseIndication(byte tokens, const User_data* userData = nullptr) = 0;
};

}
}
}

#endif
