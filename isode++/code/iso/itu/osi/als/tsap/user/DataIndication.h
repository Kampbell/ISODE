/*
 * DataIndication.h
 *
 *  Created on: 21 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_USER_DATA_INDICATION_H_
#define ALS_TSAP_USER_DATA_INDICATION_H_
#include <memory>
using std::shared_ptr;

#include "als/base/util/SharedNetworkBuffer.h"
#include "als/base/user/Indication.h"
using ALS::BASE::UTIL::SharedNetworkBuffer;

namespace ALS {
namespace TSAP {
namespace USER {

class DataIndication : public virtual ALS::BASE::USER::Indication {
public:
	/**
	 * T-DATA.INDICATION.
	 *
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode TDataIndication(const SharedNetworkBuffer& data) = 0;
	/**
	 * T-EXPEDITED-DATA.INDICATION.
	 *
	 * @param data data from peer
	 *
	 * @return the return code
	 */
	virtual ReturnCode TExpeditedDataIndication(const SharedNetworkBuffer& data) = 0;

protected:
	DataIndication() {}
	DataIndication(const DataIndication&) = delete;
	DataIndication& operator = (const DataIndication&) = delete;
};

}
}
}

#endif
