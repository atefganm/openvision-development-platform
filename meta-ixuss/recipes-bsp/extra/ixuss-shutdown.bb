require conf/license/license-gplv2.inc


SRC_URI = " \
    file://ixuss-shutdown.sh "

INITSCRIPT_NAME = "ixuss-shutdown"
INITSCRIPT_PARAMS = "start 31 0 ."

inherit pkgconfig update-rc.d

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/ixuss-shutdown.sh ${D}${sysconfdir}/init.d/ixuss-shutdown
}

COMPATIBLE_MACHINE = "^(ixussone|ixusszero)$"
