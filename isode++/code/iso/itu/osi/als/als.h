#ifndef	ALS_ALS_H_
#define ALS_ALS_H_

#include "poco/Platform.h"
#if defined(_WIN32)
	#include "poco/Platform_WIN32.h"
#elif defined(__VMS)
	#include "poco/Platform_VMS.h"
#elif defined(ALS_VXWORKS)
	#include "poco/Platform_VX.h"
#elif defined(ALS_OS_FAMILY_UNIX)
	#include "poco/Platform_POSIX.h"
#endif

//
// Ensure that ALS_DLL is default unless ALS_STATIC is defined
//
#if defined(_WIN32) && defined(_DLL)
	#if !defined(ALS_DLL) && !defined(ALS_STATIC)
		#define ALS_DLL
	#endif
#endif

#if defined(_MSC_VER)
	#if defined(ALS_DLL)
		#if defined(_DEBUG)
			#define ALS_LIB_SUFFIX "d.lib"
		#else
			#define ALS_LIB_SUFFIX ".lib"
		#endif
	#elif defined(_DLL)
		#if defined(_DEBUG)
			#define ALS_LIB_SUFFIX "mdd.lib"
		#else
			#define ALS_LIB_SUFFIX "md.lib"
		#endif
	#else
		#if defined(_DEBUG)
			#define ALS_LIB_SUFFIX "mtd.lib"
		#else
			#define ALS_LIB_SUFFIX "mt.lib"
		#endif
	#endif
#endif

#if defined(_MSC_VER)
	#pragma warning(disable:4554)	// vérifiez la priorité des opérateurs comme cause possible d'erreur ; utilisez des parenthèses pour rendre plus claires les priorités
	#pragma warning(disable:4390)	// ';' : une instruction contrôlée a été trouvée vide ; est-ce ce que vous souhaitiez ?
#endif

#include <cstddef>
#include <cassert>
#include <cstdint>
#include <string>

typedef unsigned char byte;

typedef int8_t		int1;
typedef int16_t		int2;
typedef int32_t		int4;
typedef int64_t		int8;

typedef uint8_t		nat1;
typedef uint16_t	nat2;
typedef uint32_t	nat4;
typedef uint64_t	nat8;


enum ReturnCode {
	OK, 
	NOTOK,
	DONE,
	NOTDONE
};

typedef bool		boolean;

class Printer {
public:
	virtual void  operator()(const char* s) = 0;
	virtual void  operator()(const std::string& s) = 0;
};

#endif
