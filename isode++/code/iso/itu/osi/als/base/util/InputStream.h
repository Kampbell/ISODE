/*
 * InputStream.h
 *
 *  Created on: 24 sept. 2015
 *      Author: FrancisANDRE
 */

#ifndef INPUTSTREAM_H_
#define INPUTSTREAM_H_

#include "als/base/base.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class InputStream {
			public:
				InputStream() {}
				virtual ~InputStream() {}

				virtual InputStream& operator >> (bool& value) = 0;
				virtual InputStream& operator >> (char& value) = 0;
				virtual InputStream& operator >> (int1& value) = 0;
				virtual InputStream& operator >> (int2& value) = 0;
				virtual InputStream& operator >> (int4& value) = 0;
				virtual InputStream& operator >> (int8& value) = 0;
				virtual InputStream& operator >> (nat1& value) = 0;
				virtual InputStream& operator >> (nat2& value) = 0;
				virtual InputStream& operator >> (nat4& value) = 0;
				virtual InputStream& operator >> (nat8& value) = 0;
				virtual InputStream& operator >> (float& value) = 0;
				virtual InputStream& operator >> (double& value) = 0;
			};

		}
	}
}
#endif
