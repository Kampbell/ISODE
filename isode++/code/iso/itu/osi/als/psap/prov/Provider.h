/*
 * Provider.h
 *
 *  Created on: 16 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_PROV_PROVIDER_H_
#define ALS_PSAP_PROV_PROVIDER_H_
#include "als/base/util/Bits.h"
using ALS::BASE::UTIL::Bits;

#include "als/psap/psap.h"
#include "als/nsap/addr/PSAPAddr.h"
using ALS::NSAP::ADDR::PSAPAddr;
#include "als/nsap/QualityOfService.h"
using ALS::NSAP::QualityOfService;

#include "als/ssap/user/Initiator.h"
#include "als/ssap/user/Responder.h"
#include "als/ssap/serv/Initiator.h"
#include "als/ssap/serv/Responder.h"
#include "als/ssap/prov/Provider.h"
#include "als/ssap/user/Linker.h"
#include "als/psap/user/Initiator.h"
#include "als/psap/user/Responder.h"
#include "als/psap/serv/Initiator.h"
#include "als/psap/serv/Responder.h"
#include "als/ssap/Reference.h"
#include "als/ssap/SSN.h"
#include "als/ssap/Token.h"
#include "als/ssap/Requirement.h"
#include "als/ssap/ResyncOption.h"
using ALS::SSAP::SSN;
using ALS::SSAP::Reference;
using ALS::SSAP::Requirement;
using ALS::SSAP::ResyncOption;
#include "als/psap/prov/FSM.h"

namespace ALS {
namespace PSAP {
namespace PROV {
	class Logger;

class PSAP_API Provider :		
	public ALS::SSAP::USER::Linker,
	public ALS::SSAP::USER::Initiator,
	public ALS::SSAP::USER::Responder,
	public ALS::PSAP::SERV::Initiator,
	public ALS::PSAP::SERV::Responder,
	public ALS::SSAP::Token {
	friend  class STATE;
    friend  class STATE_STAI0;
    friend  class STATE_STAI1;
    friend  class STATE_STAI2;
    friend  class STATE_STAt0;
    friend  class STATE_STAac0;
    friend  class STATE_STAac1;
    friend  class STATE_STAac2;
    friend  class STATE_Default;
    friend  class ProviderState;
    friend  class FSM;

private:
	ALS::PSAP::USER::Initiator*		psap_user_initiator;
	ALS::PSAP::USER::Responder*		psap_user_responder;
	ALS::SSAP::SERV::Initiator*		ssap_serv_initiator;
	ALS::SSAP::SERV::Responder*		ssap_serv_responder;
	ALS::SSAP::PROV::Provider*		ssap_prov_provider;
	Logger* pb_logger;

	ALS::PSAP::PROV::FSM	pb_fsm;
	bool cr;		// collision of release request: true=detected, false=resolved or not detected
	bool rs;		//
	bool rl;		// release phase		: true=started, false=not started
	bool aep;		// activity end pending	: true=^pending, false=not pending
	Presentation_context_definition_list*			pb_pcdl;
	Presentation_context_definition_result_list*	pb_pcdrl;
	Abstract_syntax_name	pb_asn;
	Transfer_syntax_name	pb_atn;
	Default_context_name	pb_defaultContext;
	int						pb_defaultContextResult;
	Requirement				pb_srequirements;
	Requirement				pb_urequirements;
	nat4					pb_ssdusize;
	PSAPAddr				pb_responding;
	int						pb_result;

	static Provider* newInstance() { return new Provider(); }

	ALS::SSAP::USER::Initiator*		initiator() const;
	ALS::SSAP::USER::Responder*		responder() const;
	ALS::SSAP::SERV::Responder*&	provider();

	ReturnCode providerException(const statemap::SmcException& exception) const;
	ReturnCode serviceException(const statemap::SmcException& exception) const;
	ReturnCode userException(const statemap::SmcException& exception) const;
	void transitionUndefinedException(const statemap::TransitionUndefinedException& tue) const;

	Provider();
	void reset();
public:
	Provider(ALS::PSAP::USER::Initiator* initiator);
	virtual ~Provider();
	ALS::BASE::ROOT::Logger&		logger() { return *(ALS::BASE::ROOT::Logger*)pb_logger; }

public:
	// PSAP
	ReturnCode PConnectRequest(const PresentationAddress& callingAddr,	const PresentationAddress& calledAddr,	const Presentation_context_definition_list& presentationContexts, const Default_context_name& defaultContext, const Presentation_requirements& prequirements, const Mode_selector& mode, const User_session_requirements& srequirements, const SSN& isn, int settings, const Reference& reference, const QualityOfService& qualityOfService, const User_data* userData = nullptr);
	ReturnCode PConnectResponse(int status, const PresentationAddress& respondingAddr,const Presentation_context_definition_result_list& results, int defaultContextResult, const Presentation_requirements& prequirements, const User_session_requirements& usrequirements, const SSN& isn, byte settings, const Reference& reference, const User_data* userData = nullptr);
	ReturnCode PActivityDiscardRequest(int reason);
	ReturnCode PActivityDiscardResponse();
	ReturnCode PActivityInterruptRequest(int reason);
	ReturnCode PActivityInterruptResponse();
	ReturnCode PActivityStartRequest(const ActivityId& activityId, const User_data* userData = nullptr);
	ReturnCode PActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& ssn, const Reference& oldReference,	const User_data* userData = nullptr);
	ReturnCode PActivityEndRequest(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PActivityEndResponse(const User_data* userData = nullptr);


	ReturnCode PAlterContextRequest(const Presentation_context_addition_list& presentationAdditions, const Presentation_context_deletion_list& presentationDeletions, const User_data* userData = nullptr);
	ReturnCode PAlterContextResponse(const Presentation_context_addition_result_list& presentationAdditionResults,	const Presentation_context_deletion_result_list& presentationDeletionResults, const User_data* userData = nullptr);

	ReturnCode PCapabilityDataRequest(const User_data* userData);
	ReturnCode PDataRequest(const User_data* data = nullptr);
	ReturnCode PExpeditedDataRequest(const User_data* userData = nullptr);
	ReturnCode PTypedDataRequest(const User_data* userData = nullptr);
	ReturnCode PExpeditedDataIndication(const User_data& userData);
	ReturnCode PCapabilityDataResponse(const User_data* userData = nullptr);

	ReturnCode PResynchronizeRequest(const ResyncOption& type, const SSN& ssn, byte tokens, const User_data* userData = nullptr);
	ReturnCode PSyncMajorRequest(const SSN& ssn, const User_data* userData = nullptr);
	ReturnCode PSyncMinorRequest(const SyncOption& type, const SSN& ssn, const User_data* userData = nullptr);

	ReturnCode PResynchronizeResponse(const SSN& ssn, int tokens, const Presentation_context_identifier_list& presentationIdentififiers, const User_data* userData = nullptr);
	ReturnCode PSyncMajorResponse(const User_data* userData = nullptr);
	ReturnCode PSyncMinorResponse(const SSN& ssn, const User_data* userData = nullptr);

	ReturnCode PControlGiveRequest();
	ReturnCode PTokenGiveRequest(int tokens, const User_data* userData = nullptr);
	ReturnCode PTokenPleaseRequest(int tokens, const User_data* userData = nullptr);

	ReturnCode PUExceptionReportRequest(int reason, const User_data* userData = nullptr);

	ReturnCode PUAbortRequest(const User_data* userData = nullptr);

	ReturnCode PReleaseRequest(int secs, const User_data* userData = nullptr);
	ReturnCode PReleaseResponse(int status, const User_data* userData = nullptr);


	// SSAP
	ReturnCode SConnectIndication(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, int result, const QualityOfService& qualityOfService, const Requirement& requirements,	SSN& firstInitialSSN, SSN& secondInitialSSN, int settings, int ssdusize, int cc = 0, const void* data = nullptr);
	ReturnCode SConnectConfirmation(const Reference& reference,	const SSAPAddr& responding,	int result,	const QualityOfService& qualityOfService,	const Requirement& requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, int settings, int ssdusize,	int cc = 0, const void* data = nullptr, int rdcc = 0, const void* realdata = nullptr);

	ReturnCode SUAbortIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPAbortIndication(int reason, int extension, int cc = 0, const void* data = nullptr);

	ReturnCode SActivityDiscardIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityDiscardConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndIndication(const SSN& firstSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityStartIndication(const ActivityId&  activityId, int cc = 0, const void* data = nullptr);

	ReturnCode SDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataConfirmation(const SharedNetworkBuffer& data);
	ReturnCode SExpeditedDataIndication(const SharedNetworkBuffer& data);
	ReturnCode STypedDataIndication(const SharedNetworkBuffer& dataL);

	ReturnCode SUExceptionReportIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPExceptionReportIndication(int reason);

	ReturnCode SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);
	ReturnCode SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);

	ReturnCode SSyncMajorIndication(const SSN& firsSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMajorConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMajorConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMinorConfirmation(const SSN& firstSSN, int cc = 0, const void* data = nullptr);


	ReturnCode SControlGiveIndication( int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenGiveIndication(int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenPleaseIndication(int tokens, int cc = 0, const void* data = nullptr);

	ReturnCode SReleaseIndication(int cc = 0, const void* data = nullptr);
	ReturnCode SReleaseConfirmation(bool affirmative, int cc = 0, const void* data = nullptr);


private:
	// Specific action
	// ------------------------------------------------------------------
	void sa01(); // Mark presentation contexts proposed for definition which provider cannot support as provider-rejection.
	void sa02(); // Set cr and rl to FALSE.
	void sa03(); // Record abstract and transfer syntaxes for the presentation contexts of the agreed DCS and for the default context.
	void sa04(); // Propose at least one transfer syntax for each presentation context.
	void sa05(); // Propose a transfer syntax for the default context if one is named in the request service primitive.
	void sa06(); // Select one transfer syntax for each presentation context agreed for definition and include the agreed presentation contexts in the DCS.
	void sa07(); // Set rl to TRUE.
	void sa08(); // If rl is TRUE then set cr to TRUE.
	void sa09(); // If aep is TRUE then:	a) set aep to FALSE; and	b) if FU(CR) is TRUE then the synchronization points associated with the last activity no longer have associated DCSs.
	void sa10(); // Record selected transfer syntax for each new presentation context and include new presentation
	void sa11(); // Remove the presentation contexts agreed for deletion from the DCS.
	void sa12(); // Record FU(f) for f in fu-dom according to the presentation requirements in the CPA PPDU.
	void sa13(); // If FU(CR) then associate the DCS with the syncpoint identifier.
	void sa14(); // If FU(CR) and an activity is in progress, set the DCS to the inter-activity DCS.
	void sa15(); // Set aep to TRUE.
	void sa16(); // Set the DCS to that associated with the syncpoint identifier.
	void sa17(); // If FU(CR) then remember the DCS as the inter-activity DCS.
	void sa18(); // Set the DCS to that agreed during presentation-connection establishment.
	void sa19(); // Eliminate any associations between syncpoint serial number and the DCS for the current activity.
	void sa20(); // Set aep to FALSE.
	void sa21(); // Set the DCS as specified by the Presentation context identifier list parameter of the PPDU.
	void sa22(); // If FU(CR), then eliminate any associations between syncpoint identifiers and DCSs.

	// Predicates
	bool p01() const; // The presentation-connection is acceptable to the PPM (local matter).
	bool p02() const; //  If present, the named default context can be supported.
	bool p03() const; //  Each presentation data value is from a presentation context of the DCS proposed in the presentation-connection establishment, or from the default context if this DCS is empty.
	bool p04() const; //  Each presentation data value is from a presentations contexts of the DCS being accepted in the presentationconnection establishment, or from the default context if this DCS is empty.
	bool p05() const; //  Each presentation data value is from presentation contexts of the DCS, or from the default context if the DCS isempty.
	bool p06() const; //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion from the DCS by the peer PPM.
	bool p07() const; //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion from the DCS by the local PPM.
	bool p08() const; //  The value of cr is TRUE.
	bool p09() const; //  Each presentation data value is from presentation contexts of the DCS not accepted for deletion from the DCS, or from presentation contexts accepted for addition to the DCS, or if no such presentation contexts are available, from the default context.
	bool p11() const; //  FU(CM) is TRUE.
	bool p13() const; //  Each presentation data value is from the default context.
	bool p14() const; //  FU(CM) is false, or FU(CM) is true and typed data functional unit was selected as a User session requirement.
	bool p15() const; //  Each presentation data value is from presentation contexts of the DCS which was agreed during presentationconnection establishment, or from the default context if this DCS is empty.
	bool p16() const; //  Each presentation data value is from presentation contexts of the DCS associated with the pair of Old activity	identifier and Synchronization point serial number parameter values or from the default context when this DCS is empty.
	bool p17() const; //  FU(CR) is TRUE.
	bool p18() const; //  Each presentation data value is in presentation contexts of the DCS associated with the syncpoint identifier or from the default context if this DCS is empty.
	bool p19() const; //  Either no syncpoint identifier is associated with a DCS or the resync identifier is not associated with a DCS and is greater than the lowest syncpoint identifier which has an associated DCS.
	bool p20() const; //  The PPDU contains a Presentation context identifier list parameter.
	bool p21() const; //  Each presentation data value is from presentation contexts specified in the PPDU, or from the default context if no presentation contexts are specified in the PPDU.
	bool p22() const; //  For each presentation data value, an instance (chosen as a local matter) of encoding is supported by the PPM.
	bool p23() const; //  For each presentation data value the encoding is supported by the PPM.
	bool p24() const; //  Each presentation data value is from presentation contexts of the DCS, or from presentation contexts proposed for addition to the DCS by the local PPM, or from the default context if either the DCS is empty or all presentation	contexts of the DCS were proposed for deletion by the local PPM.
	bool p25() const; //  Each presentation data value is from presentation contexts of the DCS not proposed for deletion by the peer PPM or from presentation contexts proposed for addition to the DCS by the local PPM.
	bool p26() const; //  The syncpoint identifier has an associated DCS.
	bool p27() const; //  Old session connection identifier parameter present.
	bool p28() const; //  There is a DCS associated with the pair of Old activity identifier and Synchronization point serial number	parameters values.
	bool p29() const; //  Each presentation data value is from presentation contexts of the inter-activity DCS or from the default context if the inter-activity DCS is empty.
	bool p30() const; //  The value of rs is TRUE.

	// Outgoing events
	void AC();	//	 		PPDU 			ALTER CONTEXT
	void ACA();	//	 		PPDU 			ALTER CONTEXT ACKNOWLEDGE
	void ARP();	//	 		PPDU 			PROVIDER ABORT
	void ARU();	//	 		PPDU 			USER ABORT
	void CP();	//	 		PPDU 			PRESENTATION CONNECT
	void CPA();	//			PPDU 			PRESENTATION CONNECT ACCEPT
	void CPR();	//	 		PPDU 			PRESENTATION CONNECT REJECT
	void P_ACTDcnf();	//	PS primitive	P-ACTIVITY-DISCARD confirm
	void P_ACTDind();	//	PS primitive	P-ACTIVITY-DISCARD indication
	void P_ACTEcnf();	//	PS primitive	P-ACTIVITY-END confirm
	void P_ACTEind();	//	PS primitive	P-ACTIVITY-END indication
	void P_ACTIcnf();	//	PS primitive	P-ACTIVITY-INTERRUPT confirm
	void P_ACTIind();	//	PS primitive	P-ACTIVITY-INTERRUPT indication
	void P_ACTRind();	//	PS primitive	P-ACTIVITY-RESUME indication
	void P_ACTSind();	//	PS primitive	P-ACTIVITY-START indication
	void P_ALTERcnf();	//	PS primitive	P-ALTER-CONTEXT confirm
	void P_ALTERind();	//	PS primitive	P-ALTER-CONTEXT indication
	void P_CDcnf();	//	 	PS primitive	P-CAPABILITY-DATA confirm
	void P_CDind();	//	 	PS primitive	P-CAPABILITY-DATA indication
	void P_CGind();	//	 	PS primitive	P-CONTROL-GIVE indication
	void P_CONcnf(bool accept);	// +	PS primitive	P-CONNECT confirm accept
							// -	PS primitive	P-CONNECT confirm reject
	void P_CONind();	//	PS primitive	P-CONNECT indication
	void P_DTind();	//	 	PS primitive	P-DATA indication
	void P_EXind();	//		PS primitive	P-EXPEDITED-DATA indication
	void P_GTind();	//	 	PS primitive	P-TOKEN-GIVE indication
	void P_PABind();	//	PS primitive	P-P-ABORT indication
	void P_PERind();	//	PS primitive	P-P-EXCEPTION-REPORT indication
	void P_PTind();	//	 	PS primitive	P-TOKEN-PLEASE indication
	void P_RELcnf(bool accept);	//+ PS primitive	P-RELEASE confirm accept
								//-	PS primitive	P-RELEASE confirm reject
	void P_RELind();	//	PS primitive	P-RELEASE indication
	void P_RSYNcnf();	//	PS primitive	P-RESYNCHRONIZE confirm
	void P_RSYNind();	//	PS primitive	P-RESYNCHRONIZE indication
	void P_SYNMcnf();	//	PS primitive	P-SYNC-MAJOR confirm
	void P_SYNMind();	//	PS primitive	P-SYNC-MAJOR indication
	void P_SYNmcnf();	//	PS primitive	P-SYNC-MINOR confirm
	void P_SYNmind();	//	PS primitive	P-SYNC-MINOR indication
	void P_TDind();	//	 	PS primitive	P-TYPED-DATA indication
	void P_UABind();	// 	PS primitive 	P-U-ABORT indication
	void P_UERind();	// 	PS primitive 	P-U-EXCEPTION-REPORT indication
	void RS();	// 			PPDU 			RESYNCHRONIZE
	void RSA();	// 		PPDU 			RESYNCHRONIZE acknowledge
	void S_ACTDreq();	//	SS primitive	S-ACTIVITY-DISCARD request
	void S_ACTDrsp();	//	SS primitive	S-ACTIVITY-DISCARD response
	void S_ACTEreq();	//	SS primitive	S-ACTIVITY-END request
	void S_ACTErsp();	//	SS primitive	S-ACTIVITY-END response
	void S_ACTIreq();	//	SS primitive	S-ACTIVITY-INTERRUPT request
	void S_ACTIrsp();	//	SS primitive	S-ACTIVITY-INTERRUPT response
	void S_ACTRreq();	//	SS primitive	S-ACTIVITY-RESUME request
	void S_ACTSreq();	//	SS primitive	S-ACTIVITY-START request
	void S_CGreq();	//		SS primitive	S-CONTROL-GIVE request
	void S_GTreq();	//		SS primitive	S-TOKEN-GIVE request
	void S_PTreq();	//		SS primitive	S-TOKEN-PLEASE request
	void S_RELreq();	//	SS primitive	S-RELEASE request
	void S_RELrsp(bool accept); //+	SS primitive	S-RELEASE response accept
								//-	SS primitive	S-RELEASE response reject
	void S_RSYNreq();	//	SS primitive	S-RESYNCHRONIZE request
	void S_RSYNrsp();	//	SS primitive	S-RESYNCHRONIZE response
	void S_SYNMreq();	//	SS primitive	S-SYNCHRONIZE-MAJOR request
	void S_SYNMrsp();	//	SS primitive	S-SYNCHRONIZE-MAJOR response
	void S_SYNmreq();	//	SS primitive	S-SYNCHRONIZE-MINOR request
	void S_SYNmrsp();	//	SS primitive	S-SYNCHRONIZE-MINOR response
	void S_UERreq();	//	SS primitive	S-U-EXCEPTION-REPORT request
	void TC();	// 			PPDU 			CAPABILITY DATA
	void TCC();	// 		PPDU 			CAPABILITY DATA ACKNOWLEDGE
	void TD();	// 			PPDU 			DATA
	void TE();	// 			PPDU 			EXPEDITED DATA
	void TTD();	// 		PPDU 			P-TYPED DATA

	void P_UERreq(); 	// PS primitive	P-U-EXCEPTION-REPORT request

	void S_ACTDind();	// PS primitive S-ACTIVITY-DISCARD indication


};

}
}
}

#endif
