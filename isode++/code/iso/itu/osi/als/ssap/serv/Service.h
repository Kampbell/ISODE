/*
 * Service.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SERV_SERVICE_H_
#define ALS_SSAP_SERV_SERVICE_H_
#include "als/ssap/ssap.h"

#include "als/base/util/Bits.h"
using ALS::BASE::UTIL::Bits;
#include "als/ssap/Requirement.h"
using ALS::SSAP::Requirement;

namespace ALS {
	namespace BASE {
		namespace ROOT {
			class Logger;
		}
	}
	namespace SSAP {
		class Reference;
	}
}
using ALS::SSAP::Reference;

namespace ALS {
namespace SSAP {
namespace SERV {
class Service {
public:
	virtual ~Service() {}
	int settings();

	virtual const Reference& reference() const = 0;
	virtual Requirement requirements() const = 0;
	virtual int available() const = 0;
	virtual Bits owned() const = 0;
	virtual bool isInitiator() const = 0;
	virtual bool isResponder() const = 0;
	virtual ALS::BASE::ROOT::Logger* logger() = 0;

};

}
}
}

#endif
