/*
 * BinaryOutputStream.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BINARYOUTPUTSTREAM_H_
#define BINARYOUTPUTSTREAM_H_

#include "als/base/base.h"
#include "als/base/util/NetworkBuffer.h"
#include "als/base/util/OutputStream.h"


namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BASE_API BinaryOutputStream : public OutputStream, public virtual NetworkBuffer {
			private:
				bool flipbytes;

			public:
				BinaryOutputStream(int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				BinaryOutputStream(char* buffer, int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				virtual ~BinaryOutputStream();

				BinaryOutputStream& operator << (bool value);
				BinaryOutputStream& operator << (char value);
				BinaryOutputStream& operator << (int1 value);
				BinaryOutputStream& operator << (int2 value);
				BinaryOutputStream& operator << (int4 value);
				BinaryOutputStream& operator << (int8 value);
				BinaryOutputStream& operator << (nat1 value);
				BinaryOutputStream& operator << (nat2 value);
				BinaryOutputStream& operator << (nat4 value);
				BinaryOutputStream& operator << (nat8 value);
				BinaryOutputStream& operator << (float value);
				BinaryOutputStream& operator << (double value);


				BinaryOutputStream& operator << (const NetworkBuffer& buffer);
				BinaryOutputStream& operator << (const std::string& value);
				BinaryOutputStream& operator << (const char* value);

				BinaryOutputStream& put(const char* bytes, int length);
				BinaryOutputStream& write(const char* bytes, int length);

				BinaryOutputStream& put(int position, char b);
				BinaryOutputStream& put(int position, unsigned char b);
				BinaryOutputStream& put(int position, int2 s);
				BinaryOutputStream& put(int position, nat2 s);
				BinaryOutputStream& put(int position, int4 i);
				BinaryOutputStream& put(int position, nat4 i);

			private:
				const string exception(int size) const;

			};

		}
	}
}
#endif
