/*
 * Response.cpp
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/user/Indication.h"

namespace ALS {
namespace TSAP {
namespace USER {
	const char* Indication::message(Reason reason) const {
		switch (reason) {
		case DR_NORMAL: return "Normal disconnection by the session entity.";
		case DR_REMOTE: return "Remote transport entity congested at connect request time.";
		case DR_CONNECT: return "Connection negotiation failed.";
		case DR_DUPLICATE: return "Duplicate source reference detected for the same pair of NSAPs.";
		case DR_MISMATCH: return "Mismatched references.";
		case DR_PROTOCOL: return "Protocol error.";
		case DR_OVERFLOW: return "Reference overflow.";
		case DR_REFUSED: return " Connect request refused on this network connection.";
		case DR_LENGTH: return "Header or parameter length invalid.";
		case DR_NETWORK: return "Network disconnect.";
		case DR_PARAMETER: return "invalid parameter.";
		case DR_OPERATION: return "Invalid operation.";
		case DR_TIMER: return "Timer expired.";
		case DR_WAITING: return "Indications waiting.";
		case DR_UNKNOWN: return "Reason not specifed";
		case DR_CONGEST: return "Congestion at TSAP";
		case DR_SESSION: return "Session entity not attached to TSAP";
		case DR_ADDRESS: return "Address unknown";
		case DR_CONS_UNDEFINED: return "CONS_UNDEFINED.";
		case DR_CONS_PROVIDER: return "originator: return ''";
		case DR_CP_DIS_TRANS: return "Disconnect - transient.";
		case DR_CP_DIS_PERM: return "Disconnect - permanent.";
		case DR_CP_REJ_UNSPEC_TRANS: return "Reject - transient.";
		case DR_CP_REJ_UNSPEC_PERM: return "Reject - permanent.";
		case DR_CP_REJ_NO_QOS_TRANS: return "No QOS - transient.";
		case DR_CP_REJ_NO_QOS_PERM: return "No QOS - permanent.";
		case DR_CP_REJ_NSAP_UNREACH_TRANS: return "NSAP unreachable transient.";
		case DR_CP_REJ_NSAP_UNREACH_PERM: return "NSAP unreachable permanent.";
		case DR_CP_RESET_UNSPEC: return "Unspecified RESET.";
		case DR_CP_RESET_CONGESTION: return "RESET due to congestion.";
		case DR_CP_REJ_NSAP_UNKNOWN_PERM: return "Unknown NSAP.";
		case DR_CONS_USER: return "NS_USER originator: return ''";
		case DR_CU_DIS_NORMAL: return "Normal disconnect.";
		case DR_CU_DIS_ABNORMAL: return "Abnormal disconnect.";
		case DR_CU_REJ_UNSPEC_TRANS: return "Reject - transient.";
		case DR_CU_REJ_UNSPEC_PERM: return "Reject - permanent.";
		case DR_CU_REJ_NO_QOS_TRANS: return "No QOS - transient. ";
		case DR_CU_REJ_NO_QOS_PERM: return "No QOS - permanent.";
		case DR_CU_REJ_INCOMPAT: return "Incompatible NS user data.";
		case DR_CU_RESET_USER_RESYNCH: return "User RESET.";
		default:
			return "???";
		}
	}
}
}
}
