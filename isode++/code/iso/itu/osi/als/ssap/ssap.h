//
// SSAP.h
//
// $Id$
//
// Library: SSAP
// Package: SSAPCore
// Module:  SSAP
//

#ifndef ALS_SSAP_SSAP_INCLUDED
#define ALS_SSAP_SSAP_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SSAP_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SSAP_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(SSAP_EXPORTS)
		#define SSAP_API __declspec(dllexport)
	#else
		#define SSAP_API __declspec(dllimport)
	#endif
#endif


#if !defined(SSAP_API)
	#define SSAP_API
#endif

//
// Automatically link SSAP library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(SSAP_EXPORTS)
		#pragma comment(lib, "ssap" ALS_LIB_SUFFIX)
	#endif
#endif


namespace ALS {
	namespace SSAP {
	/** The EXPEDITED DATA maximum size. */
	// EXPEDITED DATA (XSSDU) only
	const int	SX_EXSIZE = 14;

	/** The CAPABILITY DATA maximum size. */
	// CAPABILITY DATA only
	const int	SX_CDSIZE = 512;

	/** The CAPABILITY DATA ACKNOWLEDGE maximum size. */
	// CAPABILITY DATA ACK only
	const int	SX_CDASIZE = 512;

	// someday support CDO/OA SPDUs and Data Overflow PI...
	const int	MAX_CONNECT_DATA_SIZE = 10240;
	}
}
#define	dotokens() \
{ \
    dotoken (RELEASE_UNIT_EXISTS, RELEASE_SHIFT, RELEASE_TOKEN, RELEASE_LITERAL); \
    dotoken (MAJOR_UNIT_EXISTS, MAJOR_SHIFT, MAJOR_TOKEN, MAJOR_LITERAL); \
    dotoken (MINOR_UNIT_EXISTS, MINOR_SHIFT, MINOR_TOKEN, MINOR_LITERAL); \
    dotoken (DATA_UNIT_EXISTS, DATA_SHIFT, DATA_TOKEN, DATA_LITERAL); \
}


#endif
