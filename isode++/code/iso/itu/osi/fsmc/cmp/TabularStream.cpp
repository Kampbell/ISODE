//
// TabularStream.cpp
//
// Library: Foundation
// Package: Streams
// Module:  TabularStream
//
// Copyright (c) 2016, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//

#include <iostream>
#include <ios>
#include <locale>
#include <cstdio>
#include "TabularStream.h"
using namespace std;
using std::streambuf;
using std::fill_n;
using std::ostream;
using std::ostreambuf_iterator;

namespace Poco {
TabularStreamBuf::TabularStreamBuf() :
	_tab(0),
	_need(true) {}

int TabularStreamBuf::tab() const {
	return _tab;
}
void TabularStreamBuf::tab() {
	_tab += 1;
}
void TabularStreamBuf::back() {
	if (_tab >= 0) _tab -= 1;
}
//		IndentStream(std::ostream &os) : ib(os.rdbuf()), std::ostream(&ib) {};

TabularIOS::TabularIOS(std::ostream &os) :
	_buf(os.rdbuf()) {
//		poco_ios_init(&_buf);
}

ios::int_type TabularStreamBuf::overflow(ios::int_type c)
{
	if (traits_type::eq_int_type(c, traits_type::eof()))
		return this->sputc(c);

	if (_need) {
		fill_n(std::ostreambuf_iterator<char>(this), _tab, '\t');
		_need = false;
	}

	if (traits_type::eq_int_type(this->sputc(c), traits_type::eof()))
		return traits_type::eof();

	if (traits_type::eq_int_type(c, traits_type::to_char_type('\n')))
		_need = true;

	return traits_type::not_eof(c);
}

TabularOutputStream::TabularOutputStream(std::ostream &os) :
	std::ostream(&_buf)
{
}

}
std::ostream& tab(std::ostream& stream)
{
	Poco::TabularOutputStream* tos = dynamic_cast<Poco::TabularOutputStream*>(&stream);
	if (tos != nullptr) {
		tos->rdbuf()->tab();
	}
	return stream;
}

std::ostream& back(std::ostream& stream)
{
	Poco::TabularOutputStream* tos = dynamic_cast<Poco::TabularOutputStream*>(&stream);
	if (tos != nullptr) {
		tos->rdbuf()->back();
	}
	return stream;
}
