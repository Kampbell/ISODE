/*
 * Literal.h
 *
 *  Created on: 17 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_LITERAL_H_
#define ALS_NSAP_LITERAL_H_
#include <string>
using std::string;
#include "als/nsap/nsap.h"
namespace ALS {
namespace NSAP {

class NSAP_API Literal {
public:
	/** The Literal N-CONNECT.REQUEST. */
	static const char*	N_CONNECT_REQUEST;

	/** The Literal N-CONNECT.INDICATION. */
	static const char*	N_CONNECT_INDICATION;

	/** The Literal N-CONNECT.RESPONSE. */
	static const char*	N_CONNECT_RESPONSE;

	/** The Literal N-CONNECT.CONFIRMATION. */
	static const char*	N_CONNECT_CONFIRMATION;

	/** The Literal N-DATA.REQUEST. */
	static const char*	N_DATA_REQUEST;

	/** The Literal N-DATA_INDICATION. */
	static const char*	N_DATA_INDICATION;

	/** The Literal N-DATA-ACKNOWLEDGE.REQUEST. */
	static const char*	N_DATA_ACKNOWLEDGE_REQUEST;

	/** The Literal N-DATA-ACKNOWLEDGE.INDICATION. */
	static const char*	N_DATA_ACKNOWLEDGE_INDICATION;

	/** The Literal N-EXPEDITED-DATA.REQUEST. */
	static const char*	N_EXPEDITED_DATA_REQUEST;

	/** The Literal N-EXPEDITED-DATA_INDICATION. */
	static const char*	N_EXPEDITED_DATA_INDICATION;

	/** The Literal N-RESET.REQUEST. */
	static const char*	N_RESET_REQUEST;

	/** The Literal N-RESET.RESPONSE. */
	static const char*	N_RESET_RESPONSE;

	/** The Literal N-RESET.INDICATION. */
	static const char*	N_RESET_INDICATION;

	/** The Literal N-RESET.CONFIRMATION. */
	static const char*	N_RESET_CONFIRMATION;

	/** The Literal N-DISCONNECT.REQUEST. */
	static const char*	N_DISCONNECT_REQUEST;

	/** The Literal N-DISCONNECT.INDICATION. */
	static const char*	N_DISCONNECT_INDICATION;


private:

	Literal();
	Literal(const Literal&);
	Literal& operator = (const Literal&);

};

}
}

#endif
