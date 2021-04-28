SUMMARY = "Hardware user space LIBs for ${MACHINE}"
SECTION = "libs"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = "http://source.mynonpublic.com/azbox/${MACHINE}-mrua-${SRCDATE}.tar.gz"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

FILES_SOLIBSDEV =""

do_install() {
    install -d ${D}${libdir}
    for f in *.so; do
        oe_libinstall -s -C ${S}/ ${f%\.*} ${D}${libdir};
    done

}

FILES_${PN} += "${libdir}/lib*"
