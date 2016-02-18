/*
 * TransfertSyntaxes.h
 *
 *  Created on: 4 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_PSAP_TRANSFERT_SYNTAXES_H_
#define ALS_PSAP_TRANSFERT_SYNTAXES_H_
#include "als/psap/psap.h"

namespace ALS {
namespace PSAP {

class PSAP_API TransfertSyntaxes {
	static const char*		OED_BER	;
	static const char*		OED_CER;
	static const char*		OED_DER	;
	static const char*		OED_PER_BA;
	static const char*		OED_PER_BU;
	static const char*		OED_PER_CA;
	static const char*		OED_PER_CU;
	static const char*		OED_XER_B;
	static const char*		OED_XER_C;

private:
	static const char*		OID_BER;
	static const char*		OID_CER;
	static const char*		OID_DER;
	static const char*		OID_PER_BA;
	static const char*		OID_PER_BU;
	static const char*		OID_PER_CA;
	static const char*		OID_PER_CU;
	static const char*		OID_XER_B;
	static const char*		OID_XER_C;

	/** BER encoding of a single ASN.1 type. */
public:
	static const Transfer_syntax_name		BER;	// = ASN1_Object_Identifier_Module_values.ber;

	/** CER encoding of a single ASN.1 type. */
	static const Transfer_syntax_name		CER;

	/** DER encoding of a single ASN.1 type. */
	static const Transfer_syntax_name		DER;

	/** PER encoding of a single ASN.1 type (basic aligned). */
	static const Transfer_syntax_name		PER_BA;

	/** PER encoding of a single ASN.1 type (basic unaligned). */
	static const Transfer_syntax_name		PER_BU;

	/** PER encoding of a single ASN.1 type (canonical aligned). */
	static const Transfer_syntax_name		PER_CA;

	/** PER encoding of a single ASN.1 type (canonical unaligned). */
	static const Transfer_syntax_name		PER_CU;

	/** XER encoding of a single ASN.1 type (basic). */
	static const Transfer_syntax_name		XER_B;

	/** XER encoding of a single ASN.1 type (canonical). */
	static const Transfer_syntax_name		XER_C;

	static bool isSupported(const Transfer_syntax_name& tsn) {
		if (tsn == BER || tsn == CER ||tsn == DER) return true;
		if (tsn == PER_BA ||tsn == PER_BU ||tsn == PER_CA ||tsn == PER_CU) return true;
		if (tsn == XER_B || tsn == XER_C) return true;
		return false;
	}
private:
	TransfertSyntaxes() {}
	TransfertSyntaxes(const TransfertSyntaxes&) {}
	TransfertSyntaxes& operator = (const TransfertSyntaxes&);
};

}
}

#endif
