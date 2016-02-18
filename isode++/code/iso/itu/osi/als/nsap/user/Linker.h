/*
 * Linker.h
 *
 *  Created on: 10 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_LINKER_H_
#define ALS_NSAP_USER_LINKER_H_

#include "als/nsap/nsap.h"

namespace ALS {
namespace NSAP {
namespace SERV {
	class Initiator;
	class Responder;
}
namespace USER {
	class Initiator;
	class Responder;

class Linker {
public:
	virtual ~Linker() {}
	virtual ALS::NSAP::USER::Initiator* nsapUserInitiator() const = 0;
	virtual ALS::NSAP::USER::Responder* nsapUserResponder() const = 0;
	virtual ALS::NSAP::SERV::Initiator*&nsapServInitiator() = 0;
	virtual ALS::NSAP::SERV::Responder*&nsapServResponder() = 0;
	/*
	virtual Initiator* initiator() const = 0;
	virtual Responder* responder() const = 0;
	virtual PROV::Provider*&  provider()  = 0;
	*/
};

}
}
}

#endif
