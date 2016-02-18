/*
 * Service.h
 *
 *  Created on: 16 août 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_SERV_SERVICE_H_
#define ALS_TSAP_SERV_SERVICE_H_




namespace ALS {
namespace TSAP {
	namespace PROV{
		class Logger;
	}
namespace SERV {

class Service {
public:
	virtual ~Service() {}
	virtual ALS::TSAP::PROV::Logger& logger() const = 0;
protected:
	Service() {}
private:
	Service(const Service&){}
	Service& operator = (const Service&) { return *this; };
};

}
}
}

#endif
