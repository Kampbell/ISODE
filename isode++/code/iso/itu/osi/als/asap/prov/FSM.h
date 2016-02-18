/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : ASAP.sm
 */

#ifndef _H_FSM_ASAP
#define _H_FSM_ASAP


#define SMC_USES_IOSTREAMS

#include "statemap.h"

namespace ALS
{
    namespace ASAP
    {
        namespace PROV
        {
            // Forward declarations.
            class STATE;
            class STATE_STA0;
            class STATE_STA1;
            class STATE_STA2;
            class STATE_STA3;
            class STATE_STA4;
            class STATE_STA5;
            class STATE_STA6;
            class STATE_STA7;
            class STATE_Default;
            class ProviderState;
            class FSM;
            class Provider;

            class ProviderState :
                public statemap::State
            {
            public:

                ProviderState(const char *name, int stateId)
                : statemap::State(name, stateId)
                {};

                virtual void Entry(FSM&) {};
                virtual void Exit(FSM&) {};

                virtual void A_ABRreq(FSM& context);
                virtual void A_ASCreq(FSM& context);
                virtual void A_ASCrsp(FSM& context, bool accept);
                virtual void A_RLSreq(FSM& context);
                virtual void A_RLSrsp(FSM& context, bool accept);
                virtual void AARE(FSM& context, bool accept);
                virtual void AARQ(FSM& context);
                virtual void ABRT(FSM& context);
                virtual void EXTERN_1(FSM& context);
                virtual void EXTERN_2(FSM& context);
                virtual void EXTERN_3(FSM& context);
                virtual void P_CONcnf(FSM& context, bool accept);
                virtual void P_PABind(FSM& context);
                virtual void RLRE(FSM& context, bool accept);
                virtual void RLRQ(FSM& context);

            protected:

                virtual void Default(FSM& context);
            };

            class STATE_Default :
                public ProviderState
            {
            public:

                STATE_Default(const char *name, int stateId)
                : ProviderState(name, stateId)
                {};

            };

            class STATE_STA0 :
                public STATE_Default
            {
            public:
                STATE_STA0(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ASCreq(FSM& context);
                void AARQ(FSM& context);
            };

            class STATE_STA1 :
                public STATE_Default
            {
            public:
                STATE_STA1(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void AARE(FSM& context, bool accept);
                void ABRT(FSM& context);
                void P_CONcnf(FSM& context, bool accept);
                void P_PABind(FSM& context);
            };

            class STATE_STA2 :
                public STATE_Default
            {
            public:
                STATE_STA2(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void A_ASCrsp(FSM& context, bool accept);
                void ABRT(FSM& context);
                void P_PABind(FSM& context);
            };

            class STATE_STA3 :
                public STATE_Default
            {
            public:
                STATE_STA3(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void ABRT(FSM& context);
                void EXTERN_1(FSM& context);
                void P_PABind(FSM& context);
                void RLRE(FSM& context, bool accept);
                void RLRQ(FSM& context);
            };

            class STATE_STA4 :
                public STATE_Default
            {
            public:
                STATE_STA4(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void A_RLSrsp(FSM& context, bool accept);
                void ABRT(FSM& context);
                void EXTERN_3(FSM& context);
                void P_PABind(FSM& context);
            };

            class STATE_STA5 :
                public STATE_Default
            {
            public:
                STATE_STA5(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void A_RLSreq(FSM& context);
                void ABRT(FSM& context);
                void EXTERN_1(FSM& context);
                void EXTERN_2(FSM& context);
                void P_PABind(FSM& context);
                void RLRQ(FSM& context);
            };

            class STATE_STA6 :
                public STATE_Default
            {
            public:
                STATE_STA6(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void A_RLSrsp(FSM& context, bool accept);
                void ABRT(FSM& context);
                void P_PABind(FSM& context);
            };

            class STATE_STA7 :
                public STATE_Default
            {
            public:
                STATE_STA7(const char *name, int stateId)
                : STATE_Default(name, stateId)
                {};

                void A_ABRreq(FSM& context);
                void ABRT(FSM& context);
                void P_PABind(FSM& context);
                void RLRE(FSM& context, bool accept);
            };

            class STATE
            {
            public:
            STATE_STA0 STA0;
            STATE_STA1 STA1;
            STATE_STA2 STA2;
            STATE_STA3 STA3;
            STATE_STA4 STA4;
            STATE_STA5 STA5;
            STATE_STA6 STA6;
            STATE_STA7 STA7;
            // member class initiatlization.
            STATE() : 
            STA0("STATE::STA0", 0),
            STA1("STATE::STA1", 1),
            STA2("STATE::STA2", 2),
            STA3("STATE::STA3", 3),
            STA4("STATE::STA4", 4),
            STA5("STATE::STA5", 5),
            STA6("STATE::STA6", 6),
            STA7("STATE::STA7", 7){}
            };

            class FSM :
                public statemap::FSMContext,
                public STATE
            {
            public:

                FSM(Provider& owner)
                : FSMContext(STATE::STA0),
                  _owner(owner)
                {};

                FSM(Provider& owner, const statemap::State& state)
                : FSMContext(state),
                  _owner(owner)
                {};

                virtual void enterStartState()
                {
                    getState().Entry(*this);
                    return;
                }

                Provider& getOwner() const
                {
                    return (_owner);
                };

                ProviderState& getState() const
                {
                    if (_state == nullptr)
                    {
                        throw statemap::StateUndefinedException();
                    }

                    return (dynamic_cast<ProviderState&>(*_state));
                };

                void A_ABRreq()
                {
                    (getState()).A_ABRreq(*this);
                };

                void A_ASCreq()
                {
                    (getState()).A_ASCreq(*this);
                };

                void A_ASCrsp(bool accept)
                {
                    (getState()).A_ASCrsp(*this, accept);
                };

                void A_RLSreq()
                {
                    (getState()).A_RLSreq(*this);
                };

                void A_RLSrsp(bool accept)
                {
                    (getState()).A_RLSrsp(*this, accept);
                };

                void AARE(bool accept)
                {
                    (getState()).AARE(*this, accept);
                };

                void AARQ()
                {
                    (getState()).AARQ(*this);
                };

                void ABRT()
                {
                    (getState()).ABRT(*this);
                };

                void EXTERN_1()
                {
                    (getState()).EXTERN_1(*this);
                };

                void EXTERN_2()
                {
                    (getState()).EXTERN_2(*this);
                };

                void EXTERN_3()
                {
                    (getState()).EXTERN_3(*this);
                };

                void P_CONcnf(bool accept)
                {
                    (getState()).P_CONcnf(*this, accept);
                };

                void P_PABind()
                {
                    (getState()).P_PABind(*this);
                };

                void RLRE(bool accept)
                {
                    (getState()).RLRE(*this, accept);
                };

                void RLRQ()
                {
                    (getState()).RLRQ(*this);
                };

            private:

                Provider& _owner;
            };
        }

    }

}


#endif // _H_FSM_ASAP

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
