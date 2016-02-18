/*
 * QualityOfService.h
 *
 *  Created on: 30 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef QualityOfService_H_
#define QualityOfService_H_

#include "als/nsap/nsap.h"

namespace ALS {
namespace NSAP {

class NSAP_API QualityOfService {
public:
	enum Quality {
		HIGH_QUALITY,
		LOW_QUALITY
	};
	// transport QualityOfService
	Quality					qos_reliability;		// "reliability" element
	// session QualityOfService 
	nat1					qos_session_version;	// session version required
	bool					qos_extended;			// extended control
	int						qos_maxtime;			// for SPM response during S-CONNECT

public:
	QualityOfService();
	QualityOfService(const Quality& reliability, int version, boolean extended, int maxtime);
	virtual ~QualityOfService();

	nat1&		version()			{ return qos_session_version; }
	bool&		extended()			{ return qos_extended; }
	int&		maxtime()			{ return qos_maxtime; }
	nat1		version()	const	{ return qos_session_version; }
	bool		extended()	const	{ return qos_extended; }
	int			maxtime()	const	{ return qos_maxtime; }
};
class NSAP_API QualityOfServiceParameters {
public:
	QualityOfServiceParameters() {}
	virtual ~QualityOfServiceParameters() {}
};

}
}

#endif
