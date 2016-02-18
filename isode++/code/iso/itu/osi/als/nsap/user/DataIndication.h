/*
 * DataIndication.h
 *
 *  Created on: 6 janv. 2015
 *      Author: FrancisANDRE
 */

#ifndef ALS_NSAP_USER_DATA_INDICATION_H_
#define ALS_NSAP_USER_DATA_INDICATION_H_
#include <memory>
using std::shared_ptr;

#include "als/nsap/nsap.h"

#include "als/base/util/SharedNetworkBuffer.h"
#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
using ALS::BASE::UTIL::SharedNetworkBuffer;


namespace ALS {
namespace NSAP {
namespace USER {

class DataIndication : public virtual Indication {
public:
	virtual ReturnCode NDataIndication(const SharedNetworkBuffer& buffer) = 0;
};

}
}
}

#endif
