/*
 * NA_TCP_TS_TCP.cpp
 *
 *  Created on: 25 août 2014
 *      Author: FrancisANDRE
 */
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/NObserver.h"
#include "Poco/Exception.h"
#include "Poco/Thread.h"
using Poco::Net::IPAddress;
using Poco::Net::SocketAddress;
using Poco::NObserver;
using Poco::AutoPtr;
using Poco::Thread;

#include "als/base/util/SharedNetworkBuffer.h"
#include "als/nsap/prov/NA_TCP_TS_TCP.h"
using ALS::BASE::UTIL::SharedNetworkBuffer;

namespace ALS {
namespace NSAP {
namespace PROV {
	NA_TCP_TS_TCP::NA_TCP_TS_TCP(ALS::NSAP::USER::Initiator* initiator) : 
		initiator(initiator),
		rfc1006(socket) {
}
NA_TCP_TS_TCP::~NA_TCP_TS_TCP() {
#if 0
	// wait for CTRL-C or kill
	Application& app = Application::instance();
	ServerApplication* server = dynamic_cast<ServerApplication*>(&app);
	server->waitForTerminationRequest();
#endif
	// Stop the reading thread
	thread.join();
}
void NA_TCP_TS_TCP::run()
	{
		Thread* pThread = Thread::current();
		if (pThread)
			threadName = pThread->name();
		ran = true;
		for (;;) {
			NetworkBuffer* buffer = nullptr;
			int received = rfc1006.recv(buffer);
			if (received == 0) {
//				initiator->NDisconnectIndication();
				socket.shutdownReceive();
				return;
			}
			if (buffer == nullptr)
				return;
			SharedNetworkBuffer shared_buffer(buffer);
			initiator->NDataIndication(shared_buffer);
		}
	}

ReturnCode NA_TCP_TS_TCP::NConnectRequest(const NSAPAddr& calling, const NSAPAddr& called, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	IPAddress inetAddress(called.tcp_domain(), called.tcp_length());
	SocketAddress sa(inetAddress, called.tcp_port());
	//("localhost", port);
	socket.connect(sa);
	assert (!thread.isRunning());
	thread.start(*this);
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NConnectConfirmation(const NSAPAddr& responding, bool receiptConfirmationSelection, bool expeditedDataSelection, const QualityOfService& qualityOfService, const QualityOfServiceParameters& qosp, int cc, const byte* data) {
	return DONE;
}
ReturnCode NA_TCP_TS_TCP::NDataRequest(NetworkBuffer* buffer, bool confirmation) {
	rfc1006.send(buffer);
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NDataRequest(int cc, byte* buffer, bool confirmation) {
	int sended = rfc1006.send(cc, buffer);
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NDataIndication(const SharedNetworkBuffer& buffer) {
	return DONE;
}
ReturnCode NA_TCP_TS_TCP::NDataAcknoledgeRequest() {
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NExpeditedDataRequest(int cc, const byte* data) {
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NResetRequest(int reason) {
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NResetResponse() {
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NResetIndication(const NSAPAddr& originator, int reason) {
	return DONE;
}
ReturnCode NA_TCP_TS_TCP::NResetConfirmation() {
	return DONE;
}
ReturnCode NA_TCP_TS_TCP::NDisconnectRequest(int reason, const NSAPAddr& responding, int cc, const byte* data) {
	socket.shutdownSend();
	return OK;
}
ReturnCode NA_TCP_TS_TCP::NDisconnectIndication() {
	return DONE;
}
#if 0
void NA_TCP_TS_TCP::onReadable(const AutoPtr<ReadableNotification>& pNf)
{
	NetworkBuffer* buffer = nullptr;
	int received = rfc1006.recv(buffer);
	if (received == 0) {
		initiator->NDisconnectIndication();
		return;
	}
	if (buffer == nullptr)
		return;
	SharedNetworkBuffer shared_buffer(buffer);
	initiator->NDataIndication(shared_buffer);
}

void NA_TCP_TS_TCP::onWritable(const AutoPtr<WritableNotification>& pNf)
{
	byte bytes[32];
	//	initiator->TDataRequest(sizeof(bytes), bytes);
}
void NA_TCP_TS_TCP::onTimeout(const AutoPtr<TimeoutNotification>& pNf)
{
	Application& app = Application::instance();
	app.logger().information("onTimeout ");
}
void NA_TCP_TS_TCP::onIdle(const AutoPtr<IdleNotification>& pNf)
{
	Application& app = Application::instance();
	app.logger().information("onIdle ");
}
void NA_TCP_TS_TCP::onShutdown(const AutoPtr<ShutdownNotification>& pNf)
{
//	delete this;
}
#endif

}
}
}
