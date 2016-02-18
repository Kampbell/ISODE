#include "als/ssap/Requirement.h"

namespace ALS {
	namespace SSAP {
	/** RELEASE UNIT EXISTS = NEGOTIATED. */
	const SSAP_API Requirement	RELEASE_UNIT_EXISTS(1 << NEGOTIATED);

	/** MAJOR UNIT EXISTS = (MAJORSYNC | ACTIVITY). */
	const SSAP_API Requirement	MAJOR_UNIT_EXISTS(1 << MAJORSYNC | 1 << ACTIVITY);

	/** ACTIVITY UNIT EXISTS = ACTIVITY. */
	const SSAP_API Requirement	ACTIVITY_UNIT_EXISTS(1 << ACTIVITY);

	/** MINOR UNIT EXISTS = MINORSYNC. */
	const SSAP_API Requirement	MINOR_UNIT_EXISTS(1 << MINORSYNC);

	/** DATA UNIT EXISTS = HALFDUPLEX. */
	const SSAP_API Requirement	DATA_UNIT_EXISTS(1 << HALFDUPLEX);

	/** TOKENS SUBSET. */
	const SSAP_API Requirement	SUBSET_TOKENS(
								  RELEASE_UNIT_EXISTS
								| MAJOR_UNIT_EXISTS 
								| ACTIVITY_UNIT_EXISTS 
								| MINOR_UNIT_EXISTS 
								| DATA_UNIT_EXISTS);
	/** BASE SUBSET. */
	const SSAP_API Requirement	SUBSET_BASE(
		                          1 << HALFDUPLEX 
								| 1 << TYPEDATA 
								| 1 << CAPABILITY 
								| 1 << MINORSYNC 
								| 1 << EXCEPTIONS 
								| 1 << ACTIVITY);

	/** BC SUBSET. */
	const SSAP_API Requirement	SUBSET_BC(1 << HALFDUPLEX | 1 << DUPLEX);

	/** BS SUBSET. */
	const SSAP_API Requirement	SUBSET_BS(
		                          1 << NEGOTIATED 
								| 1 << HALFDUPLEX 
								| 1 << DUPLEX 
								| 1 << TYPEDATA 
								| 1 << MINORSYNC
								| 1 << MAJORSYNC 
								| 1 << MAJORSYNC 
								| 1 << RESYNCHRONIZE);

	const SSAP_API Requirement	SUBSET_MYREQUIRE(
								  SUBSET_BASE 
								| SUBSET_BC 
								| SUBSET_BS 
								| Requirement(1 << EXPEDITED));

	/** DEFAULT SUBSET. */
	const SSAP_API Requirement	SUBSET_DEFAULT(
								  1 << HALFDUPLEX 
								| 1 << MINORSYNC 
								| 1 << ACTIVITY 
								| 1 << CAPABILITY 
								| 1 << EXCEPTIONS);

	Requirement::Requirement(nat4 bits) : bitset(bits) {
	}
	Requirement::Requirement(const bitset<FUNCTIONAL_UNITS>& bitset) : bitset(bitset) {
	}
	Requirement::Requirement(const Requirement& requirement) : bitset(requirement) {
	}
	Requirement& Requirement::operator = (const Requirement& requirement) {
		*(bitset<FUNCTIONAL_UNITS>*)this = requirement;
		return *this;
	}
	string Requirement::to_string() const {
		string sb;
		for(size_t no = 0; no < size(); no++) {
			if (test(no)) {
				sb.append(Requirement::to_char(no));
				if (no < size() - 1)
					sb.append(", ");
			}
		}
		return sb;
	}
	const char* Requirement::to_char(byte no) {
		switch(no) {
			case FunctionalUnit::HALFDUPLEX		:	return "HALFDUPLEX";
			case FunctionalUnit::DUPLEX			:	return "DUPLEX";
			case FunctionalUnit::EXPEDITED		:	return "EXPEDITED";
			case FunctionalUnit::MINORSYNC		:	return "MINORSYNC";
			case FunctionalUnit::MAJORSYNC		:	return "MAJORSYNC";
			case FunctionalUnit::RESYNCHRONIZE	:	return "RESYNCHRONIZE";
			case FunctionalUnit::ACTIVITY		:	return "ACTIVITY";
			case FunctionalUnit::NEGOTIATED		:	return "NEGOTIATED";
			case FunctionalUnit::CAPABILITY		:	return "CAPABILITY";
			case FunctionalUnit::EXCEPTIONS		:	return "EXCEPTIONS";
			case FunctionalUnit::TYPEDATA		:	return "TYPEDATA";
			case FunctionalUnit::SYMETRIC		:	return "SYMETRIC";
			case FunctionalUnit::SEPARATION		:	return "SEPARATION";
			default								:	return "???";
		}
	}

}
}