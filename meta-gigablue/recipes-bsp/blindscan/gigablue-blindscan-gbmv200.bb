SUMMARY = "blindscan for ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

COMPATIBLE_MACHINE = "^(gbip4k|gbtrio4k)$"

PROVIDES += "virtual/blindscan-dvbs"
RPROVIDES_${PN} += "virtual/blindscan-dvbs"

SRCDATE = "20190307"

PV = "${SRCDATE}"

SRC_URI  = "http://source.mynonpublic.com/gigablue/mv200/gbmv200-blindscan-${SRCDATE}.zip"

SRC_URI[md5sum] = "b71bd793f450cd5e492e9171575475a4"
SRC_URI[sha256sum] = "bb55956f8b7b32bb483040151f374cd84162cdff6f12f3943504e432c3f16311"

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
