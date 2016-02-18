/*
 * PGI.cpp
 *
 *  Created on: 12 oct. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/spdu/pgi/PGI.h"
#include "als/ssap/spdu/pi/PI.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
void PGI::add(PI* pi) {
	HEADER::add((HEADER*)pi); 
	pgi_sons.push_back(pi); 
}
ReturnCode	PGI::encode(unique_ptr<NetworkBuffer>& tsdu) const {
	HEADER::encode(tsdu);
	for(auto son : pgi_sons) {
		son->encode(tsdu);
	}
	return OK;
}
string PGI::toString() const {
	string	sb;
	sb.append("[");
	sb.append(getLiteral());
	sb.append("]");
	return sb;
}
string PGI::getLiteral() const {
	string sb;
	switch(pgi()) {
		case PGI_CN_ID 		: sb.append("PGI_CN_ID"); 	break;
		case PGI_CN_ITEMS 	: sb.append("PGI_CN_ITEMS");break;
		case PGI_AR_LINK 	: sb.append("PGI_AR_LINK");	break;
		default				: sb.append("???" + to_string(pgi())); break;
	}
	return sb;
}

}
}
}

