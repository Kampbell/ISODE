/*
 * RF.h
 *
 *  Created on: 9 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_RF_H_
#define ALS_SSAP_SPDU_RF_H_
#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/Reference.h"
using ALS::SSAP::Reference;

namespace ALS {
namespace SSAP {
namespace SPDU {

class RF : public SPDU {
	// REFUSE SPDU
private:
	static const int SMASK_RF_REF = 0x0001;
	static const int SMASK_RF_DISC = 0x0002;
	static const int SMASK_RF_REQ = 0x0004;
	static const int SMASK_RF_VRSN = 0x0008;
	static const int RF_DISC_RELEASE = 0x01; // release transport connection
	static const int RF_DISC_MASK = RF_DISC_RELEASE;
	static const int RF_SIZE = 513;
	static const int RF_BASE_SIZE = 13;

	//
	Reference    	rf_reference;
	byte	   		rf_disconnect;
	byte	   		rf_require;
	byte	   		rf_version;
	byte*	 		rf_data;
	int				rf_cc;

public:
	RF() : SPDU (CAT1, SPDU_RF) {
	}
	RF(NetworkBuffer& tsdu) : SPDU(CAT1, SPDU_RF, tsdu)  {
	}
	virtual ~RF() {
	}
	void addDisconnect(byte disconnect) {
		addMask(SMASK_RF_DISC);
		this->rf_disconnect |= disconnect;
	}
	void setDisconnect(byte disconnect) {
		addMask(SMASK_RF_DISC);
		this->rf_disconnect = disconnect;
	}
	void setReference(const Reference& reference) {
		addMask(SMASK_RF_REF);
		this->rf_reference = reference;
	}
	void setRequire(byte require) {
		addMask(SMASK_RF_REQ);
		this->rf_require = require;
	}
	void setVersion(byte version) {
		addMask(SMASK_RF_VRSN);
		this->rf_version = version;
	}
	void setData(int cc, byte* data) {
		this->rf_cc = cc;
		this->rf_data = data;
	}
	byte* getData() {
		return rf_data;
	}
	byte getDisconnect() {
		return rf_disconnect;
	}
	int getLen() {
		return rf_cc;
	}
	const Reference& getReference() {
		return rf_reference;
	}
	byte getRequire() {
		return rf_require;
	}
	byte getVersion() {
		return rf_version;
	}
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);
};

}
}
}

#endif
