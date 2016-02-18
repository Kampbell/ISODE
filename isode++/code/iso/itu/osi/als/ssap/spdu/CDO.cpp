/*
 * CDO.cpp
 *
 *  Created on: 22 nov. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/CDO.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
int			CDO::encode() {
	return 0;
}
ReturnCode	CDO::decode(NetworkBuffer& tsdu) {
	return OK;
}

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */
