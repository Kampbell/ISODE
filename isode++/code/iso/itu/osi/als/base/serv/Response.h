/*
 * Response.h
 *
 *  Created on: 1 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_BASE_SERV_RESPONSE_H_
#define ALS_BASE_SERV_RESPONSE_H_

namespace ALS {
namespace BASE {
namespace SERV {

class Response {
protected:
	Response() {}
	Response(const Response&) = delete;
	Response& operator = (const Response&) = delete;
};

}
}
}

#endif
