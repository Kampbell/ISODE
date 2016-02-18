/*
 * Initiator.h
 *
 *  Created on: 28 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_INITIATOR_H_
#define ALS_NSAP_USER_INITIATOR_H_

#include "als/base/user/Confirmation.h"
using ALS::BASE::USER::Confirmation;

#include "als/nsap/user/DataIndication.h"
#include "als/nsap/user/DisconnectIndication.h"
#include "als/nsap/user/ResetIndication.h"
#include "als/nsap/user/ResetConfirmation.h"

namespace ALS {
	namespace NSAP {
		namespace ADDR {
			class NSAPAddr;
		}
		class QualityOfService;
		class QualityOfServiceParameters;
	}
}
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using ALS::NSAP::ADDR::NSAPAddr;

namespace ALS {
	namespace NSAP {
		namespace USER {
			class  Initiator :
				public virtual DataIndication,
				public virtual DisconnectIndication,
				public virtual ResetIndication,
				public virtual ResetConfirmation,
				public virtual Confirmation {
			public:
				virtual ~Initiator() {}
				virtual ReturnCode NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr) = 0;
			};

		}
	}
}

#endif
