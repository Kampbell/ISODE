/*****************************************************************************/
/* Copyright (C) 2013 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.                    */
/* AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.             */
/* THIS FILE MAY NOT BE DISTRIBUTED.                                         */
/*****************************************************************************/
/*
 * FILE: @(#)encode.cpp	16.1 12/03/05
 */

/*
 * Encodes a sample baseball card using BCAS (Baseball Card Abstract Syntax).
 * with BER or PER (Basic or Packed Encoding Rules).
 */

#include "asn1/csn/bcas.h"  /* compiler-generated header file */

/*
 * A class used to report ASN.1/C++ errors to the application. It is up to
 * the application programmer to decide which class to use for this purpose.
 * You may choose any different class (such as a descendant of the
 * std::exception class). You may also throw integer codes without defining
 * any class (however, we expect that most applications will use exception
 * classes).
 */

class ASN1EncodeException {
private:
    int code;
public:
    ASN1EncodeException(int asn1_code);
    ASN1EncodeException(const ASN1EncodeException & that);
    int get_code() const;
};

ASN1EncodeException::ASN1EncodeException(int asn1_code)
{
    code = asn1_code;
}

ASN1EncodeException::ASN1EncodeException(const ASN1EncodeException & that)
{
    code = that.code;
}

int ASN1EncodeException::get_code() const
{
    return code;
}

/*
 * The ASN.1/C++ error reporting function.
 */

static void throw_error(int code)
{
    throw ASN1EncodeException(code);
}

/*
 * A helper function to create an object to be encoded.
 */
static BBCard *newCard(const char *name, int age, const char *position,
		int c_from, int c_to, const char *c_team);

/*
 * A helper function to print error message and textual description of
 * the code returned by any runtime API function.
 */
static int report_error(OssControl *ctl, const char *where, ASN1EncodeException &exc); 
			  
/*
 * Creates and encodes a baseball card PDU.
 */
int main3()
{
    int code = 0;		/* return code */
    BBCard *card = NULL;	/* pointer to undecoded data */
    const char *where;		/* current operation -
				   used to print error messages if needed */

    /*
     * Handle ASN.1/C++ runtime errors with C++ exceptions.
     */
    asn1_set_error_handling(throw_error, TRUE);

    where = "initialization";
    try {
	bcas_Control ctl;	/* ASN.1/C++ control object */

	try {
	    EncodedBuffer encodedData;	/* encoded data */
	    BBCard_PDU pdu;		/* coding container for a BBCard value */
	    ossEncodingRules encRule;	/* default encoding rules */

	    where = "initial settings";

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
	     * Get the encoding rule, which is set currently.
	     */
	    encRule = ctl.getEncodingRules();

	    /*
	     * Create the instance of BBCard class to be encoded.
	     */
	    printf("Creating the PDU object to be encoded...");
	    where = "creating sample object";
	    card = newCard("Casey", 32, "left field",
			  2000, 2005, "New York Yankees");
	    printf(" success\n\n");

	    /*
	     * Set the data to the coding container.
	     */
	    pdu.set_data(*card);

	    /*
	     * Print the input to the encoder.
	     */
	    printf("The input to the encoder...\n\n");
	    where = "printing";
	    pdu.print(ctl);

	    /*
	     * Encode the object.
	     */
	    printf("\nThe encoder's trace messages (only for SOED)...\n\n");
	    where = "encoding";
	    pdu.encode(ctl, encodedData);
	    printf("\nPDU encoded successfully.\n");

	    /*
	     * Printing the encoded PDU.
	     */
	    printf("\n%s-Encoded PDU...\n\n",
		    encRule == OSS_BER ? "BER": "PER");
	    where = "printing";
	    encodedData.print_hex(ctl);

	} catch (ASN1EncodeException &exc) {
	    /*
	     * An error occurred during decoding.
	     */
	    code = report_error(&ctl, where, exc);
	}
    } catch (ASN1EncodeException &exc) {
	/*
	 * An error occurred during control object initialization.
	 */
	code = report_error(NULL, where, exc);
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
    delete card;

    /*
     * The encoder's output buffer was automatically allocated.
     * It should be deallocated by the encodedData's destructor,
     * so we don't need to delete it explicitly.
     */

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
static int report_error(OssControl *ctl, const char *where, ASN1EncodeException &exc) 
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

/*
 * FUNCTION	newCard() creates a Baseball card representation object
 *		with given component values. Input string values are copied.
 *
 * PARAMETERS
 *	name, age, position, c_from, c_to, c_team
 *		specify the components of the object to be created
 *
 * RETURNS	a pointer to the created object
 */
static BBCard *newCard(const char *name, int age, const char *position,
		   int c_from, int c_to, const char *c_team)
{
    BBCard::career career;

    /*
     * OssString has a constructor with one const char * argument,
     * so the implicit conversion takes place for name, position,
     * and team here.
     */
    CareerEntry entry(c_from, c_to, c_team);
    career.prepend(entry);
    return new BBCard(name, age, position, career);
}
