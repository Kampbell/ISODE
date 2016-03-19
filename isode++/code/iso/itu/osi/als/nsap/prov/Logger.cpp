/*
 * Logger.cpp
 *
 *  Created on: 17 août 2014
 *      Author: FrancisANDRE
 */
#include "Poco/NumberFormatter.h"
using Poco::NumberFormatter;

#include "als/base/util/NetworkBuffer.h"


#include "als/nsap/Literal.h"
#include "als/nsap/prov/Logger.h"


using namespace ALS::NSAP;
static const string NConnectRequest(Literal::N_CONNECT_REQUEST);
static const string NConnectResponse(Literal::N_CONNECT_RESPONSE);
static const string NConnectIndication(Literal::N_CONNECT_INDICATION);
static const string NConnectConfirmation(Literal::N_CONNECT_CONFIRMATION);
static const string NDataRequest(Literal::N_DATA_REQUEST); 
static const string NDataIndication(Literal::N_DATA_INDICATION);
static const string NDataAcknoledgeRequest(Literal::N_DATA_ACKNOWLEDGE_REQUEST);
static const string NExpeditedDataRequest(Literal::N_EXPEDITED_DATA_REQUEST);
static const string NResetRequest(Literal::N_RESET_REQUEST);
static const string NResetResponse(Literal::N_RESET_RESPONSE);
static const string NResetIndication(Literal::N_RESET_INDICATION);
static const string NResetConfirmation(Literal::N_RESET_CONFIRMATION);
static const string NDisconnectRequest(Literal::N_DISCONNECT_REQUEST);
static const string NDisconnectIndication(Literal::N_DISCONNECT_INDICATION);

namespace ALS {
namespace NSAP {
namespace PROV {
void Logger::dump(const void* buffer, std::size_t length, Message::Priority prio) {
	if (getLevel() > prio)
		return;
	const int BYTES_PER_LINE = 16;
	string message;
	message.reserve(4 + (BYTES_PER_LINE * 3) + (BYTES_PER_LINE * 2) + 2 + 16);
	if (!message.empty()) message.append("\n");
	unsigned char* base = (unsigned char*)buffer;
	int addr = 0;
	while (addr < length)
	{
		message.append(NumberFormatter::formatHex(addr, 4));
		message.append("  ");
		int offset = 0;
		while (addr + offset < length && offset < BYTES_PER_LINE) {
			message.append(NumberFormatter::formatHex(base[addr + offset], 2));
			message.append(offset == 7 ? "  " : " ");
			++offset;
		}
		if (offset < 7) message.append(" "); 
		while (offset < BYTES_PER_LINE) { message.append("   "); ++offset; }
		message.append(" ");
		offset = 0;
		while (addr + offset < length && offset < BYTES_PER_LINE) {
			unsigned char c = base[addr + offset];
			message += (c >= ' ' && c < 127) ? (char)c : '.';
			++offset;
		}
		debug(message);
		message.clear();
		addr += BYTES_PER_LINE;
	}
}

ReturnCode Logger::NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	const string& callingAsString = calling.to_string();
	const string& calledAsString = called.to_string();
	trace(prefix + "calling=%?s, called=%?s, cc=%?u", REQUEST, ::NConnectRequest, callingAsString, calledAsString, cc);
	return OK;
}
ReturnCode Logger::NConnectResponse(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	const string& respondingAsString = responding.to_string();
	trace(prefix + "responding=%?s, cc=%?u", RESPONSE, ::NConnectResponse, respondingAsString, cc);
	return OK;
}
ReturnCode Logger::NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	trace(prefix, CONFIRMATION, ::NConnectConfirmation);
	return DONE;
}
ReturnCode Logger::NConnectIndication(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	trace(prefix, INDICATION, ::NConnectIndication);
	return DONE;
}
ReturnCode Logger::NDataRequest(NetworkBuffer* nsdu, bool confirmation) {
	poco_check_ptr(nsdu);
	trace(prefix + "cc=%?u", REQUEST, ::NDataRequest, nsdu ? nsdu->remaining() : 0);
	dump(nsdu->bytes(), nsdu->remaining());
	return OK;
}
ReturnCode Logger::NDataRequest(int cc, byte* data, bool confirmation) {
	poco_check_ptr(data);
	trace(prefix + "cc=%?d", REQUEST, ::NDataRequest, cc);
	dump(data, cc);
	return OK;
}
ReturnCode Logger::NDataIndication(const SharedNetworkBuffer& nsdu) {
	trace(prefix + "cc=%?u", INDICATION, ::NDataIndication, nsdu ? nsdu.total() : 0);
	dump(nsdu->bytes(), nsdu->remaining());
	return DONE;
}
ReturnCode Logger::NDataAcknoledgeRequest(){
	trace(prefix, REQUEST, ::NDataAcknoledgeRequest);
	return OK;
}
ReturnCode Logger::NExpeditedDataRequest(int cc, const byte* data){
	trace(prefix + "cc=%?d", REQUEST, ::NExpeditedDataRequest, cc);
	return OK;
}

ReturnCode Logger::NResetRequest(int reason){
	trace(prefix + "reason=%?d", REQUEST, ::NResetRequest, reason);
	return OK;
}
ReturnCode Logger::NResetResponse(){
	trace(prefix, RESPONSE, ::NResetResponse);
	return OK;
}
ReturnCode Logger::NResetIndication(const NSAPAddr& originator, int reason) {
	trace(prefix + "reason=%?d", INDICATION, ::NResetIndication, reason);
	return DONE;
}
ReturnCode Logger::NResetConfirmation() {
	trace(prefix, INDICATION, ::NResetConfirmation);
	return DONE;
}
ReturnCode Logger::NDisconnectRequest(int reason, const NSAPAddr& responding, int cc, const byte* buffer){
	const string& respondingAsString = responding.to_string();
	trace(prefix + "responding=%?s, reason=%?d, cc=%?d", REQUEST, ::NDisconnectRequest, respondingAsString, reason, cc);
	return OK;
}
ReturnCode Logger::NDisconnectIndication() {
	trace(prefix, INDICATION, ::NDisconnectIndication);
	return DONE;
}

}
}
}
