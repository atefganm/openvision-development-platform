SUMMARY = "kernel modules load helper"
MAINTAINER = "beyonwiz"
PACKAGE_ARCH = "${MACHINE_ARCH}"

require conf/license/license-gplv2.inc

COMPATIBLE_MACHINE = "^(beyonwizv2)$"

SRC_URI = "file://beyonwiz-loadmodules-beyonwizv2.sh"

INITSCRIPT_NAME = "beyonwiz-loadmodules"
INITSCRIPT_PARAMS = "start 01 S ."

inherit update-rc.d

S = "${WORKDIR}"

do_compile() {
}

do_install() {
	install -d ${D}${sysconfdir}/init.d/
	install -m 0755 ${WORKDIR}/beyonwiz-loadmodules-beyonwizv2.sh ${D}${sysconfdir}/init.d/beyonwiz-loadmodules
}
