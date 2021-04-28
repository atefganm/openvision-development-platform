SUMMARY = "Utilities for transponder & dvb-s blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
require conf/license/license-close.inc

RDEPENDS_${PN} = "ncurses"

COMPATIBLE_MACHINE = "^(force4|lunix4k)$"

PACKAGES = "dags-blindscan-dvbs-utils"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_dags-blindscan-dvbs-utils += "virtual/blindscan-dvbs"

SRC_URI = "file://${BLINDSCAN_BINARY}"

S = "${WORKDIR}"

FILES_dags-blindscan-dvbs-utils = "${bindir}/*_blindscan"

do_install() {
    install -d ${D}${bindir}/
    install -m 0755 "${S}/${BLINDSCAN_BINARY}" "${D}${bindir}"
}

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
do_compile[noexec] = "1"
deltask do_populate_sysroot
