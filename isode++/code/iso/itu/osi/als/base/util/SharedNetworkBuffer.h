/*
 * SharedNetworkBuffer.h
 *
 *  Created on: 28 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef SHAREDBUFFER_H_
#define SHAREDBUFFER_H_

#include <iterator>
#include <memory>
using std::shared_ptr;

#include "als/base/util/NetworkBuffer.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class BASE_API SharedNetworkBuffer  : private shared_ptr<NetworkBuffer> {
			private:
				typedef shared_ptr<NetworkBuffer> BufferPtr;

			public:
				class iterator : public std::iterator<std::forward_iterator_tag, SharedNetworkBuffer>
				{
					SharedNetworkBuffer* sb;
				public:
					iterator(SharedNetworkBuffer* x) : sb(x) {}
					iterator(const iterator& mit) : sb(mit.sb) {}
					iterator& operator++() { sb = sb->next(); return *this; }
					iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
					bool operator==(const iterator& rhs) { return sb == rhs.sb; }
					bool operator!=(const iterator& rhs) { return sb != rhs.sb; }
					SharedNetworkBuffer& operator*() { return *sb; }
				};
				class const_iterator : public std::iterator<std::forward_iterator_tag, SharedNetworkBuffer>
				{
					const SharedNetworkBuffer* sb;
				public:
					const_iterator(const SharedNetworkBuffer* x) : sb(x) {}
					const_iterator(const const_iterator& mit) : sb(mit.sb) {}
					const_iterator& operator++() { sb = sb->next(); return *this; }
					const_iterator operator++(int) { const_iterator tmp(*this); operator++(); return tmp; }
					bool operator==(const const_iterator& rhs) const { return sb == rhs.sb; }
					bool operator!=(const const_iterator& rhs) const { return sb != rhs.sb; }
					const SharedNetworkBuffer& operator*() const { return *sb; }
				};

			public:
				SharedNetworkBuffer(NetworkBuffer* = nullptr);
				virtual ~SharedNetworkBuffer();

				iterator begin()	{ return iterator(this); }
				iterator end()		{ return nullptr; }

				const_iterator begin()const 	{ return const_iterator(this); }
				const_iterator end() const		{ return nullptr; }

				const nat4 total() const		{ return _total; }
				const SharedNetworkBuffer* next() const		{ return _next; }

				void operator=(const SharedNetworkBuffer& sb);
				void append(const SharedNetworkBuffer& toinsert);
				void reset();

				inline long count() const					{ return BufferPtr::use_count(); }
				inline NetworkBuffer*get() const _NOEXCEPT			{ return BufferPtr::get(); }
				inline NetworkBuffer*operator->() const _NOEXCEPT	{ return BufferPtr::operator->();  }
				inline explicit operator bool() const _NOEXCEPT	{ return get() != 0; }
			

			private:
				SharedNetworkBuffer(const SharedNetworkBuffer& sb);
				SharedNetworkBuffer*& next() { return _next; }

				SharedNetworkBuffer*	_next = nullptr;
				SharedNetworkBuffer*	_last;
				nat4			_total = 0;
			};

		}
	}
}

#endif
