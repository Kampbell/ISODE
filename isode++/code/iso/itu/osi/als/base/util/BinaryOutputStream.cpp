/*
 * BinaryOutputStream.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cstring>
#include "Poco/Exception.h"
#include "Poco/ByteOrder.h"
using Poco::RangeException;
using Poco::ByteOrder;

#include "als/base/util/BinaryOutputStream.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			BinaryOutputStream::BinaryOutputStream(int length, StreamByteOrder byteOrder) : NetworkBuffer(length) {
#if defined(ARCH_BIG_ENDIAN)
				flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
				flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
			}
			BinaryOutputStream::BinaryOutputStream(char* buffer, int length, StreamByteOrder byteOrder) : NetworkBuffer(buffer, length) {
#if defined(ARCH_BIG_ENDIAN)
				flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
				flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
			}
			BinaryOutputStream::~BinaryOutputStream() {
			}
			BinaryOutputStream& BinaryOutputStream::operator << (bool value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(bool*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (char value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(char*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (int1 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(int1*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (int2 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(int2*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (int4 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(int4*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (int8 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(int8*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (nat1 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(nat1*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (nat2 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(nat2*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (nat4 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(nat4*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (nat8 value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(nat8*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (float value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(float*)bytes() = value; position() += sizeof(value);
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (double value) {
				if (position() + sizeof(value) > limit())
					throw RangeException(exception(sizeof(value)));
				*(double*)bytes() = value; position() += sizeof(value);
				return *this;
			}

			BinaryOutputStream& BinaryOutputStream::operator << (const std::string& value) {
				if (position() + value.size() > limit())
					throw RangeException(exception(value.size()));
				memcpy(bytes(), value.data(), value.size()); position() += value.size();
				return *this;
			}
			BinaryOutputStream& BinaryOutputStream::operator << (const char* value) {
				if (position() + strlen(value) > limit())
					throw RangeException(exception(sizeof(int)));
				memcpy(bytes(), value, strlen(value)); position() += strlen(value);
				return *this;
			}
			BinaryOutputStream&   BinaryOutputStream::operator <<(const NetworkBuffer& buffer) {
				if (position() + buffer.remaining() > limit())
					throw RangeException(exception(buffer.remaining()));
				memcpy(bytes(), buffer.data(), buffer.remaining());
				position() += buffer.remaining();
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, char value) {
				checkByteIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(byte*)(bytes() + position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, unsigned char value) {
				checkByteIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(byte*)(bytes() + position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, int2 value) {
				checkShortIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(int2*)buffer(position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, nat2 value) {
				checkShortIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(nat2*)buffer(position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, int4 value) {
				checkIntIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(int4*)buffer(position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(int position, nat4 value) {
				checkIntIndex(position);
				if (flipbytes)
					value = ByteOrder::toNetwork(value);
				*(nat4*)buffer(position) = value;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::put(const char*data, int length) {
				if (position() + length > limit())
					throw RangeException(exception(length));
				memcpy(bytes(), data, length); position() += length;
				return *this;
			}
			BinaryOutputStream&	BinaryOutputStream::write(const char*data, int length) {
				if (position() + length > limit())
					throw RangeException(exception(length));
				memcpy(bytes(), data, length); position() += length;
				return *this;
			}
			const string BinaryOutputStream::exception(int size) const {
				string message = "cannot put object of size ";
				message += to_string(size);
				message += " to buffer " + info();
				return message;
			}
		}
	}
}