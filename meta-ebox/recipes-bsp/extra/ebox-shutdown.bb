require conf/license/license-gplv2.inc


SRC_URI = "file://ebox-shutdown.sh"

INITSCRIPT_NAME = "ebox-shutdown"
INITSCRIPT_PARAMS = "start 39 0 ."

inherit pkgconfig update-rc.d

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/ebox-shutdown.sh ${D}${sysconfdir}/init.d/ebox-shutdown
}

COMPATIBLE_MACHINE = "^(ebox5000|ebox5100|ebox7358|eboxlumi)$"
