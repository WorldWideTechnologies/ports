# $FreeBSD$

PKGNAMESUFFIX=	-qt4

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Fast and lightweight Qt4 BitTorrent client

LIB_DEPENDS=	${GEN_LIB_DEPENDS} \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	${GEN_RUN_DEPENDS}

CONFLICTS_INSTALL=	transmission-qt5-[0-9]*

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	qt4

USE_QT=		moc_build qmake_build uic_build rcc_build \
		corelib gui dbus network xml
USES=		compiler:c++11-lib desktop-file-utils qmake:no_env qt:4

EXTRA_CONF_ARGS=--disable-cli \
		--disable-daemon \
		--without-gtk \
		--disable-mac \
		--disable-nls

post-patch: general-patch
	@${REINPLACE_CMD} -e 's|/share/man|/man|g ; /PKGCONFIG/s| openssl||g' \
		${WRKSRC}/qt/qtr.pro
	@${ECHO_CMD} 'LIBS += -l${PORT_OPTIONS:M*SSL:tl:S/openssl/crypto/}' \
		>>${WRKSRC}/qt/qtr.pro

post-build:
	@(cd ${WRKSRC}/qt && ${QMAKE} ${QMAKE_ARGS} qtr.pro && ${MAKE_CMD})

do-install:
	@(cd ${WRKSRC}/qt && \
		${SETENV} INSTALL_ROOT=${STAGEDIR}${PREFIX} ${MAKE_CMD} install)

post-install: general-install
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/qt/README.txt \
		${STAGEDIR}${DOCSDIR}/README-qt4
	@${INSTALL_DATA} ${WRKSRC}/qt/transmission-qt.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/qt/icons/transmission.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/transmission-qt.png

.include "${MASTERDIR}/Makefile"
