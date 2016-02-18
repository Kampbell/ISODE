/*
 * Category.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CATEGORY_H_
#define ALS_SSAP_SPDU_CATEGORY_H_

namespace ALS {
namespace SSAP {
namespace SPDU {
enum Category {
	ALL				= 0,
	CAT0			= 1,
	CAT1			= 2,
	CAT2			= 3,
	CAT0_OR_CAT1	= 4
};
}
}
}
#endif
