# Created by: ijliao
# $FreeBSD$

PORTNAME=	libetpan
PORTVERSION=	1.8
CATEGORIES=	mail ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail framework for C language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libsasl2.so:security/cyrus-sasl2

USE_GITHUB=	yes
GH_ACCOUNT=	dinhviethoa

USES=		autoreconf gmake iconv libtool localbase
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		IPV6
OPTIONS_SINGLE=		CRYPTO
OPTIONS_SINGLE_CRYPTO=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_CONFIGURE_ON=	--without-openssl --with-gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error

IPV6_CONFIGURE_ENABLE=	ipv6

OPENSSL_CONFIGURE_ON=	--with-openssl="${OPENSSLBASE}"
OPENSSL_USES=		ssl

pre-configure:
	@(cd ${WRKSRC} && ${LN} -s README.md README)

.include <bsd.port.mk>
