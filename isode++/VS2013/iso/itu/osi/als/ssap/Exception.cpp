/*
 * Exception.cpp
 *
 *  Created on: 19 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/Exception.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
POCO_IMPLEMENT_EXCEPTION(Exception, Poco::LogicException, "SPDU Exception")
}
}
