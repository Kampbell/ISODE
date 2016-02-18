/*
 * ProtocoleException.h
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_PROTOCOLEEXCEPTION_H_
#define ALS_BASE_PROTOCOLEEXCEPTION_H_

#include "Poco/Exception.h"
#include "als/base/base.h"

namespace ALS {
namespace BASE {
namespace UTIL {

POCO_DECLARE_EXCEPTION(BASE_API, ProtocolException, Poco::LogicException)
}
}
}

#endif
