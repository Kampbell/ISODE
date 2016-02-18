/*
 * Common.h
 *
 *  Created on: 26 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SERV_REQUEST_H_
#define ALS_BASE_SERV_REQUEST_H_

namespace ALS { namespace BASE { namespace SERV {

class Request {
public:
protected:
	Request() {}
private:
	Request(const Request&){}
	Request& operator = (const Request&) { return *this; };
};

}
}
}

#endif
