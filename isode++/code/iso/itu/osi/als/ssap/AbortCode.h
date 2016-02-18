/*
 * Abort.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_ABORT_H_
#define ALS_SSAP_ABORT_H_

namespace ALS {
namespace SSAP {

class AbortCode {
public:
	/** Accepted. */
	static const int SC_ACCEPT = -1;
	static const int accepted = SC_ACCEPT;

private:
	/** Reject by SSAP-provider. */
	static const int SC_BASE = 0x80;

public:
	/** SSAP identifier unknown. */
	static const int SC_SSAPID = (SC_BASE + 1);
	static const int ssap_identifier_unknown = SC_SSAPID;

	/** SS-user not attached to SSAP. */
	static const int SC_SSUSER = (SC_BASE + 2);
	static const int ss_user_not_attached_to_SSAP = SC_SSUSER;

	/** Congestion at SSAP. */
	static const int SC_CONGEST = (SC_BASE + 3);
	static const int congestion_at_SSAP = SC_CONGEST;

	/** Proposed protocol versions not supported. */
	static const int SC_VERSION = (SC_BASE + 4);
	static const int proposed_protocol_versions_not_supported = SC_VERSION;

	// begin UNOFFICIAL
	/** Address unknown. */
	static const int SC_ADDRESS = (SC_BASE + 5);
	static const int address_unknown = SC_ADDRESS;

	/** Connect request refused on this network connection. */
	static const int SC_REFUSED = (SC_BASE + 6);
	static const int connect_request_refused = SC_REFUSED;

	/** Transport disconnect. */
	static const int SC_TRANSPORT = (SC_BASE + 7);
	static const int transport_disconnect = SC_TRANSPORT;

	/** Provider-initiated abort. */
	static const int SC_ABORT = (SC_BASE + 8);
	static const int provider_initiated_abort = SC_ABORT;

	/** Protocol error. */
	static const int SC_PROTOCOL = (SC_BASE + 9);
	static const int protocol_error = SC_PROTOCOL;

	/** Invalid parameter. */
	static const int SC_PARAMETER = (SC_BASE + 10);
	static const int invalid_parameter = SC_PARAMETER;

	/** Invalid operation. */
	static const int SC_OPERATION = (SC_BASE + 11);
	static const int invalid_operation = SC_OPERATION;

	/** Timer expired. */
	static const int SC_TIMER = (SC_BASE + 12);
	static const int timer_expired = SC_TIMER;

	/** Indications waiting. */
	static const int SC_WAITING = (SC_BASE + 13);
	static const int indications_waiting = SC_WAITING;

	/** Reason not specified. */
	static const int SC_NOTSPECIFIED = 0;
	static const int reason_not_specified = SC_NOTSPECIFIED;

	/** Temporary congestion. */
	static const int SC_CONGESTION = 1;
	static const int congestion = SC_CONGESTION;

	/** Rejected. */
	static const int SC_REJECTED = 2;
	static const int rejected = SC_REJECTED;

	AbortCode(int code) : code(code) {}

	operator int() const				{ return code; }

private:
	int		code;
};

}
}

#endif
