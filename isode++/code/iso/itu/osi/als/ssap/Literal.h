/*
 * Literal.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_LITERAL_H_
#define ALS_SSAP_LITERAL_H_
#include "als/ssap/ssap.h"

namespace ALS {
namespace SSAP {

class SSAP_API Literal {
public:
	/** The Literal S-SYNC-MAJOR.INDICATION. */
	static const char*	S_SYNC_MAJOR_INDICATION	;

	/** The Literal S-SYNC-MINOR.INDICATION. */
	static const char*	S_SYNC_MINOR_INDICATION;

	/** The Literal S-RESYNCHRONIZE.INDICATION. */
	static const char*	S_RESYNCHRONIZE_INDICATION;

	/** The Literal S-SYNC-MINOR.CONFIRMATION. */
	static const char*	S_SYNC_MINOR_CONFIRMATION;

	/** The Literal S-SYNC-MAJOR.CONFIRMATION. */
	static const char*	S_SYNC_MAJOR_CONFIRMATION;

	/** The Literal S-RESYNCHRONIZE.CONFIRMATION. */
	static const char*	S_RESYNCHRONIZE_CONFIRMATION;

	/** The Literal S-TOKEN-GIVE.INDICATION. */
	static const char*	S_TOKEN_GIVE_INDICATION;

	/** The Literal S-TOKEN-PLEASE.INDICATION. */
	static const char*	S_TOKEN_PLEASE_INDICATION;

	/** The Literal S-CONTROL-GIVE.INDICATION. */
	static const char*	S_CONTROL_GIVE_INDICATION;

	/** The Literal S-ABORT.INDICATION. */
	static const char*	S_U_ABORT_INDICATION;

	/** The Literal S-ABORT.INDICATION. */
	static const char*	S_P_ABORT_INDICATION;

	/** The literal S-ACTIVITY_INTERRUPT.CONFIRMATION */
	static const char*	S_ACTIVITY_INTERRUPT_CONFIRMATION;

	/** The literal S-ACTIVITY-DISCARD.CONFIRMATION. */
	static const char*	S_ACTIVITY_DISCARD_CONFIRMATION;

	/** The literal S-ACTIVITY-END.CONFIRMATION. */
	static const char*	S_ACTIVITY_END_CONFIRMATION;

	/** The literal S-ACTIVITY-START.INDICATION. */
	static const char*	S_ACTIVITY_START_INDICATION;

	/** The literal S-ACTIVITY-RESUME.INDICATION. */
	static const char*	S_ACTIVITY_RESUME_INDICATION;

	/** The literal S-ACTIVITY-INTERRUPT.INDICATION. */
	static const char*	S_ACTIVITY_INTERRUPT_INDICATION;

	/** The literal S-ACTIVITY-DISCARD.INDICATION. */
	static const char*	S_ACTIVITY_DISCARD_INDICATION;

	/** The literal S-ACTIVITY-END.INDICATION. */
	static const char*	S_ACTIVITY_END_INDICATION;

	/** The char* S-DATA.INDICATION. */
	static const char*	S_DATA_INDICATION;

	/** The char* S-EXPEDITED-DATA.INDICATION. */
	static const char*	S_EXPEDITED_DATA_INDICATION;

	/** The char* S-TYPED-DATA.INDICATION. */
	static const char*	S_TYPED_DATA_INDICATION;

	/** The char* S-CAPABILITY-DATA.INDICATION. */
	static const char*	S_CAPABILITY_DATA_INDICATION;

	/** The char* S-CAPABILITY-DATA.CONFIRMATION. */
	static const char*	S_CAPABILITY_DATA_CONFIRMATION;

	/** The Literal S-U-ABORT.REQUEST. */
	static const char*	S_U_ABORT_REQUEST;

	/** The Literal S-P-ABORT.REQUEST. */
	static const char*	S_P_ABORT_REQUEST;

	/** The Literal S-RELEASE.REQUEST. */
	static const char*	S_RELEASE_REQUEST;

	/** The Literal S-RELEASE.RESPONSE. */
	static const char*	S_RELEASE_RESPONSE;

	/** The Literal S-RELEASE-RETRY.REQUEST. */
	static const char*	S_RELEASE_RETRY_REQUEST;

	/** The Literal S-CAPABILITY-DATA.REQUEST. */
	static const char*	S_CAPABILITY_DATA_REQUEST;

	/** The Literal S-CAPABILITY-DATA.RESPONSE. */
	static const char*	S_CAPABILITY_DATA_RESPONSE;

	/** The Literal S-DATA.REQUEST. */
	static const char*	S_DATA_REQUEST;

	/** The Literal S-EXPEDITED-DATA.REQUEST. */
	static const char*	S_EXPEDITED_DATA_REQUEST;

	/** The Literal S-TYPED-DATA.REQUEST. */
	static const char*	S_TYPED_DATA_REQUEST;

	/** The Literal S-SEND.REQUEST  (segmented) .*/
	static const char*	S_SEND_REQUEST;

	/** The Literal S-WRITE.REQUEST (pseudo). */
	static const char*	S_WRITE_REQUEST;

	/** The literal S-U-EXCEPTION-REPORT.INDICATION. */
	static const char*	S_U_EXCEPTION_REPORT_INDICATION;

	/** The literal S-P-EXCEPTION-REPORT.INDICATION. */
	static const char*	S_P_EXCEPTION_REPORT_INDICATION;

	/** The Literal S-U-EXCEPTION-REPORT.REQUEST. */
	static const char*	S_U_EXCEPTION_REPORT_REQUEST;

	/** The Literal S-P-EXCEPTION-REPORT.REQUEST. */
	static const char*	S_P_EXCEPTION_REPORT_REQUEST;

	/** The literal S-CONNECT.CONFIRMATION */
	static const char*	S_CONNECT_CONFIRMATION;

	/** The Literal S-CONNECT.INDICATION. */
	static const char*	S_CONNECT_INDICATION;

	/** The Literal S-CONNECT.REQUEST. */
	static const char*	S_CONNECT_REQUEST;

	/** The Literal S-CONNECT.RESPONSE. */
	static const char*	S_CONNECT_RESPONSE;

	/** The Literal S-READ.REQUEST. */
	static const char*	S_READ_REQUEST;

	/** The Literal S-RESYNCHRONIZE.REQUEST. */
	static const char*	S_RESYNCHRONIZE_REQUEST;

	/** The Literal S-RESYNCHRONIZE.RESPONSE. */
	static const char*	S_RESYNCHRONIZE_RESPONSE;

	/** The Literal S-SYNC-MAJOR_REQUEST. */
	static const char*	S_SYNC_MAJOR_REQUEST;

	/** The Literal S-SYNC-MINOR.REQUEST. */
	static const char*	S_SYNC_MINOR_REQUEST;

	/** The Literal S-SYNC-MAJOR.RESPONSE. */
	static const char*	S_SYNC_MAJOR_RESPONSE;

	/** The Literal S-SYNC-MINOR.RESPONSE. */
	static const char*	S_SYNC_MINOR_RESPONSE;

	/** The Literal S-CONTROL-GIVE.REQUEST. */
	static const char*	S_CONTROL_GIVE_REQUEST;

	/** The Literal S-TOKEN-GIVE.REQUEST. */
	static const char*	S_TOKEN_GIVE_REQUEST;

	/** The Literal S-TOKEN-PLEASE.REQUEST. */
	static const char*	S_TOKEN_PLEASE_REQUEST;

	/** The Literal S-ACTIVITY-DISCARD.REQUEST. */
	static const char*	S_ACTIVITY_DISCARD_REQUEST;

	/** The Literal S-ACTIVITY-DISCARD.RESPONSE. */
	static const char*	S_ACTIVITY_DISCARD_RESPONSE;

	/** The Literal S-ACTIVITY-END.REQUEST. */
	static const char*	S_ACTIVITY_END_REQUEST;

	/** The Literal S-ACTIVITY-END.RESPONSE. */
	static const char*	S_ACTIVITY_END_RESPONSE;

	/** The Literal S-ACTIVITY-INTERRUPT.REQUEST. */
	static const char*	S_ACTIVITY_INTERRUPT_REQUEST;

	/** The Literal S-ACTIVITY-INTERRUPT.RESPONSE. */
	static const char*	S_ACTIVITY_INTERRUPT_RESPONSE;

	/** The Literal S-ACTIVITY-RESUME.REQUEST. */
	static const char*	S_ACTIVITY_RESUME_REQUEST;

	/** The Literal S-ACTIVITY-START.REQUEST. */
	static const char*	S_ACTIVITY_START_REQUEST;

	/** The Literal S-RELEASE.INDICATION. */
	static const char*	S_RELEASE_INDICATION;

	/** The Literal S-RELEASE.CONFIRMATION. */
	static const char*	S_RELEASE_CONFIRMATION;

	Literal() {
	}
	virtual ~Literal() {
	}
};

}
}

#endif
