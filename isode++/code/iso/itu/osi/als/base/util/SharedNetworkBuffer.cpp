/*
 * SharedNetworkBuffer.cpp
 *
 *  Created on: 28 janv. 2016
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <algorithm>
#include "SharedNetworkBuffer.h"

using namespace std;

namespace ALS {
namespace BASE {
namespace UTIL {
SharedNetworkBuffer::SharedNetworkBuffer(NetworkBuffer* buffer) : BufferPtr(buffer) {
	_last = this;
	if (buffer)
		_total = buffer->remaining();
}
SharedNetworkBuffer::SharedNetworkBuffer(const SharedNetworkBuffer& sharedbuffer) : BufferPtr(sharedbuffer) {
	_last = this;
	_total = sharedbuffer->remaining();
}
SharedNetworkBuffer::~SharedNetworkBuffer() {
	if (_next)
		delete _next, _next = nullptr;
	_total = 0, _last = this;
}
void SharedNetworkBuffer::operator=(const SharedNetworkBuffer& sb) {
	*static_cast<BufferPtr*>(this) = sb;
	_last = this;
	_total = sb._total;
}
void SharedNetworkBuffer::append(const SharedNetworkBuffer& buffer) {
	poco_assert(buffer.next() == nullptr);
	_last->next() =  new SharedNetworkBuffer(buffer);
	_last = _last->next();
	_total += buffer->remaining();
}
void SharedNetworkBuffer::reset() {
	if (_next)
		delete _next, _next = nullptr;
	BufferPtr::reset();
}

}
}
}
