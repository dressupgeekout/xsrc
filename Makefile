#	$NetBSD: Makefile,v 1.38 2003/05/30 13:05:58 tron Exp $
#
# Targets & Variables
#
# build: Clean out xsrc, and build and install everything that goes
#	under /usr/X11R6.
#
#  DESTDIR -- Set to an alternative directory to install under.
#  UPDATE --  If set, don't make clean first, plus attempt to make
#	only the targets that are out of date.
#
# release snapshot: Same as build, plus tar up the X sets and install
#	them under the ${RELEASEDIR}/binary/sets directory (NetBSD <=1.6)
#	or the ${RELEASEDIR}/${MACHINE}/binary/sets directory (NetBSD >1.6).
#
#  DESTDIR -- Same as for build. Mandatory for building a release.
#  RELEASEDIR -- As explained above.
#  BUILD_DONE -- If set, assume build is already done.
#  INSTALL_DONE -- If set, assume binaries to tar up are to be found
#	in ${DESTDIR} already.
#  NETBSDSRCDIR -- Set to the full path to the main source tree, /usr/src
#	by default. Needed to find ./distrib/sets.
#
# cleandir distclean: Remove all generated files from under xsrc.
#
# clean: Remove object files, but keep imake generated makefiles.

.include <bsd.own.mk>

# Backwards compatibility with NetBSD 1.5 and 1.5.x where NETBSDSRCDIR
# doesn't get defined by  "bsd.own.mk".
NETBSDSRCDIR?=	${BSDSRCDIR}

.if defined(USE_XF86_4) && (${USE_XF86_4} != no)
XCDIR=	xfree/xc
.else
XCDIR=	xc
.endif

.MAIN: all
.if defined(USE_XF86_4) && (${USE_XF86_4} != no)
all: all-xc all-local
.else
all: all-xc all-contrib all-local
.endif

all-xc:
.if exists(${XCDIR}/xmakefile) && defined(UPDATE)
	@cd ${XCDIR} && ${MAKE} Everything
.else
	@-rm -f ${XCDIR}/xmakefile
	@cd ${XCDIR} && ${MAKE} World
.endif

all-contrib:
	@if [ ! -f contrib/Makefile ]; then \
	  cd contrib && PATH=../${XCDIR}/config/imake:$$PATH \
	    sh ../${XCDIR}/config/util/xmkmf -a ../${XCDIR} \
	       ${.CURDIR}/contrib; \
	fi
	@cd contrib && ${MAKE}

all-local:
	@if [ ! -f local/Makefile ]; then \
	  cd local && PATH=../${XCDIR}/config/imake:$$PATH \
	    sh ../${XCDIR}/config/util/xmkmf -a ../${XCDIR} \
	      ${.CURDIR}/local; \
	fi
	@cd local && ${MAKE}

.if defined(USE_XF86_4) && (${USE_XF86_4} != no)
install: install-xc install-local
.else
install: install-xc install-contrib install-local
.endif

install-xc:
	@cd ${XCDIR} && \
	  ${MAKE} DESTDIR="${DESTDIR}" install && \
	  ${MAKE} DESTDIR="${DESTDIR}" install.man

install-contrib:
	@cd contrib && \
	  ${MAKE} DESTDIR="${DESTDIR}" install && \
	  ${MAKE} DESTDIR="${DESTDIR}" install.man

install-local:
	@cd local && \
	  ${MAKE} DESTDIR="${DESTDIR}" install && \
	  ${MAKE} DESTDIR="${DESTDIR}" install.man

clean:
.if defined(USE_XF86_4) && (${USE_XF86_4} != no)
	@-cd ${XCDIR} && ${MAKE} clean
	@-cd local && ${MAKE} clean
.else
	@-cd ${XCDIR} && ${MAKE} clean
	@-cd contrib && ${MAKE} clean
	@-cd local && ${MAKE} clean
.endif

cleandir distclean: clean
	find ${XCDIR} contrib local -name .depend | xargs -n5 rm
	find ${XCDIR} contrib local -name 'Makefile*' | \
	    xargs -n5 grep -l "Makefile generated by imake" | xargs rm
	-rmdir ${XCDIR}/exports
	rm -f ${XCDIR}/xmakefile

build:
.if defined(UPDATE)
	@${MAKE} all && ${MAKE} install
.else
	@${MAKE} cleandir && ${MAKE} all && ${MAKE} install
.endif

# release goo
#
.if !defined(DESTDIR)
release snapshot:
	@echo setenv DESTDIR before doing that!
	@false
.elif !defined(RELEASEDIR)
release snapshot:
	@echo setenv RELEASEDIR before doing that!
	@false
#
.else
#
.if defined(INSTALL_DONE)
release snapshot:
.elif defined(BUILD_DONE)
release snapshot: install
.else
release snapshot: build
#
.endif # INSTALL_DONE or BUILD_DONE
#
	${INSTALL} -d -m 755 -o root -g wheel ${RELEASEDIR}/${MACHINE}/binary/sets
.if (${MACHINE} == "amiga") && !(defined(USE_XF86_4) && (${USE_XF86_4} != no))
	cd ${XCDIR}/programs/Xserver/hw/netbsd/amiga && \
		${INSTALL} -c -m 644 INSTALL.X11 ${RELEASEDIR}/${MACHINE}
.endif
.if defined(METALOG.add) && !exists(${DESTDIR}/etc)
	cd ${NETBSDSRCDIR}/distrib/sets && \
	    sh ./maketars -x -d ${DESTDIR:S,^$,/,} -N ${NETBSDSRCDIR}/etc -t ${RELEASEDIR}/${MACHINE}/binary/sets
.else
	cd ${NETBSDSRCDIR}/distrib/sets && \
	    sh ./maketars -x -d ${DESTDIR:S,^$,/,} -t ${RELEASEDIR}/${MACHINE}/binary/sets
.endif
	cd ${RELEASEDIR}/${MACHINE}/binary/sets && \
		cksum -o 1 *.tgz >BSDSUM && \
		cksum *.tgz >CKSUM && \
		cksum -m *.tgz >MD5 && \
		cksum -o 2 *.tgz >SYSVSUM
#
.endif # DESTDIR and RELEASEDIR check
