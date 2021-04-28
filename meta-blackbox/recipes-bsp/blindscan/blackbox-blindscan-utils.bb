SUMMARY = "Utilities for transponder & dvb-c/s blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
require conf/license/license-close.inc

COMPATIBLE_MACHINE = "^(sogno8800hd|uniboxhde)$"

RDEPENDS_${PN} = "ncurses"

PACKAGES = "blackbox-blindscan-dvbs-utils blackbox-blindscan-dvbc-utils"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_blackbox-blindscan-dvbs-utils += "virtual/blindscan-dvbs"
RPROVIDES_blackbox-blindscan-dvbc-utils += "virtual/blindscan-dvbc"

SRC_URI = "file://tda1002x file://${BLINDSCAN_BINARY}"

PV = "2.1"

S = "${WORKDIR}"

FILES_blackbox-blindscan-dvbs-utils = "${bindir}/*_blindscan"
FILES_blackbox-blindscan-dvbc-utils = "${bindir}/tda1002x"

do_install() {
    install -d ${D}${bindir}/
    install -m 0755 "${S}/tda1002x" "${D}${bindir}"
    install -m 0755 "${S}/${BLINDSCAN_BINARY}" "${D}${bindir}"
}

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
do_compile[noexec] = "1"
deltask do_populate_sysroot
