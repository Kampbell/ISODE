/*
 * SPDU.h
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_SPDU_H_
#define ALS_SSAP_SPDU_SPDU_H_

#include <string>
using std::string;

#include "als/base/util/NetworkBuffer.h"
#include "als/ssap/spdu/Category.h"
#include "als/ssap/spdu/HEADER.h"

using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
	namespace SSAP {
		namespace PROV {
			class Provider;
		}
		namespace SPDU {
			class HEADER;
			class PGI;
			class PI;
		}
	}
}
using ALS::SSAP::PROV::Provider;
namespace ALS {
	namespace SSAP {
		namespace SPDU {
class SPDU : public HEADER {
	friend Provider;

protected:
	static const byte 	SPDU_CN		= 0x0d;		// CONNECT
	static const byte 	SPDU_CDO	= 0x0f;		// CONNECT DATA OVERFLOW
	static const byte 	SPDU_AC		= 0x0e;		// ACCEPT
	static const byte 	SPDU_OA		= 0x10;		// OVERFLOW ACCEPT
	static const byte 	SPDU_RF		= 0x0c;		// REFUSE
	static const byte 	SPDU_FN		= 0x09;		// FINISH
	static const byte 	SPDU_DN		= 0x0a;		// DISCONNECT
	static const byte 	SPDU_NF		= 0x08;		// NOT FINISHED
	static const byte 	SPDU_AB		= 0x19;		// ABORT
	static const byte 	SPDU_AA		= 0x1a;		// ABORT ACCEPT
	static const byte 	SPDU_DT		= 0x01;		// DATA TRANSFER
	static const byte 	SPDU_EX		= 0x05;		// EXPEDITED
	static const byte 	SPDU_TD		= 0x21;		// TYPED DATA
	static const byte 	SPDU_CD		= 0x3d;		// CAPABILITY DATA
	static const byte 	SPDU_CDA	= 0x3e;		// CAPABILITY DATA ACK
	static const byte 	SPDU_GT		= SPDU_DT;	// GIVE TOKENS
	static const byte 	SPDU_PT		= 0x02;		// PLEASE TOKENS
	static const byte 	SPDU_GTC	= 0x15;		// GIVE TOKENS CONFIRM
	static const byte 	SPDU_GTA	= 0x16;		// GIVE TOKENS ACK
	static const byte 	SPDU_MIP	= 0x31;		// MINOR SYNCHRONIZATION POINT
	static const byte 	SPDU_MIA	= 0x32;		// MINOR SYNC ACK
	static const byte 	SPDU_MAP	= 0x29;		// MAJOR SYNCHRONIZATION POINT
	static const byte 	SPDU_MAA	= 0x2a;		// MAJOR SYNC ACK
	static const byte 	SPDU_RS		= 0x35;		// RESYNCHRONIZE
	static const byte 	SPDU_RA		= 0x22;		// RESYNCHRONIZE ACK
	static const byte 	SPDU_PR		= 0x07;		// PREPARE
	static const byte 	SPDU_ER		= 0x00;		// EXCEPTION REPORT
	static const byte 	SPDU_ED		= 0x30;		// EXCEPTION DATA
	static const byte 	SPDU_AS		= 0x2d;		// ACTIVITY START
	static const byte 	SPDU_AR		= 0x1d;		// ACTIVITY RESUME
	static const byte 	SPDU_AI		= SPDU_AB;	// ACTIVITY INTERRUPT
	static const byte 	SPDU_AIA	= SPDU_AA;	// ACTIVITY INTERRUPT ACK
	static const byte 	SPDU_AD		= 0x39;		// ACTIVITY DISCARD
	static const byte 	SPDU_ADA	= 0x3a;		// ACTIVITY DISCARD ACK
	static const byte 	SPDU_AE		= SPDU_MAP;	// ACTIVITY END
	static const byte 	SPDU_AEA	= SPDU_MAA;	// ACTIVITY END ACK

// CONNECT/ACCEPT SPDU
	static const byte	CR_OPT_NULL			= 0x00;
	static const byte	CR_OPT_EXTD			= 0x01;
	// will receive extended concatenated SPDUs, this implementation DOESN'T; segmenting is  enough...
	static const byte	CR_OPT_MASK			= CR_OPT_EXTD;

public:
	static const int	SMASK_CN_REF		= 0x0001;
	static const int	SMASK_CN_OPT		= 0x0002;
	static const int	SMASK_CN_TSDU		= 0x0004;
	static const int	SMASK_CN_VRSN		= 0x0008;

	static const int	SIZE_CN_ISN			= 6;

	static const int	SMASK_CN_ISN		= 0x0010;
	static const int	SMASK_CN_SET		= 0x0020;
	static const int	SMASK_AC_TOKEN		= 0x0040;
	static const int	SMASK_CN_REQ		= 0x0080;
	static const int	SMASK_CN_CALLING	= 0x0100;
	static const int	SMASK_CN_CALLED		= 0x0200;
protected:
	static const int	CN_SIZE = 512;
// 	static const int	CONNECT_MAX	10240	// someday support CDO/OA SPDUs and Data Overflow PI...
	static const int CN_BASE_SIZE			= 56;
	static const int	AC_SIZE				= 512;
	static const int AC_BASE_SIZE			= 62;
	static const int	SMASK_RF_REF		= 0x0001;
	static const int	SMASK_RF_DISC		= 0x0002;
	static const int	RF_DISC_RELEASE		= 0x01;	// release transport connection
	static const int	RF_DISC_MASK		= RF_DISC_RELEASE;

	static const int	SMASK_RF_REQ		= 0x0004;
	static const int	SMASK_RF_VRSN		= 0x0008;
public:
	static const int	RF_SIZE				= 513;
	static const int RF_BASE_SIZE			= 13;

	static const int	SMASK_FN_DISC		= 0x0001;
	static const int	FN_DISC_RELEASE		= 0x01;	// release transport connection
	static const int	FN_DISC_MASK		= FN_DISC_RELEASE;
	static const int	FN_SIZE				= 512;
	static const int FN_BASE_SIZE			= 6;

	// DISCONNECT SPDU
	static const int	DN_SIZE				= 512;
	static const int DN_BASE_SIZE			= 3;

	// NOT FINISHED SPDU
	static const int	NF_SIZE				= 512;
	static const int NF_BASE_SIZE			= 3;

	// ABORT SPDU
	static const int	SMASK_AB_DISC		= 0x0001;
	static const int	AB_DISC_RELEASE		= 0x01;	// release transport connection
	static const int	AB_DISC_USER		= 0x02;	// user abort
	static const int	AB_DISC_PROTO		= 0x04;	// protocol error
	static const int	AB_DISC_UNKNOWN		= 0x08;	// no reason
	static const int	AB_DISC_MASK		= (AB_DISC_RELEASE | AB_DISC_USER | AB_DISC_PROTO | AB_DISC_UNKNOWN);

	static const int	SMASK_AB_REFL		= 0x0002;
	static const int	AB_REFL_SIZE		= 9;
	static const int	AB_SIZE				= 9;
	static const int AB_BASE_SIZE			= 17;

	// ABORT ACCEPT SPDU
	static const int	AA_SIZE				= 0;
	static const int AA_BASE_SIZE			= 0;


	// DATA TRANSFER SPDU
	static const int	DT_SIZE				= 65535;
	static const int	DT_MINSIZE			= 64;	// don't segment if MSS < this
	static const int DT_BASE_SIZE			= 3;

	// EXPEDITED DATA SPDU
	static const int	EX_SIZE				= SX_EXSIZE;
	static const int EX_BASE_SIZE			= 0;

	// TYPED DATA SPDU
	static const int	TD_SIGHS			= 65535;	// should be TD_SIZE
	static const int	TD_MINSIZE			= 64;	// don't segment if MSS < this
	static const int TD_BASE_SIZE			= 3;

	// CAPABILITY DATA SPDU
	static const int	CD_SIZE				= SX_CDSIZE;
	static const int CD_BASE_SIZE			= 3;

	// CAPABILITY DATA ACK SPDU
	static const int	CDA_SIZE			= SX_CDASIZE;
	static const int CDA_BASE_SIZE			= 3;

	// GIVE TOKENS SPDU
	static const int	SMASK_GT_TOKEN		= 0x0001;
	static const int	GT_SIZE				= 0;
	static const int GT_BASE_SIZE			= 3;

	// PLEASE TOKENS SPDU
	static const int	SMASK_PT_TOKEN		= 0x0001;
	static const int	PT_SIZE				= 512;
	static const int PT_BASE_SIZE			= 6;

	// GIVE TOKENS CONFIRM SPDU
	static const int	GTC_SIZE			= 0;
	static const int GTC_BASE_SIZE			= 0;

	// GIVE TOKENS ACK SPDU
	static const int	GTA_SIZE			= 0;
	static const int GTA_BASE_SIZE			= 0;

	// MINOR SYNC POINT SPDU
	static const int	SMASK_MIP_SYNC		= 0x0001;
	static const int	MIP_SYNC_NOEXPL		= 0x01;	// NO EXPLICIT ACK REQUIRED
	static const int	MIP_SYNC_MASK		= MIP_SYNC_NOEXPL;

	static const int	SMASK_MIP_SERIAL 	= 0x0002;
	static const int	MIP_SIZE			= 512;
	static const int MIP_BASE_SIZE			= 14;

	// MINOR SYNC ACK SPDU
	static const int	SMASK_MIA_SERIAL 	= 0x0001;
	static const int	MIA_SIZE			= 512;
	static const int MIA_BASE_SIZE			= 11;

	// MAJOR SYNC POINT SPDU
	static const int	SMASK_MAP_SYNC		= 0x0001;
	static const int	MAP_SYNC_NOEND		= 0x01;	// ACTIVITY NOT ENDED (i.e., MAP not AE)
	static const int	MAP_SYNC_MASK		= MAP_SYNC_NOEND;

	static const int	SMASK_MAP_SERIAL 	= 0x0002;
	static const int	MAP_SIZE			= 512;
	static const int MAP_BASE_SIZE			= 14;

	// MAJOR SYNC ACK SPDU
	static const int	SMASK_MAA_SERIAL 	= 0x0001;
	static const int	MAA_SIZE			= 512;
	static const int MAA_BASE_SIZE			= 11;

	// RESYNCHRONIZE SPDU
	static const int	SMASK_RS_SET		= 0x0001;
	static const int	SMASK_RS_TYPE		= 0x0002;
	static const int	SMASK_RS_SSN		= 0x0004;
	static const int	SMASK_RS_SECOND_TYPE= 0x0008;
	static const int	SMASK_RS_SECOND_SSN = 0x0010;
// 	static const int	SYNC_OK(r)	(((unsigned) (r)) <= SYNC_SET);
	static const int	RS_SIZE				= 512;
	static const int RS_BASE_SIZE			= 17;

	// RESYNCHRONIZE ACK SPDU
	static const int	SMASK_RA_SET		= 0x0001;
	static const int	SMASK_RA_TYPE		= 0x0002;
	static const int	SMASK_RA_SSN		= 0x0004;
	static const int	SMASK_RA_SECOND_TYPE= 0x0008;
	static const int	SMASK_RA_SECOND_SSN = 0x0010;
	static const int	RA_SIZE				= 512;
	static const int RA_BASE_SIZE			= 14;

	// PREPARE SPDU
	static const int	SMASK_PR_TYPE		= 0x0001;
	static const int	PR_MAA				= 1;	// expect SPDU_MAA
	static const int	PR_RS				= 2;	// expect SPDU_RS
	static const int	PR_RA				= 3;	// expect SPDU_RA
	static const int	PR_AB				= 4;	// expect SPDU_AB
	static const int	PR_MAX				= PR_AB;

	static const int	PR_SIZE				= 0;
	static const int PR_BASE_SIZE			= 3;

	// EXCEPTION REPORT SPDU
	static const int	ER_SIZE				= 0;
	static const int ER_BASE_SIZE			= 0;

	// EXCEPTION DATA SPDU
	static const int	SMASK_ED_REASON		= 0x0001;
/*
	static const int	SP_OK(r)	(((r) < SP_PROCEDURAL \;
		&& (r) != SP_RSVD1 \;
		&& (r) != SP_RSVD2) \;
	    || (r) == SP_DEMAND);
}    un_ed;;
*/
	static const int	ED_SIZE				= 512;
	static const int ED_BASE_SIZE			= 6;

	// ACTIVITY START SPDU
	static const int	SMASK_AS_ID			= 0x0001;
	static const int	AS_SIZE				= 512;
	static const int AS_BASE_SIZE			= 11;

	// ACTIVITY RESUME SPDU
	static const int	SMASK_AR_REF		= 0x0001;
	static const int	SMASK_AR_OID		= 0x0002;
	static const int	SMASK_AR_SSN		= 0x0004;
	static const int	SMASK_AR_ID			= 0x0008;
	static const int	AR_SIZE				= 512;
	static const int AR_BASE_SIZE			= 29;

	// ACTIVITY INTERRUPT (ABORT) SPDU
	static const int	SMASK_AI_REASON		= 0x0001;	// don't collide with SMASK_AB_DISC
	static const int	AI_SIZE				= 0;
	static const int AI_BASE_SIZE			= 3;

	// ACTIVITY INTERRUPT (ABORT) ACK SPDU
	static const int	AIA_SIZE			= 0;
	static const int AIA_BASE_SIZE			= 0;

	// ACTIVITY DISCARD SPDU
	static const int	SMASK_AD_REASON		= 0x0001;
	static const int	AD_SIZE				= 0;
	static const int AD_BASE_SIZE			= 3;

	// ACTIVITY DISCARD ACK SPDU
	static const int	ADA_SIZE			= 0;
	static const int ADA_BASE_SIZE			= 0;

	// ACTIVITY END (MAJOR SYNC) SPDU
	static const int	AE_SIZE				= 512;
	static const int AE_BASE_SIZE			= 8;

	// ACTIVITY END (MAJOR SYNC) ACK SPDU
	static const int	AEA_SIZE			= MAA_SIZE;
	static const int AEA_BASE_SIZE			= MAA_BASE_SIZE;

public:
	static const int 	SPDU_MAXLEN			= 65535; /* segment if SSDU larger */

	/* A nice magic number:
	for the GT SPDU, 2 octets
	for the DT SPDU, 2 octets + 3 octets for the enclosure option
	2 + 2 + 3 = 7
	*/
	static const int 	SSDU_MAGIC 		= 7;

	static const int 	SMASK_ENCLOSE	= 0x2000;
	static const int 	ENCL_BEGIN		= 0x01;	// beginning of SSDU
	static const int 	ENCL_END		= 0x02;	// ending    of SSDU
	static const int 	ENCL_MASK		= (ENCL_BEGIN | ENCL_END);

	static const int 	ENCLOSE_MAX		= 65400;
	// maximum size of enclosure per segment less slop; slop varies based on SPDU, but
	// we'll always assume the worst case

	static const int 	SEGMENT_MAX		= 65528;
	// for things other than S-DATA and S-TYPED-DATA under version 2 we allow only
	// ONE enclosure

	static const int 	SMASK_UDATA_PGI = 0x4000;
	static const int 	SMASK_SPDU_EXPD = 0x8000;	// SPDU arrived on the expedited connection
protected:
	static const int	SMASK_SPDU_AA	= 0x0001;	// to distinguish between AA and AIA SPDUs
	static const int	SMASK_SPDU_GT	= 0x0002;	// to distinguish between DT and GT SPDUs
	static const int	SMASK_SPDU_AB	= 0x0004;	// to distinguish between AB and AI SPDUs

//
private:
	int				spdu_total;
	list<HEADER*>	spdu_sons;
protected:
	Category		spdu_category;
	byte			spdu_enclose;
	const void*		spdu_udata;
	int				spdu_ulen;
	NetworkBuffer*	spdu_data = nullptr;
private:
	int				spdu_mask;
	void			reset();
public:
	virtual ~SPDU();
protected:
	SPDU(Category category, byte si);
	SPDU(Category category, int si, NetworkBuffer& tsdu);

	Category category() const				{ return spdu_category; }
	void	sli(int cc)						{ HEADER::hli(cc); }
	int		sli() const						{ return HEADER::hli(); }

public:
	bool	hasMask(int mask) const			{ return (spdu_mask & mask) != 0; }
	void	setMask(int mask)				{ spdu_mask = mask; }
	void	addMask(int mask)				{ spdu_mask |= mask; }
	void	remMask(int mask)				{ spdu_mask &= ~mask;	}
	
	bool	hasEnclose(byte enclose)	const	{ return (spdu_enclose & enclose) == enclose ? true : false;	}
	void	setEnclose(byte enclose)			{ spdu_enclose = (byte)enclose; }
	void	addEnclose(byte enclose)			{ spdu_enclose |= enclose;	}
	void	remEnclose(byte enclose)			{ spdu_enclose &= ~enclose; }
	
	void	setData(int length, const void* data);
	int		getDataLen() const				{ return spdu_ulen;}
	const void* getData(int& length) const	{ length = spdu_ulen; return spdu_udata; }
	const void* popData(int& length)		{ const void*  bytes = spdu_udata;	length = spdu_ulen; spdu_udata = nullptr;	spdu_ulen = 0; return bytes; }

	ReturnCode			flush(unique_ptr<NetworkBuffer>& tsdu, int cc = 0, const void* data = nullptr) const;
protected:
	static SPDU*		fromTSDU(Category category, NetworkBuffer& tsdu);
	static SPDU*		decode(Category category, NetworkBuffer& tsdu);
	virtual ReturnCode	decode(NetworkBuffer& tsdu) = 0;
	virtual int			encode() = 0;
//	virtual ReturnCode	encode(unique_ptr<NetworkBuffer>& tsdu) const = 0;

	void				append(HEADER* piorpgi);
	void				addSon(HEADER* header) { append(header); }
	ReturnCode			control(NetworkBuffer& tsdu);
	string				getLiteral() const;
#ifdef FIXME
	TSDU toTSDU(SPKT spkt, int fake) {
		TSDU tsdu = nullptr;
		return tsdu;
	}

	list<NetworkBuffer*> toTSDU() {
		NetworkBuffer buffer = HEADER::toTSDU(0);
		list<NetworkBuffer*> list;
		buffer.flip();
		list.addFirst(buffer);
		Iterator<SPCI> i = sons.iterator();
		while (i.hasNext()) {
			list.addAll((i.next().toTSDU()));
		}
		return list;
	}
	public int write(TPDUOutputStream pos) throws IOException{
		int length = super.write(pos);
		Iterator<SPCI> i = sons.iterator();
		while (i.hasNext()) {
			length += i.next().write(pos);
		}
		return length;
	}
#endif
};

}
}
}

#endif
