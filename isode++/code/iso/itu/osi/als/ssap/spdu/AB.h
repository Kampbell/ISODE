/*
 * AB.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_AB_H_
#define ALS_SSAP_SPDU_AB_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {

class AB : public SPDU {
	// ABORT SPDU
public:
	static const int	SMASK_AB_DISC	= 0x0001;
	static const int	AB_DISC_RELEASE	= 0x01;	// release transport connection
	static const int	AB_DISC_USER	= 0x02;	// user abort
	static const int	AB_DISC_PROTO	= 0x04;	// protocol error
	static const int	AB_DISC_UNKNOWN	= 0x08;	// no reason
	static const int	AB_DISC_MASK	= (AB_DISC_RELEASE | AB_DISC_USER | AB_DISC_PROTO | AB_DISC_UNKNOWN);

	static const int	SMASK_AB_REFL	= 0x0002;
	static const int	AB_REFL_SIZE	= 9;
	static const int	AB_SIZE			= 9;
	static const int	AB_BASE_SIZE	= 17;

private:
	byte			ab_disconnect;
	byte			ab_reflect[AB_REFL_SIZE];

public:
	AB();
	AB(NetworkBuffer& tsdu);
	virtual ~AB();
	void addDisconnect(byte disconnect);
	void setDisconnect(byte disconnect);
	void setReflect(int cc, byte* reflect);
	byte getDisconnect();
	byte*getReflect();

	NetworkBuffer* AB::toTSDU(int fake);
	int encode();
	ReturnCode	decode(NetworkBuffer& buffer);
};

}
}
}

#endif
