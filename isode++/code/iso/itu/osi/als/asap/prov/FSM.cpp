/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : ASAP.sm
 */

#include "als/asap/prov/Provider.h"
#include ".\FSM.h"

using namespace statemap;

namespace ALS
{
    namespace ASAP
    {
        namespace PROV
        {

            void ProviderState::A_ABRreq(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::A_ASCreq(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::A_ASCrsp(FSM& context, bool accept)
            {
                Default(context);
                return;
            }

            void ProviderState::A_RLSreq(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::A_RLSrsp(FSM& context, bool accept)
            {
                Default(context);
                return;
            }

            void ProviderState::AARE(FSM& context, bool accept)
            {
                Default(context);
                return;
            }

            void ProviderState::AARQ(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::ABRT(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::EXTERN_1(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::EXTERN_2(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::EXTERN_3(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::P_CONcnf(FSM& context, bool accept)
            {
                Default(context);
                return;
            }

            void ProviderState::P_PABind(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::RLRE(FSM& context, bool accept)
            {
                Default(context);
                return;
            }

            void ProviderState::RLRQ(FSM& context)
            {
                Default(context);
                return;
            }

            void ProviderState::Default(FSM& context)
            {
                throw (
                    TransitionUndefinedException(
                        context.getState().getName(),
                        context.getTransition()));

                return;
            }

            void STATE_STA0::A_ASCreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ASCreq");

                if (ctxt.p1())
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA1);
            ctxt.AARQ();
                    }
                    catch (...)
                    {
                        context.setState(context.STA1);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else
                {
                     STATE_Default::A_ASCreq(context);
                }

                return;
            }

            void STATE_STA0::AARQ(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("AARQ");

                if (ctxt.p1())
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA2);
            ctxt.A_ASCind();
                    }
                    catch (...)
                    {
                        context.setState(context.STA2);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!ctxt.p1())
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA0);
            ctxt.AARE(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA0);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::AARQ(context);
                }

                return;
            }

            void STATE_STA1::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA1::AARE(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("AARE");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA5);
            ctxt.A_ASCcnf(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA5);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!accept)
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA0);
            ctxt.A_ASCcnf(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA0);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::AARE(context, accept);
                }

                return;
            }

            void STATE_STA1::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA1::P_CONcnf(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_CONcnf");

                if (!accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA0);
            ctxt.A_ASCcnf(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA0);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else
                {
                     STATE_Default::P_CONcnf(context, accept);
                }

                return;
            }

            void STATE_STA1::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA2::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA2::A_ASCrsp(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ASCrsp");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA5);
            ctxt.AARE(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA5);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!accept)
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA5);
            ctxt.AARE(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA5);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::A_ASCrsp(context, accept);
                }

                return;
            }

            void STATE_STA2::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA2::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA3::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA3::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA3::EXTERN_1(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("EXTERN_1");

                (context.getState()).Exit(context);
                context.setState(context.STA5);
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA3::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA3::RLRE(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("RLRE");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA0);
            ctxt.A_RLScnf(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA0);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!accept)
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA5);
            ctxt.A_RLScnf(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA5);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::RLRE(context, accept);
                }

                return;
            }

            void STATE_STA3::RLRQ(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("RLRQ");

                if (ctxt.p2())
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA6);
            ctxt.A_RLSind();
                    }
                    catch (...)
                    {
                        context.setState(context.STA6);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!ctxt.p2())
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA7);
            ctxt.A_RLSind();
                    }
                    catch (...)
                    {
                        context.setState(context.STA7);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::RLRQ(context);
                }

                return;
            }

            void STATE_STA4::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA4::A_RLSrsp(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_RLSrsp");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA0);
            ctxt.RLRE(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA0);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else if (!accept)
            
    {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA5);
            ctxt.RLRE(false);
                    }
                    catch (...)
                    {
                        context.setState(context.STA5);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }                else
                {
                     STATE_Default::A_RLSrsp(context, accept);
                }

                return;
            }

            void STATE_STA4::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA4::EXTERN_3(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("EXTERN_3");

                (context.getState()).Exit(context);
                context.setState(context.STA5);
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA4::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::A_RLSreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_RLSreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA3);
            ctxt.RLRQ();
                }
                catch (...)
                {
                    context.setState(context.STA3);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::EXTERN_1(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("EXTERN_1");

                (context.getState()).Exit(context);
                context.setState(context.STA5);
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::EXTERN_2(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("EXTERN_2");

                (context.getState()).Exit(context);
                context.setState(context.STA5);
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA5::RLRQ(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("RLRQ");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA4);
            ctxt.A_RLSind();
                }
                catch (...)
                {
                    context.setState(context.STA4);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA6::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA6::A_RLSrsp(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_RLSrsp");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA3);
            ctxt.RLRE(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA3);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else
                {
                     STATE_Default::A_RLSrsp(context, accept);
                }

                return;
            }

            void STATE_STA6::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA6::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA7::A_ABRreq(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("A_ABRreq");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.ABRT();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA7::ABRT(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("ABRT");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA7::P_PABind(FSM& context)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("P_PABind");

                (context.getState()).Exit(context);
                context.clearState();
                try
                {
                    context.setState(context.STA0);
            ctxt.A_ABRind();
                }
                catch (...)
                {
                    context.setState(context.STA0);
                    throw;
                }
                (context.getState()).Entry(context);

                return;
            }

            void STATE_STA7::RLRE(FSM& context, bool accept)
            {
                Provider& ctxt = context.getOwner();
                context.setTransition("RLRE");

                if (accept)
                {
                    (context.getState()).Exit(context);
                    context.clearState();
                    try
                    {
                        context.setState(context.STA4);
            ctxt.A_RLScnf(true);
                    }
                    catch (...)
                    {
                        context.setState(context.STA4);
                        throw;
                    }
                    (context.getState()).Entry(context);
                }
                else
                {
                     STATE_Default::RLRE(context, accept);
                }

                return;
            }
        }
    }
}

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
