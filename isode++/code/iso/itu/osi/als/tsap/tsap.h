//
// TSAP.h
//
// $Id$
//
// Library: TSAP
// Package: TSAPCore
// Module:  TSAP
//

#ifndef TSAP_TSAP_INCLUDED
#define TSAP_TSAP_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TSAP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TSAP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(TSAP_EXPORTS)
		#define TSAP_API __declspec(dllexport)
	#else
		#define TSAP_API __declspec(dllimport)
	#endif
#endif


#if !defined(TSAP_API)
	#define TSAP_API
#endif

//
// Automatically link TSAP library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(TSAP_EXPORTS)
		#pragma comment(lib, "tsap" ALS_LIB_SUFFIX)
	#endif
#endif

#endif
