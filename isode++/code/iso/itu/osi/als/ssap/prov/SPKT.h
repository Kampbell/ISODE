/*
 * SPKT.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_PROV_SPKT_H_
#define ALS_SSAP_PROV_SPKT_H_
#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
	namespace SPDU {
		enum Category;
	}
	using SPDU::Category;

namespace PROV {

class SPKT {
public:
	static const int		TX_SIZE			= 16;	// EXPEDITED DATA only

	static const int		SMASK_ENCLOSE	= 0x2000;
	static const int		ENCL_BEGIN		= 0x01;		//  beginning of SSDU
	static const int		ENCL_END		= 0x02;		//  end of SSDU
	static const int		ENCL_MASK		= (ENCL_BEGIN | ENCL_END);
	static const int		ENCLOSE_MAX		= 65400;	//  maximum size of enclosure per segment
	// less slop; slop varies based on SPDU, but we'll always assume the worst case 
	static const int		SEGMENT_MAX		= 65528;	//  for things other than S-DATA and
	// S-TYPED-DATA under version 2 we allow only ONE enclosure
	static const int		SMASK_UDATA_PGI = 0x4000;
	static const int		SMASK_SPDU_EXPD = 0x8000;	//  SPDU arrived on the expedited connection  /
	static const int		AB_TIM			= 30;		// drain for 30 seconds on ABORTs
	static const int		RF_TIM			= 30;		// drain for 30 seconds on REFUSEs

	static const int		SC_REFUSE = 0x800;			// larger than any sc_reason

	static const int		CR_OPT_NULL = 0x00;
	static const int		CR_OPT_EXTD = 0x01;			// will receive extended concatenated SPDUs, 
														//this implementation DOESN'T segmenting is enough...
	static const int		CR_OPT_MASK = CR_OPT_EXTD;

private:
	//
	int						s_errno;
	SPDU::SPDU*				s_spdu;
	NetworkBuffer*			s_qbuf;		//  user info  
	int						s_qlen;
	const Provider*			s_ssap;


public:
	SPKT() {}
	SPKT(const Provider* ssap, Category category, NetworkBuffer& tsdu);
	virtual ~SPKT();

	int			error() const					{ return s_errno; }
	SPDU::SPDU*	spdu() const					{ return s_spdu; }
	
	boolean		hasMask(int mask) const			{ return s_spdu->hasMask(mask); }
	void		setMask(int mask)				{ s_spdu->setMask(mask); }
	void		addMask(int mask)				{ s_spdu->addMask(mask); }
	void		remMask(int mask)				{ s_spdu->remMask(mask); }
	
	boolean		hasEnclose(int enclose) const	{ return s_spdu->hasEnclose(enclose); }
	void		setEnclose(int enclose)			{ s_spdu->setEnclose(enclose); }
	void		addEnclose(int enclose)			{ s_spdu->addEnclose(enclose); }
	void		remEnclose(int enclose)			{ s_spdu->remEnclose(enclose); }

};

}
}
}

#endif
