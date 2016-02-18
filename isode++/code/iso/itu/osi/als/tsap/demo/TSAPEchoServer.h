/*
 * TSAPEchoServer.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef TSAPECHOSERVER_H_
#define TSAPECHOSERVER_H_

#include "tsap/user/Responder.h"
#include "tsap/serv/Responder.h"

class TSAPEchoServer : public ALS::TSAP::USER::Responder {
public:
	TSAPEchoServer();
	virtual ~TSAPEchoServer();

	virtual void TConnectIndication(){
		responder->TConnectResponse();
		responder->TDisconnectRequest();
	}
	virtual void TDisconnectIndication(){}
	virtual void TDataIndication(){
	}

private:
	ALS::TSAP::SERV::Responder*	responder;
};

#endif
