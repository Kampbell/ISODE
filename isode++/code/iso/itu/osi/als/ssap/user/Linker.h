/*
 * Link.h
 *
 *  Created on: 3 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_LINKER_H_
#define ALS_SSAP_USER_LINKER_H_

#include "als/ssap/ssap.h"

namespace ALS {
namespace SSAP {
namespace SERV {
	class Responder;
}
namespace USER {
class Initiator;
class Responder;

class Linker {
public:
	virtual ~Linker() {}
	virtual USER::Initiator*	initiator() const = 0;
	virtual SERV::Responder*&	provider()  = 0;

};

}
}
}

#endif
