/*************************************************************/
/* Copyright (C) 2014 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* This file was generated by a TRIAL version of the OSS ASN.1 Tools.
 * Applications built using this file can be executed only on the machine
 * on which you run the OSS ASN.1 compiler. */

/* Generated for: Kampbell (Trial), License: 70040Z. */
/* Abstract syntax: bcas */
/* Created: Mon Dec 22 12:04:12 2014 */
/* ASN.1/C++ compiler version: 6.0 */
/* Code generated for runtime version 6.0 or later */
/* Compiler operating system: Windows */
/* Compiler machine type: Intel x86 */
/* Target operating system: Windows */
/* Target machine type: Intel x86 */
/* C++ compiler options required: -Zp8 (Microsoft) */
/* ASN.1 compiler options and file names specified:
 * -soed -output Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1\csn -ber
 * -messageFormat msvc -allow universaltags
 * C:/ProgramData/OSS Nokalva/asn1cpp/win32.trial/6.0.0/samples/basic/encode/bcas.asn
 */

#define OSS_COMPILER_API_LEVEL 31
#define _OSS_CONTROL_FILE
#include "bcas.h"
#include "string.h"

/* Control table object */

class bcas_TableType : public OssControlTable {
public:
    static void *internal;
    bcas_TableType();
    int destroy(void *data, OssTypeIndex typeindex);
    int copy(void *src, void **dst, OssTypeIndex typeindex);
    int equal(void *data1, void *data2, OssTypeIndex typeindex);
};

bcas_TableType::bcas_TableType() : OssControlTable(internal) {
}

int bcas_TableType::destroy(void *data, OssTypeIndex typeindex) {
    switch (typeindex) {
	case 1:
	    delete (BBCard *)data;
	    break;
	default:
	    return oss_call_error(OSS_UNKNOWN_TYPE);
    }
    return 0;
}

int bcas_TableType::copy(void *src, void **dst, OssTypeIndex typeindex) {
    switch (typeindex) {
	case 1:
	    *dst = new BBCard(*(BBCard *)src);
	    break;
	default:
	    return oss_call_error(OSS_UNKNOWN_TYPE);
    }
    if (*dst == 0)
	return OSS_NO_MEMORY;
    return 0;
}

int bcas_TableType::equal(void *data1, void *data2, OssTypeIndex typeindex) {
    switch (typeindex) {
	case 1:
	    return *(BBCard *)data1 == *(BBCard *)data2;
    }
    return 0;
}

static bcas_TableType bcas_Table;

/* Representation types */

void *CareerEntry::operator new(size_t size) {
    return ossNewFunc(size);
}

void CareerEntry::operator delete(void *ptr) {
    asn1Free(ptr);
}

CareerEntry::CareerEntry() {
    memset(this, 0, sizeof(CareerEntry));
}

CareerEntry::CareerEntry(const CareerEntry & that) {
    OSSTRY {
	bit_mask = that.bit_mask;
	from_field = that.from_field;
	to_field = that.to_field;
	team_field = that.team_field;
    } OSSCLEAN(CareerEntry)
}

CareerEntry::CareerEntry(from from_val, to to_val, const team & team_val) {
    OSSTRY {
	bit_mask = 0x80;
	from_field = from_val;
	to_field = to_val;
	team_field = team_val;
    } OSSCLEAN(CareerEntry)
}

CareerEntry::CareerEntry(from from_val, const team & team_val) {
    OSSTRY {
	bit_mask = 0;
	from_field = from_val;
	team_field = team_val;
    } OSSCLEAN(CareerEntry)
}

CareerEntry & CareerEntry::operator = (const CareerEntry & that) {
    if (this == &that)
	return *this;
    this->~CareerEntry();
    bit_mask = that.bit_mask;
    from_field = that.from_field;
    to_field = that.to_field;
    team_field = that.team_field;
    return *this;
}

int CareerEntry::operator == (const CareerEntry & that) const {
    if (bit_mask != that.bit_mask)
	return 0;
    if (from_field != that.from_field)
	return 0;
    if (bit_mask & 0x80) {
	if (to_field != that.to_field)
	    return 0;
    }
    if (team_field != that.team_field)
	return 0;
    return 1;
}

int CareerEntry::operator != (const CareerEntry & that) const {
    return !(operator ==(that));
}

CareerEntry::from & CareerEntry::get_from() {
    return from_field;
}

CareerEntry::from CareerEntry::get_from() const {
    return from_field;
}

void CareerEntry::set_from(from from_val) {
    from_field = from_val;
}

CareerEntry::to *CareerEntry::get_to() {
    if (bit_mask & 0x80)
	return &to_field;
    else
	return 0;
}

const CareerEntry::to *CareerEntry::get_to() const {
    if (bit_mask & 0x80)
	return &to_field;
    else
	return 0;
}

void CareerEntry::set_to(to to_val) {
    bit_mask |= 0x80;
    to_field = to_val;
}

int CareerEntry::to_is_present() const {
    return !!(bit_mask & 0x80);
}

void CareerEntry::omit_to() {
    bit_mask &= ~0x80;
}

CareerEntry::team & CareerEntry::get_team() {
    return team_field;
}

const CareerEntry::team & CareerEntry::get_team() const {
    return team_field;
}

void CareerEntry::set_team(const team & team_val) {
    team_field = team_val;
}

/* Auxiliary data structures and functions for class __seqof1 */

class __seqof1_member {
public:
    __seqof1_member *next;
    __seqof1::component value;
    void * operator new(size_t size);
    void operator delete(void *ptr);
    __seqof1_member();
    __seqof1_member(const __seqof1::component & val);
};

void *__seqof1_member::operator new(size_t size) {
    return ossNewFunc(size);
}

void __seqof1_member::operator delete(void *ptr) {
    asn1Free(ptr);
}

__seqof1_member::__seqof1_member() {
}

__seqof1_member::__seqof1_member(const __seqof1::component & val) {
    value = val;
}

static void *__seqof1_copy(void *that) {
    return new __seqof1_member(((__seqof1_member *)that)->value);
}

static void __seqof1_destroy(void *that) {
    delete (__seqof1_member *)that;
}

static int __seqof1_compare(void *val1, void *val2) {
    return (((__seqof1_member *)val1)->value == ((__seqof1_member *)val2)->value);
}

/* Constructors */

__seqof1::__seqof1() {
}

__seqof1::__seqof1(const __seqof1 & that) {
    OSSTRY {
	do_copy(that, &__seqof1_copy);
    } OSSCLEAN(__seqof1)
}

/* Destructor */

__seqof1::~__seqof1() {
    do_destroy(&__seqof1_destroy);
}

/* Operators: assignment, equality, inequality */

__seqof1 & __seqof1::operator = (const __seqof1 & that) {
    do_destroy(&__seqof1_destroy);
    do_copy(that, &__seqof1_copy);
    return *this;
}

int __seqof1::operator == (const __seqof1 & that) const {
    return do_compare(that, &__seqof1_compare);
}

int __seqof1::operator != (const __seqof1 & that) const {
    return !do_compare(that, &__seqof1_compare);
}

/* Locate ("At" etc) methods */

__seqof1::component *__seqof1::at(OssIndex pos) {
    return &((__seqof1_member *)pos)->value;
}

const __seqof1::component *__seqof1::at(OssIndex pos) const {
    return &((__seqof1_member *)pos)->value;
}

/* Add ("Insert", "Prepend", "Append" etc) methods */

OssIndex __seqof1::prepend(const component & val) {
    __seqof1_member *newrec = new __seqof1_member(val);
    if (!newrec)
	return OSS_NOINDEX;
    return do_prepend(newrec);
}

OssIndex __seqof1::prepend(__seqof1 *seq) {
    return do_prepend(seq);
}

OssIndex __seqof1::insert_after(OssIndex pos, const component & val) {
    __seqof1_member *newrec = new __seqof1_member(val);
    if (!newrec)
	return OSS_NOINDEX;
    return do_insert_after(pos, newrec);
}

OssIndex __seqof1::insert_after(OssIndex pos, __seqof1 *seq) {
    return do_insert_after(pos, seq);
}

/* Remove methods */

int __seqof1::remove_front() {
    __seqof1_member *extr = (__seqof1_member *)do_extract_front();
    if (!extr)
	return oss_call_error(OSS_COMPONENT_MISSING);
    __seqof1_destroy(extr);
    return 0;
}

int __seqof1::remove_after(OssIndex pos) {
    __seqof1_member *extr = (__seqof1_member *)do_extract_after(pos);
    if (!extr)
	return oss_call_error(OSS_COMPONENT_MISSING);
    __seqof1_destroy(extr);
    return 0;
}

/* Extract methods */

__seqof1 *__seqof1::extract_after(OssIndex begin, OssIndex end) {
    return (__seqof1 *)do_extract_after(begin, end);
}

void *BBCard::operator new(size_t size) {
    return ossNewFunc(size);
}

void BBCard::operator delete(void *ptr) {
    asn1Free(ptr);
}

BBCard::BBCard() {
    memset(this, 0, sizeof(BBCard));
}

BBCard::BBCard(const BBCard & that) {
    OSSTRY {
	name_field = that.name_field;
	age_field = that.age_field;
	position_field = that.position_field;
	career_field = that.career_field;
    } OSSCLEAN(BBCard)
}

BBCard::BBCard(const name & name_val, age age_val, const position & position_val, 
    const career & career_val) {
    OSSTRY {
	name_field = name_val;
	age_field = age_val;
	position_field = position_val;
	career_field = career_val;
    } OSSCLEAN(BBCard)
}

BBCard & BBCard::operator = (const BBCard & that) {
    if (this == &that)
	return *this;
    name_field = that.name_field;
    age_field = that.age_field;
    position_field = that.position_field;
    career_field = that.career_field;
    return *this;
}

int BBCard::operator == (const BBCard & that) const {
    if (name_field != that.name_field)
	return 0;
    if (age_field != that.age_field)
	return 0;
    if (position_field != that.position_field)
	return 0;
    if (career_field != that.career_field)
	return 0;
    return 1;
}

int BBCard::operator != (const BBCard & that) const {
    return !(operator ==(that));
}

BBCard::name & BBCard::get_name() {
    return name_field;
}

const BBCard::name & BBCard::get_name() const {
    return name_field;
}

void BBCard::set_name(const name & name_val) {
    name_field = name_val;
}

BBCard::age & BBCard::get_age() {
    return age_field;
}

BBCard::age BBCard::get_age() const {
    return age_field;
}

void BBCard::set_age(age age_val) {
    age_field = age_val;
}

BBCard::position & BBCard::get_position() {
    return position_field;
}

const BBCard::position & BBCard::get_position() const {
    return position_field;
}

void BBCard::set_position(const position & position_val) {
    position_field = position_val;
}

BBCard::career & BBCard::get_career() {
    return career_field;
}

const BBCard::career & BBCard::get_career() const {
    return career_field;
}

void BBCard::set_career(const career & career_val) {
    career_field = career_val;
}

/* Universal PDU class */

bcas_PDU::bcas_PDU() {
}

void bcas_PDU::set_BBCard(BBCard & d) {
    index = 1;
    data = &d;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    constant = 0;
#endif
}

BBCard *bcas_PDU::get_BBCard() const {
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    if (index == 1 && !constant)
#else
    if (index == 1)
#endif
	return (BBCard *)data;
    else
	return 0;
}

#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
void bcas_PDU::set_const_BBCard(const BBCard & d) {
    index = 1;
    data = (void *)&d;
    constant = 1;
}

const BBCard *bcas_PDU::get_const_BBCard() const {
    if (index == 1)
	return (const BBCard *)data;
    else
	return 0;
}

#endif
/* Specific PDU classes */

BBCard_PDU::BBCard_PDU() {
}

void BBCard_PDU::set_data(BBCard & d) {
    data = &d;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    constant = 0;
#endif
}

BBCard *BBCard_PDU::get_data() const {
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    if (constant)
	return 0;
#endif
    return (BBCard *)data;
}

#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED

void BBCard_PDU::set_const_data(const BBCard & d) {
    data = (void *)&d;
    constant = 1;
}

const BBCard *BBCard_PDU::get_const_data() const {
    return (const BBCard *)data;
}

#endif

OssTypeIndex BBCard_PDU::get_index() const {
    return 1;
}

/* Control object class */

bcas_Control::bcas_Control() : OssControl(&bcas_Table, bcas_TableType::internal) {
}

bcas_Control::bcas_Control(const bcas_Control & that) : OssControl(that) {
}


/* ASN.1 data initialization */
/* Local control table initialization */
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
extern "C" void DLL_ENTRY _oss_run_SOED_on_INTEL_X86_WINDOWS_AND_WINNT(void);
static void _oss_post_init(struct ossGlobal *world);
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 12)
static unsigned char _privateFlags[] = {0x01,0x00};
#endif /* OSS_SPARTAN_AWARE >= 12 */
#endif /* OSS_SPARTAN_AWARE */

void DLL_ENTRY_FDEF _ossinit_bcas(struct ossGlobal *world) {
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
    _oss_run_SOED_on_INTEL_X86_WINDOWS_AND_WINNT();
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 12)
    ossPrivateSetMoreFlags(world, 13, _privateFlags);
#endif /* OSS_SPARTAN_AWARE >= 12 */
#endif /* OSS_SPARTAN_AWARE */
    ossLinkBer(world);
#if !defined(OSS_SPARTAN_AWARE) || ((OSS_SPARTAN_AWARE + 0) < 8)
    ossLinkConstraint(world);
#else  /* OSS_SPARTAN_AWARE < 8 */
    ossLinkConstraintSpartanAware8(world);
#endif /* OSS_SPARTAN_AWARE < 8 */

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
    _oss_post_init(world);
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */
}

static unsigned int const _v0 = 0;
static unsigned int const _v2 = 0;

static unsigned int const _v11[2] = {1, 64};
static unsigned short const _v9[2] = {1, 128};
static unsigned int const _v5[2] = {1, 256};
static unsigned int const _v3[2] = {0, UINT_MAX};

static const unsigned short _pduarray[] = {
    1
};

static const struct etype _etypearray[] = {
    {-1, 0, 0, NULL, 0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 1, 3, (char *)"BBCard", 24, 4, 0, 0, 8, 0, 12, 0},
    {-1, 19, 0, NULL, 4, 0, 4, 0, 200, 0, 55, 0},
    {-1, 19, 0, NULL, 4, 0, 4, 0, 200, 0, 55, 2},
    {256, 21, 26, NULL, 8, 0, 4, 4, 216, 0, 25, 4},
    {-1, 1, 23, (char *)"CareerEntry", 20, 3, 1, 1, 8, 4, 12, 0},
    {64, 21, 26, NULL, 8, 0, 4, 4, 216, 0, 25, 7},
    {-1, 19, 0, NULL, 2, 65536, 2, 0, 200, 0, 55, 10},
    {64, 21, 26, NULL, 8, 0, 4, 4, 216, 0, 25, 12},
    {-1, 1, 0, (char *)"_seqof1", 4, 20, 4, 4, 40, 5, 18, 0}
};

static const struct ConstraintEntry _econstraintarray[] = {
    {5, 15, (void *)&_v0},
    {0, 3, (void *)_v3},
    {5, 15, (void *)&_v2},
    {0, 3, (void *)_v3},
    {5, 14, (void *)_v5},
    {0, 6, (char *)NULL + 6},
    {0, 3, (void *)_v5},
    {5, 14, (void *)_v11},
    {0, 6, (char *)NULL + 9},
    {0, 3, (void *)_v11},
    {5, 14, (void *)_v9},
    {0, 3, (void *)_v9},
    {5, 14, (void *)_v11},
    {0, 6, (char *)NULL + 14},
    {0, 3, (void *)_v11}
};

static const struct efield _efieldarray[] = {
    {0, 6, -1, 0, 2},
    {8, 7, -1, 1, 2},
    {12, 8, -1, 2, 2},
    {20, 9, -1, 3, 2},
    {4, 2, -1, 4, 2},
    {8, 3, 0, 5, 3},
    {12, 4, -1, 6, 2}
};

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) > 12)
typedef struct ExtParms {
    int           versId;
    const void    *xparm[7];
} ExtParms;
static ExtParms const extParms = {
    31,
    {NULL, NULL, NULL, NULL, NULL, NULL, (char *)NULL + 4}
};
#endif /* OSS_SPARTAN_AWARE  > 12 */
#endif /* OSS_SPARTAN_AWARE */

static void * const _enamearray[] = {
    (void *)"name",
    (void *)"age",
    (void *)"position",
    (void *)"career",
    (void *)"from",
    (void *)"to",
    (void *)"team"
};

static const Etag _tagarray[] = {
    0, 1, 0x0010, 7, 10, 13, 16, 1, 0x001a, 1,
    1, 0x0002, 2, 1, 0x001a, 3, 1, 0x0010, 4, 1,
    0x0002, 1, 0x001a, 26, 29, 34, 1, 0x0002, 1, 2,
    0x0002, 2, 0x001a, 3, 1, 0x001a, 3, 1, 0x0010, 1
};


#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
static void _oss_post_init(struct ossGlobal *world) {
    static const unsigned char _oss_typeinfo[] = {
        0x00, 0x4e, 0x34, 0x19, 0x72, 0x74, 0x33, 0x1e, 0x44, 0xf2,
        0xab, 0x1c, 0x44, 0xf1, 0xab, 0x93, 0xdf, 0x3c, 0xd5, 0xbe,
        0xf5, 0x68, 0xa6, 0x65, 0x78, 0xf7, 0xe1, 0x74, 0x4d, 0x47,
        0xc8, 0x4a, 0x65, 0x63, 0xc0, 0xf2, 0xb2, 0xfc, 0xe5, 0x53,
        0x12, 0xd8, 0x9a, 0x7a, 0xfc, 0x48, 0xee, 0xd9, 0x17, 0xba,
        0xd3, 0xab, 0xe1, 0xc6, 0x03, 0x92, 0x49, 0xc6, 0xd4, 0x44,
        0x7c, 0x72, 0xf8, 0x7a, 0x52, 0xfa, 0xc7, 0xc4, 0x2b, 0x7a,
        0x7d, 0x51, 0x12, 0x41, 0x99, 0x7a, 0x95, 0x69, 0x87, 0x54
    };
    ossInitRootContext1(world, (unsigned char *)_oss_typeinfo);
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) > 12)
    ossSetExtParms(world, (void *)&extParms);
#endif /* OSS_SPARTAN_AWARE  > 12 */
#endif /* OSS_SPARTAN_AWARE */
}
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */

static const struct eheader _head = {_ossinit_bcas, 37, 115, 2837, 1, 10,
    (unsigned short *)_pduarray, (struct etype *)_etypearray,
    (struct efield *)_efieldarray, (void **)_enamearray, (Etag *)_tagarray,
    (struct ConstraintEntry *)_econstraintarray, NULL, NULL, 0, NULL, 0};

void *bcas_TableType::internal = (void *)&_head;
