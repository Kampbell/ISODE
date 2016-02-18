/*****************************************************************************/
/* Copyright (C) 2013 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.                    */
/* AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.             */
/* THIS FILE MAY NOT BE DISTRIBUTED.                                         */
/*****************************************************************************/
/*
 * FILE: @(#)decode.cpp	16.1  12/03/05
 */

/*
 * Decodes BER and PER encoded baseball card using BCAS (Baseball Card
 * Abstract Syntax).
 */

#include "asn1/csn/bcas.h"  /* compiler-generated header file */

/*
 * Input encodings.
 */

int berDataLen = 54;

int perDataLen = 43;

unsigned char berEncodedData[] = {
    0x30, 0x34, 0x1A, 0x05, 0x43, 0x61, 0x73, 0x65, 0x79, 0x02,
    0x01, 0x20, 0x1A, 0x0A, 0x6C, 0x65, 0x66, 0x74, 0x20, 0x66,
    0x69, 0x65, 0x6C, 0x64, 0x30, 0x1C, 0x30, 0x1A, 0x02, 0x02,
    0x07, 0xD0, 0x02, 0x02, 0x07, 0xD5, 0x1A, 0x10, 0x4E, 0x65,
    0x77, 0x20, 0x59, 0x6F, 0x72, 0x6B, 0x20, 0x59, 0x61, 0x6E,
    0x6B, 0x65, 0x65, 0x73
};

unsigned char perEncodedData[] = {
    0x10, 0x43, 0x61, 0x73, 0x65, 0x79, 0x3E, 0x48, 0x6C, 0x65,
    0x66, 0x74, 0x20, 0x66, 0x69, 0x65, 0x6C, 0x64, 0x01, 0x80,
    0x02, 0x07, 0xD0, 0x02, 0x07, 0xD5, 0x0F, 0x4E, 0x65, 0x77,
    0x20, 0x59, 0x6F, 0x72, 0x6B, 0x20, 0x59, 0x61, 0x6E, 0x6B,
    0x65, 0x65, 0x73
};

/*
 * A class used to report ASN.1/C++ errors to the application. It is up to
 * the application programmer to decide which class to use for this purpose.
 * You may choose any different class (such as a descendant of the
 * std::exception class). You may also throw integer codes without defining
 * any class (however, we expect that most applications will use exception
 * classes).
 */

class ASN1DecodeException {
private:
    int code;
public:
    ASN1DecodeException(int asn1_code);
    ASN1DecodeException(const ASN1DecodeException & that);
    int get_code() const;
};

ASN1DecodeException::ASN1DecodeException(int asn1_code)
{
    code = asn1_code;
}

ASN1DecodeException::ASN1DecodeException(const ASN1DecodeException & that)
{
    code = that.code;
}

int ASN1DecodeException::get_code() const
{
    return code;
}

/*
 * The ASN.1/C++ error reporting function.
 */

static void throw_error(int code)
{
    throw ASN1DecodeException(code);
}

/*
 * printCard() accesses components of the decoded data and prints them.
 */
static void printCard(BBCard *card);

/*
 * A helper function to print error message and
 * textual description of the code returned by any runtime API function.
 */
static int report_error(OssControl *ctl, const char *where, ASN1DecodeException &exc);

/* Decodes PER and BER encoded cards */
int main2()
{
    int code = 0;		/* return code */
    BBCard *cardPtr = NULL;	/* pointer to decoded data */

    /*
     * Handle ASN.1/C++ runtime errors with C++ exceptions.
     */
    asn1_set_error_handling(throw_error, TRUE);

    try {
	bcas_Control ctl;	/* ASN.1/C++ control object */

	try {
	    EncodedBuffer encodedData;	/* encoded data */
	    BBCard_PDU pdu;	/* coding container for a BBCard value */
	    int encRule;	/* default encoding rules */

#ifdef RELAXED_MODE
	    /*
	     * Set relaxed mode.
	     */
	    ctl.setEncodingFlags(NOCONSTRAIN | RELAXBER | RELAXPER);
	    ctl.setDecodingFlags(NOCONSTRAIN | RELAXBER | RELAXPER);
#endif

	    ctl.setEncodingFlags(ctl.getEncodingFlags() | DEBUGPDU);
	    ctl.setDecodingFlags(ctl.getDecodingFlags() | DEBUGPDU);

	    /*
	     * Do decoding. Note that API is the same for any encoding method.
	     * Get encoding rules which were specified on the ASN.1 compiler
	     * command line.
	     */
	    encRule = ctl.getEncodingRules();

	    /*
	     * Set the decoder's input.
	     */
	    if (encRule == OSS_BER) {
		encodedData.set_buffer(berDataLen, (char *)berEncodedData);
	    } else if (encRule == OSS_PER_ALIGNED) {
		encodedData.set_buffer(perDataLen, (char *)perEncodedData);
	    }

	    /*
	     * Print the encoded message.
	     */
	    printf("Printing the %s-encoded PDU...\n\n",
			encRule == OSS_BER ? "BER": "PER");
	    encodedData.print_hex(ctl);

	    /*
	     * Decode the encoded PDU whose encoding is in "encodedData".
	     * An exception will be thrown on any error.
	     */
	    printf("\nThe decoder's trace messages (only for SOED)...\n\n");
	    pdu.decode(ctl, encodedData);

	    /*
	     * Read and print the decoded data.
	     */
	    cardPtr = pdu.get_data();
	    printCard(cardPtr);
	} catch (ASN1DecodeException &exc) {
	    /*
	     * An error occurred during decoding.
	     */
	    code = report_error(&ctl, "decode", exc);
	}
    } catch (ASN1DecodeException &exc) {
	/*
	 * An error occurred during control object initialization.
	 */
	code = report_error(NULL, "initialization", exc);
    } catch (...) {
	/*
	 * An unexpected exception is caught.
	 */
	printf("Unexpected exception caught.\n");
	code = -1;
    }
    /*
     * Delete the decoded data (if there are any).
     */
    delete cardPtr;
    return code;
}

/*
 * FUNCTION	report_error() is a common interface for error handling.
 *
 * PARAMETERS
 *	ctl	OSS control object (NULL if the error occurred during
 *		initialization)
 *	where   the error origin
 *	exc     the exception object
 *
 * RETURNS	the value of the return code
 */
static int report_error(OssControl *ctl, const char *where, ASN1DecodeException &exc) 
{
    int code = exc.get_code();
    const char *msg;

    if (!code)
	/* success */
	return 0;

    printf("\nAn error happened\n  Error origin: %s\n  Error code: %d\n",
	     where, code);

    if (ctl) {
	msg = ctl->getErrorMsg();
    	if (msg && *msg)
	    printf("  Error text: '%s'\n", msg);
    }

    return code;
}

#define CURRENT_YEAR 2006

static void print_string(OssString &str);

/*
 * FUNCTION	printCard() prints contents of a Baseball card object in
 *		a human readable form. Besides that, it demonstrates how
 *		to access components of the decoded data. If you need no more
 *		than human readable printout of the decoded data, there is an
 *		easier way: it can be printed in the form of value notation
 *		using ASN1Handle::print() OSS ASN.1/C++ API method instead.
 * PARAMETERS
 *	card	the object to dump
 */
static void printCard(BBCard *card)
{
    int			count = 1;
    BBCard::career	*career;
    OssIndex		index;

    printf("\nBaseball card\n-------------\n");
    printf("  Name:      ");
    print_string(card->get_name());
    printf("\n  Age:       %d\n", card->get_age());
    printf("  Position:  ");
    print_string(card->get_position());
    printf("\n");

    career = &card->get_career();
    index = career->first();
    if (index != OSS_NOINDEX) {
	printf("  Career:\n");
	do {
	    CareerEntry *ce = career->at(index);

	    printf("    #%d: %d - %d: ",
			count,
			ce->get_from(),
			ce->to_is_present() ?
				*ce->get_to() :
				CURRENT_YEAR);
	    print_string(ce->get_team());
	    printf("\n");
	    count++;
	    index = career->next(index);
	} while (index != OSS_NOINDEX);
    }
}

/*
 * FUNCTION	print_string() prints contents of an OssString object in
 *		a human readable form (this may be done simpler by using
 *		the standard std::string class but we avoid STL in the
 *		sample).
 * PARAMETERS
 *	str	the object to dump
 */
static void print_string(OssString &str)
{
    const char *text = str.get_buffer();
    if (text) {
	for (unsigned int i = 0; i < str.length(); i++)
	    printf("%c", text[i]);
    } else
	printf("[unknown]");
}
