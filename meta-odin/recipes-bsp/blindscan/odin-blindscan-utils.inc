SUMMARY = "Utils for DVB-S blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

require conf/license/license-close.inc

PROVIDES += "virtual/blindscan-dvbc virtual/blindscan-dvbs"

PV = "3.6.0"
SRC = "1213"

S = "${WORKDIR}"

do_install() {
    install -d "${D}${bindir}"
    install -m 0755 "${S}/tda1002x" "${D}${bindir}"
    install -m 0755 "${S}/${BLINDSCAN_BINARY}" "${D}${bindir}"    
}

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
do_compile[noexec] = "1"
deltask do_populate_sysroot
