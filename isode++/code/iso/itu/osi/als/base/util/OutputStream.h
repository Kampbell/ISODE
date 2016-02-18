/*
 * OutputStream.h
 *
 *  Created on: 24 sept. 2015
 *      Author: FrancisANDRE
 */

#ifndef OUTPUTSTREAM_H_
#define OUTPUTSTREAM_H_

#include "als/base/base.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			class NetworkBuffer;
			class OutputStream {
			public:
				OutputStream() {}
				virtual ~OutputStream() {}

				virtual OutputStream& operator << (bool value) = 0;
				virtual OutputStream& operator << (char value) = 0;
				virtual OutputStream& operator << (int1 value) = 0;
				virtual OutputStream& operator << (int2 value) = 0;
				virtual OutputStream& operator << (int4 value) = 0;
				virtual OutputStream& operator << (int8 value) = 0;
				virtual OutputStream& operator << (nat1 value) = 0;
				virtual OutputStream& operator << (nat2 value) = 0;
				virtual OutputStream& operator << (nat4 value) = 0;
				virtual OutputStream& operator << (nat8 value) = 0;
				virtual OutputStream& operator << (float value) = 0;
				virtual OutputStream& operator << (double value) = 0;

				virtual OutputStream& operator << (const NetworkBuffer& buffer) = 0;
				virtual OutputStream& operator << (const std::string& value) = 0;
				virtual OutputStream& operator << (const char* value) = 0;
			};

		}
	}
}

#endif
