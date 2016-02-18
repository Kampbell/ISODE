/*
 * Channel.h
 *
 *  Created on: 23 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "als/base/util/NetworkBuffer.h"

namespace ALS {
	namespace BASE {
		namespace UTIL {

			class Channel {
			public:
				Channel() {}
				virtual ~Channel() {}
				virtual int send(NetworkBuffer& buffer) = 0;
				virtual int recv(NetworkBuffer& buffer) = 0;
			};
		}
	}
}
#endif
