/*
 * InputStreamOutputStream.cpp
 *
 *  Created on: 15 juil. 2015
 *      Author: FrancisANDRE
 */

#include "als/base/util/BinaryInputOutputStream.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			BinaryInputOutputStream::BinaryInputOutputStream(int length, StreamByteOrder byteOrder) :
				BinaryInputStream(length), BinaryOutputStream(length, byteOrder), NetworkBuffer(length) {
			}
			BinaryInputOutputStream::BinaryInputOutputStream(char* buffer, int length, StreamByteOrder byteOrder) :
				BinaryInputStream(buffer, length), BinaryOutputStream(buffer, length, byteOrder), NetworkBuffer(buffer, length) {
			}
			BinaryInputOutputStream::~BinaryInputOutputStream() {
			}
		}
	}
}