SUMMARY = "player daemon helper"
MAINTAINER = "uclan"
PACKAGE_ARCH = "${MACHINE_ARCH}"

require conf/license/license-gplv2.inc

COMPATIBLE_MACHINE = "^(ustym4kpro)$"

SRC_URI = "file://uclan-libreader-ustym4kpro.sh"

INITSCRIPT_NAME = "uclan-libreader"
INITSCRIPT_PARAMS = "start 05 S ."

inherit update-rc.d

S = "${WORKDIR}"

do_compile() {
}

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/uclan-libreader-ustym4kpro.sh ${D}${sysconfdir}/init.d/uclan-libreader
}
