/*
 * AR.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AR_H_
#define ALS_SSAP_SPDU_AR_H_
#include "als/ssap/ActivityId.h"
using ALS::SSAP::ActivityId;
#include "als/ssap/Reference.h"
using ALS::SSAP::Reference;

#include "als/ssap/spdu/SPDU.h"


namespace ALS {
namespace SSAP {
namespace SPDU {

class AR : public SPDU {
	// ACTIVITY RESUME SPDU 
private:
	static const int	AR_SIZE = 512;
	static const int	AR_BASE_SIZE = 29;

public:
	static const int	SMASK_AR_REF = 0x0001;
	static const int	SMASK_AR_OID = 0x0002;
	static const int	SMASK_AR_SSN = 0x0004;
	static const int	SMASK_AR_ID  = 0x0008;

private:	//
	ActivityId		ar_id;
	Reference		ar_reference;
	ActivityId		ar_oid;
	int				ar_serial;

public:
	AR() : SPDU(CAT2, SPDU_AR) {
	}

	AR(NetworkBuffer& tsdu) : SPDU(CAT2, SPDU_AR, tsdu)  {
	}
	virtual ~AR() {
	}
	const ActivityId& getActivityId() const {
		return ar_id;
	}
	const ActivityId& getOldActivityId() const {
		return ar_oid;
	}
	const Reference& getReference() const {
		return ar_reference;
	}
	int getSerial() const {
		return ar_serial;
	}
	void setReference(const Reference& reference) {
		ar_reference = reference;
		addMask(SMASK_AR_REF);
	}
	void setSerial(int serial) {
		ar_serial = serial;
		addMask(SMASK_AR_SSN);
	}
	void setActivityId(const ActivityId& aid) {
		ar_id = aid;
		addMask(SMASK_AR_ID);
	}
	void setOldActivityId(const ActivityId& oaid) {
		ar_oid = oaid;
		addMask(SMASK_AR_OID);
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);

};

}
}
}

#endif
