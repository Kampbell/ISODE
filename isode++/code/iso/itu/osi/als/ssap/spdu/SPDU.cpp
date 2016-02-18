/*
 * SPDU.cpp
 *
 *  Created on: 8 oct. 2014
 *      Author: FrancisANDRE
 */

#include <cassert>
#include <string>

#include "als/base/addr/Selector.h"
#include "als/ssap/ActivityId.h"
#include "als/ssap/Reference.h"
#include "als/ssap/Exception.h"
#include "als/ssap/AbortCode.h"
using ALS::BASE::ADDR::Selector;
using ALS::SSAP::ActivityId;
using ALS::SSAP::Reference;
using ALS::SSAP::Exception;
using ALS::SSAP::AbortCode;

#include "als/ssap/spdu/SPDU.h"
#include "als/ssap/spdu/pi/PI.h"

#include "als/ssap/spdu/AA.h"
#include "als/ssap/spdu/AA.h"
#include "als/ssap/spdu/AB.h"
#include "als/ssap/spdu/AB.h"
#include "als/ssap/spdu/AC.h"
#include "als/ssap/spdu/AD.h"
#include "als/ssap/spdu/ADA.h"
#include "als/ssap/spdu/AI.h"
#include "als/ssap/spdu/AIA.h"
#include "als/ssap/spdu/AR.h"
#include "als/ssap/spdu/AS.h"
#include "als/ssap/spdu/CD.h"
#include "als/ssap/spdu/CDA.h"
#include "als/ssap/spdu/CN.h"
#include "als/ssap/spdu/DN.h"
#include "als/ssap/spdu/DT.h"
#include "als/ssap/spdu/ED.h"
#include "als/ssap/spdu/ER.h"
#include "als/ssap/spdu/EX.h"
#include "als/ssap/spdu/FN.h"
#include "als/ssap/spdu/GT.h"
#include "als/ssap/spdu/GT.h"
#include "als/ssap/spdu/GTA.h"
#include "als/ssap/spdu/GTC.h"
#include "als/ssap/spdu/MAA.h"
#include "als/ssap/spdu/MAA.h"
#include "als/ssap/spdu/MAP.h"
#include "als/ssap/spdu/MAP.h"
#include "als/ssap/spdu/MIA.h"
#include "als/ssap/spdu/MIP.h"
#include "als/ssap/spdu/NF.h"
#include "als/ssap/spdu/PR.h"
#include "als/ssap/spdu/PT.h"
#include "als/ssap/spdu/RA.h"
#include "als/ssap/spdu/RF.h"
#include "als/ssap/spdu/RS.h"
#include "als/ssap/spdu/TD.h"
using namespace std;

namespace ALS {
namespace SSAP {
namespace SPDU {
static const int PMASK_NODATA			= 0x000000;
static const int	PMASK_CN_ID			= 0x000001;	//   1: Connection ID 
static const int	PMASK_CN_ITEMS		= 0x000002;	//   5: Connect/Accept Item 
static const int	PMASK_SYNC			= 0x000004;	//  15: Sync Type Item 
static const int	PMASK_TOKEN			= 0x000008;	//  16: Token Item 
static const int	PMASK_TDISC			= 0x000010;	//  17: Transport Disc 
static const int	PMASK_USER_REQ		= 0x000020;	//  20: Session User Req 
static const int	PMASK_VERSION		= 0x000040;	//  22: Version Number 
static const int	PMASK_PREPARE		= 0x000080;	//  24: Prepare type 
static const int	PMASK_ENCLOSE		= 0x000100;	//  25: Enclosure Item 
static const int PMASK_TOKEN_SET		= 0x000200;	//  26: Token Setting Item 
static const int	PMASK_RESYNC		= 0x000400;	//  27: Resync type 
static const int	PMASK_LINK			= 0x000800;	//  33: Linking information 
static const int	PMASK_ACT_ID		= 0x001000;	//  41: Activity ID 
static const int	PMASK_SERIAL		= 0x002000; //  42: Serial Number 
static const int	PMASK_MIA_DATA		= 0x004000;	//  46: MIA User Data 
static const int	PMASK_REFLECT		= 0x008000;	//  49: Reflect parameter 
static const int	PMASK_REASON		= 0x010000;	//  50: Refusal Reason 
static const int	PMASK_SSAP_CALLING	= 0x020000;	//  51: Calling SSAP ID 
static const int	PMASK_SSAP_CALLED	= 0x040000;	//  52: Called SSAP ID 
static const int	PMASK_UDATA			= 0x080000;	// 193: User data 
static const int	PMASK_XDATA			= 0x100000;	// 194: Extended user data 

static const int PMASK_PGI				= 0x400000;	// PGI has nested PIs 
static const int PMASK_VARLEN			= 0x800000;	// PI is Variable Len 
static const int PMASK_NOTSUPPORTED		= -1;		// Type not supported 

static const int pi_table[] = {
	0,											// 0x00 
	PMASK_VARLEN | PMASK_CN_ID | PMASK_PGI,		// 0x01: Connection ID 
	0, 0, 0,									// 0x02-04 
	PMASK_VARLEN | PMASK_CN_ITEMS | PMASK_PGI,
	// 0x05: Connect/Accept Item 
	0, 0, 0,									// 0x06-08 
	PMASK_VARLEN | PMASK_CN_ID | PMASK_LINK,	// 0x09: Called Session SS 
	PMASK_VARLEN | PMASK_CN_ID | PMASK_LINK,	// 0x0a: Calling Session SS 
	PMASK_VARLEN | PMASK_CN_ID | PMASK_LINK,	// 0x0b: Common Reference 
	PMASK_VARLEN | PMASK_CN_ID | PMASK_LINK,	// 0x0c: Additional Info 
	0, 0,										// 0x0d-0e 
	PMASK_SYNC,									// 0x0f: Sync Type Item 
	PMASK_TOKEN,								// 0x10: Token Item 
	PMASK_TDISC,								// 0x11: Transport Disc 
	0,											// 0x12 
	PMASK_CN_ITEMS,								// 0x13: Protocol Option 
	PMASK_USER_REQ,								// 0x14: Session User Req 
	PMASK_VARLEN | PMASK_CN_ITEMS,				// 0x15: TSDU Max Size 
	PMASK_VERSION,								// 0x16: Version Number 
	PMASK_VARLEN | PMASK_CN_ITEMS,				// 0x17: Initial Serial Num 
	PMASK_PREPARE,								// 0x18: Prepare Type 
	PMASK_ENCLOSE,								// 0x19: Enclosure Item 
	PMASK_CN_ITEMS | PMASK_TOKEN_SET,			// 0x1a: Token setting item 
	PMASK_RESYNC,								// 0x1b: Resync type 
	0, 0, 0, 0, 0,								// 0x1c-20 
	PMASK_VARLEN | PMASK_LINK | PMASK_PGI,		// 0x21: Activity Link 
	0, 0, 0, 0, 0, 0, 0,						// 0x22-28 
	PMASK_VARLEN | PMASK_ACT_ID,				// 0x29: Activity ID 
	PMASK_VARLEN | PMASK_SERIAL,				// 0x2a: Serial Number 
	0, 0, 0,									// 0x2b-2d 
	PMASK_VARLEN | PMASK_MIA_DATA,				// 0x2e: MIA User Data 
	0, 0,										// 0x2f-30 
	PMASK_VARLEN | PMASK_REFLECT,				// 0x31: Reflect parameter 
	PMASK_VARLEN | PMASK_REASON,				// 0x32: Refusal Reason 
	PMASK_VARLEN | PMASK_SSAP_CALLING,			// 0x33: Calling SSAP ID 
	PMASK_VARLEN | PMASK_SSAP_CALLED,			// 0x34: Called SSAP ID 
	0, 0,										// 0x35-36 
	PMASK_VARLEN | PMASK_CN_ITEMS				// 0x17: 2nd initial s/n 
};

static const int pi_length[/*PI_TABLE_LEN*/] = {
	0,											// 0x00 
	Reference::SREF_USER_SIZE					// 0x01: Connection ID 
	+ Reference::SREF_COMM_SIZE
	+ Reference::SREF_ADDT_SIZE
	+ 6,
	0, 0, 0,									// 0x02-04 
	1 + 4 + 1 + 6 + 1 + 10,						// 0x05: Connect/Accept Item 
	0, 0, 0,									// 0x06-08 
	Reference::SREF_USER_SIZE,					// 0x09: Called Session SS 
	Reference::SREF_USER_SIZE,					// 0x0a: Calling Session SS 
	Reference::SREF_COMM_SIZE,					// 0x0b: Common Reference 
	Reference::SREF_ADDT_SIZE,					// 0x0c: Additional Info 
	0, 0,										// 0x0d-0e 
	1,											// 0x0f: Sync Type Item 
	1,											// 0x10: Token Item 
	1,											// 0x11: Transport Disc 
	0,											// 0x12 
	1,											// 0x13: Protocol Option 
	2,											// 0x14: Session User Req 
	4,											// 0x15: TSDU Max Size 
	1,											// 0x16: Version Number 
	CN::SIZE_CN_ISN,							// 0x17: Initial Serial Num 
	1,											// 0x18: Prepare Type 
	1,											// 0x19: Enclosure Item 
	1,											// 0x1a: Token setting item 
	1,											// 0x1b: Resync type 
	0, 0, 0, 0, 0,								// 0x1c-20 
	2 * Reference::SREF_USER_SIZE				// 0x21: Activity Link 
	+ Reference::SREF_COMM_SIZE
	+ Reference::SREF_ADDT_SIZE
	+ ActivityId::SID_DATA_SIZE
	+ CN::SIZE_CN_ISN
	+ 6 * 2,
	0, 0, 0, 0, 0, 0, 0,						// 0x22-28 
	ActivityId::SID_DATA_SIZE,					// 0x29: Activity ID 
	CN::SIZE_CN_ISN,							// 0x2a: Serial Number 
	0, 0, 0,									// 0x2b-2d 
	SPDU::SEGMENT_MAX, // MIA_SIZE 				// 0x2e: MIA User Data 
	0, 0,										// 0x2f-30 
	SPDU::SEGMENT_MAX,							// 0x31: Reflect parameter 
	SPDU::RF_SIZE,								// 0x32: Refusal Reason 
	Selector::SIZE,								// 0x33: Calling SSAP ID 
	Selector::SIZE,								// 0x34: Called SSAP ID 
	0, 0,										// 0x35-36 
	CN::SIZE_CN_ISN,							// 0x37: 2nd initial s/n 
};

static const int si_table[] = {
		PMASK_REFLECT,				/* 0x00: SPDU_ER */
		PMASK_ENCLOSE				/* 0x01: SPDU_GT & SPDU_DT */
		| PMASK_TOKEN,
		PMASK_TOKEN					/* 0x02: SPDU_PT */
		| PMASK_ENCLOSE
		| PMASK_UDATA,
		PMASK_NOTSUPPORTED,			/* 0x03 */
		PMASK_NOTSUPPORTED,			/* 0x04 */
		PMASK_NODATA,				/* 0x05: SPDU_EX */
		PMASK_NOTSUPPORTED,			/* 0x06 */
		PMASK_PREPARE,				/* 0x07: SPDU_PR */
		PMASK_ENCLOSE				/* 0x08: SPDU_NF */
		| PMASK_UDATA,
		PMASK_TDISC					/* 0x09: SPDU_FN */
		| PMASK_ENCLOSE
		| PMASK_UDATA,
		PMASK_ENCLOSE				/* 0x0a: SPDU_DN */
		| PMASK_UDATA,
		PMASK_NOTSUPPORTED,			/* 0x0b */
		PMASK_CN_ID					/* 0x0c: SPDU_RF */
		| PMASK_TDISC
		| PMASK_USER_REQ
		| PMASK_VERSION
		| PMASK_ENCLOSE
		| PMASK_REASON,
		PMASK_CN_ID					/* 0x0d: SPDU_CN */
		| PMASK_CN_ITEMS
		| PMASK_USER_REQ
		| PMASK_VERSION
		| PMASK_SSAP_CALLING
		| PMASK_SSAP_CALLED
		| PMASK_UDATA
		| PMASK_XDATA,
		PMASK_CN_ID					/* 0x0e: SPDU_AC */
		| PMASK_CN_ITEMS
		| PMASK_USER_REQ
		| PMASK_VERSION
		| PMASK_SSAP_CALLING
		| PMASK_TOKEN
		| PMASK_ENCLOSE
		| PMASK_SSAP_CALLED
		| PMASK_UDATA
		| PMASK_XDATA,
		PMASK_NOTSUPPORTED,			/* 0x0f */
		PMASK_NOTSUPPORTED,			/* 0x10 */
		PMASK_NOTSUPPORTED,			/* 0x11 */
		PMASK_NOTSUPPORTED,			/* 0x12 */
		PMASK_NOTSUPPORTED,			/* 0x13 */
		PMASK_NOTSUPPORTED,			/* 0x14 */
		PMASK_NODATA,				/* 0x15: SPDU_GTC */
		PMASK_NODATA,				/* 0x16: SPDU_GTA */
		PMASK_NOTSUPPORTED,			/* 0x17 */
		PMASK_NOTSUPPORTED,			/* 0x18 */
		PMASK_TDISC					/* 0x19: SPDU_AB & SPDU_AI */
		| PMASK_REFLECT
		| PMASK_REASON
		| PMASK_ENCLOSE
		| PMASK_UDATA,
		PMASK_NODATA,				/* 0x1a: SPDU_AA & SPDU_AIA */
		PMASK_NOTSUPPORTED,			/* 0x1b */
		PMASK_NOTSUPPORTED,			/* 0x1c */
		PMASK_LINK					/* 0x1d: SPDU_AR */
		| PMASK_ACT_ID
		| PMASK_ENCLOSE
		| PMASK_SERIAL
		| PMASK_UDATA,
		PMASK_NOTSUPPORTED,			/* 0x1e */
		PMASK_NOTSUPPORTED,			/* 0x1f */
		PMASK_NOTSUPPORTED,			/* 0x20 */
		PMASK_ENCLOSE,				/* 0x21: SPDU_TD */
		PMASK_TOKEN_SET				/* 0x22: SPDU_RA */
		| PMASK_ENCLOSE
		| PMASK_SERIAL
		| PMASK_UDATA,
		PMASK_NOTSUPPORTED,			/* 0x23 */
		PMASK_NOTSUPPORTED,			/* 0x24 */
		PMASK_NOTSUPPORTED,			/* 0x25 */
		PMASK_NOTSUPPORTED,			/* 0x26 */
		PMASK_NOTSUPPORTED,			/* 0x27 */
		PMASK_NOTSUPPORTED,			/* 0x28 */
		PMASK_SYNC					/* 0x29: SPDU_MAP & SPDU_AE */
		| PMASK_ENCLOSE
		| PMASK_SERIAL
		| PMASK_UDATA,
		PMASK_ENCLOSE				/* 0x2a: SPDU_MAA & SPDU_AEA */
		| PMASK_SERIAL
		| PMASK_UDATA,
		PMASK_NOTSUPPORTED,			/* 0x2b */
		PMASK_NOTSUPPORTED,			/* 0x2c */
		PMASK_ENCLOSE				/* 0x2d: SPDU_AS */
		| PMASK_ACT_ID
		| PMASK_UDATA
		| PMASK_XDATA,
		PMASK_NOTSUPPORTED,			/* 0x2e */
		PMASK_NOTSUPPORTED,			/* 0x2f */
		PMASK_ENCLOSE				/* 0x30: SPDU_ED */
		| PMASK_REASON
		| PMASK_UDATA,
		PMASK_SYNC					/* 0x31: SPDU_MIP */
		| PMASK_ENCLOSE
		| PMASK_SERIAL
		| PMASK_UDATA,
		PMASK_ENCLOSE				/* 0x32: SPDU_MIA */
		| PMASK_SERIAL
		| PMASK_MIA_DATA,
		PMASK_NOTSUPPORTED,			/* 0x33 */
		PMASK_NOTSUPPORTED,			/* 0x34 */
		PMASK_TOKEN_SET				/* 0x35: SPDU_RS */
		| PMASK_ENCLOSE
		| PMASK_RESYNC
		| PMASK_SERIAL
		| PMASK_UDATA
		| PMASK_XDATA,
		PMASK_NOTSUPPORTED,			/* 0x36 */
		PMASK_NOTSUPPORTED,			/* 0x37 */
		PMASK_NOTSUPPORTED,			/* 0x38 */
		PMASK_REASON,				/* 0x39: SPDU_AD */
		PMASK_NODATA,				/* 0x3a: SPDU_ADA */
		PMASK_NOTSUPPORTED,			/* 0x3b */
		PMASK_NOTSUPPORTED,			/* 0x3c */
		PMASK_ENCLOSE				/* 0x3d: SPDU_CD */
		| PMASK_UDATA,
		PMASK_ENCLOSE				/* 0x3e: SPDU_CDA */
		| PMASK_UDATA
	};
void SPDU::reset() {
	spdu_total = 0;
	spdu_enclose = 0;
	spdu_udata = nullptr;
	spdu_ulen = 0;
	spdu_mask = 0;
}
SPDU::SPDU(Category category, byte si) : HEADER(si) {
	spdu_category = category;
	reset();
}
SPDU::SPDU(Category category, int si, NetworkBuffer& tsdu) : HEADER(si, tsdu){
	spdu_category = category;
	reset();
}
SPDU::~SPDU() {
}


void SPDU::setData(int length, const void* data) {
	if (data != nullptr && length > 0) {
		addMask(SMASK_UDATA_PGI);
		spdu_udata = data;
		spdu_ulen = length;
	} else {
		remMask(SMASK_UDATA_PGI);
		spdu_udata = nullptr;
		spdu_ulen = 0;
	}
}
SPDU*SPDU::fromTSDU(Category category, NetworkBuffer& tsdu) {
	ReturnCode rc = NOTOK;
	SPDU* spdu = nullptr;
	SPDU* previous;
#if TODO
			if ((state.sb_pr == SPDU_PR) && bool(state.sb_xspdu)) {
				logger().trace("returning XSDU buffered during preparation");
				spkt = state.sb_xspdu;
				state.sb_xspdu = nullptr;

				return spkt;
			}

			if (bool(state.sb_spdu)) { /* get previous category 0 SPDU */
				logger().trace("returning category 0 SPDU previously buffered");
				spkt = state.sb_spdu;
				state.sb_spdu = nullptr;
				return spkt;
			}

			if (ty != nullptr) {
				tx = ty;
			} else {
				tx = nullptr;
//				if (state.synchrone()) {
//					if ((rc = tsap().TReadRequest(tx, secs, td)) == NOTOK) {
//						if (td.reason() != DR_TIMER)
//							ts2sslose(sa, "TReadRequest", td);
//						else
//							sa.ssaplose(SC_TIMER, nullptr, nullptr, (Object) nullptr);
//						return nullptr;
//					}
//					if (state.sb_tx == nullptr) {
//						return nullptr;
//					}
//					tx = state.sb_tx;
//					state.sb_tx = nullptr;
//				} else {
					return nullptr;
//				}
			}

			if (logger() != nullptr && tx != nullptr) {
				logger().trace("read TSDU, size " + tx.length());
			}

#endif
	spdu = decode(Category::CAT0_OR_CAT1,tsdu);
	switch (spdu->si()) {
		case SPDU_GT: /* category 0 SPDUs */
		case SPDU_PT:
			if (!tsdu.hasRemaining()) {
				//FIXME logger().trace(String.format("got simple SPDU %d", spkt.spdu().si()));
				//FIXME tsdu.erase();
				return spdu;
			}
			break;

		case SPDU_EX: /* category 1 SPDUs with user information field  */
		case SPDU_TD:
			//FIXME spdu.setQbuf(tx);
			return spdu;

		case SPDU_CN: /* category 1 SPDUs */
		case SPDU_AC:
		case SPDU_RF:
		case SPDU_FN:
		case SPDU_DN:
		case SPDU_NF:
		case SPDU_AB:
		case SPDU_AA:
		case SPDU_GTC:
		case SPDU_GTA:
		case SPDU_PR:
			if (!tsdu.hasRemaining()) {
				simple:
				;
				//FIXME logger().trace(String.format("got simple SPDU %d", spkt.spdu().si()));
				//FIXME tx.erase();
				return spdu;
			}
			//FIXME spkt.spktlose(sa, SC_PROTOCOL, nullptr, "session protocol mangled: not expecting " + tx.length()
			//FIXME 	+ "bytes of user information after " + spkt.spdu().getLiteral());

			//FIXME tx.erase();
			return nullptr;

		default:
			//FIXME spkt.spktlose(sa, SC_PROTOCOL, nullptr, "session protocol mangled: not expecting "
			//FIXME 	+ spkt.spdu().getLiteral());
			//FIXME tx.erase();
			return nullptr;
		}

		//FIXME logger().trace(String.format("got cat0 SPDU %d, %d octets left in TSDU", spkt.spdu().si(), tx.length()));
		//FIXME state.sb_spdu = p = spdu; /* save category 0 SPDU */
		previous = spdu; /* save category 0 SPDU */

		spdu = decode(CAT2, tsdu);
		if (spdu == nullptr) {
			//FIXME spkt.spktlose(sa, bool(spkt) ? spkt.errno : SC_CONGEST, nullptr, nullptr, nullptr);
			//FIXME state.sb_spdu = nullptr;
			//FIXME tx.erase();
			return nullptr;
		}

	//TODO	    if (tx.tx_expedited)
	//TODO	    	s.setMask(SMASK_SPDU_EXPD);
	//FIXME	    tx.length() -= cc;

		//FIXME logger().trace(String.format("got cat2 SPDU %d, %d octets left in TSDU", spkt.spdu().si(), tx.length()));
		//FIXME logger().trace(String.format("checking concatenation of %d with %d", spkt.spdu().si(), p.spdu().si()));

		switch ((previous->si()) << 8 | spdu->si()) {
		case (SPDU_GT << 8) | SPDU_DT: // category 2 SPDUs with user data 
			//FIXME spkt.setQbuf(tx);
			break;

		case (SPDU_GT << 8) | SPDU_MIP: /* category 2 SPDUs */
		case (SPDU_PT << 8) | SPDU_MIA:
		case (SPDU_GT << 8) | SPDU_MAP:
//		case (SPDU_GT << 8) | SPDU_AE: 	/* aka SPDU_MAP */
		case (SPDU_PT << 8) | SPDU_MAA:
//		case (SPDU_PT << 8) | SPDU_AEA: /* aka SPDU_MAA */
		case (SPDU_GT << 8) | SPDU_RS:
		case (SPDU_PT << 8) | SPDU_RA:
		case (SPDU_GT << 8) | SPDU_AS:
		case (SPDU_GT << 8) | SPDU_AR:
		case (SPDU_GT << 8) | SPDU_AD:
		case (SPDU_PT << 8) | SPDU_ADA:
		case (SPDU_GT << 8) | SPDU_AI:
		case (SPDU_PT << 8) | SPDU_AIA:
		case (SPDU_GT << 8) | SPDU_CD:
		case (SPDU_PT << 8) | SPDU_CDA:
		case (SPDU_PT << 8) | SPDU_ER:
		case (SPDU_PT << 8) | SPDU_ED:
			if (!tsdu.hasRemaining()) {
				tsdu.clear();
				break;
			}
			//FIXME spkt.spktlose(sa, SC_PROTOCOL, nullptr, "session protocol mangled: not expecting " + tx.length()
			//FIXME 	+ " bytes of user information after " + spkt.spdu().getLiteral());
			//FIXME state.sb_spdu = nullptr;
			return nullptr;

		default:
			//FIXME spkt.spktlose(sa, SC_PROTOCOL, nullptr, "session protocol mangled: not expecting "
			//FIXME 	+ spkt.spdu().getLiteral() + "to be concatenated after " + p.spdu().getLiteral());
			//FIXME state.sb_spdu = nullptr;
			return nullptr;
	}
	switch (spdu->si()) {
		default:
			if (previous->si() == SPDU_GT) {
				GT* spdu_gt = (GT*) previous;
				if (previous->hasMask(SMASK_GT_TOKEN) && spdu_gt->getToken())
					break;
			} else {
				if (previous->hasMask(SMASK_PT_TOKEN) && (((PT*) previous)->getToken()) || previous->getDataLen() > 0)
					break;
			} /* fall... */

		case SPDU_RS:
		case SPDU_AD:
		case SPDU_AI:
		case SPDU_CD:
			previous = nullptr;
			//FIXME state.sb_spdu = nullptr;
			break;
	}

	return spdu;
}

SPDU* SPDU::decode(Category category, NetworkBuffer& tsdu) {
	ReturnCode rc = NOTOK;
	SPDU* spdu = nullptr;
	while (tsdu.hasRemaining()) {
		tsdu.markit();
		byte  si = tsdu.get();
		switch (category) {
		case CAT0_OR_CAT1:
			switch (si) {
			case  SPDU_GT: spdu = new GT(tsdu); break;
			case  SPDU_PT: spdu = new PT(tsdu); break;
			case  SPDU_CN: spdu = new CN(tsdu); break;
			case  SPDU_AC: spdu = new AC(tsdu); break;
			case  SPDU_RF: spdu = new RF(tsdu); break;
			case  SPDU_FN: spdu = new FN(tsdu); break;
			case  SPDU_DN: spdu = new DN(tsdu); break;
			case  SPDU_NF: spdu = new NF(tsdu); break;
			case  SPDU_AB: spdu = new AB(tsdu); break;
			case  SPDU_AA: spdu = new AA(tsdu); break;
			case  SPDU_GTC: spdu = new GTC(tsdu); break;
			case  SPDU_GTA: spdu = new GTA(tsdu); break;
			case  SPDU_PR: spdu = new PR(tsdu); break;
			case  SPDU_TD: spdu = new TD(tsdu); break;
			default:
				poco_assert("should not go there" == nullptr);
			}
			break;
		case CAT0:
			switch (si) {
			case  SPDU_GT: spdu = new GT(tsdu); break;
			case  SPDU_PT: spdu = new PT(tsdu); break;
			}
			break;
		case CAT1:				// ITU-T X225 Table 7 page 19
			switch (si) {
			case  SPDU_CN: spdu = new CN(tsdu); break;
			case  SPDU_AC: spdu = new AC(tsdu); break;
			case  SPDU_RF: spdu = new RF(tsdu); break;
			case  SPDU_FN: spdu = new FN(tsdu); break;
			case  SPDU_DN: spdu = new DN(tsdu); break;
			case  SPDU_NF: spdu = new NF(tsdu); break;
			case  SPDU_AB: spdu = new AB(tsdu); break;
			case  SPDU_AA: spdu = new AA(tsdu); break;
			case  SPDU_GTC: spdu = new GTC(tsdu); break;
			case  SPDU_GTA: spdu = new GTA(tsdu); break;
			case  SPDU_PR: spdu = new PR(tsdu); break;
			case  SPDU_TD: spdu = new TD(tsdu); break;
			default:
				poco_assert("should not go there" == nullptr);
			}
			break;
		case CAT2:
			switch (si) {
				case  SPDU_DT: spdu = new DT(tsdu); break;
				case  SPDU_MIP: spdu = new MIP(tsdu); break;
				case  SPDU_MIA: spdu = new MIA(tsdu); break;
				case  SPDU_MAP: spdu = new MAP(tsdu); break;
//				case  SPDU_AE: spdu = new AE(buffer); break; aka SPDU_MAP
				case  SPDU_MAA: spdu = new MAA(tsdu); break;
//				case  SPDU_AEA	: spdu = new AEA(buffer); break; aka SPDU_MAA
				case  SPDU_RS: spdu = new RS(tsdu); break;
				case  SPDU_RA: spdu = new RA(tsdu); break;
				case  SPDU_AS: spdu = new AS(tsdu); break;
				case  SPDU_AR: spdu = new AR(tsdu); break;
				case  SPDU_AI: spdu = new AI(tsdu); break;
				case  SPDU_AIA: spdu = new AIA(tsdu); break;
				case  SPDU_AD: spdu = new AD(tsdu); break;
				case  SPDU_ADA: spdu = new ADA(tsdu); break;
				case  SPDU_CD: spdu = new CD(tsdu); break;
				case  SPDU_CDA: spdu = new CDA(tsdu); break;
				case  SPDU_ER: spdu = new ER(tsdu); break;
				case  SPDU_ED: spdu = new ED(tsdu); break;

//FIXME ???		case  SPDU_EX	: spdu = new EX(buffer); break;
				default:
					poco_assert("should not go there" == nullptr);
				}
			break;
		}
		if (spdu != nullptr)
			rc = spdu->decode(tsdu);
		else
			poco_assert(false);
		return spdu;
	}
	return spdu;
}
void SPDU::append(HEADER* piorpgi) {
	add(piorpgi);
	spdu_sons.push_back(piorpgi); 
}
ReturnCode	SPDU::flush(unique_ptr<NetworkBuffer>& tsdu, int cc, const void* data) const {
	bool single = false;
	if (tsdu.get() == nullptr) {
		single = true;
		allocate(tsdu, cc);
	}
	HEADER::encode(tsdu);
	for(auto son : spdu_sons) {
		son->encode(tsdu);
	}
	if (cc > 0)
		tsdu->putBytes(cc, (const byte*)data);
	if (single) {
		poco_assert(tsdu->remaining() == 0);
		tsdu->flip();
	}
	return OK;
}

ReturnCode SPDU::control(NetworkBuffer& tsdu) {
	int pmask;
	if (spdu_category == CAT0) {
		switch (si()) {
		case SPDU_GT:
			addMask(SMASK_SPDU_GT);
			break;

		case SPDU_AB:
			addMask(SMASK_SPDU_AB);
			break;

		case SPDU_AA:
			addMask(SMASK_SPDU_AA);
			break;

		default:
			break;
		}
	}
	pmask = si_table[si()];
	if (si() >= sizeof(si_table) || pmask == PMASK_NOTSUPPORTED) {
		throw  Exception(AbortCode::SC_PROTOCOL);
	}
	return OK;
}

string SPDU::getLiteral() const {
	string	sb;
	switch (si()) {
	case SPDU_GT: sb.append("SPDU_GT"); break;
	case SPDU_CN: sb.append("SPDU_CN"); break;
	case SPDU_AC: sb.append("SPDU_AC"); break;
	case SPDU_RF: sb.append("SPDU_RF"); break;
	case SPDU_FN: sb.append("SPDU_FN"); break;
	case SPDU_DN: sb.append("SPDU_DN"); break;
	case SPDU_NF: sb.append("SPDU_NF"); break;
//	case SPDU_AB: sb.append("SPDU_AB"); break;
	case SPDU_AA: sb.append("SPDU_AA"); break;
//	case SPDU_DT: sb.append("SPDU_DT"); break;
	case SPDU_EX: sb.append("SPDU_EX"); break;
	case SPDU_TD: sb.append("SPDU_TD"); break;
	case SPDU_CD: sb.append("SPDU_CD"); break;
	case SPDU_CDA: sb.append("SPDU_CDA"); break;
//	case SPDU_GT: sb.append("SPDU_GT"); break;
	case SPDU_PT: sb.append("SPDU_PT"); break;
	case SPDU_GTC: sb.append("SPDU_GTC"); break;
	case SPDU_GTA: sb.append("SPDU_GTA"); break;
	case SPDU_MIP: sb.append("SPDU_MIP"); break;
	case SPDU_MIA: sb.append("SPDU_MIA"); break;
	case SPDU_MAP: sb.append("SPDU_MAP"); break;
	case SPDU_MAA: sb.append("SPDU_MAA"); break;
	case SPDU_RS: sb.append("SPDU_RS"); break;
	case SPDU_RA: sb.append("SPDU_RA"); break;
	case SPDU_PR: sb.append("SPDU_PR"); break;
	case SPDU_ER: sb.append("SPDU_ER"); break;
	case SPDU_ED: sb.append("SPDU_ED"); break;
	case SPDU_AS: sb.append("SPDU_AS"); break;
	case SPDU_AR: sb.append("SPDU_AR"); break;
	case SPDU_AB: sb.append("SPDU_AB"); break;
//	case SPDU_AA: sb.append("SPDU_AA"); break;
	case SPDU_AD: sb.append("SPDU_AD"); break;
	case SPDU_ADA: sb.append("SPDU_ADA"); break;
//	case SPDU_MAP: sb.append("SPDU_MAP"); break;
//	case SPDU_MAA: sb.append("SPDU_MAA"); break;
	default: sb.append("???" + to_string(si())); break;
	}
	return sb;
}
}
}
}
