/*
 * CN_AC.h
 *
 *  Created on: 23 oct. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_SSAP_SPDU_CN_AC_H_
#define ALS_SSAP_SPDU_CN_AC_H_
#include "als/base/addr/Selector.h"
using ALS::BASE::ADDR::Selector;

#include "als/ssap/Requirement.h"
using ALS::SSAP::Requirement;

#include "als/ssap/Reference.h"
using ALS::SSAP::Reference;

#include "als/ssap/spdu/SPDU.h"

namespace ALS {
namespace SSAP {
namespace SPDU {
class CN_AC : public SPDU {
public:
	static const int		CN_SIZE				= 512;

	static const int	SMASK_CN_REF		= 0x0001;
	static const int	SMASK_CN_OPT		= 0x0002;
	static const int	SMASK_CN_TSDU		= 0x0004;
	static const int	SMASK_CN_VRSN		= 0x0008;
	static const int	SMASK_CN_ISN		= 0x0010;
	static const int	SMASK_CN_SET		= 0x0020;
	static const int	SMASK_AC_TOKEN		= 0x0040;
	static const int	SMASK_CN_REQ		= 0x0080;
	static const int	SMASK_CN_CALLING	= 0x0100;
	static const int	SMASK_CN_CALLED		= 0x0200;

	/* will receive extended concatenated SPDUs,
	this implementation DOESN'T; segmenting is    enough... */

private:
	Reference	cn_reference;
	byte		cn_options;
	nat2		cn_tsdu_init;
	nat2		cn_tsdu_resp;
	byte		cn_version;
	nat4		cn_isn;
	byte		cn_settings;
	Requirement	cn_require;
	byte		cn_calling[Selector::SIZE];
	nat1		cn_callinglen;
	byte		cn_called[Selector::SIZE];
	nat1		cn_calledlen;
protected:
	byte		ac_token;


private:
	void		reset();

protected:
	CN_AC(Category cat, byte si);
	CN_AC(Category cat, byte si, NetworkBuffer& tsdu);
	virtual ~CN_AC();

public:
	int			encode();
	ReturnCode	decode(NetworkBuffer& tsdu);

	bool requires(const int requirement) const {
		return cn_require[requirement];
	}

	byte getOptions()  const {
		return cn_options;
	}

	void setOptions(byte options) {
		cn_options = options;
		addMask(SMASK_CN_OPT);
	}

	nat4 getIsn() const {
		return cn_isn;
	}

	const nat4& isn() const {
		return cn_isn;
	}

	void setIsn(int isn) {
		cn_isn = isn;
		addMask(SMASK_CN_ISN);
	}

	byte getSettings()  const {
		return cn_settings;
	}

	void setSettings(byte settings) {
		cn_settings = settings;
		addMask(SMASK_CN_SET);
	}

	void setRequires(Requirement require) {
		cn_require = require;
		addMask(SMASK_CN_REQ);
	}

	const Requirement& getRequires()  const {
		return cn_require;
	}

	const byte* getCalling()  const {
		return cn_calling;
	}

	void setCalling(int cc, const void* calling) {
		if (cc > 0) {
			memcpy(cn_calling, calling, cn_callinglen = min(cc, sizeof(cn_calling)));
			addMask(SMASK_CN_CALLING);
		}
	}

	int getCallinglen()  const {
		return cn_callinglen;
	}

	const byte* getCalled()  const {
		return cn_called;
	}

	void setCalled(int cc, const void* called) {
		if (cc > 0) {
			memcpy(cn_called, called, cn_calledlen = min(cc, sizeof(cn_called)));
			addMask(SMASK_CN_CALLED);
		}
	}

	int getCalledlen()  const {
		return cn_calledlen;
	}

	const Reference& getReference() const {
		return cn_reference;
	}

	Reference& getReference()  {
		return cn_reference;
	}

	void setReference(const Reference& reference) {
		cn_reference = reference;
		addMask(SMASK_CN_REF);
	}

	short getTSDUInitiator() const {
		return cn_tsdu_init;
	}

	void setTSDUInitiator(nat2 tsdu_init) {
		cn_tsdu_init = tsdu_init;
		addMask(SMASK_CN_TSDU);
	}

	short getTSDUResponder() const {
		return cn_tsdu_resp;
	}

	void setTSDUResponder(nat2 tsdu_resp) {
		cn_tsdu_resp =tsdu_resp;
		addMask(SMASK_CN_TSDU);
	}

	byte getVersion() const {
		return cn_version;
	}

	void setVersion(byte version) {
		cn_version = version;
		addMask(SMASK_CN_VRSN);
	}
};

}
}
}

#endif
