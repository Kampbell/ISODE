#include "als/ssap/ResyncOption.h"
#include "als/ssap/spdu/AC.h"
#include "als/ssap/spdu/MAP.h"
#include "als/ssap/prov/Provider.h"
#include "FSM.h"
using namespace statemap;
namespace ALS {
	namespace SSAP {
		namespace PROV {
			// FSM Map constructor.
			SSAP::SSAP() :
				STA01("STA01", 0),
				STA01A("STA01A", 1),
				STA01B("STA01B", 2),
				STA01C("STA01C", 3),
				STA01D("STA01D", 4),
				STA02A("STA02A", 5),
				STA02B("STA02B", 6),
				STA03("STA03", 7),
				STA04A("STA04A", 8),
				STA04B("STA04B", 9),
				STA05A("STA05A", 10),
				STA05B("STA05B", 11),
				STA05C("STA05C", 12),
				STA06("STA06", 13),
				STA08("STA08", 14),
				STA09("STA09", 15),
				STA10A("STA10A", 16),
				STA10B("STA10B", 17),
				STA11A("STA11A", 18),
				STA11B("STA11B", 19),
				STA11C("STA11C", 20),
				STA15A("STA15A", 21),
				STA15B("STA15B", 22),
				STA15C("STA15C", 23),
				STA15D("STA15D", 24),
				STA16("STA16", 25),
				STA18("STA18", 26),
				STA19("STA19", 27),
				STA20("STA20", 28),
				STA21("STA21", 29),
				STA22("STA22", 30),
				STA713("STA713", 31)
			{}
			
			// Class state -----------------------------------
			void ProviderState::AA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AB(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AB(FSM<Provider>& context, bool release) {
			     Default(context);
			}
			void ProviderState::AC(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AC(FSM<Provider>& context, SPDU::AC& ac) {
			     Default(context);
			}
			void ProviderState::AD(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::ADA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AE(FSM<Provider>& context, const SPDU::MAP& map) {
			     Default(context);
			}
			void ProviderState::AE(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::AEA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AEA(FSM<Provider>& context, int ssn) {
			     Default(context);
			}
			void ProviderState::AI(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AIA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AR(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::AR(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::AS(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CD(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CDA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CDO(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::CN(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::DN(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::DT(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::ED(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::ER(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::EX(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::FN(FSM<Provider>& context, bool release) {
			     Default(context);
			}
			void ProviderState::GT(FSM<Provider>& context, int tokens) {
			     Default(context);
			}
			void ProviderState::GTA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::GTC(FSM<Provider>& context, int tokens) {
			     Default(context);
			}
			void ProviderState::MAA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::MAA(FSM<Provider>& context, int ssn) {
			     Default(context);
			}
			void ProviderState::MAP(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::MAP(FSM<Provider>& context, const SPDU::MAP& map) {
			     Default(context);
			}
			void ProviderState::MAP(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::MIA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::MIA(FSM<Provider>& context, int ssn) {
			     Default(context);
			}
			void ProviderState::MIA(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
			     Default(context);
			}
			void ProviderState::MIP(FSM<Provider>& context, bool ds, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::NF(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::OA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::PR_AB(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::PR_MAA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::PR_RA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::PR_RS(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::PT(FSM<Provider>& context, int tokens) {
			     Default(context);
			}
			void ProviderState::RA(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::RA(FSM<Provider>& context, nat4 ssn, int tokens) {
			     Default(context);
			}
			void ProviderState::RF(FSM<Provider>& context, bool reuse) {
			     Default(context);
			}
			void ProviderState::RS(FSM<Provider>& context, ResyncOption t) {
			     Default(context);
			}
			void ProviderState::SACTDreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTDrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTEreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTEreq(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::SACTErsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTIreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTIrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTRreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SACTRreq(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::SACTSreq(FSM<Provider>& context, const ActivityId& id, int cc, const void* data) {
			     Default(context);
			}
			void ProviderState::SCDreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SCDrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SCGreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SCONreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SCONrsp(FSM<Provider>& context, bool accepted) {
			     Default(context);
			}
			void ProviderState::SCONrsp(FSM<Provider>& context, bool accepted, SPDU::AC& ac) {
			     Default(context);
			}
			void ProviderState::SDTreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SEXreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SGTreq(FSM<Provider>& context, int tokens) {
			     Default(context);
			}
			void ProviderState::SPTreq(FSM<Provider>& context, int tokens) {
			     Default(context);
			}
			void ProviderState::SRELreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SRELrsp(FSM<Provider>& context, bool accept) {
			     Default(context);
			}
			void ProviderState::SRSYNreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::SRSYNrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SRSYNrsp(FSM<Provider>& context, int ssn) {
			     Default(context);
			}
			void ProviderState::SSYNMreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SSYNMrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SSYNmreq(FSM<Provider>& context, bool ds) {
			     Default(context);
			}
			void ProviderState::SSYNmrsp(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SSYNmrsp(FSM<Provider>& context, int ssn) {
			     Default(context);
			}
			void ProviderState::SSYNmrsp(FSM<Provider>& context, nat4 ssn) {
			     Default(context);
			}
			void ProviderState::STDreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SUABreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::SUERreq(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TCONcnf(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TCONind(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TD(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TDISind(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::TIM(FSM<Provider>& context) {
			     Default(context);
			}
			void ProviderState::Default(FSM<Provider>& context) {
			    throw TransitionUndefinedException(context.getState().getName(), context.getTransition());
			    return;
			}
			
			// ----------------------------------------------------
			void SSAP_STA01::SCONreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01B);
				(context.getState()).Entry(context);
				ctxt.SA2();
				ctxt.TCONreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01::TCONind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01C);
				(context.getState()).Entry(context);
				ctxt.SA1();
				ctxt.TCONrsp();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::CN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::RF(FSM<Provider>& context, bool reuse) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
				} else 
				if (ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01C);
				(context.getState()).Entry(context);
				ctxt.SA3();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SA3();
					ctxt.TDISreq();
				} else 
				if (release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SA3();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01A::TIM(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01B::TCONcnf(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA02B);
					(context.getState()).Entry(context);
					ctxt.CN();
				} else 
				if (!ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA02A);
					(context.getState()).Entry(context);
					ctxt.CN();
				} else 
				{
				     SSAP_Default::TCONcnf(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::CDO(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::CN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p01()&&!ctxt.p76()&&ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01D);
					(context.getState()).Entry(context);
					ctxt.SA50();
					ctxt.OA();
				} else 
				if (!ctxt.p01()&&!ctxt.p76()&&!ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA08);
					(context.getState()).Entry(context);
					ctxt.SCONind();
				} else 
				if (!ctxt.p01()&&ctxt.p76()&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA4();
					ctxt.RF(false);
				} else 
				if (!ctxt.p01()&&ctxt.p76()&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.RF(true);
				} else 
				if (ctxt.p01()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::CN(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::OA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::RF(FSM<Provider>& context, bool reuse) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::SCONreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p01()&&ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA02B);
					(context.getState()).Entry(context);
					ctxt.CN();
				} else 
				if (ctxt.p01()&&!ctxt.p204()) {
					(context.getState()).Exit(context);
					context.setState(context.STA02A);
					(context.getState()).Entry(context);
					ctxt.CN();
				} else 
				{
				     SSAP_Default::SCONreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01C::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::CDO(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p202()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01D);
					(context.getState()).Entry(context);
					ctxt.SA50();
				} else 
				if (ctxt.p202()) {
					(context.getState()).Exit(context);
					context.setState(context.STA08);
					(context.getState()).Entry(context);
					ctxt.SCONind();
				} else 
				{
				     SSAP_Default::CDO(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA01D::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::AC(FSM<Provider>& context, SPDU::AC& ac) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.SA5(ac.isn());
				ctxt.SA11(ac.token());
				ctxt.SCONcnf(true);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::RF(FSM<Provider>& context, bool reuse) {
				Provider& ctxt = context.getOwner();
				
				if (!reuse) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				if (reuse&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				if (reuse&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::RF(context, reuse);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA02A);
				(context.getState()).Entry(context);
				ctxt.SA10();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA02A);
				(context.getState()).Entry(context);
				ctxt.SA10();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02B::OA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA02A);
				(context.getState()).Entry(context);
				ctxt.CDO();
				ctxt.SA51();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02B::RF(FSM<Provider>& context, bool reuse) {
				Provider& ctxt = context.getOwner();
				
				if (!reuse) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				if (reuse&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				if (reuse&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SCONcnf(false);
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::RF(context, reuse);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA02B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&ctxt.p10()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p09()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()&&ctxt.p10()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p10()&&ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p10()&&!ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p10()&&!ctxt.p34()&&ctxt.p35()&&ctxt.p32(t)) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p10()&&!ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p52()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p52()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p66()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SRELcnf(true);
					ctxt.TDISreq();
				} else 
				if (ctxt.p66()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SRELcnf(true);
				} else 
				{
				     SSAP_Default::DN(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p65()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.SRELind();
					ctxt.SA8();
					ctxt.SA18();
				} else 
				if (release&&!ctxt.p65()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.SRELind();
					ctxt.SA8();
					ctxt.SA18();
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p67()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SRELcnf(false);
				} else 
				{
				     SSAP_Default::NF(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA03::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::MAA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()&&ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SSYNMcnf();
				} else 
				{
				     SSAP_Default::MAA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::AEA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()&&ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SSYNMcnf();
				} else 
				{
				     SSAP_Default::AEA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p20(ssn)&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p32(t)&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()&&ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				if (ctxt.p48()&&!ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()&&ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				if (ctxt.p48()&&!ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::MAA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()&&ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SACTEcnf();
				} else 
				{
				     SSAP_Default::MAA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::AEA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()&&ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SACTEcnf();
				} else 
				{
				     SSAP_Default::AEA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p20(ssn)&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()&&ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				if (ctxt.p48()&&!ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()&&ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				if (ctxt.p48()&&!ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA04B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p05()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p08()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p06()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05A);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05A);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::MAP(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p12()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA23();
					ctxt.SSYNMind(map);
				} else 
				{
				     SSAP_Default::MAP(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05A);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::AE(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p17()&&ctxt.p21()&&ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&!ctxt.p178()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&!ctxt.p178()&&!ctxt.p185()&&ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				if (ds&&ctxt.p82()&&!ctxt.p178()&&!ctxt.p185()&&ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&!ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (t==a&&ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&!ctxt.p34()&&ctxt.p35()&&ctxt.p32(t)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (t==r&&ctxt.p34()&&ctxt.p35()&&ctxt.p32(t)) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&!ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (t==s&&ctxt.p34()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::RA(FSM<Provider>& context, nat4 ssn, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p35()&&ctxt.p49()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SRSYNcnf();
					ctxt.SA28(ssn);
					ctxt.SA11(tokens);
				} else 
				{
				     SSAP_Default::RA(context, ssn, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p53(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				if (release&&ctxt.p68()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05B);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05B);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05B);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTIcnf();
					ctxt.SA29();
				} else 
				{
				     SSAP_Default::AIA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::CDA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05C);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05C);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA05C);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::MIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MIA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTDcnf();
					ctxt.SA29();
				} else 
				{
				     SSAP_Default::ADA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA05C::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p05()&&!ctxt.p15()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SA10();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p06()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA06);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA06);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MAP(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::MAP(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SA23();
					ctxt.SSYNMind(map);
				} else 
				{
				     SSAP_Default::MAP(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::AE(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::MIA(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p17()&&ctxt.p21()&&ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&!ctxt.p178()&&!ctxt.p185()&&ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				if (ds&&ctxt.p82()&&!ctxt.p178()&&!ctxt.p185()&&ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA06);
				(context.getState()).Entry(context);
				ctxt.SA10();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SA10();
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&!ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA6();
				} else 
				if (t==a&&ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
					ctxt.SA6();
				} else 
				if (t==r&&!ctxt.p24()&&ctxt.p32(t)) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA6();
				} else 
				if (t==r&&ctxt.p24()&&ctxt.p32(t)) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
					ctxt.SA6();
				} else 
				if (t==s&&!ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.SA6();
				} else 
				if (t==s&&ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p59(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				if (ctxt.p53(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p54(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA06::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA08::SCONrsp(FSM<Provider>& context, bool accepted, SPDU::AC& ac) {
				Provider& ctxt = context.getOwner();
				
				if (accepted) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA5(ac.isn());
					ctxt.SA11();
					ctxt.AC(ac);
				} else 
				if (!accepted&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA4();
					ctxt.RF(false);
				} else 
				if (!accepted&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.RF(true);
				} else 
				{
				     SSAP_Default::SCONrsp(context, accepted, ac);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA08::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA08::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA08::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA08::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p04()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.DT();
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p09()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.EX();
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p07()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.TD();
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SSYNmrsp(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.MIA();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p10()&&ctxt.p28()&&!ctxt.p34()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p10()&&ctxt.p25()&&!ctxt.p34()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p10()&&ctxt.p25()&&!ctxt.p34()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.PT(tokens);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.ED();
				} else 
				{
				     SSAP_Default::SUERreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p69()&&!ctxt.p01()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.SRELcnf(true);
					ctxt.SA32();
				} else 
				{
				     SSAP_Default::DN(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SRELreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p65()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.FN(false);
					ctxt.SA8();
					ctxt.SA18();
				} else 
				{
				     SSAP_Default::SRELreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SRELrsp(FSM<Provider>& context, bool accept) {
				Provider& ctxt = context.getOwner();
				
				if (accept&&!ctxt.p66()&&ctxt.p75()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.DN();
					ctxt.SA4();
				} else 
				if (accept&&ctxt.p66()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.DN();
				} else 
				if (accept&&ctxt.p66()&&ctxt.p01()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.DN();
				} else 
				if (!accept&&ctxt.p67()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.NF();
				} else 
				{
				     SSAP_Default::SRELrsp(context, accept);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA09::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.DT();
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.EX();
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.TD();
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SSYNMrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.PR_MAA();
				ctxt.MAA();
				ctxt.SA14();
				ctxt.SA22();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SSYNmrsp(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&!ctxt.p20(ssn)&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.MIA();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p25()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p25()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.PT(tokens);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.ED();
				} else 
				{
				     SSAP_Default::SUERreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.DT();
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.EX();
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.TD();
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SACTErsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.PR_MAA();
				ctxt.AEA();
				ctxt.SA14();
				ctxt.SA22();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SSYNmrsp(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&!ctxt.p20(ssn)&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.MIA();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.PT(tokens);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.ED();
				} else 
				{
				     SSAP_Default::SUERreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA10B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p24()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p24()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::SRSYNrsp(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p43()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.PR_RA();
					ctxt.RA();
					ctxt.SA28(ssn);
					ctxt.SA11();
				} else 
				{
				     SSAP_Default::SRSYNrsp(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11B::SACTIrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.PR_RA();
				ctxt.AIA();
				ctxt.SA30();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11B::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11C::SACTDrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.PR_RA();
				ctxt.ADA();
				ctxt.SA30();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11C::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11C::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11C::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA11C::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.SA10();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::MAA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p20(ssn)&&!ctxt.p23()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SSYNMcnf();
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SA6();
				} else 
				if (ctxt.p20(ssn)&&ctxt.p23()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTEcnf();
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::MAA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::AEA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p20(ssn)&&!ctxt.p23()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SSYNMcnf();
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SA6();
				} else 
				if (ctxt.p20(ssn)&&ctxt.p23()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTEcnf();
					ctxt.SA14();
					ctxt.SA22();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::AEA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p20(ssn)&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p10()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p28()&&ctxt.p30()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p28()&&ctxt.p30()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA15A);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15A::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p05()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p06()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15B);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15B);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MAP(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SSYNMreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p13()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SSYNMreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SSYNMrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15B);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::AE(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p17()&&ctxt.p21()&&ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&!ctxt.p178()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&ctxt.p14()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SACTEreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p71()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SACTEreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SSYNmreq(FSM<Provider>& context, bool ds) {
				Provider& ctxt = context.getOwner();
				
				if (ds&&ctxt.p15()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&ctxt.p15()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SSYNmreq(context, ds);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SSYNmrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p29()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p32(t)&&ctxt.p29()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p29()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p27()&&ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p25()&&ctxt.p27()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p25()&&ctxt.p27()) {
					(context.getState()).Exit(context);
					context.setState(context.STA06);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p27()&&ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p27()&&ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AR(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p44()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SACTRind();
					ctxt.SA12();
					ctxt.SA27(ssn);
				} else 
				{
				     SSAP_Default::AR(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p44()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SACTSind();
					ctxt.SA12();
					ctxt.SA26();
				} else 
				{
				     SSAP_Default::AS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p59(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p53(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SUERreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p67()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
					ctxt.SRELcnf(false);
				} else 
				{
				     SSAP_Default::NF(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SRELreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p63()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SRELreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15B::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p05()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SA10();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p06()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				ctxt.SA43();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MAP(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::MAP(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SA23();
					ctxt.SSYNMind(map);
				} else 
				{
				     SSAP_Default::MAP(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::AE(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::MIA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&!ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p17()&&ctxt.p21()&&ctxt.p81()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&!ctxt.p178()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&ctxt.p14()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()&&!ctxt.p178()&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p82()&&!ctxt.p178()&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::SACTEreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p71()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SACTEreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::SSYNmreq(FSM<Provider>& context, bool ds) {
				Provider& ctxt = context.getOwner();
				
				if (ds&&ctxt.p15()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (!ds&&ctxt.p15()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SSYNmreq(context, ds);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::SSYNmrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15C);
				(context.getState()).Entry(context);
				ctxt.SA10();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::RA(FSM<Provider>& context, nat4 ssn, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p36()&&ctxt.p49()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SRSYNcnf();
					ctxt.SA28(ssn);
					ctxt.SA11(tokens);
				} else 
				{
				     SSAP_Default::RA(context, ssn, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p41()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTDcnf();
					ctxt.SA29();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::ADA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p37()&&ctxt.p42()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTIcnf();
					ctxt.SA29();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::AIA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p59(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)&&ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (ctxt.p53(tokens)&&!ctxt.p185()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				if (release&&ctxt.p68()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15C);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15C::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::CDO(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::OA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SCONrsp(FSM<Provider>& context, bool accepted) {
				Provider& ctxt = context.getOwner();
				
				if (accepted) {
					(context.getState()).Exit(context);
					context.setState(context.STA15D);
					(context.getState()).Entry(context);
				} else 
				if (!accepted) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SCONrsp(context, accepted);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::MIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA15D);
					(context.getState()).Entry(context);
				} else 
				if (ds&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15D);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTEreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTErsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SSYNmreq(FSM<Provider>& context, bool ds) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SSYNmrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SRSYNreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SRSYNrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTDrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTIrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SACTRreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SCDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SCDrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SCGreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA15D);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SRELreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SRELrsp(FSM<Provider>& context, bool accept) {
				Provider& ctxt = context.getOwner();
				
				if (accept) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA4();
				} else 
				if (!accept) {
					(context.getState()).Exit(context);
					context.setState(context.STA15D);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::SRELrsp(context, accept);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA15D::TIM(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AC(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::CN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::RF(FSM<Provider>& context, bool reuse) {
				Provider& ctxt = context.getOwner();
				
				if (!reuse) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
				} else 
				if (reuse) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::RF(context, reuse);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AEA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::MAP(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::PR_MAA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AE(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::MIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip) {
				Provider& ctxt = context.getOwner();
				
				if (!ds) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
				} else 
				if (ds&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SA44();
				} else 
				{
				     SSAP_Default::MIP(context, ds, mip);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::PR_RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::RA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::ADA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AR(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::DN(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::NF(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA16);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SA3();
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA16::TIM(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.TDISreq();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p70()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p70()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.DT();
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.EX();
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.TD();
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA18);
				(context.getState()).Entry(context);
				ctxt.SA10();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::GTA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.SA6();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA18::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA19);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::MAP(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA31();
				} else 
				{
				     SSAP_Default::MAP(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::AE(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA31();
				} else 
				{
				     SSAP_Default::AE(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::MIA(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::MIP(FSM<Provider>& context, bool ds, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p19(ssn)&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p32(t)&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p60(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				if (ctxt.p61(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
				} else 
				if (release&&ctxt.p68()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA19::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::MAA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MAA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::AEA(FSM<Provider>& context, int ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p20(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::AEA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::MAP(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SA31();
				} else 
				{
				     SSAP_Default::MAP(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::AE(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SA31();
				} else 
				{
				     SSAP_Default::AE(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::MIA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::MIA(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::MIP(FSM<Provider>& context, bool ds, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p19(ssn)&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p80()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p32(t)&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p28()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p25()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p25()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p11()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p11()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p60(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				if (ctxt.p61(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				if (release&&ctxt.p68()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA20::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p70()) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::CDA(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.SCDcnf();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p48()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA21::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::SCDrsp(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA713);
				(context.getState()).Entry(context);
				ctxt.CDA();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA22);
					(context.getState()).Entry(context);
					ctxt.PT(tokens);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA22::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::DT(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p05()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SDTind();
				} else 
				{
				     SSAP_Default::DT(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::EX(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SEXind();
				} else 
				{
				     SSAP_Default::EX(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::TD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.STDind();
				} else 
				{
				     SSAP_Default::TD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SDTreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p03()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.DT();
				} else 
				{
				     SSAP_Default::SDTreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SEXreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p08()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.EX();
				} else 
				{
				     SSAP_Default::SEXreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::STDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p06()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.TD();
				} else 
				{
				     SSAP_Default::STDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::MAP(FSM<Provider>& context, const SPDU::MAP& map) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p12()&&ctxt.p19(map.ssn())) {
					(context.getState()).Exit(context);
					context.setState(context.STA10A);
					(context.getState()).Entry(context);
					ctxt.SA13();
					ctxt.SA31();
					ctxt.SSYNMind(map);
				} else 
				{
				     SSAP_Default::MAP(context, map);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SSYNMreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p13()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04A);
					(context.getState()).Entry(context);
					ctxt.MAP();
					ctxt.SA13();
					ctxt.SA24();
				} else 
				{
				     SSAP_Default::SSYNMreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AE(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p72()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA10B);
					(context.getState()).Entry(context);
					ctxt.SA17();
					ctxt.SA31();
					ctxt.SACTEind();
				} else 
				{
				     SSAP_Default::AE(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::MIA(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p17()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SSYNmcnf();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::MIA(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::MIP(FSM<Provider>& context, bool ds, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (!ds&&ctxt.p14()&&ctxt.p19(ssn)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA23();
				} else 
				if (ds&&ctxt.p14()&&ctxt.p19(ssn)&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SSYNmind();
					ctxt.SA44();
					ctxt.SA23();
				} else 
				{
				     SSAP_Default::MIP(context, ds, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SACTEreq(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p71()) {
					(context.getState()).Exit(context);
					context.setState(context.STA04B);
					(context.getState()).Entry(context);
					ctxt.AE(ssn);
					ctxt.SA17();
					ctxt.SA24();
				} else 
				{
				     SSAP_Default::SACTEreq(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SSYNmreq(FSM<Provider>& context, bool ds) {
				Provider& ctxt = context.getOwner();
				
				if (ds&&ctxt.p15()&&ctxt.p82()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.MIP();
					ctxt.SA41();
					ctxt.SA24();
				} else 
				if (!ds&&ctxt.p15()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.MIP();
					ctxt.SA24();
				} else 
				{
				     SSAP_Default::SSYNmreq(context, ds);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SSYNmrsp(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p18()&&ctxt.p21()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.MIA();
					ctxt.SA25(ssn);
				} else 
				{
				     SSAP_Default::SSYNmrsp(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::PR_RS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA15B);
					(context.getState()).Entry(context);
				} else 
				if (!ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA10();
				} else 
				{
				     SSAP_Default::PR_RS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::RS(FSM<Provider>& context, ResyncOption t) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p26()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SA19();
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p32(t)&&ctxt.p26()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p26()&&ctxt.p35()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11A);
					(context.getState()).Entry(context);
					ctxt.SRSYNind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::RS(context, t);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (t==a&&ctxt.p29()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==r&&ctxt.p25()&&ctxt.p26()&&ctxt.p33()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				if (t==s&&ctxt.p25()&&ctxt.p26()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05A);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.RS(t, ssn);
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SRSYNreq(context, t, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11C);
					(context.getState()).Entry(context);
					ctxt.SACTDind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AI(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p38()&&ctxt.p40()) {
					(context.getState()).Exit(context);
					context.setState(context.STA11B);
					(context.getState()).Entry(context);
					ctxt.SACTIind();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::AI(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SACTDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05C);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AD();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SACTIreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p34()&&ctxt.p39()) {
					(context.getState()).Exit(context);
					context.setState(context.STA05B);
					(context.getState()).Entry(context);
					ctxt.PR_RS();
					ctxt.AI();
					ctxt.SA16();
				} else 
				{
				     SSAP_Default::SACTIreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AR(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p44()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTRind();
					ctxt.SA12();
					ctxt.SA27(ssn);
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::AR(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AS(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p44()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SACTSind();
					ctxt.SA12();
					ctxt.SA26();
					ctxt.SA6();
				} else 
				{
				     SSAP_Default::AS(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::CD(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p64()) {
					(context.getState()).Exit(context);
					context.setState(context.STA22);
					(context.getState()).Entry(context);
					ctxt.SCDind();
				} else 
				{
				     SSAP_Default::CD(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SACTRreq(FSM<Provider>& context, nat4 ssn) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p45()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.AR();
					ctxt.SA12();
					ctxt.SA27(ssn);
				} else 
				{
				     SSAP_Default::SACTRreq(context, ssn);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SACTSreq(FSM<Provider>& context, const ActivityId& id, int cc, const void* data) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p45()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.AS(id, cc, data);
					ctxt.SA12();
					ctxt.SA26();
				} else 
				{
				     SSAP_Default::SACTSreq(context, id, cc, data);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SCDreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p47()) {
					(context.getState()).Exit(context);
					context.setState(context.STA21);
					(context.getState()).Entry(context);
					ctxt.CD();
				} else 
				{
				     SSAP_Default::SCDreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::ED(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				if (ctxt.p51()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SUERind();
				} else 
				{
				     SSAP_Default::ED(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::ER(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				if (ctxt.p51()) {
					(context.getState()).Exit(context);
					context.setState(context.STA20);
					(context.getState()).Entry(context);
					ctxt.SPERind();
				} else 
				{
				     SSAP_Default::ER(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::GT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p59(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SA11(tokens);
					ctxt.SGTind(tokens);
				} else 
				{
				     SSAP_Default::GT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::GTC(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p62()) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.GTA();
					ctxt.SA11(tokens);
					ctxt.SCGind();
				} else 
				{
				     SSAP_Default::GTC(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::PT(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.SPTind(tokens);
				} else 
				{
				     SSAP_Default::PT(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SCGreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p55()) {
					(context.getState()).Exit(context);
					context.setState(context.STA18);
					(context.getState()).Entry(context);
					ctxt.GTC();
					ctxt.SA11();
				} else 
				{
				     SSAP_Default::SCGreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SGTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p54(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.GT(tokens);
					ctxt.SA15(tokens);
				} else 
				{
				     SSAP_Default::SGTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SPTreq(FSM<Provider>& context, int tokens) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p53(tokens)) {
					(context.getState()).Exit(context);
					context.setState(context.STA713);
					(context.getState()).Entry(context);
					ctxt.PT(tokens);
				} else 
				{
				     SSAP_Default::SPTreq(context, tokens);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SUERreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p50()) {
					(context.getState()).Exit(context);
					context.setState(context.STA19);
					(context.getState()).Entry(context);
					ctxt.ED();
				} else 
				{
				     SSAP_Default::SUERreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::FN(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&ctxt.p68()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.SRELind();
					ctxt.SA8();
				} else 
				if (release&&ctxt.p68()&&!ctxt.p01()&&ctxt.p16()) {
					(context.getState()).Exit(context);
					context.setState(context.STA09);
					(context.getState()).Entry(context);
					ctxt.SRELind();
					ctxt.SA9();
				} else 
				{
				     SSAP_Default::FN(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SRELreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (ctxt.p63()&&!ctxt.p64()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.FN(false);
					ctxt.SA8();
				} else 
				if (ctxt.p63()&&ctxt.p64()) {
					(context.getState()).Exit(context);
					context.setState(context.STA03);
					(context.getState()).Entry(context);
					ctxt.FN(true);
					ctxt.SA7();
				} else 
				{
				     SSAP_Default::SRELreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::AB(FSM<Provider>& context, bool release) {
				Provider& ctxt = context.getOwner();
				
				if (!release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (!release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
					ctxt.SA4();
				} else 
				if (release&&!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.TDISreq();
				} else 
				if (release&&ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01C);
					(context.getState()).Entry(context);
					ctxt.SxABind();
					ctxt.AA();
				} else 
				{
				     SSAP_Default::AB(context, release);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::PR_AB(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA15D);
				(context.getState()).Entry(context);
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::SUABreq(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				if (!ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA16);
					(context.getState()).Entry(context);
					ctxt.PR_AB();
					ctxt.AB(false);
					ctxt.SA4();
				} else 
				if (ctxt.p02()) {
					(context.getState()).Exit(context);
					context.setState(context.STA01A);
					(context.getState()).Entry(context);
					ctxt.AB(true);
					ctxt.SA4();
				} else 
				{
				     SSAP_Default::SUABreq(context);
				}
				return;
			};
			
			// ----------------------------------------------------
			void SSAP_STA713::TDISind(FSM<Provider>& context) {
				Provider& ctxt = context.getOwner();
				
				(context.getState()).Exit(context);
				context.setState(context.STA01);
				(context.getState()).Entry(context);
				ctxt.SPABind();
				return;
			};
		}
	}
}
