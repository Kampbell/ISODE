/*
 * AFI.h
 *
 *  Created on: 5 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_ADDR_AFI_H_
#define ALS_NSAP_ADDR_AFI_H_

#include <string>

using std::string;

namespace ALS {
namespace NSAP {
namespace ADDR {
	class NSAPAddr;

class AFI {
protected:
	 string			name_;
	 string			dec0_;
	 string			hex0_;
	 string			dec1_;
	 string			hex1_;
	 string			ia5_;
	 int			idi_len_;
	 int			dec_dslen_;
	 int			hex_dslen_;
	 mutable string	string_;

public:

	AFI(const string& name, const string& dec0, const string& hex0, const string& dec1, const string& hex1, const string& ia5, int idi_len, int dec_dslen, int hex_dslen) {

		this->name_			= name;
		this->dec0_			= dec0;
		this->hex0_			= hex0;
		this->dec1_			= dec1;
		this->hex1_			= hex1;
		this->ia5_			= ia5;
		this->idi_len_		= idi_len;
		this->dec_dslen_	= dec_dslen;
		this->hex_dslen_	= hex_dslen;

	}
	virtual ~AFI() {
	}

	virtual const char* parse(NSAPAddr& nsap, const char* address) const = 0;

	const string&	name() const	{ return name_; }
	const string&	dec0() const	{ return dec0_; }
	const string&	hex0() const	{ return hex0_; }
	const string&	dec1() const	{ return dec1_; }
	const string&	hex1() const	{ return hex1_; }
	const string&	ia5() const		{ return ia5_; }
	int				idilen() const	{ return idi_len_; }
	int				decds() const	{ return dec_dslen_; }
	int				hexds() const	{ return hex_dslen_; }

	const string&	asstring() const;
};

}
}
}

#endif
