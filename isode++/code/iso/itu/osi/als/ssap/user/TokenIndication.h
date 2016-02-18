/*
 * TokenIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_TOKENINDICATION_H_
#define ALS_SSAP_USER_TOKENINDICATION_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

namespace ALS {
namespace SSAP {
namespace USER {


	class TokenIndication : public virtual Indication {
public:
	~TokenIndication() {
	}
	/**
	 * S-TOKEN-GIVE.INDICATION.
	 * @param owned the tokens owned by user
	 * @param tokens the tokens offered/wanted
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode STokenGiveIndication(int tokens, int cc = 0, const void* data = nullptr) = 0;


	/**
	 * S-TOKEN-PLEASE.INDICATION.
	 * @param owned the tokens owned by user
	 * @param tokens the tokens offered/wanted
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode STokenPleaseIndication(int tokens, int cc = 0, const void* data = nullptr) = 0;


	/**
	 * S-CONTROL-GIVE.INDICATION.
	 * @param owned the tokens owned by user
	 * @param tokens the tokens offered/wanted
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SControlGiveIndication(int tokens, int cc = 0, const void* data = nullptr) = 0;
};

}
}
}

#endif
