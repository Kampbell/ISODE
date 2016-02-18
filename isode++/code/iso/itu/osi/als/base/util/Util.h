/*
 * Util.h
 *
 *  Created on: 27 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_UTIL_UTIL_H_
#define ALS_BASE_UTIL_UTIL_H_

#include <string>
using std::string;

#include "als/base/base.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {





			class BASE_API Util {
			public:
				static string char_to_hex(char input);
				static string char_to_hex(unsigned char input);
				static string short_to_hex(short input);
				static string short_to_hex(unsigned short input);
				static string string_to_hex(const string& input);
				static string hex_to_string(const string& input);
				static const string at(const char* file, int line);
			};

		}
	}
}

#endif
