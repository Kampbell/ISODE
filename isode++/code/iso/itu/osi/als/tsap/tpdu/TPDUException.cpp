/*
 * TPDUException.cpp
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/tsap/tpdu/TPDUException.h"

namespace ALS {
namespace TSAP {
namespace TPDU {

TPDUException::TPDUException(int code) : ProtocolException(code) {
}

TPDUException::~TPDUException() {
}

}
}
}
