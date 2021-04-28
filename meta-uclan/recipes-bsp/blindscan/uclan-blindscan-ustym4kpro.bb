SUMMARY = "blindscan for ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "^(ustym4kpro)$"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

SRCDATE = "20190305"

PV = "${SRCDATE}"

SRC_URI  = "http://source.mynonpublic.com/uclan/${MACHINE}-blindscan-${SRCDATE}.zip"

SRC_URI[md5sum] = "ee98e5c30d36a7afaff364e6015e0956"
SRC_URI[sha256sum] = "2eb583117f45a5e7d88a2843ff60ba7cf2420deb1987af83ae6299b8433a21ba"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/${BLINDSCAN_BINARY} ${D}${bindir}
}

do_package_qa() {
}

FILES_${PN}  = "${bindir}"

do_prepare_recipe_sysroot[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
do_compile[noexec] = "1"
deltask do_populate_sysroot
