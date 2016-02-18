/*
 * NotYetImplementedException.cpp
 *
 *  Created on: 23 nov. 2014
 *      Author: FrancisANDRE
 */

#include "als/base/root/NotYetImplementedException.h"

namespace ALS {
namespace BASE {
namespace ROOT {

POCO_IMPLEMENT_EXCEPTION(NotYetImplementedException, Poco::LogicException, "Protocol exception")

}
}
}
