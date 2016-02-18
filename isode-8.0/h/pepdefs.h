/* pepdefs.h */

/* 
 * $Header: /xtel/isode/isode/h/RCS/pepdefs.h,v 9.0 1992/06/16 12:17:57 isode Rel $
 *
 *
 * $Log: pepdefs.h,v $
 * Revision 9.0  1992/06/16  12:17:57  isode
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


#ifndef PEPDEF_DEFINITIONS
#define PEPDEF_DEFINITIONS
/*
 * Globally known pep definitions
 */

typedef	struct	{
	char	*md_name;	/* Name of this module */
	int	md_nentries;	/* Number of entries */
	tpe	**md_etab;	/* Pointer to encoding tables */
	tpe	**md_dtab;	/* Pointer to decoding tables */
	ptpe **md_ptab;	/* Pointer to Printing tables */
	PE	(*md_eucode)();	/* User code for encoding */
	PE	(*md_ducode)();	/* User code for decoding */
	PE	(*md_pucode)();	/* User code for printing */

	}	modtyp;

#ifndef NULL
#define NULL	(char *)0
#endif

#endif
