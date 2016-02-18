/*
 * Link.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_LINKER_H_
#define ALS_TSAP_USER_LINKER_H_

#include "als/tsap/tsap.h"

namespace ALS {
namespace TSAP {
namespace PROV {
	class Provider;
}
namespace USER {
class Initiator;
class Responder;

class TSAP_API Linker {
public:
	virtual ~Linker() {}
	virtual Initiator* initiator() const = 0;
	virtual PROV::Provider*&  provider()  = 0;
protected:
	Linker() {}
private:
	Linker(const Linker&){}
	Linker& operator = (const Linker&) { return *this; };

};

}
}
}

#endif
