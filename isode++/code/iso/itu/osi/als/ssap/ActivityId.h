/*
 * ActivityId.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_ACTIVITYID_H_
#define ALS_SSAP_ACTIVITYID_H_
#include <string>
using std::string;

#include <cstring>
#include "als/ssap/ssap.h"

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

namespace ALS {
namespace SSAP {

class ActivityId {
public:
	/** The maximum DATA part size . */
	static const int SID_DATA_SIZE = 6;
private:
	char	sd_data[SID_DATA_SIZE];

public:
	ActivityId() {
		memset(sd_data, 0, sizeof(sd_data));
	}
	ActivityId(const std::string& data) {
		memset(sd_data, 0, sizeof(sd_data));
		memcpy(sd_data, data.data(), min(data.size(), sizeof(sd_data)));
	}
	ActivityId(const char* data) {
		memset(sd_data, 0, sizeof(sd_data));
		memcpy(sd_data, data, min(strlen(data), sizeof(sd_data)));
	}
	ActivityId(int cc, const void* data) {
		memset(sd_data, 0, sizeof(sd_data));
		memcpy(sd_data, data, min(cc, sizeof(sd_data)));
	}
	~ActivityId() {
		memset(sd_data, 0, sizeof(sd_data));
	}
	int			cc() const		{ return SID_DATA_SIZE; }
	const char* data() const	{ return sd_data; }
	string to_string() const	{ return string(data(), cc()); }
};
}
}

#endif
