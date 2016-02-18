#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
/*
 * Responder.h
 *
 *  Created on: 28 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_RESPONDER_H_
#define ALS_NSAP_USER_RESPONDER_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;

#include "als/nsap/user/DataIndication.h"
#include "als/nsap/user/DisconnectIndication.h"
#include "als/nsap/user/ResetIndication.h"
#include "als/nsap/user/ResetConfirmation.h"
#include "als/nsap/user/Linker.h"

namespace ALS {
	namespace BASE {
		namespace SRVC {
			class TSAPServices;
		}
	}
}
namespace ALS {
namespace NSAP {
namespace USER {

class Responder : public Linker, 
	public virtual DataIndication,
	public virtual DisconnectIndication,
	public virtual ResetIndication,
	public virtual ResetConfirmation,
	public virtual Indication {
public:
	virtual ~Responder() {}
	virtual ReturnCode NConnectIndication(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr) = 0;
	virtual ReturnCode NSetTSAPServices(const ALS::BASE::SRVC::TSAPServices* tsapServices) = 0;
};

}
}
}

#endif
