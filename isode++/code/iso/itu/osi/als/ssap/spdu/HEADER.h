/*
 * HEADER.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_HEADER_H_
#define ALS_SSAP_SPDU_HEADER_H_
#include <list>
using std::list;

#include <memory>
using std::unique_ptr;

#include <string>
using std::string;
using std::to_string;

#include "als/ssap/ssap.h"
#include "als/base/util/NetworkBuffer.h"

using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
namespace SSAP {
namespace SPDU {

class HEADER {
private:
	byte	id;
	byte	l0;
	byte	l1;
	byte	l2;
	nat2	size;

protected:
	HEADER(byte id);
	HEADER(byte id, NetworkBuffer& tsdu);
	virtual ~HEADER();

public:
	byte si() const		{ return id; }
	byte pi()  const	{ return id; }
	byte pgi()  const	{ return id; }
	int length() const;
	virtual ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const;


protected:
	int			hli() const ;
	void		hli(int cc);
	void		allocate(unique_ptr<NetworkBuffer>& tsdu, int cc) const;
	int			add(HEADER* header);
};

}
}
}

#endif
