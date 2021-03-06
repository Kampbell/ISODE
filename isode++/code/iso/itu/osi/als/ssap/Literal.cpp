/*
 * Literal.cpp
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Literal.h"

namespace ALS {
namespace SSAP {
	/** The Literal S-SYNC-MAJOR.INDICATION. */
	const char* Literal::S_SYNC_MAJOR_INDICATION = "S-SYNC-MAJOR.INDICATION";

	/** The Literal S-SYNC-MINOR.INDICATION. */
	const char* Literal::S_SYNC_MINOR_INDICATION = "S-SYNC-MINOR.INDICATION";

	/** The Literal S-RESYNCHRONIZE.INDICATION. */
	const char* Literal::S_RESYNCHRONIZE_INDICATION = "S-RESYNCHRONIZE.INDICATION";

	/** The Literal S-SYNC-MINOR.CONFIRMATION. */
	const char* Literal::S_SYNC_MINOR_CONFIRMATION = "S-SYNC-MINOR.CONFIRMATION";

	/** The Literal S-SYNC-MAJOR.CONFIRMATION. */
	const char* Literal::S_SYNC_MAJOR_CONFIRMATION = "S-SYNC-MAJOR.CONFIRMATION";

	/** The Literal S-RESYNCHRONIZE.CONFIRMATION. */
	const char* Literal::S_RESYNCHRONIZE_CONFIRMATION = "S-RESYNCHRONIZE.CONFIRMATION";

	/** The Literal S-TOKEN-GIVE.INDICATION. */
	const char* Literal::S_TOKEN_GIVE_INDICATION = "S-TOKEN-GIVE.INDICATION";

	/** The Literal S-TOKEN-PLEASE.INDICATION. */
	const char* Literal::S_TOKEN_PLEASE_INDICATION = "S-TOKEN-PLEASE.INDICATION";

	/** The Literal S-CONTROL-GIVE.INDICATION. */
	const char* Literal::S_CONTROL_GIVE_INDICATION = "S-CONTROL-GIVE.INDICATION";

	/** The Literal S-ABORT.INDICATION. */
	const char* Literal::S_U_ABORT_INDICATION = "S-U-ABORT.INDICATION";

	/** The Literal S-ABORT.INDICATION. */
	const char* Literal::S_P_ABORT_INDICATION = "S-P-ABORT.INDICATION";

	/** The literal S-ACTIVITY_INTERRUPT.CONFIRMATION */
	const char* Literal::S_ACTIVITY_INTERRUPT_CONFIRMATION = "S-ACTIVITY-INTERRUPT.CONFIRMATION";

	/** The literal S-ACTIVITY-DISCARD.CONFIRMATION. */
	const char* Literal::S_ACTIVITY_DISCARD_CONFIRMATION = "S-ACTIVITY-DISCARD.CONFIRMATION";

	/** The literal S-ACTIVITY-END.CONFIRMATION. */
	const char* Literal::S_ACTIVITY_END_CONFIRMATION = "S-ACTIVITY-END.CONFIRMATION";

	/** The literal S-ACTIVITY-START.INDICATION. */
	const char* Literal::S_ACTIVITY_START_INDICATION = "S-ACTIVITY-START.INDICATION";

	/** The literal S-ACTIVITY-RESUME.INDICATION. */
	const char* Literal::S_ACTIVITY_RESUME_INDICATION = "S-ACTIVITY-RESUME.INDICATION";

	/** The literal S-ACTIVITY-INTERRUPT.INDICATION. */
	const char* Literal::S_ACTIVITY_INTERRUPT_INDICATION = "S-ACTIVITY-INTERRUPT.INDICATION";

	/** The literal S-ACTIVITY-DISCARD.INDICATION. */
	const char* Literal::S_ACTIVITY_DISCARD_INDICATION = "S-ACTIVITY-DISCARD.INDICATION";

	/** The literal S-ACTIVITY-END.INDICATION. */
	const char* Literal::S_ACTIVITY_END_INDICATION = "S-ACTIVITY-END.INDICATION";

	/** The char* S-DATA.INDICATION. */
	const char* Literal::S_DATA_INDICATION = "S-DATA.INDICATION";

	/** The char* S-EXPEDITED-DATA.INDICATION. */
	const char* Literal::S_EXPEDITED_DATA_INDICATION = "S-EXPEDITED-DATA.INDICATION";

	/** The char* S-TYPED-DATA.INDICATION. */
	const char* Literal::S_TYPED_DATA_INDICATION = "S-TYPED-DATA.INDICATION";

	/** The char* S-CAPABILITY-DATA.INDICATION. */
	const char* Literal::S_CAPABILITY_DATA_INDICATION = "S-CAPABILITY-DATA.INDICATION";

	/** The char* S-CAPABILITY-DATA.CONFIRMATION. */
	const char* Literal::S_CAPABILITY_DATA_CONFIRMATION = "S-CAPABILITY-DATA.CONFIRMATION";

	/** The Literal S-U-ABORT.REQUEST. */
	const char* Literal::S_U_ABORT_REQUEST = "S-U-ABORT.REQUEST";

	/** The Literal S-P-ABORT.REQUEST. */
	const char* Literal::S_P_ABORT_REQUEST = "S-P-ABORT.REQUEST";

	/** The Literal S-RELEASE.REQUEST. */
	const char* Literal::S_RELEASE_REQUEST = "S-RELEASE.REQUEST";

	/** The Literal S-RELEASE.RESPONSE. */
	const char* Literal::S_RELEASE_RESPONSE = "S-RELEASE.RESPONSE";

	/** The Literal S-RELEASE-RETRY.REQUEST. */
	const char* Literal::S_RELEASE_RETRY_REQUEST = "S-RELEASE-RETRY.REQUEST";

	/** The Literal S-CAPABILITY-DATA.REQUEST. */
	const char* Literal::S_CAPABILITY_DATA_REQUEST = "S-CAPABILITY-DATA.REQUEST";

	/** The Literal S-CAPABILITY-DATA.RESPONSE. */
	const char* Literal::S_CAPABILITY_DATA_RESPONSE = "S-CAPABILITY-DATA.RESPONSE";

	/** The Literal S-DATA.REQUEST. */
	const char* Literal::S_DATA_REQUEST = "S-DATA.REQUEST";

	/** The Literal S-EXPEDITED-DATA.REQUEST. */
	const char* Literal::S_EXPEDITED_DATA_REQUEST = "S-EXPEDITED-DATA.REQUEST";

	/** The Literal S-TYPED-DATA.REQUEST. */
	const char* Literal::S_TYPED_DATA_REQUEST = "S-TYPED-DATA.REQUEST";

	/** The Literal S-SEND.REQUEST. */
	const char* Literal::S_SEND_REQUEST = "S-SEND.REQUEST (segmented)";

	/** The Literal S-WRITE.REQUEST. */
	const char* Literal::S_WRITE_REQUEST = "S-WRITE.REQUEST (pseudo)";

	/** The literal S-U-EXCEPTION-REPORT.INDICATION. */
	const char* Literal::S_U_EXCEPTION_REPORT_INDICATION = "S-U-EXCEPTION-REPORT.INDICATION";

	/** The literal S-P-EXCEPTION-REPORT.INDICATION. */
	const char* Literal::S_P_EXCEPTION_REPORT_INDICATION = "S-P-EXCEPTION-REPORT.INDICATION";

	/** The Literal S-U-EXCEPTION-REPORT.REQUEST. */
	const char* Literal::S_U_EXCEPTION_REPORT_REQUEST = "S-U-EXCEPTION-REPORT.REQUEST";

	/** The Literal S-P-EXCEPTION-REPORT.REQUEST. */
	const char* Literal::S_P_EXCEPTION_REPORT_REQUEST = "S-P-EXCEPTION-REPORT.REQUEST";

	/** The literal S-CONNECT.CONFIRMATION */
	const char* Literal::S_CONNECT_CONFIRMATION = "S-CONNECT.CONFIRMATION";

	/** The Literal S-CONNECT.INDICATION. */
	const char* Literal::S_CONNECT_INDICATION = "S-CONNECT.INDICATION";

	/** The Literal S-CONNECT.REQUEST. */
	const char* Literal::S_CONNECT_REQUEST = "S-CONNECT.REQUEST";

	/** The Literal S-CONNECT.RESPONSE. */
	const char* Literal::S_CONNECT_RESPONSE = "S-CONNECT.RESPONSE";

	/** The Literal S-READ.REQUEST. */
	const char* Literal::S_READ_REQUEST = "S-READ.REQUEST";

	/** The Literal S-RESYNCHRONIZE.REQUEST. */
	const char* Literal::S_RESYNCHRONIZE_REQUEST = "S-RESYNCHRONIZE.REQUEST";

	/** The Literal S-RESYNCHRONIZE.RESPONSE. */
	const char* Literal::S_RESYNCHRONIZE_RESPONSE = "S-RESYNCHRONIZE.RESPONSE";

	/** The Literal S-SYNC-MAJOR_REQUEST. */
	const char* Literal::S_SYNC_MAJOR_REQUEST = "S-SYNC-MAJOR.REQUEST";

	/** The Literal S-SYNC-MINOR.REQUEST. */
	const char* Literal::S_SYNC_MINOR_REQUEST = "S-SYNC-MINOR.REQUEST";

	/** The Literal S-SYNC-MAJOR.RESPONSE. */
	const char* Literal::S_SYNC_MAJOR_RESPONSE = "S-SYNC-MAJOR.RESPONSE";

	/** The Literal S-SYNC-MINOR.RESPONSE. */
	const char* Literal::S_SYNC_MINOR_RESPONSE = "S-SYNC-MINOR.RESPONSE";

	/** The Literal S-CONTROL-GIVE.REQUEST. */
	const char* Literal::S_CONTROL_GIVE_REQUEST = "S-CONTROL-GIVE.REQUEST";

	/** The Literal S-TOKEN-GIVE.REQUEST. */
	const char* Literal::S_TOKEN_GIVE_REQUEST = "S-TOKEN-GIVE.REQUEST";

	/** The Literal S-TOKEN-PLEASE.REQUEST. */
	const char* Literal::S_TOKEN_PLEASE_REQUEST = "S-TOKEN-PLEASE.REQUEST";

	/** The Literal S-ACTIVITY-DISCARD.REQUEST. */
	const char* Literal::S_ACTIVITY_DISCARD_REQUEST = "S-ACTIVITY-DISCARD.REQUEST";

	/** The Literal S-ACTIVITY-DISCARD.RESPONSE. */
	const char* Literal::S_ACTIVITY_DISCARD_RESPONSE = "S-ACTIVITY-DISCARD.RESPONSE";

	/** The Literal S-ACTIVITY-END.REQUEST. */
	const char* Literal::S_ACTIVITY_END_REQUEST = "S-ACTIVITY-END.REQUEST";

	/** The Literal S-ACTIVITY-END.RESPONSE. */
	const char* Literal::S_ACTIVITY_END_RESPONSE = "S-ACTIVITY-END.RESPONSE";

	/** The Literal S-ACTIVITY-INTERRUPT.REQUEST. */
	const char* Literal::S_ACTIVITY_INTERRUPT_REQUEST = "S-ACTIVITY-INTERRUPT.REQUEST";

	/** The Literal S-ACTIVITY-INTERRUPT.RESPONSE. */
	const char* Literal::S_ACTIVITY_INTERRUPT_RESPONSE = "S-ACTIVITY-INTERRUPT.RESPONSE";

	/** The Literal S-ACTIVITY-RESUME.REQUEST. */
	const char* Literal::S_ACTIVITY_RESUME_REQUEST = "S-ACTIVITY-RESUME.REQUEST";

	/** The Literal S-ACTIVITY-START.REQUEST. */
	const char* Literal::S_ACTIVITY_START_REQUEST = "S-ACTIVITY-START.REQUEST";

	/** The Literal S-RELEASE.INDICATION. */
	const char* Literal::S_RELEASE_INDICATION = "S-RELEASE.INDICATION";

	/** The Literal S-RELEASE.CONFIRMATION. */
	const char* Literal::S_RELEASE_CONFIRMATION = "S-RELEASE.CONFIRMATION";

}
}
