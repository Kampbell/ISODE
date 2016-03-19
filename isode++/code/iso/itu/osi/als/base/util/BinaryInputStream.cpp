/*
 * BinaryInputStream.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cstring>
#include "Poco/Exception.h"
#include "Poco/ByteOrder.h"
using Poco::RangeException;
using Poco::ByteOrder;

#include "als/base/util/BinaryInputStream.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			BinaryInputStream::BinaryInputStream(int length, StreamByteOrder byteOrder) :
				NetworkBuffer(length) {
#if defined(ARCH_BIG_ENDIAN)
				flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
				flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
			}
			BinaryInputStream::BinaryInputStream(char* buffer, int length, StreamByteOrder byteOrder) :
				NetworkBuffer(buffer, length) {
#if defined(ARCH_BIG_ENDIAN)
				flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
				flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
			}
			BinaryInputStream::~BinaryInputStream() {
			}
			BinaryInputStream& BinaryInputStream::operator >> (bool& value) {
				if (position() + sizeof(bool) > limit())
					throw RangeException(exception(sizeof(bool)));
				value = *(bool*)bytes(); position() += sizeof(bool);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (char& value) {
				if (position() + sizeof(char) > limit())
					throw RangeException(exception(sizeof(char)));
				value = *(char*)bytes(); position() += sizeof(char);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (int1& value) {
				if (position() + sizeof(int1) > limit())
					throw RangeException(exception(sizeof(int1)));
				value = *(int1*)bytes(); position() += sizeof(int1);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (nat1& value) {
				if (position() + sizeof(nat1) > limit())
					throw RangeException(exception(sizeof(nat1)));
				value = *(nat1*)bytes(); position() += sizeof(nat1);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (int2& value) {
				if (position() + sizeof(int2) > limit())
					throw RangeException(exception(sizeof(int2)));
				value = *(int2*)bytes(); position() += sizeof(int2);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (nat2& value) {
				if (position() + sizeof(nat2) > limit())
					throw RangeException(exception(sizeof(nat2)));
				value = *(nat2*)bytes(); position() += sizeof(nat2);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (int4& value) {
				if (position() + sizeof(int4) > limit())
					throw RangeException(exception(sizeof(int4)));
				value = *(int4*)bytes(); position() += sizeof(int4);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (nat4& value) {
				if (position() + sizeof(nat4) > limit())
					throw RangeException(exception(sizeof(nat4)));
				value = *(nat4*)bytes(); position() += sizeof(nat4);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (int8& value) {
				if (position() + sizeof(int8) > limit())
					throw RangeException(exception(sizeof(int8)));
				value = *(int8*)bytes(); position() += sizeof(int8);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (nat8& value) {
				if (position() + sizeof(nat8) > limit())
					throw RangeException(exception(sizeof(nat8)));
				value = *(nat8*)bytes(); position() += sizeof(nat8);
				if (flipbytes)
					value = ByteOrder::fromNetwork(value);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (float& value) {
				if (position() + sizeof(float) > limit())
					throw RangeException(exception(sizeof(float)));
				value = *(float*)bytes(); position() += sizeof(float);
				return *this;
			}
			BinaryInputStream& BinaryInputStream::operator >> (double& value) {
				if (position() + sizeof(double) > limit())
					throw RangeException(exception(sizeof(double)));
				value = *(double*)bytes(); position() += sizeof(double);
				return *this;
			}


			BinaryInputStream& BinaryInputStream::read(char* buffer, int size) {
				if (position() + size > limit())
					throw RangeException(exception(size));
				memcpy(buffer, bytes(), size); position() += size;

				return *this;
			}
			const string BinaryInputStream::exception(int size) const {
				string message = "cannot get object of size ";
				message += to_string(size);
				message += " from buffer " + info();
				return message;
			}
		}
	}
}
