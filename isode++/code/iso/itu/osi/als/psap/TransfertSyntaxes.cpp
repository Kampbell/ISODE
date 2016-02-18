/*
 * TransfertSyntaxes.cpp
 *
 *  Created on: 4 janv. 2015
 *      Author: FrancisANDRE
 */

#include "als/psap/TransfertSyntaxes.h"

namespace ALS {
namespace PSAP {
const char*		TransfertSyntaxes::OED_BER			= "BER encoding of a single ASN.1 type";
const char*		TransfertSyntaxes::OED_CER			= "CER encoding of a single ASN.1 type";
const char*		TransfertSyntaxes::OED_DER			= "DER encoding of a single ASN.1 type";
const char*		TransfertSyntaxes::OED_PER_BA		= "PER encoding of a single ASN.1 type (basic aligned)";
const char*		TransfertSyntaxes::OED_PER_BU		= "PER encoding of a single ASN.1 type (basic unaligned)";
const char*		TransfertSyntaxes::OED_PER_CA		= "PER encoding of a single ASN.1 type (canonical aligned)";
const char*		TransfertSyntaxes::OED_PER_CU		= "PER encoding of a single ASN.1 type (canonical unaligned)";
const char*		TransfertSyntaxes::OED_XER_B		= "XER encoding of a single ASN.1 type (basic)";
const char*		TransfertSyntaxes::OED_XER_C		= "XER encoding of a single ASN.1 type (canonical)";


const char*		TransfertSyntaxes::OID_BER			= "{joint-iso-itu-t asn1(1) basic-encoding(1)}";
const char*		TransfertSyntaxes::OID_CER			= "{joint-iso-itu-t asn1(1) ber-derived(2) canonical-encoding(0)}";
const char*		TransfertSyntaxes::OID_DER			= "{joint-iso-itu-t asn1(1) ber-derived(2) distinguished-encoding(1)}";
const char*		TransfertSyntaxes::OID_PER_BA		= "{joint-iso-itu-t asn1(1) packed-encoding(3) basic(0) aligned(0)}";
const char*		TransfertSyntaxes::OID_PER_BU		= "{joint-iso-itu-t asn1(1) packed-encoding(3) basic(0) unaligned(1)}";
const char*		TransfertSyntaxes::OID_PER_CA		= "{joint-iso-itu-t asn1(1) packed-encoding(3) canonical(1) aligned(0)}";
const char*		TransfertSyntaxes::OID_PER_CU		= "{joint-iso-itu-t asn1(1) packed-encoding(3) canonical(1) unaligned(1)}";
const char*		TransfertSyntaxes::OID_XER_B		= "{joint-iso-itu-t asn1(1) xml-encoding(5) basic(0)}";
const char*		TransfertSyntaxes::OID_XER_C		= "{joint-iso-itu-t asn1(1) xml-encoding(5) canonical(1)}";

const Transfer_syntax_name	TransfertSyntaxes::BER(OID_BER);
const Transfer_syntax_name	TransfertSyntaxes::CER(OID_CER);
const Transfer_syntax_name	TransfertSyntaxes::DER(OID_DER);
const Transfer_syntax_name	TransfertSyntaxes::PER_BA(OID_PER_BA);
const Transfer_syntax_name	TransfertSyntaxes::PER_BU(OID_PER_BU);
const Transfer_syntax_name	TransfertSyntaxes::PER_CA(OID_PER_CA);
const Transfer_syntax_name	TransfertSyntaxes::PER_CU(OID_PER_CU);
const Transfer_syntax_name	TransfertSyntaxes::XER_B(OID_XER_B);
const Transfer_syntax_name	TransfertSyntaxes::XER_C(OID_XER_C);

}
}
