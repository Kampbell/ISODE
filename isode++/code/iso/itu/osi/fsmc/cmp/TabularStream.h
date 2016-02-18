//
// TabularStream.h
//
// $Id: //poco/1.4/Foundation/include/Poco/TabularStream.h#1 $
//
// Library: Foundation
// Package: Streams
// Module:  TabularStream
//
// Definition of the TabularStreamBuf, TabularInputStream and TabularOutputStream classes.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Foundation_TabularStream_INCLUDED
#define Foundation_TabularStream_INCLUDED


//#include "Poco/Foundation.h"
#define Foundation_API 

#include <ostream>


namespace Poco {
class TabularStreamBuf : public std::streambuf
{
public:
	TabularStreamBuf();

	int tab() const;
	void tab();
	void back();

protected:
	virtual int_type overflow(int_type c);

private:
	int _tab;
	bool _need;
};


class Foundation_API TabularIOS: public virtual std::ios
	/// The base class for TabularInputStream and TabularOutputStream.
	///
	/// This class is needed to ensure the correct initialization
	/// order of the stream buffer and base classes.
	///
	/// Tabulars are always opened in binary mode, a text mode
	/// with CR-LF translation is not supported. Thus, the
	/// file is always opened as if the std::ios::binary flag
	/// was specified.
	/// Use an InputLineEndingConverter or OutputLineEndingConverter
	/// if you require CR-LF translation.
	///
	/// On Windows platforms, if POCO_WIN32_UTF8 is #define'd,
	/// UTF-8 encoded Unicode paths are correctly handled.
{
public:
	TabularIOS();
		/// Creates the basic stream.
		
	~TabularIOS();
		/// Destroys the stream.

	TabularStreamBuf* rdbuf();
		/// Returns a pointer to the underlying streambuf.

protected:
	TabularStreamBuf _buf;
};


class Foundation_API TabularOutputStream: public TabularIOS, public std::ostream
	/// An output stream for writing to a file.
	///
	/// Tabulars are always opened in binary mode, a text mode
	/// with CR-LF translation is not supported. Thus, the
	/// file is always opened as if the std::ios::binary flag
	/// was specified.
	/// Use an OutputLineEndingConverter if you require CR-LF translation.
	///
	/// On Windows platforms, if POCO_WIN32_UTF8 is #define'd,
	/// UTF-8 encoded Unicode paths are correctly handled.
{
public:

	TabularOutputStream(std::ostream &os);
		/// Creates an unopened TabularOutputStream.
		
	~TabularOutputStream();
		/// Destroys the TabularOutputStream.

	friend std::ostream& tab(std::ostream& stream);
	friend std::ostream& back(std::ostream& stream);

};




} // namespace Poco


#endif // Foundation_TabularStream_INCLUDED

#if 0
#include <iostream>
#include <streambuf>
#include <locale>
#include <cstdio>

using std::streambuf;
using std::fill_n;
using std::ostream;
using std::ostreambuf_iterator;

namespace Poco {

	class TabularBuffer : public streambuf
	{
	public:

		TabularBuffer(streambuf* sbuf) : _sbuf(sbuf), _tab(0), _need(true) {}

		int tab() const {
			return _tab;
		}
		void tab() {
			_tab += 1;
		}
		void back() {
			if (_tab >= 0) _tab -= 1;
		}

	protected:
		virtual int_type overflow(int_type c) {

			if (traits_type::eq_int_type(c, traits_type::eof()))
				return _sbuf->sputc(c);

			if (_need) {
				fill_n(std::ostreambuf_iterator<char>(_sbuf), _tab, '\t');
				_need = false;
			}

			if (traits_type::eq_int_type(_sbuf->sputc(c), traits_type::eof()))
				return traits_type::eof();

			if (traits_type::eq_int_type(c, traits_type::to_char_type('\n')))
				_need = true;

			return traits_type::not_eof(c);
		}

		streambuf* _sbuf;
		int _tab;
		bool _need;
	};

	class IndentStream : public std::ostream {
	public:
		IndentStream(std::ostream &os) : ib(os.rdbuf()), std::ostream(&ib) {};

		friend std::ostream& tab(std::ostream& stream);

		friend std::ostream& back(std::ostream& stream);

	private:
		TabularBuffer ib;
	};
	std::ostream& tab(std::ostream& stream) {
		IndentStream* pIndentStream = dynamic_cast<IndentStream*>(&stream);
		if (pIndentStream != nullptr) {
			pIndentStream->ib.tab();
		}
		return stream;
	}

	std::ostream& back(std::ostream& stream) {
		IndentStream* pIndentStream = dynamic_cast<IndentStream*>(&stream);
		if (pIndentStream != nullptr) {
			pIndentStream->ib.back();
		}
		return stream;
	}
}

#endif