/*
 * Exception.cpp
 *
 *  Created on: 19 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Exception.h"

namespace ALS {
namespace SSAP {
POCO_IMPLEMENT_EXCEPTION(Exception, Poco::LogicException, "SSAP Exception")
}
}
