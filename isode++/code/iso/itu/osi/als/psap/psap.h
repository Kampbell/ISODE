//
// PSAP.h
//
// $Id$
//
// Library: PSAP
// Package: PSAP
// Module:  PSAP
//

#ifndef ALS_PSAP_PSAP_INCLUDED
#define ALS_PSAP_PSAP_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PSAP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PSAP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(PSAP_EXPORTS)
		#define PSAP_API __declspec(dllexport)
	#else
		#define PSAP_API __declspec(dllimport)
	#endif
#endif


#if !defined(PSAP_API)
	#define PSAP_API
#endif

//
// Automatically link PSAP library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(PSAP_EXPORTS)
		#pragma comment(lib, "psap" ALS_LIB_SUFFIX)
	#endif
#endif

#include "asn1/csn/ASN.h"
using namespace ASN;


const int					DEFAULT_CONTEXT	= 0;
const Abstract_syntax_name  DEFAULT_ABSTRACT_SYNTAX_NAME(acse_as_id);
const Transfer_syntax_name  DEFAULT_TRANSFERT_SYNTAX_NAME("{joint-iso-itu-t(2) asn1(1) basic-encoding(1)}");
#endif
