/*
 * DataIndication.h
 *
 *  Created on: 31 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_USER_DATAINDICATION_H_
#define ALS_SSAP_USER_DATAINDICATION_H_

#include "als/base/user/Indication.h"
using ALS::BASE::USER::Indication;
#include "als/base/util/SharedNetworkBuffer.h"
using ALS::BASE::UTIL::SharedNetworkBuffer;

namespace ALS {
namespace SSAP {
namespace USER {
	class DataIndication : public virtual Indication {
public:
	virtual ~DataIndication() {}

	/**
	 * S-DATA.INDICATION.
	 *
	 * @param data the data
	 *
	 * @return the return code
	 */
	virtual ReturnCode SDataIndication(const SharedNetworkBuffer& data) = 0;

	/**
	 * S-EXPEDITED-DATA.INDICATION.
	 * 
	 * @param data the data
	 * 
	 * @return the return code
	 */
	virtual ReturnCode SExpeditedDataIndication(const SharedNetworkBuffer& data) = 0;

	/**
	 * S-TYPED-DATA.INDICATION.
	 * 
	 * @param data the data
	 * 
	 * @return the return code
	 */
	virtual ReturnCode STypedDataIndication(const SharedNetworkBuffer& data) = 0;

	/**
	 * S-CAPABILITY-DATA.INDICATION.
	 * 
	 * @param data the data
	 * 
	 * @return the return code
	 */
	virtual ReturnCode SCapabilityDataIndication(const SharedNetworkBuffer& data) = 0;

};

}
}
}

#endif
