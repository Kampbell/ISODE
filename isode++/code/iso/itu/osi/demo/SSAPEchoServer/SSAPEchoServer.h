/*
 * SSAPEchoServer.h
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#ifndef SSAP_ECHO_SERVER_H_
#define SSAP_ECHO_SERVER_H_
#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SSAP_ECHO_SERVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SSAP_ECHO_SERVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(SSAP_ECHO_SERVER_EXPORTS)
		#define SSAP_ECHO_SERVER_API __declspec(dllexport)
	#else
		#define SSAP_ECHO_SERVER_API __declspec(dllimport)
	#endif
#endif


#if !defined(SSAP_ECHO_SERVER_API)
	#define SSAP_ECHO_SERVER_API
#endif

//
// Automatically link SSAP_ECHO_SERVER library.
//
#if defined(_MSC_VER)
	#if !defined(ALS_NO_AUTOMATIC_LIBS) && !defined(SSAP_ECHO_SERVER_EXPORTS)
		#pragma comment(lib, "SSAPEchoServer" ALS_LIB_SUFFIX)
	#endif
#endif

#include "als/base/util/Bits.h"
using ALS::BASE::UTIL::Bits;
#include "als/base/util/NetworkBuffer.h"

#include "als/ssap/user/Linker.h"
#include "als/ssap/user/Initiator.h"
#include "als/ssap/user/Responder.h"

#include "als/ssap/ActivityId.h"
using ALS::SSAP::ActivityId;
#include "als/ssap/Requirement.h"
using ALS::SSAP::Requirement;
#include "als/ssap/Token.h"
using ALS::SSAP::Token;
#include "als/ssap/SSN.h"
using ALS::SSAP::SSN;

namespace ALS {
namespace SSAP {
enum Mode {
	echo,
	sink
};

class SSAP_ECHO_SERVER_API SSAPEchoServer : 
	public USER::Linker,
	public USER::Responder,
	public Token{
private:
	SERV::Responder*	ssap_serv_responder = nullptr;
	SSAPAddr			responding;
	QualityOfService	qualityOfService;
	Requirement			requirements;
	Bits				owned = 0;
	Bits				avail = 0;
	ActivityId			activityId;
	SharedNetworkBuffer		hx;
	Mode				mode = echo;
	SSN					firstSSN;
	SSN					secondSSN;

	inline SERV::Responder&	ssap()  { return *ssap_serv_responder; }
public:
	SSAPEchoServer();
	virtual ~SSAPEchoServer();

	virtual USER::Initiator*	initiator() const;
	virtual SERV::Responder*&	provider();

	virtual ReturnCode SConnectIndication(const Reference& reference, //
		const SSAPAddr& calling, // the SSAP address of peer calling
		const SSAPAddr& called, // the SSAP address of peer called
		int result, // the result
		const QualityOfService& qualityOfService, // the quality of service
		const Requirement& requirements, // the session requirements
		SSN& firstInitialSSN, //the initial serial number
		SSN& secondInitialSSN, // the second initial serial number
		int settings, // the initial settings of tokens
		int ssdusize, // the largest atomic SSDU
		int cc = 0, const void* data = nullptr);


	ReturnCode SUAbortIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPAbortIndication(int reason, int extension, int cc = 0, const void* data = nullptr);


	ReturnCode SActivityDiscardIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityDiscardConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndIndication(const SSN& firstSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityEndConfirmation(int cc = 0, const void * data = nullptr);
	ReturnCode SActivityEndConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityInterruptConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SActivityResumeIndication(const ActivityId&  activityId, const ActivityId&  oldActivityId, const SSN& firstSSN, const SSN& secondSSN, const Reference& oldSessionReference, int cc = 0, const void* data = nullptr);
	ReturnCode SActivityStartIndication(const ActivityId&  activityId, int cc = 0, const void* data = nullptr);

	ReturnCode SDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataIndication(const SharedNetworkBuffer& data);
	ReturnCode SCapabilityDataConfirmation(const SharedNetworkBuffer& data);
	ReturnCode SExpeditedDataIndication(const SharedNetworkBuffer& data);
	ReturnCode STypedDataIndication(const SharedNetworkBuffer& dataL);

	ReturnCode SUExceptionReportIndication(int reason, int cc = 0, const void* data = nullptr);
	ReturnCode SPExceptionReportIndication(int reason);

	ReturnCode SResynchronizeIndication(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);
	ReturnCode SResynchronizeConfirmation(const ResyncOption& firstResync, const SSN& firstSSN, const ResyncOption& secondResync, const SSN& secondSSN, int settings, int cc = 0, const void* data = nullptr);

	ReturnCode SSyncMajorIndication(const SSN& firsSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMajorConfirmation(int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMajorConfirmation(const SSN& secondSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMinorIndication(const SyncOption& type, bool dataSeparation, const SSN& firstSSN, int cc = 0, const void* data = nullptr);
	ReturnCode SSyncMinorConfirmation(const SSN& firstSSN, int cc = 0, const void* data = nullptr);


	ReturnCode SControlGiveIndication( int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenGiveIndication(int tokens, int cc = 0, const void* data = nullptr);
	ReturnCode STokenPleaseIndication(int tokens, int cc = 0, const void* data = nullptr);

	ReturnCode SReleaseIndication(int cc = 0, const void* data = nullptr);
	ReturnCode SReleaseConfirmation(bool affirmative, int cc = 0, const void* data = nullptr);



private:
	ReturnCode adios(const char* what, const string& message) ;
	ReturnCode adios(const char* what, const char* message) ;
	ReturnCode ss_adios(const string& message) ;
	int i;
};

}
}

#endif
