/*
 * BinaryInputOutputStream.h
 *
 *  Created on: 15 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BinaryInputOutputStream_H_
#define BinaryInputOutputStream_H_

#include "als/base/util/BinaryInputStream.h"
#include "als/base/util/BinaryOutputStream.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BASE_API BinaryInputOutputStream : public BinaryInputStream, public BinaryOutputStream {
			public:
				BinaryInputOutputStream(int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				BinaryInputOutputStream(char* buffer, int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
				virtual ~BinaryInputOutputStream();
			};

		}
	}
}
#endif
