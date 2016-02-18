/*
 * SPKT.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#include "SPKT.h"

namespace ALS {
namespace SSAP {
namespace PROV {
	SPKT::SPKT(const Provider* ssap, Category category, Buffer& tsdu) : s_ssap(ssap) {
		s_errno = 0;
		s_spdu = NULL;
		s_qbuf = NULL;
		s_qlen = 0;

		s_spdu = SPDU::SPDU::decode(category, tsdu);
	}
	SPKT::~SPKT() {
	}
}
}
}
