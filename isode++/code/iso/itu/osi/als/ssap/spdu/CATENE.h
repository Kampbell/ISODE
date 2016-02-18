/*
 * CATENE.h
 *
 *  Created on: 9 déc. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CATENE_H_
#define ALS_SSAP_SPDU_CATENE_H_
#include <list>
using std::list;
#include <memory>
using std::unique_ptr;

#include "als/base/util/NetworkBuffer.h"

namespace ALS {
	namespace SSAP {
		namespace SPDU {
			class SPDU;
		}
	}
}
using ALS::BASE::UTIL::NetworkBuffer;

namespace ALS {
namespace SSAP {
namespace SPDU {

class CATENE {
private:
	struct SPDUWithData {
		const SPDU* spdu;
		int			cc;
		const void*	data;
	};
	list<const SPDU*>	spdus;

public:
	CATENE();
	virtual ~CATENE();

	void add(const SPDU* spdu) {
		spdus.push_back(spdu);
	}
	ReturnCode		flush(unique_ptr<NetworkBuffer>& tsdu, int cc = 0, const void* data = nullptr) const;
private:
	static void		allocate(unique_ptr<NetworkBuffer>& tsdu, int cc) ;
};

}
}
}

#endif
