/*
 * TPDU.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPCI_TPCI_H_
#define ALS_TSAP_TPCI_TPCI_H_
#include <memory>
using std::unique_ptr;


#include "als/tsap/tsap.h"
#include "als/base/util/NetworkBuffer.h"

using namespace ALS::BASE::UTIL;

namespace ALS {
namespace TSAP {
namespace PROV {
	class Provider;
};
using ALS::TSAP::PROV::Provider;
namespace TPDU {

class TSAP_API TPCI {
	friend Provider;
public:
	static const byte		TPDU_CR	= 0xe0; /* CONNECTION REQUEST */
	static const byte		TPDU_CC	= 0xd0; /* CONNECTION CONFIRMATION */
	static const byte		TPDU_DR	= 0x80; /* DISCONNECT REQUEST */
	static const byte		TPDU_DC	= 0xc0; /* DISCONNECT CONFIRMATION */
	static const byte		TPDU_DT	= 0xf0; /* DATA */
	static const byte		TPDU_ED	= 0x10; /* EXPEDITED DATA */
	static const byte		TPDU_AK	= 0x60; /* ACKNOWLEDGE */
	static const byte		TPDU_EA	= 0x20; /* EXPEDITED ACKNOWLEDGE */
	static const byte		TPDU_RJ	= 0x50; /* REJECT */
	static const byte		TPDU_ER	= 0x70; /* ERROR */

protected:
	static const byte		START	= 2;	// li + code
	static const byte		TPDU_MIN_LENGTH = 3;
	
	TPCI(byte code);
	TPCI(byte li, byte code);

public:
	byte			li() const		{ return tp_li; }
	byte			code() const	{ return tp_code; }
	NetworkBuffer*	data() const	{ return tp_buffer; }

	static TPCI*	decodeTPDU(NetworkBuffer* nsdu);
	virtual int		encode(unique_ptr<NetworkBuffer>& nsdu) = 0;
	virtual int		decode(NetworkBuffer* nsdu) = 0;

	virtual void	setData(NetworkBuffer* buffer);
	virtual void	setData(const string&  message);
	virtual void	setData(int cc, const byte* data);

protected:
	virtual int		fixedSize() const = 0;
	virtual int		variableSize() const = 0;

	int				minimumLength() const		{ return 1/* code */ + fixedSize(); }
	int				totalLength() const			{ return 1/*li*/ + headerLength(); }
	int				headerLength() const		{ return 1/*code*/ + fixedSize() + variableSize(); }
	void			addData(unique_ptr<NetworkBuffer>& nsdu);

protected:
	int				tp_len;
	const byte*		tp_data;
	NetworkBuffer*	tp_buffer;

	byte			tp_li;
	byte			tp_code;


private:
	TPCI(const TPCI&);
	TPCI& operator = (const TPCI&);

};

}
}
}

#endif
