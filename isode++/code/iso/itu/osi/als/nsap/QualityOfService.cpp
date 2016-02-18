/*
 * QualityOfService.cpp
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#include "als/nsap/QualityOfService.h"

namespace ALS {
namespace NSAP {

	QualityOfService::QualityOfService() {
		qos_session_version = 0;
		qos_extended = false;
		qos_maxtime = 0;
	}
	QualityOfService::QualityOfService(const Quality& reliability, int version, boolean extended, int maxtime) {
		qos_reliability = reliability;
		qos_session_version = version;
		qos_extended = extended;
		qos_maxtime = maxtime;
	}

	QualityOfService::~QualityOfService() {
	}

}
}
