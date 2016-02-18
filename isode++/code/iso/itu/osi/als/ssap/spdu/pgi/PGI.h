/*
 * PGI.h
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_PGI_H_
#define ALS_SSAP_SPDU_PGI_H_
#include "als/ssap/spdu/HEADER.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
	enum PI_SS_TYPE {
		CALLING = 1,
		CALLED = 2
	};


class PI;

class PGI : public HEADER {
public:
	static const int	PGI_RESERVED		= 0;
	static const int	PGI_CN_ID			= 1;
	//002-004
	static const int	PGI_CN_ITEMS		= 5;
	//006-032
	static const int	PGI_AR_LINK			= 33;

private:
	list<PI*>		pgi_sons;

protected:
	PGI(byte i) : HEADER(i) {
	}

	PGI(int pgi, NetworkBuffer& tsdu) : HEADER(pgi, tsdu) {
	}
	virtual ~PGI() {
	}
	void pgli(int cc) {
		HEADER::hli(cc);
	}
	int pgli() {
		return HEADER::hli();
	}

	 NetworkBuffer* toTSDU() {
#if 0
		NetworkBuffer			pgi = HEADER::toTSDU(0);
		pgi.flip();
		list.add(pgi);

		Iterator<PI> i = sons.iterator();
		while (i.hasNext()) {
			list.addAll(i.next().toTSDU());
		}
		return list;
#endif
		return nullptr;
	}

protected:
	ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const;
	void		add(PI* pi);

public:
	string toString() const;
	string getLiteral() const;
};

}
}
}

#endif
