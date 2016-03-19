/*
 * Provider.cpp
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */
#define ISODE

#include <typeinfo>
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <memory>
using std::ostringstream;
using std::cout;
using std::endl;
using std::pow;
using std::max;
using std::unique_ptr;

#define maximum max

#include "Poco/ClassLibrary.h"
#ifndef POCO_EXPORT_INTERFACE

#define POCO_EXPORT_INTERFACE(cls, itf) \
    pManifest->insert(new Poco::MetaObject<cls, _Base>(itf));

#endif
#include "Poco/Format.h"
#include "Poco/ClassLoader.h"
#include "Poco/Net/NetException.h"
#include "Poco/SharedLibrary.h"
#include "Poco/Thread.h"
using Poco::format;
using Poco::SharedLibrary;
using Poco::Thread;
using Poco::ClassLoader;

#include "als/base/root/NotYetImplementedException.h"
#include "als/base/srvc/SSAPServices.h"
#include "als/base/srvc/SSAPService.h"

#include "als/ssap/AbortCode.h"
#include "als/ssap/prov/Provider.h"
#include "als/ssap/prov/Logger.h"
#include "als/ssap/prov/SPKT.h"
#include "als/ssap/user/Linker.h"

#include "als/ssap/spdu/Category.h"
#include "als/ssap/spdu/CATENE.h"
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/spdu/AA.h"
#include "als/ssap/spdu/AB.h"
#include "als/ssap/spdu/AC.h"
#include "als/ssap/spdu/AD.h"
#include "als/ssap/spdu/ADA.h"
#include "als/ssap/spdu/AE.h"
#include "als/ssap/spdu/AEA.h"
#include "als/ssap/spdu/AI.h"
#include "als/ssap/spdu/AIA.h"
#include "als/ssap/spdu/AR.h"
#include "als/ssap/spdu/AS.h"
#include "als/ssap/spdu/CD.h"
#include "als/ssap/spdu/CDA.h"
#include "als/ssap/spdu/CDO.h"
#include "als/ssap/spdu/CN.h"
#include "als/ssap/spdu/DN.h"
#include "als/ssap/spdu/DT.h"
#include "als/ssap/spdu/ED.h"
#include "als/ssap/spdu/ER.h"
#include "als/ssap/spdu/EX.h"
#include "als/ssap/spdu/FN.h"
#include "als/ssap/spdu/GT.h"
#include "als/ssap/spdu/GTA.h"
#include "als/ssap/spdu/GTC.h"
#include "als/ssap/spdu/MAA.h"
#include "als/ssap/spdu/MAP.h"
#include "als/ssap/spdu/MIA.h"
#include "als/ssap/spdu/MIP.h"
#include "als/ssap/spdu/NF.h"
#include "als/ssap/spdu/OA.h"
#include "als/ssap/spdu/PR.h"
#include "als/ssap/spdu/PT.h"
#include "als/ssap/spdu/RA.h"
#include "als/ssap/spdu/RF.h"
#include "als/ssap/spdu/RS.h"
#include "als/ssap/spdu/TD.h"

using ALS::BASE::ROOT::NotYetImplementedException;
using ALS::BASE::SRVC::SSAP_SERVICES;
using ALS::BASE::SRVC::SSAPService;

using ALS::SSAP::AbortCode;
using ALS::SSAP::SPDU::Category;
using ALS::SSAP::SPDU::CATENE;
using ALS::SSAP::SPDU::AA;
using ALS::SSAP::SPDU::AB;
using ALS::SSAP::SPDU::AC;
using ALS::SSAP::SPDU::AD;
using ALS::SSAP::SPDU::ADA;
using ALS::SSAP::SPDU::AE;
using ALS::SSAP::SPDU::AEA;
using ALS::SSAP::SPDU::AI;
using ALS::SSAP::SPDU::AIA;
using ALS::SSAP::SPDU::AR;
using ALS::SSAP::SPDU::AS;
using ALS::SSAP::SPDU::CD;
using ALS::SSAP::SPDU::CDA;
using ALS::SSAP::SPDU::CDO;
using ALS::SSAP::SPDU::CN;
using ALS::SSAP::SPDU::DN;
using ALS::SSAP::SPDU::DT;
using ALS::SSAP::SPDU::ED;
using ALS::SSAP::SPDU::ER;
using ALS::SSAP::SPDU::EX;
using ALS::SSAP::SPDU::FN;
using ALS::SSAP::SPDU::GT;
using ALS::SSAP::SPDU::GTA;
using ALS::SSAP::SPDU::GTC;
using ALS::SSAP::SPDU::MAA;
using ALS::SSAP::SPDU::MAP;
using ALS::SSAP::SPDU::MIA;
using ALS::SSAP::SPDU::MIP;
using ALS::SSAP::SPDU::NF;
using ALS::SSAP::SPDU::OA;
using ALS::SSAP::SPDU::PR;
using ALS::SSAP::SPDU::PT;
using ALS::SSAP::SPDU::RA;
using ALS::SSAP::SPDU::RF;
using ALS::SSAP::SPDU::RS;
using ALS::SSAP::SPDU::TD;


#include "als/tsap/prov/Exception.h"
#include "als/tsap/prov/Provider.h"


void pocoInitializeLibrary() {
	cout << "##################### ALS::SSAP::PROV::Provider initializing" << endl;
}
void pocoUninitializeLibrary() {
	cout << "##################### ALS::SSAP::PROV::Provider uninitializing" << endl;
}
POCO_BEGIN_NAMED_MANIFEST(ALS_TSAP_USER_Responder, ALS::TSAP::USER::Responder)
POCO_EXPORT_INTERFACE(ALS::SSAP::PROV::Provider, "ALS::TSAP::USER::Responder")
POCO_END_MANIFEST


namespace ALS {
namespace SSAP {
namespace PROV {

void Provider::reset() {
	TEXP = false;
	Vact = false;
	Vnextact = false;
	Vrsp = no;
	Vrsps = no;
	Vrspr = no;
	SPMwinner = false;
	Vtca = false;
	Vtrr = false;
	Vcoll = false;
	Vdnr = false;
	Vsc = false;
	discard_rcv_flow = false;
	discard_snd_flow = false;
	rcv_flow_type = no;
	snd_flow_type = no;
	rcv_flow_serial_number_present = false;
	snd_flow_serial_number_present = false;
	sb_version = 0;			//version number of protocol
	sb_vrsnmask = 0;		//for initiating SPM...
	sb_state;				//our state
	sb_tx = nullptr;			//from TDataIndication
	sb_retry = nullptr;			//initial/final spkt
	V_A = 0;				//lowest unconfirmed ssn
	V_M = 0;				//next ssn
	V_R = 0;				//lowest ssn for resynchronization
	sb_resyncOption = 0;	//resynchronization type (an SYNC_xxx code, plus...)
	sb_rsn = 0;				//resync serial number
	sb_rsettings = 0;		//proposed token settings
	sb_pr = 0;				//SPDU to prepare for (an SPDU code)
	sb_xspdu = nullptr;		//saved expedited SPDU (really should be a linked list!)
	sb_spdu = nullptr;			//for concatenated SPDUs
	sb_qbuf = nullptr;			//for segmented (T)SSDUs
	sb_cc = 0;				//  ..
	sb_data = nullptr;			//  ..
	sb_code = 0;			//  ..
	sb_options = 0;			//connect options
	sb_settings = 0;		//tokens settings on connect
	sb_tsdu_us = 0;			//our max TSDU size
	sb_tsdu_them = 0;		//their max TSDU size
	sb_avail = 0;			//tokens available
	sb_owned = 0;			//tokens we own
//	sb_requirements(0);		//functional units selected
	sb_maxtime = 10;		//for SPM response during S-CONNECT
	sb_expedited = false;
	sb_ssdusize = 0;
	sb_logger = new Logger(0);

	ssap_user_instance = nullptr;
	ssap_user_initiator = nullptr;
	ssap_user_responder = nullptr;
	tsap_serv_initiator = nullptr;
	tsap_serv_responder = nullptr;
	tsap_serv_provider = nullptr;
	ssap_user_abortIndication = nullptr;
	ssap_user_activityIndication = nullptr;
	ssap_user_activityConfirmation = nullptr;
	ssap_user_dataIndication = nullptr;
	ssap_user_dataConfirmation = nullptr;
	ssap_user_releaseConfirmation = nullptr;
	ssap_user_releaseIndication = nullptr;
	ssap_user_reportIndication = nullptr;
	ssap_user_synchronizeConfirmation = nullptr;
	ssap_user_synchronizeIndication = nullptr;

	setDebugFlag(true);
}
Provider::Provider() {
	reset();
}
Provider::Provider(ALS::SSAP::USER::Initiator* initiator)  {
	reset();
	ssap_user_initiator = initiator;
	ssap_user_responder = nullptr;
	tsap_serv_initiator = nullptr;
	tsap_serv_responder = nullptr;

	ssap_user_instance = nullptr;
	ssap_user_abortIndication = initiator;
	ssap_user_activityIndication = initiator;
	ssap_user_activityConfirmation = initiator;
	ssap_user_dataIndication = initiator;
	ssap_user_dataConfirmation = initiator;
	ssap_user_releaseConfirmation = initiator;
	ssap_user_releaseIndication = initiator;
	ssap_user_reportIndication = initiator;
	ssap_user_synchronizeConfirmation = initiator;
	ssap_user_synchronizeIndication = initiator;

	ALS::TSAP::PROV::Provider* provider = new ALS::TSAP::PROV::Provider(this);
	tsap_serv_initiator = provider;
	tsap_data_request = (TSAP::SERV::DataRequest*) tsap_serv_initiator;
	tsap_disconnect_request = (TSAP::SERV::DisconnectRequest*) tsap_serv_initiator;
}
Provider::~Provider() {
	delete tsap_serv_initiator;
	delete ssap_user_instance;
	delete sb_logger;
}
ALS::TSAP::USER::Initiator*	Provider::initiator() const {
	return static_cast<TSAP::USER::Initiator*>((Provider*)this);
	return nullptr;
}
ALS::TSAP::PROV::Provider*&	Provider::provider() {
	return tsap_serv_provider;
}

ReturnCode Provider::TConnectIndication(const TSAPAddr& calling, const TSAPAddr& called, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc, const byte* data) {
	ReturnCode rc = DONE;
	try {
		sb_calling = calling;
		sb_called = called;
		sb_expedited = expedited;
		sb_tsdusize = tsdusize;
		sb_qos = qualityOfService;
		sb_cc = cc;
		sb_data = data;
		tsap_serv_responder = tsap_serv_provider;
		tsap_data_request = (TSAP::SERV::DataRequest*) tsap_serv_provider;
		tsap_disconnect_request = (TSAP::SERV::DisconnectRequest*) tsap_serv_provider;

		TCONind();
	} catch (const SmcException& e) {
		rc = providerException(e);
	}
	return rc;
}
ReturnCode Provider::TConnectConfirmation(const TSAPAddr& responding, bool expedited, const QualityOfService& qualityOfService, int tsdusize, NetworkBuffer* data) {
	sb_tsdusize = tsdusize;
	sb_qos = qualityOfService;
//	sb_data = data;
//FIXME when responding is wrong
//FIXME sb_responding is also wronng
//FIXME	sb_responding = responding;
	sb_expedited = expedited;
	TEXP = expedited;
//	spkt = retry;
//	retry = nullptr;

	sb_state.add(SB_TS_CONN); // now got as far as transport

	sb_responding.sa_addr = responding;
	if (expedited)
		sb_state.add(SB_EXPD);
	else
		sb_requirements[EXPEDITED] = false;
	if (sb_version < SB_VRSN2) /* XXX */
		sb_tsdu_us = sb_tsdu_them = GET_TSDU_SIZE(tsdusize);

	TCONcnf();
	return DONE;
}
ReturnCode Provider::TExpeditedDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc = DONE;
	try {
		sb_tx = data;
		unique_ptr<SPDU::SPDU> spdu(SPDU::SPDU::fromTSDU(Category::CAT0_OR_CAT1, *sb_tx.get()));
		ALS::SSAP::SPDU::PR* pr = (SPDU::PR*)spdu.get();
		switch (pr->type()) {
		case SPDU::PR::PR_MAA: FSM<Provider>::PR_MAA(); break;
		case SPDU::PR::PR_RS:  FSM<Provider>::PR_RS(); break;
		case SPDU::PR::PR_RA:  FSM<Provider>::PR_RA(); break;
		case SPDU::PR::PR_AB:  FSM<Provider>::PR_AB(); break;
		}
	} catch (const SmcException& e) {
		rc = providerException(e);
	}
	return rc;
	
}
ReturnCode Provider::TDisconnectIndication(int reason, const string& data) {
	ReturnCode rc = DONE;
	try {
		TDISind();
	} catch (const SmcException& e) {
		rc = providerException(e);
	}
	return rc;
}
ReturnCode Provider::TDataIndication(const SharedNetworkBuffer& data) {
	ReturnCode rc = OK;
	int result = 0;
	try {
		sb_tx = data;

		unique_ptr<SPDU::SPDU> spdu(SPDU::SPDU::fromTSDU(Category::CAT0_OR_CAT1, *sb_tx.get()));
		sb_spdu = spdu.get();
		poco_check_ptr(sb_spdu);
#if 0
		if (!spdu.hasMask(SMASK_SPDU_EXPD)) {
			switch (sb_pr) {
			case SPDU_PR:
				break;

			case SPDU_MAA:
				if (spdu.si() == SPDU_MAA)
					sb_pr = SPDU_PR;
				break;

			case SPDU_RS:
				switch (spdu.si()) {
				case SPDU_AB:
//				case SPDU_AI:	// aka SPDU_AB
					if (spdu.hasMask(SMASK_SPDU_AB))
						break; // else fall
				case SPDU_AD:
				case SPDU_RS:
					sb_pr = SPDU_PR;
					break;

				default:
					logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				break;

			case SPDU_RA:
				switch (spdu.si()) {
				case SPDU_AB:
					break;

				case SPDU_AA:
//							case SPDU_AIA:
					if (spdu.hasMask(SMASK_SPDU_AA))
						break; // else fall
				case SPDU_ADA:
				case SPDU_RA:
					sb_pr = SPDU_PR;
					break;

				default:
drop_it:
					logger().exception("discarding " + spdu.getLiteral() + " SPDU");
//					goto spin;
					if (bool(sb_spdu))
						continue;
				}
				break;

			case SPDU_AB:
				if (spdu.si() != SPDU_AB) {
					logger().exception(String.format("discarding SPDU: code %d ", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				sb_pr = SPDU_PR;
				break;

			default:
				break;
			}
			switch (spdu.si()) {
			case SPDU_PR:
			case SPDU_EX:
				spdu.spdulose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU 0x%x on Transport normal flow", spdu.si());
				return nullptr;
			}
		} else { // SPDU on transport expedited
			switch (spdu.si()) {
			case SPDU_PR:
				if (sb_pr != SPDU_PR) {
					spdu.spdulose(AbortCode::SC_PROTOCOL, nullptr, "PR SPDU followed by PR");
					return nullptr;
				}
			// fall
			case SPDU_AB:
			case SPDU_AA:
			case SPDU_EX:
				break;

			default:
				spdu.spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU 0x%x on Transport expedited", spdu.si());
				return nullptr;
			}
		}

		if (hasState(SB_RS | SB_AI)) {
			switch (spdu.si()) {
			case SPDU_PR:
				spdu_pr = (SPDU_PR) spdu;
				switch (spdu_pr.getType()) {
				case PR_RS:
				case PR_RA:
					break;
				default:
					logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				break;

			case SPDU_RS:
				spdu_rs = (SPDU_RS) spdu;
				if (SDoCollideAux(isInitiator(), resyncOption, rsn(), spdu_rs.getType(),
								  (long) spdu_rs.getSerial()) != NOTOK) {
					logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				break;

			case SPDU_RA:
				break;

			case SPDU_AD:
				if (SDoCollideAux(isInitiator(), resyncOption, rsn(), DISCARD, 0L) != NOTOK) {
					logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				break;

			case SPDU_AB:
//					case SPDU_AI:	// aka SPDU_AB
				if (spdu.hasMask(SMASK_SPDU_AB))
					break;
				if (SDoCollideAux(isInitiator(), resyncOption, rsn(), INTERRUPT, 0L) != NOTOK) {
					logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
					if (bool(sb_spdu))
						continue;
				}
				break;
			}
		}

		if (hasState((SB_ED | SB_ERACK))) {
			switch (spdu.si()) {
			case SPDU_AB:
				break;

			case SPDU_MAP:
			case SPDU_MIP:
				if (hasState(SB_ED))
					break;
				logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
				if (bool(sb_spdu))
					continue;

			case SPDU_PR:
				spdu_pr = (SPDU_PR) spdu;
				if (spdu_pr.getType() == PR_RS)
					break;
				logger().exception(String.format("discarding SPDU: %d", spdu.si()));
				if (bool(sb_spdu))
					continue;

			case SPDU_GT:
				spdu_gt = (SPDU_GT) spdu;
				if (spdu.hasMask(SMASK_SPDU_GT) && spdu.hasMask(SMASK_GT_TOKEN)
						&& bool(spdu_gt.getToken() & DATA_TOKEN))
					break; // else fall //

			default:
				logger().exception(String.format("discarding SPDU: code %d", spdu.si()));
				if (bool(sb_spdu))
					continue;
			}
		}

		if (sb_len > 0) {
			switch (spdu.si()) {
			case SPDU_PT:
			case SPDU_EX:
				break;

			case SPDU_PR:
				spdu_pr = (SPDU_PR) spdu;
				if (spdu_pr.getType() != PR_RS)
					break;
			case SPDU_RS:
			case SPDU_ER:
			case SPDU_ED:
			case SPDU_AD:
//					case SPDU_AI:	// aka SPDU_AB
			case SPDU_AB:
				logger().exception("flush partially assembled (T))SSDU");
				sb_qbuf.erase();
				sb_len = 0;
				break;

			case SPDU_GT:
				if (spdu.hasMask(SMASK_SPDU_GT))
					break; // else SPDU_DT //
			default:
				if (sb_code == spdu.si())
					break;
				spdu.spktlose(AbortCode::SC_PROTOCOL, nullptr, "session protocol mangled: expecting " + sb_code
							  + ", got " + spdu.getLiteral() + "during segmentation");
				return nullptr;
			}
		}

		// allows AB SPDUs to have 512, not 9, octets
		if (spdu.getDataLen() > CN_SIZE && version < SB_VRSN2) {
			spdu.spktlose(AbortCode::SC_PROTOCOL, nullptr, "too much user data (%d) in SPDU 0x%x", spdu.getDataLen(), spdu
						  .si());
			return nullptr;
		}

		if (spdu.hasMask(SMASK_ENCLOSE) && ((spdu.si() != SPDU_DT) || spdu.hasMask(SMASK_SPDU_GT))
				&& (spdu.si() != SPDU_TD)) {
			if (version < SB_VRSN2) {
				spdu.spktlose(AbortCode::SC_PROTOCOL, nullptr, "unexpected segmentation for SPDU: " + spdu.toString());
				return nullptr;
			}

//#ifdef notdef
// 	XXX: in practice, I don't think this is unreasonable.  It is
//	however not too restrictive
// 	AWY: I do think this is too restrictive and there seems to be code
//	to handle it. Some implementations segment as a matter of
//	course if permitted to do so, and work more efficiently
//	under such circumstances.

//		    	if (s.s_enclose != ENCL_MASK) {
//					s.spktlose ( AbortCode::SC_PROTOCOL, nullptr,
//				 	"non-trivial segmentation (0x%x) for SPDU 0x%x", s.s_enclose, spdu.code());
//		    		return nullptr;
//		    	}
//#endif
		}
#endif

		//
		// Check for protocol violations:
		//  (1) the PDU is valid given the negotiated
		//	    functional units (requirements);
		//	(2) the PDU is available given current token
		//	    settings;
		//	(3) the PDU is valid in the current state;
		//	(4) requested token settings are valid given
		//	    the current token availability & ownership;
		//	(5) sync-point serial numbers are correct.
		//  So far, only (1) is implemented.
		//

		switch (spdu->si()) {
		// case SPDU_GT: done later //
		case SPDU::SPDU::SPDU_GTC:
		case SPDU::SPDU::SPDU_GTA:
		case SPDU::SPDU::SPDU_PT:
			if (!sb_requirements.has(SUBSET_TOKENS)) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_TD:
			if (!sb_requirements[TYPEDATA]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_EX:
			if (!sb_requirements[EXPEDITED]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_CD:
		case SPDU::SPDU::SPDU_CDA:
			if (!sb_requirements[CAPABILITY]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_MAP:
//		case SPDU::SPDU::SPDU_AE:	// aka SPDU_MAP
		case SPDU::SPDU::SPDU_MAA:
//		case SPDU::SPDU::SPDU_AEA:	// aka SPDU_MAA //
			if (!(sb_requirements[MAJORSYNC] || sb_requirements[ACTIVITY])) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_MIP:
		case SPDU::SPDU::SPDU_MIA:
			if (!sb_requirements[MINORSYNC]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_RS:
		case SPDU::SPDU::SPDU_RA:
			if (!sb_requirements[RESYNCHRONIZE]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_ER: // this implementation never generates these //
		case SPDU::SPDU::SPDU_ED:
			if (!sb_requirements[EXCEPTIONS]) {
				spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		case SPDU::SPDU::SPDU_AS:
		case SPDU::SPDU::SPDU_AR:
		case SPDU::SPDU::SPDU_AD:
		case SPDU::SPDU::SPDU_ADA:
// 				case SPDU_AIA: cannot do as same code as SPDU_AA //
			if (!sb_requirements[ACTIVITY]) {
				//FIXME invalid: spdu.spktlose(AbortCode::SC_PROTOCOL, nullptr, "invalid SPDU in this connection");
				return NOTOK;
			}
			break;
		}

		try {
			switch (spdu->si()) {
			case SPDU::SPDU::SPDU_AA: {
				FSM<Provider>::AA();
				break;
			}
			case SPDU::SPDU::SPDU_AB: {
				FSM<Provider>::AB();
				break;
			}
			case SPDU::SPDU::SPDU_AC: {	// ACCEPT
				SPDU::AC& spdu_ac = *(SPDU::AC*) spdu.get();
				result = AbortCode::SC_ACCEPT;
				if (spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_REF))
					sb_reference = spdu_ac.getReference();

				if (spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_OPT))
					sb_options = spdu_ac.getOptions();
				
				if (!spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_TSDU)) {
					spdu_ac.setTSDUInitiator((short) 0);
					spdu_ac.setTSDUResponder((short) 0);
				}
				if (spdu_ac.getTSDUInitiator() < sb_tsdu_us)
					sb_tsdu_us = spdu_ac.getTSDUInitiator();
				if (spdu_ac.getTSDUResponder() < sb_tsdu_them)
					sb_tsdu_them = spdu_ac.getTSDUResponder();

				if (BAD_TSDU_SIZE(sb_tsdu_us)) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, format("perposterous TSDU size (%d) for initiator", sb_tsdu_us));
					return rc;
				}
				if (BAD_TSDU_SIZE(sb_tsdu_them)) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, format("perposterous TSDU size (%d) for responder", sb_tsdu_them));
					return rc;
				}
				if (spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_VRSN)) {
					if (!spdu_ac.getVersion() & sb_vrsnmask) {
						/* not SC_VERSION */
						rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, format("version mismatch: expecting something in 0x%x, got 0x%x", sb_vrsnmask, spdu_ac.getVersion()));
						return rc;
					}
					sb_vrsnmask &= spdu_ac.getVersion();
				}
				sb_version = sb_vrsnmask & (1 << SB_VRSN2) ? SB_VRSN2 : SB_VRSN1;
				if (!spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_REQ)) {
					spdu_ac.setRequires(SUBSET_DEFAULT);
				}
// catch this in the next test
//			    switch ( hasRequirement((SR_HALFDUPLEX | SR_DUPLEX)) {
//				case SR_HALFDUPLEX:
//				    if (spdu_ac.s_cn_requirements & SR_HALFDUPLEX)
//					break;
//				    rc = s.spktlose ( AbortCode::SC_PROTOCOL, null, "half-duplex negotiation failed");
//				    goto out;
//
//				case SR_DUPLEX:
//				    if (spdu_ac.s_cn_requirements & SR_DUPLEX)
//					break;
//				    rc = s.spktlose ( AbortCode::SC_PROTOCOL, null, "full-duplex negotiation failed");
//				    goto out;
//
//				default:
//				    break;
//			    }
				
#ifdef FIXME
				if (spdu_ac.getRequires() & ~sb_requirements) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, "requirements negotiation failed");
					return rc;
				}
#endif
				sb_requirements &= spdu_ac.getRequires();
				if (sb_requirements[HALFDUPLEX] && sb_requirements[DUPLEX]) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, "half/full-duplex negotiation failed");
					return rc;
				}
				if (sb_requirements[EXCEPTIONS] && !sb_requirements[HALFDUPLEX]) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, "exception service requires half-duplex service");
					return rc;
				}
				if (sb_requirements[CAPABILITY] && !sb_requirements[ACTIVITY]) {
					rc = spktlose(AbortCode::SC_PROTOCOL, nullptr, "capability-data service requires activity-management service");
					return rc;
				}
				Bits please = 0;
				int settings = 0;

#ifdef ISODE
#define	dotoken(requires,shift,bit,type) \
{ \
   if (sb_requirements.has(requires)) { \
switch (sb_settings & (CHOICE_MASK << shift)) { \
    case CALLED_VALUE << shift: \
	if (!spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_SET)) \
	    spdu_ac.setSettings(INITIATOR_VALUE << shift); \
	switch (spdu_ac.getSettings() & (CHOICE_MASK << shift)) { \
	    case INITIATOR_VALUE << shift: \
	    default: \
		sb_owned.add(bit); \
		settings |= INITIATOR_VALUE << shift; \
		break; \
\
	    case RESPONDER_VALUE << shift: \
		settings |= RESPONDER_VALUE << shift; \
		break; \
	} \
	break; \
\
    case INITIATOR_VALUE << shift: \
	sb_owned.add(bit); \
	settings |= INITIATOR_VALUE << shift; \
	break; \
\
    case RESPONDER_VALUE << shift: \
	settings |= RESPONDER_VALUE << shift; \
	break; \
} \
\
if (spdu_ac.hasMask(SPDU::SPDU::SMASK_AC_TOKEN) && (spdu_ac.getToken() & bit)) \
    please.add(bit); \
   } \
}
				dotokens();
#undef dotoken
#else
				if (hasRequirement(RELEASE_UNIT_EXISTS)) {
					switch (settings() & (CHOICE_MASK << RELEASE_SHIFT)) {
					case CALLER_VALUE << RELEASE_SHIFT:
						if (!hasMask(SMASK_CN_SET))
							spdu_ac.setSettings(INITIATOR_VALUE << RELEASE_SHIFT);
						switch (spdu_ac.getSettings() & (CHOICE_MASK << RELEASE_SHIFT)) {
						case INITIATOR_VALUE << RELEASE_SHIFT:
						default:
							addOwned(RELEASE_TOKEN);
							settings |= INITIATOR_VALUE << RELEASE_SHIFT;
							break;

						case RESPONDER_VALUE << RELEASE_SHIFT:
							settings |= RESPONDER_VALUE << RELEASE_SHIFT;
							break;
						}
						break;

					case INITIATOR_VALUE << RELEASE_SHIFT:
						addOwned(RELEASE_TOKEN);
						settings |= INITIATOR_VALUE << RELEASE_SHIFT;
						break;

					case RESPONDER_VALUE << RELEASE_SHIFT:
						settings |= RESPONDER_VALUE << RELEASE_SHIFT;
						break;
					}

					if (hasMask(SMASK_AC_TOKEN) && spdu_ac.hasToken(RELEASE_TOKEN))
						please |= RELEASE_TOKEN;
				}

				if (hasRequirement(MAJOR_UNIT_EXISTS)) {
					switch (settings() & (CHOICE_MASK << MAJOR_SHIFT)) {
					case CALLER_VALUE << MAJOR_SHIFT:
						if (!hasMask(SMASK_CN_SET))
							spdu_ac.setSettings(INITIATOR_VALUE << MAJOR_SHIFT);
						switch (spdu_ac.getSettings() & (CHOICE_MASK << MAJOR_SHIFT)) {
						case INITIATOR_VALUE << MAJOR_SHIFT:
						default:
							addOwned(MAJOR_TOKEN);
							settings |= INITIATOR_VALUE << MAJOR_SHIFT;
							break;

						case RESPONDER_VALUE << MAJOR_SHIFT:
							settings |= RESPONDER_VALUE << MAJOR_SHIFT;
							break;
						}
						break;

					case INITIATOR_VALUE << MAJOR_SHIFT:
						addOwned(MAJOR_TOKEN);
						settings |= INITIATOR_VALUE << MAJOR_SHIFT;
						break;

					case RESPONDER_VALUE << MAJOR_SHIFT:
						settings |= RESPONDER_VALUE << MAJOR_SHIFT;
						break;
					}

					if (hasMask(SMASK_AC_TOKEN) && spdu_ac.hasToken(MAJOR_TOKEN))
						please |= MAJOR_TOKEN;
				}

				if (hasRequirement(MINOR_UNIT_EXISTS)) {
					switch (settings() & (CHOICE_MASK << MINOR_SHIFT)) {
					case CALLER_VALUE << MINOR_SHIFT:
						if (!hasMask(SMASK_CN_SET))
							spdu_ac.setSettings(INITIATOR_VALUE << MINOR_SHIFT);
						switch (spdu_ac.getSettings() & (CHOICE_MASK << MINOR_SHIFT)) {
						case INITIATOR_VALUE << MINOR_SHIFT:
						default:
							addOwned(MINOR_TOKEN);
							settings |= INITIATOR_VALUE << MINOR_SHIFT;
							break;

						case RESPONDER_VALUE << MINOR_SHIFT:
							settings |= RESPONDER_VALUE << MINOR_SHIFT;
							break;
						}
						break;

					case INITIATOR_VALUE << MINOR_SHIFT:
						addOwned(MINOR_TOKEN);
						settings |= INITIATOR_VALUE << MINOR_SHIFT;
						break;

					case RESPONDER_VALUE << MINOR_SHIFT:
						settings |= RESPONDER_VALUE << MINOR_SHIFT;
						break;
					}

					if (hasMask(SMASK_AC_TOKEN) && spdu_ac.hasToken(MINOR_TOKEN))
						please |= MINOR_TOKEN;
				}

				if (hasRequirement(DATA_UNIT_EXISTS)) {
					switch (settings() & (CHOICE_MASK << DATA_SHIFT)) {
					case CALLER_VALUE << DATA_SHIFT:
						if (!hasMask(SMASK_CN_SET))
							spdu_ac.setSettings(INITIATOR_VALUE << DATA_SHIFT);
						switch (spdu_ac.getSettings() & (CHOICE_MASK << DATA_SHIFT)) {
						case INITIATOR_VALUE << DATA_SHIFT:
						default:
							addOwned(DATA_TOKEN);
							settings |= INITIATOR_VALUE << DATA_SHIFT;
							break;

						case RESPONDER_VALUE << DATA_SHIFT:
							settings |= RESPONDER_VALUE << DATA_SHIFT;
							break;
						}
						break;

					case INITIATOR_VALUE << DATA_SHIFT:
						addOwned(DATA_TOKEN);
						settings |= INITIATOR_VALUE << DATA_SHIFT;
						break;

					case RESPONDER_VALUE << DATA_SHIFT:
						settings |= RESPONDER_VALUE << DATA_SHIFT;
						break;
					}

					if (hasMask(SMASK_AC_TOKEN) && spdu_ac.hasToken(DATA_TOKEN))
						please |= DATA_TOKEN;
				}
#endif
#ifdef FIXME
				if (spdu_ac.hasMask(SPDU::SPDU::SMASK_CN_CALLED)) {
					if ((len = spdu_ac.getCalledlen()) > sb_responding.sa_selector.sizeof())
						len = sb_responding.sa_selector.sizeof();
					spdu_ac.setCalled(sb_responding.bytes(), len);
				}


							respondingSSAPAddr = sb_responding;
							if ((ssdusize = sb_tsdu_us - SSDU_MAGIC) < 0)
								ssdusize = tsdusize - SSDU_MAGIC;

							sc_qos = qos;
							sc_qos.sversion(version + 1);
							sc_qos.extended(hasState(SB_EXPD) ? true : false);
							sc_data = popData();

							addState(SB_CONN | SB_INIT);
#endif
					sb_settings = settings;
					FSM<Provider>::AC(spdu_ac);
				break;
			}
			case SPDU::SPDU::SPDU_AD: {
				FSM<Provider>::AD();
				break;
			}
			case SPDU::SPDU::SPDU_ADA: {
				FSM<Provider>::ADA();
				break;
			}
//			case SPDU::SPDU::SPDU_AE:	// aka SPDU_MAP
			case SPDU::SPDU::SPDU_MAP: {
				SPDU::MAP& spdu_map = *(SPDU::MAP*) spdu.get();
#if 0
				if (V(M) != spdu_map.getSerial()) {
					if (sb_spdu != nullptr)
						;//FIXME continue;
				}
#endif
				if (!spdu_map.hasMask(SPDU::SPDU::SMASK_MAP_SYNC) ||
					!(spdu_map.getSync() & SPDU::SPDU::MAP_SYNC_NOEND)) {
#if 0
					if (!hasState(SB_Vsc))
						V_A(V_M());
					addV_M(1);
					remState(SB_Vnextact);
					addState(SB_MAA | SB_AE);
					sv = new SSAPActivityEndIndication(spkt);
					sv.sv_ssn = new SSN(spdu_map.getSerial());
					return sv;
#else
					FSM<Provider>::AE(spdu_map.ssn());

#endif
				} else {
#if 0
					if (!hasState(SB_Vsc))
						V_A(V_M());
					addV_M(1);
					if (hasState((SB_ED | SB_ERACK))) {
						spkt = null;
						if (bool(sb_spdu))
							continue;
					}
					if (hasRequirement(ACTIVITY))
						addState(SB_Vnextact);
					addState(SB_MAA);
					sn = new SSAPSyncMajorIndication(spkt, new SSN(spdu_map.getSerial()));
					return sn;
#else
					FSM<Provider>::MAP(spdu_map);
#endif
				}

				break;
			}
			case SPDU::SPDU::SPDU_AEA: { //SPDU_MAA
				SPDU::MAA& spdu_maa = *(SPDU::MAA*) spdu.get();
				//TODO split AEA and PAA processing
				FSM<Provider>::MAA(spdu_maa.getSerial());
				break;
			}
//			case SPDU::SPDU::SPDU_AI: { AI(); break; }
//			case SPDU::SPDU::SPDU_AIA: { AIA(); break; }
			case SPDU::SPDU::SPDU_AR: {
				//TODO split SPDU_AI and SPDU_AIA processing from AR processing
				SPDU::AR& spdu_ar = *(SPDU::AR*) spdu.get();
				FSM<Provider>::AR();
				break;
			}
			case SPDU::SPDU::SPDU_AS: {
				SPDU::AS& spdu_as = *(SPDU::AS*) spdu.get();
				FSM<Provider>::AS(spdu_as.getId());
				break;
			}
			case SPDU::SPDU::SPDU_CD: {
				FSM<Provider>::CD();
				break;
			}
			case SPDU::SPDU::SPDU_CDA: {
				FSM<Provider>::CDA();
				break;
			}
			case SPDU::SPDU::SPDU_CDO: {
				FSM<Provider>::CDO();
				break;
			}
			case SPDU::SPDU::SPDU_CN: {
				SPDU::CN& spdu_cn = *(SPDU::CN*)spdu.get();
				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_VRSN) && !(spdu_cn.getVersion() & SB_ALLVRSNS)) {
					//					spktlose(SC_VERSION | SC_REFUSE, nullptr,	"version mismatch: expecting something in 0x%x, got 0x%x", SB_ALLVRSNS, spdu_cn.getVersion());
					return NOTOK;
				}
				if (sb_tx.get() != nullptr)
					sb_tx->clear();
#if 0
				if (spdu.error() != SC_ACCEPT) {
					spdu.spktlose((bool(spdu) ? spdu.error() : SC_CONGEST) | SC_REFUSE, nullptr, nullptr, nullptr);
					return NOTOK;
				}
				if (spdu.spdu().si() != SPDU::SPDU::SPDU_CN) {
					//					spdu.spktlose(AbortCode::SC_PROTOCOL | SC_REFUSE, nullptr, "session protocol mangled: expected 0x%x, got 0x%x",	SPDU_CN, spdu.spdu().si());
					return NOTOK;
				}
#endif

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_VRSN) && !(spdu_cn.getVersion() & SB_ALLVRSNS)) {
//					spdu.spktlose(SC_VERSION | SC_REFUSE, nullptr,	"version mismatch: expecting something in 0x%x, got 0x%x", SB_ALLVRSNS, spdu_cn.getVersion());
					return NOTOK;
				}


				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_REQ)) {
					if (spdu_cn.requires(EXCEPTIONS) && !spdu_cn.requires(HALFDUPLEX)) {
						//spktlose(AbortCode::SC_PROTOCOL, nullptr, "proposed session requirements error: got 0x%x", spdu_cn.getRequires());
						return NOTOK;
					}
					if (!spdu_cn.requires(HALFDUPLEX) && !spdu_cn.requires(DUPLEX)) {
						//spktlose(AbortCode::SC_PROTOCOL, nullptr, "proposed session requirements error: got 0x%x", spdu_cn.getRequires());
						return NOTOK;
					}
					if (spdu_cn.requires(CAPABILITY) && !spdu_cn.requires(ACTIVITY)) {
						//spktlose(AbortCode::SC_PROTOCOL, nullptr, "proposed session requirements error: got 0x%x", spdu_cn.getRequires());
						return NOTOK;
					}


					if ((spdu_cn.requires(MINORSYNC) ||
							spdu_cn.requires(MAJORSYNC) ||
							spdu_cn.requires(RESYNCHRONIZE)) ? (!spdu_cn.requires(ACTIVITY)
									&& !spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_ISN)) : spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_ISN)) {
						//	spktlose(AbortCode::SC_PROTOCOL, nullptr, "proposed session ISN error: %s, got FUs 0x%x", hasMask(SPDU_CONNECT.SPDU::SPDU::SMASK_CN_ISN) ? "present" : "absent", spdu_cn.getRequires());
						return NOTOK;
					}
				}

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_VRSN)) {
					sb_version = (spdu_cn.getVersion() & (1 << SB_VRSN2)) ? SB_VRSN2 : SB_VRSN1;
				} else {
					sb_version = spdu_cn.getDataLen() > SS_SIZE ? SB_VRSN2 : SB_VRSN1;
				}

				if (sb_expedited)
					sb_state.add(SB_EXPD);

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_REF))
					sb_reference = spdu_cn.getReference();

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_OPT))
					sb_options = spdu_cn.getOptions();

				int isn;
				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_ISN)) {
					isn = spdu_cn.getIsn();
					V(A) = isn;
					V(M) = isn;
				} else
					isn = SERIAL_NONE;

				if (!spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_TSDU)) {
					spdu_cn.setTSDUInitiator((short)0);
					spdu_cn.setTSDUResponder((short)0);
				}

				if (spdu_cn.getTSDUInitiator() < (sb_tsdu_them = GET_TSDU_SIZE(sb_tsdusize)))
					sb_tsdu_them = spdu_cn.getTSDUInitiator();

				if (spdu_cn.getTSDUResponder() < (sb_tsdu_us = GET_TSDU_SIZE(sb_tsdusize)))
					sb_tsdu_us = spdu_cn.getTSDUResponder();

				if (sb_version >= SB_VRSN2) /* XXX */
					sb_tsdu_them = sb_tsdu_us = 0;

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_SET))
					sb_settings = spdu_cn.getSettings();

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_REQ)) {
					sb_requirements = spdu_cn.getRequires() & SUBSET_MYREQUIRE;
				} else {
					sb_requirements = SUBSET_DEFAULT & SUBSET_MYREQUIRE;
				}

				if (!sb_expedited)
					sb_requirements[EXPEDITED] = false;

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_CALLING)) {
					sb_initiating.sa_selectlen = spdu_cn.getCallinglen();
					sb_initiating.sa_selector = Selector(spdu_cn.getCallinglen(), spdu_cn.getCalling());
				}

				if (spdu_cn.hasMask(SPDU::SPDU::SMASK_CN_CALLED)) {
					sb_responding.sa_selectlen = spdu_cn.getCalledlen();
					sb_responding.sa_selector = Selector(spdu_cn.getCalledlen(), spdu_cn.getCalled());
				}

				if ((sb_ssdusize = sb_tsdu_us - SPDU::SPDU::SSDU_MAGIC) < 0)
					sb_ssdusize = sb_tsdusize - SPDU::SPDU::SSDU_MAGIC;

				sb_qos.version() = sb_version + 1;
				sb_qos.extended() = sb_state.has(SB_EXPD) ? true : false;
				int cc;
				const void* bytes = spdu_cn.popData(cc);


				rc = NOTOK;
				if (sb_services == nullptr) {
					spktlose(Disconnect::DR_CONNECT, nullptr, "SSAP services not set");
					return NOTOK;
				}
				const SSAPService* service = nullptr;
				service = (const SSAPService*)sb_services->getServiceBySelector(sb_responding.selector());
				if (service == nullptr) {
					return spktlose(Disconnect::DR_CONNECT, nullptr, "unknown SSAP service with selector %s", sb_responding.selector().to_string());
				}

				std::string path(service->library());
				path.append(SharedLibrary::suffix());
				sb_UserResponserLoader.loadLibrary(path, "ALS_SSAP_USER_Responder");
				ssap_user_responder = sb_UserResponserLoader.create("ALS::SSAP::USER::Responder");
				if (ssap_user_responder == nullptr) {
					spktlose(Disconnect::DR_CONNECT, nullptr, "server is missing ALS::SSAP::USER::Responder as base class");
					return NOTOK;
				}

				USER::Linker* linker = dynamic_cast<USER::Linker*>(ssap_user_responder);
				if (linker == nullptr) {
					return NOTOK;
				}
				linker->provider() = this;

				ssap_user_abortIndication			= static_cast<USER::AbortIndication*>(ssap_user_responder);
				ssap_user_activityIndication		= static_cast<USER::ActivityIndication*>(ssap_user_responder);
				ssap_user_activityConfirmation		= static_cast<USER::ActivityConfirmation*>(ssap_user_responder);
				ssap_user_dataIndication			= static_cast<USER::DataIndication*>(ssap_user_responder);
				ssap_user_dataConfirmation			= static_cast<USER::DataConfirmation*>(ssap_user_responder);
				ssap_user_releaseConfirmation		= static_cast<USER::ReleaseConfirmation*>(ssap_user_responder);
				ssap_user_releaseIndication			= static_cast<USER::ReleaseIndication*>(ssap_user_responder);
				ssap_user_reportIndication			= static_cast<USER::ReportIndication*>(ssap_user_responder);
				ssap_user_synchronizeConfirmation	= static_cast<USER::SynchronizeConfirmation*>(ssap_user_responder);
				ssap_user_synchronizeIndication		= static_cast<USER::SynchronizeIndication*>(ssap_user_responder);
				FSM<Provider>::CN();
				break;
			}
			case SPDU::SPDU::SPDU_DN: {
				FSM<Provider>::DN();
				break;
			}
//			case SPDU::SPDU::SPDU_DT: {
//				DT(); break;
//			}
			case SPDU::SPDU::SPDU_ED: {
				FSM<Provider>::ED();
				break;
			}
			case SPDU::SPDU::SPDU_ER: {
				FSM<Provider>::ER();
				break;
			}
			case SPDU::SPDU::SPDU_EX: {
				FSM<Provider>::EX();
				break;
			}
			case SPDU::SPDU::SPDU_FN: {
				SPDU::FN& spdu_fn = *(SPDU::FN*) spdu.get();
				FSM<Provider>::FN(spdu_fn.getDisconnect() & SPDU::SPDU::FN_DISC_RELEASE);
				break;
			}
			case SPDU::SPDU::SPDU_GT: {
				byte tokens;
				if (spdu->category() == Category::CAT0) { //SPDU_GT
					SPDU::GT& spdu_gt = *(SPDU::GT*) spdu.get();
					if (sb_state.has(SB_GTC)) {
						if (sb_spdu != nullptr)
							;// FIXME continue;
					}
					tokens = 0;
					if (spdu_gt.hasMask(SPDU::SPDU::SMASK_GT_TOKEN)) {
						if (sb_requirements.has(RELEASE_UNIT_EXISTS) && (spdu_gt.getToken() & RELEASE_TOKEN)) {
// done in SA11(tokens)		sb_owned.add(RELEASE_TOKEN);
							tokens |= RELEASE_TOKEN;
						}
						if (sb_requirements.has(MAJOR_UNIT_EXISTS) && (spdu_gt.getToken() & MAJOR_TOKEN)) {
// done in SA11(tokens)		sb_owned.add(MAJOR_TOKEN);
							tokens |= MAJOR_TOKEN;
						}
						if (sb_requirements.has(MINOR_UNIT_EXISTS) && (spdu_gt.getToken() & MINOR_TOKEN)) {
// done in SA11(tokens)		sb_owned.add(MINOR_TOKEN);
							tokens |= MINOR_TOKEN;
						}
						if (sb_requirements.has(DATA_UNIT_EXISTS) && (spdu_gt.getToken() & DATA_TOKEN)) {
// done in SA11(tokens)			sb_owned.add(DATA_TOKEN);
							tokens |= DATA_TOKEN;
						}
					}
					if (tokens && !sb_requirements.has(SUBSET_TOKENS)) {
						;
						spktlose( AbortCode::SC_PROTOCOL, nullptr, "GT SPDU not available");
						break;
					}
					if (tokens & DATA_TOKEN)
						sb_state.rem(SB_ED | SB_ERACK);
					//				st = new SSAPTokenGive(spkt);
					//				st.tokens(tokens);
					//				st.owned((byte) owned());
					//				spkt = nullptr;
					//				return st;
					FSM<Provider>::GT(tokens);
				} else {// else fall for case SPDU_DT:
					//		case SPDU_DT:
					FSM<Provider>::DT();
				}
				break;
			}
			case SPDU::SPDU::SPDU_GTA: {
				FSM<Provider>::GTA();
				break;
			}
			case SPDU::SPDU::SPDU_GTC: {
				FSM<Provider>::GTC(sb_avail);
				break;
			}
//			case SPDU::SPDU::SPDU_MAA: { MAA(); break; }
//			case SPDU::SPDU::SPDU_MAP: { MAP(); break; }
			case SPDU::SPDU::SPDU_MIA: {
				SPDU::MIA& spdu_mia = *(SPDU::MIA*) spdu.get();
				updateAMR06(Event::MIA, spdu_mia.getSerial());
				FSM<Provider>::MIA(spdu_mia.ssn());
				break;
			}
			case SPDU::SPDU::SPDU_MIP: {
				SPDU::MIP& spdu_mip = *(SPDU::MIP*) spdu.get();
				updateAMR03(Event::AE, spdu_mip.getSerial());
				FSM<Provider>::MIP(false, spdu_mip);
				break;
			}
			case SPDU::SPDU::SPDU_NF: {
				FSM<Provider>::NF();
				break;
			}
			case SPDU::SPDU::SPDU_OA: {
				FSM<Provider>::OA();
				break;
			}
			case SPDU::SPDU::SPDU_PR: {
				break;
			}
			case SPDU::SPDU::SPDU_PT: {
				SPDU::PT& spdu_pt = *(SPDU::PT*) spdu.get();
				if (sb_state.has(SB_GTC)) {
					spdu = nullptr;
					//if (sb_spdu != nullptr)
					//	;//FIXME continue;
				}
				int tokens = 0;
				if (spdu_pt.hasMask(SPDU::SPDU::SMASK_PT_TOKEN)) {
					if (sb_requirements.has(RELEASE_UNIT_EXISTS) && (spdu_pt.getToken() & RELEASE_TOKEN)) {
						tokens |= RELEASE_TOKEN;
					}
					if (sb_requirements.has(MAJOR_UNIT_EXISTS) && (spdu_pt.getToken() & MAJOR_TOKEN)) {
						tokens |= MAJOR_TOKEN;
					}
					if (sb_requirements.has(MINOR_UNIT_EXISTS) && (spdu_pt.getToken() & MINOR_TOKEN)) {
						tokens |= MINOR_TOKEN;
					}
					if (sb_requirements.has(DATA_UNIT_EXISTS) && (spdu_pt.getToken() & DATA_TOKEN)) {
						tokens |= DATA_TOKEN;
					}
				}
				FSM<Provider>::PT(tokens);
				break;
			}
			case SPDU::SPDU::SPDU_RA: {
				SPDU::RA& spdu_ra = *(SPDU::RA*) spdu.get();
				FSM<Provider>::RA(spdu_ra.ssn(), spdu_ra.settings());
				break;
			}
			case SPDU::SPDU::SPDU_RF: {
				FSM<Provider>::RF(false);
				break;
			}
			case SPDU::SPDU::SPDU_RS: {
				SPDU::RS& spdu_rs = *(SPDU::RS*) spdu.get();
				FSM<Provider>::RS(spdu_rs.type());
				break;
			}
			case SPDU::SPDU::SPDU_TD: {
				FSM<Provider>::TD();
				break;
			}
			default:
				poco_assert(false);
				break;
			}
		} catch (const SmcException& e) {
			providerException(e);
		}

	} catch (ALS::TSAP::PROV::Exception& e) {
//		rc = sa.ssaplose(SC_CONGEST, nullptr, MSG_OUT_OF_MEMORY);
		rc = NOTOK;
	}
	return rc;
}
ReturnCode Provider::TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices) {
	sb_services = ssapServices;
	return OK;
}
ReturnCode Provider::SConnectRequest(const Reference& reference, const SSAPAddr& calling, const SSAPAddr& called, const QualityOfService& qualityOfService, const Requirement&  requirements, const SSN& firstInitialSSN, const SSN& secondInitialSSN, byte settings, int cc, const void* data) {
	ReturnCode rc = OK;
	sb_logger->SConnectRequest(reference, calling, called, qualityOfService, requirements, firstInitialSSN, secondInitialSSN, settings, cc, data);

	if (!reference.valid()) {
		return NOTOK; //FIXME Abortindication
	}
	if (reference.vlength() != 0) {
		return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_BAD_FORMAT_FOR_REFERENCE);
	}
	if (!called.valid()) {
		return NOTOK; //FIXME Abortindication
	}
	if (requirements.has(~SUBSET_MYREQUIRE)) {
		return  NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "requirements settings not supported");
	}
	if (requirements[EXCEPTIONS] && !requirements[HALFDUPLEX]) {
		return  NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "exception service requires half-duplex service");
	}
	if (requirements.has(RELEASE_UNIT_EXISTS))
		switch (settings & (CHOICE_MASK << RELEASE_SHIFT)) {
		case INITIATOR_VALUE << RELEASE_SHIFT:
		case RESPONDER_VALUE << RELEASE_SHIFT:
		case CALLED_VALUE << RELEASE_SHIFT:
			break;

		default:
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_RELEASE);
		}
	if (requirements.has(MAJOR_UNIT_EXISTS))
		switch (settings & (CHOICE_MASK << MAJOR_SHIFT)) {
		case INITIATOR_VALUE << MAJOR_SHIFT:
		case RESPONDER_VALUE << MAJOR_SHIFT:
		case CALLED_VALUE << MAJOR_SHIFT:
			break;

		default:
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_MAJORSYNC);
		}
	if (requirements.has(MINOR_UNIT_EXISTS))
		switch (settings & (CHOICE_MASK << MINOR_SHIFT)) {
		case INITIATOR_VALUE << MINOR_SHIFT:
		case RESPONDER_VALUE << MINOR_SHIFT:
		case CALLED_VALUE << MINOR_SHIFT:
			break;

		default:
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_MINORSYNC);
		}
	if (requirements.has(DATA_UNIT_EXISTS))
		switch (settings & (CHOICE_MASK << DATA_SHIFT)) {
		case INITIATOR_VALUE << DATA_SHIFT:
		case RESPONDER_VALUE << DATA_SHIFT:
		case CALLED_VALUE << DATA_SHIFT:
			break;

		default:
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, data);
		}

	if (requirements[MINORSYNC] || requirements[MAJORSYNC] || requirements[RESYNCHRONIZE]) {
		if (!requirements[ACTIVITY] || firstInitialSSN.ssn() != SERIAL_NONE)
			if (!firstInitialSSN.isValid()) {
				return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "bad choice for initial serial number");
			}
	} else if (firstInitialSSN.ssn() != SERIAL_NONE) {
		return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "initial serial number invalid given requirements");
	}

	if (data != nullptr && cc > MAX_CONNECT_DATA_SIZE) {
		return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "too much initial user data " + data.length + " octets");
	}

	//rc = SConnectRequestAux(reference, calling, called, requirements, settings, firstInitialSSN, data, qualityOfService,	sa);
	if (qualityOfService.maxtime() <= 0)
		sb_maxtime = INFINITE;
	else
		sb_maxtime = qualityOfService.maxtime();

	sb_initiating = calling;
	sb_responding = called;
	sb_requirements = requirements;
	sb_settings = settings;
	sb_reference = reference;
	sb_calling = sb_initiating.tsapaddr();
	sb_called = sb_responding.tsapaddr();

	if (qualityOfService.version() < 0) {
		sb_version = SB_VRSN1;
		sb_vrsnmask = SB_ALLVRSNS;
	} else {
		if (cc > SS_SIZE || (qualityOfService.version() > 1))
			sb_version = SB_VRSN2;
		else
			sb_version = SB_VRSN1;
		sb_vrsnmask = 1 << sb_version;
	}
	try {
		SCONreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
#define	dotoken(requires,shift,bit,type) \
{ \
    if (sb_requirements.has(requires)) \
	switch (sb_settings & (CHOICE_MASK << shift)) { \
	    case CALLED_VALUE << shift: \
		switch (settings & (CHOICE_MASK << shift)) { \
		    case INITIATOR_VALUE << shift: \
			settings &= ~(CHOICE_MASK << shift); \
			settings |= INITIATOR_VALUE << shift; \
			break; \
 \
		    case RESPONDER_VALUE << shift: \
			settings &= ~(CHOICE_MASK << shift); \
			settings |= RESPONDER_VALUE << shift; \
			sb_owned.add(bit); \
			break; \
 \
		    default: \
			return NOTOK; /*ssaplose (SC_PARAMETER, nullptr, "improper choice of %s token setting", type);*/ \
		} \
		break; \
 \
	    case INITIATOR_VALUE << shift: \
		if ((settings & (CHOICE_MASK << shift)) == (RESERVED_VALUE << shift)) \
		    please.add(bit); \
		settings &= ~(CHOICE_MASK << shift); \
		settings |= INITIATOR_VALUE << shift; \
		break; \
 \
	    case RESPONDER_VALUE << shift: \
		settings &= ~(CHOICE_MASK << shift); \
		settings |= RESPONDER_VALUE << shift; \
		sb_owned.add(bit); \
		break; \
	} \
}
ReturnCode Provider::SConnectResponse(const Reference& reference, const SSAPAddr& responding, int result, const QualityOfService& qualityOfService, const Requirement&  requirements, int settings, SSN& firstInitialSSN, SSN& secondInitialSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	sb_logger->SConnectResponse(reference, responding, result, sb_qos, requirements, settings, firstInitialSSN, secondInitialSSN, cc, data);
	Bits please;
	switch (result) {
	case AbortCode::SC_ACCEPT:
		if (requirements.has(~SUBSET_MYREQUIRE))
			return NOTOK; // sa.ssaplose(SC_PARAMETER, nullptr, "requirements settings not supported");
		if (false) {// screwy session protocol... /
			if ((requirements & ~sb_requirements).any())
				return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "requirements settings not available");
		}

		if (requirements[HALFDUPLEX] && requirements[DUPLEX])
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "half-duplex and duplex services are incompatible");

		if (requirements[EXCEPTIONS] && !requirements[HALFDUPLEX])
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "exception service requires half-duplex service");

		sb_requirements &= requirements;
		sb_avail = 0;
		sb_owned.reset();
#ifdef ISODE
		dotokens();
#else
		if (sb_requirements.has(RELEASE_UNIT_EXISTS)) {
			sb_avail.add(RELEASE_TOKEN);
			switch (sb_settings & (CHOICE_MASK << RELEASE_SHIFT)) {
			case CALLED_VALUE << RELEASE_SHIFT:
				switch (selectReleaseToken(settings)) {
				case INITIATOR_VALUE << RELEASE_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << RELEASE_SHIFT);
					settings = addSetting(settings, INITIATOR_VALUE << RELEASE_SHIFT);
					break;

				case RESPONDER_VALUE << RELEASE_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << RELEASE_SHIFT);
					settings = addSetting(settings, RESPONDER_VALUE << RELEASE_SHIFT);
					sb_owned.add(RELEASE_TOKEN);
					break;

				default:
					return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_RELEASE);
				}
				break;

			case INITIATOR_VALUE << RELEASE_SHIFT:
				if ((settings & (CHOICE_MASK << RELEASE_SHIFT)) == (RESERVED_VALUE << RELEASE_SHIFT))
					please.add(RELEASE_TOKEN);
				settings = remSetting(settings, CHOICE_MASK << RELEASE_SHIFT);
				settings = addSetting(settings, INITIATOR_VALUE << RELEASE_SHIFT);
				break;

			case RESPONDER_VALUE << RELEASE_SHIFT:
				settings = remSetting(settings, CHOICE_MASK << RELEASE_SHIFT);
				settings = addSetting(settings, RESPONDER_VALUE << RELEASE_SHIFT);
				sb_owned.add(RELEASE_TOKEN);
				break;
			}
		}

		if (sb_requirements.has(MAJOR_UNIT_EXISTS)) {
			sb_avail.add(MAJOR_TOKEN);
			switch (sb_settings & (CHOICE_MASK << MAJOR_SHIFT)) {
			case CALLED_VALUE << MAJOR_SHIFT:
				switch (settings & (CHOICE_MASK << MAJOR_SHIFT)) {
				case INITIATOR_VALUE << MAJOR_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << MAJOR_SHIFT);
					settings = addSetting(settings, INITIATOR_VALUE << MAJOR_SHIFT);
					break;

				case RESPONDER_VALUE << MAJOR_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << MAJOR_SHIFT);
					settings = addSetting(settings, RESPONDER_VALUE << MAJOR_SHIFT);
					sb_owned.add(MAJOR_TOKEN);
					break;

				default:
					return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_MAJORSYNC);
				}
				break;

			case INITIATOR_VALUE << MAJOR_SHIFT:
				if ((settings & (CHOICE_MASK << MAJOR_SHIFT)) == (RESERVED_VALUE << MAJOR_SHIFT))
					please .add(MAJOR_TOKEN);
				settings = remSetting(settings, CHOICE_MASK << MAJOR_SHIFT);
				settings = addSetting(settings, INITIATOR_VALUE << MAJOR_SHIFT);
				break;

			case RESPONDER_VALUE << MAJOR_SHIFT:
				settings = remSetting(settings, CHOICE_MASK << MAJOR_SHIFT);
				settings = addSetting(settings, RESPONDER_VALUE << MAJOR_SHIFT);
				sb_owned.add(MAJOR_TOKEN);
				break;
			}
		}

		if (sb_requirements.has(MINOR_UNIT_EXISTS)) {
			sb_avail.add(MINOR_TOKEN);
			switch (sb_settings & (CHOICE_MASK << MINOR_SHIFT)) {
			case CALLED_VALUE << MINOR_SHIFT:
				switch (settings & (CHOICE_MASK << MINOR_SHIFT)) {
				case INITIATOR_VALUE << MINOR_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << MINOR_SHIFT);
					settings = addSetting(settings, INITIATOR_VALUE << MINOR_SHIFT);
					break;

				case RESPONDER_VALUE << MINOR_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << MINOR_SHIFT);
					settings = addSetting(settings, RESPONDER_VALUE << MINOR_SHIFT);
					sb_owned.add(MINOR_TOKEN);
					break;

				default:
					return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_MINORSYNC);
				}
				break;

			case INITIATOR_VALUE << MINOR_SHIFT:
				if ((settings & (CHOICE_MASK << MINOR_SHIFT)) == (RESERVED_VALUE << MINOR_SHIFT))
					please.add(MINOR_TOKEN);
				settings = remSetting(settings, CHOICE_MASK << MINOR_SHIFT);
				settings = addSetting(settings, INITIATOR_VALUE << MINOR_SHIFT);
				break;

			case RESPONDER_VALUE << MINOR_SHIFT:
				settings = remSetting(settings, CHOICE_MASK << MINOR_SHIFT);
				settings = addSetting(settings, RESPONDER_VALUE << MINOR_SHIFT);
				sb_owned.add(MINOR_TOKEN);
				break;
			}
		}

		if (sb_requirements.has(DATA_UNIT_EXISTS)) {
			sb_avail.add(DATA_TOKEN);
			switch (sb_settings & (CHOICE_MASK << DATA_SHIFT)) {
			case CALLED_VALUE << DATA_SHIFT:
				switch (settings & (CHOICE_MASK << DATA_SHIFT)) {
				case INITIATOR_VALUE << DATA_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << DATA_SHIFT);
					settings = addSetting(settings, INITIATOR_VALUE << DATA_SHIFT);
					break;

				case RESPONDER_VALUE << DATA_SHIFT:
					settings = remSetting(settings, CHOICE_MASK << DATA_SHIFT);
					settings = addSetting(settings, RESPONDER_VALUE << DATA_SHIFT);
					sb_owned.add(DATA_TOKEN);
					break;

				default:
					return NOTOK;//FIXME  sa.ssaplose(SC_PARAMETER, nullptr, MSG_IMPROPER_CHOICE_OF_TOKEN_SETTING, MSG_DATA);
				}
				break;

			case INITIATOR_VALUE << DATA_SHIFT:
				if ((settings & (CHOICE_MASK << DATA_SHIFT)) == (RESERVED_VALUE << DATA_SHIFT))
					please.add(DATA_TOKEN);
				settings = remSetting(settings, CHOICE_MASK << DATA_SHIFT);
				settings = addSetting(settings, INITIATOR_VALUE << DATA_SHIFT);
				break;

			case RESPONDER_VALUE << DATA_SHIFT:
				settings = remSetting(settings, CHOICE_MASK << DATA_SHIFT);
				settings = addSetting(settings, RESPONDER_VALUE << DATA_SHIFT);
				sb_owned.add(DATA_TOKEN);
				break;
			}
		}
#endif
		if (sb_requirements[MINORSYNC] || sb_requirements[MAJORSYNC] || sb_requirements[RESYNCHRONIZE]) {
			if (!sb_requirements[ACTIVITY] || firstInitialSSN.ssn() != SERIAL_NONE) {
				if (!firstInitialSSN.isValid())
					return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "bad choice for initial serial number");
			}
		} else if (firstInitialSSN.ssn() != SERIAL_NONE)
			return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "initial serial number invalid given requirements");
		break;

	case AbortCode::SC_NOTSPECIFIED:
	case AbortCode::SC_CONGESTION:
	case AbortCode::SC_REJECTED:
		break;

	default:
		return NOTOK;//FIXME sa.ssaplose(SC_PARAMETER, nullptr, "invalid rc");
	}
	//FIXME cc = data == nullptr ? 0 : data.length;

	if (cc > ((sb_version < SB_VRSN2) ? AC::AC_SIZE : SPDU::SPDU::ENCLOSE_MAX))
		return NOTOK;//FIXME  sa.ssaplose(SC_PARAMETER, nullptr, "too much initial user data" + cc + " octets");

#if FIXME
	if (result != SC_ACCEPT) {
		SPDU::RF rf = new SPDU_RF();
//		spkt = new SPKT(this, rf);

		rf.setReference(reference);
		if (result == SC_REJECTED) {
			rf.setRequire(requirements);
		}
		//rf.rf_rdata = ByteBuffer.allocate(rf.rf_rlen = cc + 1);
		byte* rfdata = new byte[cc + 1];
		rfdata[0] = (byte)(result & 0xff);
		if (cc > 0) {
			System.arraycopy(data, 0, rfdata, 1, cc);//rf.rf_rdata.put(data);
		}
		rf.setData(rfdata);
		rc = refuse(spkt);

		return (rc != NOTOK && result != SC_ACCEPT ? OK : NOTOK);
	}
#endif
	SPDU::AC ac;

	ac.setReference(reference);
	ac.setOptions(SPDU::SPDU::CR_OPT_NULL);
	ac.setVersion((1 << sb_version));

	if (firstInitialSSN.ssn() != SERIAL_NONE) {
		ac.setIsn((int)firstInitialSSN.ssn());
	}

	if (sb_tsdu_us != 0 || sb_tsdu_them != 0) {
		ac.setTSDUResponder(GET_TSDU_SIZE(sb_tsdu_us));
		ac.setTSDUInitiator(GET_TSDU_SIZE(sb_tsdu_them));
	}

	ac.setRequires(sb_requirements);
	if (sb_requirements.has(SUBSET_TOKENS)) {
		ac.setSettings(settings);
	}
	if (please != 0) {
		ac.setToken(please);
	}
	ac.setCalling(sb_responding.selector().length(), sb_responding.selector().literal());

	ac.setData(cc, data);
	try {
		SCONrsp(true, ac);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	ac.setData(0, nullptr);
	return rc;
}
ReturnCode Provider::SUAbortRequest(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SUAbortRequest(cc, data);
		SUABreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityDiscardRequest(int reason, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityDiscardRequest(reason, cc, data);
		SACTDreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityDiscardResponse(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityDiscardResponse(cc, data);
		SACTDrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityEndRequest(SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		firstSSN = V(M);
		sb_logger->SActivityEndRequest(firstSSN, cc, data);
		SACTEreq(V(M));
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityEndResponse(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityEndResponse(cc, data);
		SACTErsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityEndResponse(const SSN& secondSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityEndResponse(secondSSN, cc, data);
		SACTErsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityInterruptRequest(int reason, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityInterruptRequest(reason, cc, data);
		SACTIreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityInterruptResponse(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityInterruptResponse(cc, data);
		SACTIrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityResumeRequest(const ActivityId& activityId, const ActivityId& oldActivityId, const SSN& firstSSN, const SSN&  secondSSN, const Reference& reference, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityResumeRequest(activityId, oldActivityId, firstSSN, secondSSN, reference,cc, data);
		SACTRreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SActivityStartRequest(const ActivityId& activityId, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SActivityStartRequest(activityId, cc, data);
		SACTSreq(activityId, cc, data);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SDataRequest(int cc, const void* data) {
	ReturnCode rc = OK;
	poco_assert(sb_cc == 0 && sb_data == nullptr);
	sb_cc = cc;
	sb_data = data;
	try {
		sb_logger->SDataRequest(cc, data);
		SDTreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	sb_cc = 0;
	sb_data = nullptr;
	return rc;
}
ReturnCode Provider::SDataRequest(const SharedNetworkBuffer& data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SDataRequest(data);
		SDTreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SCapabilityDataRequest(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SCapabilityDataRequest(cc, data);
		SCDreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SCapabilityDataResponse(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SCapabilityDataResponse(cc, data);
		SCDrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SExpeditedDataRequest(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SExpeditedDataRequest(cc, data);
		SEXreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::STypedDataRequest(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->STypedDataRequest(cc, data);
		STDreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SSendRequest(bool begin, bool end, int cc, const void* data) {
	ReturnCode rc = OK;
	sb_logger->SSendRequest(begin, end, cc, data);
	poco_assert(false);
	return rc;
}
ReturnCode Provider::SWriteRequest(bool typed, int cc, const void* data) {
	ReturnCode rc = OK;
	poco_assert(false);
	return rc;
}
ReturnCode Provider::SUExceptionReportRequest(int reason, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SUExceptionReportRequest(reason, cc, data);
		SUERreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SResynchronizeRequest(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SResynchronizeRequest(firstResync, firstSSN, secondResync, secondSSN, settings, cc, data);
		SRSYNreq(firstResync, firstSSN);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SResynchronizeResponse(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SResynchronizeResponse(firstResync, firstSSN, secondResync, secondSSN, settings, cc, data);
		SRSYNrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}

ReturnCode Provider::SSyncMajorRequest(SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		firstSSN = V(M);
		sb_logger->SSyncMajorRequest(firstSSN, cc, data);
		SSYNMreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SSyncMajorResponse(int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SSyncMajorResponse(cc, data);
		SSYNMrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SSyncMajorResponse(const SSN& secondSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SSyncMajorResponse(secondSSN, cc, data);
		SSYNMrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SSyncMinorRequest(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SSyncMinorRequest(type, dataSeparation, firstSSN, cc, data);
		updateAMR01(Event::SSYNmreq);
		SSYNmreq(dataSeparation);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SSyncMinorResponse(const SSN& firstSSN, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SSyncMinorResponse(firstSSN, cc, data);
		updateAMR05(Event::SSYNmrsp, firstSSN);
		SSYNmrsp();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SControlGiveRequest() {
	ReturnCode rc = OK;
	try {
		sb_logger->SControlGiveRequest();
		SCGreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::STokenGiveRequest(int tokens, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->STokenGiveRequest(tokens, cc, data);
		SGTreq(tokens);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::STokenPleaseRequest(int tokens, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->STokenPleaseRequest(tokens, cc, data);
		SPTreq(tokens);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SReleaseRequest(int secs, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SReleaseRequest(secs, cc, data);
		SRELreq();
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::SReleaseResponse(bool accept, int cc, const void* data) {
	ReturnCode rc = OK;
	try {
		sb_logger->SReleaseResponse(accept, cc, data);
		SRELrsp(accept);
	} catch (const TransitionUndefinedException& e) {
		rc = serviceException(e);
	} catch (const SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}

// Auxilliary functions
/*
	Functional units
	The set of all functional units specified in this Recommendation | International Standard is defined as:

	fu-dom = {FD, HD, EXCEP, TD, NR, SY, SS, DS, MA, RESYN, EX, ACT, CD} where

	FD Duplex functional unit
	HD Half-duplex functional unit
	EXCEP Exceptions functional unit
	TD Typed data functional unit
	NR Negotiated release functional unit
	SY Minor synchronize functional unit
	SS Symmetric synchronize functional unit
	DS Data separation functional unit
	MA Major synchronize functional unit
	RESYN Resynchronize functional unit
	EX Expedited data functional unit
	ACT Activity management functional unit
	CD Capability data exchange functional unit
*/
bool Provider::FU(FunctionalUnit fu) const {//see ITU-T REC X.225 § A.5.2
	/*
		fu-dom = {FD, HD, EXCEP, TD, NR, SY, SS, DS, MA, RESYN, EX, ACT, CD}
		for f in fu-dom
		FU(f) = true if and only if the functional unit f has been selected during the session connection
		establishment phase. The value is set when the ACCEPT SPDU is sent or received	
	*/
	return sb_requirements[fu];
}
bool Provider::AV(Tokens token) const {		// Availability of the tokens. see ITU-T REC X.225 § A.5.2
	/*
		AV(t), for t in tk-dom, is a function which defines the availability of the corresponding token and has the
		following values:
		AV(mi) = FU(SY);
		AV(dk) = FU(HD);
		AV(tr) = FU(NR);
		AV(ma) = FU(MA) OR FU(ACT).	
	*/
	switch(token) {
	case mi:	// the synchronize - minor token;
		return FU(SY);
		break;
	case ma:	// the major / activity token;
		return FU(HD);
		break;
	case tr:	// the release token;
		return FU(NR);
		break;
	case dk:	// the data token.
		return FU(MA) || FU(ACT);
		break;
	default:
		poco_assert(false);
	}
	return false;
}
bool Provider::OWNED(Tokens token) const {	// see ITU-T REC X.225 § A.5.2
	/*
		for t in tk-dom, is a function which defines the assignment of the corresponding token and is
		defined as:
		OWNED(t) = true: if token assigned to the SPM;
		OWNED(t) = false: if token not assigned to the SPM.
		OWNED(t) is not defined if AV(t) = false. OWNED(t) is set when:
		1) the ACCEPT SPDU is sent or received; or
		2) the RESYNCHRONIZE ACK SPDU is sent or received; or
		3) the GIVE TOKENS SPDU is sent or received; or
		4) the GIVE TOKENS CONFIRM SPDU is sent or received;
		5) the ACTIVITY INTERRUPT ACK SPDU is sent or received;
		6) the ACTIVITY DISCARD ACK SPDU is sent or received.	
	*/
	switch(token) {
	case mi:	// the synchronize - minor token;
		return hasMinorToken(sb_owned);
		break;
	case ma:	// the major / activity token;
		return hasMajorToken(sb_owned);
		break;
	case tr:	// the release token;
		return hasReleaseToken(sb_owned);
		break;
	case dk:	// the data token.
		return hasDataToken(sb_owned);
		break;
	default:
		poco_assert(false);
	}
	return false;
}
bool Provider::initiating(Tokens token) const { // see ITU-T REC X.225 § A.5.2: I(t)
	// for t in tk-dom, is a function which, when true, indicates that the SPM has Initiating rights for the
	// behaviour controlled by the token. This applies even if the corresponding token is not available:
	// I(t) = ¬AV(t) OR OWNED(t)

	return !AV(token) || OWNED(token);
}
bool Provider::accepting(Tokens token) const { // see ITU-T REC X.225 § A.5.2:  A(t)
	// for t in tk-dom, is a function which, when true, indicates that the SPM has Accepting rights for the
	// behaviour controlled by the token. This applies even if the corresponding token is not available:
	// A(t) = ¬AV(t) OR ¬OWNED(t)

	return !AV(token) || !OWNED(token);
}
bool Provider::initiating_when_owned_and_available(Tokens token) const { //		II(t)
	// for t in tk-dom, is a function which, when true, indicates that the SPM has Initiating rights as I(t), but
	// this applies to the case when the behaviour may only be initiated if the corresponding token is available
	// and owned:
	// II(t) = AV(t) AND OWNED(t)	

	return AV(token) && OWNED(token);
}
bool Provider::accepting_when_owned_and_available(Tokens token) const { //		AA(t)
	// for t in tk-dom, is a function which, when true, indicates that the SPM has Accepting rights as
	// A(t), but only if the corresponding token is available, but not owned:
	// AA(t) = AV(t) AND ¬OWNED(t)	

	return AV(token) && !OWNED(token);
}
/*
Events SPDU or primitive for update
of variables								V(A)			V(M)		V(R)		Vsc
SSYNMreq		if Vsc true					set to V(M)		V(M) + 1	unchanged	false
SSYNmreq		if Vsc false				unchanged		V(M) + 1	unchanged	false
SACTEreq


MAP SPDU
AE SPDU
sn = V(M) if Vsc true unchanged V(M) + 1 unchanged unchanged
if Vsc false set to V(M) V(M) + 1 unchanged unchanged
MIP SPDU sn = V(M) if Vsc true unchanged V(M) + 1 unchanged true
if Vsc false set to V(M) V(M) + 1 unchanged true
SSYNMrsp
SACTErsp
MAA SPDU
AEA SPDU
sn = V(M) - 1 set to V(M) unchanged set to V(M) unchanged
SSYNmrsp Vsc = true and
V(M) > sn ³ V(A)*
set to sn + 1 unchanged unchanged unchanged
MIA SPDU Vsc = false and
V(M) > sn ³ V(A)*
set to sn + 1 unchanged unchanged unchanged
SRSYNreq a: not applicable
r: V(M) ³ sn ³ V(R)
s: sn £ (10**ULSN) - 1
abandon
restart
set
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
RS SPDU a: sn £ (10**ULSN) - 1
r: sn ³ V(R)
s: sn £ (10**ULSN) - 1
abandon
restart
set
unchanged
unchanged
unchanged
max sn, V(M)
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
unchanged
SRSYNrsp a: sn = V(M)
r: sn as in RS SPDU
s: sn £ (10**ULSN) - 1
abandon
restart
set
set to sn
set to sn
set to sn
set to sn
set to sn
set to sn
0
unchanged
0
unchanged
unchanged
unchanged
RA SPDU a: sn ³ V(M)
r: sn as in RS SPDU
s: sn £ (10**ULSN) - 1
abandon
restart
set
set to sn
set to sn
set to sn
set to sn
set to sn
set to sn
0
unchanged
0
unchanged
unchanged
unchanged
SACTRreq
AR SPDU
set sn + 1 set sn + 1 set to 1 unchanged
SACTSreq
AS SPDU
set to 1 set to 1 set to 1 unchanged
SCONrsp+
AC SPDU
sn present set to sn set to sn 0 false
sn Synchronization point serial number quoted in SS-user request or SPDU
ULSN Upper limit serial number negotiated during the connection establishment phase
³ Greater than or equal to
£ Less than or equal to
* Synchronization point serial number not equal to V(M) - 1 if major synchronization or activity end outstanding
*/
void Provider::updateAMR01(Event event) {
	return;
	poco_assert(event == Event::SSYNMreq || event == Event::SSYNmreq || event == Event::SACTEreq);
	if (Vsc) {
		V(A) = V(M); V(M) += 1; Vsc = false;
	} else {
		V(M) += 1; Vsc = false;
	}
}
void Provider::updateAMR02(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::MAP || event == Event::AE);
	poco_assert(ssn == V(M));
	if (Vsc) {
		V(M) += 1;
	}
	else {
		V(A) = V(M);
		V(M) += 1;
	}
}
void Provider::updateAMR03(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::MIP);
	poco_assert(ssn == V(M));
	if (Vsc) {
		V(M) += 1;	Vsc = true;
	}
	else {
		V(A) = V(M); V(M) += 1; Vsc = true;
	}
}
void Provider::updateAMR04(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::SSYNMrsp || event == Event::SACTErsp || event == Event::MAA || event == Event::AEA);
	if (ssn > 0)	// FIXME See X.225 Table A.4 4rth line
		poco_assert(ssn == V(M) - 1);
	V(A) = V(M);
	V(R) = V(M);
}
void Provider::updateAMR05(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::SSYNmrsp);
	poco_assert(Vsc == true && V(M) > ssn && ssn >= V(A));
	V(A) = ssn + 1;
}
void Provider::updateAMR06(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::MIA);
	poco_assert(Vsc == false && V(M) > ssn && ssn >= V(A));
	V(A) = ssn + 1;
}
void Provider::updateAMR07(Event event, nat4 ssn, ResyncOption resync) {
	return;
	poco_assert(event == Event::SRSYNreq);
	switch (resync) {
	case a: poco_assert(false); break;
	case r: poco_assert(V(M) >= ssn && ssn >= V(R)); break;
	case s: poco_assert(ssn <= pow(10, sb_ulsn) - 1); break;
	default: poco_assert(false);
	}
}
void Provider::updateAMR08(Event event, nat4 ssn, ResyncOption resync) {
	return;
	poco_assert(event == Event::RS);
	switch (resync) {
	case a: poco_assert(ssn <= pow(10, sb_ulsn) - 1); V(M) = max(ssn, V(M)); break;
	case r: poco_assert(ssn >= V(R)); break;
	case s: poco_assert(ssn <= pow(10, sb_ulsn) - 1); break;
	default: poco_assert(false);
	}
}
void Provider::updateAMR09(Event event, nat4 ssn, ResyncOption resync) {
	return;
	poco_assert(event == Event::SRSYNrsp);
	switch (resync) {
	case a: poco_assert(ssn == V(M)); V(A) = V(M) = ssn; V(R) = 0;  break;
	case r: poco_assert(ssn >= V(R));  V(A) = V(M) = ssn; break;
	case s: poco_assert(ssn <= pow(10, sb_ulsn) - 1);  V(A) = V(M) = ssn; V(R) = 0; break;
	default: poco_assert(false);
	}
}
void Provider::updateAMR10(Event event, nat4 serial, ResyncOption resync) {
	return;
	poco_assert(event == Event::RA);
	switch (resync) {
	case a: poco_assert(serial >= V(M)); V(A) = V(M) = serial; V(R) = 0; break;
	case r: poco_assert(serial >= V(R));  V(A) = V(M) = serial; break;
	case s: poco_assert(serial <= pow(10, sb_ulsn) - 1); V(A) = V(M) = serial; V(R) = 0; break;
	default: poco_assert(false);
	}
}
void Provider::updateAMR11(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::SACTRreq || event == Event::AR);
	V(A) = V(M) = ssn + 1; V(R) = 1;
}
void Provider::updateAMR12(Event event) {
	return;
	poco_assert(event == Event::SACTSreq || event == Event::AS);
	V(A) = V(M) = V(R) = 1;
}
void Provider::updateAMR13(Event event, nat4 ssn) {
	return;
	poco_assert(event == Event::SCONrsp || event == Event::AC);
	if (ssn != -1) {
		V(A) = V(M) = ssn; V(R) = 0;
	}
	Vsc = false;
}

ALS::SSAP::USER::AbortIndication&		Provider::abortIndication() const {
	AbortIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (AbortIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (AbortIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::ActivityIndication&	Provider::activityIndication() const {
	ActivityIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ActivityIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ActivityIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::ActivityConfirmation&	Provider::activityConfirmation() const {
	ActivityConfirmation* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ActivityConfirmation*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ActivityConfirmation*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::DataIndication&		Provider::dataIndication() const {
	ALS::SSAP::USER::DataIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ALS::SSAP::USER::DataIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ALS::SSAP::USER::DataIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::DataConfirmation&		Provider::dataConfirmation() const {
	ALS::SSAP::USER::DataConfirmation* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ALS::SSAP::USER::DataConfirmation*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ALS::SSAP::USER::DataConfirmation*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::ReleaseIndication&		Provider::releaseIndication() const {
	ReleaseIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ReleaseIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ReleaseIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::ReleaseConfirmation&		Provider::releaseConfirmation() const {
	ReleaseConfirmation* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ReleaseConfirmation*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ReleaseConfirmation*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::ReportIndication&		Provider::reportIndication() const {
	ReportIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (ReportIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (ReportIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::SynchronizeIndication&	Provider::synchronizeIndication() const {
	SynchronizeIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (SynchronizeIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (SynchronizeIndication*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::SynchronizeConfirmation&	Provider::synchronizeConfirmation() const {
	SynchronizeConfirmation* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (SynchronizeConfirmation*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (SynchronizeConfirmation*)ssap_user_responder;
	return *ind;
}
ALS::SSAP::USER::TokenIndication&		Provider::tokenIndication() const {
	TokenIndication* ind;
	poco_assert(ssap_user_initiator != nullptr ^ ssap_user_responder != nullptr);
	if (ssap_user_initiator != nullptr) ind = (TokenIndication*)ssap_user_initiator;
	if (ssap_user_responder != nullptr) ind = (TokenIndication*)ssap_user_responder;
	return *ind;
}
TSAP::SERV::DataRequest&	Provider::dataRequest() const {
	TSAP::SERV::DataRequest* request;
	poco_assert(tsap_serv_initiator != nullptr ^ tsap_serv_responder != nullptr);
	if (tsap_serv_initiator != nullptr) request = (TSAP::SERV::DataRequest*)tsap_serv_initiator;
	if (tsap_serv_responder != nullptr) request = (TSAP::SERV::DataRequest*)tsap_serv_responder;
	return *request;
}
TSAP::SERV::DisconnectRequest&	Provider::disconnectRequest() const {
	TSAP::SERV::DisconnectRequest* request;
	poco_assert(tsap_serv_initiator != nullptr ^ tsap_serv_responder != nullptr);
	if (tsap_serv_initiator != nullptr) request = (TSAP::SERV::DisconnectRequest*)tsap_serv_initiator;
	if (tsap_serv_responder != nullptr) request = (TSAP::SERV::DisconnectRequest*)tsap_serv_responder;
	return *request;
}



// Outgoing Events
ReturnCode Provider::InvalidOperation() {
	sb_logger->SPAbortIndication(AbortCode::invalid_operation, 0);
	abortIndication().SPAbortIndication(AbortCode::invalid_operation, 0);
	return NOTOK;
}

ReturnCode Provider::SxABind() {
	return DONE;
}
ReturnCode Provider::SACTDind() { 		// SS-provider S-ACTIVITY-DISCARD indication primitive
	sb_logger->SActivityDiscardIndication(0);
	activityIndication().SActivityDiscardIndication(0);
	return DONE;
}
ReturnCode Provider::SACTDcnf() { 		// SS-provider S-ACTIVITY-DISCARD confirm primitive
	sb_logger->SActivityDiscardConfirmation();
	activityConfirmation().SActivityDiscardConfirmation();
	return DONE;
}
ReturnCode Provider::SACTEind() { 		// SS-provider S-ACTIVITY-END indication primitive
	sb_logger->SActivityEndIndication(V(M) - 1);
	activityIndication().SActivityEndIndication(V(M) - 1);
	return DONE;
}
ReturnCode Provider::SACTEcnf() { 		// SS-provider S-ACTIVITY-END confirm primitive
	SSN sb_secondSSN;
	sb_logger->SActivityEndConfirmation(sb_secondSSN);
	activityConfirmation().SActivityEndConfirmation(sb_secondSSN);
	return DONE;
}
ReturnCode Provider::SACTIind() { 		// SS-provider S-ACTIVITY-INTERRUPT indication primitive
	int reason = 0;
	sb_logger->SActivityInterruptIndication(reason);
	activityIndication().SActivityInterruptIndication(reason);
	return DONE;
}
ReturnCode Provider::SACTIcnf() { 		// SS-provider S-ACTIVITY-INTERRUPT confirm primitive
	sb_logger->SActivityInterruptConfirmation();
	activityConfirmation().SActivityInterruptConfirmation();
	return DONE;
}
ReturnCode Provider::SACTRind() { 		// SS-provider S-ACTIVITY-RESUME indication primitive
	ActivityId id;
	ActivityId oid;
	SSN sb_firstSSN;
	SSN sb_secondSSN;
	Reference oref;
	sb_logger->SActivityResumeIndication(id, oid, sb_firstSSN, sb_secondSSN, oref);
	activityIndication().SActivityResumeIndication(id, oid, sb_firstSSN, sb_secondSSN, oref);
	return DONE;
}
ReturnCode Provider::SACTSind(const ActivityId& id) { 		// SS-provider S-ACTIVITY-START indication primitive
	sb_logger->SActivityStartIndication(id);
	activityIndication().SActivityStartIndication(id);
	return DONE;
}
ReturnCode Provider::SCDind() { 		// SS-provider S-CAPABILITY-DATA indication primitive
	sb_logger->SCapabilityDataIndication(sb_tx);
	dataIndication().SCapabilityDataIndication(sb_tx);
	return DONE;
}
ReturnCode Provider::SCDcnf() { 		// SS-provider S-CAPABILITY-DATA confirm primitive
	sb_logger->SCapabilityDataConfirmation(sb_tx);
	dataConfirmation().SCapabilityDataConfirmation(sb_tx);
	return DONE;
}
ReturnCode Provider::SCGind() { 		// SS-provider S-CONTROL-GIVE indication primitive
	sb_logger->SControlGiveIndication(sb_owned);
	tokenIndication().SControlGiveIndication(sb_owned);
	return DONE;
}
ReturnCode Provider::SCONind() { 		// SS-provider S-CONNECT indication primitive
	sb_logger->SConnectIndication(sb_reference, sb_initiating, sb_responding, 0, sb_qos, sb_requirements, sb_firstInitialSSN, sb_secondInitialSSN,	sb_settings, sb_ssdusize);
	ssap_user_responder->SConnectIndication(sb_reference, sb_initiating, sb_responding, 0, sb_qos, sb_requirements, sb_firstInitialSSN, sb_secondInitialSSN, sb_settings, sb_ssdusize);
	return DONE;
}
ReturnCode Provider::SCONcnf(bool accept) {// SS-provider S-CONNECT (accept(true)/reject(false)) confirm primitive
	sb_logger->SConnectConfirmation(sb_reference, sb_responding, AbortCode::SC_ACCEPT, sb_qos, sb_requirements, sb_firstInitialSSN, sb_secondInitialSSN, sb_settings, sb_ssdusize);
	ssap_user_initiator->SConnectConfirmation(sb_reference, sb_responding, AbortCode::SC_ACCEPT, sb_qos, sb_requirements, sb_firstInitialSSN, sb_secondInitialSSN, sb_settings, sb_ssdusize);
	return DONE;
}
ReturnCode Provider::SDTind() { 		// SS-provider S-DATA indication primitive
	sb_logger->SDataIndication(sb_tx);
	dataIndication().SDataIndication(sb_tx);
	return DONE;
}
ReturnCode Provider::SEXind() { 		// SS-provider S-EXPEDITED-DATA indication primitive
	sb_logger->SExpeditedDataIndication(sb_tx);
	dataIndication().SExpeditedDataIndication(sb_tx);
	return DONE;
}
ReturnCode Provider::SGTind(int tokens) { // SS-provider S-TOKEN-GIVE indication primitive
	sb_logger->STokenGiveIndication(tokens);
	tokenIndication().STokenGiveIndication(tokens);
	return DONE;
}
ReturnCode Provider::SPABind() { 		// SS-provider S-P-ABORT indication primitive
	int reason = 0;
	sb_logger->SPAbortIndication(reason, 0);
	abortIndication().SPAbortIndication(reason, 0);
	return DONE;
}
ReturnCode Provider::SPERind() { 		// SS-provider S-P-EXCEPTION-REPORT indication primitive
	int reason = 0;
	sb_logger->SPExceptionReportIndication(reason);
	reportIndication().SPExceptionReportIndication(reason);
	return DONE;
}
ReturnCode Provider::SPTind(int tokens) { // SS-provider S-TOKEN-PLEASE indication primitive
	sb_logger->STokenPleaseIndication(tokens);
	tokenIndication().STokenPleaseIndication(tokens);
	return DONE;
}
ReturnCode Provider::SRELind() { 		// SS-provider S-RELEASE indication primitive
	sb_logger->SReleaseIndication();
	releaseIndication().SReleaseIndication();
	return DONE;
}
ReturnCode Provider::SRELcnf(bool accept) { 	// SS-provider S-RELEASE (accept(true)/reject(false)) confirm primitive
	sb_logger->SReleaseConfirmation(accept);
	releaseConfirmation().SReleaseConfirmation(accept);
	return DONE;
}
ReturnCode Provider::SRSYNind() { 		// SS-provider S-RESYNCHRONIZE indication primitive
	poco_assert(sb_spdu->si() == SPDU::SPDU::SPDU_RS);
	SPDU::RS& rs = *(SPDU::RS*)sb_spdu;
	sb_logger->SResynchronizeIndication(rs.type(), rs.ssn(), rs.secondType(), rs.secondSSN(), rs.settings());
	synchronizeIndication().SResynchronizeIndication(rs.type(), rs.ssn(), rs.secondType(), rs.secondSSN(), rs.settings());
	return DONE;
}
ReturnCode Provider::SRSYNcnf() { 		// SS-provider S-RESYNCHRONIZE confirm primitive
	SSN sb_firstSSN;
	SSN sb_secondSSN;
	ResyncOption sb_firstResync;
	ResyncOption sb_secondResync;
	sb_logger->SResynchronizeConfirmation(sb_firstResync, sb_firstSSN, sb_secondResync, sb_secondSSN, sb_settings);
	synchronizeConfirmation().SResynchronizeConfirmation(sb_firstResync, sb_firstSSN, sb_secondResync, sb_secondSSN, sb_settings);
	return DONE;
}
ReturnCode Provider::SSYNMind(const SPDU::MAP& map) { 		// SS-provider S-SYNC-MAJOR indication
	sb_logger->SSyncMajorIndication(map.getSerial());
	synchronizeIndication().SSyncMajorIndication(map.getSerial());
	return DONE;
}
ReturnCode Provider::SSYNMcnf() { 		// SS-provider S-SYNC-MAJOR confirm
	SSN sb_secondSSN;
	sb_logger->SSyncMajorConfirmation(V(M) - 1);
	synchronizeConfirmation().SSyncMajorConfirmation(V(M) - 1);
	return DONE;
}
ReturnCode Provider::SSYNmind() { 		// SS-provider S-SYNC-MINOR indication primitive
	SSN sb_firstSSN;
	SyncOption sb_sync;
	bool dataSeparation = false;
	sb_logger->SSyncMinorIndication(sb_sync, dataSeparation, sb_firstSSN);
	synchronizeIndication().SSyncMinorIndication(sb_sync, dataSeparation, sb_firstSSN);
	return DONE;
}
ReturnCode Provider::SSYNmdind() { 		// SS-provider S-SYNC-MINOR (data separation) indication primitive
	SSN sb_firstSSN;
	SyncOption sb_sync;
	bool dataSeparation = true;
	sb_logger->SSyncMinorIndication(sb_sync, dataSeparation, sb_firstSSN);
	synchronizeIndication().SSyncMinorIndication(sb_sync, dataSeparation, sb_firstSSN);
	return DONE;
}
ReturnCode Provider::SSYNmcnf() { 		// SS-provider S-SYNC-MINOR confirm primitive
	SSN sb_firstSSN;
	sb_logger->SSyncMinorConfirmation(sb_firstSSN);
	synchronizeConfirmation().SSyncMinorConfirmation(sb_firstSSN);
	return DONE;
}
ReturnCode Provider::STDind() { 		// SS-provider S-TYPED-DATA indication primitive
	sb_logger->STypedDataIndication(sb_tx);
	dataIndication().STypedDataIndication(sb_tx);
	return DONE;
}
ReturnCode Provider::SUABind() { 		// SS-provider S-U-ABORT indication primitive
	sb_logger->SUAbortIndication(0);
	abortIndication().SUAbortIndication(0);
	return DONE;
}
ReturnCode Provider::SUERind() { 		// SS-provider S-U-EXCEPTION-REPORT indication primitive
	sb_logger->SUExceptionReportIndication(0);
	reportIndication().SUExceptionReportIndication(0);
	return DONE;
}
ReturnCode Provider::TCONreq() {  		// TS-user T-CONNECT request primitive
	ReturnCode rc;
	bool expedited = sb_qos.extended() || sb_requirements.has(EXPEDITED);
	rc = tsap_serv_initiator->TConnectRequest(sb_calling, sb_called, expedited, sb_qos);
	return rc;
}
ReturnCode Provider::TCONrsp() {  		// TS-user T-CONNECT response primitive
	poco_assert(tsap_serv_initiator == nullptr && tsap_serv_responder != nullptr);
	tsap_serv_responder->TConnectResponse(sb_called, sb_expedited, sb_qos);
	return OK;
}
ReturnCode Provider::TDISreq() {  		// TS-user T-DISCONNECT request primitive
	disconnectRequest().TDisconnectRequest(0, sb_called);
	return OK;
}

#define GTCAT(type, name) 	CATENE spdus;SPDU::GT gt;spdus.add(&gt);SPDU::type name;spdus.add(&name)
#define PTCAT(type, name) 	CATENE spdus;SPDU::PT pt;spdus.add(&pt);SPDU::type name;spdus.add(&name)

ReturnCode Provider::AA() { 			// ABORT ACCEPT SPDU
	ReturnCode rc = OK;
	SPDU::AA spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = tsap_serv_initiator->TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::AB(bool reuse) {	// ABORT (reuse(r)/not reuse(nr)) SPDU
	ReturnCode rc = OK;
	SPDU::AB spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = tsap_serv_initiator->TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::AC(SPDU::AC& ac) { // ACCEPT SPDU
	ReturnCode rc;
	int len = ac.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	rc = ac.flush(ssdu);
	poco_assert(tsap_serv_responder != nullptr);
	rc = tsap_serv_responder->TDataRequest(ssdu.get());
	if (rc == OK) {
		sb_state.add(SB_CONN);
	}
	return OK;
}
ReturnCode Provider::AD() { 			// ACTIVITY DISCARD SPDU
	ReturnCode rc = OK;
	GTCAT(AD, ad);
	gt.encode();
	ad.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::ADA() { 			// ACTIVITY DISCARD ACK SPDU
	ReturnCode rc = OK;
	PTCAT(ADA, ada);
	pt.encode();
	ada.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AE(nat4 ssn) { 	// ACTIVITY END SPDU
	ReturnCode rc = OK;
	GTCAT(AE, ae);
	ae.setSerial(ssn);
	gt.encode();
	ae.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AEA() { 			// ACTIVITY END ACK SPDU
	ReturnCode rc = OK;
	PTCAT(AEA, aea);
	aea.setSerial(V(M) - 1);
	pt.encode();
	aea.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AI() { 			// ACTIVITY INTERRUPT SPDU
	ReturnCode rc = OK;
	GTCAT(AI, ai);
	gt.encode();
	ai.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AIA() { 			// ACTIVITY INTERRUPT ACK SPDU
	ReturnCode rc = OK;
	PTCAT(AIA, aia);
	pt.encode();
	aia.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AR() { 			// ACTIVITY RESUME SPDU
	ReturnCode rc = OK;
	PTCAT(AR, ar);
	pt.encode();
	ar.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::AS(const ActivityId& activityId, int cc, const void* data) { 			// ACTIVITY START SPDU
	ReturnCode rc = OK;
	GTCAT(AS, as);
	as.setId(activityId);
	as.setData(cc, data);
	gt.encode();
	as.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::CD() { 			// CAPABILITY DATA SPDU
	ReturnCode rc = OK;
	GTCAT(CD, cd);
	gt.encode();
	cd.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::CDA() { 			// CAPABILITY DATA ACK SPDU
	ReturnCode rc = OK;
	PTCAT(CDA, cda);
	pt.encode();
	cda.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::CDO() { 			// CONNECT DATA OVERFLOW SPDU
	ReturnCode rc = OK;
	SPDU::CDO spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = tsap_serv_initiator->TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::CN() { 			// CONNECT SPDU
	ReturnCode rc;
	SPDU::CN spdu;
	spdu.setCalling(sb_initiating.selector().length(), sb_initiating.selector().data());
	spdu.setCalled(sb_responding.selector().length(), sb_responding.selector().data());
	spdu.setReference(sb_reference);
	spdu.setVersion(sb_vrsnmask);

	if (sb_firstInitialSSN.ssn() != SERIAL_NONE) {
		spdu.setIsn((int)sb_firstInitialSSN.ssn());
	}

	spdu.setData(sb_cc, sb_data);
	//	retry = cn;
	if (sb_tsdu_us > 0 || sb_tsdu_them > 0) {
		spdu.setTSDUResponder((short)GET_TSDU_SIZE(sb_tsdu_us));
		spdu.setTSDUInitiator((short)GET_TSDU_SIZE(sb_tsdu_them));
	}

	spdu.setRequires(sb_requirements);
	if (spdu.getRequires() .has(SUBSET_TOKENS)) {
		spdu.setSettings(settings());
	}

	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = tsap_serv_initiator->TDataRequest(ssdu.get());
	//	rc = spkt2sd(dataRequest, false, sa);
	/*
	s.s_mask &= ~SMASK_UDATA_PGI;
	s.s_udata = nullptr, s.s_ulen = 0;
	s = nullptr;
	*/
	spdu.setData(0, nullptr);

	return rc;
}
ReturnCode Provider::DN() { 			// DISCONNECT SPDU
	ReturnCode rc = OK;
	SPDU::DN spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::DT() { 			// DATA TRANSFER SPDU
	ReturnCode rc = OK;
	GTCAT(DT, dt);
	gt.encode();
	//TODO make proper decision on concatenation and segmentation
	// the code below is just to make progress on the overall design
	dt.addMask(SPDU::SPDU::SMASK_ENCLOSE);
	dt.addEnclose(SPDU::SPDU::ENCL_BEGIN);
	dt.addEnclose(SPDU::SPDU::ENCL_END);
	dt.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::ED() { 			// EXCEPTION DATA SPDU
	ReturnCode rc = OK;
	PTCAT(ED, ed);
	pt.encode();
	ed.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::ER() { 			// EXCEPTION REPORT SPDU
	ReturnCode rc = OK;
	PTCAT(ER, er);
	pt.encode();
	er.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::EX() { 			// EXPEDITED DATA SPDU
	ReturnCode rc = OK;
	SPDU::EX spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::FN(bool reuse) { // FINISH (reuse(r)/not reuse(nr)) SPDU
	ReturnCode rc = OK;
	SPDU::FN spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::GT(int tokens) { 	// GIVE TOKENS SPDU
	ReturnCode rc = OK;
	SPDU::GT spdu(tokens);
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::GTA() { 			// GIVE TOKENS ACK SPDU
	ReturnCode rc = OK;
	SPDU::GTA spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::GTC() { 			// GIVE TOKENS CONFIRM SPDU
	ReturnCode rc = OK;
	SPDU::GTC spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::MAA() { 			// MAJOR SYNC ACK SPDU
	ReturnCode rc = OK;
	PTCAT(MAA, maa);
	pt.encode();
	maa.setSerial(V(M) - 1);
	maa.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::MAP() { 			// MAJOR SYNC POINT SPDU
	ReturnCode rc = OK;
	GTCAT(MAP, map);
	gt.encode();
	map.setSerial(V(M));
	map.setSync(SyncOption::MAJOR_SYNC_WITOUT_END_OF_ACTIVITY);
	map.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::MIA() { 			// MINOR SYNC ACK SPDU
	ReturnCode rc = OK;
	PTCAT(MIA, mia);
	pt.encode();
	mia.setSerial(V(M) - 1);
	mia.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::MIP() { 			// MINOR SYNC POINT SPDU
	ReturnCode rc = OK;
	GTCAT(MIP, mip);
	gt.encode();
	mip.setSerial(V(M) - 1);
	mip.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::MIP(bool dataSeparationPoint) { // -d// MINOR SYNC (data separation(true)) POINT SPDU
	ReturnCode rc = OK;
	GTCAT(MIP, mip);
	gt.encode();
	mip.setSerial(V(M));
	mip.encode();
	unique_ptr<NetworkBuffer>	tsdu((nullptr_t)nullptr);
	spdus.flush(tsdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(tsdu.get());
	return rc;
}
ReturnCode Provider::NF() { 			// NOT FINISHED SPDU
	ReturnCode rc = OK;
	SPDU::NF spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::OA() { 			// OVERFLOW ACCEPT SPDU
	ReturnCode rc = OK;
	SPDU::OA spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = tsap_serv_initiator->TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::PR_AB() { 			// PREPARE (ABORT) SPDU
	ReturnCode rc = OK;
	if (false) { // FIXME to send on Transport Expedited flow if available
		SPDU::AB spdu;
		spdu.encode();
		unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
		spdu.flush(ssdu);
		rc = dataRequest().TDataRequest(ssdu.get());
	}
	return rc;
}
ReturnCode Provider::PR_MAA() { 		// PREPARE (MAJOR SYNC ACK) SPDU
	ReturnCode rc = OK;
	if (false) { // FIXME to send on Transport Expedited flow if available
		SPDU::PR spdu;
		spdu.encode();
		unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
		spdu.flush(ssdu);
		rc = dataRequest().TDataRequest(ssdu.get());
	}
	return rc;
}
ReturnCode Provider::PR_RA() { 			// PREPARE (RESYNCHRONIZE ACK) SPDU
	ReturnCode rc = OK;
	SPDU::RA spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::PR_RS() { 			// PREPARE (RESYNCHRONIZE) SPDU
	ReturnCode rc = OK;
	if (false) { // FIXME to send on Transport Expedited flow if available
		SPDU::RS spdu;
		spdu.encode();
		unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
		spdu.flush(ssdu);
		rc = dataRequest().TDataRequest(ssdu.get());
	}
	return rc;
}
ReturnCode Provider::PT(int tokens) { 	// PLEASE TOKENS SPDU
	ReturnCode rc = OK;
	SPDU::PT spdu(tokens);
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::RA() { 			// RESYNCHRONIZE ACK SPDU
	ReturnCode rc = OK;
	PTCAT(RA, ra);
	ra.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdus.flush(ssdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::RF(bool reuse) {	// REFUSE (reuse(r)/not reuse(nr)) SPDU
	ReturnCode rc = OK;
	SPDU::RF spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::RS(ResyncOption resync, nat4 ssn) { 	// RESYNCHRONIZE (abandon(a)/restart(r)/set(s)) SPDU
	ReturnCode rc = OK;
	GTCAT(RS, rs);
	rs.type(resync);
	rs.setSerial(ssn);
	gt.encode();
	rs.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdus.flush(ssdu, sb_cc, sb_data);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}
ReturnCode Provider::TD() { 			// TYPED DATA SPDU
	ReturnCode rc = OK;
	SPDU::TD spdu;
	spdu.encode();
	unique_ptr<NetworkBuffer>	ssdu((nullptr_t)nullptr);
	spdu.flush(ssdu);
	rc = dataRequest().TDataRequest(ssdu.get());
	return rc;
}

void Provider::dump(FSM& context) {
	int i = 2;
	context.getTransition();
}

// *****************************************************************************************
// Specific Actions
// *****************************************************************************************
void Provider::SA1() {
	Vtca = true;
}
void Provider::SA2() {
	Vtca = false;
}
void Provider::SA3() {
	/*Stop  timer TIM*/
}
void Provider::SA4() {
	/*Start timer TIM*/
}
void Provider::SA5(nat4 ssn) {
	V(A) = V(M) = ssn;

	V(R) = 0;
	Vcoll = false;
	Vrsp = no;
	Vsc = false;
	V(Ado) = SERIAL_NONE;
	V(Adi) = SERIAL_NONE;
	TEXP = false;
	/* FIXME
	Set FU(f) for f in fu-dom according to the intersection of Session User Requirements
	in the CONNECT SPDU and Session User Requirements in the ACCEPT SPDU
	*/
	if (FU(ACT))
		Vact = false;
	Vdnr = false;
}
void Provider::SA6() {
	// FIXME
	// Recall the queued events until the queue is empty
	// throw NotYetImplementedException();
}
void Provider::SA7() {
	Vtrr = true;
}
void Provider::SA8() {
	Vtrr = false;
}
void Provider::SA9() {
	// Set Vtrr according to the Transport Disconnect PV field in the SPDU
	// As a local decision, Vtrr may always be set false
	Vtrr = false;
}
void Provider::SA10() {
	// Store the event in the queue
	throw NotYetImplementedException();
}
void Provider::SA11(int tokens) { // Update the position of the tokens
	sb_owned.add(tokens);
}
void Provider::SA12() {
	Vact = true;
}
void Provider::SA13() {
	Vnextact = true;
}
void Provider::SA14() {
	Vact = Vnextact;
}
void Provider::SA15(int tokens) { // as SA15 is unused, take it for removing token instead of SA11
	sb_owned.rem(tokens);
}
void Provider::SA16(bool reuse) {
	/*
	If ¬FU(SS), then:
		Update Vrsp
		If RS-r, update Vrspnb
		Set Discard-rcv-flow = true
		Set Discard-snd-flow = true
	If FU(SS), then:
		Update Vrsps
		If Vrsps = r, update Vrspnbs
		If Vrsps != no, set Discard-snd-flow = true
	If FU(SS), then:
		Update Vrspr
		If Vrspr = r, update Vrspnbr
		If Vrspr != no, set Discard-rcv-flow = true
	*/
	if (!FU(SS)) {
		Vrsp = no;	// What does mean update Vrsp???
		if (reuse) Vrspnb += 1;
		discard_rcv_flow = true;
		discard_snd_flow = true;
	}
	if (FU(SS)) {
		Vrsps = r; //FIXME
		if (Vrsps == r);//FIXME update Vrspnbs; //TYPO If Vrsps = r, update Vrspnbs
		if (Vrsps != no) discard_snd_flow = true;
	}
	if (FU(SS)) {
		Vrspr = r; //FIXME
		if (Vrspr == r);//FIXME udpate Vrspnbr;
		if (Vrspr != no) discard_rcv_flow = true;
	}
}
void Provider::SA17() {
	Vnextact = false;
}
void Provider::SA18() {
	Vcoll = true;
}
void Provider::SA19() {
	/*
	If ¬FU(SS), then: V(M) = maximum [V(M), received serial_number]
	If FU(SS), then: V(Mr) = maximum [V(Mr), received first serial_number]
	V(Ms) = maximum [V(Ms), received second serial_number]
	*/
	if(!FU(SS)) {
		V(M) = maximum(V(M), rcv_serial_number);
	}
	if (FU(SS)) {
		V(Mr) = maximum(V(Mr), rcv_first_serial_number);
	}
	V(Ms) = maximum(V(Ms), rcv_second_serial_number);
}
void Provider::SA20() {
	Vsc = false;
}
void Provider::SA21() {
	V(M) = V(M) + 1;
}
void Provider::SA22() {
	V(R) = V(A) = V(M);
}
void Provider::SA23() {
	if (Vsc == false)
		V(A) = V(M);

	Vsc = true;
	V(M) = V(M) + 1;
}
void Provider::SA24() {
	if (Vsc == true)
		V(A) = V(M);

	Vsc = false;
	V(M) = V(M) + 1;
}
void Provider::SA25(nat4 ssn) {
	V(A) = ssn + 1;
}
void Provider::SA26() {
	V(A) = V(M) = V(R) = 1;
}
void Provider::SA27(nat4 ssn) {
	V(A) = V(M) = ssn + 1;
	V(R) = 1;
}
void Provider::SA28(nat4 ssn) {
	V(A) = V(M) = ssn;
	if (Vrsp == a)
		V(R) = 0;
	if (Vrsp == s)
		V(R) = 0;
	Vrsp = no;
	V(Ado) = SERIAL_NONE;
	V(Adi) = SERIAL_NONE;
	discard_rcv_flow = false;
	discard_snd_flow = false;
}
void Provider::SA29() {
	/*
	Set the position of the tokens such that all available tokens are owned
	Set Vact = false
	Set Vrsp = no
	*/
	sb_owned.reset();
	// FIXME if available then add
	sb_owned.add(RELEASE_TOKEN);
	sb_owned.add(MAJOR_TOKEN);
	sb_owned.add(MINOR_TOKEN);
	sb_owned.add(DATA_TOKEN);
	Vact = false;
	Vrsp = no;
}
void Provider::SA30() {
	/*
	Set the position of the tokens such that all available tokens are not owned
	Set Vact = false
	Set Vrsp = no
	*/
	// FIXME if available then rem
	sb_owned.rem(RELEASE_TOKEN);
	sb_owned.rem(MAJOR_TOKEN);
	sb_owned.rem(MINOR_TOKEN);
	sb_owned.rem(DATA_TOKEN);
	Vact = false;
	Vrsp = no;
}
void Provider::SA31() {
	if (Vsc == false)
		V(A) = V(M);
	V(M) = V(M) + 1;
}
void Provider::SA32() {
	Vdnr = true;
}
void Provider::SA41() {
	V(Ado) = V(M);
}
void Provider::SA42() {
	V(Ado) = V(Ms);
}
void Provider::SA43() {
	V(Ado) = -1;
	V(Adi) = -1;
}
void Provider::SA44() {
	V(Adi) = V(M);
}
void Provider::SA45() {
	V(Adi) = V(Mr);
}
void Provider::SA50() {
	//FIXME Preserve user data for subsequent SCONind
	throw NotYetImplementedException();
}
void Provider::SA51() {
	/*
	If p201 send subsequent CDO SPDUs until ¬p201
	*/
	if (p201()) {
		//FIXME send subsequent CDO SPDUs until ¬p201
		throw NotYetImplementedException();
	}
}
void Provider::SA62() {
	V(Mr) = V(Mr) + 1;
}
void Provider::SA63() {
	V(Ms) = V(Ms) + 1;
}
void Provider::SA64() {
	V(Rs) = V(As) = V(Ms);
	V(Rr) = V(Ar) = V(Mr);
}
void Provider::SA65() {
	V(As) = serial_number + 1;
}
void Provider::SA66() {
	V(Ar) = serial_number + 1;
}
void Provider::SA67() {
	/*
	If neither Resync Type is present, then:
	Set Discard-rcv-flow = true
	Set Discard-snd-flow = true
	If Resync Type is present for sending flow, then:
	Set Discard-snd-flow = true
	If Resync Type is present for receiving flow, then:
	Set Discard-rcv-flow = true
	*/
#if FIXME
	if (neither Resync Type is present for send and receiveing flow) {
			discard_rcv_flow = true;
			discard_snd_flow = true;
		}
	if (Resync Type is present for sending flow)
			discard_snd_flow = true;

	if (Resync Type is present for receiving flow)
			discard_rcv_flow = true;
#else
	throw NotYetImplementedException();
#endif
}
void Provider::SA68() {
	/*
	Set V(As) = V(Ms) = sending_flow_serial_number, if present
	If Vrsps = a, then set V(Rs) = 0
	If Vrsps = s, then set V(Rs) = 0
	Set Vrsps = no
	Set Discard-snd-flow = false
	Set V(Ar) = V(Mr) = receiving_flow_serial_number, if present
	If Vrspr = a, then set V(Rr) = 0
	If Vrspr = s, then set V(Rr) = 0
	Set Vrspr = no
	Set Discard-rcv-flow = false
	Set V(Ado) = -1
	Set V(Adi) = -1
	*/
	if (snd_flow_serial_number_present)
		V(As) = V(Ms) = snd_flow_serial_number;
	if (Vrsps == a) V(Rs) = 0;
	if (Vrsps == s) V(Rs) = 0;
	Vrsps = no;
	discard_snd_flow = false;
	if (rcv_flow_serial_number_present)
		V(Ar) = V(Mr) = rcv_flow_serial_number;
	if (Vrspr == a) V(Rr) = 0;
	if (Vrspr == s) V(Rr) = 0;
	Vrspr = no;
	discard_rcv_flow = false;
	V(Ado) = -1;
	V(Adi) = -1;
}
void Provider::SA69() {
	V(As) = V(Ms) = snd_flow_serial_number + 1;
	V(Rs) = 1;
	V(Ar) = V(Mr) = rcv_flow_serial_number + 1;
	V(Rr) = 1;
}
void Provider::SA70() {
	V(As) = V(Ms) = V(Rs) = 1;
	V(Ar) = V(Mr) = V(Rr) = 1;
}
void Provider::SA71() {
	V(As) = V(Ms) = snd_flow_serial_number;// in ACCEPT SPDU;
	V(Rs) = 0;
	Vrsps = no;
	discard_snd_flow = false;
	V(Ar) = V(Mr) = rcv_flow_serial_number;// in ACCEPT SPDU;
	V(Rr) = 0;
	Vrspr = no;
	discard_rcv_flow = false;
	Vcoll = false;
	V(Ado) = -1;
	V(Adi) = -1;
}
void Provider::SA72() {
	/*
	If FU(SS), then update Vrspr, Vrsps, Vrspnbr, and Vrspnbs as in A.5.4.5
	*/
	if (FU(SS)) {
		//FIXME update Vrspr, Vrsps, Vrspnbr, and Vrspnbs as in A.5.4.5;
		throw NotYetImplementedException();
	}
}

#define I(token) initiating(token)
#define A(token) accepting(token)
#define II(token) initiating_when_owned_and_available(token)
#define AA(token) accepting_when_owned_and_available(token)

// *****************************************************************************************
// Predicates
// *****************************************************************************************
bool Provider::p01() const {
	return !Vtca;
}
bool Provider::p02() const {
	return /*FIXME local_choice && */ !TEXP;
}
bool Provider::p03() const {
	return I(dk);
}
bool Provider::p04() const {
	return FU(FD) && !Vcoll;
}
bool Provider::p05() const {
	return A(dk);
}
bool Provider::p06() const {
	return FU(FunctionalUnit::TD);
}
bool Provider::p07() const {
	return FU(FunctionalUnit::TD) && !Vcoll;
}
bool Provider::p08() const {
	return FU(FunctionalUnit::EX);
}
bool Provider::p09() const {
	return FU(FunctionalUnit::EX) & !Vcoll;
}

bool Provider::p10() const {
	return !Vcoll;
}
bool Provider::p11() const {
	return II(ma);
}
bool Provider::p12() const { 
	return FU(MA) && (!FU(ACT) || Vact) && A(dk) && A(mi) && AA(ma);
}
bool Provider::p13()  {
	return FU(MA) && (!FU(ACT) || Vact) && I(dk) && I(mi) && II(ma);
}
bool Provider::p14() const {
	return (!FU(ACT) || Vact) && A(dk) && AA(mi);
}
bool Provider::p15() const {
	return (!FU(ACT) || Vact) && I(dk) && II(mi);
}
bool Provider::p16() const {
	return !TEXP;
}
bool Provider::p17() const {
	return (!FU(ACT) || Vact) &&  (FU(SS) || FU(SY)) &&  (FU(SS) || !Vsc);
}
bool Provider::p18() const {
	return (!FU(ACT) || Vact) &&  (FU(SS) || FU(SY)) &&  (FU(SS) || Vsc);
}
bool Provider::p19(nat4 ssn) const {
	return !FU(SS) && (ssn == V(M));
}
bool Provider::p20(nat4 ssn) const {
	return !FU(SS) && (ssn==(V(M) - 1));
}
bool Provider::p21() const {
	return !FU(SS) && (V(M) > serial_number && serial_number >= V(A));
}
bool Provider::p22() const {
	/* Unused */ poco_assert(false);
	return true;
}
bool Provider::p23() const {
	return FU(ACT) && !Vnextact;
}
bool Provider::p24() const {
	return !SPMwinner;
}
bool Provider::p25() const {
	return (FU(SY) || FU(SS) || FU(MA)) && FU(RESYN);
}
bool Provider::p26() const {
	return (!FU(ACT) || Vact);
}
bool Provider::p27() const {
	return Vrsp == no;
}
bool Provider::p28() const {
	return FU(RESYN);
}
bool Provider::p29() const {
	return (!FU(ACT) || Vact) && FU(RESYN);
}

bool Provider::p30() const {
	return !FU(ACT) || Vnextact;
}
bool Provider::p31() const {
	return FU(ACT) && Vnextact;
}
bool Provider::p32(ResyncOption type) const {
	return (!FU(SS) && ((type != r) || (serial_number >= V(R))))
		   || (FU(SS)
			   && ((rcv_flow_type != r) || (rcv_flow_serial_number >= V(Rr)))
			   && ((snd_flow_type != r) || (snd_flow_serial_number >= V(Rs))));
}
bool Provider::p33() const {
	return V(M) >= serial_number && serial_number >= V(R);
}
bool Provider::p34() const {
	return FU(ACT);
}
bool Provider::p35() const {
	return FU(RESYN) && (!TEXP || FU(DS));
}
bool Provider::p36() const {
	return FU(RESYN) && TEXP;
}
bool Provider::p37() const {
	return FU(ACT) && TEXP;
}
bool Provider::p38() const {
	return FU(ACT) && !TEXP;
}
bool Provider::p39() const {
	return Vact && II(ma);
}

bool Provider::p40() const {
	return AA(ma);
}
bool Provider::p41() const {
	return Vrsp == dsc;
}
bool Provider::p42() const {
	return Vrsp == inte;
}
bool Provider::p43() const {
	return !FU(SS)
		   && (
			   ((Vrsp == r) &&  (serial_number == Vrspnb))
			   || ((Vrsp == a) &&  (serial_number == V(M)))
			   || (Vrsp == s));
}
bool Provider::p44() const {	// return (FU(ACT) && !Vact) && A(dk) && A(mi) && A(ma);
	bool result = true;
	result &= FU(ACT);
	result &= !Vact;
	result &= A(dk);
	result &= A(mi);
	result &= A(ma);
	return result;
}
bool Provider::p45() const {
	return (FU(ACT) && !Vact) && I(dk) && I(mi) && I(ma);
}
bool Provider::p46() const {
	return FU(FunctionalUnit::CD) && (FU(ACT) && !Vact) && A(dk) && A(mi) && !OWNED(ma);
}
bool Provider::p47() const {
	return FU(FunctionalUnit::CD) && (FU(ACT) && !Vact) && I(dk) && I(mi) && OWNED(ma);
}
bool Provider::p48() const {
	return FU(EXCEP) && FU(HD);
}
bool Provider::p49() const {
	return ((Vrsp == r) &&  (serial_number == Vrspnb))
		   || ((Vrsp == a) &&  (serial_number >= V(M)))
		   || (Vrsp == s);
}
bool Provider::p50() const				{
	return FU(EXCEP) && (!FU(ACT) || Vact) && AA(dk);
}
bool Provider::p51() const				{
	return FU(EXCEP) && (!FU(ACT) || Vact) && II(dk);
}
bool Provider::p52() const				{
	return FU(EXCEP) && !FU(ACT) && II(dk);
}
bool Provider::p53(int tokens) const	{ // ALL(AV, RT)
	bool result = true;
	if (hasMinorToken(tokens))
		result &= AV(mi);
	if (hasMajorToken(tokens))
		result &= AV(ma);
	if (hasReleaseToken(tokens))
		result &= AV(tr);
	if (hasDataToken(tokens))
		result &= AV(dk);
	return result;
}
bool Provider::p54(int tokens) const	{ // ALL(II, GT); }
	if (tokens == 0)
		return true;
	bool result = true;
	if (hasMinorToken(tokens))
		result &= II(mi);
	if (hasMajorToken(tokens))
		result &= II(ma);
	if (hasReleaseToken(tokens))
		result &= II(tr);
	if (hasDataToken(tokens))
		result &= II(dk);
	return result;
}
bool Provider::p55() const				{ // (FU(ACT) && !Vact) && ALL(I, tk_dom)
	bool result = (FU(ACT) && !Vact);
	result &= I(mi);
	result &= I(ma);
	result &= I(tr);
	result &= I(dk);
	return result;
}

bool Provider::p57(int tokens) const	{ // ALL(II, GT) && (dk not in GT)
	if (hasDataToken(tokens))
		return false;
	bool result = true;
	if (hasMinorToken(tokens))
		result &= II(mi);
	if (hasMajorToken(tokens))
		result &= II(ma);
	if (hasReleaseToken(tokens))
		result &= II(tr);
	if (hasDataToken(tokens))
		result &= II(dk);
	return result;
}
bool Provider::p58(int tokens) const	{ // ALL(II, GT) && (dk in GT); }
	if (hasDataToken(tokens)) {
		bool result = true;
		if (hasMinorToken(tokens))
			result &= II(mi);
		if (hasMajorToken(tokens))
			result &= II(ma);
		if (hasReleaseToken(tokens))
			result &= II(tr);
		if (hasDataToken(tokens))
			result &= II(dk);
		return result;
	}
	return false;
}
bool Provider::p59(int tokens) const	{ // ALL(AA, GT)
	bool result = true;
	if (hasMinorToken(tokens))
		result &= AA(mi);
	if (hasMajorToken(tokens))
		result &= AA(ma);
	if (hasReleaseToken(tokens))
		result &= AA(tr);
	if (hasDataToken(tokens))
		result &= AA(dk);
	return result;
}

bool Provider::p60(int tokens) const	{ // ALL(AA, GT) && (dk not in GT); }
	if (hasDataToken(tokens))
		return false;
	bool result = true;
	if (hasMinorToken(tokens))
		result &= AA(mi);
	if (hasMajorToken(tokens))
		result &= AA(ma);
	if (hasReleaseToken(tokens))
		result &= AA(tr);
	if (hasDataToken(tokens))
		result &= AA(dk);
	return result;
}
bool Provider::p61(int tokens) const	{ // ALL(AA, GT) && (dk in GT)
	if (hasDataToken(tokens)) {
		bool result = true;
		if (hasMinorToken(tokens))
			result &= AA(mi);
		if (hasMajorToken(tokens))
			result &= AA(ma);
		if (hasReleaseToken(tokens))
			result &= AA(tr);
		if (hasDataToken(tokens))
			result &= AA(dk);
		return result;
	}
	return false;
}
bool Provider::p62() const				{ // (FU(ACT) && !Vact) && ALL(A, tk_dom)
	bool result = (FU(ACT) && !Vact);
	result &= A(mi);
	result &= A(ma);
	result &= A(tr);
	result &= A(dk);
	return result;
}
bool Provider::p63() const				{ // ALL(I, tk_dom) && (!FU(ACT) || !Vact)
	if (!FU(ACT) || !Vact) {
		bool result = true;
		result &= I(mi);
		result &= I(ma);
		result &= I(tr);
		result &= I(dk);
		return result;
	}
	return false;
}
bool Provider::p64() const				{ //FIXME local choice && !Vtca && !TEXP
	return !Vtca && !TEXP;
}
bool Provider::p65() const				{ // ANY(AV, tk_dom)
	if (AV(mi)) return true;
	if (AV(ma)) return true;
	if (AV(tr)) return true;
	if (AV(dk)) return true;
	return false;
}
bool Provider::p66() const				{
	return Vtrr;
}
bool Provider::p67() const				{
	return FU(NR);
}
bool Provider::p68() const				{ // ALL(A, tk_dom) && (!FU(ACT) || !Vact)
	if (!FU(ACT) || !Vact) {
		bool result = true;
		result &= A(mi);
		result &= A(ma);
		result &= A(tr);
		result &= A(dk);
		return result;
	}
	return false;
}
bool Provider::p69() const				{
	return Vcoll;
}

bool Provider::p70() const				{
	return FU(FD);
}
bool Provider::p71() const				{
	return FU(ACT) && Vact && I(dk) && I(mi) && II(ma);
}
bool Provider::p72() const				{
	return FU(ACT) && Vact && A(dk) && A(mi) && AA(ma);
}

bool Provider::p75() const				{
	return (Vcoll && Vdnr) || !Vcoll;
}
bool Provider::p76() const				{ //FIXME CN SPDU is not acceptable to the SPM for transient or persistent reason(see 8.3.5.10)
	return false;
}
bool Provider::p80() const {
	return !FU(DS)
		   || (!FU(SS) && (V(Adi) < V(A)))
		   || ( FU(SS) && (V(Adi) < V(Ar)));
}
bool Provider::p81() const {
	return (!FU(SS) && V(Ado) >= V(A))
		   || ( FU(SS) && V(Ado) >= V(As));
}
bool Provider::p82() const				{
	return FU(DS);
}

bool Provider::p173() const				{ //FIXME FU(SS) && (serial_numbers == V(Ms) - 1, V(Mr))
	return FU(SS);
}
bool Provider::p174() const				{ //FIXME FU(SS) && (serial_numbers == V(Ms), V(Mr) - 1)
	return FU(SS);
}
bool Provider::p175() const				{
	return FU(SS) && (serial_number.operator==(V(Mr) - 1));
}
bool Provider::p176() const				{
	return FU(SS) && (V(Ms) > serial_number && serial_number >= V(As));
}
bool Provider::p177() const				{
	return FU(SS) && (serial_number == V(Mr));
}
bool Provider::p178() const				{
	return FU(SS);
}
bool Provider::p179() const				{
	return FU(SS) && (V(Mr) > serial_number && serial_number >= V(Ar));
}
bool Provider::p180(ResyncOption type) const {
	return (!FU(SS) && (type != r))
		   || (FU(SS)
			   && ((rcv_flow_type == a) || (rcv_flow_type == s))
			   && ((snd_flow_type == a) || (snd_flow_type == s)));
}
bool Provider::p184() const {
	return FU(SS) && Vrsps == no;
}
bool Provider::p185() const {
	return discard_rcv_flow && !p81();
}
bool Provider::p186() const {
	return discard_snd_flow;
}
bool Provider::p187() const {
	return FU(SS)
		   && ((Vrspr != r) || (rcv_flow_serial_number == Vrspnbr))
		   && ((Vrsps != r) || (snd_flow_serial_number == Vrspnbs));
}
bool Provider::p201() const { //FIXME More user data to send;
	throw NotYetImplementedException();
	return false;
}
bool Provider::p202() const { //FIXME End of user data; }
	throw NotYetImplementedException();
	return false;
}
bool Provider::p204() const { //FIXME More than 10 240 octets of SS - user data to be transferred; }
	return false;
}
#undef I
#undef A
#undef II
#undef AA

ReturnCode Provider::ssaplose(int reason, const char* what, const char* fmt)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt);
	}
	return NOTOK;
}
ReturnCode Provider::ssaplose(int reason, const char* what, const char* fmt, const Any& a1)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1);
	}
	return NOTOK;
}
ReturnCode Provider::ssaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::ssaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2, a3);
	}
	sb_logger->error(message);
	return NOTOK;
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const string& fmt) {
	string message;
	if (what != nullptr)
		message += what;
	if (!fmt.empty()) {
		Poco::format(message, fmt);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const char* fmt) {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const string& fmt, const Any& a1)  {
	string message;
	if (what != nullptr)
		message += what;
	if (!fmt.empty()) {
		Poco::format(message, fmt, a1);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const char* fmt, const Any& a1)  {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const string& fmt, const Any& a1, const Any& a2) {
	string message;
	if (what != nullptr)
		message += what;
	if (!fmt.empty()) {
		Poco::format(message, fmt, a1, a2);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2) {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const string& fmt, const Any& a1, const Any& a2, const Any& a3) {
	string message;
	if (what != nullptr)
		message += what;
	if (!fmt.empty()) {
		Poco::format(message, fmt, a1, a2, a3);
	}
	sb_logger->error(message);
	return NOTOK;
}
ReturnCode Provider::spktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3) {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2, a3);
	}
	sb_logger->error(message);
	return NOTOK;
}


ReturnCode Provider::providerException(const SmcException& exception) const {
	int reason = AbortCode::reason_not_specified;
	sb_logger->error(exception.what());
	string message = exception.what();
	sb_logger->SPAbortIndication(reason, 0);
	dumpState();
	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
	disconnectRequest().TDisconnectRequest(reason, sb_called);
	return NOTOK;
}
ReturnCode Provider::serviceException(const SmcException& exception) const {
	sb_logger->error(exception.what());
	string message = exception.what();
	dumpState();
	sb_logger->SPAbortIndication(AbortCode::reason_not_specified, 0);
	abortIndication().SPAbortIndication(AbortCode::invalid_operation, 0, message.size(), message.c_str());
	return NOTOK;
}
ReturnCode Provider::serviceException(const TransitionUndefinedException& exception) const {
#if 0
	string error("error in ");
	if (exception.getState() != nullptr) {
		error += "state ";
		error += exception.getState();
	}
	if (exception.getTransition() != nullptr) {
		error += " on ";
		error += exception.getTransition();
	}
	sb_logger->error(error);
#endif
	sb_logger->SPAbortIndication(AbortCode::invalid_operation, 0);
	abortIndication().SPAbortIndication(AbortCode::invalid_operation, 0);
	return NOTOK;
}
void Provider::dumpState() const {
	string error;
	ostringstream oss;

#define DUMPINT(var)  oss << var;error = #var "\t\t\t= ";error += oss.str();sb_logger->error(error);oss.str("")
#define DUMPBOOL(var) oss << std::boolalpha << var;error = #var "\t\t\t= ";error += oss.str();sb_logger->error(error);oss.str("")
#define DUMPSSN(var) error = #var "\t\t\t= ";error += var.to_string();sb_logger->error(error)


	error = "owned" "\t\t\t= ";
	error += Token::token(sb_owned);
	sb_logger->error(error);
	error = "requirments" "\t\t= ";
	error += sb_requirements.to_string();
	sb_logger->error(error);
	DUMPBOOL(TEXP);
	DUMPBOOL(Vact);
	DUMPBOOL(Vnextact);

	if (FU(SS)) {
		DUMPINT(Vrsps);
		DUMPINT(Vrspr);
		DUMPSSN(Vrspnbs);
		DUMPSSN(Vrspnbr);
	} else {
		DUMPINT(Vrsp);
		DUMPSSN(Vrspnb);
	}

	DUMPBOOL(Vtca);
	DUMPBOOL(Vtrr);
	DUMPBOOL(Vcoll);
	DUMPBOOL(Vdnr);
	DUMPBOOL(SPMwinner);

	DUMPBOOL(Vsc);

	if (FU(SS)) {
		DUMPSSN(V(Ar));
		DUMPSSN(V(As));
		DUMPSSN(V(Ms));
		DUMPSSN(V(Mr));
		DUMPSSN(V(Rs));
		DUMPSSN(V(Rr));
	} else {
		DUMPSSN(V(A));
		DUMPSSN(V(M));
		DUMPSSN(V(R));
	}
	DUMPSSN(V(Ado));
	DUMPSSN(V(Adi));
	DUMPSSN(V(SAs));
}
}
}
}
