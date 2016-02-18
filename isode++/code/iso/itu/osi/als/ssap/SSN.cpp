/*
 * SSN.cpp
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#include "SSN.h"

namespace ALS {
namespace SSAP {
	string SSN::to_string() const {
		string string;
		if (serial == SERIAL_NONE) {
			string = "NONE";
		}
		else {
			char ssnc[SIZE_CN_ISN + 1];
			sprintf(ssnc, "%0*d", SIZE_CN_ISN, serial);
			string = ssnc;// format.format(ssn);
		}
		return string;
	}
}
}
