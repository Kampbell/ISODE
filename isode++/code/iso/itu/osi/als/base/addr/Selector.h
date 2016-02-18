/*
 * Selector.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_ADDR_SELECTOR_H_
#define ALS_BASE_ADDR_SELECTOR_H_

#include <string>
#include "Poco/ByteOrder.h"
#include "als/base/base.h"

using std::string;
using Poco::ByteOrder;

namespace ALS {
namespace BASE {
namespace ADDR {

class BASE_API Selector {
public:
	static const int SIZE = 64;
	enum Kind {
		EMPTY, NUMBER, STRING
	};
private:
	mutable string sl_string;

	Kind	sl_kind = EMPTY;
	byte	sl_length = 0;
	union {
		nat2	number;			// always in Network Byte Order
		byte	literal[SIZE];
	} value;
	bool sl_present = false;

public:
	Selector();
	Selector(nat2 port);
	Selector(int cc, const byte* value);
	Selector(const Selector& selector);
	~Selector() {}

	Selector&		operator = (const Selector& selector);
	bool			operator < (const Selector& other) const;

	const char*		parse(const char* addr);
	static Selector	parse(const string& addr);

	const Kind		kind() const		{ return sl_kind; }
	const nat2		number() const		{ return ByteOrder::fromNetwork(value.number); }
	const byte*		literal() const		{ return value.literal; }
	const char*		data() const		{ return (char*)value.literal; }
	const byte		length() const		{ return sl_length; }
	const bool		isNull() const		{ return sl_length == 0; }
	const bool		isNotNull() const	{ return sl_length > 0; }
	const bool		isPresent() const	{ return sl_present; }
	const string&	to_string() const;

};

}
}
}

#endif
