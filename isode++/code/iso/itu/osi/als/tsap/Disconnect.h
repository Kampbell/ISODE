/*
 * Disconnect.h
 *
 *  Created on: 15 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_DISCONNECT_H_
#define ALS_TSAP_USER_DISCONNECT_H_

#include "als/tsap/tsap.h"

namespace ALS {
namespace TSAP {

class TSAP_API Disconnect {
private:
	enum Base {
		DR_BASE = 0x80,		// Base for official reason codes
		DR_CONS = 256		// Base for CONS reson codes
	};

public:
	enum Reason {
		/** Normal disconnect by session entity. */
		DR_NORMAL	= (DR_BASE + 0),

		/** Remote transport entity congested at connect request time. */
		DR_REMOTE	= (DR_BASE + 1),

		/** Connection negotiation failed. */
		DR_CONNECT	= (DR_BASE + 2),

		/** Duplicate source reference detected for the same pair of NSAPs. */
		DR_DUPLICATE= (DR_BASE + 3),

		/** Mismatched references. */
		DR_MISMATCH	= (DR_BASE + 4),

		/** Protocol error. */
		DR_PROTOCOL	= (DR_BASE + 5),

		/** Reference overflow. */
		DR_OVERFLOW	= (DR_BASE + 7),

		/** Connect request refused on this network connection. */
		DR_REFUSED	= (DR_BASE + 8),

		/** Header or parameter length invalid. */
		DR_LENGTH	= (DR_BASE + 10),


		// begin UNOFFICIAL
		/** Network disconnect. */
		DR_NETWORK	= (DR_BASE + 11),

		/** invalid parameter. */
		DR_PARAMETER= (DR_BASE + 12),

		/** Invalid operation. */
		DR_OPERATION= (DR_BASE + 13),

		/** Timer expired. */
		DR_TIMER	= (DR_BASE + 14),

		/** Indications waiting. */
		DR_WAITING	= (DR_BASE + 15),

		DR_UNKNOWN	= 0,				// Reason not specifed

		/** Congestion at TSAP. */
		DR_CONGEST	= 1,				// Congestion at TSAP

		/** Session entity not attached to TSAP. */
		DR_SESSION	= 2,				// Session entity not attached to TSAP

		/** Address unknown. */
		DR_ADDRESS	= 3,				// Address unknown


		/** CONS_UNDEFINED. */
		DR_CONS_UNDEFINED				= DR_CONS + 0,		// Undefined

		// originator: NS_PROVIDER
		DR_CONS_PROVIDER				= DR_CONS + 224,	// GENERIC

		/** Disconnect - transient. */
		DR_CP_DIS_TRANS					= DR_CONS + 225,	// Disconnect - transient

		/** Disconnect - permanent. */
		DR_CP_DIS_PERM					= DR_CONS + 226,	// Disconnect - permanent

		/** Reject - transient. */
		DR_CP_REJ_UNSPEC_TRANS			= DR_CONS + 227,	// Reject - transient

		/** Reject - permanent. */
		DR_CP_REJ_UNSPEC_PERM			= DR_CONS + 228,	// Reject - permanent

		/** No QualityOfService - transient. */
		DR_CP_REJ_NO_QualityOfService_TRANS			= DR_CONS + 229,	// No QualityOfService - transient

		/** No QualityOfService - permanent. */
		DR_CP_REJ_NO_QualityOfService_PERM			= DR_CONS + 230,	// No QualityOfService - permanent

		/** NSAP unreachable transient. */
		DR_CP_REJ_NSAP_UNREACH_TRANS	= DR_CONS + 231,	// NSAP unreachable

		/** NSAP unreachable permanent. */
		DR_CP_REJ_NSAP_UNREACH_PERM		= DR_CONS + 232,	// NSAP unreachable

		/** Unspecified RESET. */
		DR_CP_RESET_UNSPEC				= DR_CONS + 233,	// Unspecified RESET

		/** RESET due to congestion. */
		DR_CP_RESET_CONGESTION			= DR_CONS + 234,	// RESET due to congestion

		/** Unknown NSAP. */
		DR_CP_REJ_NSAP_UNKNOWN_PERM		= DR_CONS + 235,	// Unknown NSAP

		// originator: NS_USER
		DR_CONS_USER					= DR_CONS + 240,	// GENERIC

		/** Normal disconnect. */
		DR_CU_DIS_NORMAL				= DR_CONS + 241,	// Normal disconnect

		/** Abnormal disconnect. */
		DR_CU_DIS_ABNORMAL				= DR_CONS + 242,	// Abnormal disconnect

		/** Reject - transient. */
		DR_CU_REJ_UNSPEC_TRANS			= DR_CONS + 244,	// Reject - transient

		/** Reject - permanent. */
		DR_CU_REJ_UNSPEC_PERM			= DR_CONS + 245,	// Reject - permanent

		/** No QualityOfService - transient. */
		DR_CU_REJ_NO_QualityOfService_TRANS			= DR_CONS + 246,	// No QualityOfService - transient

		/** No QualityOfService - permanent. */
		DR_CU_REJ_NO_QualityOfService_PERM			= DR_CONS + 247,	// No QualityOfService - permanent

		/** Incompatible NS user data. */
		DR_CU_REJ_INCOMPAT				= DR_CONS + 248,	// Incompatable NS user data

		/** User RESET. */
		DR_CU_RESET_USER_RESYNCH		= DR_CONS + 250,	// User RESET
		};

	const char* message(Reason reason) const;

private:
	Disconnect() {}
	Disconnect(const Disconnect&){}
	Disconnect& operator = (const Disconnect&);

};

}
}

#endif
