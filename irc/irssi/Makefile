# $FreeBSD$

PORTNAME=	irssi
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES?=	irc
MASTER_SITES=	https://github.com/irssi/irssi/releases/download/${PORTVERSION}/

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Modular IRC client with many features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gettext-runtime gmake libtool ncurses pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20

USE_HARDENING=	safestack

OPTIONS_DEFINE=	PERL PROXY SOCKS BOT DOCS TRUECOLOR CAPSICUM
OPTIONS_DEFAULT=	PERL CAPSICUM

# If we're on FreeBSD 10 don't offer the Capsicum option.
OPTIONS_EXCLUDE_FreeBSD_10=	CAPSICUM

OPTIONS_SUB=	yes
SOCKS_DESC=	Socks proxy support
SOCKS_CONFIGURE_WITH=	socks
BOT_DESC=	Bot support
BOT_CONFIGURE_WITH=	bot
PERL_USES=	perl5
PERL_CONFIGURE_ON=	--with-perl-lib=site
PERL_CONFIGURE_OFF=	--with-perl=no
PROXY_CONFIGURE_WITH=	proxy
TRUECOLOR_DESC=	Truecolor (24bit) support
TRUECOLOR_CONFIGURE_ENABLE=	true-color
CAPSICUM_DESC=	Capsicum support
CAPSICUM_CONFIGURE_WITH=	capsicum

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
USES+=		ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' -e 's|/etc|${PREFIX}&|' \
		${WRKSRC}/docs/irssi.1

post-configure:
	@${MV} ${WRKSRC}/irssi.conf ${WRKSRC}/irssi.conf.sample

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/irssi/modules

post-install-PERL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/Irssi.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/Irc/Irc.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/TextUI/TextUI.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Irssi/UI/UI.so

.include <bsd.port.mk>
