# $FreeBSD$

PORTNAME=	dhcp6c
DISTVERSION=	20180412
DISTVERSIONPREFIX=v
CATEGORIES=	net ipv6

MAINTAINER=	franco@opnsense.org
COMMENT=	OPNsense WIDE-DHCPv6 client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

CONFLICTS_INSTALL=	dhcp6

USE_HARDENING=	safestack

USE_GITHUB=	yes
GH_ACCOUNT=	opnsense

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc \
		--with-localdbdir=/var/db
USE_RC_SUBR=	dhcp6c
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS RAW

RAW_DESC=	Raw option support (experimental)

RAW_EXTRA_PATCHES=${PATCHDIR}/extra-patch-raw

post-install:
	${INSTALL_DATA} ${WRKSRC}/dhcp6c.conf.sample ${STAGEDIR}${PREFIX}/etc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
