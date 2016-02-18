#ifndef FSM_H
#define FSM_H
#define SMC_USES_IOSTREAMS
#include "statemap.h"
namespace ALS {
	namespace TSAP {
		namespace PROV {
			// Forward declarations.--------------------------
			class TSAP;
			class TSAP_AKWAIT;
			class TSAP_CLOSED;
			class TSAP_CLOSING;
			class TSAP_CLOSING_BOC;
			class TSAP_CLOSING_BOC_WR;
			class TSAP_CLOSING_R;
			class TSAP_CLOSING_WR;
			class TSAP_ERROR;
			class TSAP_OPEN;
			class TSAP_OPEN_R;
			class TSAP_OPEN_WR;
			class TSAP_REFWAIT;
			class TSAP_WBCL;
			class TSAP_WBCL_R;
			class TSAP_WBCL_WR;
			class TSAP_WBOC;
			class TSAP_WBOC_WR;
			class TSAP_WFCC;
			class TSAP_WFCC_R;
			class TSAP_WFNC;
			class TSAP_WFNC_R;
			class TSAP_WFTRESP;
			class TSAP_WFTRESP_WR;
			class TSAP_Default;
			class ProviderState;
			template<typename Derived> class FSM;
			class Provider;
			
			
			// ProviderState.---------------------------------
			class ProviderState : public statemap::State {
			public:
				ProviderState(const char *name, int no) : statemap::State(name, no) {};
				
				virtual void Entry(FSM<Provider>&) {};
				virtual void Exit(FSM<Provider>&) {};
				
				virtual void AK(FSM<Provider>& context);
				virtual void CC(FSM<Provider>& context);
				virtual void CC(FSM<Provider>& context, const TPDU::CC* cc);
				virtual void CR(FSM<Provider>& context);
				virtual void CR(FSM<Provider>& context, const TPDU::CR* cr);
				virtual void DC(FSM<Provider>& context);
				virtual void DR(FSM<Provider>& context);
				virtual void DT(FSM<Provider>& context);
				virtual void DT(FSM<Provider>& context, BufferPtr& tsdu);
				virtual void EA(FSM<Provider>& context);
				virtual void ED(FSM<Provider>& context);
				virtual void ER(FSM<Provider>& context);
				virtual void NCONconf(FSM<Provider>& context);
				virtual void NCONconf(FSM<Provider>& context, Buffer* tdsu);
				virtual void NDISind(FSM<Provider>& context);
				virtual void NRSTind(FSM<Provider>& context);
				virtual void RJ(FSM<Provider>& context);
				virtual void TCONreq(FSM<Provider>& context);
				virtual void TCONreq(FSM<Provider>& context, TPDU::CR& tsdu);
				virtual void TCONresp(FSM<Provider>& context);
				virtual void TCONresp(FSM<Provider>& context, TPDU::CC& tsdu);
				virtual void TDISreq(FSM<Provider>& context);
				virtual void TDISreq(FSM<Provider>& context, TPDU::DR& tsdu);
				virtual void TDTreq(FSM<Provider>& context);
				virtual void TDTreq(FSM<Provider>& context, TPDU::DT& tsdu);
				virtual void TEXreq(FSM<Provider>& context);
			protected:
				virtual void Default(FSM<Provider>& context);
			};
			
			
			// FSM map default state class.-------------------
			class TSAP_Default : public ProviderState {
			public:
				TSAP_Default (const char *name, int stateId) : ProviderState(name, stateId)	{}
			};
			
			// FSM map states class.--------------------------
			// --------------------------------------------------
			class TSAP_AKWAIT:  public TSAP_Default { 
			public:
				TSAP_AKWAIT(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_CLOSED:  public TSAP_Default { 
			public:
				TSAP_CLOSED(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TCONreq(FSM<Provider>& context);
				void TCONreq(FSM<Provider>& context, TPDU::CR& tsdu);
				void CR(FSM<Provider>& context, const TPDU::CR* cr);
				void DR(FSM<Provider>& context);
				void DC(FSM<Provider>& context);
				void CC(FSM<Provider>& context);
				void AK(FSM<Provider>& context);
				void EA(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void DT(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class TSAP_CLOSING:  public TSAP_Default { 
			public:
				TSAP_CLOSING(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_CLOSING_BOC:  public TSAP_Default { 
			public:
				TSAP_CLOSING_BOC(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_CLOSING_BOC_WR:  public TSAP_Default { 
			public:
				TSAP_CLOSING_BOC_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_CLOSING_R:  public TSAP_Default { 
			public:
				TSAP_CLOSING_R(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_CLOSING_WR:  public TSAP_Default { 
			public:
				TSAP_CLOSING_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_ERROR:  public TSAP_Default { 
			public:
				TSAP_ERROR(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TCONreq(FSM<Provider>& context);
				void TCONresp(FSM<Provider>& context);
				void TDTreq(FSM<Provider>& context);
				void TEXreq(FSM<Provider>& context);
				void TDISreq(FSM<Provider>& context);
				void NDISind(FSM<Provider>& context);
				void NCONconf(FSM<Provider>& context);
				void NRSTind(FSM<Provider>& context);
				void CR(FSM<Provider>& context);
				void CC(FSM<Provider>& context);
				void DR(FSM<Provider>& context);
				void DC(FSM<Provider>& context);
				void AK(FSM<Provider>& context);
				void EA(FSM<Provider>& context);
				void DT(FSM<Provider>& context);
				void ED(FSM<Provider>& context);
				void ER(FSM<Provider>& context);
				void RJ(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class TSAP_OPEN:  public TSAP_Default { 
			public:
				TSAP_OPEN(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TDTreq(FSM<Provider>& context, TPDU::DT& tsdu);
				void TDISreq(FSM<Provider>& context);
				void TDISreq(FSM<Provider>& context, TPDU::DR& tsdu);
				void NRSTind(FSM<Provider>& context);
				void NDISind(FSM<Provider>& context);
				void CR(FSM<Provider>& context);
				void DT(FSM<Provider>& context, BufferPtr& tsdu);
				void DR(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class TSAP_OPEN_R:  public TSAP_Default { 
			public:
				TSAP_OPEN_R(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_OPEN_WR:  public TSAP_Default { 
			public:
				TSAP_OPEN_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_REFWAIT:  public TSAP_Default { 
			public:
				TSAP_REFWAIT(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WBCL:  public TSAP_Default { 
			public:
				TSAP_WBCL(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WBCL_R:  public TSAP_Default { 
			public:
				TSAP_WBCL_R(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WBCL_WR:  public TSAP_Default { 
			public:
				TSAP_WBCL_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WBOC:  public TSAP_Default { 
			public:
				TSAP_WBOC(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WBOC_WR:  public TSAP_Default { 
			public:
				TSAP_WBOC_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WFCC:  public TSAP_Default { 
			public:
				TSAP_WFCC(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TDISreq(FSM<Provider>& context);
				void NRSTind(FSM<Provider>& context);
				void NDISind(FSM<Provider>& context);
				void DR(FSM<Provider>& context);
				void CC(FSM<Provider>& context, const TPDU::CC* cc);
			};
			
			// --------------------------------------------------
			class TSAP_WFCC_R:  public TSAP_Default { 
			public:
				TSAP_WFCC_R(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WFNC:  public TSAP_Default { 
			public:
				TSAP_WFNC(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TDISreq(FSM<Provider>& context);
				void NCONconf(FSM<Provider>& context, Buffer* tdsu);
				void NDISind(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class TSAP_WFNC_R:  public TSAP_Default { 
			public:
				TSAP_WFNC_R(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// --------------------------------------------------
			class TSAP_WFTRESP:  public TSAP_Default { 
			public:
				TSAP_WFTRESP(const char* name, int no) : TSAP_Default(name, no) {}
				
				void Entry(FSM<Provider>& context);
				void Exit(FSM<Provider>& context);
				
				void TCONresp(FSM<Provider>& context, TPDU::CC& tsdu);
				void TDISreq(FSM<Provider>& context, TPDU::DR& tsdu);
				void NRSTind(FSM<Provider>& context);
				void NDISind(FSM<Provider>& context);
				void CR(FSM<Provider>& context);
				void DR(FSM<Provider>& context);
			};
			
			// --------------------------------------------------
			class TSAP_WFTRESP_WR:  public TSAP_Default { 
			public:
				TSAP_WFTRESP_WR(const char* name, int no) : TSAP_Default(name, no) {}
				
				
			};
			
			// FSM map class.---------------------------------
			class TSAP {
			public:
				TSAP();
				 TSAP_AKWAIT AKWAIT;
				 TSAP_CLOSED CLOSED;
				 TSAP_CLOSING CLOSING;
				 TSAP_CLOSING_BOC CLOSING_BOC;
				 TSAP_CLOSING_BOC_WR CLOSING_BOC_WR;
				 TSAP_CLOSING_R CLOSING_R;
				 TSAP_CLOSING_WR CLOSING_WR;
				 TSAP_ERROR ERROR;
				 TSAP_OPEN OPEN;
				 TSAP_OPEN_R OPEN_R;
				 TSAP_OPEN_WR OPEN_WR;
				 TSAP_REFWAIT REFWAIT;
				 TSAP_WBCL WBCL;
				 TSAP_WBCL_R WBCL_R;
				 TSAP_WBCL_WR WBCL_WR;
				 TSAP_WBOC WBOC;
				 TSAP_WBOC_WR WBOC_WR;
				 TSAP_WFCC WFCC;
				 TSAP_WFCC_R WFCC_R;
				 TSAP_WFNC WFNC;
				 TSAP_WFNC_R WFNC_R;
				 TSAP_WFTRESP WFTRESP;
				 TSAP_WFTRESP_WR WFTRESP_WR;
			};
			// FSM context class -----------------------------
			template<typename Derived>
			class FSM : public statemap::FSMContext, public TSAP {
			public:
				explicit 
				FSM() : FSMContext(TSAP::CLOSED) {};
				FSM(const statemap::State& state) : FSMContext(state) {};
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
				void AK() {
				    setTransition("AK");
				    getState().AK(*this);
				    setTransition(nullptr);
				};
				void CC() {
				    setTransition("CC");
				    getState().CC(*this);
				    setTransition(nullptr);
				};
				void CC(const TPDU::CC* cc) {
				    setTransition("CC");
				    getState().CC(*this, cc);
				    setTransition(nullptr);
				};
				void CR() {
				    setTransition("CR");
				    getState().CR(*this);
				    setTransition(nullptr);
				};
				void CR(const TPDU::CR* cr) {
				    setTransition("CR");
				    getState().CR(*this, cr);
				    setTransition(nullptr);
				};
				void DC() {
				    setTransition("DC");
				    getState().DC(*this);
				    setTransition(nullptr);
				};
				void DR() {
				    setTransition("DR");
				    getState().DR(*this);
				    setTransition(nullptr);
				};
				void DT() {
				    setTransition("DT");
				    getState().DT(*this);
				    setTransition(nullptr);
				};
				void DT(BufferPtr& tsdu) {
				    setTransition("DT");
				    getState().DT(*this, tsdu);
				    setTransition(nullptr);
				};
				void EA() {
				    setTransition("EA");
				    getState().EA(*this);
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
				void NCONconf() {
				    setTransition("NCONconf");
				    getState().NCONconf(*this);
				    setTransition(nullptr);
				};
				void NCONconf(Buffer* tdsu) {
				    setTransition("NCONconf");
				    getState().NCONconf(*this, tdsu);
				    setTransition(nullptr);
				};
				void NDISind() {
				    setTransition("NDISind");
				    getState().NDISind(*this);
				    setTransition(nullptr);
				};
				void NRSTind() {
				    setTransition("NRSTind");
				    getState().NRSTind(*this);
				    setTransition(nullptr);
				};
				void RJ() {
				    setTransition("RJ");
				    getState().RJ(*this);
				    setTransition(nullptr);
				};
				void TCONreq() {
				    setTransition("TCONreq");
				    getState().TCONreq(*this);
				    setTransition(nullptr);
				};
				void TCONreq(TPDU::CR& tsdu) {
				    setTransition("TCONreq");
				    getState().TCONreq(*this, tsdu);
				    setTransition(nullptr);
				};
				void TCONresp() {
				    setTransition("TCONresp");
				    getState().TCONresp(*this);
				    setTransition(nullptr);
				};
				void TCONresp(TPDU::CC& tsdu) {
				    setTransition("TCONresp");
				    getState().TCONresp(*this, tsdu);
				    setTransition(nullptr);
				};
				void TDISreq() {
				    setTransition("TDISreq");
				    getState().TDISreq(*this);
				    setTransition(nullptr);
				};
				void TDISreq(TPDU::DR& tsdu) {
				    setTransition("TDISreq");
				    getState().TDISreq(*this, tsdu);
				    setTransition(nullptr);
				};
				void TDTreq() {
				    setTransition("TDTreq");
				    getState().TDTreq(*this);
				    setTransition(nullptr);
				};
				void TDTreq(TPDU::DT& tsdu) {
				    setTransition("TDTreq");
				    getState().TDTreq(*this, tsdu);
				    setTransition(nullptr);
				};
				void TEXreq() {
				    setTransition("TEXreq");
				    getState().TEXreq(*this);
				    setTransition(nullptr);
				};
			};
		}
	}
}
#endif
