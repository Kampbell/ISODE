/*
 * Exception.h
 *
 *  Created on: 19 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_EXCEPTION_H_
#define ALS_SSAP_EXCEPTION_H_
#include "Poco/Exception.h"
#include "als/ssap/ssap.h"

namespace ALS {
namespace SSAP {

POCO_DECLARE_EXCEPTION(SSAP_API, Exception, Poco::LogicException);

}
}

#endif
