#include "Provider.h"
#include "FSM.h"
using namespace statemap;
namespace ALS {
	namespace TSAP {
		namespace PROV {
			// Static class declarations.
			TSAP_AKWAIT		TSAP::AKWAIT("AKWAIT", 0);
			TSAP_CLOSED		TSAP::CLOSED("CLOSED", 1);
			TSAP_CLOSING		TSAP::CLOSING("CLOSING", 2);
			TSAP_CLOSING_BOC		TSAP::CLOSING_BOC("CLOSING_BOC", 3);
			TSAP_CLOSING_BOC_WR		TSAP::CLOSING_BOC_WR("CLOSING_BOC_WR", 4);
			TSAP_CLOSING_R		TSAP::CLOSING_R("CLOSING_R", 5);
			TSAP_CLOSING_WR		TSAP::CLOSING_WR("CLOSING_WR", 6);
			TSAP_ERROR		TSAP::ERROR("ERROR", 7);
			TSAP_OPEN		TSAP::OPEN("OPEN", 8);
			TSAP_OPEN_R		TSAP::OPEN_R("OPEN_R", 9);
			TSAP_OPEN_WR		TSAP::OPEN_WR("OPEN_WR", 10);
			TSAP_REFWAIT		TSAP::REFWAIT("REFWAIT", 11);
			TSAP_WBCL		TSAP::WBCL("WBCL", 12);
			TSAP_WBCL_R		TSAP::WBCL_R("WBCL_R", 13);
			TSAP_WBCL_WR		TSAP::WBCL_WR("WBCL_WR", 14);
			TSAP_WBOC		TSAP::WBOC("WBOC", 15);
			TSAP_WBOC_WR		TSAP::WBOC_WR("WBOC_WR", 16);
			TSAP_WFCC		TSAP::WFCC("WFCC", 17);
			TSAP_WFCC_R		TSAP::WFCC_R("WFCC_R", 18);
			TSAP_WFNC		TSAP::WFNC("WFNC", 19);
			TSAP_WFNC_R		TSAP::WFNC_R("WFNC_R", 20);
			TSAP_WFTRESP		TSAP::WFTRESP("WFTRESP", 21);
			TSAP_WFTRESP_WR		TSAP::WFTRESP_WR("WFTRESP_WR", 22);
			
			// Provider state --------------------------------
			void ProviderState::AK(FSM& context) {
			     Default(context);
			}
			void ProviderState::CC(FSM& context) {
			     Default(context);
			}
			void ProviderState::CR(FSM& context) {
			     Default(context);
			}
			void ProviderState::DC(FSM& context) {
			     Default(context);
			}
			void ProviderState::DR(FSM& context) {
			     Default(context);
			}
			void ProviderState::DT(FSM& context) {
			     Default(context);
			}
			void ProviderState::DT(FSM& context, shared_ptr<Buffer>& tsdu) {
			     Default(context);
			}
			void ProviderState::EA(FSM& context) {
			     Default(context);
			}
			void ProviderState::ED(FSM& context) {
			     Default(context);
			}
			void ProviderState::ER(FSM& context) {
			     Default(context);
			}
			void ProviderState::NCONconf(FSM& context) {
			     Default(context);
			}
			void ProviderState::NCONconf(FSM& context, Buffer* tdsu) {
			     Default(context);
			}
			void ProviderState::NDISind(FSM& context) {
			     Default(context);
			}
			void ProviderState::NRSTind(FSM& context) {
			     Default(context);
			}
			void ProviderState::RJ(FSM& context) {
			     Default(context);
			}
			void ProviderState::TCONreq(FSM& context) {
			     Default(context);
			}
			void ProviderState::TCONreq(FSM& context, TPDU::CR& tsdu) {
			     Default(context);
			}
			void ProviderState::TCONresp(FSM& context) {
			     Default(context);
			}
			void ProviderState::TCONresp(FSM& context, TPDU::CC& tsdu) {
			     Default(context);
			}
			void ProviderState::TDISreq(FSM& context) {
			     Default(context);
			}
			void ProviderState::TDISreq(FSM& context, TPDU::DR& tsdu) {
			     Default(context);
			}
			void ProviderState::TDTreq(FSM& context) {
			     Default(context);
			}
			void ProviderState::TDTreq(FSM& context, TPDU::DT& tsdu) {
			     Default(context);
			}
			void ProviderState::TEXreq(FSM& context) {
			     Default(context);
			}
			void ProviderState::Default(FSM& context) {
			    throw TransitionUndefinedException(context.getState().getName(), context.getTransition());
			    return;
			}
			
			// ----------------------------------------------------
			void TSAP_CLOSED::TCONreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TCONreq");
				
				if (ctxt.P0()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSED);
						ctxt.TDISind();
					} catch (...) {
						context.setState(TSAP::CLOSED);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				if (ctxt.P2()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::WFNC);
						ctxt.NCONreq();
					} catch (...) {
						context.setState(TSAP::WFNC);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				if (ctxt.P4()) {
					(context.getState()).Exit(context);
					context.setState(TSAP::WFNC);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TCONreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::TCONreq(FSM& context, TPDU::CR& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TCONreq");
				
				if (ctxt.P3()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::WFCC);
						ctxt.CR(tsdu);
					} catch (...) {
						context.setState(TSAP::WFCC);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TCONreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::CR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CR");
				
				if (ctxt.P1()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSED);
						ctxt.DR();
					} catch (...) {
						context.setState(TSAP::CLOSED);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				if (!ctxt.P1()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::WFTRESP);
						ctxt.TCONind();
					} catch (...) {
						context.setState(TSAP::WFTRESP);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DR");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DC(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DC");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::CC(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CC");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.DR();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::AK(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("AK");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::EA(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("EA");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::ED(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("ED");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::DT(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DT");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_CLOSED::ER(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("ER");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TCONreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TCONreq");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TCONresp(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TCONresp");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TDTreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDTreq");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TEXreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TEXreq");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::TDISreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NDISind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NDISind");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NCONconf(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NCONconf");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::NRSTind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NRSTind");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::CR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CR");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::CC(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CC");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DR");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DC(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DC");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::AK(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("AK");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::EA(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("EA");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::DT(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DT");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::ED(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("ED");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::ER(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("ER");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_ERROR::RJ(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("RJ");
				
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDTreq(FSM& context, TPDU::DT& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDTreq");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::OPEN);
					ctxt.DT(tsdu);
				} catch (...) {
					context.setState(TSAP::OPEN);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDISreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				if (ctxt.P5()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSED);
						ctxt.NDISreq(0);
					} catch (...) {
						context.setState(TSAP::CLOSED);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::TDISreq(FSM& context, TPDU::DR& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				if (ctxt.P7()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSING);
						ctxt.DR(tsdu);
					} catch (...) {
						context.setState(TSAP::CLOSING);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::NRSTind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NRSTind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind(Disconnect::DR_NETWORK);
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::NDISind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NDISind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::CR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CR");
				
				if (ctxt.P9()) {
					(context.getState()).Exit(context);
					context.setState(TSAP::OPEN);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::DT(FSM& context, shared_ptr<Buffer>& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DT");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::OPEN);
					ctxt.TDTind(tsdu);
				} catch (...) {
					context.setState(TSAP::OPEN);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_OPEN::DR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DR");
				
				if (ctxt.P5()) {
					(context.getState()).Exit(context);
					context.setState(TSAP::ERROR);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::DR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::TDISreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				if (!ctxt.P7()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSED);
						ctxt.NDISreq(0);
					} catch (...) {
						context.setState(TSAP::CLOSED);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				if (ctxt.P7()) {
					(context.getState()).Exit(context);
					context.setState(TSAP::WBCL);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::TDISreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::NRSTind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NRSTind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind(Disconnect::DR_NETWORK, "Network reset");
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::NDISind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NDISind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::DR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DR");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFCC::CC(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CC");
				
				if (ctxt.P8()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::OPEN);
						ctxt.TCONconf();
					} catch (...) {
						context.setState(TSAP::OPEN);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				if (ctxt.P6()&&ctxt.P5()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::CLOSED);
						ctxt.TDISind();
						ctxt.NDISreq(0);
					} catch (...) {
						context.setState(TSAP::CLOSED);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CC(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFNC::TDISreq(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				(context.getState()).Exit(context);
				context.setState(TSAP::CLOSED);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFNC::NCONconf(FSM& context, Buffer* tdsu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NCONconf");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::WFCC);
					ctxt.CR(tdsu);
				} catch (...) {
					context.setState(TSAP::WFCC);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFNC::NDISind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NDISind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::TCONresp(FSM& context, TPDU::CC& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TCONresp");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::OPEN);
					ctxt.CC(tsdu);
				} catch (...) {
					context.setState(TSAP::OPEN);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::TDISreq(FSM& context, TPDU::DR& tsdu) {
				Provider& ctxt = context.getOwner();
				context.setTransition("TDISreq");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.DR(tsdu);
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::NRSTind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NRSTind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::NDISind(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("NDISind");
				
				(context.getState()).Exit(context);
				context.clearState();
				try {
					context.setState(TSAP::CLOSED);
					ctxt.TDISind();
				} catch (...) {
					context.setState(TSAP::CLOSED);
					throw;
				}
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::CR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("CR");
				
				if (ctxt.P9()) {
					(context.getState()).Exit(context);
					context.setState(TSAP::WFTRESP);
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::CR(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void TSAP_WFTRESP::DR(FSM& context) {
				Provider& ctxt = context.getOwner();
				context.setTransition("DR");
				
				if (ctxt.P10()) {
					(context.getState()).Exit(context);
					context.clearState();
					try {
						context.setState(TSAP::ERROR);
						ctxt.DC();
					} catch (...) {
						context.setState(TSAP::ERROR);
						throw;
					}
					(context.getState()).Entry(context);
				} else 
				{
				     TSAP_Default::DR(context);
				}
				return;
			};
		}
	}
}
