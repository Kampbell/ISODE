/*
 * BinaryInputStream.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BINARYINPUTSTREAM_H_
#define BINARYINPUTSTREAM_H_

#include <ios>
using std::ios_base;

#include "als/base/util/NetworkBuffer.h"
#include "als/base/util/InputStream.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			class BASE_API BinaryInputStream : public InputStream, public virtual NetworkBuffer {
			private:
				bool flipbytes;

			public:
				BinaryInputStream(int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				BinaryInputStream(char* buffer = NULL, int length = 0, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				virtual ~BinaryInputStream();

				BinaryInputStream& operator >> (bool& value);
				BinaryInputStream& operator >> (char& value);
				BinaryInputStream& operator >> (int1& value);
				BinaryInputStream& operator >> (int2& value);
				BinaryInputStream& operator >> (int4& value);
				BinaryInputStream& operator >> (int8& value);
				BinaryInputStream& operator >> (nat1& value);
				BinaryInputStream& operator >> (nat2& value);
				BinaryInputStream& operator >> (nat4& value);
				BinaryInputStream& operator >> (nat8& value);
				BinaryInputStream& operator >> (float& value);
				BinaryInputStream& operator >> (double& value);
				BinaryInputStream& read(char* buffer, int size);

			private:
				const string exception(int size) const;

			};

		}
	}
}
#endif
