/*
 * NetworkChannel.h
 *
 *  Created on: 4 août 2015
 *      Author: FrancisANDRE
 */

#ifndef NetworkCHANNEL_H_
#define NetworkCHANNEL_H_

#include "als/base/util/Channel.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {
			class NetworkChannel : public Channel {
			public:
				NetworkChannel() {}
				virtual ~NetworkChannel() {}
				virtual void connect(int timeout = 0) = 0;
				virtual void disconnect(int timeout = 0) = 0;
				virtual void setRecvTimeout(int second) = 0;
				virtual void setSendTimeout(int second) = 0;
			};
		}
	}
}
#endif
