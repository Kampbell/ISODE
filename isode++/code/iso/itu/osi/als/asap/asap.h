//
// ASAP.h
//
// $Id$
//
// Library: ASAP
// Package: ASAP
// Module:  ASAP
//

#ifndef ALS_ASAP_INCLUDED
#define ALS_ASAP_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ASAP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ASAP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(ASAP_EXPORTS)
		#define ASAP_API __declspec(dllexport)
	#else
		#define ASAP_API __declspec(dllimport)
	#endif
#endif


#if !defined(ASAP_API)
	#define ASAP_API
#endif

//
// Automatically link ASAP library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(ASAP_EXPORTS)
		#pragma comment(lib, "asap" ALS_LIB_SUFFIX)
	#endif
#endif

#include "asn1/csn/ASN.h"
using namespace ASN;


#endif
