DESCRIPTION="AiO screenshot grabber"
MAINTAINER = "PLi team"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://LICENSE;md5=751419260aa954499f7abaabaa882bbe"

DEPENDS = "jpeg libpng zlib"

inherit gitpkgv

PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"

GITHUB_URI ?= "git://github.com"
SRC_URI = "${GITHUB_URI}/OpenPLi/${BPN}.git"

S = "${WORKDIR}/git"

inherit autotools pkgconfig

EXTRA_OECONF = "ac_cv_prog_c_openmp=-fopenmp"

SRC_URI_azboxme = "${GITHUB_URI}/oe-alliance/${BPN}.git"
SRC_URI_azboxminime = "${GITHUB_URI}/oe-alliance/${BPN}.git"
SRC_URI_dm900 = "${GITHUB_URI}/oe-alliance/${BPN}.git"
SRC_URI_dm920 = "${GITHUB_URI}/oe-alliance/${BPN}.git"
SRC_URI_sh4 = "${GITHUB_URI}/oe-alliance/${BPN}.git"
