/* pepy_strings.c - constant strings used in pepy */

#ifndef	lint
static char *rcsid = "$Header: /xtel/isode/isode/pepsy/RCS/pepsy_str.c,v 9.0 1992/06/16 12:24:03 isode Rel $";
#endif

/* 
 * $Header: /xtel/isode/isode/pepsy/RCS/pepsy_str.c,v 9.0 1992/06/16 12:24:03 isode Rel $
 *
 *
 * $Log: pepsy_str.c,v $
 * Revision 9.0  1992/06/16  12:24:03  isode
 * Release 8.0
 *
 */

/*
 *				  NOTICE
 *
 *    Acquisition, use, and distribution of this module and related
 *    materials are subject to the restrictions of a license agreement.
 *    Consult the Preface in the User's Manual for the full terms of
 *    this agreement.
 *
 */

#ifndef lint
char	*pepy_strings[] = {
	"bad ",				/* PEPY_ERR_BAD */
	"bad bitstring: ",		/* PEPY_ERR_BAD_BITS */
	"bad boolean: ",		/* PEPY_ERR_BAD_BOOLEAN */
	"bad class/id: ",		/* PEPY_ERR_BAD_CLASS */
	"bad class/form/id: ",		/* PEPY_ERR_BAD_CLASS_FORM_ID */
	"bad form ",			/* PEPY_ERR_BAD_FORM */
	"bad integer: ",		/* PEPY_ERR_BAD_INTEGER */
	"bad object identifier: ",	/* PEPY_ERR_BAD_OID */
	"bad octetstring: ",		/* PEPY_ERR_BAD_OCTET */
	"bad real: ",			/* PEPY_ERR_BAD_REAL */
	"bad sequence: ",		/* PEPY_ERR_BAD_SEQ */
	"bad set: ",			/* PEPY_ERR_BAD_SET */
	"has too many bits",		/* PEPY_ERR_TOO_MANY_BITS */
	"has too many elements",	/* PEPY_ERR_TOO_MANY_ELEMENTS */
	"has unknown choice: ",		/* PEPY_ERR_UNKNOWN_CHOICE */
	"has unknown component: ",	/* PEPY_ERR_UNK_COMP */
	"initialization fails",		/* PEPY_ERR_INIT_FAILED */
	"invalid choice selected: ",	/* PEPY_ERR_INVALID_CHOICE */
	"missing ",			/* PEPY_ERR_MISSING */
	"out of memory",		/* PEPY_ERR_NOMEM  */
	"too many elements for tagged ", /* PEPY_ERR_TOO_MANY_TAGGED */
	"warning: extra or duplicate members present in SET",
					/* PEPY_ERR_EXTRA_MEMBERS */
	(char *)0
};
#endif	
	
