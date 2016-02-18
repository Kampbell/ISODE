#ifndef ALS_PSAP_FunctionalUnit_h
#define ALS_PSAP_FunctionalUnit_h

namespace ALS {
	namespace PSAP {
		//
		// As BitSet index starts at 0, the first FunctionalUnit enum is 0 instead of 1
		// Order is mandate by the ITU-T X.226
		//
		enum  FunctionalUnit {
			/** 0x0001 HALFDUPLEX. */
			CM				= 0,		// Context Management functional unit
			/** 0x0002 DUPLEX. */
			CR				= 1,		// Context Restoration functional unit

			//
			// readable aliases
			//
			CONTEXT_MANAGEMENT		= CM,
			CONTEXT_RESTORATION		= CR
		};

		const int FUNCTIONAL_UNITS = 2;
	}
}
#endif