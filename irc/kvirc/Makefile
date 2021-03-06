# Created by: Michael Ranner
# $FreeBSD$

PORTNAME=	kvirc
PORTVERSION=	4.2.0
PORTREVISION=	8
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.de/pub/kvirc/%SUBDIR%/ \
		http://kvirc.gmake.de/pub/kvirc/%SUBDIR%/ \
		http://kvirc-ftp.visualscripts.com/%SUBDIR%/ \
		ftp://dedimarbo.ath.cx/pub/kvirc/%SUBDIR%/ \
		ftp://kvirc.eban-meban.com/%SUBDIR%/ \
		http://kvirc.tradebit.com/%SUBDIR%/ \
		http://kvirc.imsam.info/%SUBDIR%/ \
		http://kvirc.bcoos.net/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}/source

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	IRC client for KDE 4

USE_HARDENING=	pie:off

USE_PERL5=	build
USE_QT=		moc_build qmake_build rcc_build uic_build \
		dbus gui network sql xml
USES=		cmake cpe gettext perl5 qt:4 ssl tar:bzip2
CMAKE_ARGS=	-DWANT_ESD=no -DWANT_DOXYGEN=no \
		-DMANDIR=${MANPREFIX}
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AUDIOFILE GSM PERL PYTHON DEBUG
OPTIONS_SUB=	yes

AUDIOFILE_DESC=		Support for various audio formats
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
AUDIOFILE_CMAKE_OFF=	-DWITHOUT_AUDIOFILE=yes

GSM_DESC=		u-law to gsm audio converter support
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CMAKE_OFF=		-DWANT_GSM=no

PERL_DESC=	Perl scripting support
PERL_USE=	PERL5=run
PERL_CMAKE_OFF=	-DWANT_PERL=no

PYTHON_DESC=		Python scripting support
PYTHON_USES=		python
PYTHON_CMAKE_OFF=	-DWANT_PYTHON=no

DEBUG_CMAKE_ON=	-DWITH_DEBUG=yes -DVERBOSE=yes

.if defined(PKGNAMESUFFIX)
CONFLICTS_INSTALL=	kvirc-4.*

CMAKE_ARGS+=	-DWITHOUT_KDE4=yes
PLIST_SUB+=	QT="" KDE="@comment "

OPTIONS_DEFINE+=	PHONON WEBKIT

PHONON_DESC=	Build with Phonon support
PHONON_USES=	qt:4
PHONON_USE=	QT=phonon
PHONON_CMAKE_OFF=	-DWITHOUT_PHONON=yes

WEBKIT_DESC=	Build with QtWebkit support
WEBKIT_USES=	qt:4
WEBKIT_USE=	QT=webkit
WEBKIT_CMAKE_OFF=	-DWITHOUT_QTWEBKIT=yes
.else #defined(PKGNAMESUFFIX)
CONFLICTS_INSTALL=	kvirc-qt4-4.*

USES+=		kde:4 shared-mime-info
USE_KDE=	kdelibs automoc4
PLIST_SUB+=	QT="@comment " KDE=""
.endif #defined(PKGNAMESUFFIX)

PLIST_SUB+=	VER="${PORTVERSION:R}"

pre-fetch-PERL-on:
	@${ECHO_CMD} "====================================================="
	@${ECHO_CMD} "    Perl scripting requires perl with multiplicity"
	@${ECHO_CMD} "    support (enabled in ports by default)."
	@${ECHO_CMD} "====================================================="

post-patch:
	${REINPLACE_CMD} -e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/CMakeLists.txt
	# Fix error: invalid suffix on literal; C++11 requires a space between literal and identifier
	${REINPLACE_CMD} -e 's|"KVI_OPTIONS_WIDGET_KEYWORDS|" KVI_OPTIONS_WIDGET_KEYWORDS|g' \
		${WRKSRC}/src/modules/options/OptionsInstanceManager.cpp
	${REINPLACE_CMD} -e 's|"KVI_PATH_SEPARATOR|" KVI_PATH_SEPARATOR|g' \
		${WRKSRC}/src/kvirc/kernel/KviApplication_filesystem.cpp

.include <bsd.port.mk>
