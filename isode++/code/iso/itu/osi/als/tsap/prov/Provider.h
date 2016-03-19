/*
 * Provider.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_PROV_PROVIDER_H_
#define ALS_TSAP_PROV_PROVIDER_H_

#include <stack>
using std::stack;

#include "Poco/ClassLoader.h"
#include "Poco/Semaphore.h"
using Poco::ClassLoader;
using Poco::Semaphore;

#include "als/tsap/tsap.h"

#include "als/nsap/QualityOfService.h"
#include "als/base/srvc/TSAPServices.h"
#include "als/nsap/addr/NSAPAddr.h"
#include "als/nsap/addr/TSAPAddr.h"
#include "als/nsap/addr/AddrTSAP.h"
#include "als/nsap/user/Initiator.h"
#include "als/nsap/user/Responder.h"
#include "als/nsap/serv/DataRequest.h"
#include "als/nsap/serv/DisconnectRequest.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"
#include "als/tsap/serv/Initiator.h"
#include "als/tsap/serv/Responder.h"
#include "als/tsap/tpdu/TPCI.h"
#include "als/tsap/prov/Logger.h"
#include "als/tsap/Disconnect.h"
#include "als/base/util/NetworkBuffer.h"

using ALS::BASE::SRVC::TSAPServices;
using ALS::NSAP::QualityOfService;
using ALS::NSAP::QualityOfServiceParameters;
using ALS::NSAP::ADDR::NSAPAddr;
using ALS::NSAP::ADDR::TSAPAddr;
using ALS::NSAP::ADDR::AddrTSAP;
using ALS::TSAP::TPDU::TPCI;
using ALS::TSAP::Disconnect;
using namespace ALS::TSAP::SERV;


namespace ALS { 
	namespace NSAP { 
		class TSAPServiceHandler;
	}
	namespace TSAP {
		namespace TPDU {
			class CC; class CR; class DT; class DR; class DC; class AK; class ED; class EA;
		}
	}
}
#ifdef ERROR
#undef ERROR
#endif
#include "als/tsap/prov/FSM.h"

namespace ALS { 
namespace TSAP {
namespace PROV {

class TSAP_API Provider : 
	public ALS::TSAP::SERV::Initiator,
	public ALS::TSAP::SERV::Responder,
	public ALS::NSAP::USER::Initiator,
	public ALS::NSAP::USER::Responder,
	public ALS::TSAP::PROV::FSM<Provider> {
	friend class ALS::NSAP::TSAPServiceHandler;
private:
	static const int	TS_SIZE		= 32;					// CR user data max
	static const int	TC_SIZE		= 32;					// CC user data max
	static const int	TX_SIZE		= 16;					// expdited data max
	static const int	SIZE_DFLT	= 128;
	static const int	SIZE_MAXTP0	= 2 * 1024;
	static const int	SIZE_8K		= 8 * 1024;

	static const int	TB_NULL		= 0x0000;
	static const int	TB_CONN		= 0x0001;				// connected
	static const int	TB_ASYN		= 0x0002;				// asynchronous
	static const int	TB_EXPD		= 0x0004;				// expedited transfer selected
	static const int	TB_TCP		= 0x0008;				// underlying service is TCP
	static const int	TB_X25		= 0x0010;				// underlying service is X25
	static const int	TB_TP0		= (TB_TCP | TB_X25);	// 
	static const int	TB_TP4		= 0x0040;				//
	/*
	 * all TP4's use this value as it make sense to have only one TP4 service compiled in...
	 */
	static const int	TB_STACKS	= (TB_TP0 | TB_TP4);	// all TS stacks
	static const int	TB_QWRITES	= 0x0080;				// queued writes OK 
	static const int	TB_RUN		= 0x0100;
	//
	enum State {
		WFNC,			//	Wait for network connection
		WFCC,			// 	Wait for the CC TPDU
		WBCL,			// 	Wait before releasing(wait for CC TPDU before sending the TPDU DR)
		OPEN,			// 	Transport connection is open
		CLOSING,		// 	Release in progress
		WFTRESP,		// 	Wait for T-CONNECT response
		CLOSED,			// 	Transport connection is closed
#if 0
		WFNC_R,			// 	Wait for network connection and reassignment in progress
		WFCC_R,			// 	Wait for CC TPDU and reassignment in progress
		WBCL_R,			// 	Wait before releasing and reassignment in progress
		OPEN_R,			//	Open and reassignment in progress
		OPEN_WR,		// 	Open and wait for reassignment
		CLOSING_R,		// 	Release in progress and reassignment in progress
		CLOSING_WR,		// 	Release in progress and wait for reassignment
		WFTRESP_WR,		// 	Wait for T_CONNECT response and wait for reassignment
		WBCL_WR,		// 	Wait before releasing and wait for reassignment
		WBOC,			// 	Wait before open complete(CC is unacknowledged)
		WBOC_WR,		// 	Wait before open complete and wait for reassignment
		CLOSING_BOC,	// 	BOC Wait before open complete and release in progress
		CLOSING_BOC_WR,	// 	BOC-WR Idem and wait for reassignment
		AKWAIT,			//	Waiting for acknowledgement of CC TPDU
		REFWAIT			//	Waiting for frozen reference time
#endif
	};
	const TSAPServices*			tb_services = nullptr;
	State						tb_state;

	short						tb_status;			// our state

	const byte*					tb_magic;			// generic pointer saved retry variables
	const byte*					tb_data;			// saved user data
	int							tb_cc;				// saved user data count
	bool						tb_expedited;		// saved expedited
	TSAPAddr					tb_called;			// saved addresses
	TSAPAddr					tb_calling;			//
//	TPCI*						tb_tpdu;			// initial packet
	short						tb_srcref;			// source reference
	short						tb_dstref;			// destination reference
	int							tb_tsdusize;		// maximum TSDU size
	int							tb_tpduslop;		// ..
	int							tb_tpdusize;		// for tp0ts
	int							tb_sent;			// TPDU bytes sent
	int							tb_recv;			// TPDU bytes recv
	QualityOfService			tb_qos;
	QualityOfServiceParameters	tb_qosp;
	int							tb_len;				// ..
	AddrTSAP					tb_initiating;		// initiator
	AddrTSAP					tb_responding;		// responder
	TSAPAddr					tb_realcalled;
	Logger*						tb_logger;
	int							tb_reason;
	string						tb_message;
	SharedNetworkBuffer			tb_qbuf;			// for segmented TSDUs
	Semaphore					tb_semaphore;
	ClassLoader<USER::Responder>tb_UserResponserLoader;
	
public:
	// TSAP FSM actions see FSM.sm and ITU-T X.224
	// outgoing events
	// ------------------------------------------------------------------------------------
	// Abbreviated name 								Category								Name
	void TCONind();										// TS-provider 							T-CONNECT indication primitive
	void TCONconf();									// TS-provider 							T-CONNECT confirm primitive
	void TDTind(const SharedNetworkBuffer& tsdu);		// TS-provider 							T-DATA indication primitive
	void TEXind(const SharedNetworkBuffer& tsdu);		// TS-provider 							T-EXPEDITED DATA indication primitive
	void TDISind();										// TS-provider 							T-DISCONNECT indication primitive
	void TDISind(int reason, const char* message = nullptr);
	void NDISreq(int reason, int cc = 0, const byte* data = nullptr);	// NS-user 								N-DISCONNECT Request primitive
	void NRSTresp();									// NS-user 								N-RESET Response primitive
	void NCONreq();										// NS-user 								N-CONNECT Request primitive
	void CR(NetworkBuffer* cr);							// TPDU Connection Request 				TPDU
	void CR(TPDU::CR& cr);								// TPDU Connection Request 				TPDU
	void CC(TPDU::CC& cc);								// TPDU Connection confirm 				TPDU
	void DR();											// TPDU Disconnect Request 				TPDU
	void DR(TPDU::DR& dr);								// TPDU Disconnect Request 				TPDU
	void DC();											// TPDU Disconnect confirm 				TPDU
	void DC(TPDU::DC& dc);								// TPDU Disconnect confirm 				TPDU
	void AK(TPDU::AK& ak);								// TPDU Data Acknowledgement 			TPDU
	void EA(TPDU::EA& ea);								// TPDU Expedited Data Acknowledgement 	TPDU
	void DT(TPDU::DT& dt);								// TPDU Data 							TPDU
	void ED(int cc, const byte* data);					// TPDU Expedited Data 					TPDU
	void ER();											// TPDU Error	 						TPDU
	void RJ();											// TPDU Reject 							TPDU
	void Entry(const char*);
	void Exit(const char*);

	// TSAP FSM predicates see FSM.sm and ITU-T X.224
	bool P0();						// T-CONNECT request unacceptable
	bool P1(const TPDU::CR* cr);	// Unacceptable CR TPDU
	bool P2();						// No network connection available
	bool P3();						// Network connection available and open
	bool P4();						// Network connection available and open in progress
	bool P5();						// Class in class 0 (class selected in CC)
	bool P6();						// Unacceptable CC
	bool P7();						// Class is class 2
	bool P8(const TPDU::CC* cc);	// Acceptable CC
	bool P9();						// Class 4 CR
	bool P10();						// Local choice

private:
	void reset();
public:
	Provider();
	Provider(ALS::TSAP::USER::Initiator* initiator);
	virtual ~Provider();

	virtual ALS::NSAP::USER::Initiator*		nsapUserInitiator() const {
		return static_cast<ALS::NSAP::USER::Initiator*>((Provider*)this);
	}
	virtual ALS::NSAP::USER::Responder*		nsapUserResponder() const {
		return static_cast<ALS::NSAP::USER::Responder*>((Provider*)this);
	}
	virtual ALS::NSAP::SERV::Initiator*&	nsapServInitiator() {
		return nsap_serv_initiator;
	}
	virtual ALS::NSAP::SERV::Responder*&	nsapServResponder() {
		return nsap_serv_responder;
	}

	virtual ReturnCode TConnectRequest(int tpdusize, const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TConnectRequest(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TConnectResponse(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	
	virtual ReturnCode TDataRequest(NetworkBuffer* tsdu);
	virtual ReturnCode TDataRequest(int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TExpeditedDataRequest(int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TDisconnectRequest(int reason, const TSAPAddr& responding, int cc = 0, const byte* data = nullptr);

	virtual ReturnCode NConnectIndication(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode NDisconnectIndication();
	virtual ReturnCode NDataIndication(const SharedNetworkBuffer& buffer);
	virtual ReturnCode NResetIndication(const NSAPAddr& originator, int reason);
	virtual ReturnCode NResetConfirmation();
	virtual ReturnCode NSetTSAPServices(const TSAPServices* tsapservices)			{ tb_services = tsapservices; return OK; }

	bool isConnected() const		{ return getState().getId() == TSAP::OPEN.getId(); }
	bool isExpedited() const		{ return hasStatus(TB_EXPD); }
	bool isAsynchronous() const		{ return hasStatus(TB_ASYN); }

	int& tpdusize()					{ return tb_tpdusize; }

	virtual Logger& logger() const	{ return tb_logger->logger();  }

private:
	void*									tsap_user_instance;
	ALS::TSAP::USER::Initiator*				tsap_user_initiator;
	ALS::TSAP::USER::Responder*				tsap_user_responder;

	ALS::NSAP::SERV::Initiator*				nsap_serv_initiator;
	ALS::NSAP::SERV::Responder*				nsap_serv_responder;

	ALS::TSAP::USER::DisconnectIndication*	tsap_user_disconnectIndication;
	ALS::TSAP::USER::DataIndication*		tsap_user_dataIndication;

	ALS::NSAP::SERV::DataRequest*			nsap_data_request;
	ALS::NSAP::SERV::DisconnectRequest*		nsap_disconnect_request;



	inline bool hasStatus(int state) const		{ return (tb_status & state) != 0;	}
	inline void setStatus(int state)			{ tb_status |= state; }
	inline void remStatus(int state)			{ tb_status &= ~state; }


	ReturnCode tsapPsig() const;
	ReturnCode TmissingP(void* p, const string& s) const;
	ReturnCode TtoomuchP(int length, const byte* b, int max) const;
	ReturnCode tsaplose(int reason, const char* what, const char* fmt)  const;
	ReturnCode tsaplose(int reason, const char* what, const char* fmt, const Any& a1)  const;
	ReturnCode tsaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2)  const;
	ReturnCode tsaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3)  const;
	ReturnCode tpktlose(int reason, const char* what, const char* fmt);
	ReturnCode tpktlose(int reason, const char* what, const char* fmt, const Any& a1) ;
	ReturnCode tpktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2);
	ReturnCode tpktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3);
	void disconnect(TPDU::DR& dr);

	ReturnCode		providerException(const statemap::SmcException& exception) const;
	ReturnCode		serviceException(const statemap::SmcException& exception) const;
	void			transitionUndefinedException(const statemap::TransitionUndefinedException& tue) const;
};

}}
}

#endif
