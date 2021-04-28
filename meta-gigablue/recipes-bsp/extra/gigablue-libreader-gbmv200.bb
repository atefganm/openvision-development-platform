SUMMARY = "player daemon helper"
MAINTAINER = "gigablue"

require conf/license/license-gplv2.inc

COMPATIBLE_MACHINE = "^(gbtrio4k|gbip4k)$"

SRC_URI = "file://gigablue-libreader-${MACHINE}.sh"

INITSCRIPT_NAME = "gigablue-libreader"
INITSCRIPT_PARAMS = "start 05 S ."

inherit update-rc.d

S = "${WORKDIR}"

do_compile() {
}

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/gigablue-libreader-${MACHINE}.sh ${D}${sysconfdir}/init.d/gigablue-libreader
}
