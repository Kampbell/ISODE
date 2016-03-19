/*
 * Provider.cpp
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */
#include <cstdarg>
#include <memory>
#include <string>
#include <iostream>
using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;

#include "Poco/ClassLibrary.h"
#ifndef POCO_EXPORT_INTERFACE

#define POCO_EXPORT_INTERFACE(cls, itf) \
    pManifest->insert(new Poco::MetaObject<cls, _Base>(itf));

#endif

#include "Poco/Manifest.h"
#include "Poco/SharedLibrary.h"
#include "Poco/Format.h"
#include "Poco/Thread.h"
#include "Poco/Net/NetException.h"
using Poco::SharedLibrary;
using Poco::Thread;

#include "als/base/addr/Selector.h"

#include "als/base/srvc/SSAPServices.h"
#include "als/base/srvc/TSAPService.h"
using ALS::BASE::SRVC::SSAP_SERVICES;
using ALS::BASE::SRVC::TSAPService;

#include "als/tsap/tpdu/TPCI.h"
#include "als/tsap/tpdu/CR.h"
#include "als/tsap/tpdu/CC.h"
#include "als/tsap/tpdu/DT.h"
#include "als/tsap/tpdu/ED.h"
#include "als/tsap/tpdu/EA.h"
#include "als/tsap/tpdu/AK.h"
#include "als/tsap/tpdu/DR.h"
#include "als/tsap/tpdu/DC.h"
#include "als/tsap/tpdu/ER.h"
#include "als/tsap/tpdu/RJ.h"
using ALS::TSAP::TPDU::CR;
using ALS::TSAP::TPDU::CC;
using ALS::TSAP::TPDU::DT;
using ALS::TSAP::TPDU::ED;
using ALS::TSAP::TPDU::EA;
using ALS::TSAP::TPDU::AK;
using ALS::TSAP::TPDU::DR;
using ALS::TSAP::TPDU::DC;
using ALS::TSAP::TPDU::ER;
using ALS::TSAP::TPDU::RJ;

#include "als/nsap/prov/RFC1006.h"
#include "als/nsap/prov/Provider.h"
#include "als/tsap/prov/Provider.h"
#include "als/tsap/user/Linker.h"
#include "als/tsap/Disconnect.h"

#include "als/base/util/NetworkBuffer.h"

using namespace ALS::NSAP::ADDR;
using namespace ALS::TSAP::TPDU;
using namespace ALS::TSAP::USER;

void pocoInitializeLibrary() {
	cout << "ALS::TSAP::PROV::Provider initializing" << endl;
}
void pocoUninitializeLibrary() {
	cout << "ALS::TSAP::PROV::Provider uninitializing" << endl;
}
POCO_BEGIN_NAMED_MANIFEST(ALS_NSAP_USER_Responder, ALS::NSAP::USER::Responder)
POCO_EXPORT_INTERFACE(ALS::TSAP::PROV::Provider, "ALS::NSAP::USER::Responder")
POCO_END_MANIFEST

namespace ALS  {
namespace TSAP {
namespace PROV {
void Provider::reset() {
	;
	tb_state = CLOSED;
	tb_status = 0;
	tb_magic = nullptr;
	tb_data = nullptr;
	tb_cc = 0;
	tb_expedited = false;
	tb_srcref = 0;
	tb_dstref = 0;
	tb_tsdusize = 0;
	tb_tpduslop = TPDU::DT::DT_MAGIC;
	tb_tpdusize = NSAP::PROV::RFC1006::TPDU_MAXLEN;
	tb_sent = 0;
	tb_recv = 0;
	tb_len = 0;
	tb_reason = 0;
//	setDebugFlag(true);
	enterStartState();
}

Provider::Provider() : 
	tb_semaphore(0, 1) {
	tb_logger = new Logger(0);
	reset();
	tsap_user_instance  = nullptr;
	tsap_user_initiator = nullptr;
	tsap_user_responder = nullptr;
	nsap_serv_initiator = nullptr;
	nsap_serv_responder = nullptr;
}
Provider::Provider(ALS::TSAP::USER::Initiator* initiator) :
	tb_semaphore(0, 1) {
	tb_logger = new Logger(0);
	reset();
	tsap_user_instance  = nullptr;
	tsap_user_initiator = initiator;
	tsap_user_responder = nullptr;
	nsap_serv_initiator = nullptr;
	nsap_serv_responder = nullptr;
	tsap_user_dataIndication = initiator;
	tsap_user_disconnectIndication = initiator;

	nsap_serv_initiator = new ALS::NSAP::PROV::Provider(this);
	nsap_data_request = (NSAP::SERV::DataRequest*) nsap_serv_initiator;
	nsap_disconnect_request = (NSAP::SERV::DisconnectRequest*) nsap_serv_initiator;
}
Provider::~Provider() {
	delete nsap_serv_initiator;
	delete tsap_user_instance;
	delete tb_logger;
}
ReturnCode Provider::TConnectRequest(int tpdusize, const TSAPAddr& calling, const TSAPAddr& called, bool expedited, const QualityOfService& qualityOfService, int cc, const byte* data) {
	tb_tpdusize = tpdusize;
	return TConnectRequest(calling, called, expedited, qualityOfService, cc, data);
}
ReturnCode Provider::TConnectRequest(const TSAPAddr& calling, const TSAPAddr& called, bool expedited, const QualityOfService& qualityOfService, int cc, const byte* data) {
	ReturnCode rc = OK;
	QualityOfServiceParameters qosp;
	tb_logger->TConnectRequest(calling, called, expedited, qualityOfService, cc, data);
	int no = 0;
	try {
		if ((no = called.size()) <= 0) {
			return tsaplose(Disconnect::DR_PARAMETER, nullptr, "no NSAP addresses in called parameter");
		}
		if (no > TSAPAddr::NTADDR) {
			return tsaplose(Disconnect::DR_PARAMETER, nullptr, "too many NSAP addresses in called parameter");
		}

		TtoomuchP(cc, data, TS_SIZE);

		if (called.selector().isNotNull() && calling.selector().isNull()) {
			const Selector selector((short)Thread::current()->currentTid());
			((TSAPAddr&)calling).selector(selector);
		}

		tb_calling = calling;
		tb_initiating.selector() = calling.selector();
		tb_called = called;
		tb_responding.selector() = called.selector();
		tb_data = data;
		tb_cc = cc;
		tb_expedited = expedited;

		poco_assert(nsap_serv_initiator != nullptr);
		for (int no = 0; no < called.size(); no++) {
			try {
				tb_logger->information("Connecting %s", called.nsapaddr(no).to_string());
				rc = nsap_serv_initiator->NConnectRequest(calling.nsapaddr(0), called.nsapaddr(no), false, false, qualityOfService, qosp, cc, data);
			} catch (Poco::Net::ConnectionRefusedException& e) {
				tb_logger->notice("Connection refused on %s", called.nsapaddr(no).to_string());
				rc = NOTOK;
			}
			if (rc == OK)
				break;
		}
		if (rc == NOTOK) {
			return tsaplose(Disconnect::DR_NETWORK, nullptr, "Connection refused");
		}

		// 		if 	(la!= null && la != calling.nsapAddrs()) {
		//			NSAPaddr ns;
		// 			ns = calling.nsapAddrs()[0]; // copy
		//			calling.nsapAddrs()[0] = la; // ..
		//			la = ns; // ..
		//			la = calling.nsapAddrs(); // ..
		//		}
		//		state().tb_responding.selector(state().realcalled.selector());
		//
		//		state().tb_responding.ta_present = true;
		//		state().tb_responding.ta_addr = realna; /* copy */
		//		state().tb_tpdusize = SIZE_MAXTP0;//SIZE_DFLT;//
		//
		if (tb_tpdusize == 0)
			tb_tpdusize = SIZE_MAXTP0;
		tb_tsdusize = tb_tpdusize-tb_tpduslop;

		if (!hasStatus(TB_TCP)) {
			expedited = false;
		}
		if (hasStatus(TB_TP0) && cc > 0) {
			return tsaplose(Disconnect::DR_PARAMETER, nullptr, "initial user data not allowed with class 0");
		}

		tb_srcref = (short)Thread::current()->currentTid();
		tb_dstref = 0;

		TPDU::CR tpdu_cr;

		tpdu_cr.dstref(tb_dstref);
		tpdu_cr.srcref(tb_srcref);
		tpdu_cr.klass(TPDU::C::TP0);
		{
			//TODO as tp0 is the only class supported rigth now, TPDU size is set to SIZE_MAXTP0
			// but one extends to support otehr classes over other network with different size
			// as detected/computed below
			// 			int i, j, k;
			// 			i = k = tb_tsdusize + tb_tpduslop;
			// 			for (j = 0; i > 0; j++)
			// 				i >>= 1;
			// 			if (k == (1 << (j-1)))
			// 				j--;
			// 			if (hasState(TB_TCP)) {
			// 				if (j <= SIZE_8K)
			// 					tpci_cr.setTPDUSize(j);
			// 				} else {
			// 					if (j > SIZE_MAXTP0) {
			// 						j = SIZE_MAXTP0;
			// 						tb_tsdusize = (1 << j)-tb_tpduslop;
			// 					}
			// 					if (j != SIZE_DFLT)
			// 						tpci_cr.setTPDUSize(j);
			// 			}
			if (tb_tpdusize != SIZE_DFLT)
				tpdu_cr.tpdusize(tb_tpdusize);
		}
		tpdu_cr.calling(tb_initiating.selector().length(), tb_initiating.selector().literal());
		tpdu_cr.called(tb_responding.selector().length(), tb_responding.selector().literal());

		if (expedited) {
			setStatus(TB_EXPD);
			tpdu_cr.addOption(TPDU::C::UseTransportExpedited);
		}
		FSM<Provider>::TCONreq(tpdu_cr);
		tb_semaphore.wait();
	} catch (const statemap::SmcException& e) {
		rc = serviceException(e);
	} catch (const Poco::Exception& e) {
		tb_logger->log(e);
		rc =  tsaplose(Disconnect::DR_PARAMETER, nullptr, e.what());
	} catch (const std::exception& e) {
		tb_logger->error(e.what());
		rc =  tsaplose(Disconnect::DR_PARAMETER, nullptr, e.what());
	} catch (...) {
		tb_logger->error("unknown exception", __FILE__, __LINE__);
		rc = tsaplose(Disconnect::DR_PARAMETER, nullptr, "unknown exception");
	}
	return rc;
}
ReturnCode Provider::TConnectResponse(const TSAPAddr& responding, bool expedited, const QualityOfService& qualityOfService, int cc, const byte* data) {
	ReturnCode rc = OK;
	try {
		tb_logger->TConnectResponse(responding, expedited, qualityOfService, cc, data);

		if (isConnected()) {
			return tsaplose(Disconnect::DR_PARAMETER, nullptr, "invalid transport layer");
		}

		TPDU::CC tpdu_cc;

		tpdu_cc.dstref(tb_dstref);
		tpdu_cc.srcref(tb_srcref);
		tpdu_cc.klass(CC::TP0);

#if 0
		int i, j, k;
		i = k = tb_tsdusize + tb_tpduslop;
		for (j = 0; i > 0; j++)
			i >>= 1;

		if (k == (1 << (j-1)))
			j--;

		if (hasState(TB_TCP)) {
			if (j <= SIZE_8K) {
				tpdu_cc.tpdusize(j);
			}
		} else {
			if (j > SIZE_MAXTP0) {
				j = SIZE_MAXTP0;
				tb_tsdusize = (1 << j)-tb_tpduslop;
			}

			if (j != SIZE_DFLT) {
				tpdu_cc.tpdusize(j);
			}
		}
#else
		if (hasStatus(TB_TCP)) {
			if (tb_tpdusize <= SIZE_8K) {
				tpdu_cc.tpdusize(tb_tpdusize);
			}
		} else {
			if (tb_tpdusize > SIZE_MAXTP0) {
				tb_tpdusize = SIZE_MAXTP0;
				tb_tsdusize = tb_tpdusize-tb_tpduslop;
			}

			if (tb_tpdusize != SIZE_DFLT) {
				tpdu_cc.tpdusize(tb_tpdusize);
			}
		}

#endif
		FSM<Provider>::TCONresp(tpdu_cc);
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::TDataRequest(NetworkBuffer* tsdu) {
	ReturnCode rc = OK;
	try {
		tb_logger->TDataRequest(tsdu);

		TPDU::DT tpdu_dt;
		tpdu_dt.setEOT();
		tpdu_dt.setData(tsdu);
		FSM<Provider>::TDTreq(tpdu_dt);
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::TDataRequest(int cc, const byte* data) {
	ReturnCode rc = OK;
	try {
		tb_logger->TDataRequest(cc, data);
		int remain = cc;
		int sended = 0;
		for (;;) {
			if (remain <= tb_tsdusize)
				break;
			unique_ptr<NetworkBuffer> tsdu(new NetworkBuffer(tb_tsdusize));
			tsdu->putBytes(tb_tsdusize, data + sended);
			tsdu->flip();
			TPDU::DT tpdu_dt;
			tpdu_dt.setData(tsdu.get());
			FSM<Provider>::TDTreq(tpdu_dt);
			sended += tb_tsdusize;
			remain -= tb_tsdusize;
		}
		unique_ptr<NetworkBuffer> tsdu(new NetworkBuffer(remain));
		tsdu->putBytes(remain, data + sended);
		tsdu->flip();
		TPDU::DT tpdu_dt;
		tpdu_dt.setEOT();
		tpdu_dt.setData(tsdu.get());
		FSM<Provider>::TDTreq(tpdu_dt);
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::TExpeditedDataRequest(int cc, const byte* data) {
	ReturnCode rc = OK;
	TtoomuchP (cc, data, TX_SIZE);
	try {
		tb_logger->TExpeditedDataRequest(cc, data);
		FSM<Provider>::TEXreq(cc, data);
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::TDisconnectRequest(int reason, const TSAPAddr& responding, int cc, const byte* data) {
	tb_logger->TDisconnectRequest(reason, responding, cc, data);
	ReturnCode rc = OK;
	try {
		FSM<Provider>::TDISreq();
	} catch (statemap::SmcException& e) {
		rc = serviceException(e);
	}
	return rc;
}
ReturnCode Provider::NResetIndication(const NSAPAddr& originator, int reason) {
	return DONE;
}
ReturnCode Provider::NResetConfirmation() {
	return DONE;
}
ReturnCode Provider::NConnectIndication(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	poco_assert(nsap_serv_responder != nullptr);
	nsap_data_request = (NSAP::SERV::DataRequest*) nsap_serv_responder;
	nsap_disconnect_request = (NSAP::SERV::DisconnectRequest*) nsap_serv_responder;

	return DONE;
}
ReturnCode Provider::NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	ReturnCode rc = DONE;
	try {
		FSM<Provider>::NCONconf();
	} catch (statemap::SmcException& e) {
		rc = providerException(e);
	}
	return rc;
}
ReturnCode Provider::NDisconnectIndication() {
	ReturnCode rc = DONE;
	try {
		FSM<Provider>::NDISind();
	} catch (statemap::SmcException& e) {
		rc = providerException(e);
	}
	return rc;
}
ReturnCode Provider::NDataIndication(const SharedNetworkBuffer& nsdu) {
	ReturnCode rc = DONE;
	try {
		unique_ptr<TPCI> tb_tpdu(TPCI::decodeTPDU(nsdu.get()));

		if (tb_tpdu.get() == nullptr) {
			rc = tpktlose(Disconnect::DR_PROTOCOL, nullptr,"transport protocol mangled: not expecting a empty TPDU" );
			return NOTOK;
		}
		switch (tb_tpdu->code()) {
		case TPCI::TPDU_CR: {
			const TPDU::CR* tpdu_cr = (TPDU::CR*)tb_tpdu.get();

			//FIXME
			//			if (CR_CLASS (t) != CR_CLASS_TP0) {
			//				if (t->t_cr.cr_alternate & (ALT_TP0 | ALT_TP1))
			//					t->t_cr.cr_class = CR_CLASS_TP0;
			//				else { rc = tpktlose (td, DR_CONNECT, nullptr, "only class 0 supported, not 0x%x", CR_CLASS (t)); goto
			// out; } }

			tb_srcref = (short)Thread::current()->currentTid();
			tb_dstref = tpdu_cr->srcref();

			tb_tpdusize = tpdu_cr->tpdusize();
			if (!hasStatus(TB_TCP) || tpdu_cr->tpdusize() >= 0) {
				if (tpdu_cr->tpdusize() == 0) {
					tb_tpdusize = SIZE_DFLT;
				} else

					if (tpdu_cr->tpdusize() > SIZE_MAXTP0 && !hasStatus(TB_TCP)) {
						tb_tpdusize = SIZE_MAXTP0;
					}
			}

			tb_tsdusize = tb_tpdusize-tb_tpduslop;

			if ((tpdu_cr->callinglen()) > 0) {
				tb_initiating.selector() = Selector(tpdu_cr->callinglen(), tpdu_cr->calling());
			}

			if ((tpdu_cr->calledlen()) > 0) {
				tb_responding.selector() = Selector(tpdu_cr->calledlen(), tpdu_cr->called());
			}

			if (tpdu_cr->hasTransportOption(C::UseTransportExpedited) && hasStatus(TB_TCP)) {
				setStatus(TB_EXPD);
			}
			/* initial DATA from peer */
			byte data[TS_SIZE];
			byte cc = 0;

			TSAPAddr ts_calling(tb_initiating);// address of peer calling
			TSAPAddr ts_called(tb_responding); // address of peer called

			int tsdusize = tb_tsdusize; // largest atomic TSDU
			QualityOfService qualityOfService = tb_qos; // quality of service

#if 0
			if (data != nullptr && cc > 0) {
				NetworkBuffer* buffer = new NetworkBuffer(cc);
				buffer->putBytes(cc, data);
				buffer->flip();
				if (tb_qbuf != nullptr)
					tb_qbuf->add(buffer);
			}
#endif
			if (tb_services == nullptr) {
				return tpktlose(Disconnect::DR_CONNECT, nullptr, "TSAP services not set");
			}
			const TSAPService* service = nullptr;
			service = (const TSAPService*)tb_services->getServiceBySelector(tb_responding.selector());
			if (service == nullptr) {
				return tpktlose(Disconnect::DR_CONNECT, nullptr, "unknown TSAP service with selector %s", tb_responding.selector().to_string());
			}
			string path(service->library());
			path.append(SharedLibrary::suffix()); 
			tb_UserResponserLoader.loadLibrary(path, "ALS_TSAP_USER_Responder");
			tsap_user_responder = tb_UserResponserLoader.create("ALS::TSAP::USER::Responder");
			if (tsap_user_responder == nullptr) {
				return tpktlose(Disconnect::DR_CONNECT, nullptr, "server is missing ALS::TSAP::USER::Responder as base class");
			}
			tsap_user_responder->TSetSSAPServices(&SSAP_SERVICES);

			USER::Linker* linker = dynamic_cast<USER::Linker*>(tsap_user_responder);
			if (linker == nullptr) {
				return NOTOK;
			}
			linker->provider() = this;
			tsap_user_dataIndication = tsap_user_responder;
			tsap_user_disconnectIndication = tsap_user_responder;
			FSM<Provider>::CR(tpdu_cr);
		}
		break;

		case TPCI::TPDU_CC: {
			const TPDU::CC* tpdu_cc = (TPDU::CC*)tb_tpdu.get();
#if 0
			if (isConnected()) {
				rc = tpktlose(td, DR_PROTOCOL, "transport protocol mangled: not expecting 0x%x", tpdu.tp_code());
				return rc;
			}

			TPCI_CC cc = (TPCI_CC) tpdu;

			if (cc.CC_CLASS() != CR_CLASS_TP0) {
				rc = tpktlose(td, DR_PROTOCOL, "proposed class 0, got back 0x%x", cc.CC_CLASS());
				return rc;
			}

			if (state().tb_srcref != cc.getDestinationReference()) {
				rc = tpktlose(td, DR_MISMATCH, "sent srcref of 0x%x, got 0x%x", state().tb_srcref, cc
					.getDestinationReference());
				return rc;
			}

			state().tb_dstref = cc.getSourceReference();

			if (!hasState(TB_TCP) || cc.getTPDUSize() >= 0) {
				if (cc.getTPDUSize() == 0) {
					cc.setTPDUSize(SIZE_DFLT);
				} else

				if (cc.getTPDUSize() > SIZE_MAXTP0 && !hasState(TB_TCP)) {
					cc.setTPDUSize(SIZE_MAXTP0);
				}

				state().tb_tpdusize = cc.getTPDUSize();
				state().tb_tsdusize = state().tb_tpdusize-state().tb_tpduslop;
			}

			if ((len = cc.getCalledLen()) > 0) {
				if (len > state().tb_responding.selector().sizeof()) {
					len = state().tb_responding.selector().sizeof();
				}

				state().tb_responding.selector(new Selector(cc.getCalled()));
			}

			TSAPAddr responding = new TSAPAddr();
			boolean expedited;
			int tsdusize; //largest atomic TSDU
			QualityOfService qos;

			copyTSAPaddrX(state().tb_responding, responding);
			if (!cc.useTransportExpedited() || !hasState(TB_TCP)) {
				remState(TB_EXPD);
			}

			expedited = hasState(TB_EXPD) ? true : false;
			tsdusize = state().tb_tsdusize;
			qos = state().tb_qos;

			byte[] datas = null;
			if (tpdu.tp_udata != null) {
				datas = copyTSAPdata(tpdu.tp_udata, tpdu.tp_ulen);
			}
			setState(TB_CONN);

			if (logger() != null) {
				logger().TConnectConfimation(qos, responding, expedited, datas);
			}
			TSAPServices services = new TSAPProvider(state(), nsapServices);
			tsapStacker.setTSAPServices(services);

			rc = tsapInitiations.TConnectConfirmation(tsdusize, qos, responding, expedited, datas);

			tsapIndicator = new TSAPIndicator(this, tsapStacker);
			NSAPIndications nsapIndications = tsapIndicator;
			nsapInitiator.setNSAPIndications(nsapIndications);
			tsapIndicator.setTSAPIndications(tsapStacker.getTSAPIndications());


#endif
			FSM<Provider>::CC(tpdu_cc);
		}
		break;

		case TPCI::TPDU_DT: {
			const TPDU::DT* tpdu_dt = (TPDU::DT*)tb_tpdu.get();
#if 0
			if (!isConnected()) {
				tpktlose(td, DR_PROTOCOL, "transport protocol mangled: expecting 0x%x, got 0x%x", TPCIBase.TPDU_CC,
						 tpdu.tp_code());
				return NOTOK;
			}
			TPCI_DT dt = (TPCI_DT) tpdu;
			if (state().tb_qbuf == nullptr)
				state().tb_qbuf = new TSAPData();

			state().tb_qbuf.addLast(dt.tp_udata);
			state().tb_len += dt.tp_ulen;

			if (!dt.isEOT()) {
				//					if (synchrone()) {
				//						nsdu = nsap().NReadNSDU(INFINITE, na);
				//						continue;
				//					} else {
				return DONE;
				//					}
			}
			if (logger() != nullptr) {
				logger().TDataIndication(state().tb_qbuf);
			}
			rc = indications().TDataIndication(state().tb_qbuf);
			state().tb_qbuf = nullptr;
			state().tb_len = 0;
#endif
			if (!tb_qbuf)
				tb_qbuf = nsdu;
			else
				tb_qbuf.append(nsdu);
			if (!tpdu_dt->isEOT()) {
				return DONE;
			}
			FSM<Provider>::DT(tb_qbuf);
			tb_qbuf.reset();
		}
		break;

		case TPCI::TPDU_ED: {
			const TPDU::ED* tpdu_ed = (TPDU::ED*)tb_tpdu.get();
#if 0
			if (!isConnected()) {
				rc = tpktlose(td, DR_PROTOCOL, "transport protocol mangled: expecting 0x%x, got 0x%x",
							  TPCIBase.TPDU_CC, tpdu.tp_code());
				return rc;
			}
			TPCI_ED ed = (TPCI_ED) tpdu;
			ByteBuffer tex = nullptr;
			//tex.tex_cc = ed.tp_ulen;
			if (ed.tp_udata != nullptr) {
				tex = ed.tp_udata;
			}

			if (logger() != nullptr) {
				logger().TExpeditedDataIndication(tex);
			}
			rc = indications().TExpeditedDataIndication(tex);
#endif
			FSM<Provider>::ED(nsdu);
			tb_qbuf.reset();
		}
		break;

		case TPCI::TPDU_DR: {
			const TPDU::DR* tpdu_dr = (TPDU::DR*)tb_tpdu.get();
#if 0
			if (!isConnected()) {
				rc = tpktlose(td, DR_PROTOCOL, "transport protocol mangled: expecting 0x%x, got 0x%x",
							  TPCIBase.TPDU_CC, tpdu.tp_code());
				return NOTOK;
			}
			TPCI_DR dr = (TPCI_DR) tpdu;

			td.td_reason = dr.reason();
			if (logger() != nullptr) {
				logger().TDisconnectIndication(dr.reason(), dr.tp_udata);
			}
			rc = indications().TDisconnectIndication(dr.reason(), dr.tp_udata);
			state().remState(TB_CONN);
#endif
			FSM<Provider>::DR();
		}
		break;

		case TPCI::TPDU_EA: {
			const TPDU::EA* tpdu_ea = (TPDU::EA*)tb_tpdu.get();
			FSM<Provider>::EA();
		}
		break;

		case TPCI::TPDU_DC: {
			const TPDU::DC* tpdu_dc = (TPDU::DC*)tb_tpdu.get();
#if 0
			if (!isConnected()) {
				rc = tpktlose(td, DR_PROTOCOL, "transport protocol mangled: expecting 0x%x, got 0x%x",
							  TPCIBase.TPDU_CC, tpdu.tp_code());
				return NOTOK;
			}
			TPCI_DC dc = (TPCI_DC) tpdu;

			td.td_reason = dc.reason();
			if (logger() != nullptr) {
				logger().TDisconnectConfirmation(dc.reason(), dc.tp_udata);
			}
			rc = DONE;
			state().release(rc);
#endif
			FSM<Provider>::DC();
		}
		break;

		case TPCI::TPDU_ER: {
			const TPDU::ER* tpdu_er = (TPDU::ER*)tb_tpdu.get();
#if 0
			if (!isConnected()) {
				tpktlose(td, DR_PROTOCOL, "transport protocol mangled: expecting 0x%x, got 0x%x", TPCIBase.TPDU_CC,
						 tpdu.tp_code());
				return NOTOK;
			}
			TPCI_ER er = (TPCI_ER) tpdu;

			switch (er.reject()) {
			case ER_REJ_NOTSPECIFIED:
			default:
				td.td_reason = DR_UNKNOWN;
				break;

			case ER_REJ_CODE:
			case ER_REJ_TPDU:
			case ER_REJ_VALUE:
				td.td_reason = DR_PROTOCOL;
				break;
			}

			td.td_cc = 0;
			rc = indications().TDisconnectIndication(0, nullptr);
			state().release(rc);
#endif
			FSM<Provider>::ER();
		}
		break;

		default:
			rc = tpktlose(Disconnect::DR_PROTOCOL, nullptr,"transport protocol mangled: not expecting 0x%x", tb_tpdu->code());
			return NOTOK;
		}
	} catch (statemap::SmcException& e) {
		rc = providerException(e);
	}
	return rc;
}

// ---------------------------------------------------------------------------------
//
// TSAP FSM actions see FSM.sm and ITU-T X.224
// outgoing events
//

// ---------------------------------------------------------------------------------
// TS-provider 	T-CONNECT indication primitive
void Provider::TCONind() {
	tb_logger->TConnectIndication(tb_calling, tb_called, hasStatus(TB_EXPD), tb_tsdusize, tb_qos);
	poco_assert(tsap_user_responder != nullptr);
	tsap_user_responder->TConnectIndication(tb_calling, tb_called, hasStatus(TB_EXPD), tb_tsdusize, tb_qos);
}
// ---------------------------------------------------------------------------------
// TS-provider 	T-CONNECT confirm primitive
void Provider::TCONconf() {
	tb_logger->TConnectConfirmation(tb_responding, hasStatus(TB_EXPD), tb_qos, tb_tsdusize);
	poco_assert(tsap_user_initiator != nullptr);
	tsap_user_initiator->TConnectConfirmation(tb_responding, hasStatus(TB_EXPD), tb_qos, tb_tsdusize);
	tb_semaphore.set();
}
// ---------------------------------------------------------------------------------
// TS-provider 	T-DATA indication primitive
void Provider::TDTind(const SharedNetworkBuffer& tsdu) {
	tb_logger->TDataIndication(tsdu);
	poco_assert(tsap_user_dataIndication != nullptr);
	tsap_user_dataIndication->TDataIndication(tsdu);
}
// ---------------------------------------------------------------------------------
// TS-provider 	T-EXPEDITED DATA indication primitive
void Provider::TEXind(const SharedNetworkBuffer& tsdu) {
	tb_logger->TExpeditedDataIndication(tsdu);
	poco_assert(tsap_user_dataIndication != nullptr);
	tsap_user_dataIndication->TExpeditedDataIndication(tsdu);
}
// ---------------------------------------------------------------------------------
// TS-provider 	T-DISCONNECT indication primitive
void Provider::TDISind() {
	string message;
	tb_logger->TDisconnectIndication(Disconnect::DR_NORMAL, message);
	poco_assert(tsap_user_disconnectIndication != nullptr);
	tsap_user_disconnectIndication->TDisconnectIndication(Disconnect::DR_NORMAL, message);
}
// ---------------------------------------------------------------------------------
// TS-provider 	T-DISCONNECT indication primitive
void Provider::TDISind(int reason, const char* message) {
	poco_assert(tsap_user_disconnectIndication != nullptr);
	if (message == nullptr) {
		tb_logger->TDisconnectIndication(reason, "");
		tsap_user_disconnectIndication->TDisconnectIndication(reason, "");
	} else {
		size_t cc = strlen(message);
		tb_logger->TDisconnectIndication(reason, message);
		tsap_user_disconnectIndication->TDisconnectIndication(reason, message);
	}
}
// ---------------------------------------------------------------------------------
// NS-user 		N-DISCONNECT Request primitive
void Provider::NDISreq(int reason, int cc, const byte* data) {
	nsap_disconnect_request->NDisconnectRequest(reason, tb_called.nsapaddr(0), cc, data);
}
// ---------------------------------------------------------------------------------
// NS-user 		N-RESET Response primitive
void Provider::NRSTresp() {
}
// ---------------------------------------------------------------------------------
// NS-user 		N-CONNECT Request primitive
void Provider::NCONreq() {
}
// ---------------------------------------------------------------------------------
// TPDU 			Connection Request
void Provider::CR(NetworkBuffer* cr) {
}
// ---------------------------------------------------------------------------------
// TPDU 			Connection Request
void Provider::CR(TPDU::CR& cr) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	cr.encode(nsdu);
	poco_assert(nsap_serv_initiator != nullptr);
	nsap_serv_initiator->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Connection confirm
void Provider::CC(TPDU::CC& cc) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	cc.encode(nsdu);
	poco_assert(nsap_serv_responder != nullptr);
	nsap_serv_responder->NDataRequest(nsdu.get());
}
// TPDU 			Disconnect Request
void Provider::DR() {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	TPDU::DR dr;
	dr.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Disconnect Request
void Provider::DR(TPDU::DR& dr) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	dr.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU Disconnect confirm
void Provider::DC() {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	TPDU::DC dc;
	dc.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU Disconnect confirm
void Provider::DC(TPDU::DC& dc) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	dc.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Data Acknowledgement
void Provider::AK(TPDU::AK& ak) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	ak.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Expedited Data Acknowledgement
void Provider::EA(TPDU::EA& ea) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	ea.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Data
void Provider::DT(TPDU::DT& dt) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	dt.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Expedited Data
void Provider::ED(int cc, const byte* data) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	TPDU::ED ed;
	ed.setData(cc, data);
	ed.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			TPDU Error
void Provider::ER() {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	TPDU::ER er;
	er.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
// ---------------------------------------------------------------------------------
// TPDU 			Reject
void Provider::RJ() {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	TPDU::RJ rj;
	rj.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
}
void Provider::Entry(const char* s) {
	tb_logger->debug(s);
}
void Provider::Exit(const char* s) {
	tb_logger->debug(s);
}

// ---------------------------------------------------------------------------------
//
// TSAP FSM Predicates
//
// ------------------------------------------------
bool Provider::P0() {		// T-CONNECT request unacceptable
	return false;
}

// ------------------------------------------------
bool Provider::P1(const TPDU::CR* tb_tpdu) {		// Unacceptable CR TPDU
	if (tb_tpdu == nullptr)
		return true;
	if (tb_tpdu->code() == TPCI::TPDU_CR)
		return false;
	return true;
}

// ------------------------------------------------
bool Provider::P2() {		// No network connection available
	return false;
}

// ------------------------------------------------
bool Provider::P3() {		// Network connection available and open
	return true;
}

// ------------------------------------------------
bool Provider::P4() {		// Network connection available and open in progress
	return false;
}

// ------------------------------------------------
bool Provider::P5() {		// Class in class 0 (class selected in CC)
	return true;
}

// ------------------------------------------------
bool Provider::P6() {		// Unacceptable CC
	return false;
}

// ------------------------------------------------
bool Provider::P7() {		// Class is class 2
	return false;
}

// ------------------------------------------------
bool Provider::P8(const TPDU::CC* cc) {		// Acceptable CC
	if (cc == nullptr)
		return false;
	if (cc->code() == TPCI::TPDU_CC)
		return true;
	return false;
}

// ------------------------------------------------
bool Provider::P9() {		// Class 4 CR
	return false;
}

// ------------------------------------------------
bool Provider::P10() {		// Local choice
	return false;
}


ReturnCode Provider::tsapPsig() const {
	if (!isConnected()) {
		return tsaplose(Disconnect::DR_OPERATION, nullptr, "transport layer not connected");
	}
	return OK;
}

ReturnCode Provider::TmissingP(void* p, const string& s)  const {
	if (p == nullptr) {
		return tsaplose(Disconnect::DR_PARAMETER, nullptr, "missing mandatory parameter: %s" , s);
	}
	return OK;
}

ReturnCode Provider::TtoomuchP(int length, const byte* b, int max)  const {
	if (b != nullptr && length > max) {
		return tsaplose(Disconnect::DR_PARAMETER, nullptr, "too much %d user data > %d", length, max);
	}
	return OK;
}
static int countPercent(const char* fmt) {
	int count = 0;

	for (int i = 0; i < strlen(fmt); i++)
		if (fmt[i] == '%') count++;

	return count;
}
ReturnCode Provider::tsaplose(int reason, const char* what, const char* fmt)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		message += fmt;
	}
	tb_logger->error(message);
	tsap_user_disconnectIndication->TDisconnectIndication(reason, message);
	return NOTOK;
}
ReturnCode Provider::tsaplose(int reason, const char* what, const char* fmt, const Any& a1)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1);
	}
	tb_logger->error(message);
	tsap_user_disconnectIndication->TDisconnectIndication(reason, message);
	return NOTOK;
}
ReturnCode Provider::tsaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2)  const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2);
	}
	tb_logger->error(message);
	tsap_user_disconnectIndication->TDisconnectIndication(reason, message);
	return NOTOK;
}
ReturnCode Provider::tsaplose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3) const {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2, a3);
	}
	tb_logger->error(message);
	tsap_user_disconnectIndication->TDisconnectIndication(reason, message);
	return NOTOK;
}
ReturnCode Provider::tpktlose(int reason, const char* what, const char* fmt)  {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		message += fmt;
	}
	tb_logger->error(message);
	TPDU::DR dr;
	dr.srcref() = tb_srcref;
	dr.dstref() = tb_dstref;
	dr.reason() = reason;
	dr.setData(message);
	disconnect(dr);
	return NOTOK;
}
ReturnCode Provider::tpktlose(int reason, const char* what, const char* fmt, const Any& a1)   {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1);
	}
	tb_logger->error(message);
	TPDU::DR dr;
	dr.srcref() = tb_srcref;
	dr.dstref() = tb_dstref;
	dr.reason() = reason;
	dr.setData(message);
	disconnect(dr);
	return NOTOK;
}
ReturnCode Provider::tpktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2)   {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2);
	}
	tb_logger->error(message);
	TPDU::DR dr;
	dr.srcref() = tb_srcref;
	dr.dstref() = tb_dstref;
	dr.reason() = reason;
	dr.setData(message);
	disconnect(dr);
	return NOTOK;
}
ReturnCode Provider::tpktlose(int reason, const char* what, const char* fmt, const Any& a1, const Any& a2, const Any& a3)   {
	string message;
	if (what != nullptr)
		message += what;
	if (fmt != nullptr) {
		Poco::format(message, fmt, a1, a2, a3);
	}
	tb_logger->error(message);
	TPDU::DR dr;
	dr.srcref() = tb_srcref;
	dr.dstref() = tb_dstref;
	dr.reason() = reason;
	dr.setData(message);
	disconnect(dr);
	return NOTOK;
}
void Provider::disconnect(TPDU::DR& dr) {
	unique_ptr<NetworkBuffer>	nsdu((nullptr_t)nullptr);
	dr.encode(nsdu);
	nsap_data_request->NDataRequest(nsdu.get());
	nsap_disconnect_request->NDisconnectRequest(0, tb_responding.addr());
	setState(TSAP::CLOSED);
}

ReturnCode Provider::providerException(const statemap::SmcException& exception) const {
	int reason = 0;
	tb_logger->error(exception.what());
	if ( typeid(exception)==typeid(statemap::TransitionUndefinedException)) {
		const statemap::TransitionUndefinedException& tue = static_cast<const statemap::TransitionUndefinedException&>(exception);
		transitionUndefinedException(tue);
	}
	string message = exception.what();
//	tb_logger->SPAbortIndication(reason, 0);
//	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
//	disconnectRequest().TDisconnectRequest(reason, sb_called);
	return NOTOK;
}
ReturnCode Provider::serviceException(const statemap::SmcException& exception) const {
	int reason = 0;
	tb_logger->error(exception.what());
	if ( typeid(exception)==typeid(statemap::TransitionUndefinedException)) {
		const statemap::TransitionUndefinedException& tue = static_cast<const statemap::TransitionUndefinedException&>(exception);
		transitionUndefinedException(tue);
	}
	string message = exception.what();
//	tb_logger->SPAbortIndication(reason, 0);
//	abortIndication().SPAbortIndication(reason, 0, message.size(), message.c_str());
	return NOTOK;
}
void Provider::transitionUndefinedException(const statemap::TransitionUndefinedException& tue) const {
	string error("error in ");
	if (tue.getState() != nullptr) {
		error += "state ";
		error += tue.getState();
	}
	if (tue.getTransition() != nullptr) {
		error += " on ";
		error += tue.getTransition();
	}
	tb_logger->error(error);
}
}
}
}
