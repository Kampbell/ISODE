/*
 * OA.cpp
 *
 *  Created on: 22 nov. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/OA.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
int			OA::encode() {
	return 0;
}
ReturnCode	OA::decode(NetworkBuffer& tsdu) {
	return OK;
}

} /* namespace SPDU */
} /* namespace SSAP */
} /* namespace ALS */
