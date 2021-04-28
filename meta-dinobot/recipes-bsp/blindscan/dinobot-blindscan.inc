SUMMARY = "blindscan for dinobot"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

PV = "${SRCDATE}"

SRC_URI  = "http://source.mynonpublic.com/dinobot/${BLINDSCAN_BINARY}-${SRCDATE}-${MACHINETYPE}.tar.gz"

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
