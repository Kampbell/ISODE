/*
 * NetworkBuffer.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_UTIL_Buffer_H_
#define ALS_BASE_UTIL_Buffer_H_

#include <string>
using std::to_string;
using std::string;
#include <memory>
using std::shared_ptr;

#include "Poco/Exception.h"
using Poco::InvalidArgumentException;
using Poco::RangeException;

#include "als/base/base.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			class BASE_API NetworkBuffer {
			private:
				static const int OFFSET;

				// Invariants: mark <= position <= limit <= capacity
				nat2				_position;
				nat2				_limit;
				nat2				_capacity;
				nat2				_mark;
				char*				_buffer;
				bool				_owned;

				// Creates a new buffer with the given mark, position, limit, and capacity,
				// after checking invariants.
				//
				//	NetworkBuffer(int mark, int pos, int lim, int cap) {       // package-private
				//		if (cap < 0)
				//			throw new IllegalArgumentException("Negative capacity: " + cap);
				//		this._capacity = cap;
				//		limit(lim);
				//		position(pos);
				//		if (mark >= 0) {
				//			if (mark > pos)
				//				throw new IllegalArgumentException(
				//						"mark > position: (" + mark + " > " + pos + ")");
				//			this._mark = mark;
				//		}
				//	}
			public:
				nat2& position() 						{ return _position; }
				nat2& limit() 							{ return _limit; }
				//	nat2& mark() 							{ return _mark;	}
			private:
				const nat2&		mark() const			{ return _mark; }

			public:
				const nat2&		capacity() const		{ return _capacity; }
				const nat2&		position() const		{ return _position; }
				const nat2&		limit() const			{ return _limit; }

			public:
				NetworkBuffer() = delete;
				NetworkBuffer(int length);
				NetworkBuffer(char* buffer, int length);
				NetworkBuffer(const NetworkBuffer&) = delete;
				NetworkBuffer& operator = (const NetworkBuffer&) = delete;
				virtual ~NetworkBuffer();

				void use(char* buffer, int length);
				void take(char* buffer, int length);

				nat2	remaining() const				{ return _limit - _position; }
				bool	hasRemaining() const			{ return _position < _limit; }
				nat2	position(int position)			{ return _position = position; }

			private:
				NetworkBuffer& newPosition(nat2 newPosition);
				NetworkBuffer& newLimit(nat2 newLimit);

			public:
				NetworkBuffer& markit();
				NetworkBuffer& reset();
				NetworkBuffer& clear();
				NetworkBuffer& flip();
				NetworkBuffer& rewind();
				NetworkBuffer& shrink(int size);
				NetworkBuffer& skip(int size);

				inline byte		get()			{ return getByte(); }
				inline NetworkBuffer&	put(byte b)		{ return putByte(b); }

				byte	getByte();
				int2	getShort();
				int4	getInt();
				int8	getLong();

				NetworkBuffer&	putByte(byte b);
				NetworkBuffer&	putShort(int2 s);
				NetworkBuffer&	putInt(int4 i);
				NetworkBuffer&	putLong(int8 l);

				NetworkBuffer&	putByte(nat2 position, byte b);
				NetworkBuffer&	putShort(nat2 position, int2 s);
				NetworkBuffer&	putInt(nat2 position, int4 i);
				NetworkBuffer&	putLong(nat2 position, int8 l);

				nat2	getBytes(nat2 length, byte* bytes);
				NetworkBuffer&	putBytes(nat2 length, const byte*bytes);
				nat2	getBytes(nat2 length, char* bytes);
				NetworkBuffer&	putBytes(nat2 length, const char*bytes);


			private:
				void truncate();

			public:
#ifdef KEEP_THIS_CODE
				void* operator new(size_t size, unsigned short length){
					return new char[size + length];
				}
					void operator delete(void* where, unsigned short length) {
					delete where;
				}
				void operator delete(void* where) {
					delete where;
				}

				inline char* data() const { return ((char*)this) + OFFSET + position(); }
				inline byte* here() const { return ((byte*)this) + OFFSET + position(); }
				inline byte* here(int position) const { return ((byte*)this) + OFFSET + position; }
#endif
				inline char* begin()					{ return ((char*)_buffer); }
				inline char* data()						{ return ((char*)_buffer) + position(); }
				inline const char* begin() const		{ return ((char*)_buffer); }
				inline const char* data() const			{ return ((char*)_buffer) + position(); }
				inline byte at(int no) const			{ return *(_buffer + position() + no); }
				inline byte operator[](int no) const	{ return *(_buffer + position() + no); }
				string str(int length) const			{ return string(data(), length); }

				void			dump(Printer& printer) const;
				const string	info() const;

				inline byte* buffer(int position)		{ return ((byte*)_buffer) + position; }
				inline byte* here() 					{ return ((byte*)_buffer) + position(); }

				int checkByteIndex(nat2 index);
				int checkShortIndex(nat2 index);
				int checkIntIndex(nat2 index);
				int checkLongIndex(nat2 index);
private:
				void discardMark();
			};

			inline NetworkBuffer& NetworkBuffer::markit() {
				_mark = position();
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::reset() {
				int m = _mark;
				if (m < 0)
					throw InvalidArgumentException("");
				_position = m;
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::clear() {
				_position = 0;
				_limit = _capacity;
				_mark = -1;
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::flip() {
				_limit = _position;
				_position = 0;
				_mark = -1;
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::rewind() {
				_position = 0;
				_mark = -1;
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::shrink(int size) {
				if (size > remaining())
					throw InvalidArgumentException(to_string(size));
				_limit = _position + size;
				return *this;
			}
			inline NetworkBuffer& NetworkBuffer::skip(int size) {
				return newPosition(_position + size);
			}
			inline void NetworkBuffer::truncate() {
				_mark = -1;
				_position = 0;
				_limit = 0;
				_capacity = 0;
			}
			inline int NetworkBuffer::checkByteIndex(nat2 index) {
				if (!(0 <= index && index <= limit() - sizeof(byte)))
					throw RangeException(to_string(index));
				return index;
			}
			inline int NetworkBuffer::checkShortIndex(nat2 index) {
				if (!(0 <= index && index <= limit() - sizeof(nat2)))
					throw RangeException(to_string(index));
				return index;
			}
			inline int NetworkBuffer::checkIntIndex(nat2 index) {
				if (!(0 <= index && index <= limit() - sizeof(nat4)))
					throw RangeException(to_string(index));
				return index;
			}
			inline int NetworkBuffer::checkLongIndex(nat2 index) {
				if (!(0 <= index && index <= limit() - sizeof(nat8)))
					throw RangeException(to_string(index));
				return index;
			}
			inline void NetworkBuffer::discardMark() {
				_mark = -1;
			}
		}
	}
}

#endif
