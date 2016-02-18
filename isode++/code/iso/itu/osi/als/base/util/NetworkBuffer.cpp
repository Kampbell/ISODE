/*
 * NetworkBuffer.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
#include <limits>
#include <algorithm>

#include "Poco/ByteOrder.h"
#include "Poco/NumberFormatter.h"
using Poco::ByteOrder;
using Poco::NumberFormatter;
using Poco::NotImplementedException;

#include "als/base/util/Util.h"
#include "als/base/util/NetworkBuffer.h"

using namespace std;

namespace ALS {
namespace BASE {
namespace UTIL {


#ifdef KEEP_THIS_CODE
const int NetworkBuffer::OFFSET = izeof(NetworkBuffer);
#else
const int NetworkBuffer::OFFSET = 0;
#endif

NetworkBuffer::NetworkBuffer(int length) :
	_mark(-1), _position(0), _limit(length) {
	poco_assert(length <= USHRT_MAX);
	_capacity = length;
	_owned = true;
	if (length > 0) {
		_buffer = new char[length];
		memset(_buffer, 0, length);
	}
}

NetworkBuffer::NetworkBuffer(char* buffer, int length) :
	_mark(-1), _position(0), _limit(length) {
	poco_assert(length <= USHRT_MAX);
	_capacity = length;
	_owned = false;
	_buffer = buffer;
}

NetworkBuffer::~NetworkBuffer() {
	if (_owned) {
		delete[] _buffer;
		_mark = -1, _position = _limit = _capacity = 0;
		_buffer = nullptr;
	}
}
void NetworkBuffer::use(char* buffer, int length) {
	if (_owned)
		delete _buffer;
	_mark = -1, _position = 0, _limit = length;
	poco_assert(length <= USHRT_MAX);
	_capacity = length;
	_owned = false;
	_buffer = buffer;
}
void NetworkBuffer::take(char* buffer, int length) {
	if (_owned)
		delete _buffer;
	_mark = -1, _position = 0, _limit = length;
	poco_assert(length <= USHRT_MAX);
	_capacity = length;
	_owned = true;
	_buffer = buffer;
}
byte NetworkBuffer::getByte() {
	byte b;
	if (_position + sizeof(b) > _limit)
		throw RangeException(__FILE__, __LINE__);
	b = *(byte*)here();
	_position += sizeof(b);
	return b;
}
int2 NetworkBuffer::getShort() {
	int2 s;
	if (_position + sizeof(s) > _limit)
		throw RangeException(__FILE__, __LINE__);
	s = ByteOrder::fromNetwork(*(short*)here());
	_position += sizeof(s);
	return s;
}
int4 NetworkBuffer::getInt() {
	int4 i;
	if (_position + sizeof(i) > _limit)
		throw RangeException(__FILE__, __LINE__);
	i = ByteOrder::fromNetwork(*(int*)here());
	_position += sizeof(i);
	return i;
}
nat2 NetworkBuffer::getBytes(nat2 length, byte*bytes) {
	length = std::min(length, remaining());
	memcpy(bytes, here(), length);
	_position += length;
	return length;
}
nat2 NetworkBuffer::getBytes(nat2 length, char*bytes) {
	length = std::min(length, remaining());
	memcpy(bytes, here(), length);
	_position += length;
	return length;
}
NetworkBuffer& NetworkBuffer::putByte(byte b) {
	if (_position + sizeof(b) > _limit)
		throw RangeException(__FILE__, __LINE__);
	*(byte*)here() = b;
	_position += sizeof(byte);
	return *this;
}
NetworkBuffer& NetworkBuffer::putShort(int2 s) {
	if (_position + sizeof(s) > _limit)
		throw RangeException(__FILE__, __LINE__);
	*(int2*)here() = ByteOrder::toNetwork(s);
	_position += sizeof(short);
	return *this;
}
NetworkBuffer& NetworkBuffer::putInt(int4 i) {
	if (_position + sizeof(i) > _limit)
		throw RangeException(__FILE__, __LINE__);
	*(int4*)here() = ByteOrder::toNetwork(i);
	_position += sizeof(int);
	return *this;
}
NetworkBuffer& NetworkBuffer::putBytes(nat2 length, const byte*bytes) {
	if (_position + length > _limit)
		throw RangeException(__FILE__, __LINE__);
	memcpy(here(), bytes, length);
	_position += length;
	return *this;
}
NetworkBuffer& NetworkBuffer::putBytes(nat2 length, const char*bytes) {
	if (_position + length > _limit)
		throw RangeException(__FILE__, __LINE__);
	memcpy(here(), bytes, length);
	_position += length;
	return *this;
}
NetworkBuffer& NetworkBuffer::putByte(nat2 position, byte b) {
	checkByteIndex(position);
	*(byte*)buffer(position) = b;
	return *this;
}
NetworkBuffer& NetworkBuffer::putShort(nat2 position, int2 s) {
	checkShortIndex(position);
	*(int2*)buffer(position) = ByteOrder::toNetwork(s);
	return *this;
}
NetworkBuffer& NetworkBuffer::putInt(nat2 position, int4 i) {
	checkIntIndex(position);
	*(int4*)buffer(position) = ByteOrder::toNetwork(i);
	return *this;
}
NetworkBuffer& NetworkBuffer::putLong(nat2 position, int8 l) {
	checkLongIndex(position);
	*(int8*)buffer(position) = ByteOrder::toNetwork(l);
	return *this;
}

NetworkBuffer& NetworkBuffer::newPosition(nat2 newPosition) {
	if ((newPosition > limit()) || (newPosition < 0))
		throw invalid_argument(to_string(newPosition));
	_position = newPosition;
	if (mark() > position()) _mark = -1;
	return *this;
}

NetworkBuffer& NetworkBuffer::newLimit(nat2 newLimit) {
	if ((newLimit > capacity()) || (newLimit < 0))
		throw invalid_argument(to_string(newLimit));
	_limit = newLimit;
	if (position() > limit()) _position = limit();
	if (mark() > limit()) _mark = -1;
	return *this;
}
void NetworkBuffer::dump(Printer& printer) const {
	const int BYTES_PER_LINE = 32;
	string message;
	int length = remaining();
	message.reserve(4 + (BYTES_PER_LINE * 3) + (BYTES_PER_LINE * 2) + 2);
	if (!message.empty()) message.append("\n");
	unsigned char* base = (unsigned char*)_buffer;
	int addr = 0;
	while (addr < length) {
		//				message.append(NumberFormatter::formatHex(addr, 4));
		message.append("  ");
		int offset = 0;
		while (addr + offset < length && offset < BYTES_PER_LINE) {
			//message.append(NumberFormatter::formatHex(base[addr + offset], 2));
			message.append(Util::string_to_hex(string(base[addr + offset], 2)));
			message.append(offset == 7 ? "  " : " ");
			++offset;
		}
		if (offset < 7) message.append(" ");
		while (offset < BYTES_PER_LINE) {
			message.append("   ");
			++offset;
		}
		message.append(" ");
		offset = 0;
		while (addr + offset < length && offset < BYTES_PER_LINE) {
			unsigned char c = base[addr + offset];
			message += (c >= ' ' && c < 127) ? (char)c : '.';
			++offset;
		}
		printer(message);
		message.clear();
		addr += BYTES_PER_LINE;
	}
}
const string NetworkBuffer::info() const {
	string message;
	message += "[";
	message += to_string(mark());
	message += ", ";
	message += to_string(position());
	message += ", ";
	message += to_string(limit());
	message += ", ";
	message += to_string(capacity());
	message += "]";
	return message;
}

//
// DO NOT DELETE THE LINES BELOW
// That's the only way I found to generated the template functions of shared_ptr<NetworkBuffer>
class BASE_API SharedBufferInstance : public shared_ptr<NetworkBuffer> {
public:
	SharedBufferInstance(NetworkBuffer*buffer) : shared_ptr<NetworkBuffer>(buffer) {}
};
}
}
}
