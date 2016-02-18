#ifndef ALS_SSAP_FUNCTIONALUNIT_H_
#define ALS_SSAP_FUNCTIONALUNIT_H_

namespace ALS {
	namespace SSAP {
		/*
		A.5.1 Functional units
		The set of all functional units specified in this Recommendation | International Standard is defined as:
		fu-dom = {FD, HD, EXCEP, TD, NR, SY, SS, DS, MA, RESYN, EX, ACT, CD} where

		FD Duplex functional unit
		HD Half-duplex functional unit
		EXCEP Exceptions functional unit
		TD Typed data functional unit
		NR Negotiated release functional unit
		SY Minor synchronize functional unit
		SS Symmetric synchronize functional unit
		DS Data separation functional unit
		MA Major synchronize functional unit
		RESYN Resynchronize functional unit
		EX Expedited data functional unit
		ACT Activity management functional unit
		CD Capability data exchange functional unit
		*/

		//
		// As BitSet index starts at 0, the first FunctionalUnit enum is 0 instead of 1
		// Order is mandate by the ITU-T X.225
		// Names are those of the normative States table in ITU-T X.225 Annex A
		//
		enum  FunctionalUnit {
			/** 0x0001 HALFDUPLEX. */
			HD				= 0,		// Half - duplex functional unit
			/** 0x0002 DUPLEX. */
			FD				= 1,		// Duplex functional unit
			/** 0x0004 EXPEDITED DATA. */
			EX				= 2,		// Expedited data functional unit
			/** 0x0008 MINOR SYNCHRONIZE. */
			SY				= 3,		// Minor synchronize functional unit
			/** 0x0010 MAJOR SYNCHRONIZE. */
			MA				= 4,		// Major synchronize functional unit
			/** 0x0020 RESYNCHRONIZE. */
			RESYN			= 5,		// Resynchronize functional unit
			/** 0x0040 ACTIVITY MANAGEMENT. */
			ACT				= 6,		// Activity management functional unit
			/** 0x0080 NEGOTIATED RELEASE. */
			NR				= 7,		// Negotiated release functional unit
			/** 0x0100 CAPABILITY DATA TRANSFER. */
			CD				= 8,		// Capability data exchange functional unit
			/** 0x0200 EXCEPTIONS REPORTING. */
			EXCEP			= 9,		// Exceptions functional unit
			/** 0x0400 TYPED DATA TRANSFER. */
			TD				= 10,		// Typed data functional unit
			/** 0x0800 SYMETRIC SYNCHRONIZE. */
			SS				= 11,		// Symmetric synchronize functional unit
			/** 0x1000 DATA SEPARATION. */
			DS				= 12,		// Data separation functional unit

			//
			// readable aliases
			//
			HALFDUPLEX		= HD,
			DUPLEX			= FD,
			EXPEDITED		= EX,
			MINORSYNC		= SY,
			MAJORSYNC		= MA,
			RESYNCHRONIZE	= RESYN,
			ACTIVITY		= ACT,
			NEGOTIATED		= NR,
			CAPABILITY		= CD,
			EXCEPTIONS		= EXCEP,
			TYPEDATA		= TD,
			SYMETRIC		= SS,
			SEPARATION		= DS,
		};

		const int FUNCTIONAL_UNITS = 13;
	}
}
/*
DUPLEX		= FD,
HALFDUPLEX	= HD,
EXCEPTIONS	= EXCEP,
TYPEDDATA	= TD,
NEGOTIATED_RELEASE = NR,
SYMETRIC_SYNCHRONIZE = SS,
DATA_SEPARATION = DS,
MAJOR_SYNCHRONIZE = MA,
MINOR_SYNCHRONIZE = SY,
MAJORSYNC	= MA,
RESYNCHRONIZE = RESYN,
ACTIVITY	= ACT,
CAPABILITY	= CD
*/
#endif