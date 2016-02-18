#include "Provider.h"
#include "FSM.h"
using namespace statemap;
namespace ALS {
	namespace TSAP {
		namespace PROV {
			// Static class declarations.
			TSAP::TSAP() :
				OPEN("OPEN", 8),
				AKWAIT("AKWAIT", 0),
				CLOSED("CLOSED", 1),
				CLOSING("CLOSING", 2),
				CLOSING_BOC("CLOSING_BOC", 3),
				CLOSING_BOC_WR("CLOSING_BOC_WR", 4),
				CLOSING_R("CLOSING_R", 5),
				CLOSING_WR("CLOSING_WR", 6),
				ERROR("ERROR", 7),
				OPEN_R("OPEN_R", 9),
				OPEN_WR("OPEN_WR", 10),
				REFWAIT("REFWAIT", 11),
				WBCL("WBCL", 12),
				WBCL_R("WBCL_R", 13),
				WBCL_WR("WBCL_WR", 14),
				WBOC("WBOC", 15),
				WBOC_WR("WBOC_WR", 16),
				WFCC("WFCC", 17),
				WFCC_R("WFCC_R", 18),
				WFNC("WFNC", 19),
				WFNC_R("WFNC_R", 20),
				WFTRESP("WFTRESP", 21),
				WFTRESP_WR("WFTRESP_WR", 22)
			{}
			
			// Provider state --------------------------------
			void ProviderState::AK(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CC(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CC(FSM<Provider>& context, const TPDU::CC* cc) {
			     Default(context);
			}
			void ProviderState::CR(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CR(FSM<Provider>& context, const TPDU::CR* cr) {
			     Default(context);
			}
			void ProviderState::DC(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::DR(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::DT(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::DT(FSM<Provider>& context, BufferPtr& tsdu) {
			     Default(context);
			}
			void ProviderState::EA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::ED(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::ER(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::NCONconf(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::NCONconf(FSM<Provider>& context, Buffer* tdsu) {
			     Default(context);
			}
			void ProviderState::NDISind(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::NRSTind(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::RJ(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TCONreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TCONreq(FSM<Provider>& context, TPDU::CR& tsdu) {
			     Default(context);
			}
			void ProviderState::TCONresp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TCONresp(FSM<Provider>& context, TPDU::CC& tsdu) {
			     Default(context);
			}
			void ProviderState::TDISreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TDISreq(FSM<Provider>& context, TPDU::DR& tsdu) {
			     Default(context);
			}
			void ProviderState::TDTreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TDTreq(FSM<Provider>& context, TPDU::DT& tsdu) {
			     Default(context);
			}
			void ProviderState::TEXreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::Default(FSM<Provider>& context) {
			    throw TransitionUndefinedException(context.getState().getName(), context.getTransition());
			    return;
			}
			void TSAP_CLOSED::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("CLOSED::Entry");
			}
			void TSAP_CLOSED::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("CLOSED::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_CLOSED::TCONreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P0()) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSED);
					(context.getState()).Entry(context);
					ctxt.TDISind();
				} else 
				if (ctxt.P2()) {
					(context.getState()).Exit(context);
					context.setState(context.WFNC);
					(context.getState()).Entry(context);
					ctxt.NCONreq();
				} else 
				if (ctxt.P4()) {
					(context.getState()).Exit(context);
					context.setState(context.WFNC);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TCONreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::TCONreq(FSM<Provider>& context, TPDU::CR& tsdu) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P3()) {
					(context.getState()).Exit(context);
					context.setState(context.WFCC);
					(context.getState()).Entry(context);
					ctxt.CR(tsdu);
				} else 
				{
				     TSAP_Default::TCONreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::CR(FSM<Provider>& context, const TPDU::CR* cr) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P1(cr)) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSED);
					(context.getState()).Entry(context);
					ctxt.DR();
				} else 
				if (!ctxt.P1(cr)) {
					(context.getState()).Exit(context);
					context.setState(context.WFTRESP);
					(context.getState()).Entry(context);
					ctxt.TCONind();
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::CC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.DR();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::AK(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::EA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			void TSAP_ERROR::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("ERROR::Entry");
			}
			void TSAP_ERROR::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("ERROR::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_ERROR::TCONreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				ctxt.Exit("foobar");
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TCONresp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TDISreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NCONconf(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NRSTind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::CR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::CC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::AK(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::EA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::RJ(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				return;
			};
			void TSAP_OPEN::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("OPEN::Entry");
			}
			void TSAP_OPEN::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("OPEN::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDTreq(FSM<Provider>& context, TPDU::DT& tsdu) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.OPEN);
				(context.getState()).Entry(context);
				ctxt.DT(tsdu);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDISreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P5()) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSED);
					(context.getState()).Entry(context);
					ctxt.NDISreq(0);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDISreq(FSM<Provider>& context, TPDU::DR& tsdu) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P7()) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSING);
					(context.getState()).Entry(context);
					ctxt.DR(tsdu);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::NRSTind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind(Disconnect::DR_NETWORK);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::NDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::CR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P9()) {
					(context.getState()).Exit(context);
					context.setState(context.OPEN);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::DT(FSM<Provider>& context, BufferPtr& tsdu) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.OPEN);
				(context.getState()).Entry(context);
				ctxt.TDTind(tsdu);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::DR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P5()) {
					(context.getState()).Exit(context);
					context.setState(context.ERROR);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::DR(context);
				}
				return;
			};
			void TSAP_WFCC::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("WFCC::Entry");
			}
			void TSAP_WFCC::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("WFCC::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_WFCC::TDISreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.P7()) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSED);
					(context.getState()).Entry(context);
					ctxt.NDISreq(0);
				} else 
				if (ctxt.P7()) {
					(context.getState()).Exit(context);
					context.setState(context.WBCL);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::NRSTind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind(Disconnect::DR_NETWORK, "Network reset");
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::NDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::DR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::CC(FSM<Provider>& context, const TPDU::CC* cc) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P8(cc)) {
					(context.getState()).Exit(context);
					context.setState(context.OPEN);
					(context.getState()).Entry(context);
					ctxt.TCONconf();
				} else 
				if (ctxt.P6()&&ctxt.P5()) {
					(context.getState()).Exit(context);
					context.setState(context.CLOSED);
					(context.getState()).Entry(context);
					ctxt.TDISind();
					ctxt.NDISreq(0);
				} else 
				{
				     TSAP_Default::CC(context);
				}
				return;
			};
			void TSAP_WFNC::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("WFNC::Entry");
			}
			void TSAP_WFNC::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("WFNC::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_WFNC::TDISreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFNC::NCONconf(FSM<Provider>& context, Buffer* tdsu) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.WFCC);
				(context.getState()).Entry(context);
				ctxt.CR(tdsu);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFNC::NDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			void TSAP_WFTRESP::Entry(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Entry("WFTRESP::Entry");
			}
			void TSAP_WFTRESP::Exit(FSM<Provider>& context) {
			    Provider& ctxt = context.getOwner();
				ctxt.Exit("WFTRESP::Exit");
			}
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::TCONresp(FSM<Provider>& context, TPDU::CC& tsdu) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.OPEN);
				(context.getState()).Entry(context);
				ctxt.CC(tsdu);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::TDISreq(FSM<Provider>& context, TPDU::DR& tsdu) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.DR(tsdu);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::NRSTind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::NDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.CLOSED);
				(context.getState()).Entry(context);
				ctxt.TDISind();
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::CR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P9()) {
					(context.getState()).Exit(context);
					context.setState(context.WFTRESP);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::DR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.P10()) {
					(context.getState()).Exit(context);
					context.setState(context.ERROR);
					(context.getState()).Entry(context);
					ctxt.DC();
				} else 
				{
				     TSAP_Default::DR(context);
				}
				return;
			};

		}
	}
}
