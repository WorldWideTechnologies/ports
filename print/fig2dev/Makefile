# $FreeBSD$

PORTNAME=	fig2dev
PORTVERSION=	3.2.7
CATEGORIES=	print
MASTER_SITES=	SF/mcj/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools to convert Xfig .fig files

RUN_DEPENDS=	ppmtogif:graphics/netpbm
LIB_DEPENDS=	libpng.so:graphics/png

CONFLICTS=	transfig-*

USES=		alias ghostscript:run iconv tar:xz
CFLAGS+=	-Wno-return-type
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-transfig
USE_XORG=	xpm

.include <bsd.port.mk>
