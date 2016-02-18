/*
 * Provider.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */
// *INDENT-OFF*
#ifndef ALS_SSAP_PROV_PROVIDER_H_
#define ALS_SSAP_PROV_PROVIDER_H_
#include <BitSet>
using std::bitset;

#include "Poco/ClassLoader.h"
#include "Poco/Exception.h"
#include "Poco/Any.h"
using Poco::ClassLoader;
using Poco::InvalidArgumentException;
using Poco::Any;

#include "als/base/srvc/SSAPServices.h"
#include "als/base/util/Bits.h"
#include "als/nsap/addr/SSAPAddr.h"
#include "als/nsap/QualityOfService.h"
using ALS::BASE::UTIL::Bits;
using ALS::BASE::SRVC::SSAPServices;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using ALS::NSAP::ADDR::SSAPAddr;


#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"
#include "als/tsap/serv/Initiator.h"
#include "als/tsap/serv/Responder.h"
#include "als/tsap/user/Linker.h"

#include "als/ssap/ssap.h"
#include "als/ssap/user/Initiator.h"
#include "als/ssap/user/Responder.h"
#include "als/ssap/serv/Initiator.h"
#include "als/ssap/serv/Responder.h"
#include "als/ssap/Reference.h"
#include "als/ssap/SSN.h"
#include "als/ssap/Token.h"
#include "als/ssap/Requirement.h"
#include "als/ssap/ResyncOption.h"
using ALS::SSAP::SSN;
using ALS::SSAP::Reference;
using ALS::SSAP::Requirement;
using ALS::SSAP::ResyncOption;
using ALS::SSAP::USER::AbortIndication;
using ALS::SSAP::USER::ActivityIndication;
using ALS::SSAP::USER::ActivityConfirmation;
using ALS::SSAP::USER::DataIndication;
using ALS::SSAP::USER::DataConfirmation;
using ALS::SSAP::USER::ReleaseIndication;
using ALS::SSAP::USER::ReleaseConfirmation;
using ALS::SSAP::USER::ReportIndication;
using ALS::SSAP::USER::SynchronizeIndication;
using ALS::SSAP::USER::SynchronizeConfirmation;
using ALS::SSAP::USER::TokenIndication;

namespace ALS {
	namespace BASE {
		namespace ROOT {
			class Logger;
		}
	}
	namespace SSAP {
		namespace SPDU {
			class AC;
			class AE;
			class AR;
			class MAP;
			class MIA;
			class MIP;
			class RA;
			class RS;
		}
	}
}
#include "als/ssap/FunctionalUnit.h"
#include "als/ssap/prov/FSM.h"
using statemap::TransitionUndefinedException;
using statemap::SmcException;


namespace ALS {
namespace SSAP {
namespace PROV {
	class Logger;
	class SPKT;

	enum class Event {
		SACTDreq, 		// SS-user		S-ACTIVITY-DISCARD request primitive 
		SACTDrsp, 		// SS-user		S-ACTIVITY-DISCARD response primitive 
		SACTEreq, 		// SS-user		S-ACTIVITY-END request primitive 
		SACTErsp, 		// SS-user		S-ACTIVITY-END response primitive 
		SACTIreq, 		// SS-user		S-ACTIVITY-INTERRUPT request primitive 
		SACTIrsp, 		// SS-user		S-ACTIVITY-INTERRUPT response primitive 
		SACTRreq, 		// SS-user		S-ACTIVITY-RESUME request primitive 
		SACTSreq, 		// SS-user		S-ACTIVITY-START request primitive 
		SCDreq, 		// SS-user		S-CAPABILITY-DATA request primitive 
		SCDrsp, 		// SS-user		S-CAPABILITY-DATA response primitive 
		SCGreq, 		// SS-user		S-CONTROL-GIVE request primitive 
		SCONreq, 		// SS-user		S-CONNECT request primitive 
		SCONrsp,		// SS-user		S-CONNECT (accept) response primitive 
		SDTreq, 		// SS-user		S-DATA request primitive 
		SEXreq, 		// SS-user		S-EXPEDITED-DATA request primitive 
		SGTreq, 		// SS-user		S-TOKEN-GIVE request primitive 
		SPTreq, 		// SS-user		S-TOKEN-PLEASE request primitive 
		SRELreq, 		// SS-user		S-RELEASE request primitive 
		SRELrsp,		// SS-user		S-RELEASE (accept) response primitive 
		SRSYNreq, 		// SS-user		S-RESYNCHRONIZE (abandon) request primitive 
		SRSYNrsp, 		// SS-user		S-RESYNCHRONIZE response primitive 
		SSYNMreq, 		// SS-user		S-SYNC-MAJOR request primitive 
		SSYNMrsp, 		// SS-user		S-SYNC-MAJOR response primitive 
		SSYNmreq, 		// SS-user		S-SYNC-MINOR request primitive 
		SSYNmdreq, 		// SS-user		S-SYNC-MINOR (data separation) request primitive 
		SSYNmrsp, 		// SS-user		S-SYNC-MINOR response primitive 
		STDreq, 		// SS-user		S-TYPED-DATA request primitive 
		SUABreq, 		// SS-user		S-U-ABORT request primitive 
		SUERreq, 		// SS-user		S-U-EXCEPTION-REPORT request primitive 

		TCONind, 		// TS-provider T-CONNECT indication primitive 
		TCONcnf, 		// TS-provider T-CONNECT confirm primitive 
		TDISind,		// TS-provider T-DISCONNECT indication primitive 

		TIM, 			// Timer Time out 

		AA, 			// ABORT ACCEPT SPDU 
		AB, 			// ABORT (not reuse) SPDU 
		AC, 			// ACCEPT SPDU (Note 1) 
		AD, 			// ACTIVITY DISCARD SPDU 
		ADA, 			// ACTIVITY DISCARD ACK SPDU 
		AE, 			// ACTIVITY END SPDU 
		AEA, 			// ACTIVITY END ACK SPDU 
		AI, 			// ACTIVITY INTERRUPT SPDU 
		AIA, 			// ACTIVITY INTERRUPT ACK SPDU 
		AR, 			// ACTIVITY RESUME SPDU 
		AS, 			// ACTIVITY START SPDU 
		CD, 			// CAPABILITY DATA SPDU 
		CDA, 			// CAPABILITY DATA ACK SPDU 
		CDO, 			// CONNECT DATA OVERFLOW SPDU 
		CN, 			// CONNECT SPDU 
		DN, 			// DISCONNECT SPDU 
		DT, 			// DATA TRANSFER SPDU 
		ED, 			// EXCEPTION DATA SPDU 
		ER, 			// EXCEPTION REPORT SPDU 
		EX, 			// EXPEDITED DATA SPDU 
		FN, 			// FINISH (not reuse) SPDU 
		GT, 			// GIVE TOKENS SPDU with Token Item parameter (Note 2) 
		GTA, 			// GIVE TOKENS ACK SPDU 
		GTC, 			// GIVE TOKENS CONFIRM SPDU 
		MAA, 			// MAJOR SYNC ACK SPDU 
		MAP, 			// MAJOR SYNC POINT SPDU 
		MIA, 			// MINOR SYNC ACK SPDU 
		MIP, 			// MINOR SYNC POINT SPDU 
		NF, 			// NOT FINISHED SPDU 
		OA, 			// OVERFLOW ACCEPT SPDU 
		PR_AB, 			// PREPARE (ABORT) SPDU 
		PR_MAA, 		// PREPARE (MAJOR SYNC ACK) SPDU 
		PR_RA, 			// PREPARE (RESYNCHRONIZE ACK) SPDU 
		PR_RS, 			// PREPARE (RESYNCHRONIZE) SPDU 
		PT, 			// PLEASE TOKENS SPDU with Token Item parameter (Notes 1 and 2) 
		RA, 			// RESYNCHRONIZE ACK SPDU 
		RF, 			// REFUSE (not reuse) SPDU 
		RS, 			// RESYNCHRONIZE (abandon) SPDU 
		TD 				// TYPED DATA SPDU 
	};
	enum SSNVariables { // monotone increasing starting at 0 as an index
		A	= 0,		// When the symmetric synchronize functional unit has not been selected, V(A) is used by the SPM and is the lowest serial
						// number to which a synchronization point confirmation is expected. No confirmation is expected when V(A) = V(M).
						// It is the lowest unconfirmed ssn.

		M	= 1,		// When the symmetric synchronize functional unit has not been selected, V(M) is used by the SPM and is the next serial
						// number to be used. It is the next ssn.

		R	= 2,		// When the symmetric synchronize functional unit has not been selected, V(R) is used by the SPM and is the lowest serial
						// number to which resynchronization restart is permitted. It's the lowest ssn for resynchronization
		
		Ado = 3,		// V(Ado) is used by the SPM and is the highest synchronization point serial number which was sent in a MINOR
						// SYNCHRONIZATION POINT SPDU with the data separation parameter set to true. Received SPDUs cannot be
						// discarded in case of resynchronization when V(Ado) is greater than or equal to V(A).
		
		Adi = 4,		// V(Adi) is used by the SPM and is the highest synchronization point serial number which was received in a MINOR
						// SYNCHRONIZATION POINT SPDU with the data separation parameter set to true
		SAs = 5,

		Ar	= 6,		// V(As) and V(Ar) are used by the SPM to manage synchronization point confirmations.
		As	= 7,		// V(As) is the lowest serial number on the SPM’s sending data flow to which a synchronization point confirmation is
						// expected to be received. No confirmation is expected to be received when V(As) = V(Ms). V(Ar) is the lowest serial
						// number on the SPM’s receiving data flow for which a confirmation has not yet been sent. No confirmation will be sent
						// by the SPM when V(Ar) = V(Mr)
		
		Ms	= 8,		// V(Ms) and V(Mr) are used by the SPM to maintain the next serial number to be used on the sending and receiving data
		Mr	= 9,		// flows. V(Ms) is the serial number of the next synchronization point to be sent. V(Mr) is the serial number of the next
						// synchronization point to be received
		
		Rs	= 10,		// V(Rs) and V(Rr) are used by the SPM to maintain the lowest serial numbers to which resynchronization restart is
		Rr	= 11		// permitted. V(Rs) is the lowest serial number on the SPM’s sending data flow to which resynchronization restart is permitted.
						// V(Rr) is the lowest serial number on the SPM’s receiving data flow to which resynchronization restart is permitted
		
	};
	class Variable {
	private:
		SSN SSNs[Rr + 1];
	public:
		SSN& operator() (SSNVariables v) {
			return SSNs[v];
		}
		const SSN& operator() (SSNVariables v) const {
			return SSNs[v];
		}
	};
	class SSAP_API Provider :
		public ALS::TSAP::USER::Linker,
		public ALS::TSAP::USER::Initiator,
		public ALS::TSAP::USER::Responder,
		public ALS::SSAP::SERV::Initiator,
		public ALS::SSAP::SERV::Responder,
		public ALS::SSAP::Token,
		FSM<Provider> {
		friend class SSAP_STA1;
		friend class SSAP_STA01;
		friend class SSAP_STA01A;
		friend class SSAP_STA01B;
		friend class SSAP_STA01C;
		friend class SSAP_STA01D;
		friend class SSAP_STA02A;
		friend class SSAP_STA02B;
		friend class SSAP_STA03;
		friend class SSAP_STA04A;
		friend class SSAP_STA04B;
		friend class SSAP_STA05A;
		friend class SSAP_STA05B;
		friend class SSAP_STA05C;
		friend class SSAP_STA06;
		friend class SSAP_STA08;
		friend class SSAP_STA09;
		friend class SSAP_STA10A;
		friend class SSAP_STA10B;
		friend class SSAP_STA11A;
		friend class SSAP_STA11B;
		friend class SSAP_STA11C;
		friend class SSAP_STA15A;
		friend class SSAP_STA15B;
		friend class SSAP_STA15C;
		friend class SSAP_STA15D;
		friend class SSAP_STA16;
		friend class SSAP_STA18;
		friend class SSAP_STA19;
		friend class SSAP_STA20;
		friend class SSAP_STA21;
		friend class SSAP_STA22;
		friend class SSAP_STA713;
		friend class SSAP_Default;
		friend class ProviderState;
	private:
		static const int	SB_NULL		= 0x000000;
		static const int	SB_CONN		= 0x000001; //connected
		static const int	SB_FINN		= 0x000002; //other side wants to finish
		static const int	SB_INIT		= 0x000004; //this side initiated the session
		static const int	SB_ASYN		= 0x000008; //asynchronous
		static const int	SB_EXPD		= 0x000010; //expedited service available on transport
		static const int	SB_CD		= 0x000020; //CD request in progress
		static const int	SB_CDA		= 0x000040; //awaiting CD response from user
		static const int	SB_GTC		= 0x000080; //GTC request in progress
		static const int	SB_MAP		= 0x000100; //MAP request in progress
		static const int	SB_MAA		= 0x000200; //awaiting MAP response from user
		static const int	SB_AE		= 0x000400; //MAP is really AE
		static const int	SB_RS		= 0x000800; //RS request in progress
		static const int	SB_RA		= 0x001000; //awaiting RS response from user
		static const int	SB_AI		= 0x002000; //AI request in progress
		static const int	SB_AIA		= 0x004000; //awaiting AI response from user
		static const int	SB_ED		= 0x008000; //user exception in progress
		static const int	SB_EDACK	= 0x010000; //awaiting user exception to be cleared
		static const int	SB_ERACK	= 0x020000; //awaiting provider exception to be cleared
		static const int	SB_Vact		= 0x040000; //activity in progress
		static const int	SB_Vsc		= 0x080000; //okay to reply to minorsync
		static const int	SB_Vnextact	= 0x100000; //activity MAP sent/received
		static const int	SB_RELEASE = 0x200000; //release in progress
		static const int	SB_ASYNC_CONN = 0x400000; //connections are async
		static const int	SB_TS_CONN	= 0x800000; //TS is established

	private:
		void*									ssap_user_instance;
		ALS::SSAP::USER::Initiator*				ssap_user_initiator;
		ALS::SSAP::USER::Responder*				ssap_user_responder;

		ALS::TSAP::SERV::Initiator*				tsap_serv_initiator;
		ALS::TSAP::SERV::Responder*				tsap_serv_responder;
		
		ALS::SSAP::USER::AbortIndication*		ssap_user_abortIndication;
		ALS::SSAP::USER::ActivityIndication*	ssap_user_activityIndication;
		ALS::SSAP::USER::ActivityConfirmation*	ssap_user_activityConfirmation;
		ALS::SSAP::USER::DataIndication*		ssap_user_dataIndication;
		ALS::SSAP::USER::DataConfirmation*		ssap_user_dataConfirmation;
		ALS::SSAP::USER::ReleaseConfirmation*	ssap_user_releaseConfirmation;
		ALS::SSAP::USER::ReleaseIndication*		ssap_user_releaseIndication;
		ALS::SSAP::USER::ReportIndication*		ssap_user_reportIndication;
		ALS::SSAP::USER::SynchronizeConfirmation*ssap_user_synchronizeConfirmation;
		ALS::SSAP::USER::SynchronizeIndication*	ssap_user_synchronizeIndication;

		ALS::TSAP::PROV::Provider*				tsap_serv_provider;
		
		ALS::TSAP::SERV::DataRequest*			tsap_data_request;
		ALS::TSAP::SERV::DisconnectRequest*		tsap_disconnect_request;


	private:
		static const int	SS_ACCEPT = 1;
		static const int	SS_ACCEPTED = 1;
		static const int	SS_REJECT = 2;
		static const int	SS_REJECTED = 2;

		static const int	SS_SIZE = 512;

		static const int	DT_MINSIZE = 64;			//FIXME in sskt
		static const int	SB_VRSN1 = 0;				// Version 1
		static const int	SB_VRSN2 = 1;				// Version 2
		static const int	SB_ALLVRSNS = (1 << SB_VRSN1) | (1 << SB_VRSN2);

		Logger* sb_logger;

	private:
		void reset();
	public:
		Provider();
		Provider(ALS::SSAP::USER::Initiator* initiator);
		virtual ~Provider();

		void setSSAPServices(const SSAPServices* ssapservices) {
			sb_services = ssapservices;
		}

		ALS::TSAP::USER::Initiator*	initiator() const;
		ALS::TSAP::PROV::Provider*&	provider();

		ReturnCode TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
		ReturnCode TConnectConfirmation(const TSAPAddr& responding, bool expedited, const QualityOfService& qualityOfService, int tsdusize, NetworkBuffer* data = nullptr);
		ReturnCode TDataIndication(const SharedNetworkBuffer& data);
		ReturnCode TExpeditedDataIndication(int cc = 0, const byte* data = nullptr);
		ReturnCode TDisconnectIndication(int reason, const string& data);
		ReturnCode TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices);

		ReturnCode SConnectRequest(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, const QualityOfService& qualityOfService, const Requirement&  requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, byte settings, int cc = 0, const void* data = nullptr);
		ReturnCode SConnectResponse(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement&  requirements, int settings, SSN& firstInitialSSN, SSN& secondInitialSSN, int cc = 0, const void* data = nullptr);

		ReturnCode SUAbortRequest(int cc = 0, const void* data = nullptr);

		ReturnCode SActivityDiscardRequest(int reason, int cc = 0, const void* data = nullptr);
		ReturnCode SActivityDiscardResponse(int cc = 0, const void* data = nullptr);
		ReturnCode SActivityEndRequest(SSN& ssn, int cc = 0, const void* data = nullptr);
		ReturnCode SActivityEndResponse(int cc = 0, const void* data = nullptr);
		ReturnCode SActivityEndResponse(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
		ReturnCode SActivityInterruptRequest(int reason, int cc = 0, const void* data = nullptr);
		ReturnCode SActivityInterruptResponse(int cc = 0, const void* data = nullptr);
		ReturnCode SActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN&  secondSSN, const Reference& reference, int cc = 0, const void* data = nullptr);
		ReturnCode SActivityStartRequest(const ActivityId& activityId, int cc = 0, const void* data = nullptr);

		ReturnCode SDataRequest(int cc = 0, const void* data = nullptr);
		ReturnCode SDataRequest(const SharedNetworkBuffer& data);
		ReturnCode SCapabilityDataRequest(int cc = 0, const void* data = nullptr);
		ReturnCode SCapabilityDataResponse(int cc = 0, const void* data = nullptr);
		ReturnCode SExpeditedDataRequest(int cc = 0, const void* data = nullptr);
		ReturnCode STypedDataRequest(int cc = 0, const void* data = nullptr);

		ReturnCode SSendRequest(bool begin, bool end, int cc = 0, const void* data = nullptr);
		ReturnCode SWriteRequest(bool typed, int cc = 0, const void* data = nullptr);

		ReturnCode SUExceptionReportRequest(int reason, int cc = 0, const void* data = nullptr);

		ReturnCode SResynchronizeRequest(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);
		ReturnCode SResynchronizeResponse(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);

		ReturnCode SSyncMajorRequest(SSN& firstSSN, int cc = 0, const void* data = nullptr);
		ReturnCode SSyncMajorResponse(int cc = 0, const void* data = nullptr);
		ReturnCode SSyncMajorResponse(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
		ReturnCode SSyncMinorRequest(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data = nullptr);
		ReturnCode SSyncMinorResponse(const SSN& firstSSN, int cc = 0, const void* data = nullptr);

		ReturnCode SControlGiveRequest();
		ReturnCode STokenGiveRequest(int tokens, int cc = 0, const void* data = nullptr);
		ReturnCode STokenPleaseRequest(int tokens, int cc = 0, const void* data = nullptr);

		ReturnCode SReleaseRequest(int secs, int cc = 0, const void* data = nullptr);
		ReturnCode SReleaseResponse(bool accept, int cc = 0, const void* data = nullptr);

		inline int settings()				const	{ return sb_settings; }
		inline const Reference& reference()	const	{ return sb_reference; }
		inline Requirement requirements()	const	{ return sb_requirements; }
		inline int available()				const	{ return sb_avail; }
		inline Bits owned()					const	{ return sb_owned;  }
		inline bool isInitiator()			const	{ return tsap_serv_initiator != nullptr; }
		inline bool isResponder()			const	{ return tsap_serv_responder != nullptr; }
		inline ALS::BASE::ROOT::Logger*	logger()	{ return (ALS::BASE::ROOT::Logger*)sb_logger; }

	private:
		ALS::SSAP::USER::AbortIndication&			abortIndication() const;
		ALS::SSAP::USER::ActivityIndication&		activityIndication() const;
		ALS::SSAP::USER::ActivityConfirmation&		activityConfirmation() const;
		ALS::SSAP::USER::DataIndication&			dataIndication() const;
		ALS::SSAP::USER::DataConfirmation&			dataConfirmation() const;
		ALS::SSAP::USER::ReleaseIndication&			releaseIndication() const;
		ALS::SSAP::USER::ReleaseConfirmation&		releaseConfirmation() const;
		ALS::SSAP::USER::ReportIndication&			reportIndication() const;
		ALS::SSAP::USER::SynchronizeIndication&		synchronizeIndication() const;
		ALS::SSAP::USER::SynchronizeConfirmation&	synchronizeConfirmation() const;
		ALS::SSAP::USER::TokenIndication&			tokenIndication() const;

		ALS::TSAP::SERV::DataRequest&				dataRequest() const;
		ALS::TSAP::SERV::DisconnectRequest&			disconnectRequest() const;


		bool FU(FunctionalUnit fu) const;
		bool AV(Tokens token) const;
		bool OWNED(Tokens token) const;
		bool initiating(Tokens token) const;
		bool accepting(Tokens token) const;
		bool initiating_when_owned_and_available(Tokens token) const;
		bool accepting_when_owned_and_available(Tokens token) const;

		static bool		hasSetting(int settings, int setting)			{ return (settings & setting) != 0; }
		static int		addSetting(int settings, int setting)			{ return settings |= setting; }
		static int		remSetting(int settings, int setting)			{ return settings &= ~setting; }

		void			dumpState() const;
		void			updateAMR01(Event event);
		void			updateAMR02(Event event, nat4 serial);
		void			updateAMR03(Event event, nat4 serial);
		void			updateAMR04(Event event, nat4 serial);
		void			updateAMR05(Event event, nat4 serial);
		void			updateAMR06(Event event, nat4 serial);
		void			updateAMR07(Event event, nat4 serial, ResyncOption resync);
		void			updateAMR08(Event event, nat4 serial, ResyncOption resync);
		void			updateAMR09(Event event, nat4 serial, ResyncOption resync);
		void			updateAMR10(Event event, nat4 serial, ResyncOption resync);
		void			updateAMR11(Event event, nat4 serial);
		void			updateAMR12(Event event);
		void			updateAMR13(Event event, nat4 serial);

		ReturnCode		providerException(const SmcException& exception) const;
		ReturnCode		serviceException(const TransitionUndefinedException& exception) const;
		ReturnCode		serviceException(const SmcException& exception) const;

		bool			TEXP;			// true: use of transport expedited service is selected for use on this session connection
		
		bool			Vact;			// true : an activity is in progress
										// false: no activity is in progress
		
		bool			Vnextact;		// true : a MAJOR SYNC POINT SPDU has been sent or received
										// false: an ACTIVITY END SPDU has been sent or received

		ResyncOption	Vrsp;
		SSN				Vrspnb;

		ResyncOption	Vrsps;
		ResyncOption	Vrspr;
		SSN				Vrspnbs;
		SSN				Vrspnbr;

		bool			SPMwinner;

		bool			Vtca;			// true: the SPM received the T-CONNECT indication (transport connection acceptor)
										// false: the SPM initiated the T-CONNECT request (transport connection initiator);
		
		bool			Vtrr;			// true: the transport connection can be reused by the SPM for another session connection
										// false: the transport connection cannot be reused by the SPM for another session connection
		
		bool			Vcoll;			// true: a collision of FINISH SPDUs has been detected
										// false: there has not been a collision of FINISH SPDUs
		
		bool			Vdnr;			// true: a DISCONNECT SPDU has been received in STA09 (following a collision of FINISH SPDUs)
										// false: no DISCONNECT SPDU has been received

		bool			Vsc;			// true: the SS-user has the right to issue minor synchronization point responses when V(A) is less than V(M);
										// false: the SS-user does not have the right to issue minor synchronization point responses
/*
When the symmetric synchronize functional unit has not been selected, Vsc is used by the SPM to determine whether or
not the SS-user has the right to send minor synchronization point responses. Vsc has the following values:
	– Vsc = true: the SS-user has the right to issue minor synchronization point responses when V(A) is less
than V(M);
	– Vsc = false: the SS-user does not have the right to issue minor synchronization point responses.
NOTE – The manipulation of V(A), V(M), V(R) and Vsc and the circumstances under which they are updated
are specified in clause 7 and are summarized in Table A.4.
*/

		Variable		V;

		bool			discard_rcv_flow;
		bool			discard_snd_flow;
		ResyncOption	rcv_flow_type;
		ResyncOption	snd_flow_type;
		SSN				rcv_flow_serial_number;
		SSN				snd_flow_serial_number;
		bool			rcv_flow_serial_number_present;
		bool			snd_flow_serial_number_present;

		SSN				serial_number;
		SSN				rcv_serial_number;
		SSN				rcv_first_serial_number;
		SSN				rcv_second_serial_number;

		SSN								sb_firstInitialSSN;
		SSN								sb_secondInitialSSN;
		int								sb_version;			//version number of protocol
		int								sb_vrsnmask;		//for initiating SPM...
		Bits							sb_state;			//our state
		SharedNetworkBuffer	 			sb_tx;				//from TDataIndication
		SPKT*							sb_retry;			//initial/const spkt
		int								V_A;				//lowest unconfirmed ssn
		int								V_M;				//next ssn
		int								V_R;				//lowest ssn for resynchronization
		byte							sb_resyncOption;	//resynchronization type (an SYNC_xxx code, plus...)
		int								sb_rsn;				//resync serial number
		int								sb_rsettings;		//proposed token settings on resync
		int								sb_pr;				//SPDU to prepare for (an SPDU code)
		SPKT*							sb_xspdu;			//saved expedited SPDU (really should be a linked list!)
		SPKT*							sb_spdu;			//for concatenated SPDUs
		NetworkBuffer*					sb_qbuf;			//for segmented (T)SSDUs
		int								sb_cc;				//  ..
		const void*						sb_data;
		int								sb_code;			//  ..
		int								sb_options;			//connect options
		byte							sb_settings;		//tokens settings on connect/confirmation
		int								sb_tsdu_us;			//our max TSDU size
		int								sb_tsdu_them;		//their max TSDU size
		Bits							sb_avail;			//tokens available
		Bits							sb_owned;			//tokens we own
		Requirement						sb_requirements;	//functional units selected
//		bitset<FUNCTIONAL_UNITS>		sb_requirements;	//functional units selected
		TSAPAddr						sb_calling;			//calling
		TSAPAddr						sb_called;			//called
		SSAPAddr						sb_initiating;		//initiator
		SSAPAddr						sb_responding;		//responder
		int								sb_maxtime;			//for SPM response during S-CONNECT
		bool							sb_expedited;
		int								sb_ssdusize;
		int								sb_tsdusize;
		Reference						sb_reference;
		QualityOfService				sb_qos;
		ClassLoader<USER::Responder>	sb_UserResponserLoader;
		const SSAPServices*				sb_services = nullptr;
		nat4							sb_ulsn;

private:
	// Outgoing Events
	ReturnCode InvalidOperation();

	ReturnCode SxABind();

	ReturnCode SACTDind();							// SS-provider S-ACTIVITY-DISCARD indication primitive
	ReturnCode SACTDcnf();							// SS-provider S-ACTIVITY-DISCARD confirm primitive
	ReturnCode SACTEind();							// SS-provider S-ACTIVITY-END indication primitive
	ReturnCode SACTEcnf();							// SS-provider S-ACTIVITY-END confirm primitive
	ReturnCode SACTIind();							// SS-provider S-ACTIVITY-INTERRUPT indication primitive
	ReturnCode SACTIcnf();							// SS-provider S-ACTIVITY-INTERRUPT confirm primitive
	ReturnCode SACTRind();							// SS-provider S-ACTIVITY-RESUME indication primitive
	ReturnCode SACTSind();							// SS-provider S-ACTIVITY-START indication primitive
	ReturnCode SCDind();							// SS-provider S-ACTIVITY-DATA indication primitive
	ReturnCode SCDcnf();							// SS-provider S-CAPABILITY-DATA confirm primitive
	ReturnCode SCGind();							// SS-provider S-CONTROL-GIVE indication primitive
	ReturnCode SCONind();							// SS-provider S-CONNECT indication primitive
	ReturnCode SCONcnf(bool accept);				// SS-provider S-CONNECT (accept(true)/reject(false)) confirm primitive
	ReturnCode SDTind();							// SS-provider S-DATA indication primitive
	ReturnCode SEXind();							// SS-provider S-EXPEDITED-DATA indication primitive
	ReturnCode SGTind(int tokens);					// SS-provider S-TOKEN-GIVE indication primitive
	ReturnCode SPABind();							// SS-provider S-P-ABORT indication primitive
	ReturnCode SPERind();							// SS-provider S-P-EXCEPTION-REPORT indication primitive
	ReturnCode SPTind(int tokens);					// SS-provider S-TOKEN-PLEASE indication primitive
	ReturnCode SRELind();							// SS-provider S-RELEASE indication primitive
	ReturnCode SRELcnf(bool accept);				// SS-provider S-RELEASE (accept(true)/reject(false)) confirm primitive
	ReturnCode SRSYNind();							// SS-provider S-RESYNCHRONIZE indication primitive
	ReturnCode SRSYNcnf();							// SS-provider S-RESYNCHRONIZE confirm primitive
	ReturnCode SSYNMind(const SPDU::MAP& map);		// SS-provider S-SYNC-MAJOR indication
	ReturnCode SSYNMcnf();							// SS-provider S-SYNC-MAJOR confirm
	ReturnCode SSYNmind();							// SS-provider S-SYNC-MINOR indication primitive
	ReturnCode SSYNmdind();							// SS-provider S-SYNC-MINOR (data separation) indication primitive
	ReturnCode SSYNmcnf();							// SS-provider S-SYNC-MINOR confirm primitive
	ReturnCode STDind();							// SS-provider S-TYPED-DATA indication primitive
	ReturnCode SUABind();							// SS-provider S-U-ABORT indication primitive
	ReturnCode SUERind();							// SS-provider S-U-EXCEPTION-REPORT indication primitive
	ReturnCode TCONreq(); 							// TS-user T-CONNECT request primitive
	ReturnCode TCONrsp(); 							// TS-user T-CONNECT response primitive
	ReturnCode TDISreq(); 							// TS-user T-DISCONNECT request primitive
	ReturnCode AA();								// ABORT ACCEPT SPDU
	ReturnCode AB(bool reuse);						// ABORT (reuse(r)/not reuse(nr)) SPDU
	ReturnCode AC(SPDU::AC& ac);					// ACCEPT SPDU
	ReturnCode AD();								// ACTIVITY DISCARD SPDU
	ReturnCode ADA();								// ACTIVITY DISCARD ACK SPDU
	ReturnCode AE(nat4 ssn);						// ACTIVITY END SPDU
	ReturnCode AEA();								// ACTIVITY END ACK SPDU
	ReturnCode AI();								// ACTIVITY INTERRUPT SPDU
	ReturnCode AIA();								// ACTIVITY INTERRUPT ACK SPDU
	ReturnCode AR();								// ACTIVITY RESUME SPDU
	ReturnCode AS(const ActivityId& activityId, int cc, const void* data);	// ACTIVITY START SPDU
	ReturnCode CD();								// CAPABILITY DATA SPDU
	ReturnCode CDA();								// CAPABILITY DATA ACK SPDU
	ReturnCode CDO();								// CONNECT DATA OVERFLOW SPDU
	ReturnCode CN();								// CONNECT SPDU
	ReturnCode DN();								// DISCONNECT SPDU
	ReturnCode DT();								// DATA TRANSFER SPDU
	ReturnCode ED();								// EXCEPTION DATA SPDU
	ReturnCode ER();								// EXCEPTION REPORT SPDU
	ReturnCode EX();								// EXPEDITED DATA SPDU
	ReturnCode FN(bool reuse);						// FINISH (reuse(r)/not reuse(nr)) SPDU
	ReturnCode GT(int tokens);						// GIVE TOKENS SPDU
	ReturnCode GTA();								// GIVE TOKENS ACK SPDU
	ReturnCode GTC();								// GIVE TOKENS CONFIRM SPDU
	ReturnCode MAA();								// MAJOR SYNC ACK SPDU
	ReturnCode MAP();								// MAJOR SYNC POINT SPDU
	ReturnCode MIA();								// MINOR SYNC ACK SPDU
	ReturnCode MIP();								// MINOR SYNC POINT SPDU
	ReturnCode MIP(bool dsp);						//MINOR SYNC (data separation(true)) POINT SPDU
	ReturnCode NF();								// NOT FINISHED SPDU
	ReturnCode OA();								// OVERFLOW ACCEPT SPDU
	ReturnCode PR_AB();								// PREPARE (ABORT) SPDU
	ReturnCode PR_MAA();							// PREPARE (MAJOR SYNC ACK) SPDU
	ReturnCode PR_RA();								// PREPARE (RESYNCHRONIZE ACK) SPDU
	ReturnCode PR_RS();								// PREPARE (RESYNCHRONIZE) SPDU
	ReturnCode PT(int tokens);						// PLEASE TOKENS SPDU
	ReturnCode RA();								// RESYNCHRONIZE ACK SPDU
	ReturnCode RF(bool reuse);						// REFUSE (reuse(r)/not reuse(nr)) SPDU
	ReturnCode RS(ResyncOption resync, nat4 ssn);	// RESYNCHRONIZE (abandon(a)/restart(r)/set(s)) SPDU
	ReturnCode TD();								// TYPED DATA SPDU

	void dump(FSM& context);

	// Special Actions
	void SA1();
	void SA2();
	void SA3();
	void SA4();
	void SA5(nat4 ssn);
	void SA6();
	void SA7();
	void SA8();
	void SA9();

	void SA10();
	void SA11() {}; // FIXME should not exists. Wait for completing the FSM
	void SA11(int tokens);
	void SA12();
	void SA13();
	void SA14();
	void SA15(int tokens);
	void SA16(bool reuse = false);
	void SA17();
	void SA18();
	void SA19();

	void SA20();
	void SA21();
	void SA22();
	void SA23();
	void SA24();
	void SA25(nat4 ssn);
	void SA26();
	void SA27(nat4 ssn);
	void SA28(nat4 ssn);
	void SA29();

	void SA30();
	void SA31();
	void SA32();
	void SA41();
	void SA42();
	void SA43();
	void SA44();
	void SA45();

	void SA50();
	void SA51();

	void SA62();
	void SA63();
	void SA64();
	void SA65();
	void SA66();
	void SA67();
	void SA68();
	void SA69();

	void SA70();
	void SA71();
	void SA72();


	//predicates
	bool p01() const;
	bool p02() const;
	bool p03() const;
	bool p04() const;
	bool p05() const;
	bool p06() const;
	bool p07() const;
	bool p08() const;
	bool p09() const;

	bool p10() const;
	bool p11() const;
	bool p12() const;
	bool p13() ;
	bool p14() const;
	bool p15() const;
	bool p16() const;
	bool p17() const;
	bool p18() const;
	bool p19(nat4 ssn) const;

	bool p20(nat4 ssn) const;
	bool p21() const;
	bool p22() const;
	bool p23() const;
	bool p24() const;
	bool p25() const;
	bool p26() const;
	bool p27() const;
	bool p28() const;
	bool p29() const;

	bool p30() const;
	bool p31() const;
	bool p32(ResyncOption type) const;
	bool p33() const;
	bool p34() const;
	bool p35() const;
	bool p36() const;
	bool p37() const;
	bool p38() const;
	bool p39() const;

	bool p40() const;
	bool p41() const;
	bool p42() const;
	bool p43() const;
	bool p44() const;
	bool p45() const;
	bool p46() const;
	bool p47() const;
	bool p48() const;
	bool p49() const;

	bool p50() const;
	bool p51() const;
	bool p52() const;
	bool p53(int tokens) const;
	bool p54(int tokens) const;
	bool p55() const;
	bool p56() const;
	bool p57(int tokens) const;
	bool p58(int tokens) const;
	bool p59(int tokens) const;

	bool p60(int tokens) const;
	bool p61(int tokens) const;
	bool p62() const;
	bool p63() const;
	bool p64() const;
	bool p65() const;
	bool p66() const;
	bool p67() const;
	bool p68() const;
	bool p69() const;

	bool p70() const;
	bool p71() const;
	bool p72() const;
	bool p73() const;
	bool p74() const;
	bool p75() const;
	bool p76() const;
	bool p77() const;
	bool p78() const;
	bool p79() const;

	bool p80() const;
	bool p81() const;
	bool p82() const;

	bool p173() const;
	bool p174() const;
	bool p175() const;
	bool p176() const;
	bool p177() const;
	bool p178() const;
	bool p179() const;
	bool p180(ResyncOption type) const;
	bool p184() const;
	bool p185() const;
	bool p186() const;
	bool p187() const;
	bool p201() const;
	bool p202() const;
	bool p204() const;

	static bool BAD_TSDU_SIZE(int s) {
		 return (s) ? (s) < DT_MINSIZE : 0;
	}
	static nat2 GET_TSDU_SIZE(int s) {
		return (s < DT_MINSIZE ? 0 : s);
	}

	ReturnCode ssaplose(int reason, const char* what, const char* fmt)  const;
	ReturnCode ssaplose(int reason, const char* what, const char* fmt, const Any& a1)  const;
	ReturnCode ssaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2)  const;
	ReturnCode ssaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3)  const;
	ReturnCode spktlose(int reason, const char* what, const string& fmt);
	ReturnCode spktlose(int reason, const char* what, const string& fmt, const Any& a1) ;
	ReturnCode spktlose(int reason, const char* what, const string& fmt, const Any& a1, const Any& a2);
	ReturnCode spktlose(int reason, const char* what, const string& fmt, const Any& a1, const Any& a2, const Any& a3);
	ReturnCode spktlose(int reason, const char* what, const char* fmt);
	ReturnCode spktlose(int reason, const char* what, const char* fmt, const Any& a1) ;
	ReturnCode spktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2);
	ReturnCode spktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3);
//	void disconnect(TPDU::DR& dr);

#if 0
		bool hasState(int state)	const		{ return (sb_state & state) != 0; }
		void addState(int state)				{ sb_state |= state; }
		void remState(int state)				{ sb_state &= ~state; }

		bool owns(int token)		const		{ return (sb_owned & token) != 0; }
		void addOwned(int token)				{ sb_owned |= token; }
		void remOwned(int token)				{ sb_owned &= ~token; }

		bool hasSetting(int setting)	const	{ return (sb_settings & setting) != 0;	}
		void addSetting(int setting)			{ sb_settings |= setting; }
		void remSetting(int setting)			{ sb_settings &= ~setting; }

		bool hasRequirement(int requirement) const { return (sb_requirements & requirement) != 0; }
		void addRequirement(int requirement)	{ sb_requirements |= requirement; }
		void remRequirement(int requirement)	{ sb_requirements &= ~requirement; }
		static bool		hasRequirement(int requirement, int required)	{ return (required & requirement) == required; }
#endif



};

}
}
}

#endif
// *INDENT-ON*