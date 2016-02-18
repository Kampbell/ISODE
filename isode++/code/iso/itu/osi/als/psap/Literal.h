/*
 * Literal.h
 *
 *  Created on: 22 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_LITERAL_H_
#define ALS_PSAP_LITERAL_H_

namespace ALS {
namespace PSAP {

class Literal {
public:
	/** The Literal P-SYNC-MAJOR.INDICATION. */
	static const char*	P_SYNC_MAJOR_INDICATION	;

	/** The Literal P-SYNC-MINOR.INDICATION. */
	static const char*	P_SYNC_MINOR_INDICATION;

	/** The Literal P-RESYNCHRONIZE.INDICATION. */
	static const char*	P_RESYNCHRONIZE_INDICATION;

	/** The Literal P-SYNC-MINOR.CONFIRMATION. */
	static const char*	P_SYNC_MINOR_CONFIRMATION;

	/** The Literal P-SYNC-MAJOR.CONFIRMATION. */
	static const char*	P_SYNC_MAJOR_CONFIRMATION;

	/** The Literal P-RESYNCHRONIZE.CONFIRMATION. */
	static const char*	P_RESYNCHRONIZE_CONFIRMATION;

	/** The Literal P-TOKEN-GIVE.INDICATION. */
	static const char*	P_TOKEN_GIVE_INDICATION;

	/** The Literal P-TOKEN-PLEASE.INDICATION. */
	static const char*	P_TOKEN_PLEASE_INDICATION;

	/** The Literal P-CONTROL-GIVE.INDICATION. */
	static const char*	P_CONTROL_GIVE_INDICATION;

	/** The Literal P-ABORT.INDICATION. */
	static const char*	P_U_ABORT_INDICATION;

	/** The Literal P-ABORT.INDICATION. */
	static const char*	P_P_ABORT_INDICATION;

	/** The literal P-ACTIVITY_INTERRUPT.CONFIRMATION */
	static const char*	P_ACTIVITY_INTERRUPT_CONFIRMATION;

	/** The literal P-ACTIVITY-DISCARD.CONFIRMATION. */
	static const char*	P_ACTIVITY_DISCARD_CONFIRMATION;

	/** The literal P-ACTIVITY-END.CONFIRMATION. */
	static const char*	P_ACTIVITY_END_CONFIRMATION;

	/** The literal P-ACTIVITY-START.INDICATION. */
	static const char*	P_ACTIVITY_START_INDICATION;

	/** The literal P-ACTIVITY-RESUME.INDICATION. */
	static const char*	P_ACTIVITY_RESUME_INDICATION;

	/** The literal P-ACTIVITY-INTERRUPT.INDICATION. */
	static const char*	P_ACTIVITY_INTERRUPT_INDICATION;

	/** The literal P-ACTIVITY-DISCARD.INDICATION. */
	static const char*	P_ACTIVITY_DISCARD_INDICATION;

	/** The literal P-ACTIVITY-END.INDICATION. */
	static const char*	P_ACTIVITY_END_INDICATION;

	/** The char* P-DATA.INDICATION. */
	static const char*	P_DATA_INDICATION;

	/** The char* P-EXPEDITED-DATA.INDICATION. */
	static const char*	P_EXPEDITED_DATA_INDICATION;

	/** The char* P-TYPED-DATA.INDICATION. */
	static const char*	P_TYPED_DATA_INDICATION;

	/** The char* P-CAPABILITY-DATA.INDICATION. */
	static const char*	P_CAPABILITY_DATA_INDICATION;

	/** The char* P-CAPABILITY-DATA.CONFIRMATION. */
	static const char*	P_CAPABILITY_DATA_CONFIRMATION;

	/** The Literal P-U-ABORT.REQUEST. */
	static const char*	P_U_ABORT_REQUEST;

	/** The Literal P-P-ABORT.REQUEST. */
	static const char*	P_P_ABORT_REQUEST;

	/** The Literal P-RELEASE.REQUEST. */
	static const char*	P_RELEASE_REQUEST;

	/** The Literal P-RELEASE.RESPONSE. */
	static const char*	P_RELEASE_RESPONSE;

	/** The Literal P-RELEASE-RETRY.REQUEST. */
	static const char*	P_RELEASE_RETRY_REQUEST;

	/** The Literal P-CAPABILITY-DATA.REQUEST. */
	static const char*	P_CAPABILITY_DATA_REQUEST;

	/** The Literal P-CAPABILITY-DATA.RESPONSE. */
	static const char*	P_CAPABILITY_DATA_RESPONSE;

	/** The Literal P-DATA.REQUEST. */
	static const char*	P_DATA_REQUEST;

	/** The Literal P-EXPEDITED-DATA.REQUEST. */
	static const char*	P_EXPEDITED_DATA_REQUEST;

	/** The Literal P-TYPED-DATA.REQUEST. */
	static const char*	P_TYPED_DATA_REQUEST;

	/** The Literal P-SEND.REQUEST  (segmented) .*/
	static const char*	P_SEND_REQUEST;

	/** The Literal P-WRITE.REQUEST (pseudo). */
	static const char*	P_WRITE_REQUEST;

	/** The literal P-U-EXCEPTION-REPORT.INDICATION. */
	static const char*	P_U_EXCEPTION_REPORT_INDICATION;

	/** The literal P-P-EXCEPTION-REPORT.INDICATION. */
	static const char*	P_P_EXCEPTION_REPORT_INDICATION;

	/** The Literal P-U-EXCEPTION-REPORT.REQUEST. */
	static const char*	P_U_EXCEPTION_REPORT_REQUEST;

	/** The Literal P-P-EXCEPTION-REPORT.REQUEST. */
	static const char*	P_P_EXCEPTION_REPORT_REQUEST;

	/** The Literal P-CONNECT.REQUEST. */
	static const char*	P_CONNECT_REQUEST;

	/** The Literal P-CONNECT.INDICATION. */
	static const char*	P_CONNECT_INDICATION;

	/** The Literal P-CONNECT.RESPONSE. */
	static const char*	P_CONNECT_RESPONSE;

	/** The literal P-CONNECT.CONFIRMATION */
	static const char*	P_CONNECT_CONFIRMATION;

	/** The Literal P-ALTER-CONTEXT.REQUEST. */
	static const char*	P_ALTER_CONTEXT_REQUEST;

	/** The Literal P-ALTER-CONTEXT.INDICATION. */
	static const char*	P_ALTER_CONTEXT_INDICATION;

	/** The Literal P-ALTER-CONTEXT.RESPONSE. */
	static const char*	P_ALTER_CONTEXT_RESPONSE;

	/** The literal P-ALTER-CONTEXT.CONFIRMATION */
	static const char*	P_ALTER_CONTEXT_CONFIRMATION;

	/** The Literal P-READ.REQUEST. */
	static const char*	P_READ_REQUEST;

	/** The Literal P-RESYNCHRONIZE.REQUEST. */
	static const char*	P_RESYNCHRONIZE_REQUEST;

	/** The Literal P-RESYNCHRONIZE.RESPONSE. */
	static const char*	P_RESYNCHRONIZE_RESPONSE;

	/** The Literal P-SYNC-MAJOR_REQUEST. */
	static const char*	P_SYNC_MAJOR_REQUEST;

	/** The Literal P-SYNC-MINOR.REQUEST. */
	static const char*	P_SYNC_MINOR_REQUEST;

	/** The Literal P-SYNC-MAJOR.RESPONSE. */
	static const char*	P_SYNC_MAJOR_RESPONSE;

	/** The Literal P-SYNC-MINOR.RESPONSE. */
	static const char*	P_SYNC_MINOR_RESPONSE;

	/** The Literal P-CONTROL-GIVE.REQUEST. */
	static const char*	P_CONTROL_GIVE_REQUEST;

	/** The Literal P-TOKEN-GIVE.REQUEST. */
	static const char*	P_TOKEN_GIVE_REQUEST;

	/** The Literal P-TOKEN-PLEASE.REQUEST. */
	static const char*	P_TOKEN_PLEASE_REQUEST;

	/** The Literal P-ACTIVITY-DISCARD.REQUEST. */
	static const char*	P_ACTIVITY_DISCARD_REQUEST;

	/** The Literal P-ACTIVITY-DISCARD.RESPONSE. */
	static const char*	P_ACTIVITY_DISCARD_RESPONSE;

	/** The Literal P-ACTIVITY-END.REQUEST. */
	static const char*	P_ACTIVITY_END_REQUEST;

	/** The Literal P-ACTIVITY-END.RESPONSE. */
	static const char*	P_ACTIVITY_END_RESPONSE;

	/** The Literal P-ACTIVITY-INTERRUPT.REQUEST. */
	static const char*	P_ACTIVITY_INTERRUPT_REQUEST;

	/** The Literal P-ACTIVITY-INTERRUPT.RESPONSE. */
	static const char*	P_ACTIVITY_INTERRUPT_RESPONSE;

	/** The Literal P-ACTIVITY-RESUME.REQUEST. */
	static const char*	P_ACTIVITY_RESUME_REQUEST;

	/** The Literal P-ACTIVITY-START.REQUEST. */
	static const char*	P_ACTIVITY_START_REQUEST;

	/** The Literal P-RELEASE.INDICATION. */
	static const char*	P_RELEASE_INDICATION;

	/** The Literal P-RELEASE.CONFIRMATION. */
	static const char*	P_RELEASE_CONFIRMATION;

	Literal() {
	}
	virtual ~Literal() {
	}
};

}
}

#endif
