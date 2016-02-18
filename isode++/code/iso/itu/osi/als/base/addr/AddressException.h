/*
 * AddressException.h
 *
 *  Created on: 11 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_ADDR_AddressException_H_
#define ALS_BASE_ADDR_AddressException_H_

#include <typeinfo>
#include "Poco/Exception.h"
#include "Poco/Net/NetException.h"
#include "als/base/base.h"

namespace ALS {
namespace BASE {
namespace ADDR {

POCO_DECLARE_EXCEPTION(BASE_API, AddressException, Poco::Net::InvalidAddressException)
}
}
}

#endif
