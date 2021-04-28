SUMMARY = "blindscan for ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "^(viper4k)$"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

SRCDATE = "20190306"

PV = "${SRCDATE}"

SRC_URI  = "http://source.mynonpublic.com/amiko/${MACHINE}-blindscan-${SRCDATE}.zip"

SRC_URI[md5sum] = "c1f286a12791e0e5461f73ee7aae0712"
SRC_URI[sha256sum] = "2da5f797ee4147a0f9f35c9c72dfa958258deb492a074c7cf60a7a3bf467dea9"

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
