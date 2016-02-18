#ifndef FOO
#define FOO
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
			class FSM;
			class Provider;
			
			
			// ProviderState.---------------------------------
			class ProviderState : public statemap::State {
			public:
				ProviderState(const char *name, int no) : statemap::State(name, no) {};
				
				virtual void Entry(FSM&) {};
				virtual void Exit(FSM&) {};
				virtual void AK(FSM& context);
				virtual void CC(FSM& context);
				virtual void CR(FSM& context);
				virtual void DC(FSM& context);
				virtual void DR(FSM& context);
				virtual void DT(FSM& context);
				virtual void DT(FSM& context, shared_ptr<Buffer>& tsdu);
				virtual void EA(FSM& context);
				virtual void ED(FSM& context);
				virtual void ER(FSM& context);
				virtual void NCONconf(FSM& context);
				virtual void NCONconf(FSM& context, Buffer* tdsu);
				virtual void NDISind(FSM& context);
				virtual void NRSTind(FSM& context);
				virtual void RJ(FSM& context);
				virtual void TCONreq(FSM& context);
				virtual void TCONreq(FSM& context, TPDU::CR& tsdu);
				virtual void TCONresp(FSM& context);
				virtual void TCONresp(FSM& context, TPDU::CC& tsdu);
				virtual void TDISreq(FSM& context);
				virtual void TDISreq(FSM& context, TPDU::DR& tsdu);
				virtual void TDTreq(FSM& context);
				virtual void TDTreq(FSM& context, TPDU::DT& tsdu);
				virtual void TEXreq(FSM& context);
			protected:
				virtual void Default(FSM& context);
			};
			
			// FSM map class.---------------------------------
			class TSAP {
			public:
				static TSAP_AKWAIT AKWAIT;
				static TSAP_CLOSED CLOSED;
				static TSAP_CLOSING CLOSING;
				static TSAP_CLOSING_BOC CLOSING_BOC;
				static TSAP_CLOSING_BOC_WR CLOSING_BOC_WR;
				static TSAP_CLOSING_R CLOSING_R;
				static TSAP_CLOSING_WR CLOSING_WR;
				static TSAP_ERROR ERROR;
				static TSAP_OPEN OPEN;
				static TSAP_OPEN_R OPEN_R;
				static TSAP_OPEN_WR OPEN_WR;
				static TSAP_REFWAIT REFWAIT;
				static TSAP_WBCL WBCL;
				static TSAP_WBCL_R WBCL_R;
				static TSAP_WBCL_WR WBCL_WR;
				static TSAP_WBOC WBOC;
				static TSAP_WBOC_WR WBOC_WR;
				static TSAP_WFCC WFCC;
				static TSAP_WFCC_R WFCC_R;
				static TSAP_WFNC WFNC;
				static TSAP_WFNC_R WFNC_R;
				static TSAP_WFTRESP WFTRESP;
				static TSAP_WFTRESP_WR WFTRESP_WR;
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
				void TCONreq(FSM& context);
				void TCONreq(FSM& context, TPDU::CR& tsdu);
				void CR(FSM& context);
				void DR(FSM& context);
				void DC(FSM& context);
				void CC(FSM& context);
				void AK(FSM& context);
				void EA(FSM& context);
				void ED(FSM& context);
				void DT(FSM& context);
				void ER(FSM& context);
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
				void TCONreq(FSM& context);
				void TCONresp(FSM& context);
				void TDTreq(FSM& context);
				void TEXreq(FSM& context);
				void TDISreq(FSM& context);
				void NDISind(FSM& context);
				void NCONconf(FSM& context);
				void NRSTind(FSM& context);
				void CR(FSM& context);
				void CC(FSM& context);
				void DR(FSM& context);
				void DC(FSM& context);
				void AK(FSM& context);
				void EA(FSM& context);
				void DT(FSM& context);
				void ED(FSM& context);
				void ER(FSM& context);
				void RJ(FSM& context);
			};
			
			// --------------------------------------------------
			class TSAP_OPEN:  public TSAP_Default { 
			public:
				TSAP_OPEN(const char* name, int no) : TSAP_Default(name, no) {}
				void TDTreq(FSM& context, TPDU::DT& tsdu);
				void TDISreq(FSM& context);
				void TDISreq(FSM& context, TPDU::DR& tsdu);
				void NRSTind(FSM& context);
				void NDISind(FSM& context);
				void CR(FSM& context);
				void DT(FSM& context, shared_ptr<Buffer>& tsdu);
				void DR(FSM& context);
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
				void TDISreq(FSM& context);
				void NRSTind(FSM& context);
				void NDISind(FSM& context);
				void DR(FSM& context);
				void CC(FSM& context);
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
				void TDISreq(FSM& context);
				void NCONconf(FSM& context, Buffer* tdsu);
				void NDISind(FSM& context);
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
				void TCONresp(FSM& context, TPDU::CC& tsdu);
				void TDISreq(FSM& context, TPDU::DR& tsdu);
				void NRSTind(FSM& context);
				void NDISind(FSM& context);
				void CR(FSM& context);
				void DR(FSM& context);
			};
			
			// --------------------------------------------------
			class TSAP_WFTRESP_WR:  public TSAP_Default { 
			public:
				TSAP_WFTRESP_WR(const char* name, int no) : TSAP_Default(name, no) {}
			};
			
			// FSM context class -----------------------------
			class FSM : public statemap::FSMContext {
			public:
				FSM(Provider& owner) : FSMContext(TSAP::CLOSED), _owner(owner) {};
				FSM(Provider& owner, const statemap::State& state) : FSMContext(state), _owner(owner) {};
				virtual void enterStartState() {
				    getState().Entry(*this);
				    return;
				}
				Provider& getOwner() const {
				    return (_owner);
				};
				ProviderState& getState() const {
				    if (_state == nullptr) {
				        throw statemap::StateUndefinedException();
				    }
				     return (dynamic_cast<ProviderState&>(*_state));
				};
				void AK() {
				     (getState()).AK(*this);
				};
				void CC() {
				     (getState()).CC(*this);
				};
				void CR() {
				     (getState()).CR(*this);
				};
				void DC() {
				     (getState()).DC(*this);
				};
				void DR() {
				     (getState()).DR(*this);
				};
				void DT() {
				     (getState()).DT(*this);
				};
				void DT(shared_ptr<Buffer>& tsdu) {
				     (getState()).DT(*this, tsdu);
				};
				void EA() {
				     (getState()).EA(*this);
				};
				void ED() {
				     (getState()).ED(*this);
				};
				void ER() {
				     (getState()).ER(*this);
				};
				void NCONconf() {
				     (getState()).NCONconf(*this);
				};
				void NCONconf(Buffer* tdsu) {
				     (getState()).NCONconf(*this, tdsu);
				};
				void NDISind() {
				     (getState()).NDISind(*this);
				};
				void NRSTind() {
				     (getState()).NRSTind(*this);
				};
				void RJ() {
				     (getState()).RJ(*this);
				};
				void TCONreq() {
				     (getState()).TCONreq(*this);
				};
				void TCONreq(TPDU::CR& tsdu) {
				     (getState()).TCONreq(*this, tsdu);
				};
				void TCONresp() {
				     (getState()).TCONresp(*this);
				};
				void TCONresp(TPDU::CC& tsdu) {
				     (getState()).TCONresp(*this, tsdu);
				};
				void TDISreq() {
				     (getState()).TDISreq(*this);
				};
				void TDISreq(TPDU::DR& tsdu) {
				     (getState()).TDISreq(*this, tsdu);
				};
				void TDTreq() {
				     (getState()).TDTreq(*this);
				};
				void TDTreq(TPDU::DT& tsdu) {
				     (getState()).TDTreq(*this, tsdu);
				};
				void TEXreq() {
				     (getState()).TEXreq(*this);
				};
			private:
			    Provider& _owner;
			};
		}
	}
}
#endif
