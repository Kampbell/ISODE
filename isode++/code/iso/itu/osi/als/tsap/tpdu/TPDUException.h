/*
 * TPDUException.h
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_TPDU_EXCEPTION_H_
#define ALS_TSAP_TPDU_TPDU_EXCEPTION_H_

#include "als/base/util/ProtocolException.h"

using ALS::BASE::UTIL::ProtocolException;

namespace ALS {
namespace TSAP {
namespace TPDU {

class TPDUException : public ProtocolException {
public:
	TPDUException(int code);
	virtual ~TPDUException();
};

}
}
}

#endif
