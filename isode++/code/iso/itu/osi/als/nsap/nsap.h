#ifndef ALS_NSAP_NSAP_INCLUDED
#define ALS_NSAP_NSAP_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the NSAP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// NSAP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(NSAP_EXPORTS)
		#define NSAP_API __declspec(dllexport)
	#else
		#define NSAP_API __declspec(dllimport)
	#endif
#endif


#if !defined(NSAP_API)
	#define NSAP_API
#endif

//
// Automatically link NSAP library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(NSAP_EXPORTS)
		#pragma comment(lib, "nsap" ALS_LIB_SUFFIX)
	#endif
#endif

#endif
