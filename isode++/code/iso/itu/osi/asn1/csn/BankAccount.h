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
/* Abstract syntax: Remote_Operations_Useful_Definitions */
/* Created: Wed Dec 24 13:30:20 2014 */
/* ASN.1/C++ compiler version: 6.0 */
/* Code generated for runtime version 6.0 or later */
/* Compiler operating system: Windows */
/* Compiler machine type: Intel x86 */
/* Target operating system: Windows */
/* Target machine type: Intel x86 */
/* C++ compiler options required: -Zp8 (Microsoft) */
/* ASN.1 compiler options and file names specified:
 * -output Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/csn\BankAccount
 * -modlistingfile
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/csn\BankAccount.lst
 * -gendirectives
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/csn\BankAccount.gen -2008 -per
 * -ber -der -root -messageFormat msvc -namespace BankAccount
 * -allow universaltags
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/BankAccount.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Information-Objects.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Generic-ROS-PDUs.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Realizations.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Abstract-Syntaxes.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Information-Objects-extensions.asn
 * Z:/git/ISO.ITU.OSI/cpp/src/iso/itu/osi/asn1/asn/Remote-Operations-Useful-Definitions.asn
 */

#ifndef OSS_Remote_Operations_Useful_Definitions
#define OSS_Remote_Operations_Useful_Definitions

#include "oss.h"
#include "asn1.h"

namespace BankAccount {

/* Representation types */

enum _enum1 {
    association_service = 0,
    transfer_service = 1
};


const OSS_INT32 inappropriateAuthentication = 1;
const OSS_INT32 invalidCredentials = 2;
const OSS_INT32 insufficientAccessRights = 3;
const OSS_INT32 invalidSignature = 4;
const OSS_INT32 protectionRequired = 5;
const OSS_INT32 noInformation = 6;
const OSS_INT32 blockedCredentials = 7;
const OSS_INT32 invalidQOPMatch = 8;
const OSS_INT32 spkmError = 9;

const OSS_INT32 unrecognizedPDU = 0;
const OSS_INT32 mistypedPDU = 1;
const OSS_INT32 badlyStructuredPDU = 2;

const OSS_INT32 duplicateInvocation = 0;
const OSS_INT32 unrecognizedOperation = 1;
const OSS_INT32 mistypedArgument = 2;
const OSS_INT32 resourceLimitation = 3;
const OSS_INT32 releaseInProgress = 4;
const OSS_INT32 unrecognizedLinkedId = 5;
const OSS_INT32 linkedResponseUnexpected = 6;
const OSS_INT32 unexpectedLinkedOperation = 7;

const OSS_INT32 ReturnResultProblem_unrecognizedInvocation = 0;
const OSS_INT32 resultResponseUnexpected = 1;
const OSS_INT32 mistypedResult = 2;

const OSS_INT32 ReturnErrorProblem_unrecognizedInvocation = 0;
const OSS_INT32 errorResponseUnexpected = 1;
const OSS_INT32 unrecognizedError = 2;
const OSS_INT32 unexpectedError = 3;
const OSS_INT32 mistypedParameter = 4;

const OSS_INT32 localSystemProblem = 0;
const OSS_INT32 invalidParameter = 1;
const OSS_INT32 unrecognizedActivity = 2;
const OSS_INT32 temporaryProblem = 3;
const OSS_INT32 protocolError = 4;
const OSS_INT32 permanentProblem = 5;
const OSS_INT32 userError = 6;
const OSS_INT32 transferCompleted = 7;
typedef OSS_INT32 AccountBindArgument;

class OSS_PUBLIC __shared2   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OssString name;
    typedef OSS_INT32 code;

    __shared2();
    __shared2(const __shared2 &);
    __shared2(const name &, code);

    __shared2 & operator = (const __shared2 &);
    int operator == (const __shared2 &) const;
    int operator != (const __shared2 &) const;

    name & get_name();
    const name & get_name() const;
    void set_name(const name &);

    code & get_code();
    code get_code() const;
    void set_code(code);
private:
    name name_field;
    code code_field;
};

typedef __shared2 Bank;

typedef __shared2 AccountBindResult;

class OSS_PUBLIC __shared3  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	present_chosen = 1,
	absent_chosen = 2
    };
    typedef OSS_INT32 present;
    typedef Nulltype absent;

    __shared3();
    __shared3(const __shared3 &);

    __shared3 & operator = (const __shared3 &);
    int operator == (const __shared3 &) const;
    int operator != (const __shared3 &) const;

    present *get_present();
    const present *get_present() const;
    void set_present(present);

    absent *get_absent();
    const absent *get_absent() const;
    void set_absent(absent);
private:
    union {
	present present_field;
	absent absent_field;
    };
};

typedef __shared3 InvokeId;

typedef __shared3 BA_InvokeIDSet;

typedef OSS_INT32 Teller;

typedef OSS_INT32 AccountId;

typedef OSS_INT32 Account;

typedef OSS_INT32 Amount;

typedef OSS_INT32 Result;

class OSS_PUBLIC __shared4   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 account;
    typedef OSS_INT32 amount;

    __shared4();
    __shared4(const __shared4 &);
    __shared4(account, amount);

    __shared4 & operator = (const __shared4 &);
    int operator == (const __shared4 &) const;
    int operator != (const __shared4 &) const;

    account & get_account();
    account get_account() const;
    void set_account(account);

    amount & get_amount();
    amount get_amount() const;
    void set_amount(amount);
private:
    account account_field;
    amount amount_field;
};

typedef __shared4 OperationArgument;

typedef __shared4 Deposit;

typedef __shared4 Withdraw;

class OSS_PUBLIC Decimal   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 mantisse;
    typedef OSS_INT32 decimal;

    Decimal();
    Decimal(const Decimal &);
    Decimal(mantisse, decimal);

    Decimal & operator = (const Decimal &);
    int operator == (const Decimal &) const;
    int operator != (const Decimal &) const;

    mantisse & get_mantisse();
    mantisse get_mantisse() const;
    void set_mantisse(mantisse);

    decimal & get_decimal();
    decimal get_decimal() const;
    void set_decimal(decimal);
private:
    mantisse mantisse_field;
    decimal decimal_field;
};

typedef OSS_INT32 SecurityProblem;

typedef OSS_UINT32 Priority;

class OSS_PUBLIC Code  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	local_chosen = 1,
	global_chosen = 2
    };
    typedef OSS_INT32 local;
    typedef OssEncOID global;

    Code();
    Code(const Code &);
    ~Code();

    Code & operator = (const Code &);
    int operator == (const Code &) const;
    int operator != (const Code &) const;

    local *get_local();
    const local *get_local() const;
    void set_local(local);

    global *get_global();
    const global *get_global() const;
    void set_global(const global &);
private:
    union {
	local local_field;
	OSSC::COssEncOID global_field;
    };
    void cleanup();
};

typedef OSS_INT32 GeneralProblem;

typedef OSS_INT32 InvokeProblem;

typedef OSS_INT32 ReturnResultProblem;

typedef OSS_INT32 ReturnErrorProblem;

class OSS_PUBLIC __choice1  : public OssChoice   /* CHOICE */
{
public:
    enum Id {
	unselected,
	general_chosen = 1,
	invoke_chosen = 2,
	returnResult_chosen = 3,
	returnError_chosen = 4
    };
    typedef OSS_INT32 general;
    typedef OSS_INT32 invoke;
    typedef OSS_INT32 returnResult;
    typedef OSS_INT32 returnError;

    __choice1();
    __choice1(const __choice1 &);

    __choice1 & operator = (const __choice1 &);
    int operator == (const __choice1 &) const;
    int operator != (const __choice1 &) const;

    general *get_general();
    const general *get_general() const;
    void set_general(general);

    invoke *get_invoke();
    const invoke *get_invoke() const;
    void set_invoke(invoke);

    returnResult *get_returnResult();
    const returnResult *get_returnResult() const;
    void set_returnResult(returnResult);

    returnError *get_returnError();
    const returnError *get_returnError() const;
    void set_returnError(returnError);
private:
    union {
	general general_field;
	invoke invoke_field;
	returnResult returnResult_field;
	returnError returnError_field;
    };
};

class OSS_PUBLIC Reject   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef __shared3 invokeId;
    typedef __choice1 problem;

    Reject();
    Reject(const Reject &);
    Reject(const invokeId &, const problem &);

    Reject & operator = (const Reject &);
    int operator == (const Reject &) const;
    int operator != (const Reject &) const;

    invokeId & get_invokeId();
    const invokeId & get_invokeId() const;
    void set_invokeId(const invokeId &);

    problem & get_problem();
    const problem & get_problem() const;
    void set_problem(const problem &);
private:
    invokeId invokeId_field;
    problem problem_field;
};

typedef __shared3 NoInvokeId;

class OSS_PUBLIC __shared5   /* SEQUENCE */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef enum _enum1 realization_type;
    typedef ossBoolean concatenation;

    static const concatenation default_concatenation;

    static concatenation get_default_concatenation();

    __shared5();
    __shared5(const __shared5 &);
    __shared5(realization_type, concatenation);
    __shared5(realization_type);

    __shared5 & operator = (const __shared5 &);
    int operator == (const __shared5 &) const;
    int operator != (const __shared5 &) const;

    realization_type & get_realization_type();
    realization_type get_realization_type() const;
    void set_realization_type(realization_type);

    concatenation *get_concatenation();
    const concatenation *get_concatenation() const;
    void set_concatenation(concatenation);
    int concatenation_is_default() const;
    void set_default_concatenation();
private:
    OSS_UINT32 bit_mask;
    realization_type realization_type_field;
    concatenation concatenation_field;
};

typedef __shared5 RealizationParameter;

typedef OSS_INT32 RTTPapdu;

typedef OssString RTTRapdu;

typedef OSS_INT32 AbortReason;

class OSS_PUBLIC RTABapdu   /* SET */
{
public:
    void * operator new(size_t size);
    void operator delete(void *ptr);

    typedef OSS_INT32 abortReason;
    typedef OssBitString reflectedParameter;
    typedef OssOpen userdataAB;

    RTABapdu();
    RTABapdu(const RTABapdu &);
    RTABapdu(abortReason, const reflectedParameter &, const userdataAB &);

    RTABapdu & operator = (const RTABapdu &);
    int operator == (const RTABapdu &) const;
    int operator != (const RTABapdu &) const;

    abortReason *get_abortReason();
    const abortReason *get_abortReason() const;
    void set_abortReason(abortReason);
    int abortReason_is_present() const;
    void omit_abortReason();

    reflectedParameter *get_reflectedParameter();
    const reflectedParameter *get_reflectedParameter() const;
    void set_reflectedParameter(const reflectedParameter &);
    int reflectedParameter_is_present() const;
    void omit_reflectedParameter();

    userdataAB *get_userdataAB();
    const userdataAB *get_userdataAB() const;
    void set_userdataAB(const userdataAB &);
    int userdataAB_is_present() const;
    void omit_userdataAB();
private:
    OSS_UINT32 bit_mask;
    abortReason abortReason_field;
    reflectedParameter reflectedParameter_field;
    userdataAB userdataAB_field;
};

typedef __shared3 ROSEInvokeIds;

typedef __shared5 Acse_RealizationParameter;

typedef __shared5 Acse_with_concatenation_RealizationParameter;

typedef __shared5 Association_by_RTSE_RealizationParameter;

typedef __shared5 PData_RealizationParameter;

typedef __shared5 PData_with_concatenation_RealizationParameter;

typedef __shared5 Transfer_by_RTSE_RealizationParameter;

/* Universal PDU class */

class OSS_PUBLIC Remote_Operations_Useful_Definitions_PDU : public UniversalPDU {
public:
    Remote_Operations_Useful_Definitions_PDU();
    void set_Teller(Teller &);
    Teller *get_Teller() const;
    void set_Decimal(Decimal &);
    Decimal *get_Decimal() const;
    void set_SecurityProblem(SecurityProblem &);
    SecurityProblem *get_SecurityProblem() const;
    void set_NoInvokeId(NoInvokeId &);
    NoInvokeId *get_NoInvokeId() const;
    void set_ROSEInvokeIds(ROSEInvokeIds &);
    ROSEInvokeIds *get_ROSEInvokeIds() const;
    void set_Acse_RealizationParameter(Acse_RealizationParameter &);
    Acse_RealizationParameter *get_Acse_RealizationParameter() const;
    void set_Acse_with_concatenation_RealizationParameter(Acse_with_concatenation_RealizationParameter &);
    Acse_with_concatenation_RealizationParameter *get_Acse_with_concatenation_RealizationParameter() const;
    void set_Association_by_RTSE_RealizationParameter(Association_by_RTSE_RealizationParameter &);
    Association_by_RTSE_RealizationParameter *get_Association_by_RTSE_RealizationParameter() const;
    void set_PData_RealizationParameter(PData_RealizationParameter &);
    PData_RealizationParameter *get_PData_RealizationParameter() const;
    void set_PData_with_concatenation_RealizationParameter(PData_with_concatenation_RealizationParameter &);
    PData_with_concatenation_RealizationParameter *get_PData_with_concatenation_RealizationParameter() const;
    void set_Transfer_by_RTSE_RealizationParameter(Transfer_by_RTSE_RealizationParameter &);
    Transfer_by_RTSE_RealizationParameter *get_Transfer_by_RTSE_RealizationParameter() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_Teller(const Teller &);
    const Teller *get_const_Teller() const;
    void set_const_Decimal(const Decimal &);
    const Decimal *get_const_Decimal() const;
    void set_const_SecurityProblem(const SecurityProblem &);
    const SecurityProblem *get_const_SecurityProblem() const;
    void set_const_NoInvokeId(const NoInvokeId &);
    const NoInvokeId *get_const_NoInvokeId() const;
    void set_const_ROSEInvokeIds(const ROSEInvokeIds &);
    const ROSEInvokeIds *get_const_ROSEInvokeIds() const;
    void set_const_Acse_RealizationParameter(const Acse_RealizationParameter &);
    const Acse_RealizationParameter *get_const_Acse_RealizationParameter() const;
    void set_const_Acse_with_concatenation_RealizationParameter(const Acse_with_concatenation_RealizationParameter &);
    const Acse_with_concatenation_RealizationParameter *get_const_Acse_with_concatenation_RealizationParameter() const;
    void set_const_Association_by_RTSE_RealizationParameter(const Association_by_RTSE_RealizationParameter &);
    const Association_by_RTSE_RealizationParameter *get_const_Association_by_RTSE_RealizationParameter() const;
    void set_const_PData_RealizationParameter(const PData_RealizationParameter &);
    const PData_RealizationParameter *get_const_PData_RealizationParameter() const;
    void set_const_PData_with_concatenation_RealizationParameter(const PData_with_concatenation_RealizationParameter &);
    const PData_with_concatenation_RealizationParameter *get_const_PData_with_concatenation_RealizationParameter() const;
    void set_const_Transfer_by_RTSE_RealizationParameter(const Transfer_by_RTSE_RealizationParameter &);
    const Transfer_by_RTSE_RealizationParameter *get_const_Transfer_by_RTSE_RealizationParameter() const;
#endif
};

/* Specific PDU classes */

class OSS_PUBLIC Teller_PDU : public ConcretePDU {
public:
    Teller_PDU();
    void set_data(Teller &);
    Teller *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Teller & d);
    const Teller *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Decimal_PDU : public ConcretePDU {
public:
    Decimal_PDU();
    void set_data(Decimal &);
    Decimal *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Decimal & d);
    const Decimal *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC SecurityProblem_PDU : public ConcretePDU {
public:
    SecurityProblem_PDU();
    void set_data(SecurityProblem &);
    SecurityProblem *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const SecurityProblem & d);
    const SecurityProblem *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC NoInvokeId_PDU : public ConcretePDU {
public:
    NoInvokeId_PDU();
    void set_data(NoInvokeId &);
    NoInvokeId *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const NoInvokeId & d);
    const NoInvokeId *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC ROSEInvokeIds_PDU : public ConcretePDU {
public:
    ROSEInvokeIds_PDU();
    void set_data(ROSEInvokeIds &);
    ROSEInvokeIds *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const ROSEInvokeIds & d);
    const ROSEInvokeIds *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Acse_RealizationParameter_PDU : public ConcretePDU {
public:
    Acse_RealizationParameter_PDU();
    void set_data(Acse_RealizationParameter &);
    Acse_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Acse_RealizationParameter & d);
    const Acse_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Acse_with_concatenation_RealizationParameter_PDU : public ConcretePDU {
public:
    Acse_with_concatenation_RealizationParameter_PDU();
    void set_data(Acse_with_concatenation_RealizationParameter &);
    Acse_with_concatenation_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Acse_with_concatenation_RealizationParameter & d);
    const Acse_with_concatenation_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Association_by_RTSE_RealizationParameter_PDU : public ConcretePDU {
public:
    Association_by_RTSE_RealizationParameter_PDU();
    void set_data(Association_by_RTSE_RealizationParameter &);
    Association_by_RTSE_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Association_by_RTSE_RealizationParameter & d);
    const Association_by_RTSE_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PData_RealizationParameter_PDU : public ConcretePDU {
public:
    PData_RealizationParameter_PDU();
    void set_data(PData_RealizationParameter &);
    PData_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PData_RealizationParameter & d);
    const PData_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC PData_with_concatenation_RealizationParameter_PDU : public ConcretePDU {
public:
    PData_with_concatenation_RealizationParameter_PDU();
    void set_data(PData_with_concatenation_RealizationParameter &);
    PData_with_concatenation_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const PData_with_concatenation_RealizationParameter & d);
    const PData_with_concatenation_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

class OSS_PUBLIC Transfer_by_RTSE_RealizationParameter_PDU : public ConcretePDU {
public:
    Transfer_by_RTSE_RealizationParameter_PDU();
    void set_data(Transfer_by_RTSE_RealizationParameter &);
    Transfer_by_RTSE_RealizationParameter *get_data() const;
#ifdef OSS_PREALLOCATED_BUFFER_DECODE_SUPPORTED
    void set_const_data(const Transfer_by_RTSE_RealizationParameter & d);
    const Transfer_by_RTSE_RealizationParameter *get_const_data() const;
#endif
protected:
    OssTypeIndex get_index() const;
};

/* Control object class */

class OSS_PUBLIC Remote_Operations_Useful_Definitions_Control : public OssControl {
public:
    Remote_Operations_Useful_Definitions_Control();
    Remote_Operations_Useful_Definitions_Control(const Remote_Operations_Useful_Definitions_Control &);
};


/* External definitions for named values */

extern OSS_PUBLIC const Code& id_opcode_deposit;

extern OSS_PUBLIC const Code& id_opcode_withdraw;

extern OSS_PUBLIC const Code& id_opcode_open;

extern OSS_PUBLIC const Code& id_opcode_close;

extern OSS_PUBLIC const Code& id_opcode_create;

extern OSS_PUBLIC const Code& id_opcode_delete;

extern OSS_PUBLIC const Code& id_errcode_securityError;

extern OSS_PUBLIC const Code& id_errcode_attributeError;

extern OSS_PUBLIC const Code& id_errcode_nameError;

extern OSS_PUBLIC const Code& id_errcode_serviceError;

extern OSS_PUBLIC const Code& id_errcode_referral;

extern OSS_PUBLIC const Code& id_errcode_abandoned;

extern OSS_PUBLIC const Code& id_errcode_abandonFailed;

extern OSS_PUBLIC const Code& id_errcode_updateError;

extern OSS_PUBLIC const Code& id_errcode_dsaReferral;

extern OSS_PUBLIC const OssEncOID& id_rosObject_ba;

extern OSS_PUBLIC const OssEncOID& id_contract_dap;

extern OSS_PUBLIC const OssEncOID& id_ac_bankAccountAC;

extern OSS_PUBLIC const OssEncOID& id_package_baConnection;

extern OSS_PUBLIC const OssEncOID& id_package_create;

extern OSS_PUBLIC const OssEncOID& id_package_open;

extern OSS_PUBLIC const OssEncOID& id_package_modify;

extern OSS_PUBLIC const OssEncOID& id_as_bankAccountAS;

extern OSS_PUBLIC const __shared3& noInvokeId;

} // namespace BankAccount

#endif // OSS_Remote_Operations_Useful_Definitions
