/*
 * Literal.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_LITERAL_H_
#define ALS_TSAP_LITERAL_H_

#include <string>
using std::string;
#include "als/tsap/tsap.h"

namespace ALS {
namespace TSAP {

class TSAP_API Literal {
public:
	/** The Literal T-CONNECT.REQUEST. */
	static const char*	T_CONNECT_REQUEST;

	/** The Literal T-CONNECT.CONFIRMATION. */
	static const char*	T_CONNECT_CONFIRMATION;

	/** The Literal T-CONNECT.INDICATION. */
	static const char*	T_CONNECT_INDICATION;

	/** The Literal T-CONNECT.RESPONSE. */
	static const char*	T_CONNECT_RESPONSE;

	/** The Literal T-DATA.REQUEST. */
	static const char*	T_DATA_REQUEST;

	/** The Literal T-EXPEDITED-DATA.REQUEST. */
	static const char*	T_EXPEDITED_DATA_REQUEST;

	/** The Literal T-READ.REQUEST. */
	static const char*	T_READ_REQUEST;

	/** The Constant T-DATA_INDICATION. */
	static const char*	T_DATA_INDICATION;

	/** The Constant T-EXPEDITED_DATA_INDICATION. */
	static const char*	T_EXPEDITED_DATA_INDICATION;

	/** The Constant T-DISCONNECT.REQUEST. */
	static const char*	T_DISCONNECT_REQUEST;

	/** The Constant T-DISCONNECT_INDICATION. */
	static const char*	T_DISCONNECT_INDICATION;

private:
	Literal();
	Literal(const Literal&);
	Literal& operator = (const Literal&);

};

}
}

#endif
