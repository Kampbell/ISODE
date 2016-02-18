/*
 * AddressException.cpp
 *
 *  Created on: 11 août 2014
 *      Author: FrancisANDRE
 */

#include "als/base/addr/AddressException.h"

namespace ALS {
	namespace BASE {
		namespace ADDR {
			POCO_IMPLEMENT_EXCEPTION(AddressException, Poco::Net::InvalidAddressException, "address invalid")
}
}
}
