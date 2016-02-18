/*
 * ProtocoleException.cpp
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/base/util/ProtocolException.h"

namespace ALS {
namespace BASE {
namespace UTIL {
POCO_IMPLEMENT_EXCEPTION(ProtocolException, Poco::LogicException, "Protocol exception")


}
}
}
