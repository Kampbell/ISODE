/*
 * Logger.cpp
 *
 *  Created on=1 août 2014
 *      Author=FrancisANDRE
 */

#include "als/tsap/Literal.h"
#include "als/tsap/prov/Logger.h"

using namespace ALS::TSAP;
static const string TConnectRequest(Literal::T_CONNECT_REQUEST);
static const string TConnectResponse(Literal::T_CONNECT_RESPONSE);
static const string TConnectIndication(Literal::T_CONNECT_INDICATION);
static const string TConnectConfirmation(Literal::T_CONNECT_CONFIRMATION);
static const string TDataRequest(Literal::T_DATA_REQUEST);
static const string TDataIndication(Literal::T_DATA_INDICATION);
static const string TExpeditedDataRequest(Literal::T_EXPEDITED_DATA_REQUEST);
static const string TExpeditedDataIndication(Literal::T_EXPEDITED_DATA_INDICATION);
static const string TDisconnectRequest(Literal::T_DISCONNECT_REQUEST);
static const string TDisconnectIndication(Literal::T_DISCONNECT_INDICATION);

namespace ALS {
namespace TSAP {
namespace PROV {

ReturnCode Logger::TConnectRequest(const TSAPAddr& calling, const TSAPAddr& called, bool expedited, const QualityOfService& qualityOfService, int cc, const byte* data){
	const string& callingAddrAsString = calling.to_string();
	const string& calledAddrAsString = called.to_string();
	trace(prefix + "calling=%s, called=%s, expedited=%b, cc=%?d", REQUEST, ::TConnectRequest, callingAddrAsString, calledAddrAsString, expedited, cc);
	return OK;
}
ReturnCode Logger::TConnectResponse(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int cc, const byte* data){
	const string&  respondingAddrAsString = respondingAddr.to_string();
	trace(prefix + "responding=%s, expedited=%b, cc=%?d", RESPONSE, ::TConnectResponse, respondingAddrAsString, expedited, cc);
	return OK;
}
ReturnCode Logger::TConnectIndication(const TSAPAddr& callingAddr, const TSAPAddr& calledAddr, bool expedited, int tsdusize, const QualityOfService& qualityOfService, int cc, const byte* data){
	const string&  callingAddrAsString = callingAddr.to_string();
	const string&  calledAddrAsString = calledAddr.to_string();
	trace(prefix + "calling=%s, called=%s, expedited=%b, tsdusize=%?d, cc=%?d", INDICATION, ::TConnectIndication, callingAddrAsString, calledAddrAsString, expedited, tsdusize, cc);
	return DONE;
}
ReturnCode Logger::TConnectConfirmation(const TSAPAddr& respondingAddr, bool expedited, const QualityOfService& qualityOfService, int tsdusize, NetworkBuffer* data){
	const string&  respondingAddrAsString = respondingAddr.to_string();
	trace(prefix + "responding=%s, expedited=%b, tsdusize=%?d, cc=%?d", CONFIRMATION, ::TConnectConfirmation, respondingAddrAsString, expedited, tsdusize, data ? data->remaining() : 0);
	return DONE;
}
ReturnCode Logger::TDataRequest(NetworkBuffer* tsdu){
	trace(prefix + "cc=%?u", REQUEST, ::TDataRequest, tsdu ? tsdu->remaining() : 0);
	return OK;
}
ReturnCode Logger::TDataRequest(int cc, const byte* data) {
	trace(prefix + "cc=%?d", REQUEST, ::TDataRequest, cc);
	return OK;
}
ReturnCode Logger::TDataIndication(const SharedNetworkBuffer& tsdu){
	trace(prefix + "cc=%?u", INDICATION, ::TDataIndication, tsdu ? tsdu.total() : 0);
	return DONE;
}
ReturnCode Logger::TExpeditedDataRequest(int cc, const byte* data) {
	trace(prefix + "cc=%?d", REQUEST, ::TExpeditedDataRequest, cc);
	return OK;
}
ReturnCode Logger::TExpeditedDataIndication(const SharedNetworkBuffer& tsdu) {
	trace(prefix + "cc=%?u", INDICATION, ::TExpeditedDataIndication, tsdu ? tsdu.total() : 0);
	return OK;
}
ReturnCode Logger::TDisconnectRequest(int reason, const TSAPAddr& responding, int cc, const byte* data){
	trace(prefix + "reason=%?d, cc=%?d", REQUEST, ::TDisconnectRequest, reason, cc);
	return OK;
}
ReturnCode Logger::TDisconnectIndication(int reason, const string& data){
	trace(prefix + "reason=%?d, data=%s", INDICATION, ::TDisconnectIndication, reason, data);
	return DONE;
}
ReturnCode Logger::TSetSSAPServices(const ALS::BASE::SRVC::SSAPServices* ssapServices) {
	return OK;
}

}
}
}
