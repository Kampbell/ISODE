/*
 * TSAPTestSuiteResponder.h
 *
 *  Created on: 2 août 2014
 *      Author: FrancisANDRE
 */

#ifndef TSAP_TEST_SUITE_RESPONDER_H_
#define TSAP_TEST_SUITE_RESPONDER_H_
#include "als/ALS.h"

//
// The following block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TSAP_ECHO_SERVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TSAP_ECHO_SERVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(ALS_DLL)
	#if defined(TSAP_TEST_SUITE_RESPONDER_EXPORTS)
		#define TSAP_TEST_SUITE_RESPONDER_API __declspec(dllexport)
	#else
		#define TSAP_TEST_SUITE_RESPONDER_API __declspec(dllimport)
	#endif
#endif


#if !defined(TSAP_TEST_SUITE_RESPONDER_API)
	#define TSAP_TEST_SUITE_RESPONDER_API
#endif

#include "als/tsap/user/Linker.h"
#include "als/tsap/user/Initiator.h"
#include "als/tsap/user/Responder.h"

namespace ALS {
namespace TSAP {

class TSAP_TEST_SUITE_RESPONDER_API TSAPTestSuiteResponder : 
	public USER::Linker,
	public USER::Responder {
private:
	PROV::Provider*		tsap_serv_provider;
	TSAPAddr			responding;
	QualityOfService	qualityOfService;

public:
	TSAPTestSuiteResponder();
	virtual ~TSAPTestSuiteResponder();

	virtual ReturnCode TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc = 0, const byte* data = nullptr);
	virtual ReturnCode TDataIndication(const SharedNetworkBuffer& data);
	virtual ReturnCode TExpeditedDataIndication(const SharedNetworkBuffer& data);
	virtual ReturnCode TDisconnectIndication(int reason, const string& data);
	virtual ReturnCode TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices) { return OK; }

	virtual USER::Initiator*	initiator() const;
	virtual PROV::Provider*&	provider();

private:
	int i;
};

}
}

#endif
