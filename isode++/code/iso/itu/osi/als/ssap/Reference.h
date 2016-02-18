/*
 * Reference.h
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_REFERENCE_H_
#define ALS_SSAP_REFERENCE_H_
#include <string>
#include <algorithm>
using std::string;
using std::min;

#include "als/ssap/ssap.h"

namespace ALS {
namespace SSAP {

class SSAP_API Reference {
public:
	/** The USER reference maximum size. */
	static const int SREF_USER_SIZE = 64;	// USER reference

	/** The COMMON reference maximum size. */
	static const int SREF_COMM_SIZE = 64;	// COMMON reference/

	/** The ADDITIONAL reference maximum size. */
	static const int SREF_ADDT_SIZE = 4;	// ADDITIONAL reference

	//
private:
	byte	sref_udata_length;
	byte	sref_cdata_length;
	byte	sref_adata_length;
	byte	sref_vdata_length;
	byte 	sref_udata[SREF_USER_SIZE];
	byte 	sref_cdata[SREF_COMM_SIZE];
	byte 	sref_adata[SREF_ADDT_SIZE];
	byte 	sref_vdata[SREF_USER_SIZE];/* for S-ACTIVITY-RESUME */

public:
	Reference();
	Reference(size_t cc, const void* addr);
	~Reference();

	const byte* udata() const	{ return sref_udata; }
	const byte* cdata() const	{ return sref_cdata; }
	const byte* adata() const	{ return sref_adata; }
	const byte* vdata() const	{ return sref_vdata; }

	void udata(size_t cc, const void* data);
	void cdata(size_t cc, const void* data);
	void adata(size_t cc, const void* data);
	void vdata(size_t cc, const void* data);

	byte ulength() const	{ return sref_udata_length; }
	byte clength() const	{ return sref_cdata_length; }
	byte alength() const	{ return sref_adata_length; }
	byte vlength() const	{ return sref_vdata_length; }

	bool valid() const;
};

}
}

#endif
