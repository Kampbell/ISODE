###############################################################################
#   Instructions to Make, for compilation of ISODE processes for Ultrix
#   versions greater than 3.1.
###############################################################################

###############################################################################
#
# $Header: /xtel/isode/isode/config/RCS/ultrix.make,v 9.0 1992/06/16 12:08:13 isode Rel $
#
#
# $Log: ultrix.make,v $
# Revision 9.0  1992/06/16  12:08:13  isode
# Release 8.0
#
#
###############################################################################

###############################################################################
#
#				 NOTICE
#
#    Acquisition, use, and distribution of this module and related
#    materials are subject to the restrictions of a license agreement.
#    Consult the Preface in the User's Manual for the full terms of
#    this agreement.
#
###############################################################################


###############################################################################
# Ultrix 4.2 and X Windows DUAs
###############################################################################

# To build the X-Windows DUA you will need to add
#
#	-I/usr/include/mit
#
# to OPTIONS above, before ANY other header file path.
#
# You will also need to include
#
#	-L/usr/local/lib
#
# to LDFLAGS below.
#
# You also need to ensure /usr/lib/libXext-mit.a is linked into
# /usr/local/lib/libXext.a to get the MIT version of the library.
# Alternatively, modify Makefile link commands to use -lXext-mit 
# instead of -lXext.


###############################################################################
# Options
###############################################################################

OPTIONS	=	-I. -I$(TOPDIR)h $(PEPYPATH) $(KRBOPT)

HDIR	=	$(TOPDIR)h/
UTILDIR	=	$(TOPDIR)util/
BINDIR	=	/usr/local/bin/
SBINDIR	=	/usr/etc/
ETCDIR	=	/usr/etc/
LOGDIR	=	/usr/tmp/
INCDIRM	=	/usr/include/isode
INCDIR	=	$(INCDIRM)/
PEPYDIRM=	$(INCDIR)pepy
PEPYDIR	=	$(PEPYDIRM)/
PEPSYDIRM=	$(INCDIR)pepsy
PEPSYDIR=	$(PEPSYDIRM)/
LIBDIR	=	/usr/lib/
LINTDIR	=	/usr/lib/lint/

LIBISODE=	$(TOPDIR)libisode.a
LIBDSAP	=	$(TOPDIR)libdsap.a

SYSTEM	=	-bsd42
MANDIR	=	/usr/man/
MANOPTS	=	-bsd42


###############################################################################
# Programs and Libraries
###############################################################################
#
# If using the -O option in CFLAGS you might also need to add 
#     -Olimit 2000 
# to ensure everything gets optimized
#

MAKE	=	./make DESTDIR=$(DESTDIR) $(MFLAGS) -k
SHELL	=	/bin/sh

CC      =	cc
CFLAGS  =	-O    $(OPTIONS)
LIBCFLAGS=	      $(CFLAGS)
LINT    =	lint
LFLAGS  =	-bhuz $(OPTIONS)
LD	=	ld
LDCC	=	$(CC)
LDFLAGS =	-s
ARFLAGS	=

LN	=	ln

# Add -lx25 -ldnet to LSOCKET below for the DEMSA X.25 router
LSOCKET	=	$(KRBLIB)


###############################################################################
# Generation Rules for library modules
###############################################################################

.c.o:;		$(CC) $(LIBCFLAGS) -c $*.c
		-ld -x -r $@
		mv a.out $@
