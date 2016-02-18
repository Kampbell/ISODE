/*
 * Requirement.h
 *
 *  Created on: 27 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_REQUIREMENT_H_
#define ALS_SSAP_REQUIREMENT_H_
#define USE_BITSET 1
#include <string>
using std::string;

#include "als/ssap/ssap.h"

#include "als/ssap/FunctionalUnit.h"
using ALS::SSAP::FunctionalUnit;

#if USE_BITSET
#include <bitset>
using std::bitset;
#else
#include "als/base/util/Bits.h"
#endif

namespace ALS {
namespace SSAP {
#if USE_BITSET
class SSAP_API Requirement : public bitset<FUNCTIONAL_UNITS> {
public:

#if 0
	/** 0x0001 HALFDUPLEX. */
	static const int	HALFDUPLEX				= FunctionalUnit::HD;

	/** 0x0002 DUPLEX. */
	static const int	DUPLEX					= FunctionalUnit::FD;

	/** 0x0004 EXPEDITED DATA. */
	static const int	EXPEDITED				= FunctionalUnit::EX;

	/** 0x0008 MINOR SYNCHRONIZE. */
	static const int	MINORSYNC				= FunctionalUnit::SY;

	/** 0x0010 MAJOR SYNCHRONIZE. */
	static const int	MAJORSYNC				= FunctionalUnit::MA;

	/** 0x0020 RESYNCHRONIZE. */
	static const int	RESYNCHRONIZE			= FunctionalUnit::RESYN;

	/** 0x0040 ACTIVITY MANAGEMENT. */
	static const int	ACTIVITY				= FunctionalUnit::ACT;

	/** 0x0080 NEGOTIATED RELEASE. */
	static const int	NEGOTIATED				= FunctionalUnit::NR;

	/** 0x0100 CAPABILITY DATA TRANSFER. */
	static const int	CAPABILITY				= FunctionalUnit::CD;

	/** 0x0200 EXCEPTIONS REPORTING. */
	static const int	EXCEPTIONS				= FunctionalUnit::EXCEP;

	/** 0x0400 TYPED DATA TRANSFER. */
	static const int	TYPEDATA				= FunctionalUnit::TD;

	/** 0x0800 SYMETRIC SYNCHRONIZE. */
	static const int	SYMETRIC				= FunctionalUnit::SS;

	/** 0x1000 DATA SEPARATION. */
	static const int	SEPARATION				= FunctionalUnit::DS;
#endif

public:
		Requirement(nat4 bits = 0);
		Requirement(const bitset<FUNCTIONAL_UNITS>& bitset);
		Requirement(const Requirement& requirement);

		bool has(const Requirement& requirement) const { return (*this & requirement).any(); }
		Requirement& operator= (const Requirement& requirement);
		static nat2 toint(FunctionalUnit fu) { assert(fu < FUNCTIONAL_UNITS); return 1 << fu; }
		string to_string() const;
private:
		static const char* to_char(byte no);
};
	/** RELEASE UNIT EXISTS = NEGOTIATED. */
	extern const SSAP_API Requirement	RELEASE_UNIT_EXISTS;// = NEGOTIATED

	/** MAJOR UNIT EXISTS = (MAJORSYNC | ACTIVITY). */
	extern SSAP_API const Requirement	MAJOR_UNIT_EXISTS;	//= (MAJORSYNC | ACTIVITY);

	/** ACTIVITY UNIT EXISTS = ACTIVITY. */
	extern SSAP_API const Requirement	ACTIVITY_UNIT_EXISTS;//= ACTIVITY;

	/** MINOR UNIT EXISTS = MINORSYNC. */
	extern SSAP_API const Requirement	MINOR_UNIT_EXISTS;	//= MINORSYNC;

	/** DATA UNIT EXISTS = HALFDUPLEX. */
	extern SSAP_API const Requirement	DATA_UNIT_EXISTS;	//= HALFDUPLEX;

	/** TOKENS SUBSET. */
	extern SSAP_API const Requirement	SUBSET_TOKENS;		//= (RELEASE_UNIT_EXISTS | MAJOR_UNIT_EXISTS | ACTIVITY_UNIT_EXISTS | MINOR_UNIT_EXISTS | DATA_UNIT_EXISTS);

	/** BASE SUBSET. */
	extern SSAP_API const Requirement	SUBSET_BASE;		//= (HALFDUPLEX | TYPEDATA | CAPABILITY | MINORSYNC | EXCEPTIONS | ACTIVITY);

	/** BC SUBSET. */
	extern SSAP_API const Requirement	SUBSET_BC;			//= (HALFDUPLEX | DUPLEX);

	/** BS SUBSET. */
	extern SSAP_API const Requirement	SUBSET_BS;			//= (NEGOTIATED | HALFDUPLEX | DUPLEX | TYPEDATA | MINORSYNC | MAJORSYNC | MAJORSYNC | RESYNCHRONIZE

	/* MYREQUIREMENT SUBSET */
	extern SSAP_API const Requirement	SUBSET_MYREQUIRE;	//= (SUBSET_BASE | SUBSET_BC | SUBSET_BS | EXPEDITED);

	/** DEFAULT SUBSET. */
	extern SSAP_API const Requirement	SUBSET_DEFAULT;		//= (HALFDUPLEX | MINORSYNC | ACTIVITY | CAPABILITY | EXCEPTIONS);

#else
class Requirement : public ALS::BASE::UTIL::Bits {
public:
	/** 0x0001 HALFDUPLEX. */
	static const int	HALFDUPLEX				= 0x0001;

	/** 0x0002 DUPLEX. */
	static const int	DUPLEX					= 0x0002;

	/** 0x0004 EXPEDITED DATA. */
	static const int	EXPEDITED				= 0x0004;

	/** 0x0008 MINOR SYNCHRONIZE. */
	static const int	MINORSYNC				= 0x0008;

	/** 0x0010 MAJOR SYNCHRONIZE. */
	static const int	MAJORSYNC				= 0x0010;

	/** 0x0020 RESYNCHRONIZE. */
	static const int	RESYNCHRONIZE			= 0x0020;

	/** 0x0040 ACTIVITY MANAGEMENT. */
	static const int	ACTIVITY				= 0x0040;

	/** 0x0080 NEGOTIATED RELEASE. */
	static const int	NEGOTIATED				= 0x0080;

	/** 0x0100 CAPABILITY DATA TRANSFER. */
	static const int	CAPABILITY				= 0x0100;

	/** 0x0200 EXCEPTIONS REPORTING. */
	static const int	EXCEPTIONS				= 0x0200;

	/** 0x0400 TYPED DATA TRANSFER. */
	static const int	TYPEDATA				= 0x0400;

	/** 0x0800 SYMETRIC SYNCHRONIZE. */
	static const int	SYMETRIC				= 0x0800;

	/** 0x1000 DATA SEPARATION. */
	static const int	SEPARATION				= 0x1000;

	/** RELEASE UNIT EXISTS = NEGOTIATED. */
	static const int	RELEASE_UNIT_EXISTS		= NEGOTIATED;

	/** MAJOR UNIT EXISTS = (MAJORSYNC | ACTIVITY). */
	static const int	MAJOR_UNIT_EXISTS		= (MAJORSYNC | ACTIVITY);

	/** ACTIVITY UNIT EXISTS = ACTIVITY. */
	static const int	ACTIVITY_UNIT_EXISTS	= ACTIVITY;

	/** MINOR UNIT EXISTS = MINORSYNC. */
	static const int	MINOR_UNIT_EXISTS		= MINORSYNC;

	/** DATA UNIT EXISTS = HALFDUPLEX. */
	static const int	DATA_UNIT_EXISTS		= HALFDUPLEX;

	/** TOKENS SUBSET. */
	static const int	SUBSET_TOKENS			= (RELEASE_UNIT_EXISTS | MAJOR_UNIT_EXISTS | ACTIVITY_UNIT_EXISTS
														| MINOR_UNIT_EXISTS | DATA_UNIT_EXISTS);
	/** BASE SUBSET. */
	static const int	SUBSET_BASE				= (HALFDUPLEX | TYPEDATA | CAPABILITY | MINORSYNC | EXCEPTIONS | ACTIVITY);

	/** BC SUBSET. */
	static const int	SUBSET_BC				= (HALFDUPLEX | DUPLEX);

	/** BS SUBSET. */
	static const int	SUBSET_BS				= (NEGOTIATED | HALFDUPLEX | DUPLEX | TYPEDATA | MINORSYNC
												 | MAJORSYNC | MAJORSYNC | RESYNCHRONIZE
	);

	static const int	SUBSET_MYREQUIRE		= (SUBSET_BASE | SUBSET_BC | SUBSET_BS | EXPEDITED);

	/** DEFAULT SUBSET. */
	static const int	SUBSET_DEFAULT			= (HALFDUPLEX | MINORSYNC | ACTIVITY | CAPABILITY | EXCEPTIONS);

public:
	Requirement() {
	}
	Requirement(int4 bits) : Bits(bits){
	}
	virtual ~Requirement() {
	}

	bool operator[] (FunctionalUnit no) const { return this->has(1 << no); }
};
#endif
}
}

#endif
