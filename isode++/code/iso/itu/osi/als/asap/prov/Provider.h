/*
 * Provider.h
 *
 *  Created on: 18 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_PROV_PROVIDER_H_
#define ALS_ASAP_PROV_PROVIDER_H_
#include "als/asap/asap.h"
#include "als/psap/user/Initiator.h"
#include "als/psap/user/Responder.h"
#include "als/psap/serv/Initiator.h"
#include "als/psap/serv/Responder.h"
#include "als/psap/prov/Provider.h"
#include "als/psap/user/Linker.h"
#include "als/asap/user/Initiator.h"
#include "als/asap/user/Responder.h"
#include "als/asap/serv/Initiator.h"
#include "als/asap/serv/Responder.h"
#include "als/asap/prov/FSM.h"

namespace ALS {
namespace ASAP {
namespace PROV {
class Logger;

class ASAP_API Provider :
	public ALS::PSAP::USER::Linker,
	public ALS::ASAP::SERV::Initiator,
	public ALS::ASAP::SERV::Responder,
	public ALS::PSAP::USER::Initiator,
	public ALS::PSAP::USER::Responder,
	public ALS::SSAP::Token {
	friend class STATE;
    friend class STATE_STA0;
    friend class STATE_STA1;
    friend class STATE_STA2;
    friend class STATE_STA3;
    friend class STATE_STA4;
    friend class STATE_STA5;
    friend class STATE_STA6;
    friend class STATE_STA7;
    friend class STATE_Default;
    friend class ProviderState;
    friend class FSM;
private:
	ALS::ASAP::USER::Initiator*	asap_user_initiator;
	ALS::ASAP::USER::Responder*	asap_user_responder;
	ALS::PSAP::SERV::Initiator*		psap_serv_initiator;
	ALS::PSAP::SERV::Responder*		psap_serv_responder;
	ALS::PSAP::PROV::Provider*		psap_prov_provider;
	Logger* acb_logger;

	static Provider* newInstance() { return new Provider(); }
	FSM								acb_fsm;
	int								acb_sversion;
	int								acb_acse_as_id;

	Application_context_name 					applicationContext;
	Application_context_name_list 				applicationContexts;
	AP_title									callingAPtitle;
	AE_qualifier								callingAEqualifier;
	AP_invocation_identifier					callingAPInvocationIdentifier;
	AE_invocation_identifier					callingAEInvocationIdentifier;
	AP_title									calledAPtitle;
	AE_qualifier								calledAEqualifier;
	AP_invocation_identifier					calledAPInvocationIdentifier;
	AE_invocation_identifier					calledAEInvocationIdentifier;
	ACSE_requirements 							senderACSERequirements;
	Mechanism_name								mechanism;
	Authentication_value						authentification;
	Implementation_data 						implementation;
	Association_information* 					userInformation;
	PresentationAddress 						callingPresentationAddress;
	PresentationAddress 						calledPresentationAddress;
	Presentation_context_definition_list		presentationContexts;
	Presentation_context_definition_result_list	presentationContextResults;
	Default_context_name 						defaultContext;
	int 										defaultContextResult;
	Presentation_requirements 					presentationRequirements;
	User_session_requirements					sessionRequirements;
	SSN											isn;
	int											settings;
	Reference									reference;
	QualityOfService							qualityOfService;

	AP_title									respondingAPtitle;
	AE_qualifier								respondingAEqualifier;
	AP_invocation_identifier					respondingAPInvocationIdentifier;
	AE_invocation_identifier					respondingAEInvocationIdentifier;
	PresentationAddress							respondingPresentationAddress;

public:
	Provider() : acb_fsm(*this) {
	}
	virtual ~Provider() {
	}
	ReturnCode AAssociateRequest(
		const Mode_selector&								mode,
		const Application_context_name& 					applicationContext,
		const Application_context_name_list& 				applicationContexts,
		const AP_title&										callingAPtitle,
		const AE_qualifier&									callingAEqualifier,
		const AP_invocation_identifier&						callingAPInvocationIdentifier,
		const AE_invocation_identifier&						callingAEInvocationIdentifier,
		const AP_title&										calledAPtitle,
		const AE_qualifier&									calledAEqualifier,
		const AP_invocation_identifier&						calledAPInvocationIdentifier,
		const AE_invocation_identifier&						calledAEInvocationIdentifier,
		const ACSE_requirements& 							senderACSERequirements,
		const Mechanism_name& 								mechanism,
		const Authentication_value& 						authentification,
		const Implementation_data& 							implementation,
		const PresentationAddress&							callingPresentationAddress,
		const PresentationAddress& 							calledPresentationAddress,
		const Presentation_context_definition_list&			presentationContexts,
		const Default_context_name& 						defaultContext,
		const Presentation_requirements& 					presentationRequirements,
		const User_session_requirements& 					sessionRequirements,
		const SSN& 											isn,
		byte 												settings,
		const Reference& 									reference,
		const QualityOfService&				 				qualityOfService,
		const Association_information* 						userInformation = nullptr);
	
	ReturnCode AAssociateResponse(
		const Associate_result&								result,
		const Associate_source_diagnostic&					diagnostic,
		const Application_context_name&						applicationContext,
		const Application_context_name_list&				applicationContexts,
		const AP_title&										respondingAPtitle,
		const AE_qualifier&									respondingAEqualifier,
		const AP_invocation_identifier&						respondingAPInvocationIdentifier,
		const AE_invocation_identifier&						respondingAEInvocationIdentifier,
		const ACSE_requirements&							senderACSERequirements,
		const Mechanism_name&								mechanism,
		const Authentication_value&							authentification,
		const PresentationAddress&							respondingPresentationAddress,
		const Presentation_context_definition_result_list&	presentationContextResults,
		int													defaultContextResult,
		const QualityOfService&								qualityOfService,
		const Presentation_requirements&					presentationRequirements,
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference,
		const Association_information*						userInformation = nullptr);
	
	ReturnCode AReleaseRequest(
		const Release_request_reason&						requestReason,
		const Association_information*						userInformation = nullptr);
	
	ReturnCode AReleaseResponse(
		bool												result,
		const Release_response_reason&						responseReason,
		const Association_information*						userInformation = nullptr);
	
	ReturnCode AAbortRequest(
		const ABRT_diagnostic&								diagnostic,
		const Association_information*						userInformation = nullptr);
	
	ReturnCode PConnectIndication(
		const PresentationAddress&							callingPresentationAddress,
		const PresentationAddress&							calledPresentationAddress,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		const Default_context_name&							defaultContext,
		const Presentation_requirements&					presentationRequirements,
		const Mode_selector&								mode,
		const User_session_requirements&					sessionRequirements,
		const SSN&											isn,
		int													settings,
		const Reference&									reference, 
		const QualityOfService&								qualityOfService,
		const User_data*									userData = nullptr);
	ReturnCode PConnectConfirmation(
		const PresentationAddress&							respondingPresentationAddress,
		const Presentation_context_definition_list&			presentationContexts,
		const Presentation_context_definition_result_list&	presentationContextResults,
		int													defaultContextResult,
		const Presentation_requirements&					presentationRequirements, 
		const User_session_requirements&					sessionRequirements,
		int													settings, 
		const SSN&											isn,
		const Reference&									reference, 
		int													ssdusize,
		const QualityOfService&								qualityOfService, 
		int													result,
		const User_data*									userData = nullptr);

	ReturnCode PReleaseIndication(const User_data* userData = nullptr);
	ReturnCode PReleaseConfirmation(bool affirmative, const User_data* userData = nullptr);
	
	ReturnCode PUAbortIndication(int reason, int extension, const User_data* userData = nullptr);
	ReturnCode PPAbortIndication(int reason, int extension, const User_data* userData = nullptr);

private:
	// Outgoing events
	// ------------------------------------------------------------------
	// Abbreviated name 		Target Name and description
	void A_ASCind();				// AC-user A-ASSOCIATE indication primitive
	void A_ASCcnf(bool accepted);	//+AC-user A-ASSOCIATE confirm primitive (Result = accepted)
									//-AC-user A-ASSOCIATE confirm primitive (Result = rejected (permanent) or rejected (transient))
	void AARQ();					// AC-peer A-ASSOCIATE-REQUEST APDU The AARQ is sent as user data on a P-CONNECT request primitive
	void AARE(bool accepted);		//+AC-peer A-ASSOCIATE-RESPONSE APDU (Result = accepted) The AARE+ is sent as user data on a P-CONNECT+ response primitive (Result = acceptance)
									//-AC-peer A-ASSOCIATE-RESPONSE APDU (Result = rejected (permanent) or rejected (transient)) The AARE- is sent as user data on a P-CONNECT- response primitive (Result = user-rejection)
	void A_RLSind();				// AC-user A-RELEASE indication primitive
	void A_RLScnf(bool result);		//+AC-user A-RELEASE confirm primitive (Result = affirmative)
									//-AC-user A-RELEASE confirm primitive (Result = negative)
	void RLRQ();					// AC-peer A-RELEASE-REQUEST ADPU The RLRQ is sent as user data on a P-RELEASE request primitive
	void RLRE(bool result);			//+AC-peer A-RELEASE-RESPONSE APDU The RLRE+ is sent as user data on a P-RELEASE response primitive (Result = affirmative)
									//-AC-peer A-RELEASE-RESPONSE APDU The RLRE- is sent as user data on a P-RELEASE response primitive (Result = negative)
	void A_ABRind();				// AC-user A-ABORT indication primitive (Source = ACSE service user or ACSE service-provider)
	void ABRT();					// a)AC-peer A-ABORT APDU (Source = ACSE service-user or ACSE service-provider) The ABRT is sent as user data on a P-U-ABORT request primitive
	void P_PABind();				// AC-user A-P-ABORT indication primitive

	// a) When supported by version 1 of the session-protocol (ITU-T Rec. X.225 | ISO/IEC 8327-1), the A-ABORT APDU has
	// no APCI. The receipt of the P-U-ABORT indication implies its existence.


	// Predicate
	// ------------------------------------------------------------------
	// Code 			Meaning
	bool p1() const;	// ACPM can support requested connection
	bool p2() const;	// ACPM originated this association
};

}
}
}

#endif
