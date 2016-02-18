/*
 * Literal.h
 *
 *  Created on: 23 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_ASAP_LITERAL_H_
#define ALS_ASAP_LITERAL_H_

namespace ALS {
namespace ASAP {

class Literal {
public:
	/** The Literal A-ASSOCIATE.REQUEST. */
	static const char*	A_ASSOCIATE_REQUEST;

	/** The Literal A-ASSOCIATE.INDICATION. */
	static const char*	A_ASSOCIATE_INDICATION;

	/** The Literal A-ASSOCIATE.RESPONSE. */
	static const char*	A_ASSOCIATE_RESPONSE;

	/** The Literal A-ASSOCIATE.CONFIRMATION. */
	static const char*	A_ASSOCIATE_CONFIRMATION;

	/** The Literal A-RELEASE.REQUEST. */
	static const char*	A_RELEASE_REQUEST;

	/** The Literal A-RELEASE.INDICATION. */
	static const char*	A_RELEASE_INDICATION;

	/** The Literal A-RELEASE.RESPONSE. */
	static const char*	A_RELEASE_RESPONSE;

	/** The Literal A-RELEASE.CONFIRMATION. */
	static const char*	A_RELEASE_CONFIRMATION;

	/** The Literal A-ABORT.REQUEST. */
	static const char*	A_ABORT_REQUEST;

	/** The Literal A-ABORT.INDICATION. */
	static const char*	A_ABORT_INDICATION;

	/** The Literal A-P-ABORT.REQUEST. */
	static const char*	A_P_ABORT_INDICATION;

	/** The Literal A-UNIT-DATA.REQUEST. */
	static const char*	A_UNIT_DATA_REQUEST;

	Literal() {
	}
	virtual ~Literal() {
	}
};

}
}

#endif
