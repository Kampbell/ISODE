#ifndef ALS_SSAP_PROV_FSM_H
#define ALS_SSAP_PROV_FSM_H
#include "statemap.h"
namespace ALS {
	namespace SSAP {
		namespace PROV {
			// Forward declarations.--------------------------
			class SSAP;
			class SSAP_STA01;
			class SSAP_STA01A;
			class SSAP_STA01B;
			class SSAP_STA01C;
			class SSAP_STA01D;
			class SSAP_STA02A;
			class SSAP_STA02B;
			class SSAP_STA03;
			class SSAP_STA04A;
			class SSAP_STA04B;
			class SSAP_STA05A;
			class SSAP_STA05B;
			class SSAP_STA05C;
			class SSAP_STA06;
			class SSAP_STA08;
			class SSAP_STA09;
			class SSAP_STA10A;
			class SSAP_STA10B;
			class SSAP_STA11A;
			class SSAP_STA11B;
			class SSAP_STA11C;
			class SSAP_STA15A;
			class SSAP_STA15B;
			class SSAP_STA15C;
			class SSAP_STA15D;
			class SSAP_STA16;
			class SSAP_STA18;
			class SSAP_STA19;
			class SSAP_STA20;
			class SSAP_STA21;
			class SSAP_STA22;
			class SSAP_STA713;
			class SSAP_Default;
			class ProviderState;
			template<typename Derived> class FSM;
			class Provider;
			
			
			// Class State.-----------------------------------
			class ProviderState : public statemap::State {
			public:
				ProviderState(const char *name, int no) : statemap::State(name, no) {};
				
				virtual void Entry(FSM<Provider>&) {};
				virtual void Exit(FSM<Provider>&) {};
				
				virtual void AA(FSM<Provider>& context);
				virtual void AB(FSM<Provider>& context);
				virtual void AB(FSM<Provider>& context, bool release);
				virtual void AC(FSM<Provider>& context);
				virtual void AC(FSM<Provider>& context, SPDU::AC& ac);
				virtual void AD(FSM<Provider>& context);
				virtual void ADA(FSM<Provider>& context);
				virtual void AE(FSM<Provider>& context, const SPDU::MAP& map);
				virtual void AE(FSM<Provider>& context, nat4 ssn);
				virtual void AEA(FSM<Provider>& context);
				virtual void AEA(FSM<Provider>& context, int ssn);
				virtual void AI(FSM<Provider>& context);
				virtual void AIA(FSM<Provider>& context);
				virtual void AR(FSM<Provider>& context);
				virtual void AR(FSM<Provider>& context, nat4 ssn);
				virtual void AS(FSM<Provider>& context, const ActivityId& id);
				virtual void CD(FSM<Provider>& context);
				virtual void CDA(FSM<Provider>& context);
				virtual void CDO(FSM<Provider>& context);
				virtual void CN(FSM<Provider>& context);
				virtual void DN(FSM<Provider>& context);
				virtual void DT(FSM<Provider>& context);
				virtual void ED(FSM<Provider>& context);
				virtual void ER(FSM<Provider>& context);
				virtual void EX(FSM<Provider>& context);
				virtual void FN(FSM<Provider>& context, bool release);
				virtual void GT(FSM<Provider>& context, int tokens);
				virtual void GTA(FSM<Provider>& context);
				virtual void GTC(FSM<Provider>& context, int tokens);
				virtual void MAA(FSM<Provider>& context);
				virtual void MAA(FSM<Provider>& context, int ssn);
				virtual void MAP(FSM<Provider>& context);
				virtual void MAP(FSM<Provider>& context, const SPDU::MAP& map);
				virtual void MAP(FSM<Provider>& context, nat4 ssn);
				virtual void MIA(FSM<Provider>& context);
				virtual void MIA(FSM<Provider>& context, int ssn);
				virtual void MIA(FSM<Provider>& context, nat4 ssn);
				virtual void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				virtual void MIP(FSM<Provider>& context, bool ds, nat4 ssn);
				virtual void NF(FSM<Provider>& context);
				virtual void OA(FSM<Provider>& context);
				virtual void PR_AB(FSM<Provider>& context);
				virtual void PR_MAA(FSM<Provider>& context);
				virtual void PR_RA(FSM<Provider>& context);
				virtual void PR_RS(FSM<Provider>& context);
				virtual void PT(FSM<Provider>& context, int tokens);
				virtual void RA(FSM<Provider>& context);
				virtual void RA(FSM<Provider>& context, nat4 ssn, int tokens);
				virtual void RF(FSM<Provider>& context, bool reuse);
				virtual void RS(FSM<Provider>& context, ResyncOption t);
				virtual void SACTDreq(FSM<Provider>& context);
				virtual void SACTDrsp(FSM<Provider>& context);
				virtual void SACTEreq(FSM<Provider>& context);
				virtual void SACTEreq(FSM<Provider>& context, nat4 ssn);
				virtual void SACTErsp(FSM<Provider>& context);
				virtual void SACTIreq(FSM<Provider>& context);
				virtual void SACTIrsp(FSM<Provider>& context);
				virtual void SACTRreq(FSM<Provider>& context);
				virtual void SACTRreq(FSM<Provider>& context, nat4 ssn);
				virtual void SACTSreq(FSM<Provider>& context, const ActivityId& id, int cc, const void* data);
				virtual void SCDreq(FSM<Provider>& context);
				virtual void SCDrsp(FSM<Provider>& context);
				virtual void SCGreq(FSM<Provider>& context);
				virtual void SCONreq(FSM<Provider>& context);
				virtual void SCONrsp(FSM<Provider>& context, bool accepted);
				virtual void SCONrsp(FSM<Provider>& context, bool accepted, SPDU::AC& ac);
				virtual void SDTreq(FSM<Provider>& context);
				virtual void SEXreq(FSM<Provider>& context);
				virtual void SGTreq(FSM<Provider>& context, int tokens);
				virtual void SPTreq(FSM<Provider>& context, int tokens);
				virtual void SRELreq(FSM<Provider>& context);
				virtual void SRELrsp(FSM<Provider>& context, bool accept);
				virtual void SRSYNreq(FSM<Provider>& context);
				virtual void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				virtual void SRSYNrsp(FSM<Provider>& context);
				virtual void SRSYNrsp(FSM<Provider>& context, int ssn);
				virtual void SSYNMreq(FSM<Provider>& context);
				virtual void SSYNMrsp(FSM<Provider>& context);
				virtual void SSYNmreq(FSM<Provider>& context, bool ds);
				virtual void SSYNmrsp(FSM<Provider>& context);
				virtual void SSYNmrsp(FSM<Provider>& context, int ssn);
				virtual void SSYNmrsp(FSM<Provider>& context, nat4 ssn);
				virtual void STDreq(FSM<Provider>& context);
				virtual void SUABreq(FSM<Provider>& context);
				virtual void SUERreq(FSM<Provider>& context);
				virtual void TCONcnf(FSM<Provider>& context);
				virtual void TCONind(FSM<Provider>& context);
				virtual void TD(FSM<Provider>& context);
				virtual void TDISind(FSM<Provider>& context);
				virtual void TIM(FSM<Provider>& context);
			protected:
				virtual void Default(FSM<Provider>& context);
			};
			
			// FSM map default state class.-------------------
			class SSAP_Default : public ProviderState {
			public:
				SSAP_Default (const char *name, int stateId) : ProviderState(name, stateId)	{}
			};
			
			// FSM map states class.--------------------------
			// --------------------------------------------------
			class SSAP_STA01:  public SSAP_Default { 
			public:
				SSAP_STA01(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SCONreq(FSM<Provider>& context);
				void TCONind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA01A:  public SSAP_Default { 
			public:
				SSAP_STA01A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AC(FSM<Provider>& context);
				void CN(FSM<Provider>& context);
				void RF(FSM<Provider>& context, bool reuse);
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RA(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void ADA(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void AR(FSM<Provider>& context);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTA(FSM<Provider>& context);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void DN(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void AA(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void TDISind(FSM<Provider>& context);
				void TIM(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA01B:  public SSAP_Default { 
			public:
				SSAP_STA01B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void TCONcnf(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA01C:  public SSAP_Default { 
			public:
				SSAP_STA01C(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AC(FSM<Provider>& context);
				void CDO(FSM<Provider>& context);
				void CN(FSM<Provider>& context);
				void OA(FSM<Provider>& context);
				void RF(FSM<Provider>& context, bool reuse);
				void SCONreq(FSM<Provider>& context);
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RA(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void ADA(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void AR(FSM<Provider>& context);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTA(FSM<Provider>& context);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void DN(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void AA(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA01D:  public SSAP_Default { 
			public:
				SSAP_STA01D(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void CDO(FSM<Provider>& context);
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RA(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void ADA(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void AR(FSM<Provider>& context);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTA(FSM<Provider>& context);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void DN(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void AA(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA02A:  public SSAP_Default { 
			public:
				SSAP_STA02A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AC(FSM<Provider>& context, SPDU::AC& ac);
				void RF(FSM<Provider>& context, bool reuse);
				void EX(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA02B:  public SSAP_Default { 
			public:
				SSAP_STA02B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void OA(FSM<Provider>& context);
				void RF(FSM<Provider>& context, bool reuse);
				void AB(FSM<Provider>& context, bool release);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA03:  public SSAP_Default { 
			public:
				SSAP_STA03(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MIA(FSM<Provider>& context, int ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void PT(FSM<Provider>& context, int tokens);
				void DN(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA04A:  public SSAP_Default { 
			public:
				SSAP_STA04A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context, int ssn);
				void AEA(FSM<Provider>& context, int ssn);
				void PR_MAA(FSM<Provider>& context);
				void MIA(FSM<Provider>& context, int ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA04B:  public SSAP_Default { 
			public:
				SSAP_STA04B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context, int ssn);
				void AEA(FSM<Provider>& context, int ssn);
				void PR_MAA(FSM<Provider>& context);
				void MIA(FSM<Provider>& context, int ssn);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA05A:  public SSAP_Default { 
			public:
				SSAP_STA05A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context, const SPDU::MAP& map);
				void PR_MAA(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void RA(FSM<Provider>& context, nat4 ssn, int tokens);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void FN(FSM<Provider>& context, bool release);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA05B:  public SSAP_Default { 
			public:
				SSAP_STA05B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AIA(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA05C:  public SSAP_Default { 
			public:
				SSAP_STA05C(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void MIA(FSM<Provider>& context);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void ADA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA06:  public SSAP_Default { 
			public:
				SSAP_STA06(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void MAP(FSM<Provider>& context, const SPDU::MAP& map);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, nat4 ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void FN(FSM<Provider>& context, bool release);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA08:  public SSAP_Default { 
			public:
				SSAP_STA08(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SCONrsp(FSM<Provider>& context, bool accepted, SPDU::AC& ac);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA09:  public SSAP_Default { 
			public:
				SSAP_STA09(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void SSYNmrsp(FSM<Provider>& context, nat4 ssn);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void DN(FSM<Provider>& context);
				void SRELreq(FSM<Provider>& context);
				void SRELrsp(FSM<Provider>& context, bool accept);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA10A:  public SSAP_Default { 
			public:
				SSAP_STA10A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void SSYNMrsp(FSM<Provider>& context);
				void SSYNmrsp(FSM<Provider>& context, int ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA10B:  public SSAP_Default { 
			public:
				SSAP_STA10B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void SACTErsp(FSM<Provider>& context);
				void SSYNmrsp(FSM<Provider>& context, int ssn);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA11A:  public SSAP_Default { 
			public:
				SSAP_STA11A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void SRSYNrsp(FSM<Provider>& context, int ssn);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA11B:  public SSAP_Default { 
			public:
				SSAP_STA11B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SACTIrsp(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA11C:  public SSAP_Default { 
			public:
				SSAP_STA11C(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void SACTDrsp(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA15A:  public SSAP_Default { 
			public:
				SSAP_STA15A(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context, int ssn);
				void AEA(FSM<Provider>& context, int ssn);
				void MIA(FSM<Provider>& context, int ssn);
				void PR_RS(FSM<Provider>& context);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA15B:  public SSAP_Default { 
			public:
				SSAP_STA15B(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void SSYNMreq(FSM<Provider>& context);
				void SSYNMrsp(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void SACTEreq(FSM<Provider>& context);
				void SSYNmreq(FSM<Provider>& context, bool ds);
				void SSYNmrsp(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void AR(FSM<Provider>& context, nat4 ssn);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SGTreq(FSM<Provider>& context, int tokens);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void NF(FSM<Provider>& context);
				void SRELreq(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA15C:  public SSAP_Default { 
			public:
				SSAP_STA15C(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void MAP(FSM<Provider>& context, const SPDU::MAP& map);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context, int ssn);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void SACTEreq(FSM<Provider>& context);
				void SSYNmreq(FSM<Provider>& context, bool ds);
				void SSYNmrsp(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RA(FSM<Provider>& context, nat4 ssn, int tokens);
				void ADA(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void FN(FSM<Provider>& context, bool release);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA15D:  public SSAP_Default { 
			public:
				SSAP_STA15D(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AC(FSM<Provider>& context);
				void CDO(FSM<Provider>& context);
				void OA(FSM<Provider>& context);
				void SCONrsp(FSM<Provider>& context, bool accepted);
				void DT(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void SACTEreq(FSM<Provider>& context);
				void SACTErsp(FSM<Provider>& context);
				void SSYNmreq(FSM<Provider>& context, bool ds);
				void SSYNmrsp(FSM<Provider>& context);
				void RA(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context);
				void SRSYNrsp(FSM<Provider>& context);
				void AD(FSM<Provider>& context);
				void ADA(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void SACTDreq(FSM<Provider>& context);
				void SACTDrsp(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void SACTIrsp(FSM<Provider>& context);
				void AR(FSM<Provider>& context);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void SACTRreq(FSM<Provider>& context);
				void SCDreq(FSM<Provider>& context);
				void SCDrsp(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTA(FSM<Provider>& context);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SCGreq(FSM<Provider>& context);
				void SGTreq(FSM<Provider>& context, int tokens);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void SRELreq(FSM<Provider>& context);
				void SRELrsp(FSM<Provider>& context, bool accept);
				void AB(FSM<Provider>& context, bool release);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
				void TIM(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA16:  public SSAP_Default { 
			public:
				SSAP_STA16(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AC(FSM<Provider>& context);
				void CN(FSM<Provider>& context);
				void RF(FSM<Provider>& context, bool reuse);
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context);
				void AEA(FSM<Provider>& context);
				void MAP(FSM<Provider>& context);
				void PR_MAA(FSM<Provider>& context);
				void AE(FSM<Provider>& context, const SPDU::MAP& map);
				void MIA(FSM<Provider>& context);
				void MIP(FSM<Provider>& context, bool ds, const SPDU::MIP& mip);
				void PR_RA(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void RA(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void ADA(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void AIA(FSM<Provider>& context);
				void AR(FSM<Provider>& context);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTA(FSM<Provider>& context);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void DN(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void NF(FSM<Provider>& context);
				void AA(FSM<Provider>& context);
				void AB(FSM<Provider>& context);
				void PR_AB(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
				void TIM(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA18:  public SSAP_Default { 
			public:
				SSAP_STA18(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void PR_RS(FSM<Provider>& context);
				void GTA(FSM<Provider>& context);
				void PT(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA19:  public SSAP_Default { 
			public:
				SSAP_STA19(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAP(FSM<Provider>& context, nat4 ssn);
				void AE(FSM<Provider>& context, nat4 ssn);
				void MIA(FSM<Provider>& context, nat4 ssn);
				void MIP(FSM<Provider>& context, bool ds, nat4 ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void FN(FSM<Provider>& context, bool release);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA20:  public SSAP_Default { 
			public:
				SSAP_STA20(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void MAA(FSM<Provider>& context, int ssn);
				void AEA(FSM<Provider>& context, int ssn);
				void MAP(FSM<Provider>& context, nat4 ssn);
				void AE(FSM<Provider>& context, nat4 ssn);
				void MIA(FSM<Provider>& context);
				void MIP(FSM<Provider>& context, bool ds, nat4 ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void FN(FSM<Provider>& context, bool release);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA21:  public SSAP_Default { 
			public:
				SSAP_STA21(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void CDA(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA22:  public SSAP_Default { 
			public:
				SSAP_STA22(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void AI(FSM<Provider>& context);
				void SCDrsp(FSM<Provider>& context);
				void SPTreq(FSM<Provider>& context, int tokens);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class SSAP_STA713:  public SSAP_Default { 
			public:
				SSAP_STA713(const char* name, int no) : SSAP_Default(name, no) {}
				
				
				void DT(FSM<Provider>& context);
				void EX(FSM<Provider>& context);
				void TD(FSM<Provider>& context);
				void SDTreq(FSM<Provider>& context);
				void SEXreq(FSM<Provider>& context);
				void STDreq(FSM<Provider>& context);
				void MAP(FSM<Provider>& context, const SPDU::MAP& map);
				void SSYNMreq(FSM<Provider>& context);
				void AE(FSM<Provider>& context, nat4 ssn);
				void MIA(FSM<Provider>& context, nat4 ssn);
				void MIP(FSM<Provider>& context, bool ds, nat4 ssn);
				void SACTEreq(FSM<Provider>& context, nat4 ssn);
				void SSYNmreq(FSM<Provider>& context, bool ds);
				void SSYNmrsp(FSM<Provider>& context, nat4 ssn);
				void PR_RS(FSM<Provider>& context);
				void RS(FSM<Provider>& context, ResyncOption t);
				void SRSYNreq(FSM<Provider>& context, ResyncOption t, nat4 ssn);
				void AD(FSM<Provider>& context);
				void AI(FSM<Provider>& context);
				void SACTDreq(FSM<Provider>& context);
				void SACTIreq(FSM<Provider>& context);
				void AR(FSM<Provider>& context, nat4 ssn);
				void AS(FSM<Provider>& context, const ActivityId& id);
				void CD(FSM<Provider>& context);
				void SACTRreq(FSM<Provider>& context, nat4 ssn);
				void SACTSreq(FSM<Provider>& context, const ActivityId& id, int cc, const void* data);
				void SCDreq(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void GT(FSM<Provider>& context, int tokens);
				void GTC(FSM<Provider>& context, int tokens);
				void PT(FSM<Provider>& context, int tokens);
				void SCGreq(FSM<Provider>& context);
				void SGTreq(FSM<Provider>& context, int tokens);
				void SPTreq(FSM<Provider>& context, int tokens);
				void SUERreq(FSM<Provider>& context);
				void FN(FSM<Provider>& context, bool release);
				void SRELreq(FSM<Provider>& context);
				void AB(FSM<Provider>& context, bool release);
				void PR_AB(FSM<Provider>& context);
				void SUABreq(FSM<Provider>& context);
				void TDISind(FSM<Provider>& context);
			};
			
			// FSM map class.---------------------------------
			class SSAP {
			public:
				SSAP();
				SSAP_STA01 STA01;
				SSAP_STA01A STA01A;
				SSAP_STA01B STA01B;
				SSAP_STA01C STA01C;
				SSAP_STA01D STA01D;
				SSAP_STA02A STA02A;
				SSAP_STA02B STA02B;
				SSAP_STA03 STA03;
				SSAP_STA04A STA04A;
				SSAP_STA04B STA04B;
				SSAP_STA05A STA05A;
				SSAP_STA05B STA05B;
				SSAP_STA05C STA05C;
				SSAP_STA06 STA06;
				SSAP_STA08 STA08;
				SSAP_STA09 STA09;
				SSAP_STA10A STA10A;
				SSAP_STA10B STA10B;
				SSAP_STA11A STA11A;
				SSAP_STA11B STA11B;
				SSAP_STA11C STA11C;
				SSAP_STA15A STA15A;
				SSAP_STA15B STA15B;
				SSAP_STA15C STA15C;
				SSAP_STA15D STA15D;
				SSAP_STA16 STA16;
				SSAP_STA18 STA18;
				SSAP_STA19 STA19;
				SSAP_STA20 STA20;
				SSAP_STA21 STA21;
				SSAP_STA22 STA22;
				SSAP_STA713 STA713;
			};
			
			// FSM context class -----------------------------
			template<typename Derived>
			class FSM : public statemap::FSMContext, public SSAP {
			public:
				explicit 
				FSM() : FSMContext(SSAP::STA01) {};
				FSM(const statemap::State& state) : FSMContext(state) {};
				
				void setStartState(const statemap::State& state) {
					setState(state);
				}
				
				virtual void enterStartState() {
				    getState().Entry(*this);
				    return;
				}
				
				Derived& getOwner() {
				    return (*static_cast<Derived*>(this));
				};
				
				const Derived& getOwner() const {
				    return (*static_cast<const Derived*>(this));
				};
				
				ProviderState& getState() const {
				    if (_state == nullptr) {
				        throw statemap::StateUndefinedException();
				    }
				     return (dynamic_cast<ProviderState&>(*_state));
				};
				
				void AA() {
				    setTransition("AA");
				    getState().AA(*this);
				    setTransition(nullptr);
				};
				void AB() {
				    setTransition("AB");
				    getState().AB(*this);
				    setTransition(nullptr);
				};
				void AB(bool release) {
				    setTransition("AB");
				    getState().AB(*this, release);
				    setTransition(nullptr);
				};
				void AC() {
				    setTransition("AC");
				    getState().AC(*this);
				    setTransition(nullptr);
				};
				void AC(SPDU::AC& ac) {
				    setTransition("AC");
				    getState().AC(*this, ac);
				    setTransition(nullptr);
				};
				void AD() {
				    setTransition("AD");
				    getState().AD(*this);
				    setTransition(nullptr);
				};
				void ADA() {
				    setTransition("ADA");
				    getState().ADA(*this);
				    setTransition(nullptr);
				};
				void AE(const SPDU::MAP& map) {
				    setTransition("AE");
				    getState().AE(*this, map);
				    setTransition(nullptr);
				};
				void AE(nat4 ssn) {
				    setTransition("AE");
				    getState().AE(*this, ssn);
				    setTransition(nullptr);
				};
				void AEA() {
				    setTransition("AEA");
				    getState().AEA(*this);
				    setTransition(nullptr);
				};
				void AEA(int ssn) {
				    setTransition("AEA");
				    getState().AEA(*this, ssn);
				    setTransition(nullptr);
				};
				void AI() {
				    setTransition("AI");
				    getState().AI(*this);
				    setTransition(nullptr);
				};
				void AIA() {
				    setTransition("AIA");
				    getState().AIA(*this);
				    setTransition(nullptr);
				};
				void AR() {
				    setTransition("AR");
				    getState().AR(*this);
				    setTransition(nullptr);
				};
				void AR(nat4 ssn) {
				    setTransition("AR");
				    getState().AR(*this, ssn);
				    setTransition(nullptr);
				};
				void AS(const ActivityId& id) {
				    setTransition("AS");
				    getState().AS(*this, id);
				    setTransition(nullptr);
				};
				void CD() {
				    setTransition("CD");
				    getState().CD(*this);
				    setTransition(nullptr);
				};
				void CDA() {
				    setTransition("CDA");
				    getState().CDA(*this);
				    setTransition(nullptr);
				};
				void CDO() {
				    setTransition("CDO");
				    getState().CDO(*this);
				    setTransition(nullptr);
				};
				void CN() {
				    setTransition("CN");
				    getState().CN(*this);
				    setTransition(nullptr);
				};
				void DN() {
				    setTransition("DN");
				    getState().DN(*this);
				    setTransition(nullptr);
				};
				void DT() {
				    setTransition("DT");
				    getState().DT(*this);
				    setTransition(nullptr);
				};
				void ED() {
				    setTransition("ED");
				    getState().ED(*this);
				    setTransition(nullptr);
				};
				void ER() {
				    setTransition("ER");
				    getState().ER(*this);
				    setTransition(nullptr);
				};
				void EX() {
				    setTransition("EX");
				    getState().EX(*this);
				    setTransition(nullptr);
				};
				void FN(bool release) {
				    setTransition("FN");
				    getState().FN(*this, release);
				    setTransition(nullptr);
				};
				void GT(int tokens) {
				    setTransition("GT");
				    getState().GT(*this, tokens);
				    setTransition(nullptr);
				};
				void GTA() {
				    setTransition("GTA");
				    getState().GTA(*this);
				    setTransition(nullptr);
				};
				void GTC(int tokens) {
				    setTransition("GTC");
				    getState().GTC(*this, tokens);
				    setTransition(nullptr);
				};
				void MAA() {
				    setTransition("MAA");
				    getState().MAA(*this);
				    setTransition(nullptr);
				};
				void MAA(int ssn) {
				    setTransition("MAA");
				    getState().MAA(*this, ssn);
				    setTransition(nullptr);
				};
				void MAP() {
				    setTransition("MAP");
				    getState().MAP(*this);
				    setTransition(nullptr);
				};
				void MAP(const SPDU::MAP& map) {
				    setTransition("MAP");
				    getState().MAP(*this, map);
				    setTransition(nullptr);
				};
				void MAP(nat4 ssn) {
				    setTransition("MAP");
				    getState().MAP(*this, ssn);
				    setTransition(nullptr);
				};
				void MIA() {
				    setTransition("MIA");
				    getState().MIA(*this);
				    setTransition(nullptr);
				};
				void MIA(int ssn) {
				    setTransition("MIA");
				    getState().MIA(*this, ssn);
				    setTransition(nullptr);
				};
				void MIA(nat4 ssn) {
				    setTransition("MIA");
				    getState().MIA(*this, ssn);
				    setTransition(nullptr);
				};
				void MIP(bool ds, const SPDU::MIP& mip) {
				    setTransition("MIP");
				    getState().MIP(*this, ds, mip);
				    setTransition(nullptr);
				};
				void MIP(bool ds, nat4 ssn) {
				    setTransition("MIP");
				    getState().MIP(*this, ds, ssn);
				    setTransition(nullptr);
				};
				void NF() {
				    setTransition("NF");
				    getState().NF(*this);
				    setTransition(nullptr);
				};
				void OA() {
				    setTransition("OA");
				    getState().OA(*this);
				    setTransition(nullptr);
				};
				void PR_AB() {
				    setTransition("PR-AB");
				    getState().PR_AB(*this);
				    setTransition(nullptr);
				};
				void PR_MAA() {
				    setTransition("PR-MAA");
				    getState().PR_MAA(*this);
				    setTransition(nullptr);
				};
				void PR_RA() {
				    setTransition("PR-RA");
				    getState().PR_RA(*this);
				    setTransition(nullptr);
				};
				void PR_RS() {
				    setTransition("PR-RS");
				    getState().PR_RS(*this);
				    setTransition(nullptr);
				};
				void PT(int tokens) {
				    setTransition("PT");
				    getState().PT(*this, tokens);
				    setTransition(nullptr);
				};
				void RA() {
				    setTransition("RA");
				    getState().RA(*this);
				    setTransition(nullptr);
				};
				void RA(nat4 ssn, int tokens) {
				    setTransition("RA");
				    getState().RA(*this, ssn, tokens);
				    setTransition(nullptr);
				};
				void RF(bool reuse) {
				    setTransition("RF");
				    getState().RF(*this, reuse);
				    setTransition(nullptr);
				};
				void RS(ResyncOption t) {
				    setTransition("RS");
				    getState().RS(*this, t);
				    setTransition(nullptr);
				};
				void SACTDreq() {
				    setTransition("SACTDreq");
				    getState().SACTDreq(*this);
				    setTransition(nullptr);
				};
				void SACTDrsp() {
				    setTransition("SACTDrsp");
				    getState().SACTDrsp(*this);
				    setTransition(nullptr);
				};
				void SACTEreq() {
				    setTransition("SACTEreq");
				    getState().SACTEreq(*this);
				    setTransition(nullptr);
				};
				void SACTEreq(nat4 ssn) {
				    setTransition("SACTEreq");
				    getState().SACTEreq(*this, ssn);
				    setTransition(nullptr);
				};
				void SACTErsp() {
				    setTransition("SACTErsp");
				    getState().SACTErsp(*this);
				    setTransition(nullptr);
				};
				void SACTIreq() {
				    setTransition("SACTIreq");
				    getState().SACTIreq(*this);
				    setTransition(nullptr);
				};
				void SACTIrsp() {
				    setTransition("SACTIrsp");
				    getState().SACTIrsp(*this);
				    setTransition(nullptr);
				};
				void SACTRreq() {
				    setTransition("SACTRreq");
				    getState().SACTRreq(*this);
				    setTransition(nullptr);
				};
				void SACTRreq(nat4 ssn) {
				    setTransition("SACTRreq");
				    getState().SACTRreq(*this, ssn);
				    setTransition(nullptr);
				};
				void SACTSreq(const ActivityId& id, int cc, const void* data) {
				    setTransition("SACTSreq");
				    getState().SACTSreq(*this, id, cc, data);
				    setTransition(nullptr);
				};
				void SCDreq() {
				    setTransition("SCDreq");
				    getState().SCDreq(*this);
				    setTransition(nullptr);
				};
				void SCDrsp() {
				    setTransition("SCDrsp");
				    getState().SCDrsp(*this);
				    setTransition(nullptr);
				};
				void SCGreq() {
				    setTransition("SCGreq");
				    getState().SCGreq(*this);
				    setTransition(nullptr);
				};
				void SCONreq() {
				    setTransition("SCONreq");
				    getState().SCONreq(*this);
				    setTransition(nullptr);
				};
				void SCONrsp(bool accepted) {
				    setTransition("SCONrsp");
				    getState().SCONrsp(*this, accepted);
				    setTransition(nullptr);
				};
				void SCONrsp(bool accepted, SPDU::AC& ac) {
				    setTransition("SCONrsp");
				    getState().SCONrsp(*this, accepted, ac);
				    setTransition(nullptr);
				};
				void SDTreq() {
				    setTransition("SDTreq");
				    getState().SDTreq(*this);
				    setTransition(nullptr);
				};
				void SEXreq() {
				    setTransition("SEXreq");
				    getState().SEXreq(*this);
				    setTransition(nullptr);
				};
				void SGTreq(int tokens) {
				    setTransition("SGTreq");
				    getState().SGTreq(*this, tokens);
				    setTransition(nullptr);
				};
				void SPTreq(int tokens) {
				    setTransition("SPTreq");
				    getState().SPTreq(*this, tokens);
				    setTransition(nullptr);
				};
				void SRELreq() {
				    setTransition("SRELreq");
				    getState().SRELreq(*this);
				    setTransition(nullptr);
				};
				void SRELrsp(bool accept) {
				    setTransition("SRELrsp");
				    getState().SRELrsp(*this, accept);
				    setTransition(nullptr);
				};
				void SRSYNreq() {
				    setTransition("SRSYNreq");
				    getState().SRSYNreq(*this);
				    setTransition(nullptr);
				};
				void SRSYNreq(ResyncOption t, nat4 ssn) {
				    setTransition("SRSYNreq");
				    getState().SRSYNreq(*this, t, ssn);
				    setTransition(nullptr);
				};
				void SRSYNrsp() {
				    setTransition("SRSYNrsp");
				    getState().SRSYNrsp(*this);
				    setTransition(nullptr);
				};
				void SRSYNrsp(int ssn) {
				    setTransition("SRSYNrsp");
				    getState().SRSYNrsp(*this, ssn);
				    setTransition(nullptr);
				};
				void SSYNMreq() {
				    setTransition("SSYNMreq");
				    getState().SSYNMreq(*this);
				    setTransition(nullptr);
				};
				void SSYNMrsp() {
				    setTransition("SSYNMrsp");
				    getState().SSYNMrsp(*this);
				    setTransition(nullptr);
				};
				void SSYNmreq(bool ds) {
				    setTransition("SSYNmreq");
				    getState().SSYNmreq(*this, ds);
				    setTransition(nullptr);
				};
				void SSYNmrsp() {
				    setTransition("SSYNmrsp");
				    getState().SSYNmrsp(*this);
				    setTransition(nullptr);
				};
				void SSYNmrsp(int ssn) {
				    setTransition("SSYNmrsp");
				    getState().SSYNmrsp(*this, ssn);
				    setTransition(nullptr);
				};
				void SSYNmrsp(nat4 ssn) {
				    setTransition("SSYNmrsp");
				    getState().SSYNmrsp(*this, ssn);
				    setTransition(nullptr);
				};
				void STDreq() {
				    setTransition("STDreq");
				    getState().STDreq(*this);
				    setTransition(nullptr);
				};
				void SUABreq() {
				    setTransition("SUABreq");
				    getState().SUABreq(*this);
				    setTransition(nullptr);
				};
				void SUERreq() {
				    setTransition("SUERreq");
				    getState().SUERreq(*this);
				    setTransition(nullptr);
				};
				void TCONcnf() {
				    setTransition("TCONcnf");
				    getState().TCONcnf(*this);
				    setTransition(nullptr);
				};
				void TCONind() {
				    setTransition("TCONind");
				    getState().TCONind(*this);
				    setTransition(nullptr);
				};
				void TD() {
				    setTransition("TD");
				    getState().TD(*this);
				    setTransition(nullptr);
				};
				void TDISind() {
				    setTransition("TDISind");
				    getState().TDISind(*this);
				    setTransition(nullptr);
				};
				void TIM() {
				    setTransition("TIM");
				    getState().TIM(*this);
				    setTransition(nullptr);
				};
			};
		}
	}
}
#endif
