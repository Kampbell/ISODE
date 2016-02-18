#ifndef ALS_BASE_BASE_INCLUDED
#define ALS_BASE_BASE_INCLUDED

#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the BASE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// BASE_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(BASE_EXPORTS)
		#define BASE_API __declspec(dllexport)
	#else
		#define BASE_API __declspec(dllimport)
	#endif
#endif


#if !defined(BASE_API)
	#define BASE_API
#endif

//
// Automatically link BASE library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(BASE_EXPORTS)
		#pragma comment(lib, "base" ALS_LIB_SUFFIX)
	#endif
#endif

namespace ALS {
	namespace BASE {
		namespace UTIL {
			enum class StreamByteOrder	{
				NATIVE_BYTE_ORDER = 1,			/// the host's native byte-order
				BIG_ENDIAN_BYTE_ORDER = 2,		/// big-endian (network) byte-order
				NETWORK_BYTE_ORDER = 2,			/// big-endian (network) byte-order
				LITTLE_ENDIAN_BYTE_ORDER = 3,	/// little-endian byte-order
				UNSPECIFIED_BYTE_ORDER = 4		/// unknown, byte-order will be determined by reading the byte-order mark
			};
		}
	}
}
#endif
