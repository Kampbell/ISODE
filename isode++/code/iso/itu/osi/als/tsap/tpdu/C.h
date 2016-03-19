/*
 * C.h
 *
 *  Created on: 29 juil. 2014
 *      Author: FrancisANDRE
 */

#ifndef ALS_TSAP_TPDU_C_H_
#define ALS_TSAP_TPDU_C_H_

#include <list>
#include "als/tsap/tpdu/TPCI.h"

using std::list;

namespace ALS {
namespace TSAP {
namespace TPDU {

class TSAP_API C : public TPCI {
	friend class Provider;
public:
	enum TransportClass {
		TP0, TP1, TP2, TP3, TP4
	};

	enum TransportPDUSize {
		Size128 = 128, Size256 = 256, Size512 = 512, Size1K = 1024, 
		Size2K = 2 * 1024, Size4K = 4 * 1024, Size8K = 8 * 1024
	};

	enum TransportOption {
		UseTransportExpedited,
		Use16bitChecksum, 
		UseReceiptConfirmation, 
		UseNetworkExpedited, 
		UseSelectiveAcknowledgement,
		UseRequestAcknoledgement
	};

	enum TransportAlternate {
		AlternateTP0, AlternateTP1, AlternateTP2, AlternateTP3
	};

protected:
	static const byte	TS_SIZE					= 32;
	static const byte	ID_SIZE					= 64;
	static const byte	CR_CLASS_TP0			= 0x00;	// class 0
	static const byte	CR_CLASS_TP1			= 0x10;	//   ..  1
	static const byte	CR_CLASS_TP2			= 0x20;	//   ..  2
	static const byte	CR_CLASS_TP3			= 0x30;	//   ..  3
	static const byte	CR_CLASS_TP4			= 0x40;	//   ..  4
	static const byte	CR_OPT_EXTD				= 0x02;	// extended formats in classes 2-4
	static const byte	CR_OPT_EXPL				= 0x01;	// explicit flow control in class 2
	static const byte	CR_NO_OPT				= 0x00;	// no options

protected:
	static const byte	VDAT_TSAP_CALLING		= 0xc1;	// TSAP ID of the calling TSAP
	static const byte	VDAT_TSAP_CALLED		= 0xc2;	// TSAP ID of the called TSAP
	static const byte	VDAT_PREFERED_TPDU_SIZE	= 0xf0;	// Prefered maximum TPDU SIZE
	static const byte	VDAT_TPDU_SIZE			= 0xc0;	// TPDU SIZE
	static const byte		SIZE_8K				= 0x0d;	//   8192
	static const byte		SIZE_4K				= 0x0c;	//   4096
	static const byte		SIZE_2K				= 0x0b;	//   2048
	static const byte		SIZE_1K				= 0x0a;	//   1024
	static const byte		SIZE_512			= 0x09;	//    512
	static const byte		SIZE_256			= 0x08;	//    256
	static const byte		SIZE_128			= 0x07;	//    128
	static const byte	VDAT_VRSN				= 0xc4;	// Version number
	static const byte	VDAT_SECURITY			= 0xc5;	// Security parameters
	static const byte	VDAT_CHECKSUM			= 0xc3;	// Checksum
	static const byte	VDAT_OPTIONS			= 0xc6;	// Additional option selections
	static const byte	OPT_REQUEST_ACK			= 0x20;	//     Use request acknowledgement in class 1, 3, 4
	static const byte	OPT_SELECTIVE_ACK		= 0x10;	//     Use selective acknowledgement in class 4
	static const byte	OPT_NEXPEDITE			= 0x08;	//     Use network expedited in class 1*/
	static const byte	OPT_CONFIRM				= 0x04;	//     Use receipt confirmation in class 1*/
	static const byte	OPT_CHECKSUM			= 0x02;	//     Use 16-bit checksum in class 4
	static const byte	OPT_TEXPEDITE			= 0x01;	//     Use transport expedited data service
	static const byte	VDAT_ALTERNATE			= 0xc7;	// Alterated protocol class(es)
	static const byte		ALT_TP0				= 0x01;	//     class 0
	static const byte		ALT_TP1				= 0x02;	//     class 1
	static const byte		ALT_TP2				= 0x04;	//     class 2
	static const byte		ALT_TP3				= 0x08;	//     class 3
	static const byte		ALT_TP4				= 0x10;	//     class 4
	static const byte	VDAT_ACKTIME			= 0x85;	// Acknowledge time
	static const byte	VDAT_THROUGHPUT			= 0x89;	// Throughput
	static const byte	VDAT_ERRORATE			= 0x86;	// Residual error rate
	static const byte	VDAT_PRIORITY			= 0x87;	// Priority
	static const byte	VDAT_DELAY				= 0x88;	// Transit delay
	static const byte	VDAT_TTR				= 0x8b;	// Reassignment time
	static const byte	VDAT_INACTIVITY_TIMER	= 0xf2;	// Reassignment time

protected:
	
	// FIXED part
	short					tp_dstref = 0;
	short					tp_srcref = 0;
	byte					tp_klass = 0;

	// VARIABLE part
	byte					tp_options = OPT_TEXPEDITE;
	byte					tp_alternate = 0;

private:
	byte					tp_calling[ID_SIZE];
	byte					tp_callinglen = 0;
	byte					tp_called[ID_SIZE];
	byte					tp_calledlen = 0;
	byte					tp_tpdusize = SIZE_128;
	nat4					tp_prefered_tpdusize = 0;
	// number of bytes for the VARIABLE part of a TPDU
	mutable int				tp_vlen = 0;
	mutable int				tp_vsize = -1;

//protected:
	short&  dstref() 		{ return tp_dstref; }
	short&  srcref()		{ return tp_srcref; }
	byte*	called() 		{ return &tp_called[0]; }
	byte*	calling() 		{ return &tp_calling[0]; }
	byte&	calledlen() 	{ return tp_calledlen; }
	byte&   callinglen()	{ return tp_callinglen; }
	byte&	alternate() 	{ return tp_alternate; }
	byte&	klass() 		{ return tp_klass; }
#if 0
	short&	tpdusize() 		{ return tp_tpdusize; }
#endif
	short		dstref() const		{ return tp_dstref; }
	short		srcref() const		{ return tp_srcref; }
	const byte* called() const		{ return &tp_called[0]; }
	const byte* calling() const		{ return &tp_calling[0]; }
	byte		calledlen() const	{ return tp_calledlen; }
	byte		callinglen() const	{ return tp_callinglen; }
	nat2		tpdusize() const;

public:
	C(byte code)			: TPCI(code) {}
	C(byte li, byte code) 	: TPCI(li, code) {}

	virtual int fixedSize() const		{ return 5; }
	virtual int variableSize() const	{
		if (tp_vsize == -1) {
			tp_vsize = tp_vlen;
			if (tp_options != 0)
				tp_vlen += 3;
			if (tp_prefered_tpdusize > 0) {
				tp_vlen += 1 + 1 + 4;
			}
			else {
				tp_vlen += 3;
			}
		}
		return tp_vlen; 
		//(calledlen + 2) + (callinglen + 2) + 1 + 2 + 1;
		//3 + 7 + (2 + callinglen) + (2 + calledlen) + 3);		
	}


	virtual int		decode(NetworkBuffer* nsdu);
	virtual int		encode(unique_ptr<NetworkBuffer>& nsdu);
	virtual void	setData(NetworkBuffer* buffer);
	virtual void	setData(const string&  message);
	virtual void	setData(int cc, const byte* data);

	TransportClass					transportClass() const;
	TransportAlternate				transportAlternate() const;
	bool							hasTransportOption(const TransportOption& option) const;

	void		dstref(short ref)	{ tp_dstref = ref; }
	void		srcref(short ref)	{ tp_srcref = ref; }
	void		called(byte length, const byte* bytes);
	void		calling(byte length, const byte* bytes);
	void		tpdusize(nat4 size);
	void		klass(const TransportClass& tc);
	void		addOption(const TransportOption& option);
	void		remOption(const TransportOption& option);

protected:
private:
	C(const C& ak) = delete;
	C& operator = (const C&)  = delete;
};

}
}
}

#endif
