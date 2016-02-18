/*
 * Reference.cpp
 *
 *  Created on: 8 sept. 2014
 *      Author: FrancisANDRE
 */

#include "als/ssap/Reference.h"

namespace ALS {
namespace SSAP {
Reference::Reference() {
	sref_udata_length = 0;
	sref_cdata_length = 0;
	sref_adata_length = 0;
	sref_vdata_length = 0;
	memset(sref_udata, ' ', sizeof(sref_udata));
	memset(sref_cdata, ' ', sizeof(sref_cdata));
	memset(sref_adata, ' ', sizeof(sref_adata));
	memset(sref_vdata, ' ', sizeof(sref_vdata));
}

Reference::Reference(size_t cc, const void* addr) {
	sref_udata_length = 0;
	sref_cdata_length = 0;
	sref_adata_length = 0;
	sref_vdata_length = 0;
	memset(sref_udata, ' ', sizeof(sref_udata));
	memset(sref_cdata, ' ', sizeof(sref_cdata));
	memset(sref_adata, ' ', sizeof(sref_adata));
	memset(sref_vdata, ' ', sizeof(sref_vdata));
	memcpy(sref_udata, addr, sref_udata_length = min(cc, sizeof(sref_udata)));
}
Reference::~Reference() {
}

void Reference::udata(size_t cc, const void* data) {
	memset(sref_udata, ' ', sizeof(sref_udata));
	memcpy(sref_udata, data, sref_udata_length = min(cc, sizeof(sref_udata)));
}
void Reference::cdata(size_t cc, const void* data) {
	memset(sref_cdata, ' ', sizeof(sref_cdata));
	memcpy(sref_cdata, data, sref_cdata_length = min(cc, sizeof(sref_cdata)));
}
void Reference::adata(size_t cc, const void* data) {
	memset(sref_adata, ' ', sizeof(sref_adata));
	memcpy(sref_adata, data, sref_adata_length = min(cc, sizeof(sref_adata)));
}
void Reference::vdata(size_t cc, const void* data) {
	memset(sref_vdata, ' ', sizeof(sref_vdata));
	memcpy(sref_vdata, data, sref_vdata_length = min(cc, sizeof(sref_vdata)));
}
bool Reference::valid() const {
	return	
		sref_udata_length <= SREF_USER_SIZE &&
		sref_cdata_length <= SREF_COMM_SIZE &&
		sref_adata_length <= SREF_ADDT_SIZE &&
		sref_vdata_length <= SREF_USER_SIZE;
}

}
}
